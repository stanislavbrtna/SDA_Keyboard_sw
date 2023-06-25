/*
 * hw_inits.c
 *
 *  Created on: 25. 6. 2023
 *      Author: stanislaw
 */

#include "hw_inits.h"

extern uint16_t kbd_pins[32];
extern uint32_t kbd_ports[32];

USART_InitTypeDef USART_InitStructure;

void kbd_init_pinout() {
  kbd_pins[24] = GPIO_Pin_0;
  kbd_ports[24] = (uint32_t)GPIOA;
  kbd_pins[23] = GPIO_Pin_1;
  kbd_ports[23] = (uint32_t)GPIOA;
  kbd_pins[22] = GPIO_Pin_2;
  kbd_ports[22] = (uint32_t)GPIOA;
  kbd_pins[21] = GPIO_Pin_3;
  kbd_ports[21] = (uint32_t)GPIOA;
  kbd_pins[20] = GPIO_Pin_4;
  kbd_ports[20] = (uint32_t)GPIOA;
  kbd_pins[19] = GPIO_Pin_5;
  kbd_ports[19] = (uint32_t)GPIOA;
  kbd_pins[18] = GPIO_Pin_6;
  kbd_ports[18] = (uint32_t)GPIOA;
  kbd_pins[17] = GPIO_Pin_7;
  kbd_ports[17] = (uint32_t)GPIOA;
  kbd_pins[16] = GPIO_Pin_8;
  kbd_ports[16] = (uint32_t)GPIOA;
  kbd_pins[15] = GPIO_Pin_11;
  kbd_ports[15] = (uint32_t)GPIOA;
  kbd_pins[14] = GPIO_Pin_12;
  kbd_ports[14] = (uint32_t)GPIOA;
  kbd_pins[13] = GPIO_Pin_11;
  kbd_ports[13] = (uint32_t)GPIOB;
  kbd_pins[12] = GPIO_Pin_12;
  kbd_ports[12] = (uint32_t)GPIOB;
  kbd_pins[11] = GPIO_Pin_15;
  kbd_ports[11] = (uint32_t)GPIOA;
  kbd_pins[10] = GPIO_Pin_0;
  kbd_ports[10] = (uint32_t)GPIOB;
  kbd_pins[9] = GPIO_Pin_1;
  kbd_ports[9] = (uint32_t)GPIOB;

  kbd_pins[8] = GPIO_Pin_2;
  kbd_ports[8] = (uint32_t)GPIOB;
  kbd_pins[7] = GPIO_Pin_3;
  kbd_ports[7] = (uint32_t)GPIOB;
  kbd_pins[6] = GPIO_Pin_4;
  kbd_ports[6] = (uint32_t)GPIOB;
  kbd_pins[5] = GPIO_Pin_5;
  kbd_ports[5] = (uint32_t)GPIOB;
  kbd_pins[4] = GPIO_Pin_6;
  kbd_ports[4] = (uint32_t)GPIOB;
  kbd_pins[3] = GPIO_Pin_7;
  kbd_ports[3] = (uint32_t)GPIOB;
  kbd_pins[2] = GPIO_Pin_8;
  kbd_ports[2] = (uint32_t)GPIOB;
  kbd_pins[1] = GPIO_Pin_9;
  kbd_ports[1] = (uint32_t)GPIOB;
  kbd_pins[0] = GPIO_Pin_10;
  kbd_ports[0] = (uint32_t)GPIOB;
}


void kbd_init_pin(int pin_n, GPIOOType_TypeDef dir) {
  GPIO_InitTypeDef GPIO_InitStructure;

  GPIO_InitStructure.GPIO_Pin = kbd_pins[pin_n];
  GPIO_InitStructure.GPIO_Mode = dir;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
  GPIO_Init((GPIO_TypeDef *)kbd_ports[pin_n], &GPIO_InitStructure);
  //GPIO_Init(GPIOC, &GPIO_InitStructure);
}

uint8_t kbd_get_pin(int pin_n) {
  return  (uint8_t)GPIO_ReadInputDataBit((GPIO_TypeDef *)kbd_ports[pin_n], kbd_pins[pin_n]);
}

void kbd_set_pin(int pin_n, BitAction BitVal) {
  GPIO_WriteBit((GPIO_TypeDef *)kbd_ports[pin_n], kbd_pins[pin_n], BitVal);
}


void kbd_hw_init() {
	// clocks
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;


	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);


	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_1);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	USART_Cmd(USART1,ENABLE);

	// output leds
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}


