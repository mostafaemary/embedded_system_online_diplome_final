/*
 * BUTTON.h
 *
 * Created: 9/30/2022 2:22:59 PM
 *  Author: MOSTAFA
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include"../../MCAL/DIO.h"

#define B_A PORT_A 
#define B_B PORT_B 
#define B_C PORT_C 
#define B_D PORT_D 

typedef enum BUTTON_S
{
	PIN_LOW,PIN_HIGH
}BUTTON_S;
void BUTTON_init(vuint8_t portnumber,vuint8_t pinnumber);//button is an input device
BUTTON_S BUTTON_READ(vuint8_t portnumber,vuint8_t pinnumber);


#endif /* BUTTON_H_ */
