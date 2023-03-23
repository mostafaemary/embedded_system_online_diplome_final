typedef volatile unsigned int vint32_t;
#include"stdint.h"
#define RCC_BASE    0x40021000
#define PORTA_BASE  0x40010800
#define RCC_APB2ENR *(vint32_t*) (RCC_BASE+0x18)
#define PORTA_ODR *(vint32_t*) (PORTA_BASE+0x0c)
#define PORTA_CRH *(vint32_t*) (PORTA_BASE+0x04)
#define RCC_CFGR *(vint32_t*) (RCC_BASE+0x04)
#define RCC_CR *(vint32_t*) (RCC_BASE+0x00)

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
volatile ACCESS_PORTA*access_a=(volatile ACCESS_PORTA* )(PORTA_BASE+0x0c);


int main()
{
	//RCC_APB2ENR|=1<<2;
	PORTA_CRH &=0xff0fffff;
	PORTA_CRH |=0x00200000;


	//	Bits 21:18 PLLMUL: PLL multiplication factor
	//	These bits are written by software to define the PLL multiplication factor. These bits can be
	//	written only when PLL is disabled.
	//	Caution: The PLL output frequency must not exceed 72 MHz.
	//	0000: PLL input clock x 2
	//	0001: PLL input clock x 3
	//	0010: PLL input clock x 4
	//	0011: PLL input clock x 5
	//	0100: PLL input clock x 6
	//	0101: PLL input clock x 7
	/////	0110: PLL input clock x 8
	//	0111: PLL input clock x 9
	//	1000: PLL input clock x 10
	//	1001: PLL input clock x 11
	//	1010: PLL input clock x 12
	//	1011: PLL input clock x 13
	//	1100: PLL input clock x 14
	//	1101: PLL input clock x 15
	//	1110: PLL input clock x 16
	//	1111: PLL input clock x 16

	RCC_CFGR|=(0b0110<<18);











	//	Bits //13:11 PPRE2: APB high-speed prescaler (APB2)
	//	Set and cleared by software to control the division factor of the APB high-speed clock
	//	(PCLK2).
	//	0xx: HCLK not divided
	//	100: HCLK divided by 2
	//	//101: HCLK divided by 4
	//	110: HCLK divided by 8
	//	111: HCLK divided by 16


	/*lab2_1	RCC_CFGR|=1<<11;
	RCC_CFGR|=1<<13;//RCC_CFGR|=(0b101<<11);*/
	RCC_CFGR|=(0b101<<11);


	//	Bits //10:8 PPRE1: APB low-speed prescaler (APB1)
	//	Set and cleared by software to control the division factor of the APB low-speed clock
	//	(PCLK1).
	//	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	//	0xx: HCLK not divided
	//	100: HCLK divided by 2
	//	101: HCLK divided by 4
	//	110: HCLK divided by 8
	//	111: HCLK divided by 16

	/*lab2_1 RCC_CFGR|=(0b100<<8);*/
	RCC_CFGR|=(0b100<<8);


	//	Bit 24 PLLON: PLL enable
	//	Set and cleared by software to enable PLL.
	//	Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
	//	PLL clock is used as system clock or is selected to become the system clock.
	//	0: PLL OFF
	//	//1: PLL ON
	RCC_CFGR|=(0b10<<0);
	RCC_CR |=1<<24;




	while(1)
	{
		int i;
		for(i=0;i<4000;i++)
			access_a->PORT_FIELD.LED=1;
		//PORTA_ODR|=1<<13;
		for(i=0;i<4000;i++)
			access_a->PORT_FIELD.LED=0;
		//PORTA_ODR &=~(1<<13);
	}
	return 0;
}
