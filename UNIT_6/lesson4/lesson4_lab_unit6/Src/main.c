/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
//GPIO CONFIGURATION
#define PORTA_BASE  0x40010800
#define PORTA_ODR *(volatile unsigned int*) (PORTA_BASE+0x0c)
#define PORTA_CRH *(volatile unsigned int*) (PORTA_BASE+0x04)
#define PORTA_CRL *(volatile unsigned int*) (PORTA_BASE+0x00)
//alternate function configuration
#define AFIO_BASE  0x40010000
#define AFIO_EXTICR1 *(volatile unsigned int*) (AFIO_BASE+0x08)


//CLOCK CONFIGURATION
#define RCC_BASE 	0x40021000
#define RCC_APB2EN *(volatile unsigned int*)(RCC_BASE + 0x18)


//EXTINT CONFIGURATION
#define EXTI_BASE 0x40010400
//mask register
#define EXTI_IMR *(volatile unsigned int*) (EXTI_BASE+0x00)
//RISING TRIGGER SELECTION REGISTER
#define EXTI_RTSR *(volatile unsigned int*) (EXTI_BASE+0x08)
#define EXTI_PR *(volatile unsigned int*) (EXTI_BASE+0x14)
//NVIC CONFIGURATION
#define NVIC_EXTIE0 	*(volatile unsigned int*)(0xE000E100)

void CLOCK_INIT(void)
{
	// I/O port A clock enable:TRM
	RCC_APB2EN |=(1<<2);
	//PA alternative functional clock enable
	RCC_APB2EN |=(1<<0);
}
void GPIO_INIT(void)
{
	//pin13 oprta out pin
	PORTA_CRH &=0xff0fffff;
	PORTA_CRH |=0x00200000;
	//PA PIN0 FLOATING INPUT
	PORTA_CRL|=(0b01<<2);
}

int main()
{
	CLOCK_INIT();
	GPIO_INIT();
	//ENABLE EXTI LINE 0
	//1: Interrupt request from Line x is not masked
	EXTI_IMR |=(1<<0);
	//select the PA0 AS source input for EXTI0 external interrupt.
	AFIO_EXTICR1 |=(0b000<<0);
	//select rising edge
	EXTI_RTSR |=(1<<0);
	//ENABLE NVIC IRQ
	NVIC_EXTIE0 |=(1<<6);
	while(1)
	{

	}
	return 0;
}

void EXTI0_IRQHandler(void)
{
	//IRQ IS HAPPENED>>EXTI0_|_RISING EDGE
	//PINA13
	PORTA_ODR^=(1<<13);
	//Pending register: cleared by writing a ‘1’ into the bit.
	EXTI_PR |=(1<<0);
}
