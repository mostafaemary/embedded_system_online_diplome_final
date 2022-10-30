/*
 * main.c
 *
 *  Created on: Jul 1, 2022
 *      Author: MOSTAFA
 */
#include "stdio.h"
struct Sdata{
	char name[50];
	int roll;
	float marks;
};
struct Sdata read_data(struct Sdata x)
{
	struct Sdata y;
	printf("enter student name: ");
	fflush (stdout);
	scanf("%s",x.name);
	printf("enter student roll: ");
	fflush (stdout);
	scanf("%d",&x.roll);
	printf("enter student marks: ");
	fflush (stdout);
	scanf("%f",&x.marks);
	y=x;
	return y;
}
void display_data(struct Sdata x)
{
	printf("student name is: %s \r\n",x.name);
	printf("student roll is: %d \r\n",x.roll);
	printf("student marks is: %f \r\n",x.marks);
}

int main()
{
	int i;
	struct Sdata arr[4],y[4];
	for(i=0;i<4;i++)
	{
		y[i]=read_data(arr[i]);
	}
	for(i=0;i<4;i++)
	{
		printf("information of student %d \n",i+1);
		display_data (y[i]);
		printf("\n\n");
	}

	return 0;
}
