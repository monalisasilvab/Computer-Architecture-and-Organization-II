#include <stdio.h>
#include <stdlib.h>
#include "decoder.h"

int main(){

	int option;

	system("/usr/bin/clear");
	
	printf("### Thumb instruction set decoder ###\n");
	retorna:
	printf("\n1-Digitar instrução. \n2-Ler instruções do arquivo. \n3-Sair.\n\n");
	scanf("%d", &option);

	system("/usr/bin/clear");

	switch(option){

		case 1:

		valid_hex_number();

		break;

		case 2:

		read_file();

		break;

		case 3:

		exit(1);

		break;

		default:

		printf("Digite novamente!\n");

		goto retorna;
		break;
	}	
}