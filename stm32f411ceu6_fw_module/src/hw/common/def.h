/*
 * def.h
 *
 *  Created on: Dec 6, 2020
 *      Author: baram
 */

#ifndef SRC_COMMON_DEF_H_
#define SRC_COMMON_DEF_H_

//TODO 공용헤더 파일 및 모듈 채널 설정
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>


#define _DEF_LED1           	0


#define _DEF_UART1          	0
#define _DEF_UART2          	1


#define _DEF_INPUT				0
#define _DEF_INPUT_PULLUP		1
#define _DEF_INPUT_PULLDOWN		2
#define _DEF_OUTPUT				3
#define _DEF_OUTPUT_PULLUP		4
#define _DEF_OUTPUT_PULLDWON	5


#endif /* SRC_COMMON_DEF_H_ */
