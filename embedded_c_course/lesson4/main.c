typedef volatile unsigned int vuint32_t;
//#include "stdint.h"
#define SYSCTL_BASE 0x400FE000
#define SYSCTL_RCGC2_R *( (vuint32_t*) (SYSCTL_BASE + 0x018) )
#define GPIOF_BASE  0x40025000
#define GPIO_PORTF_DEN_R  *((vuint32_t*) (GPIOF_BASE + 0x51C))
#define GPIO_PORTF_DIR_R  *((vuint32_t*) (GPIOF_BASE + 0x400))
#define GPIO_PORTF_DATA_R *((vuint32_t*) (GPIOF_BASE + 0x3FC))



int main()
{
	vuint32_t delay;
	SYSCTL_RCGC2_R = 0x00000020;
	//delay to make sure GPIOF is UP and running
	for (delay=0;delay<500;delay++);
	//enable pin 3 to be ready for write on it
	GPIO_PORTF_DEN_R |= 1<<3;
	//enable pin 3 direction is output
	GPIO_PORTF_DIR_R |=1<<3;
	//toggling led pf3
	while (1)
	{
	GPIO_PORTF_DATA_R |=1<<3;
	for (delay=0;delay<200000;delay++);
	GPIO_PORTF_DATA_R &=~(1<<3);
	for (delay=0;delay<200000;delay++);
	}
	return 0;
}
