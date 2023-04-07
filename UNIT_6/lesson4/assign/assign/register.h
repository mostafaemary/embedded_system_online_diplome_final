//REGISTERS CONFIGURATION
#define PORTA *(vuint8_t*)(0x3B)//8 bit register
#define DDRA *(vuint8_t*)(0x3A)//8 bit register
#define PINA *(vuint8_t*)(0x39)//8 bit register
/*PORTB REGISTERS*/
#define PORTB *(vuint8_t*)(0x38)//8 bit register
#define DDRB *(vuint8_t*)(0x37)//8 bit register
#define PINB *(vuint8_t*)(0x36)//8 bit register
/*PORTC REGISTERS*/
#define PORTC *(vuint8_t*)(0x35)//8 bit register
#define DDRC *(vuint8_t*)(0x34)//8 bit register
#define PINC *(vuint8_t*)(0x33)//8 bit register
/*PORTD REGISTERS*/
#define PORTD *(vuint8_t*)(0x32)//8 bit register
#define DDRD *(vuint8_t*)(0x31)//8 bit register
#define PIND *(vuint8_t*)(0x30)//8 bit register
//TIMER 0 REGISTERS
#define TCCR0 *(vuint8_t*)(0x53)//8 bit register
#define TCNT0 *(vuint8_t*)(0x52)//8 bit register
#define TIFR *(vuint8_t*)(0x58)//8 bit register
//status register
#define SREG *(vuint8_t*)(0x5f)//8 bit register
//external INT CONTROL REG
#define MCUCR *(vuint8_t*)(0x55)//8 bit register
#define MCUCSR *(vuint8_t*)(0x54)//8 bit register
//general int control reg
#define GICR *(vuint8_t*)(0x5B)//8 bit register
#define GIFR *(vuint8_t*)(0x5A)//8 bit register