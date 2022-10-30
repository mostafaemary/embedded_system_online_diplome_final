/*
 * main.c
 *
 *  Created on: Aug 25, 2022
 *      Author: MOSTAFA
 */
#include"fifo.h"

int main()
{
	int i, choice;
	//set fifo 
	FIFO_BUFF_T uart_fifo;
	FIFO_CRATE(&uart_fifo,uart_buffer, width1);
	PRINT("1- insert item into the fifo\n");
	PRINT("2- remove item from the fifo\n");
	PRINT("3- display current item of the fifo\n");
	PRINT("4- display all items\n");
	PRINT("5- delete all items\n");
	PRINT("please enter your choice(1,2,3,4,5):= ");
	scanf("%d", &choice);
	while (choice != 5)
	{
		int num_of_items;
		if (choice == 1)
		{
			PRINT("how many items to insert?= ");
			scanf("%d", &num_of_items);
			for (i = 0; i < num_of_items; i++)
			{
				FIFO_ENQUEUE (&uart_fifo,i+1);
			}
		}//end of insert

		if (choice == 2)
		{
			PRINT("how many items to remove?= ");
			scanf("%d", &num_of_items);
			for (i = 0; i < num_of_items; i++)
			{
				FIFO_DEQUEUE(&uart_fifo);
			}
		}//end of remove


		if (choice == 3)
		{
			display_current_item(&uart_fifo);
		}//end of display the current item
		if (choice == 4)
		{
			DISPLAY_ALL(&uart_fifo);
		}//end of display all
		PRINT("\nplease enter another your choice(1,2,3,4,5):= ");
		scanf("%d", &choice);
	}


	if (choice == 5)
	{
		for (i = 0; i < width1; i++)
		{
			FIFO_DEQUEUE(&uart_fifo);
		}
	}//end of remove all

	return 0;
}
