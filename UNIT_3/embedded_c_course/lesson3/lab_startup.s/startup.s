/* 
startup_cortexM3.s
eng. Mostafa Emary 
*/
/* BOOT ROM SW: STARTS FROM 0x0000 0000 TO 0x0800 0000 */
/* FLASH starts at 0x0800 0000 */
/* SRAM starts at 0x2000 0000 */
/* SP_Adress */ 
.section .vectors			/* creat vector section for these lines */
.word _stack_top	  		/* stack top adress */
.word _reset		  		/* 1 reset */
.word _vector_handler 		/* 2 NMI */
.word _vector_handler		/* 3 MM FAULT */
.word _vector_handler		/* 4 BUS FAULT */
.word _vector_handler		/* 5 USAGE FAULT */
.word _vector_handler		/* 6 HARD FAULT */
.word _vector_handler		/* 7 REVERSED */
.word _vector_handler		/* 8 REVERSED */
.word _vector_handler		/* 9 REVERSED */
.word _vector_handler		/* 10 REVERSED */
.word _vector_handler		/* 11 SV call */
.word _vector_handler		/* 12 DEBUG reversed */
.word _vector_handler		/* 13 REVERSED */
.word _vector_handler		/* 14 PondSV */
.word _vector_handler		/* 15 SysTic */
.word _vector_handler		/* 16 IRQ0 */
.word _vector_handler		/* 17 IRQ1 */
.word _vector_handler		/* 18 IRQ2 */
.word _vector_handler		/* 19 ... */
			/* on to IRQ67 */
.section .text
_reset:
	bl main
	b .
.thumb_func 
_vector_handler:
	b _reset
