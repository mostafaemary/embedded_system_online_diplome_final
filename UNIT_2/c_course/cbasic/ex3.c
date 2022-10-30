/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: MOSTAFA
 */

#include "stdio.h"
int main()
{


	float a,b,c;
	printf("enter 3 different number: ");
	fflush(stdout);
	scanf("%f",&a);
	printf("\n");
	scanf("%f",&b);
	printf("\n");
	scanf("%f",&c);
	if (a>b && a>c)
	{
		printf("%f is the largest of the numbers ",a);
	}
	else if(b>a && b>c)
	{
		printf("%f is the largest of the numbers ",b);

	}
	else if(c>a && c>b)
	{
		printf("%f is the largest of the numbers ",c);

	}
	else

	{
		printf("wrong numbers");

	}



	return 0;
}
