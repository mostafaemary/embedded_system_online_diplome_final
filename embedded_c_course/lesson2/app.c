#include "uart.h"
unsigned char S_B[100]="learn in depth: mostafa emary";
int main()
{
	UART_SEND_STRING_(S_B);
	return 0;
}