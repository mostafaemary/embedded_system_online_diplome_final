#include "stdint.h"
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
extern uint32_t _stack_top;
uint32_t vectors[] __attribute__ ((section(".vectors")))=
{
	(uint32_t*) &_stack_top,
	(uint32_t*) &Reset_Handler,
	(uint32_t*) &NMI_Handler,
	(uint32_t*) &LL_Fault_Handler,
	(uint32_t*) &MM_Fault_Handler,
	(uint32_t*) &MM_Bus,
	(uint32_t*) &Usage_Fault_Handler
};
extern uint32_t _E_text_ ;
extern uint32_t _S_DATA_ ;
extern uint32_t _E_DATA_ ;
extern uint32_t _S_BSS_ ;
extern uint32_t _E_BSS_ ;
void Reset_Handler(){
		//copy data section from flash to sram
		uint32_t DATA_SIZE = (uint8_t*)&_E_DATA_ - (uint8_t*)&_S_DATA_ ;
		uint8_t* p_scr = (uint8_t*)&_E_text_ ;
		uint8_t* p_dst = (uint8_t*)&_S_DATA_ ;
		int i;
		for (i = 0;i<DATA_SIZE;i++)
		{
			*((uint8_t*)p_dst++) = *((uint8_t*)p_scr++);
		}
		//init .bss section in sram by 0
		uint32_t BSS_SIZE = (uint8_t*)&_E_BSS_ - (uint8_t*)&_S_BSS_ ;
		p_dst = (uint8_t*)&_S_BSS_ ;
		for (i = 0;i<BSS_SIZE;i++)
		{
			*((uint8_t*)p_dst++) = (uint8_t) 0;
		}
		//jump main
	main();
}