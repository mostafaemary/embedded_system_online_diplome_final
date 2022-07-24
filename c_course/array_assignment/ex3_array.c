/*
*      Author: Mostafa Emary
 */
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int r,c,a,b;
	printf("enter rows and columns of matrix: ");
	fflush(stdout);
	scanf("%d %d",&r,&c);
	float m[r][c],t[c][r];
	printf("Enter Elements Of Matrix: \n");
	for(a=0;a<r;a++)
	{
		for(b=0;b<c;b++)
		{
			printf("enter element  m%d%d: ",a+1,b+1);
			fflush(stdout);
			scanf("%f",&m[a][b]);
		}
	}

	for(a=0;a<c;a++)
	{
		for(b=0;b<r;b++)
		{
			t[a][b]=m[b][a];
		}
	}


	printf("Entered Matrix: \n");
	for(a=0;a<r;a++)
		{
			for(b=0;b<c;b++)
			{
				printf("%2.2f\t",m[a][b]);
			}
			printf("\n");
		}
	printf("Transpose Of Matrix: \n");
	for(a=0;a<c;a++)
		{
			for(b=0;b<r;b++)
			{
				printf("%2.2f\t",t[a][b]);
			}
			printf("\n");
		}






	return 0;
}


