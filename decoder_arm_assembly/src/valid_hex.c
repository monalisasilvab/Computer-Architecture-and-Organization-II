#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "decoder.h"

void valid_hex_number(){

int instruction = 0;
int opcode_num; 
int option;
int num; //variavel que recebe o numero da string e armazena esse valor em hexadecimal
char *hexa; //ponteiro para string que armazena o numero hexadecimal do usuário
int j = 0; //contador que passa pela string, analisando cada caractere
int count = 0; //contador para verificar quantos caracteres existe na string
int a; //outro contador que passa pela string, verificando se existem numeros de 0x0000 até 0xFFFF
int valido = 0; //variável que permite que sempre 4 caracteres válidos sejam aceitos

system("/usr/bin/clear");

digitar_novamente: 

hexa = (char *)calloc(100, sizeof(char));

if(hexa == NULL){
    printf("Error! memory not allocated.");
    exit(0);
}

printf("Digite um valor em hexadecimal: ");
scanf("%s", hexa);

	//scanf("%x%*c", &i);
	while(hexa[j] != '\0'){
		count++;
		j++;
	}

	if(count > 4){

		printf("Número inválido.\n");
		sleep(1);
		printf("Digite outro hexadecimal.\n");
		free(hexa);
		j = 0;
		count = 0;
		valido = 0;
		system("/usr/bin/clear");
		free(hexa);
		goto digitar_novamente;
	}

	for(a = 0; a < 4; a++){
		if(hexa[a] == '0' || hexa[a] == '1' || hexa[a] == '2' || hexa[a] == '3' || hexa[a] == '4' || hexa[a] == '5' || 
			hexa[a] == '6' || hexa[a] == '7' || hexa[a] == '8' || hexa[a] == '9' || hexa[a] == 'a' || hexa[a] == 'b' || 
			hexa[a] == 'c' || hexa[a] == 'd' || hexa[a] == 'e' || hexa[a] == 'f'|| hexa[a] == 'A' || hexa[a] == 'B' || 
			hexa[a] == 'C'|| hexa[a] == 'D'|| hexa[a] == 'E'|| hexa[a] == 'F'){

			valido++;
				
		}

		else{
			
			printf("Número inválido.\n");
			sleep(1);
			printf("Digite outro hexadecimal.\n");
			sleep(1);
			free(hexa);
			a = 0;
			j = 0;
			count = 0;
			valido = 0;
			system("/usr/bin/clear");
			goto digitar_novamente;
		}
	}

		if(valido = 4){
			printf("Número válido!\n");
		}

		else{
			printf("Número inválido! Digite novamente!\n");
			sleep(1);
			free(hexa);
			j = 0;
			count = 0;
			valido = 0;
			system("/usr/bin/clear");
			goto digitar_novamente;
		}

		sscanf(hexa, "%x%*c", &num); //conversão da string para hexadecimal

		opcode_num = opcode(instruction, num);
	
		printf("Decoded instruction:\n");
		instruction_decoder(instruction, opcode_num, num, hexa);

		printf("%s\n", hexa);

		free(hexa);
}
