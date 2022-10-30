/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: MOSTAFA
 */
#include"stdio.h"
int main()
{
	int num;
	printf("enter number of elements: " );
	fflush(stdout);
	scanf("%d",&num);
	int *p,i, arr[num];
	p=arr;
	for (i=0;i<num;i++){

		printf("enter element %d: ",i+1);
		fflush(stdout);
		scanf("%d",p++);
	}
	p--;
	for (;i>0;i--,p--)
		printf("\n element %d is: %d\n",i,*p);




	return 0;
}
