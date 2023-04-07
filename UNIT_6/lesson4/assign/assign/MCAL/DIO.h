/*
 * driver_lib.h
 *
 * Created: 9/30/2022 7:11:31 AM
 *  Author: MOSTAFA
 */ 


#ifndef DRIVER_LIB_H_
#define DRIVER_LIB_H_
#include "stdio.h"
#include "math.h"
#include "../register.h"
//internal typedefs
typedef volatile unsigned char vuint8_t;

//direction defines
typedef enum DIO_direction
{
	INPUT, OUTPUT
}DIO_direction;

//handler error defines 
typedef enum DIO_ERROR
{
	OK, ERROR
}DIO_ERROR;

//status defines
typedef enum DIO_value
{
	LOW, HIGH
}DIO_STATE;

typedef enum DELAY_E
{
    DELAY_OK,DELAY_ERROR
}DELAY_E;
//all driver macros
//PORTS DEFINES

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//think how to control pins?
//functions prototypes
DIO_ERROR DIO_init(vuint8_t portnumber,vuint8_t pinnumber, vuint8_t direction);// SET DIRECTION
DIO_ERROR DIO_write(vuint8_t portnumber,vuint8_t pinnumber, DIO_STATE state);//write on pin 
void DIO_toggle(vuint8_t portnumber,vuint8_t pinnumber);//toggle pin 
vuint8_t DIO_read(vuint8_t portnumber,vuint8_t pinnumber, vuint8_t *value);//read status
//TIMER APIS
DELAY_E DELAY(int prescaler,int intial_value,int no_overflow);
void delay1(double t);


#endif /* DRIVER_LIB_H_ */


