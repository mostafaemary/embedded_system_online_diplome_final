#@copyright : mostafa emary
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -mthumb -gdwarf-2 -g #to debug by Uvision5
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
PROJECT_NAME=UNIT3_LAB4_CORTEXM4

all: $(PROJECT_NAME).bin	
	@echo "==========Bild is Done========="
#startup.o: startup.s 
#	$(CC)as.exe $(CFLAGS) $<	-o $@
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS)  $(INCS)  $<	-o $@

$(PROJECT_NAME).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o	$@ -Map=Map_file.map
	cp $(PROJECT_NAME).elf $(PROJECT_NAME).axf		#to copy .elf file(executable)  to .axf(executable"to debug it with Uvesion5")
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf 
	$(CC)objcopy.exe -O binary $<	$@


clean_all:
		rm *.o *.elf *.bin 


clean:
		rm *.elf *.bin
	