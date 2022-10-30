ENTRY(reset)
MEMORY
{
	FLASH (rwx):ORIGIN = 0x00000000 , LENGTH = 64M
}

SECTIONS
{
	. = 0x10000;
	.startup . :
	{
		startup.o(.text)
	}> FLASH
	.text :
	{
		*(.text)
	}> FLASH
	.data :
	{
		*(.data)
		*(.rodata)
	}> FLASH
	.bss :
	{
		*(.bss)
	}> FLASH
	. = . + 0x1000 ;
	Stack_Top = . ;

}