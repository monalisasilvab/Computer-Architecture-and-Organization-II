CHAIN=arm-none-eabi
CFLAGS=-std=c99 -Wall
IPATH=-Iinc/
SRC=src/
OBJ=obj/
BIN=bin/
TFTP=/tftpboot/

all: app

app: clean obj/start.o
	$(CHAIN)-ld $(OBJ)start.o $(SRC)linkerscript.lds -o $(OBJ)start.elf
	$(CHAIN)-objcopy $(OBJ)start.elf $(BIN)spl.boot -O binary
	cp $(BIN)spl.boot /tftpboot/appGpio.bin
	ln -s $(TFTP)appGpio.bin $(TFTP)app

$(OBJ)start.o: $(SRC)start.s
	$(CHAIN)-as $(IPATH) $(SRC)start.s -o $(OBJ)start.o

clean:
	rm -rf $(OBJ)* $(BIN)*
