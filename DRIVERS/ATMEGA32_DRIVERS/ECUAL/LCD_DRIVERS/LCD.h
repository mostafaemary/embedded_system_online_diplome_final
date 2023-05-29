/*
 * IncFile1.h
 *
 * Created: 5/12/2023 2:57:31 AM
 *  Author: MOSTAFA
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../MCAL/DIO.h"

void Check_IF_Busy(void);


//8_BIT_MODE_APIS
void LCD_8_BIT_MODE_INIT(void);
void LCD_8_BIT_MODE_SEND_COMMAND(uint8_t COMMAND);
void LCD_8_BIT_MODE_DISPLPLY_CHARACTER(vuint8_t character);
void LCD_8_BIT_MODE_DISPLPLY_STRING(char *STRING);


//4_BIT_MODE_APIS
void LCD_4_BIT_MODE_INIT(void);
void LCD_4_BIT_MODE_SEND_COMMAND(vuint8_t command);
void LCD_4_BIT_MODE_DISPLPLY_CHARACTER(vuint8_t character);
void LCD_4_BIT_MODE_DISPLPLY_STRING(char *STRING);
void LCD_DISPLAY_STRING(char *STRING);
void LCD_DISPLAY_CHARACTER(char CHARACTER);
void LCD_GotoXY(unsigned char line, unsigned char position );
#endif /* LCD_H_ */
