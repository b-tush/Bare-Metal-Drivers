/*
 * stm32f407xx_gpio_drv.h
 *
 *  Created on: 10-Aug-2021
 *      Author: tushar<tushar.bhanarkar05gmail.com>
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

/*
 * ===================>Peripheral Clock Enable/Disable<======================
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EorD);  											/* Pointer to the GPIO Base Address, Enable or Disable the Clock */

/*
 * ====================>Data Read and Write<=========_=======================
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);  									/*Return type is boolen*/
uint16_t  GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);  												    /*16 pin GPIO port*/
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * ====================>GPIO Init and De-Init<===============================
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);  																/*Parameter to GPIO Handler*/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * =====================>IRQ Configuration and ISR Handling<=================
 */

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EorD);
void GPIO_IRQHandling(uint8_t PinNumber);



#endif /* INC_STM32F407XX_GPIO_DRV_H_ */
