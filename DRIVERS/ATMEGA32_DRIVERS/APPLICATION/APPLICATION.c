/*
 * APPLICATION.c
 *
 * Created: 9/30/2022 2:28:50 PM
 *  Author: MOSTAFA EMARY
 */ 
#include "APPLICATION.h"
//#include "util/delay.h"
void EXT_INTERRUPT_INIT(int mode,int INT_NUM)
{
	if (INT_NUM==0)//INT0
	{
		if (mode==0)//falling edge
			{
				MCUCR|=(0b10<<0);
			}
		else if (mode==1)//rising edge
		{
			MCUCR |=(0b11<<0);
		}
		else if (mode==2)//any logical change
		{
			MCUCR |=(0b01<<0);
		}
		else//low level 
		{
			MCUCR &=~(0b11<<0);
		}
		GICR|=(1<<6);
		SREG|=(1<<7);
	}
	if (INT_NUM==1)//INT1
	{
		if (mode==0)//falling edge
			{
				MCUCR|=(0b10<<1);
			}
		else if (mode==1)//rising edge
		{
			MCUCR |=(0b11<<1);
		}
		else if (mode==2)//any logical change
		{
			MCUCR |=(0b01<<1);
		}
		else//low level 
		{
			MCUCR &=~(0b11<<1);
		}
		GICR|=(1<<7);
		SREG|=(1<<7);
	}
	if (INT_NUM==2)//INT2
	{
		GICR &=~(1<<5);
		if (mode==0)//falling edge
			{
				MCUCSR &=~(1<<6);
			}
		if (mode==1)//rising edge
		{
			MCUCSR |=(1<<6);
		}
		GICR|=(1<<5);
		SREG|=(1<<7);
	}
}
void APP_INIT(void)
{
	BUTTON_init(B_D,2);
	BUTTON_init(B_D,3);
	BUTTON_init(B_B,2);
	EXT_INTERRUPT_INIT(2,0);
	EXT_INTERRUPT_INIT(1,1);
	EXT_INTERRUPT_INIT(0,2);
				while(1)
				{
					LED_OFF(LED_D,5);
					LED_OFF(LED_D,6);
					LED_OFF(LED_D,7);
				}


}
