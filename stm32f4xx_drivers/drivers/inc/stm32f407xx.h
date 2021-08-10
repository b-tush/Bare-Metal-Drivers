/*
 * stm32f407xx.h
 *
 *  Created on: 06-Aug-2021
 *      Author: tushar<tushar.bhanarkar05gmail.com>
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include<stdint.h>
#define __vo volatile

/*
 * Generic MACROS
 */

#define ENABLE								 1
#define DISABLE 							 0
#define SET 								 ENABLE
#define RESET								 DISABLE
#define GPIO_PIN_SET						 SET
#define GPIO_PIN_RESET						 RESET


/*
 * base address of flash and SRAM memories
 */

#define FLASH_BASEADDR                                  0x08000000U          // (uint32_t)
#define SRAM1_BASEADDR									0x20000000U  		//112KB*1024= 1C00
#define SRAM2_BASEADDR									0x20001C00U 	  	/* SRAM1+112KB*/
#define ROM_BASEADDR 									0x1FFF0000U   		/*System Memory*/
#define SRAM 											SRAM1_BASEADDR
/*
 *  AHBx and APBx Bus peripheral base Address
 */
#define PERIPH_BASE										0x40000000U
#define APB1PERIPH_BASE									PERIPH_BASE
#define APB2PERIPH_BASE									0x40010000U
#define AHB1PERIPH_BASE									0x40020000U
#define AHB2PERIPH_BASE									0x50000000U

/*
 * Base addresses of peripheral which are connected on AHB1 Bus
 * =============================AHB1 Bus==============================
 * GPIOA GPIOB GPIOC GPIOD GPIOE GPIOF GPIOG  GPIOH GPIOI GPIOJ GPIOK RCC
 */

#define GPIOA_BASEADDR									(AHB1PERIPH_BASE + 0x0000)  /*0x40020000U*/
#define GPIOB_BASEADDR									(AHB1PERIPH_BASE + 0x0400)  /*0x40020400U*/
#define GPIOC_BASEADDR									(AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR									(AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR									(AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR									(AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR									(AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR									(AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASEADDR									(AHB1PERIPH_BASE + 0x2000)
#define RCC_BASEADDR									(AHB1PERIPH_BASE + 0x3800)  /*0x40023800U*/
//#define GPIOJ_BASEADDR									(AHB1PERIPH_BASE + 0x2400)
//#define GPIOK_BASEADDR									(AHB1PERIPH_BASE + 0x2800)

/*
 * Base addresses of peripheral which are connected on AHB1 Bus
 * =============================APB1 Bus==============================
 * I2C1 I2C2 I2C3 SPI2 SPI3 USART2 USART3 UART4 UART5
 */

#define I2C1_BASEADDR									(APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR									(APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR									(APB1PERIPH_BASE + 0x5C00)
#define SPI2_BASEADDR									(APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR									(APB1PERIPH_BASE + 0x3C00)
#define USART2_BASEADDR									(APB1PERIPH_BASE + 0x4400)
#define USART3_BASEADDR									(APB1PERIPH_BASE + 0x4800)
#define UART4_BASEADDR									(APB1PERIPH_BASE + 0x4C00)
#define UART5_BASEADDR									(APB1PERIPH_BASE + 0x5000)

/*
 * Base addresses of peripheral which are connected on AHB1 Bus
 * =============================APB2 Bus==============================
 * SPI1 USART1 USART6 EXT1 SYSCFG
 */

#define SPI1_BASEADDR									(APB2PERIPH_BASE + 0x3000)
#define USART1_BASEADDR									(APB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR									(APB2PERIPH_BASE + 0x1400)
#define EXTI_BASEADDR									(APB2PERIPH_BASE + 0x3C00)
#define SYSCFG_BASEADDR									(APB2PERIPH_BASE + 0x3800)

/*
 * Peripheral register definition structure
 * =============================GPIO==============================
 */

typedef struct
{
	__vo uint32_t MODER;  			/*GPIO port mode register   					offset=0x00		 */
	__vo uint32_t OTYPER;			/*GPIO port output type register  				offset=0x04 	 */
	__vo uint32_t OSPEEDR;			/*GPIO port output speed register  				offset=0x08 	 */
	__vo uint32_t PUPDR;			/*GPIO port pull-up/pull-down register  		offset=0x0C 	 */
	__vo uint32_t IDR;				/*GPIO port input data register			  		offset=0x10 	 */
	__vo uint32_t ODR;				/*GPIO port output data register		  		offset=0x14 	 */
	__vo uint32_t BSBRR;			/*GPIO port bit set/reset register  			offset=0x18 	 */
	__vo uint32_t LCKR;				/*GPIO port configuration lock register  		offset=0x1c 	 */
	__vo uint32_t AFR[2];			/*GPIO alternate function Low/High register  	offset=0x20-0x24 */
}GPIO_RegDef_t;

/*GPIO_RegDef_t *pGPIO=(GPIO_RegDef_t*)0x40020000U;
 * GPIO_RegDef_t *pGPIO =GPIOA;
 * GPIOA -> MODER = 15;
*/
/*
 * Peripheral definition (peripheral base address typecasted to GPIO_RegDef_t)
 */

#define GPIOA 			((GPIO_RegDef_t*)(GPIOA_BASEADDR))  /*(GPIO_RegDef_t*)0x40020000U*/
#define GPIOB			((GPIO_RegDef_t*)(GPIOB_BASEADDR))
#define GPIOC 			((GPIO_RegDef_t*)(GPIOC_BASEADDR))
#define GPIOD 			((GPIO_RegDef_t*)(GPIOD_BASEADDR))
#define GPIOE 			((GPIO_RegDef_t*)(GPIOE_BASEADDR))
#define GPIOF 			((GPIO_RegDef_t*)(GPIOF_BASEADDR))
#define GPIOG 			((GPIO_RegDef_t*)(GPIOG_BASEADDR))
#define GPIOH 			((GPIO_RegDef_t*)(GPIOH_BASEADDR))
#define GPIOI 			((GPIO_RegDef_t*)(GPIOI_BASEADDR))


/*
 * Peripheral register definition structure
 * =============================Reset & Control Clock==============================
 */

typedef struct
{
	__vo uint32_t CR;  								/*RCC clock control register   									offset=0x00		 */
	__vo uint32_t PLLCFGR;							/*RCC PLL configuration register  								offset=0x04 	 */
	__vo uint32_t CFGR;								/*RCC clock configuration register  							offset=0x08 	 */
	__vo uint32_t CIR;								/*RCC clock interrupt register  								offset=0x0C 	 */
	__vo uint32_t AHB1RSTR;							/*RCC AHB1 peripheral reset register			  				offset=0x10 	 */
	__vo uint32_t AHB2RSTR;							/*RCC AHB2 peripheral reset register		  					offset=0x14 	 */
	__vo uint32_t AHB3RSTR;							/*RCC AHB3 peripheral reset register  							offset=0x18 	 */
		 uint32_t Reserved0;						/*Reserved Bit  												offset=0x1c 	 */
	__vo uint32_t APB1RSTR;							/*RCC APB1 peripheral reset register  							offset=0x20		 */
	__vo uint32_t APB2RSTR;  						/*RCC APB2 peripheral reset register   							offset=0x24		 */
		 uint32_t Reserved1[2];						/*Reserved Bit 													offset=0x28-0x2c */
	__vo uint32_t AHB1ENR;							/*RCC AHB1 peripheral clock enable register  					offset=0x30 	 */
	__vo uint32_t AHB2ENR;							/*RCC AHB2 peripheral clock enable register  					offset=0x34 	 */
	__vo uint32_t AHB3ENR;							/*RCC AHB3 peripheral clock enable register			  			offset=0x38 	 */
		 uint32_t Reserved2;						/*Reserved Bit		  											offset=0x3c 	 */
	__vo uint32_t APB1ENR;							/*RCC APB1 peripheral clock enable register  					offset=0x40 	 */
	__vo uint32_t APB2ENR;							/*RCC APB2 peripheral clock enable register  					offset=0x44 	 */
		 uint32_t Reserved3[2];						/*Reserved Bit  												offset=0x48-0x4c */
		 uint32_t AHB1LPENR;						/*RCC AHB1 peripheral clock enable in low power mode register  	offset=0x50 	 */
	__vo uint32_t AHB2LPENR;						/*RCC AHB2 peripheral clock enable in low power mode register  	offset=0x54 	 */
	__vo uint32_t AHB3LPENR;						/*RCC AHB3 peripheral clock enable in low power mode register  	offset=0x58 	 */
		 uint32_t Reserved4;						/*Reserved Bit			  										offset=0x5c 	 */
		 uint32_t APB1LPENR;						/*RCC APB1 peripheral clock enable in low power mode register	offset=0x60 	 */
	__vo uint32_t APB2LPENR;						/*RCC APB2 peripheral clock enable in low power mode register  	offset=0x64 	 */
		 uint32_t Reserved5[2];						/*Reserved Bit 													offset=0x68-0x6c */
	__vo uint32_t BDCR;								/*RCC Backup domain control register  							offset=0x70 	 */
	__vo uint32_t CSR;								/*RCC clock control & status register  							offset=0x74 	 */
		 uint32_t Reserved6[2];						/*Reserved Bit 													offset=0x78-0x7c */
	__vo uint32_t SSCGR;							/*RCC spread spectrum clock generation register  				offset=0x80 	 */
	__vo uint32_t PLLI2SCFGR;						/*RCC PLLI2S configuration register 							offset=0x84      */
	__vo uint32_t PLLSAICFGR;
	__vo uint32_t DCKCFGR;
}RCC_RegDef_t;

//RCC_RegDef_t *pRCC= (RCC_RegDef_t*)0x40023800U

/*
 * Peripheral definition (peripheral base address typecasted to RCC_RegDef_t)
 */

#define RCC 			((RCC_RegDef_t*)(RCC_BASEADDR))  /*(RCC_RegDef_t*)0x40023800U*/

/*
 * ==================================================================================
 *  <=================Peripheral Clock Enable/Disable MACROS=======================>
 * ==================================================================================
 */

/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()      ( RCC->AHB1ENR | = (1<<0) )   /*Set 0th Bit of AHB1ENR register to configure GPIOA_EN */
#define GPIOB_PCLK_EN()      ( RCC->AHB1ENR | = (1<<1) )   /*Set 1th Bit of AHB1ENR register to configure GPIOB_EN */
#define GPIOC_PCLK_EN()      ( RCC->AHB1ENR | = (1<<2) )   /*Set 2th Bit of AHB1ENR register to configure GPIOC_EN */
#define GPIOD_PCLK_EN()      ( RCC->AHB1ENR | = (1<<3) )   /*Set 3th Bit of AHB1ENR register to configure GPIOD_EN */
#define GPIOE_PCLK_EN()      ( RCC->AHB1ENR | = (1<<4) )   /*Set 4th Bit of AHB1ENR register to configure GPIOE_EN */
#define GPIOF_PCLK_EN()      ( RCC->AHB1ENR | = (1<<5) )   /*Set 5th Bit of AHB1ENR register to configure GPIOF_EN */
#define GPIOG_PCLK_EN()      ( RCC->AHB1ENR | = (1<<6) )   /*Set 6th Bit of AHB1ENR register to configure GPIOG_EN */
#define GPIOH_PCLK_EN()      ( RCC->AHB1ENR | = (1<<7) )   /*Set 7th Bit of AHB1ENR register to configure GPIOH_EN */
#define GPIOI_PCLK_EN()      ( RCC->AHB1ENR | = (1<<8) )   /*Set 8th Bit of AHB1ENR register to configure GPIOI_EN */


/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI()      ( RCC->AHB1ENR & = ~(1<<0) )   /*ReSet 0th Bit of AHB1ENR register to configure GPIOA_EN */
#define GPIOB_PCLK_DI()      ( RCC->AHB1ENR & = ~(1<<1) )   /*ReSet 1th Bit of AHB1ENR register to configure GPIOB_EN */
#define GPIOC_PCLK_DI()      ( RCC->AHB1ENR & = ~(1<<2) )   /*ReSet 2th Bit of AHB1ENR register to configure GPIOC_EN */
#define GPIOD_PCLK_DI()      ( RCC->AHB1ENR & = ~(1<<3) )   /*ReSet 3th Bit of AHB1ENR register to configure GPIOD_EN */
#define GPIOE_PCLK_DI()      ( RCC->AHB1ENR & = ~(1<<4) )   /*ReSet 4th Bit of AHB1ENR register to configure GPIOE_EN */
#define GPIOF_PCLK_DI()      ( RCC->AHB1ENR & = ~(1<<5) )   /*ReSet 5th Bit of AHB1ENR register to configure GPIOF_EN */
#define GPIOG_PCLK_DI()      ( RCC->AHB1ENR & = ~(1<<6) )   /*ReSet 6th Bit of AHB1ENR register to configure GPIOG_EN */
#define GPIOH_PCLK_DI()      ( RCC->AHB1ENR & = ~(1<<7) )   /*ReSet 7th Bit of AHB1ENR register to configure GPIOH_EN */
#define GPIOI_PCLK_DI()      ( RCC->AHB1ENR & = ~(1<<8) )   /*ReSet 8th Bit of AHB1ENR register to configure GPIOI_EN */


/*
 * Clock Enable Macros for I2Cx Peripherals
 */

#define I2C1_PCLK_EN()       ( RCC->APB1ENR | = (1<<21) )   /*Set 21th Bit of APB1ENR register to configure I2C1_EN */
#define I2C2_PCLK_EN()       ( RCC->APB1ENR | = (1<<22) )   /*Set 22th Bit of APB1ENR register to configure I2C2_EN */
#define I2C3_PCLK_EN()       ( RCC->APB1ENR | = (1<<23) )   /*Set 23th Bit of APB1ENR register to configure I2C3_EN */

/*
 * Clock Disable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_DI()       ( RCC->APB1ENR & = ~(1<<21) )   /*ReSet 21th Bit of APB1ENR register to configure I2C1_EN */
#define I2C2_PCLK_DI()       ( RCC->APB1ENR & = ~(1<<22) )   /*ReSet 22th Bit of APB1ENR register to configure I2C2_EN */
#define I2C3_PCLK_DI()       ( RCC->APB1ENR & = ~(1<<23) )   /*ReSet 23th Bit of APB1ENR register to configure I2C3_EN */

/*
 * Clock Enable Macros for SPIx Peripherals
 */
#define SPI1_PCLK_EN()       ( RCC->APB2ENR | = (1<<12) )   /*Set 12th Bit of APB2ENR register to configure I2C1_EN */
#define SPI2_PCLK_EN()       ( RCC->APB1ENR | = (1<<14) )   /*Set 14th Bit of APB1ENR register to configure SPI2_EN */
#define SPI3_PCLK_EN()       ( RCC->APB1ENR | = (1<<15) )   /*Set 15th Bit of APB1ENR register to configure SPI3_EN */

/*
 * Clock Disable Macros for SPIx peripherals
 */
#define SPI1_PCLK_DI()       ( RCC->APB2ENR & = ~(1<<12) )   /*ReSet 12th Bit of APB2ENR register to configure I2C1_EN */
#define SPI2_PCLK_DI()       ( RCC->APB1ENR & = ~(1<<14) )   /*ReSet 14th Bit of APB1ENR register to configure SPI2_EN */
#define SPI3_PCLK_DI()       ( RCC->APB1ENR & = ~(1<<15) )   /*ReSet 15th Bit of APB1ENR register to configure SPI3_EN */
/*
 * Clock Enable Macros for USARTx peripherals
 */
#define USART1_PCLK_EN()     ( RCC->APB2ENR | = (1<<4)  )   /*Set 4th  Bit of APB2ENR register to configure USART1_EN */
#define USART2_PCLK_EN()     ( RCC->APB1ENR | = (1<<17) )   /*Set 17th Bit of APB1ENR register to configure USART2_EN */
#define USART3_PCLK_EN()	 ( RCC->APB1ENR | = (1<<18) )   /*Set 18th Bit of APB1ENR register to configure USART3_EN */
#define USART6_PCLK_EN()     ( RCC->APB2ENR | = (1<<5)  )   /*Set 5th  Bit of APB2ENR register to configure USART6_EN */

/*
 * Clock Disable Macros for USARTx peripherals
 */
#define USART1_PCLK_DI()     ( RCC->APB2ENR & = ~(1<<4)  )   /*ReSet 4th  Bit of APB2ENR register to configure USART1_EN */
#define USART2_PCLK_DI()     ( RCC->APB1ENR & = ~(1<<17) )   /*ReSet 17th Bit of APB1ENR register to configure USART2_EN */
#define USART3_PCLK_DI()	 ( RCC->APB1ENR & = ~(1<<18) )   /*ReSet 18th Bit of APB1ENR register to configure USART3_EN */
#define USART6_PCLK_DI()     ( RCC->APB2ENR & = ~(1<<5)  )   /*ReSet 5th  Bit of APB2ENR register to configure USART6_EN */

/*
 * Clock Enable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN()             ( RCC->APB2ENR | = (1<<14) )   /*Set 14th Bit of APB2ENR register to configure SYSCFG_EN */

/*
 * Clock Disable Macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_DI()             ( RCC->APB2ENR & = ~(1<<14) )   /*ReSet 14th Bit of APB2ENR register to configure SYSCFG_EN */


#endif /* INC_STM32F407XX_H_ */
