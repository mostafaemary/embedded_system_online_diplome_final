/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: MOSTAFA
 */

#include "stdio.h"
#include"string.h"
int main()
{
	char word[50];
	printf("enter your string: ");
	fflush(stdout);
	gets(word);
	char*p=word;
	int i;
	for(i=1;*p!='\0';i++,p++);

	for(;i!=0;i--,p--)
	{
		printf("%c",*p);
	}


	return 0;
}
