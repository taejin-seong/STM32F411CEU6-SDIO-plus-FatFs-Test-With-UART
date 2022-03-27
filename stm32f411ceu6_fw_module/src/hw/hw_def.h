/*
 * hw_def.h
 *
 *  Created on: Dec 6, 2020
 *      Author: baram
 */

#ifndef SRC_HW_HW_DEF_H_
#define SRC_HW_HW_DEF_H_


#include "def.h"
#include "bsp.h"


//TODO 컴파일 유뮤 선언
#define _USE_HW_SD
#define _USE_HW_FATFS

#define _USE_HW_LED
#define      HW_LED_MAX_CH          1

#define _USE_HW_UART
#define		 HW_UART_MAX_CH		    1

#define	_USE_HW_GPIO
#define 	 HW_GPIO_MAX_CH			1

#define _PIN_GPIO_SDCARD_DETECT		0


#endif /* SRC_HW_HW_DEF_H_ */
