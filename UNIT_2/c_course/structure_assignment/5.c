/*
 * main.c
 *
 *  Created on: Jul 1, 2022
 *      Author: MOSTAFA
 */

#include"stdio.h"
#define pi 3.14
int main()
{
	float r,area;
	printf("enter radius: ");
	fflush(stdout);
	scanf("%f",&r);
	area=pi*r*r;
	printf("Area=%f",area);

return 0;
}
