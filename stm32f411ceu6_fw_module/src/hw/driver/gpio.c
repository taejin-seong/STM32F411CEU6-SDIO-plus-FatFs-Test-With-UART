/*
 * gpio.c
 *
 *  Created on: 2021. 4. 2.
 *      Author: sungt
 */


#include "gpio.h"



typedef struct
{

	GPIO_TypeDef	*port;
	uint32_t		 pin;
	uint8_t 		 mode;
	GPIO_PinState	 on_state;
	GPIO_PinState	 off_state;
	bool			 init_value;

}gpio_tbl_t;


gpio_tbl_t gpio_tbl[GPIO_MAX_CH] =
		{
		    {GPIOB, GPIO_PIN_9, _DEF_INPUT_PULLUP, GPIO_PIN_RESET, GPIO_PIN_SET,   true},       // 0. SD CD

		};




bool gpioInit(void)
{
	bool ret = true;

	__HAL_RCC_GPIOB_CLK_ENABLE(); /* 클럭 설정  */

	for(int i = 0; i < GPIO_MAX_CH; i++)
	{
		gpioPinMode(i, gpio_tbl[i].mode);
		gpioPinWrite(i, gpio_tbl[i].init_value);
	}


	return ret;
}


bool gpioPinMode(uint8_t ch, uint8_t mode)
{
	bool ret = true;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	switch(mode)
	{
		case _DEF_INPUT:
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
			GPIO_InitStruct.Pull = GPIO_NOPULL;
			break;

		case _DEF_INPUT_PULLUP:
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
			GPIO_InitStruct.Pull = GPIO_PULLUP;
			break;

		case _DEF_INPUT_PULLDOWN:
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
			GPIO_InitStruct.Pull = GPIO_PULLDOWN;
			break;

		case _DEF_OUTPUT:
			GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; /* PUSH-PULL 출력 구조 */
			GPIO_InitStruct.Pull = GPIO_NOPULL;
			break;

		case _DEF_OUTPUT_PULLUP:
			GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; /* PUSH-PULL 출력 구조 */
			GPIO_InitStruct.Pull = GPIO_PULLUP;
			break;

		case _DEF_OUTPUT_PULLDWON:
			GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; /* PUSH-PULL 출력 구조 */
			GPIO_InitStruct.Pull = GPIO_PULLDOWN;
			break;
	  }


	GPIO_InitStruct.Pin = gpio_tbl[ch].pin;
	HAL_GPIO_Init(gpio_tbl[ch].port, &GPIO_InitStruct);


	return ret;
}


void gpioPinWrite(uint8_t ch, bool value)
{
	if( ch >= GPIO_MAX_CH)
	{
		return ;
	}

	if (value == true)
	{
		  HAL_GPIO_WritePin(gpio_tbl[ch].port, gpio_tbl[ch].pin, gpio_tbl[ch].on_state);
	}
	else
	{
		  HAL_GPIO_WritePin(gpio_tbl[ch].port, gpio_tbl[ch].pin, gpio_tbl[ch].off_state);
	}

}


bool gpioPinRead(uint8_t ch)
{

	bool ret = false;

	if( ch >= GPIO_MAX_CH)
	{
		return false;
	}

	if (HAL_GPIO_ReadPin(gpio_tbl[ch].port, gpio_tbl[ch].pin) == gpio_tbl[ch].on_state)
	{
		ret = true;
	}

	return ret;
}

void gpioPinToggle(uint8_t ch)
{
	if( ch >= GPIO_MAX_CH)
	{
		return;
	}

	HAL_GPIO_TogglePin(gpio_tbl[ch].port, gpio_tbl[ch].pin);

}
