/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: MOSTAFA
 */

#include "stdio.h"
int main()
{


	float num;
	printf("enter number: ");
	fflush(stdout);
	scanf("%f",&num);
	if(num>0)
	{
		printf("%f is a positive number ",num);
	}
	else if(num<0)
	{
		printf("%f is a negative number ",num);
	}
	else if(num==0)
	{
		printf(" you entered zero ");
	}
	else
	{
		printf("you entered a wrong number");
	}



	return 0;
}
