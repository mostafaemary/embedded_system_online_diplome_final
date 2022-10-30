/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: MOSTAFA
 */


#include"stdio.h"
int main()
{
	char a='A';
	char b='B';
	int i, dif= b-a;
	char* p=&a;
	for(i=0;i<26;i++)
	printf("%c\t ",*p+dif*i);
return 0;
}
