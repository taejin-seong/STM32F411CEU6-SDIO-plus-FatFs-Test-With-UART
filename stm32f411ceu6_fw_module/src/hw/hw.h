/*
 * hw.h
 *
 *  Created on: Dec 6, 2020
 *      Author: baram
 */

#ifndef SRC_HW_HW_H_
#define SRC_HW_HW_H_


#include "hw_def.h"

//TODO 모듈 헤더파일 선언
#include "led.h"
#include "uart.h"
#include "gpio.h"
#include "sd.h"
#include "fatfs.h"
#include "ff.h"


void hwInit(void);


#endif /* SRC_HW_HW_H_ */
