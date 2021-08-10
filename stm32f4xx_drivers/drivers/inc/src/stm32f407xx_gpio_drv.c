/*
 * stm32f407xx_gpio_drv.c
 *
 *  Created on: 10-Aug-2021
 *      Author: tushar<tushar.bhanarkar05gmail.com>
 */

#include "stm32f407xx_gpio_drv.h"
#include "stm32f407xx.h"
#include<stdio.h>
#include<stdint.h>


/****************************************************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EorD)			/* Pointer to the GPIO Base Address, Enable or Disable the Clock */
{
	if(EorD == ENABLE)
		{
			if(pGPIOx == GPIOA)
			{
				GPIOA_PCLK_EN();
			}else if (pGPIOx == GPIOB)
			{
				GPIOB_PCLK_EN();
			}else if (pGPIOx == GPIOC)
			{
				GPIOC_PCLK_EN();
			}else if (pGPIOx == GPIOD)
			{
				GPIOD_PCLK_EN();
			}else if (pGPIOx == GPIOE)
			{
				GPIOE_PCLK_EN();
			}else if (pGPIOx == GPIOF)
			{
				GPIOF_PCLK_EN();
			}else if (pGPIOx == GPIOG)
			{
				GPIOG_PCLK_EN();
			}else if (pGPIOx == GPIOH)
			{
				GPIOH_PCLK_EN();
			}else if (pGPIOx == GPIOI)
			{
				GPIOI_PCLK_EN();
			}
		}
		else
		{
			if(pGPIOx == GPIOA)
						{
							GPIOA_PCLK_DI();
						}else if (pGPIOx == GPIOB)
						{
							GPIOB_PCLK_DI();
						}else if (pGPIOx == GPIOC)
						{
							GPIOC_PCLK_DI();
						}else if (pGPIOx == GPIOD)
						{
							GPIOD_PCLK_DI();
						}else if (pGPIOx == GPIOE)
						{
							GPIOE_PCLK_DI();
						}else if (pGPIOx == GPIOF)
						{
							GPIOF_PCLK_DI();
						}else if (pGPIOx == GPIOG)
						{
							GPIOG_PCLK_DI();
						}else if (pGPIOx == GPIOH)
						{
							GPIOH_PCLK_DI();
						}else if (pGPIOx == GPIOI)
						{
							GPIOI_PCLK_DI();
						}
		}
}



/*
 * ====================>Data Read and Write<=========_=======================
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)  									/*Return type is boolen*/
{

}

uint16_t  GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)  												    /*16 pin GPIO port*/
{

}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber, uint8_t Value)
{

}


void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
}

/*********************************************************************
 * @fn      		  - GPIO_Init
 *
 * @brief             - Initialise GPIO port, GPIO pin.
 *
 * 						1. Configure the mode of GPIO pin.
 * 						2. Configure the Speed.
 * 						3. Configure the PuPd settings.
 * 						4. Configure the Optype
 * 						5. Configure the Alt functionality.
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)																/*Parameter to GPIO Handler*/
{

}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

}

/*
 * =====================>IRQ Configuration and ISR Handling<=================
 */

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EorD)
{

}

void GPIO_IRQHandling(uint8_t PinNumber)
{

}

