/*
 * LED.h
 *
 * Created: 9/30/2022 2:22:41 PM
 *  Author: MOSTAFA
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO.h"
#define LED_A PORT_A
#define LED_B PORT_B
#define LED_C PORT_C
#define LED_D PORT_D
typedef enum LED_MODE
{
	OFF, ON,TOGGLE, LED_ERROR
}LED_MODE;
void LED_init(vuint8_t portnumber,vuint8_t pinnumber);
void PIN_MODE(vuint8_t portnumber,vuint8_t pinnumber,LED_MODE mode);
void LED_ON(vuint8_t portnumber,vuint8_t pinnumber);
void LED_OFF(vuint8_t portnumber,vuint8_t pinnumber);
void LED_TOGGLE(vuint8_t portnumber,vuint8_t pinnumber,float t);
void LED_BLINK(vuint8_t portnumber,vuint8_t pinnumber,int blink,float t);
vuint8_t* LED_STATE(vuint8_t portnumber,vuint8_t pinnumber,vuint8_t*value);
#endif /* LED_H_ */