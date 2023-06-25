/*
 * hw_inits.h
 *
 *  Created on: 25. 6. 2023
 *      Author: stanislaw
 */

#ifndef HW_INITS_H_
#define HW_INITS_H_

#include <stdio.h>
#include <stdlib.h>
#include "stm32f0xx.h"

void kbd_init_pinout();
void kbd_init_pin(int pin_n, GPIOOType_TypeDef dir);
uint8_t kbd_get_pin(int pin_n);
void kbd_hw_init();



#endif /* HW_INITS_H_ */
