/*
 * bsp.h
 *
 *  Created on: Dec 6, 2020
 *      Author: baram
 */

#ifndef SRC_BSP_BSP_H_
#define SRC_BSP_BSP_H_


#include "def.h"



#include "stm32f4xx_hal.h"



void bspInit(void);

void delay_ms(uint32_t ms);
void delay_us(uint32_t us);
uint32_t millis(void);


void Error_Handler(void);


#endif /* SRC_BSP_BSP_H_ */
