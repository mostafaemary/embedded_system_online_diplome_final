/*
 * implementation.c
 *
 *  Created on: Sep 26, 2021
 *      Author: Mostafa Emary
 */
#include "functions.h"

//functions of the home work
void check_prime_number(int star,int end)
{
	int i,j;
	int num;
	printf("prime numbers between %d & %d: ",star,end);
	for(j=star+1;j<=end;j++)
	{
		num=j-1;
	for (i=2;i<num;i++)
	{
		if(num%i==0)
		{

			break;
		}
	}
	if(i==num)
		printf("%d \t",num);

	}
}

int factorial(int num ){
	int fact=1;

	while(num>0)
	{
		fact=num-- *fact;
	factorial(num);
	}
	return fact;
}
int power(int base,int exponent)
{

	if (exponent!=1)
	{
		base=base*power(base,--exponent);
	}
	return base;
}
void reverse()
{
	char a;
	if((a=getchar())!='\n')
	{
		reverse();
		printf("%c",a);
	}
}

////functions of lecture labs
int calcminimum(int arr[],int size)
{
	int i,minimum=arr[0];
	for (i=1;i<=size;i++)
	{
		if (arr[i]<minimum)
		{
			minimum=arr[i];
		}
	}
	return minimum;
}
void findnames(char name[],char names[][20],int i)
{

	int x=0;
	for (x=0;x<i;x++)
	{
		if(stricmp(names[x],name)==0)
		{
			printf("welcome");
			break;
		}
	}
	if (x==i)
		printf("good by");
}
void diss (int num){
	int j=0, i;
	for(;j<=num;j++){

		for (i=j;i<=num;i++){
			printf("%d \t",i);
		}
		printf("\n");
	}
}
