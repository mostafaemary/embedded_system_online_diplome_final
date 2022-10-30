/*

 * main.c
 *
 *  Created on: Aug 3, 2021
 *      Author: Mostafa
 */
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
int main()
{
	char array[100],reverse[100];
	int i,j;
	printf("enter a string: ");
	fflush(stdout);
	gets(array);
	j=0;

	for (i=strlen(array)-1;i>=0;i--)
	{
		reverse[i]=array[j];
		j++;
	}
	reverse[strlen(array)]='\0';
	printf("the reverse string is: %s",reverse);

	return 0;
}

