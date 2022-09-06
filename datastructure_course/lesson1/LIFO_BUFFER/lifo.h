/*
 * lifo.h
 *
 *  Created on: Aug 25, 2022
 *      Author: MOSTAFA
 */
#include"stdlib.h"
#include "stdio.h"
#include"conio.h"
#ifndef LIFO_H_
#define LIFO_H_
#define PRINT(...) {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}
//type definitions:
typedef struct {
	unsigned int leangth;
	unsigned int count;
	unsigned int*base;
	unsigned int*head;
}LIFO_BuF_t;


typedef enum{
	LIFO_NO_ERROR,
	LIFO_IS_FULL,
	LIFO_EMPTY,
	LIFO_NULL
}LIFO_STATUS;


//APIS
LIFO_STATUS CHECK_IF_LIFO_IS_SET_TO_BUFFER (LIFO_BuF_t *LIFO_BUF);
LIFO_STATUS IS_EMPTY(LIFO_BuF_t *LIFO_BUF);
LIFO_STATUS IS_FULL(LIFO_BuF_t *LIFO_BUF);
void LIFO_insert_item(LIFO_BuF_t* LIFO_BUF, unsigned int item);
void LIFO_end_item(LIFO_BuF_t* LIFO_BUF);
void LIFO_creat(unsigned int length,LIFO_BuF_t* LIFO_BUF, unsigned int *buf);
void DISPLAY_all(LIFO_BuF_t *LIFO_BUF);
void display_current_item(LIFO_BuF_t *LIFO_BUF);
#endif /* LIFO_H_ */
