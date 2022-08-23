.global reset
reset: 
	ldr sp, = Stack_Top
	bl main
stop: b stop