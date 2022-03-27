/*
 * gpio.h
 *
 *  Created on: 2021. 4. 2.
 *      Author: sungt
 */

#ifndef SRC_HW_COMMON_HW_INCLUDE_GPIO_H_
#define SRC_HW_COMMON_HW_INCLUDE_GPIO_H_

#include "hw_def.h"

#ifdef _USE_HW_GPIO

#define GPIO_MAX_CH				HW_GPIO_MAX_CH



bool gpioInit(void);
bool gpioPinMode(uint8_t ch, uint8_t mode);
void gpioPinWrite(uint8_t ch, bool value);
bool gpioPinRead(uint8_t ch);
void gpioPinToggle(uint8_t ch);




#endif /* _USE_HW_GPIO */

#endif /* SRC_HW_COMMON_HW_INCLUDE_GPIO_H_ */
