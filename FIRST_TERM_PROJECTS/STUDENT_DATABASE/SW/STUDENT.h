/*
 * STUDENT.h
 *
 *  Created on: Oct 14, 2022
 *      Author: MOSTAFA
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include "stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#define PRINT(...) {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}
typedef volatile unsigned int   vuint32_t;

typedef struct SINFO_T
{
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int cid[10];
}SINFO_T;

typedef struct FIFO_T{
	unsigned int length;
	unsigned int count;
	SINFO_T *tail;
	SINFO_T *base;
	SINFO_T *head;
}FIFO_T;

typedef enum DATABASE_STATUS{
	BUFFER_NULL,FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}DATABASE_STATUS;

//APIS
DATABASE_STATUS FIFO_IS_FULL(FIFO_T* FIFO_BUF);
DATABASE_STATUS FIFO_IS_NULL(FIFO_T* FIFO_BUF);
DATABASE_STATUS FIFO_IS_EMPTY(FIFO_T* FIFO_BUF);

DATABASE_STATUS FIFO_CRATE(FIFO_T* FIFO_BUF, SINFO_T* buf,int length);

void add_student_file(FIFO_T* FIFO,SINFO_T * buf);
void add_student_manually(FIFO_T* FIFO_BUF, SINFO_T* buf);
void find_r1();
void find_fn();
void find_c();
void tot_s();
void del_s();
void up_s();
void show_s();
#endif /* STUDENT_H_ */
