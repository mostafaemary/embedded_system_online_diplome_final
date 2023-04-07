/*
 * BUTTON.c
 *
 * Created: 9/30/2022 2:23:18 PM
 * Author: MOSTAFA EMARY
 */
#include "BUTTON.h"

void BUTTON_init(vuint8_t portnumber,vuint8_t pinnumber)//button is an input device
{
	DIO_init(portnumber,pinnumber,INPUT);
}
 BUTTON_S BUTTON_READ(vuint8_t portnumber,vuint8_t pinnumber)
 {
	 BUTTON_init(portnumber,pinnumber);
	 if( ((portnumber&(1<<pinnumber))>>pinnumber) )
        return PIN_HIGH;
    else
        return PIN_LOW;    
 }
 