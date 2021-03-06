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

/****************************************************************************************************
 * @fn      		  - GPIO_ReadFromInputPin
 *
 * @brief             - T
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - Pin Number
 * @param[in]         -
 *
 * @return            -  1 or 0
 *
 * @Note              -  none
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)  									/*Return type is boolen*/
{
  uint8_t value;
  value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
  return value;

}

/****************************************************************************************************
 * @fn      		  - GPIO_ReadFromInputPort
 *
 * @brief             - GPIO IDR has 16-bit memory mapped data register,
 * 						The data I/P through the I/O are stored into the I/P data register(IDR)
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -  none
 */

uint16_t  GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)  										    /*16 pin GPIO port*/
{
uint16_t value;
value = (uint16_t) (pGPIOx->IDR);
return value;

}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber, uint8_t Value)
{
 if(Value == GPIO_PIN_SET)
 {
	 pGPIOx->ODR |= (1<<PinNumber);   /*Write 1 to the output data register at the bit field corresponding to the pin Number*/
 }else
 {
	 pGPIOx->ODR &= ~(1<<PinNumber);  /*Write 0 to the output data register at the bit field corresponding to the pin Number*/
 }


}


/****************************************************************************************************
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             - GPIO ODR has 16-bit memory mapped data register,
 * 						The data I/P through the I/O are stored into the I/P data register(IDR)
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -  none
 */


void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
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
 * @param[in]         - GPIOHandle
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)																				/*Parameter to GPIO Handler*/
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
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)  		 	/* Configure the Interrupt for Falling Edge*/
		{
			  EXTI->EXTI_FTSR |= (1 << PinNo );                                                    //Configure FTSR register
			  //Clear the corresponding RTSR Bit
			  EXTI->EXTI_RTSR &= ~(1 << PinNo);
		}else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT) 		/* Configure the Interrupt for Rising Edge*/
		{
			EXTI->EXTI_RTSR |= (1 << PinNo );                                                  //Configure RTSR regsiter
			//Clear the FTSR bit to avoid any malfunctioning
			EXTI->EXTI_FTSR &= ~(1 << PinNo);
		}else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
		{
			//Configure the FTSR and RTSR register.
			EXTI->EXTI_FTSR |= (1 << PinNo);
			EXTI->EXTI_RTSR &= ~(1 << PinNo);

		}

		//2. COnfigure the GPIO port selection in SYSCFG_EXTICR
		uint8_t temp1= pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;   			//4 dedicated SYSCFG_EXTICR register.
		uint8_t temp2= pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;              // 4 bits are reserved for each EXTI section

		uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYSCFG_PCLK_EN();
		SYSCFG->EXTICR[temp1] =  portcode << (temp2 *4);                          // Shift to every 4bit for new section

		// 3. Enable the interrupt delivery using IMR

		EXTI->EXTI_IMR |= (1 << PinNo);

	}
	//2. Configure the Speed.
	temp =0;

		temp = ( pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ));  			/* In Pin Speed values */
		pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << PinNo);
		pGPIOHandle->pGPIOx->OSPEEDR |= temp; /* transfer the value to OSPEED register*/
	temp =0;

	//3. Configure the PuPd settings.

		temp = ( pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ));   /*Each pin takes 2 bits that's why we are multiplying by 2*/
		pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << PinNo);
		pGPIOHandle->pGPIOx->PUPDR |= temp;  																			  /*Instead assignement operator use Bitwise OR for chanfing the particular bit w/o disturbing the rest */

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

/*********************************************************************
 * @fn      		  - GPIO_DeInit
 *
 * @brief             - Disable the GPIO peripheral
 *
 *
 *
 * @param[in]         -  GPIO_RegDef_t
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -  Using RCC AHB1RSTR regsiter we are resetting or deinitializing the GPIO peripheral
 */

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
				{
					GPIOA_REG_RESET();           				/*Using RCC AHB1RSTR regsiter we are resetting or deinitializing the GPIO peripheral */
				}else if (pGPIOx == GPIOB)
				{
					GPIOB_REG_RESET();
				}else if (pGPIOx == GPIOC)
				{
					GPIOC_REG_RESET();
				}else if (pGPIOx == GPIOD)
				{
					GPIOD_REG_RESET();
				}else if (pGPIOx == GPIOE)
				{
					GPIOE_REG_RESET();
				}else if (pGPIOx == GPIOF)
				{
					GPIOF_REG_RESET();
				}else if (pGPIOx == GPIOG)
				{
					GPIOG_REG_RESET();
				}else if (pGPIOx == GPIOH)
				{
					GPIOH_REG_RESET();
				}else if (pGPIOx == GPIOI)
				{
					GPIOI_REG_RESET();
				}
}

/*
 * =====================>IRQ Configuration and ISR Handling<=================
 * Note: 81 IRQ number is Implemented in the device by the vendor
 */

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EorD)   // IRQ Number, Priority, Enable/Disable
{
	if(EorD == ENABLE)
	{
		if(IRQNumber <= 31)                           // Program NVIC ISER0 Register if IRQNumber less than 32   (Setting/Enabling IRQ)
		{
			*NVIC_ISER0  |= (1 << IRQNumber);

		}else if(IRQNumber > 31 && IRQNumber < 64)    // Program NVIC ISER1 Register if IRQNumber less than 64
		{
			*NVIC_ISER1 |= (1 << (IRQNumber % 32));    // Mod of 32 IRQ No. will SET the Oth bit, henceforth Mod od 33 IRQ No. will set 1st Bit.

		}else if(IRQNumber > 64 && IRQNumber < 96)	  // Program NVIC ISER2 Register if IRQNumber less than 96
		{
			*NVIC_ISER2 |= (1 << (IRQNumber % 64));    // Mod of 64 IRQ No. will SET the Oth bit, henceforth Mod od 65 IRQ No. will set 1st Bit.
		}
	}else
	{
		if(IRQNumber <= 31)                           // Program NVIC ICER0 Register if IRQNumber less than 32  (Clearing /Disabling IRQ)
		 {
			*NVIC_ICER0  |= (1 << IRQNumber);
     	 }else if(IRQNumber > 31 && IRQNumber < 64)    // Program NVIC ICER1 Register if IRQNumber less than 64
		 {
     		*NVIC_ICER1  |= (1 << (IRQNumber %32));
		 }else if(IRQNumber > 64 && IRQNumber < 96)	  // Program NVIC ICER2 Register if IRQNumber less than 96
		 {
			 *NVIC_ICER2  |= (1 << (IRQNumber %64));
		 }
	}

}

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority)   //Priority register Configuration
{
	     //1.  Finding IPR Register. e.g. (IRQNumber)/4
	   uint8_t iprx = IRQNumber/4;
	     //2. Finding the IPR section e.g. (IRQNumber)%4
	   uint8_t iprx_section = IRQNumber % 4;
	   uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED) ; // Each section of 8 bits. In which lower 4 bits are RESERVED and cannot be configured

	   *(NVIC_PR_BASEADDR + (iprx * 4)) |= (IRQPriority << shift_amount );

}

void GPIO_IRQHandling(uint8_t PinNumber)
{
  //Clear the PR register corresponding to the Pin Number
	if(EXTI->EXTI_PR & (1 << PinNumber))  // to check if bit is 0 set to 1
	{
		//Clear (set the PR once ISR is serviced)
		EXTI->EXTI_PR |= (1 << PinNumber);
	}
}

