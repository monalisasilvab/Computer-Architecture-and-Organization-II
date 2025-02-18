all: folder app

CC  = gcc
BIN = app

INC = -I./inc

ARQ =	valid_hex.o \
		read_file.o \
		decoder.o \
		decoder_cond.o \
		decoder_regs.o \
		main.o

app: $(ARQ)
	$(CC) $(INC) obj/main.o obj/decoder_regs.o obj/decoder_cond.o obj/decoder.o obj/read_file.o obj/valid_hex.o -o bin/app	 
	
main.o: src/main.c
	$(CC) -o main.o -c $(INC) src/main.c -o obj/main.o

decoder_regs.o: src/decoder_regs.c
	$(CC) -o decoder_regs.o -c $(INC) src/decoder_regs.c -o obj/decoder_regs.o

decoder_cond.o: src/decoder_cond.c
	$(CC) -o decoder_cond.o -c $(INC) src/decoder_cond.c -o obj/decoder_cond.o

decoder.o: src/decoder.c
	$(CC) $(INC) src/decoder.c -c -o obj/decoder.o

read_file.o: src/read_file.c
	$(CC) -o read_file.o -c $(INC) src/read_file.c -o obj/read_file.o

valid_hex.o: src/valid_hex.c
	$(CC) -o valid_hex.o -c $(INC) src/valid_hex.c -o obj/valid_hex.o	

folder: 
	mkdir -p bin obj

clean:
	rm obj/*.o bin/*.bin -rf obj/ bin/ tags
