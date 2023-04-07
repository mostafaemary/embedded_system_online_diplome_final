/*
 * first.c
 *
 * Created: 9/29/2022 9:17:25 AM
 *  Author: MOSTAFA EMARY
 */ 

//#include <avr/io.h>
//#include "registers.h"
#include "ECUAL/LED_DRIVER/LED.h"
//#include "NORMAL MODE/normal.h"
#include "ECUAL/BUTTON_DRIVER/BUTTON.h"
#include "APPLICATION/APPLICATION.h"
//#define F_CPU 1000000U
//#include <util/delay.h>

//button interrupt
int main(void)
{
		
		APP_INIT();
		return 0;

}
ISR(EXT_INT(1))
{
	LED_ON(LED_D,5);
	delay1(1);
}
ISR(EXT_INT(2))
{
	LED_ON(LED_D,6);
	delay1(1);
}ISR(EXT_INT(3))
{
	LED_ON(LED_D,7);
	delay1(1);
}