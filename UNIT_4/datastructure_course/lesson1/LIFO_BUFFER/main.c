/*
 * main.c
 *
 *  Created on: Aug 25, 2022
 *      Author: MOSTAFA
 */
#include"lifo.h"
int main()
{
	int num,i,choice;
	PRINT("enter the length of your lifo= ");
	
	scanf("%d",&num);
	//static allocation
	unsigned int buffer[num];
	//set lifo 
	LIFO_BuF_t uart_lifo;
	LIFO_creat (num,&uart_lifo,buffer);
	PRINT ("1- insert item into the lifo\n"); 
	PRINT ("2- remove item from the lifo\n");
	PRINT ("3- display current item of the lifo\n");
	PRINT ("4- display all items\n");
	PRINT ("5- delete all items\n");
	PRINT ("please enter your choice(1,2,3,4,5):= ");
	scanf("%d",&choice);
	while (choice!=5)
	{
		int num_of_items;
		if (choice == 1)
		{
			PRINT("how many items to insert?= ");
			scanf("%d",&num_of_items);
			for (i= 0; i < num_of_items; i++)
			{
				LIFO_insert_item(&uart_lifo, i+1);
			}
		}//end of insert

		if (choice == 2)
		{
			PRINT("how many items to remove?= ");
			scanf("%d",&num_of_items);
			for (i = 0; i < num_of_items; i++)
			{
				LIFO_end_item(&uart_lifo);
			} 
		}//end of remove


		if (choice == 3)
		{
			display_current_item(&uart_lifo);
		}//end of display the current item
		if (choice == 4)
		{
			DISPLAY_all(&uart_lifo);
		}//end of display all
		PRINT ("please enter another your choice(1,2,3,4,5):= ");
		scanf("%d",&choice);
	}


	if (choice == 5)
	{
		for (i = 0; i < num; i++)
		{
			LIFO_end_item(&uart_lifo);
		} 
	}//end of remove all

	return 0;
}
