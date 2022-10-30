/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: MOSTAFA
 */

#include "stdio.h"
#include "string.h"
struct employee
{
	char name[50];
	int id;
};
int main()
{
	struct employee employer1={"mostafa",2000},employer2={"emary",1000},employer3={"mohamed",3000};
	struct employee *arr[3]={&employer1,&employer2,&employer3};
	struct employee (*(*p)[3])=&arr;
	printf("%s\n",(***p).name);
	printf("%d",(***p).id);


	return 0;
}
