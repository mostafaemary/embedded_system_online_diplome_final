/*
 * LCD.c
 *
 * Created: 5/12/2023 2:58:09 AM
 *  Author: MOSTAFA
 */ 
#include "LCD.h"
int value;


#define LCD_4_BIT_MODE
//#define LCD_8_BIT_MODE
#define CONTROL_PORT_DIRECTION		'C'
#define CONTROL_PORT				'C'
#define DATA_PORT_DIRECTION			DDRD
#define DATA_PORT					PORTD
//E CONFIGURATION									
#define E_PIN							2
#define E_ENABLE						1
#define E_DISABLE						0

//RW CONFIGURATION									
#define RW_PIN							1
#define RW_Write						0
#define RW_Read							1

//RS CONFIGURATION
#define RS_PIN							0
#define RS_Data							1
#define RS_Command						0

//DATA PINS CONFIG
#define D7_PIN							7


void Control_Pins_IS_OUTPUT(void)
{
	//CONFIGURE CONTROL PINS AS OUTPUT
	DIO_init(CONTROL_PORT_DIRECTION,RS_PIN , OUTPUT);
	DIO_init(CONTROL_PORT_DIRECTION,E_PIN , OUTPUT);
	DIO_init(CONTROL_PORT_DIRECTION,RW_PIN , OUTPUT);
}
void Data_Pins_IS_OUTPUT(void)
{
	DATA_PORT_DIRECTION=0XFF;
}
void Data_Pins_IS_INPUT(void)
{
	//CONFIGURE CONTROL PINS AS INPUT
	DATA_PORT_DIRECTION=0X00;
}


void Check_IF_Busy(void)
{
	Control_Pins_IS_OUTPUT();
	//set data port as input
	Data_Pins_IS_INPUT();
	DIO_write(CONTROL_PORT, RW_PIN, RW_Read);
	
	DIO_write(CONTROL_PORT, RS_PIN, RS_Command);

	if(DIO_read(DATA_PORT,D7_PIN, (vuint8_t*)&value))
	{
		delay1(0.005);
	}
}



void LCD_8_BIT_MODE_SEND_COMMAND(vuint8_t command)
{
	Check_IF_Busy();
	Data_Pins_IS_OUTPUT();
	Control_Pins_IS_OUTPUT();
	DIO_write(CONTROL_PORT, RS_PIN, RS_Command);
	DIO_write(CONTROL_PORT, RW_PIN, RW_Write);
	DATA_PORT=command;
	DIO_write(CONTROL_PORT, E_PIN, E_DISABLE);
	delay1(0.0005);
	DIO_write(CONTROL_PORT, E_PIN, E_ENABLE);
}

void LCD_8_BIT_MODE_INIT(void)
{
	Control_Pins_IS_OUTPUT();
	Data_Pins_IS_OUTPUT();
	delay1(0.002);

	LCD_8_BIT_MODE_SEND_COMMAND(0X38);
	
	LCD_8_BIT_MODE_SEND_COMMAND(0X0E);
	
	LCD_8_BIT_MODE_SEND_COMMAND(0X06);
	
	LCD_8_BIT_MODE_SEND_COMMAND(0X01);
	
	LCD_8_BIT_MODE_SEND_COMMAND(0X80);
}
void LCD_8_BIT_MODE_DISPLPLY_CHARACTER(vuint8_t character)
{
	
	Check_IF_Busy();
	Data_Pins_IS_OUTPUT();
	Control_Pins_IS_OUTPUT();
	DIO_write(CONTROL_PORT, RS_PIN, RS_Data);
	DIO_write(CONTROL_PORT, RW_PIN, RW_Write);
	DATA_PORT=character;
	DIO_write(CONTROL_PORT, E_PIN, E_ENABLE);
	delay1(0.0005);
	DIO_write(CONTROL_PORT, E_PIN, E_DISABLE);
}


void LCD_8_BIT_MODE_DISPLPLY_STRING(char *STRING)
{
	char*P;
	P=(char *)STRING;
	int i=0;
	while(*P!='\0')
	{
		if(i<16)
		{
			if(*P=='\n')
			{
				LCD_8_BIT_MODE_SEND_COMMAND(0xC0);
			}
			LCD_8_BIT_MODE_DISPLPLY_CHARACTER(*P);
			delay1(0.005);
			P++;
			i++;
		}
		else if(i<32)
		{
			LCD_8_BIT_MODE_SEND_COMMAND(0xC0);
			while(*P!='\0')
			{
				LCD_8_BIT_MODE_DISPLPLY_CHARACTER(*P);
				delay1(0.005);
				P++;
				i++;
				if (i==32)
				{
					delay1(5);
					break;
				}
			}
		}
		else
		{
			LCD_8_BIT_MODE_SEND_COMMAND(0x01);
			LCD_8_BIT_MODE_SEND_COMMAND(0x80);
			i=0;
		}
		
		
	}
}

void LCD_4_BIT_MODE_SEND_COMMAND(vuint8_t command)
{
	Check_IF_Busy();
	Data_Pins_IS_OUTPUT();
	Control_Pins_IS_OUTPUT();
	DIO_write(CONTROL_PORT, RS_PIN, RS_Command);
	DIO_write(CONTROL_PORT, RW_PIN, RW_Write);
	DATA_PORT=(DATA_PORT&0x0F)|(command&0xF0);
	DIO_write(CONTROL_PORT, E_PIN, E_ENABLE);
	delay1(0.0005);
	DIO_write(CONTROL_PORT, E_PIN, E_DISABLE);
	DATA_PORT= (DATA_PORT & 0x0F)|(command<<4);
	DIO_write(CONTROL_PORT, E_PIN, E_ENABLE);
	delay1(0.0005);
	DIO_write(CONTROL_PORT, E_PIN, E_DISABLE);
}



void LCD_4_BIT_MODE_INIT(void)
{
	Control_Pins_IS_OUTPUT();
	Data_Pins_IS_OUTPUT();
	delay1(0.002);
	LCD_4_BIT_MODE_SEND_COMMAND(0x02);
	
	LCD_4_BIT_MODE_SEND_COMMAND(0X28);
	
	LCD_4_BIT_MODE_SEND_COMMAND(0X0E);
	
	LCD_4_BIT_MODE_SEND_COMMAND(0X06);
	
	LCD_4_BIT_MODE_SEND_COMMAND(0X01);
	
	LCD_4_BIT_MODE_SEND_COMMAND(0X80);
}
void LCD_4_BIT_MODE_DISPLPLY_CHARACTER(vuint8_t character)
{
	Check_IF_Busy();
	Data_Pins_IS_OUTPUT();
	Control_Pins_IS_OUTPUT();
	DIO_write(CONTROL_PORT, RS_PIN, RS_Data);
	DIO_write(CONTROL_PORT, RW_PIN, RW_Write);
	DATA_PORT=(DATA_PORT&0x0F)|(character&0xF0);
	DIO_write(CONTROL_PORT, E_PIN, E_ENABLE);
	delay1(0.0005);
	DIO_write(CONTROL_PORT, E_PIN, E_DISABLE);
	
	DATA_PORT= (DATA_PORT & 0x0F)|(character<<4);
	DIO_write(CONTROL_PORT, E_PIN, E_ENABLE);
	delay1(0.0005);
	DIO_write(CONTROL_PORT, E_PIN, E_DISABLE);	
}




void LCD_4_BIT_MODE_DISPLPLY_STRING(char *STRING)
{
	char*P;
	P=(char *)STRING;
	int i=0;
	while(*P!='\0')
	{
		if(i<16)
		{
			if(*P=='\n')
			{
				LCD_4_BIT_MODE_SEND_COMMAND(0xC0);
			}
			LCD_4_BIT_MODE_DISPLPLY_CHARACTER(*P);
			delay1(0.005);
			P++;
			i++;
		}
		else if(i<32)
		{
			LCD_4_BIT_MODE_SEND_COMMAND(0xC0);	
			while(*P!='\0')
			{
				LCD_4_BIT_MODE_DISPLPLY_CHARACTER(*P);
				delay1(0.005);
				P++;
				i++;
				if (i==32)
				{
					delay1(5);
					break;	
				}
			}
		}
		else
		{
			LCD_4_BIT_MODE_SEND_COMMAND(0x01);
			LCD_4_BIT_MODE_SEND_COMMAND(0x80);	
			i=0;   
		}		
}
}
void LCD_DISPLAY_STRING(char *STRING)
{
	
	#ifdef LCD_4_BIT_MODE
	LCD_4_BIT_MODE_INIT();
	LCD_4_BIT_MODE_DISPLPLY_STRING((char*)STRING);
	#endif
	#ifdef LCD_8_BIT_MODE
	LCD_8_BIT_MODE_INIT();
	LCD_8_BIT_MODE_DISPLPLY_STRING((char*)STRING);
	#endif

}
void LCD_DISPLAY_CHARACTER(char CHARACTER)
{
	
	#ifdef LCD_4_BIT_MODE
	LCD_4_BIT_MODE_INIT();
	LCD_4_BIT_MODE_DISPLPLY_CHARACTER(CHARACTER);
	#endif
	#ifdef LCD_8_BIT_MODE
	LCD_8_BIT_MODE_INIT();
	LCD_8_BIT_MODE_DISPLPLY_CHARACTER(CHARACTER);
	#endif

}

void LCD_GotoXY(unsigned char line, unsigned char position )
{

	if(line==0)
	{
		if (position < 16 && position >=0)
		{
		#ifdef LCD_4_BIT_MODE
		LCD_4_BIT_MODE_SEND_COMMAND(0x80+position);
		#endif
		#ifdef LCD_4_BIT_MODE
		LCD_8_BIT_MODE_SEND_COMMAND(0x80+position);
		#endif
		}
	}
	else if (line==1)
	{
		if (position < 16 && position >=0)
		{
		#ifdef LCD_4_BIT_MODE
		LCD_4_BIT_MODE_SEND_COMMAND(0xc0+position);
		#endif
		#ifdef LCD_4_BIT_MODE
		LCD_8_BIT_MODE_SEND_COMMAND(0xc0+position);
		#endif
		}

	}
}