/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
typedef volatile unsigned int vint32_t;

#include"stdint.h"
#define RCC_BASE    0x40021000
#define PORTA_BASE  0x40010800
#define RCC_APB2ENR *((volatile vint32_t*) (RCC_BASE+0x18))
typedef union
{
	vint32_t  ALL_PORTA;
	struct{
		vint32_t REVERSED:13;
		vint32_t LED:1;
		vint32_t reversed:6;
		vint32_t chr_acces:4;
	}PORT_FIELD;
}ACCESS_PORTA;
volatile ACCESS_PORTA*access_a=(volatile ACCESS_PORTA* )PORTA_BASE;
int main()
{
	RCC_APB2ENR|=1<<2;
	access_a->PORT_FIELD.chr_acces=2;
	while(1)
	{
		int i;
		for(i=0;i<5000;i++)
		{
			access_a->PORT_FIELD.LED=1;
		}
		for(i=0;i<5000;i++)
		{
			access_a->PORT_FIELD.LED=0;
		}

	}
	return 0;
}



//#define RCC_BASE 0x40021000
//#define PORTA_BASE 40010800
//#define RCC_APB2ENR    *(volatile uint32_t *)(RCC_BASE + 0X18)
//#define GPIO_CRH  	   *(volatile uint32_t *)(PORTA_BASE + 0X04)
//#define GPIO_ODR 	   *(volatile uint32_t *)(PORTA_BASE + 0X0C)
//
//
//typedef union{
//
//	vint32_t ALLPORTS;
//	struct{
//
//
//		vint32_t RESERVED:13;
//		vint32_t PIN13:1;
//	}PIN;
//
//
//} R_ODR_t;
//
//volatile R_ODR_t* R_ODR =(volatile R_ODR_t *)(PORTA_BASE+0x0c);
//int main(void)
//{
//	RCC_APB2ENR|=1<<2;//to set bin 2 //it will enable the gpio (data sheet)
//	GPIO_CRH &=0xff0fffff;
//	GPIO_CRH |=0x00200000;
//	while(1){
//	GPIO_ODR |=1<<13;
//	for (int i=0;i<5000;i++);
//	GPIO_ODR &=~(1<<13);
//	for (int i=0;i<5000;i++);
//	}
//	return 0;
//}