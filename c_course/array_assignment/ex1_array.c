
/*
 * main.c
 *
 *  Created on: Aug 2, 2021
 *      Author: Mostafa Emary
 */


#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int main()
{
	int r,c;
	float mat1[2][2],mat2[2][2],sum[2][2];
	printf("matrix 1 is: \n");
	for (r=0;r<2;r++)
	{
		for(c=0;c<2;c++)
		{
			printf("enter element (%d,%d)",r,c);
			fflush(stdout);
			scanf("%f", &mat1[r][c]);
		}
	}

	printf("matrix 2 is: \n");
	for (r=0;r<2;r++)
	{
		for(c=0;c<2;c++)
		{
			printf("enter element (%d,%d)",r,c);
			fflush(stdout);
			scanf("%f", &mat2[r][c]);
		}
	}
	for (r=0;r<2;r++)
	{
		for(c=0;c<2;c++)
		{
			sum[r][c]=mat1[r][c]+mat2[r][c];
		}
	}
	printf("sum of two matricies is: \n");
		for (r=0;r<2;r++)
		{
			for(c=0;c<2;c++)
			{
				printf("element (%d,%d)is: ",r,c);
				printf("%2.2f \t",sum[r][c]);

			}
			printf("\n");
		}




	return 0;
}
