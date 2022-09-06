/*
 * lifo.c
 *
 *  Created on: Aug 25, 2022
 *      Author: MOSTAFA
 */

#include"lifo.h"
//APIS
LIFO_STATUS CHECK_IF_LIFO_IS_SET_TO_BUFFER (LIFO_BuF_t *LIFO_BUF)
{
	if(LIFO_BUF->head==NULL && LIFO_BUF->base==NULL)
	{
		PRINT("\n no lifo is set to the buffer please creat lifo \n");
		return LIFO_NULL;

	}
	else
	{
		return LIFO_NO_ERROR;
	}
}
LIFO_STATUS IS_EMPTY(LIFO_BuF_t *LIFO_BUF)
{
	if (LIFO_BUF->count==0)
	{
		return LIFO_EMPTY;
	}
	else
	{
		return LIFO_NO_ERROR;
	}
}
LIFO_STATUS IS_FULL(LIFO_BuF_t *LIFO_BUF)
{
	//if(LIFO_BUF->head >= (LIFO_BUF->base + (LIFO_BUF->leangth *4)))
	if (LIFO_BUF->count == LIFO_BUF->leangth)
	{
		return LIFO_IS_FULL;
	}
	else{
		return LIFO_NO_ERROR;
	}
}
void LIFO_insert_item(LIFO_BuF_t* LIFO_BUF, unsigned int item)
{

	//check lifo is exist?
	if(CHECK_IF_LIFO_IS_SET_TO_BUFFER (LIFO_BUF) == LIFO_NULL );
	//check lifo is full?

	//insert item
	else if(IS_FULL(LIFO_BUF) == LIFO_IS_FULL);
	else
	{


		*(LIFO_BUF->head)=item;
		LIFO_BUF->count ++;
		LIFO_BUF->head ++;
	}
}
void LIFO_end_item(LIFO_BuF_t* LIFO_BUF)
{
	//check if lifo is exist
	if(CHECK_IF_LIFO_IS_SET_TO_BUFFER (LIFO_BUF) == LIFO_NULL );
	else if(IS_EMPTY(LIFO_BUF) == LIFO_EMPTY );

	else
	{
		LIFO_BUF->head --;
		LIFO_BUF->count --;
		PRINT("item: (%d) is poped ",*(LIFO_BUF->head));
		display_current_item(LIFO_BUF);
	}
}
void LIFO_creat(unsigned int length,LIFO_BuF_t* LIFO_BUF, unsigned int *buf)
{
	if (buf==NULL);
	else
	{
		LIFO_BUF->base=buf;
		LIFO_BUF->head=buf;
		LIFO_BUF->count=0;
		LIFO_BUF->leangth=length;
	}
}
void DISPLAY_all(LIFO_BuF_t *LIFO_BUF)
{
	int i;
	int* temp;
	temp = (int*)LIFO_BUF->head;
	if(CHECK_IF_LIFO_IS_SET_TO_BUFFER (LIFO_BUF) == LIFO_NULL );
	else if(IS_EMPTY(LIFO_BUF) == LIFO_EMPTY);
	else
	{
		PRINT("\n======= buffer content : =======\n");
		for(i=0;i<LIFO_BUF->count;i++)
		{
			temp --;
			PRINT("%d \n",*temp);
		}
		temp =(int*)LIFO_BUF->head;
	}
}
void display_current_item(LIFO_BuF_t *LIFO_BUF)
{
	LIFO_BuF_t* temp =LIFO_BUF;
	if(CHECK_IF_LIFO_IS_SET_TO_BUFFER (LIFO_BUF) == LIFO_NULL );
	else if(IS_EMPTY(LIFO_BUF) == LIFO_EMPTY);
	else
	{
		PRINT("\n the next item is:= (%d) \n",*((temp->head -1)));
	}
}
