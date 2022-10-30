/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: MOSTAFA
 */

#include "stdio.h"
int main()
{


	int number,sum=0;
		printf("enter number: ");
		fflush(stdout);
		scanf("%d",&number);
		for(int i=1; i<=number;i++)
		{
			sum+=i;
		}
		printf("sum= %d",sum);

	return 0;
}
