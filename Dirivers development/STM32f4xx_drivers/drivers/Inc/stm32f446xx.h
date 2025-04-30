/*
 * stm32f446xx.h
 *
 *  Created on: Dec 26, 2024
 *      Author: kfakh
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_
#include <stdint.h>
// base memory addresses
#define FLASH_BASEADDR 			0X08000000U
#define SRAM1_BASEADDR			0X20000000U
#define SRAM2_BASEADDR			0x2001C000U
#define ROM_BASEADDR			0x1FFF0000U
#define SRAM 					SRAM1_BASEADDR
// base bus address
#define PERIPH_BASE					0X40000000U
#define APB1PERIPH_BASE			PERIPH_BASE
#define APB2PERIPH_BASE			0X40010000U
#define AHB1PERIPH_BASE 		0X40020000U
#define AHB2PERIPH_BASE			0X50000000U
// base address of AHB1 bus peripherals
#define GPIOA_BASEADDR			(AHB1PERIPH_BASE+0x0000)
#define GPIOB_BASEADDR			(AHB1PERIPH_BASE+0x0400)
#define GPIOC_BASEADDR			(AHB1PERIPH_BASE+0x0800)
#define GPIOD_BASEADDR			(AHB1PERIPH_BASE+0x0C00)
#define GPIOE_BASEADDR			(AHB1PERIPH_BASE+0x1000)
#define GPIOF_BASEADDR			(AHB1PERIPH_BASE+0x1400)
#define GPIOG_BASEADDR			(AHB1PERIPH_BASE+0x1800)
#define GPIOH_BASEADDR			(AHB1PERIPH_BASE+0x1C00)
#define RCC_BASEADDR			(AHB1PERIPH_BASE+0x3800)
// base address of APB1 bus peripherals
#define I2C1_BASEADDR			(APB1PERIPH_BASE+0x5400)
#define I2C2_BASEADDR			(APB1PERIPH_BASE+0x5800)
#define I2C3_BASEADDR			(APB1PERIPH_BASE+0x5C00)

#define SPI2_BASEADDR			(APB1PERIPH_BASE+0x3800)
#define SPI3_BASEADDR			(APB1PERIPH_BASE+0x3C00)

#define USART2_BASEADDR			(APB1PERIPH_BASE+0x4400)
#define USART3_BASEADDR			(APB1PERIPH_BASE+0x4800)
#define UART4_BASEADDR			(APB1PERIPH_BASE+0x4C00)
#define UART5_BASEADDR			(APB1PERIPH_BASE+0x5000)

// base address of APB2 bus peripherals
#define EXTI_BASEADDR			(APB2PERIPH_BASE+0x3C00)
#define SPI_BASEADDR			(APB1PERIPH_BASE+0x3000)
#define SYSCFG_BASEADDR			(APB1PERIPH_BASE+0x3800)
#define USART1_BASEADDR			(APB1PERIPH_BASE+0x1000)
#define USART6_BASEADDR			(APB1PERIPH_BASE+0x1400)



typedef struct
{
    volatile uint32_t MODER;    /* Address offset: 0x00 */
    volatile uint32_t OTYPER;   /* Address offset: 0x04 */
    volatile uint32_t OSPEEDR;  /* Address offset: 0x08 */
    volatile uint32_t PUPDR;    /* Address offset: 0x0C */
    volatile uint32_t IDR;      /* Address offset: 0x10 */
    volatile uint32_t ODR;      /* Address offset: 0x14 */
    volatile uint32_t BSRRL;    /* Address offset: 0x18 */
    volatile uint32_t BSRRH;    /* Address offset: 0x1A */
    volatile uint32_t LCKR;     /* Address offset: 0x1C */
    volatile uint32_t AFR[2];   /* AFL and AFH Address offset: 0x20-0x24 */
} GPIO_RegDef_t;


typedef struct
{
    volatile uint32_t CR;                 /*     Address offset: 0x00 */
    volatile uint32_t PLLCFGR;            /*     Address offset: 0x04 */
    volatile uint32_t CFGR;               /*     Address offset: 0x08 */
    volatile uint32_t CIR;                /*     Address offset: 0x0C */
    volatile uint32_t AHB1RSTR;           /*     Address offset: 0x10 */
    volatile uint32_t AHB2RSTR;           /*     Address offset: 0x14 */
    volatile uint32_t AHB3RSTR;           /*     Address offset: 0x18 */
    uint32_t RESERVED0;                   /*     Address offset: 0x1C */
    volatile uint32_t APB1RSTR;           /*     Address offset: 0x20 */
    volatile uint32_t APB2RSTR;           /*     Address offset: 0x24 */
    uint32_t RESERVED1[2];                /*   	 Address offset: 0x28-0x2C */
    volatile uint32_t AHB1ENR;            /*     Address offset: 0x30 */
    volatile uint32_t AHB2ENR;            /*     Address offset: 0x34 */
    volatile uint32_t AHB3ENR;            /*     Address offset: 0x38 */
    uint32_t RESERVED2;                   /*     Address offset: 0x3C */
    volatile uint32_t APB1ENR;            /*     Address offset: 0x40 */
    volatile uint32_t APB2ENR;            /*     Address offset: 0x44 */
    uint32_t RESERVED3[2];                /*     Address offset: 0x48-0x4C */
    volatile uint32_t AHB1LPENR;          /*     Address offset: 0x50 */
    volatile uint32_t AHB2LPENR;          /*     Address offset: 0x54 */
    volatile uint32_t AHB3LPENR;          /*     Address offset: 0x58 */
    uint32_t RESERVED4;               	  /* 	 Address offset: 0x5C */
    volatile uint32_t APB1LPENR;          /*     Address offset: 0x60 */
    volatile uint32_t APB2LPENR;          /*     Address offset: 0x64 */
    uint32_t RESERVED5[2];            	  /*     Address offset: 0x68-0x6C */
    volatile uint32_t BDCR;               /*     Address offset: 0x70 */
    volatile uint32_t CSR;                /*     Address offset: 0x74 */
    uint32_t RESERVED6[2];           	  /*     Address offset: 0x78-0x7C */
    volatile uint32_t SSCGR;              /*     Address offset: 0x80 */
    volatile uint32_t PLLI2SCFGR;         /*     Address offset: 0x84 */
    volatile uint32_t PLLSAICFGR;         /*     Address offset: 0x88 */
    volatile uint32_t DCKCFGR;            /*     Address offset: 0x8C */
    volatile uint32_t CKGATENR;           /*     Address offset: 0x90 */
    volatile uint32_t DCKCFGR2;           /*     Address offset: 0x94 */
} RCC_RegDef_t;


//GPIO_RegDef_t *pGPIOA = (GPIO_RegDef_t*)0x40020000;

/*pGPIOA->MODER = 25; // storing value 25 in to MODER register
*(0x40020000 + 0x00) = 25; // this is how compiler does

pGPIOA->ODR = 44; // storing value 44 in to ODR register
*(0x40020000 + 0x14) = 44; // this is how compiler does*/
//port definition
#define GPIOA ((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH ((GPIO_RegDef_t*) GPIOH_BASEADDR)
#define GPIOI ((GPIO_RegDef_t*) GPIOI_BASEADDR)
#define RCC	  ((RCC_RegDef_t*) RCC_BASEADDR)
// Clock enable macros GPIOx peripherals
#define GPIOA_PCLK_ENABLE() (RCC->AHB1ENR |= (1<<0)) //peripheral clock enable
#define GPIOB_PCLK_ENABLE() (RCC->AHB1ENR |= (1<<1)) //peripheral clock enable
#define GPIOC_PCLK_ENABLE() (RCC->AHB1ENR |= (1<<2)) //peripheral clock enable
#define GPIOD_PCLK_ENABLE() (RCC->AHB1ENR |= (1<<3)) //peripheral clock enable
#define GPIOE_PCLK_ENABLE() (RCC->AHB1ENR |= (1<<4)) //peripheral clock enable
#define GPIOF_PCLK_ENABLE() (RCC->AHB1ENR |= (1<<5)) //peripheral clock enable
#define GPIOG_PCLK_ENABLE() (RCC->AHB1ENR |= (1<<6)) //peripheral clock enable
#define GPIOH_PCLK_ENABLE() (RCC->AHB1ENR |= (1<<7)) //peripheral clock enable
#define GPIOI_PCLK_ENABLE() (RCC->AHB1ENR |= (1<<8)) //peripheral clock enable

// clock enable macros I2c peripherals
#define I2C1_PCLK_ENABLE() (RCC->APB1ENR |= (1<<21)) //peripheral clock enable

// clock disable

#define GPIOA_PCLK_DIS() (RCC->AHB1ENR &= ~(1<<0)) //peripheral clock DIS
#define GPIOB_PCLK_DIS() (RCC->AHB1ENR &= ~(1<<1)) //peripheral clock DIS
#define GPIOC_PCLK_DIS() (RCC->AHB1ENR &= ~(1<<2)) //peripheral clock enable
#define GPIOD_PCLK_DIS() (RCC->AHB1ENR &= ~(1<<3)) //peripheral clock DIS
#define GPIOE_PCLK_DIS() (RCC->AHB1ENR &= ~(1<<4)) //peripheral clock DIS
#define GPIOF_PCLK_DIS() (RCC->AHB1ENR &= ~(1<<5)) //peripheral clock DIS
#define GPIOG_PCLK_DIS() (RCC->AHB1ENR &= ~(1<<6)) //peripheral clock DIS
#define GPIOH_PCLK_DIS() (RCC->AHB1ENR &= ~(1<<7)) //peripheral clock DIS
#define GPIOI_PCLK_DIS() (RCC->AHB1ENR &= ~(1<<8)) //peripheral clock DIS


#endif /* INC_STM32F446XX_H_ */
