#ifndef DECODER_REGS_H_
#define DECODER_REGS_H_

typedef enum types{
	TYPE_1,		//2 registradores e um imediato (5 bits)
	TYPE_1_1,	//2 registradores e um imediato (5 bits) (Byte access)
	TYPE_1_2,	//2 registradores e um imediato (5 bits) (Half access)
	TYPE_1_3,	//2 registradores e um imediato (5 bits) (Word access)
	TYPE_2_1,		//3 registradores (MEMORIA)
	TYPE_2_2,		//3 registradores
	TYPE_3, 	//2 registradores e um imediato (3 bits)
	TYPE_4, 	//1 registrador e um imediato (8 bits)
	TYPE_4_1,	//1 registrador e um imediato (8 bits) (pc) [MEMORIA]
	TYPE_4_2,	//1 registrador e um imediato (8 bits) (sp) [MEMORIA]
	TYPE_4_3,	//1 registrador e um imediato (8 bits) (pc)
	TYPE_4_4,	//1 registrador e um imediato (8 bits) (sp)
	TYPE_5, 	//2 registradores
	TYPE_6,		//Lista de registradores 
	TYPE_6_1, 	//Lista de registradores - PUSH
	TYPE_6_2,	//Lista de registradores - POP
	TYPE_7,		//1 imediato (8 bits)
	TYPE_8,		//1 imediato (11 bits)
	TYPE_9,		//1 imediato (11 bits)
	TYPE_10     //1 registrador
} types;

typedef enum regs{
	R0,
	R1, 
	R2, 
	R3, 
	R4,		
	R5, 
	R6,		
	R7, 
	R8, 
	R9, 
	R10, 
	R11, 
	R12, 
	R13, 
	R14, 
	R15,
} regs;

char *decoder_reg(int reg);
void name_reg(int num, int TYPE, char *buffer);

#endif // DECODER_REGS_H_

