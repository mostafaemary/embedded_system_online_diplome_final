#@copyright : mostafa emary
CC=arm-none-eabi-
CFLAGS= -g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
PROJECT_NAME=UART_LAB

all: $(PROJECT_NAME).bin	
	@echo "==========Bild is Done========="
startup.o: startup.s 
	$(CC)as.exe $(CFLAGS) $<	-o $@
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS)  $(INCS)  $<	-o $@

$(PROJECT_NAME).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -Map=OUTPUT.map -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o	$@
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf 
	$(CC)objcopy.exe -O binary $<	$@


clean_all:
		rm *.o *.elf *.bin 


clean:
		rm *.elf *.bin
	