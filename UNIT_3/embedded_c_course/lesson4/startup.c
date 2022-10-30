#include "stdint.h"
typedef volatile unsigned int vuint32_t;
void Reset_Handler();
extern int main();
void Default_Handler()
{
	Reset_Handler();
}
void NMI_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void LL_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void MM_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));
void MM_Bus() __attribute__ ((weak, alias ("Default_Handler")));
void Usage_Fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));

static vuint32_t _stack_top [256];

/*
extern vuint32_t _stack_top;
vuint32_t vectors[] __attribute__ ((section(".vectors")))={

	(vuint32_t) (&_stack_top+1),
	(vuint32_t) &Reset_Handler,
	(vuint32_t) &NMI_Handler,
	(vuint32_t) &LL_Fault_Handler,
	(vuint32_t) &MM_Fault_Handler,
	(vuint32_t) &MM_Bus,
	(vuint32_t) &Usage_Fault_Handler
};
*/	
//interview question (define stack top automaticlly on .bss )
void (* const g_p_func_vectors[])() __attribute__ ((section(".vectors")))= //array of pointers to function take nothing and return void 
{
(void (*)()) ((uint32_t)&_stack_top+1),//casting adresses to the type of array element to avoid warning
&Reset_Handler,// we can cast it but it's from the same type (show the implementation)(pointer to func take nothing and return void)
&NMI_Handler,
&LL_Fault_Handler,
&MM_Fault_Handler,
&MM_Bus,
&Usage_Fault_Handler
};


extern uint32_t _E_text_ ;
extern uint32_t _S_DATA_ ;
extern uint32_t _E_DATA_ ;
extern uint32_t _S_BSS_ ;
extern uint32_t _E_BSS_ ;
void Reset_Handler(){
		//copy data section from flash to sram
		vuint32_t DATA_SIZE = (uint8_t*)&_E_DATA_ - (uint8_t*)&_S_DATA_ ;
		uint8_t* p_scr = (uint8_t*)&_E_text_ ;
		uint8_t* p_dst = (uint8_t*)&_S_DATA_ ;
		vuint32_t i;
		for (i = 0;i<DATA_SIZE;i++)
		{
			*((uint8_t*)p_dst++) = *((uint8_t*)p_scr++);
		}
		//init .bss section in sram by 0
		vuint32_t BSS_SIZE = (uint8_t*)&_E_BSS_ - (uint8_t*)&_S_BSS_ ;
		p_dst = (uint8_t*)&_S_BSS_ ;
		for (i = 0;i<BSS_SIZE;i++)
		{
			*((uint8_t*)p_dst++) = (uint8_t) 0;
		}

		//jump main
	main();
}