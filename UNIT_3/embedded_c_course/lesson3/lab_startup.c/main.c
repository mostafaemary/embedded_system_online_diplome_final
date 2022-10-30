
typedef volatile unsigned int vint32_t;

#include"stdint.h"
#define RCC_BASE    0x40021000
#define PORTA_BASE  0x40010800
#define RCC_APB2ENR *((volatile vint32_t*) (RCC_BASE+0x18))
typedef union
{
	vint32_t  ALL_PORTA;
	struct{
		vint32_t REVERSED:13;
		vint32_t LED:1;
		vint32_t reversed:6;
		vint32_t chr_acces:4;
	}PORT_FIELD;
}ACCESS_PORTA;
volatile ACCESS_PORTA*access_a=(volatile ACCESS_PORTA* )PORTA_BASE;
int main()
{
	RCC_APB2ENR|=1<<2;
	access_a->PORT_FIELD.chr_acces=2;
	while(1)
	{
		int i;
		for(i=0;i<5000;i++)
		{
			access_a->PORT_FIELD.LED=1;
		}
		for(i=0;i<5000;i++)
		{
			access_a->PORT_FIELD.LED=0;
		}

	}
	return 0;
}
