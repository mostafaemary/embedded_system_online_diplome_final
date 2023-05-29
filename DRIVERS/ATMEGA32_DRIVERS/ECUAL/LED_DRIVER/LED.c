/*
 * LED.c
 *
 * Created: 9/30/2022 2:22:24 PM
 * Author: MOSTAFA EMARY
 */ 
#include "LED.h"
void LED_init(vuint8_t portnumber,vuint8_t pinnumber)
{
	DIO_init(portnumber, pinnumber , OUTPUT);
}
void PIN_MODE(vuint8_t portnumber,vuint8_t pinnumber,LED_MODE mode)
{
		LED_init(portnumber,pinnumber);
		if(mode==ON)
		DIO_write(portnumber, pinnumber, HIGH);
		else if(mode==OFF)
		DIO_write(portnumber, pinnumber, LOW);
		else
		DIO_toggle(portnumber,pinnumber);
}
void LED_ON(vuint8_t portnumber,vuint8_t pinnumber)
{
	LED_init(portnumber,pinnumber);
	PIN_MODE(portnumber, pinnumber, ON);
}
void LED_TOGGLE(vuint8_t portnumber,vuint8_t pinnumber,float t)
{
	LED_init(portnumber,pinnumber);
	PIN_MODE(portnumber, pinnumber, ON);
	delay1(t);
	PIN_MODE(portnumber, pinnumber, OFF);
	delay1(t);
}
void LED_OFF(vuint8_t portnumber,vuint8_t pinnumber)
{
	LED_init(portnumber,pinnumber);
	PIN_MODE(portnumber, pinnumber, OFF);
}
void LED_BLINK(vuint8_t portnumber,vuint8_t pinnumber,int blink,float t)
{
	while(blink--)
	{
		LED_TOGGLE(portnumber,pinnumber,t);
	}
}
/*vuint8_t* LED_STATE(vuint8_t portnumber,vuint8_t pinnumber,vuint8_t*value)
{
	
}*/