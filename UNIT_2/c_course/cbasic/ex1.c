/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: MOSTAFA
 */


#include"stdio.h"
int main()
{
	int x;
	printf("enter a number: ");
	fflush(stdout);
	scanf("%d",&x);
	if (x%2==0)
	{
		printf("%d is even ",x);
	}
	else
	{
		printf("%d is odd ",x);
	}

	return 0;
}
