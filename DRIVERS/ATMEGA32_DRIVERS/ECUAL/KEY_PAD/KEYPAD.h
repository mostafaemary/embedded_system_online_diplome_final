/*
 * KEYPAD.h
 *
 * Created: 5/25/2023 9:05:29 PM
 *  Author: MOSTAFA
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../../MCAL/DIO.h"
#define R1 7
#define R2 6
#define R3 5
#define R4 4
#define C1 3
#define C2 2
#define C3 1
#define C4 0

#define KEYPAD_PORT PORTA
#define KEYPAD_PIN PINA
#define KEYPAD_DDR DDRA
#define POrt_number 'A'
#define DDR_NUM		'A'
void KEYPAD_INIT(void);
char KEYPAD_DETECTED(void);
#endif /* KEYPAD_H_ */