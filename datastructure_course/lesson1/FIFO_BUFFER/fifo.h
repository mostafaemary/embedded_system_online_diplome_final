/*
 * fifo.h
 *
 *  Created on: Aug 28, 2022
 *      Author: MOSTAFA
 */
#include"stdio.h"
#include"stdint.h"
#include"stdlib.h"

#ifndef FIFO_H_
#define FIFO_H_

#define PRINT(...) {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

//USER Configuration
//SELECT the element type (uint8_t , uint16_t , uint32_t , ....)
#define element_type uint8_t
// create buffer 1
#define width1 5
element_type uart_buffer[width1];

//FIFO DATA TYPES
typedef struct{
	unsigned int length;
	unsigned int count;
	element_type *tail;
	element_type *base;
	element_type *head;
}FIFO_BUFF_T;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}BUF_STATUS;

//FIFO APIS
BUF_STATUS FIFO_IS_FULL(FIFO_BUFF_T* FIFO_BUF);
BUF_STATUS FIFO_IS_NULL(FIFO_BUFF_T* FIFO_BUF);
BUF_STATUS FIFO_IS_EMPTY(FIFO_BUFF_T* FIFO_BUF);
void FIFO_CRATE(FIFO_BUFF_T* FIFO_BUF, element_type* buf,uint32_t length);
void FIFO_ENQUEUE(FIFO_BUFF_T* FIFO_BUF, element_type DATA);
void FIFO_DEQUEUE(FIFO_BUFF_T* FIFO_BUF);
void DISPLAY_ALL(FIFO_BUFF_T *FIFO_BUF);
void display_current_item(FIFO_BUFF_T *FIFO_BUF);

// BUF_STATUS FIFO_CRATE(FIFO_BUFF_T* FIFO, element_type* buf,uint32_t length);
// BUF_STATUS FIFO_ENQUEUE(FIFO_BUFF_T* FIFO, element_type DATA);
// BUF_STATUS FIFO_DEQUEUE(FIFO_BUFF_T* FIFO, element_type* DATA);
// BUF_STATUS FIFO_STATUS(FIFO_BUFF_T *FIFO);
// void DISPLAY(FIFO_BUFF_T *FIFO);

#endif /* FIFO_H_ */
