/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: MOSTAFA
 */

#include "stdio.h"
int main()
{


	float x,y;
	char operator;
	printf("enter your operator: ");
	fflush(stdout);
	scanf("%c",&operator);
	printf("enter two numbers: ");
	fflush(stdout);
	scanf("%f,%f",&x,&y);

	switch(operator)
	{
	case '+':
	{
		float sum;
		sum=x+y;
		printf("%f + %f = %f",x,y,sum);
	}
	break;
	case '-':
	{
		float sub;
		sub=x-y;
		printf("%f - %f = %f",x,y,sub);
	}
	break;
	case '*':
	{
		float multi;
		multi=x*y;
		printf("%f * %f = %f",x,y,multi);
	}
	break;
	case '/':
	{
		float div;
		div=x/y;
		printf("%f / %f = %f",x,y,div);
	}
	break;
	default:
	{
		printf("wrong operator, try again");
	}
	break;

	}


	return 0;
}
