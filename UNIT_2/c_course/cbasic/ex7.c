/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: MOSTAFA
 */

#include "stdio.h"
int main()
{


	int number,fact=1;
		printf("enter number: ");
		fflush(stdout);
		scanf("%d",&number);
		if (number>=0)
		{
			int i;
			for(i=1; i<=number;i++)
			{
				fact*=i;
			}

			printf("factorial= %d",fact);
		}
		else
			printf("factorial of negative number doesn't exist");

	return 0;
}
