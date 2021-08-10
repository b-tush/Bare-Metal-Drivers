/*
 * stm32f407xx_gpio_drv.h
 *
 *  Created on: 10-Aug-2021
 *      Author: tushar
 */

#ifndef INC_STM32F407XX_GPIO_DRV_H_
#define INC_STM32F407XX_GPIO_DRV_H_

#include "stm32f407xx.h"
#include "stdint.h"


/*
 * This is a Configuration structure for a GPIO pin
 * Pin Number, Mode, Speed, Output-type, Pullup-Pulldown, Alt.function mode
 */
typedef struct
{
uint8_t GPIO_PinNumber;
uint8_t GPIO_PinMode;
uint8_t GPIO_PinSpeed;
uint8_t GPIO_PinPuPdControl;
uint8_t GPIO_PinOPType;
uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*
 * This is a Handle Structure for a GPIO pin
 */
typedef struct
{
	GPIO_RegDef_t *pGPIOx;    									/* This holds the base address of the GPIO port to which pin belongs*/
	GPIO_PinConfig_t GPIO_PinConfig;							/* This holds the GPIO pin configuration settings*/
}GPIO_Handle_t;

/************************************************************************************************
 *                     API's Supported by the Driver
 *    For more information about the API's check the function definitions
 ***********************************************************************************************/




#endif /* INC_STM32F407XX_GPIO_DRV_H_ */
