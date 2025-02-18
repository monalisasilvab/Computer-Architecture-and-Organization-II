#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decoder.h"

void read_file(){
	char *hexa;
	int num, instruction = 0, opcode_num, option, a = 0, contador = 0, i = 0;
	int valid = 0;
	char nome_arquivo[256];
	char buffer[1024];

	hexa = (char *)calloc(10000000, sizeof(char));

	printf("Insira o nome do arquivo: ");

	scanf("%s", nome_arquivo);

	char *extensao_ptr = strstr(nome_arquivo, ".in");

	if(extensao_ptr == NULL) {
		printf("Arquivo com extensão errada!\n");
		exit(1);
	}

	FILE *arquivo_entrada;
	arquivo_entrada = fopen(nome_arquivo,"r");

	if(arquivo_entrada == NULL){
		printf("Arquivo não encontrado!\n");
		exit(1);
	}

	strcpy(extensao_ptr, ".out");

	FILE *arquivo_saida;
	arquivo_saida = fopen(nome_arquivo,"w+");

	while(fgets(hexa, 10000000, arquivo_entrada) != NULL){
    	/* writing content to stdout */
    	//puts(hexa);

		sscanf(hexa, "%x", &num);

	/*
		for(i = 0; i < 10000000; i++){
			if((hexa[i] == '0' || hexa[i] == '1' || hexa[i] == '2' || hexa[i] == '3' || hexa[i] == '4' || hexa[i] == '5' || 
				hexa[i] == '6' || hexa[i] == '7' || hexa[i] == '8' || hexa[i] == '9' || hexa[i] == 'a' || hexa[i] == 'b' || 
				hexa[i] == 'c' || hexa[i] == 'd' || hexa[i] == 'e' || hexa[i] == 'f'|| hexa[i] == 'A' || hexa[i] == 'B' || 
				hexa[i] == 'C'|| hexa[i] == 'D'|| hexa[i] == 'E'|| hexa[i] == 'F')){

				valid++;
			}

			else{
				printf("Numero inválido.\n");
				break;
			}
		}

	*/
    		while(hexa[a] != '\n'){
				contador++;
				a++;
			}

			if(contador > 4 || contador < 4){
				printf("Instrução inválida!\n");
				printf("\n");	
			}

				else{ 
	   				opcode_num = opcode(instruction, num);
	
					instruction_decoder(instruction, opcode_num, num, buffer);

					fprintf(stdout, "%04x\t%s\n", num, buffer);
					fprintf(arquivo_saida, "%04x\t%s\n", num, buffer);
				}

			contador = 0;
			a = 0;
	}

	free(hexa);
	fclose(arquivo_entrada);
	fclose(arquivo_saida);
}