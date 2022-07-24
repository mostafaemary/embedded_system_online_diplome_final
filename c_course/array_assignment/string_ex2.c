/*
 * main.c
 *
 *  Created on: Aug 3, 2021
 *      Author: Mostafa
 */
#include "stdio.h"
#include"string.h"
#include "stdlib.h"
int main()
{
	int i;
	char array[100];
	printf("enter a string: ");
	fflush(stdout);
	gets(array);
	i=0;
	while(array[i]!='\0')
	{
		i++;
	}
	printf("length of string = %d",i);


	return 0;
}

