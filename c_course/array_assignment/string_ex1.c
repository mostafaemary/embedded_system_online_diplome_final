/*
 *      Author: Mostafa Emary
 */
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int num,i;
	char character;
	char arr[100];
	printf("enter a string: ");
	fflush(stdout);
	gets(arr);
	printf("enter a character: ");
	fflush(stdout);
	scanf("%c", &character);
	num=0;
	i=0;
	while (arr[i]!='\0')
	{
		if(arr[i]==character)
		{
			num++;
		}
		i++;
	}
	printf("frequency of %c = %d", character,num);



	return 0;
}

