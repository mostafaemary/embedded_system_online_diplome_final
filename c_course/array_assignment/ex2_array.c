/*
 * main.c
 *
 *  Created on: Aug 2, 2021
 *      Author: Mostafa Emary
 */
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int n;
	printf("enter number of data: ");
	fflush(stdout);
	scanf("%d",&n);
	printf("enter number of data: %d \n",n);
	float array[n];
	int i;
	for(i=0; i<n ;i++)
	{
		printf("%d. enter number of data: ",i+1);
		fflush(stdout);
		scanf("%f",&array[i]);
	}
	for(i=0; i<n ;i++)
		{
			printf("%d. enter number of data: ",i+1);
			printf("%2.2f \n",array[i]);

		}
	float sum=0;
	for(i=0; i<n ;i++)
		{
			sum+=array[i];
		}
	printf("Average = %2.2f",sum/n);




	return 0;
}

