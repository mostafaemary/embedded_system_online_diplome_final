/*
 *      Author: Mostafa Emary
 */
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int num,i, location,inserter_elemnt;
	float arr[20];
	printf("enter number of elements: ");
	fflush(stdout);
	scanf("%d",&num);

	for(i=0;i<num;i++)
	{
		scanf("%f",&arr[i]);
	}
	printf("enter location of element: ");
	fflush(stdout);
	scanf("%d",&location);
	for(i=20;i<=location;i--)
	{
		arr[i]=arr[i-1];
	}

	printf("enter inserted element: ");
	fflush(stdout);
	scanf("%d",&inserter_elemnt);
	arr[location]=inserter_elemnt;
	printf("the new array is: \n");
	for(i=0;i<=num;i++)
	{
		printf("%2.2f \n",arr[i]);
	}
	return 0;
}
