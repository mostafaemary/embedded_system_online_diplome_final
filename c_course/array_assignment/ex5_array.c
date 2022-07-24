/*
 *      Author: Mostafa Emary
 */
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int num,i,serched_elemnt;
	float arr[20];
	printf("enter number of elements: ");
	fflush(stdout);
	scanf("%d",&num);

	for(i=0;i<num;i++)
	{
		scanf("%f",&arr[i]);
	}
	printf("enter number to be searched: ");
	fflush(stdout);
	scanf("%d",&serched_elemnt);
	for(i=0;i<num;i++)
	{
		if (arr[i]==serched_elemnt)
		{
			printf("number found at the location= %d",i+1);
			break;
		}
	}
	if(i==num)
	{
		printf("sorry the searched element isn't found");
	}
	return 0;
}
