/*
 * DIO.c
 *
 * Created: 9/30/2022 7:12:46 AM
 * Author: MOSTAFA EMARY
 */ 
//includes 
#include "DIO.h"
//global variables
//function definitions
DIO_ERROR DIO_init(vuint8_t portnumber,vuint8_t pinnumber, DIO_direction direction)
{
	switch(portnumber)
	{
		case PORT_A:
			if (direction == INPUT)
			{
				DDRA &=~(1<<pinnumber);
				return OK;
			}
			else if(direction == OUTPUT)
			{
				DDRA |=(1<<pinnumber);
				return OK;
			}
			else
			{
				return ERROR;
			}
		break;
		case PORT_B:
		if (direction == INPUT)
		{
			DDRB &=~(1<<pinnumber);
			return OK;
		}
		else if(direction == OUTPUT)
		{
			DDRB |=(1<<pinnumber);
			return OK;
		}
		else
		{
			return ERROR;
			//return error
		}
		break;
		case PORT_C:
		if (direction == INPUT)
		{
			DDRC &=~(1<<pinnumber);
			return OK;
		}
		else if(direction == OUTPUT)
		{
			DDRC |=(1<<pinnumber);
			return OK;
		}
		else
		{
			return ERROR;
			//return error
		}
		break;
		case PORT_D:
		if (direction == INPUT)
		{
			DDRD &=~(1<<pinnumber);
			return OK;
		}
		else if(direction == OUTPUT)
		{
			DDRD |=(1<<pinnumber);
			return OK;
		}
		else
		{
			return ERROR;
			//return error
		}
		break;
		default:
		return ERROR;
		break;
	}
}
DIO_ERROR DIO_write(vuint8_t portnumber,vuint8_t pinnumber, DIO_STATE state)
{
		switch(portnumber)
		{
			case PORT_A:
			if (state == LOW)
			{
				PORTA &=~(1<<pinnumber);
				return OK;
			}
			else if(state == HIGH)
			{
				PORTA |=(1<<pinnumber);
				return OK;
			}
			else
			{
				return ERROR;
				//return error
			}
			break;
			case PORT_B:
			if (state == LOW)
			{
				PORTB &=~(1<<pinnumber);
				return OK;
			}
			else if(state == HIGH)
			{
				PORTB |=(1<<pinnumber);
				return OK;
			}
			else
			{
				return ERROR;
				//return error
			}
			break;
			case PORT_C:
			if (state == LOW)
			{
				PORTC &=~(1<<pinnumber);
				return OK;
			}
			else if(state == HIGH)
			{
				PORTC |=(1<<pinnumber);
				return OK;
			}
			else
			{
				return ERROR;
				//return error
			}
			break;
			case PORT_D:
			if (state == LOW)
			{
				PORTD &=~(1<<pinnumber);
				return OK;
			}
			else if(state == HIGH)
			{
				PORTD |=(1<<pinnumber);
				return OK;
			}
			else
			{
				return ERROR;
				//return error
			}
			break;
			default:
			return ERROR;
			break;
		}
}
void DIO_toggle(vuint8_t portnumber,vuint8_t pinnumber)
{
	DIO_write(portnumber,pinnumber,HIGH);
	//DELAY(1,256,19532);
	delay1(5);
	DIO_write(portnumber,pinnumber,LOW);
	//DELAY(1,256,19532);
	delay1(5);
}
vuint8_t DIO_read(vuint8_t portnumber,vuint8_t pinnumber, vuint8_t *value)
{
	switch(portnumber)
	{
		case PORT_A:
		*value=(PINA&(1<<pinnumber)>>pinnumber);
		return *value;
		break;
		case PORT_B:
		*value=(PINB&(1<<pinnumber)>>pinnumber);
		return *value;
		break;
		case PORT_C:
		*value=(PINC&(1<<pinnumber)>>pinnumber);
		return *value;
		break;
		case PORT_D:
		*value=(PIND&(1<<pinnumber)>>pinnumber);
		return *value;
		break;
		default:
		break;
	}
	return 0;	
}
//delay function
DELAY_E DELAY(int prescaler,int intial_value,int no_overflow)
{
	if ((prescaler==1) | (prescaler==8) | (prescaler == 64) | (prescaler == 256) | (prescaler == 1024))
	{
		while(no_overflow)
		{
			//NORMAL MODE not start
			TCCR0=0x00;
			//set timer initial value (12)
			TCNT0=intial_value;
			//start timer -> set prescaler
			//1 | 8 | 64 | 256 | 1024
			if(prescaler == 1)
				TCCR0|=(1<<0);
			if(prescaler==8)
				TCCR0|=(1<<1);
			if(prescaler==64)
			{
				TCCR0|=(1<<0);
				TCCR0|=(1<<1);
			}
			if(prescaler==256)
				TCCR0|=(1<<2);
			if(prescaler==1024)
			{
				TCCR0|=(1<<0);
				TCCR0|=(1<<2);
			}
			while((TIFR & (1<<0))==0);
			TIFR|=(1<<0);
			no_overflow --;
		}
		return DELAY_OK;
	}
	else
		return DELAY_ERROR;
}


void delay1(double t)
{
	int n_o_overflow;
	if(t<=0.000256)//no prescaler&no overflows
	{
		//NORMAL MODE not start
		TCCR0=0x00;
		TCNT0=(ceil)((0.000256-t)/0.000001);
		TCCR0|=(1<<0);
		while((TIFR & (1<<0))==0);
		TIFR|=(1<<0);
	}
	else if(t<=0.002048)//8 prescaler&no overflows
	{
		TCCR0=0x00;
		TCNT0=(ceil)((0.002048-t)/0.000008);
		TCCR0|=(1<<1);
		while((TIFR & (1<<0))==0);
		TIFR|=(1<<0);
	}
	else if(t<=0.016384)//64 prescaler&no overflows
	{
		TCCR0=0x00;
		TCNT0=(ceil)((0.016384-t)/0.000064);
		TCCR0|=(1<<0);
		TCCR0|=(1<<1);
		while((TIFR & (1<<0))==0);
		TIFR|=(1<<0);
	}
	else if(t<=0.065536)//256 prescaler&no overflows
	{
		TCCR0=0x00;
		TCNT0=(ceil)((0.065536-t)/0.000256);
		TCCR0|=(1<<2);
		while((TIFR & (1<<0))==0);
		TIFR|=(1<<0);
	}
	else if(t<=0.262144)//1024 prescaler&no overflows
	{
		TCCR0=0x00;
		TCNT0=(int)((0.262144-t)/0.001024);
		TCCR0|=(1<<0);
		TCCR0|=(1<<2);
		while((TIFR & (1<<0))==0);
		TIFR|=(1<<0);
	}
	else//1024 prescaler & overflows
	{
		n_o_overflow=(ceil)(t/0.262144);
		while(n_o_overflow)
		{
			TCCR0=0x00;
			TCNT0=(ceil)((256- ((t/0.001024)/(t/0.262144))));
			TCCR0|=(1<<0);
			TCCR0|=(1<<2);
			while((TIFR & (1<<0))==0);
			TIFR|=(1<<0);
			n_o_overflow --;
		}
	}
}

//enable global interrupt