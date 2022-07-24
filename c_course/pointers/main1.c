/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: MOSTAFA
 */

#include "stdio.h"
int main()
{
	int *ab,m;
	m=29;
	ab=&m;
	printf(" Address of m : %p\n Value of m:  %d \n \n",&m,m);

	ab=&m;
	printf(" Now pointer ab access variable m\n\n");
	printf(" Address has accessed by ab is: %p \n value accessed by ab is:%d\n\n",ab,*ab);

	m=30;
	printf(" Now value of m changed to 30 m\n\n");
	printf(" Address has accessed by ab is: %p \n value accessed by ab is:%d\n\n ",ab,*ab);

	*ab=15;
	printf("the pointer variable is signed with value of 15 \n\n");
	printf(" Address of m : %p\n Value of m:  %d \n \n",&m,m);

	return 0;
}

