/*******************************************************
*                                                      *
*   Criado em: Dom 02/Out/2016,  20:20 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/
#ifndef DECODER_H_
#define DECODER_H_

int opcode(int instruction, int num);
void instruction_decoder(int instruction, int opcode, int num, char *buffer);
void read_file();
void valid_hex_number();

#endif //DECODER_H_
