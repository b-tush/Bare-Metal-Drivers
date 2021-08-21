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

#define PinNo    						pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber

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
				GPIOA_PCLK_EN();    					    /* #define GPIOA_PCLK_EN()    ( RCC->AHB1ENR | = (1<<0)) defined in header file */
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
							GPIOA_PCLK_DI();         		 /* #define GPIOA_PCLK_DI()      ( RCC->AHB1ENR & = ~(1<<0) ) defined in header file */
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
 * 						4. Configure the OutPut type
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
	uint32_t temp=0;
	//1. Configure the mode of GPIO pin.

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		 temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ));       /* In Pin Mode register configuring GPIO pin Modes i.e pin0 takes two bits  0x2=0, for pin1 1x2=2 starts with 2 */
		 pGPIOHandle->pGPIOx->MODER &= ~(0x3 << PinNo ); 															   /* Before Setting the Bit we need to Clear the Bit to avoid any overwrite*/
		 pGPIOHandle->pGPIOx->MODER |= temp;   																		   /* transfer the value to MODER register*/

	}

	else
	{
		//Interrupt Mode
	}
	//2. Configure the Speed.
	temp =0;

		temp = ( pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ));  /* In Pin Speed values */
		pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << PinNo);
		pGPIOHandle->pGPIOx->OSPEEDR |= temp; /* transfer the value to OSPEED register*/
	temp =0;

	//3. Configure the PuPd settings.

		temp = ( pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ));   /*Each pin takes 2 bits that's why we are multiplying by 2*/
		pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << PinNo);
		pGPIOHandle->pGPIOx->PUPDR |= temp;  /*Instead assignement operator use Bitwise OR for chanfing the particular bit w/o disturbing the rest */

		temp=0;

	//4. Configure the OutPut type

		temp= ( pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ));  /*left shift to 1 bit */
		pGPIOHandle->pGPIOx->OTYPER &= ~(0x3 << PinNo);
		pGPIOHandle->pGPIOx->OTYPER |= temp;
		temp =0;

	//5. Configure the Alt functionality.

		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode == GPIO_MODE_ALTFN)
		{
			uint8_t temp1, temp2;

			temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber /8;
			temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber %8;
			pGPIOHandle->pGPIOx->AFR[temp1] &= ~( 0xf << (4  * temp2 ));
			pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4* temp2));

		}


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

