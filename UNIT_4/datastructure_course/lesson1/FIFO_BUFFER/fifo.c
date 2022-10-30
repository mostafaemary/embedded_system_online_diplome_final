/*
 * fifo.c
 *
 *  Created on: Aug 28, 2022
 *      Author: MOSTAFA
 */
#include "fifo.h"
BUF_STATUS FIFO_IS_NULL(FIFO_BUFF_T* FIFO_BUF)
{
    //check if the fifo is set to the buffer
    if (FIFO_BUF->head == NULL && FIFO_BUF->tail == NULL && FIFO_BUF->base == NULL)
        return FIFO_NULL;
    else
        return FIFO_NO_ERROR;
}
BUF_STATUS FIFO_IS_FULL(FIFO_BUFF_T* FIFO_BUF)
{
    //check if the buffer is full
    if (FIFO_BUF->count == FIFO_BUF->length)
        return FIFO_FULL;
    else
        return FIFO_NO_ERROR;
}
BUF_STATUS FIFO_IS_EMPTY(FIFO_BUFF_T* FIFO_BUF)
{
    //check if empty
    if (FIFO_BUF->count == 0)
        return FIFO_EMPTY;
    else
        return FIFO_NO_ERROR;
}

void FIFO_CRATE(FIFO_BUFF_T* FIFO_BUF, element_type* buf, uint32_t length)
{
    if (buf == NULL);
    else
    {
        FIFO_BUF->count = 0;
        FIFO_BUF->length = length;
        FIFO_BUF->head = buf;
        FIFO_BUF->base = buf;
        FIFO_BUF->tail = buf;
    }
}

void FIFO_ENQUEUE(FIFO_BUFF_T* FIFO_BUF, element_type DATA)
{
    if (FIFO_IS_NULL(FIFO_BUF) == FIFO_NULL)
    {
        PRINT("fifo is null\n");
    }
    else if (FIFO_IS_FULL(FIFO_BUF) == FIFO_FULL)
    {
        PRINT("fifo is full\n");
    }
    //in case of circular
    else
    {
        *(FIFO_BUF->head) = DATA;
        FIFO_BUF->count++;
        if (FIFO_BUF->head == FIFO_BUF->base + (FIFO_BUF->length) * sizeof(element_type))
        {
            FIFO_BUF->head = FIFO_BUF->base;
        }
        else
        {
            FIFO_BUF->head++;
        }
    }
}
void FIFO_DEQUEUE(FIFO_BUFF_T* FIFO_BUF)
{
    if (FIFO_IS_NULL(FIFO_BUF) == FIFO_NULL)
    {
    	PRINT("fifo is null\n");
    }
    else if (FIFO_IS_EMPTY(FIFO_BUF) == FIFO_EMPTY)
        {
    	PRINT("fifo is empty\n");
        }
    else {
        FIFO_BUF->count--;
        PRINT("\n element: %d is poped \n", *(FIFO_BUF->tail));
        //in case of fcircular
        if (FIFO_BUF->tail == FIFO_BUF->base + (FIFO_BUF->length) * sizeof(element_type))
        {
            FIFO_BUF->tail = FIFO_BUF->base;
        }
        else
        {
            FIFO_BUF->tail++;
        }
        PRINT("the current element is: %d ", *(FIFO_BUF->tail));
    }
}

void DISPLAY_ALL(FIFO_BUFF_T* FIFO_BUF)
{
    if (FIFO_IS_NULL(FIFO_BUF) == FIFO_NULL)
        {
    	PRINT("fifo is null\n");
        }
    else if (FIFO_IS_EMPTY(FIFO_BUF) == FIFO_EMPTY)
        {
    	PRINT("fifo is empty\n");
        }
    else {
        int i;
        element_type* temp = (element_type*)FIFO_BUF->tail;
        PRINT("=========== the buffer content is ===========");
        for (i = 0; i < FIFO_BUF->count; i++)
        {
            if (temp == (FIFO_BUF->base + (FIFO_BUF->length) * sizeof(element_type)))
            {
                PRINT("\n %x \n", *temp);
                temp = (element_type*)FIFO_BUF->base;
                temp++;
            }
            else
            {
                PRINT("\n %x \n", *temp);
                temp++;
            }
        }
        temp = (element_type*)FIFO_BUF->tail;
    }
}

void display_current_item(FIFO_BUFF_T* FIFO_BUF)
{
    if (FIFO_IS_NULL(FIFO_BUF) == FIFO_NULL)
    {
    	PRINT("fifo is null\n");
    }
    else if (FIFO_IS_EMPTY(FIFO_BUF) == FIFO_EMPTY)
        {
    	PRINT("fifo is empty\n");
        }
    else
        PRINT("the current element is: %d \n", *(FIFO_BUF->tail));
}
