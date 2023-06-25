#include <stdio.h>
#include <stdlib.h>
#include "stm32f0xx.h"
#include "layouts.h"
#include "hw_inits.h"
#include "matrix.h"

#define KEY_CAPS  41
#define KEY_NUMLK 11
#define KEY_FN    67
#define KEY_CZLK  10

uint8_t kbd_matrix_x[80];
uint8_t kbd_matrix_y[80];

char * kbd_strings[80];
char * kbd_strings_sh[80];
char * kbd_strings_alt[80];
char * kbd_strings_nmlk[80];
char * kbd_strings_czlk[80];

uint16_t kbd_pins[32];
uint32_t kbd_ports[32];

uint8_t kbd_pressed[80];
uint8_t kbd_pressed_pre[80];

uint8_t kbd_caps;
uint8_t kbd_numlk;
uint8_t kbd_czlk;


void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}


void SysTick_Handler (void) {
  #if defined(USE_HAL_DRIVER)
    HAL_IncTick();
  #endif
}


void myputs(uint8_t *t) {
  int i=0;
  while (t[i] != 0) {
    USART_SendData(USART1, (uint16_t) t[i]);
    Delay(1000);
    while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
          {
          }
    i++;
  }
}


uint8_t get_shift() {

  if (kbd_caps == 1) {
    return 1;
  }

  if ((kbd_pressed_pre[53] == 1 && kbd_pressed[53] == 1) || (kbd_pressed_pre[66] == 1 && kbd_pressed[66] == 1)) {
    return 1;
  } else {
    return 0;
  }
}


uint8_t get_alt() {
  if (kbd_pressed_pre[70] == 1 && kbd_pressed[70] == 1) {
    return 1;
  } else {
    return 0;
  }
}


void print_key(int n, char dir) {
  char c[6];
  c[0] = '$';
  c[1] = dir;
  c[2] = '0' + n/10;
  c[3] = '0' + n%10;
  c[4] = '$';
  c[5] = 0;

  uint8_t * out;

  if (kbd_numlk && ((n >= 22 && n<= 26) || (n >= 35 && n <= 38) || (n >= 48 && n <= 51)|| (n >= 61 && n <= 64))) {
    out  = (uint8_t *) kbd_strings_nmlk[n];
  } else if(kbd_czlk && n >= 16 && n <= 25) {
	out  = (uint8_t *) kbd_strings_czlk[n];
  } else if (get_shift() == 1) {
    out  = (uint8_t *) kbd_strings_sh[n];
  } else if(get_alt() == 1) {
    out  = (uint8_t *) kbd_strings_alt[n];
  } else {
    out  = (uint8_t *) kbd_strings[n];
  }

  myputs((uint8_t *)c);
  myputs(out);
  myputs((uint8_t *)"!\n");

}


void blink_leds() {
  GPIO_WriteBit(GPIOB, GPIO_Pin_13, Bit_SET);
  GPIO_WriteBit(GPIOB, GPIO_Pin_14, Bit_SET);
  GPIO_WriteBit(GPIOB, GPIO_Pin_15, Bit_SET);

  Delay(100000);

  GPIO_WriteBit(GPIOB, GPIO_Pin_13, Bit_RESET);
  GPIO_WriteBit(GPIOB, GPIO_Pin_14, Bit_RESET);
  GPIO_WriteBit(GPIOB, GPIO_Pin_15, Bit_RESET);
}


int main(int argc, char* argv[]) {

  SysTick_Config(SystemCoreClock);

  kbd_hw_init();

  puts("");
  puts("starting kbd fw 1.0");

  blink_leds();

  kbd_init_pinout();
  kbd_init_matrix();

  init_kbd_strings ();
  init_kbd_strings_sh();
  init_kbd_strings_alt();
  init_kbd_strings_nmlk();
  init_kbd_strings_czlk();

  static uint8_t fn_modif;

  while(1) {

    for(int n = 0; n < 80; n++) {
      kbd_pressed[n] = 0;
    }

    for (int n = 0; n < 25; n++){
      // set as inputs
      for(int a=0; a < 25; a++) {
        kbd_init_pin(a, GPIO_Mode_IN);
        kbd_set_pin(n, Bit_RESET);
      }

      // set one as output
      kbd_init_pin(n, GPIO_Mode_OUT);
      kbd_set_pin(n, Bit_SET);

      // read inputs
      for (int a = n+1; a < 25; a++) {
        if (kbd_get_pin(a)){
          for(int g = 0; g < 80; g++){
            if ((a == kbd_matrix_y[g]) && (n == kbd_matrix_x[g])) {
              kbd_pressed[g] = 1;
            }
          }
        }
      }
    }

    // generate events
    for(int n = 0; n < 80; n++) {
      if ((kbd_pressed[n] == 1) && (kbd_pressed_pre[n] == 0)) {
        print_key(n, 'P');
      }
      if ((kbd_pressed[n] == 0) && (kbd_pressed_pre[n] == 1)) {
        print_key(n, 'R');
      }
      if ((kbd_pressed[n] == 1) && (kbd_pressed_pre[n] == 1)) {
        if (n != 66 && n != 53 && n != 68 && n != 70) { // ignoring rshift 66, lshift 53, ctrl 68, alt 70
          print_key(n, 'H');
        }
      }
    }

    // auto handle lock keys
    if ((kbd_pressed[KEY_CAPS] == 1) && (kbd_pressed_pre[KEY_CAPS] == 0)) {
      kbd_caps = 1 - kbd_caps;
      GPIO_WriteBit(GPIOB, GPIO_Pin_14, kbd_caps);
    }

    if ((kbd_pressed[KEY_NUMLK] == 1) && (kbd_pressed_pre[KEY_NUMLK] == 0)) {
      kbd_numlk = 1 - kbd_numlk;
      GPIO_WriteBit(GPIOB, GPIO_Pin_13, kbd_numlk);
    }

    if ((kbd_pressed[KEY_CZLK] == 1) && (kbd_pressed_pre[KEY_CZLK] == 0) && fn_modif == 1) {
	  kbd_czlk = 1 - kbd_czlk;
	  GPIO_WriteBit(GPIOB, GPIO_Pin_15, kbd_czlk);
	}

    if ((kbd_pressed[KEY_FN] == 1) && (kbd_pressed_pre[KEY_FN] == 0)) {
	  fn_modif = 1;
	}

    if ((kbd_pressed[KEY_FN] == 0) && (kbd_pressed_pre[KEY_FN] == 1)) {
	  fn_modif = 0;
	}


    for(int n = 0; n < 80; n++) {
      kbd_pressed_pre[n] = kbd_pressed[n];
    }
  }
}

// ----------------------------------------------------------------------------
