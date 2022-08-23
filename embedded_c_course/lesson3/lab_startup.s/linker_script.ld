/* linker script for cortexM3
Eng. Mostafa Emary
*/

MEMORY
{
	FLASH(RX) : ORIGIN = 0X08000000, LENGTH = 128K
	SRAM(RWX) : ORIGIN = 0X20000000, LENGTH = 20K
}
SECTIONS
{
	.text : {
			*(.vectors*)
			*(.text*)
			*(.rodata)
			_E_text_ = . ;
	}> FLASH
 
	.data : {
			_S_DATA_ = . ;
			*(.data)
			. = ALIGN(4) ;
			_E_DATA_ = . ;
	}> FLASH
	.bss : {
			_S_BSS_ = . ;
			*(.bss)
			. = ALIGN(4) ;
			_E_BSS_ = . ;
			. = . + 0x1000 ;
			_stack_top = . ;
	}> SRAM
}