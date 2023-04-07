/*
 * APPLICATION.h
 *
 * Created: 9/30/2022 2:29:08 PM
 *  Author: MOSTAFA
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
//#include "../MCAL/DIO.h"
//#include "../NORMAL MODE/normal.h"
//#include "../PEDESTRAIN MODE/predestrain.h"
#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"
#include "../ECUAL/LED_DRIVER/LED.h"
//interrupt handling
typedef enum INT_TRIGGER
{
    FALLING_EDGE, RISING_EDGE,ANY_LOGICAL, LEVEL
}INT_TRIGGER;
#define EXT_INT(X) __vector_##X
#define ISR(EXT_IN) void EXT_IN(void) __attribute__ ((signal,used));\
void EXT_IN(void)

//APP APIS

void APP_INIT(void);
void EXT_INTERRUPT_INIT(int mode,int INT_NUM);//

#endif /* APPLICATION_H_ */