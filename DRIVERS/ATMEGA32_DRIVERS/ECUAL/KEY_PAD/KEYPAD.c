/*
 * KEYPAD.c
 *
 * Created: 5/25/2023 9:05:09 PM
 *  Author: MOSTAFA
 */ 
#include "KEYPAD.h"
void KEYPAD_INIT(void)
{
	//KEYPAD_DDR|=(1<<0)|KEYPAD_DDR|=(1<<1)|KEYPAD_DDR|=(1<<2)|KEYPAD_DDR|=(1<<3);
	DIO_init(DDR_NUM,R1,INPUT); DIO_init(DDR_NUM,R2,INPUT);DIO_init(DDR_NUM,R3,INPUT);DIO_init(DDR_NUM,R4,INPUT);
	DIO_init(DDR_NUM,C1,OUTPUT);DIO_init(DDR_NUM,C2,OUTPUT);DIO_init(DDR_NUM,C3,OUTPUT);DIO_init(DDR_NUM,C4,OUTPUT);
	KEYPAD_PORT =0XFF;
}
int RAWS[4]={R1,R2,R3,R4};
int COULOMS[4]={C1,C2,C3,C4};
char KEYPAD_DETECTED(void)
{
	
for(int i=0;i<4;i++)	
	{
		
		KEYPAD_PORT |=(1<<COULOMS[0])|(1<<COULOMS[1])|(1<<COULOMS[2])|(1<<COULOMS[3]);
		DIO_write(POrt_number,COULOMS[i],LOW);
		for(int j=0;j<4;j++)
		{
			if(!(PINA&(1<<RAWS[j])))
			{
				while(!(PINA&(1<<RAWS[j])));
				switch(i)
				{
					case(0):
					{
					if(j==0)		return '7';
					else if (j==1)	return '4';
					else if (j==2)	return '1';
					else if (j==3)	return 'C';
					break;
					}
					case(1):
					{
					if(j==0)		return '8';
					else if (j==1)	return '5';
					else if (j==2)	return '2';
					else if (j==3)	return '0';
					break;
					}
					case(2):
					{
					if(j==0)		return '9';
					else if (j==1)	return '6';
					else if (j==2)	return '3';
					else if (j==3)	return '=';
					break;
					}
					case(3):
					{
					if(j==0)		return '/';
					else if (j==1)	return '*';
					else if (j==2)	return '-';
					else if (j==3)	return '+';
					break;
					}
				}
			}	
		}
	}
	
	return 'A';
}
