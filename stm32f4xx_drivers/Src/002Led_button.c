/*
 * 002Leb_button.c
 *
 *  Created on: 30-Aug-2021
 *      Author: tushar
 */


#include "stm32f407xx.h"
#include "stdio.h"
#include "stm32f407xx_gpio_drv.h"     //Included in device specific header as well



void delay(void)
{
	for(uint32_t i = 0; i< 500000/4; i++);
}


int main(void)
{
	GPIO_Handle_t GpioLed, GpioBtn;
	GpioLed.pGPIOx = GPIOD;

	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;

	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;

	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);
	GPIO_Init(&GpioLed);


	GpioBtn.pGPIOx = GPIOA;

	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;

	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;

	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;


	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

		GPIO_PeriClockControl(GPIOA,ENABLE);
		GPIO_Init(&GpioBtn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == 1 )
			delay();
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);



	}
	return 0;
	}
