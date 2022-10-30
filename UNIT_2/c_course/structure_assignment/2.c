/*
 * main.c
 *
 *  Created on: Jul 1, 2022
 *      Author: MOSTAFA
 */
#include "stdio.h"
struct SDistance
{
	float feets,inches;
};
struct SDistance add(struct SDistance x,struct SDistance y)
{
	struct SDistance sum;
	printf("enter feet of the tow distance like f1-f2: ");
	fflush(stdout);
	scanf("%f-%f",&x.feets,&y.feets);
	printf("enter inches of the tow distance like i1-i2: ");
	fflush(stdout);
	scanf("%f-%f",&x.inches,&y.inches);
	sum.feets=x.feets+y.feets;
	sum.inches=x.inches+y.inches;
	if (sum.inches>=12)
	{
		sum.feets+=(int)sum.inches/12;
		sum.inches= sum.inches-12*(int)(sum.inches/12);
	}
	return sum;
}
void display(struct SDistance x)
{
	printf("sum of distances is: %f '- %f\" ",x.feets,x.inches);
}
int main()
{
	struct SDistance x,y,sum;
	sum=add(x,y);
	display(sum);
	return 0;
}

