/*
 * main.c
 *
 *  Created on: Jul 1, 2022
 *      Author: MOSTAFA
 */
#include "stdio.h"
struct SComplex
{
	float real,imaginary;
};
struct SComplex add(struct SComplex x,struct SComplex y)
{
	struct SComplex sum;
	printf("enter complex1 like r1-i1: ");
	fflush(stdout);
	scanf("%f-%f",&x.real,&x.imaginary);
	printf("enter complex1 like r2-i2: ");
	fflush(stdout);
	scanf("%f-%f",&y.real,&y.imaginary);
	sum.real=x.real+y.real;
	sum.imaginary=x.imaginary+y.imaginary;
	return sum;
}
void display(struct SComplex x)
{
	printf("sum = : %f + j%f",x.real,x.imaginary);
}
int main()
{
	struct SComplex x,y,sum;
	sum=add(x,y);
	display(sum);
	return 0;
}

