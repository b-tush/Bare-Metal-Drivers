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
uint8_t GPIO_PinNumber;							/* Possible Values from @GPIO_PIN_NUMBERS	*/
uint8_t GPIO_PinMode;							/* Possible Values from @GPIO_PIN_MODES  	*/
uint8_t GPIO_PinSpeed;							/* Possible Values from @GPIO_PIN_SPEED  	*/
uint8_t GPIO_PinPuPdControl;					/* Possible Values from @GPIO_PIN_PUPD      */
uint8_t GPIO_PinOPType;							/* Possible Values from @GPIO_PIN_OP_TYPE   */
uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*
 * This is a Handle Structure for a GPIO pin
 */

typedef struct
{
	GPIO_RegDef_t *pGPIOx;    				/* This holds the base address of the GPIO port to which pin belongs	*/
	GPIO_PinConfig_t GPIO_PinConfig;		/* This holds the GPIO pin configuration settings						*/
}GPIO_Handle_t;


/*
 * @GPIO_PIN_MODES
 * GPIO Pin Modes MACROS
 */

#define GPIO_MODE_IN  		0         /*GPIO Input Mode                           	*/
#define GPIO_MODE_OUT 		1		  /*GPIO Output Mode                          	*/
#define GPIO_MODE_ALTFN		2		  /*GPIO Alternate Function Mode              	*/
#define GPIO_MODE_ANALOG	3		  /*GPIO Analog Mode                          	*/
#define GPIO_MODE_IT_FT		4         /*GPIO input Interrupt falling Edge         	*/
#define GPIO_MODE_IT_RT		5         /*GPIO input Interrupt Rising Edge            */
#define GPIO_MODE_IT_RFT	6		  /*GPIO input Interrupt Rising and Falling edge*/

/*
 * @GPIO_PIN_OP_TYPE
 * GPIO Pin Output Types MACROS
 */

#define GPIO_OP_TYPE_PP 	0           /*Output PUSH-PULL 							*/
#define GPIO_OP_TYPE_OD 	1			/*Output OPEN DRAIN							*/


/*
 * @GPIO_PIN_SPEED
 * GPIO Pin Output Speed register MACROS
 */

#define GPIO_SPEED_LOW 		0   		/*GPIO Output Low Speed						*/
#define GPIO_SPEED_MED  	1			/*GPIO Output Med Speed						*/
#define GPIO_SPEED_FAST 	2			/*GPIO Output FAST Speed					*/
#define GPIO_SPEED_HIGH		3			/*GPIO Output HIGH Speed					*/

/*
 * @GPIO_PIN_PUPD
 * GPIO Pin pull-up/pull-down register MACROS
 */

#define GPIO_NO_PUPD 	0         	/*GPIO NO PULL-UP/PULL-DOWN register 			*/
#define GPIO_PU			1           /*GPIO PULL-UP 									*/
#define GPIO_PD			2           /*GPIO PULL-DOWN								*/

/*
 * @GPIO_PIN_NUMBERS
 * GPIO Pin Numbers
 */
#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15
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
