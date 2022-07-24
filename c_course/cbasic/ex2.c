/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: MOSTAFA
 */


#include"stdio.h"
int main()
{
	char alpha;
		printf("enter alphabet: ");
		fflush(stdout);
		scanf("%c",&alpha);
		switch(alpha)
		{
		case 'a':
		case 'A':
		{
			printf("%c is vowel", alpha);
		}
		break;
		case 'e':
		case 'E':
		{
			printf("%c is vowel", alpha);
		}
		break;
		case 'i':
		case 'I':
		{
			printf("%c is vowel", alpha);
		}
		break;
		case 'o':
		case 'O':
		{
			printf("%c is vowel", alpha);
		}
		break;
		case 'u':
		case 'U':
		{
			printf("%c is vowel", alpha);
		}
		break;
		default:
		{
			printf("%c is consonant", alpha);
		}
		}


	return 0;
}
