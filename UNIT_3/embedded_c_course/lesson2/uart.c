#include "uart.h"
#define UARTDR 		*((volatile unsigned int*)((unsigned int *) 0x101F1000))
void UART_SEND_STRING_(unsigned char* p)
{
	while (*p!='\0')
	{
		UARTDR =(unsigned int)*p;
		p++;
	}
}