#include "funcoes.h"
#include "comparacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){ 

	if(argc < 4 || argc > 5){
        cout <<"FORMATO DE EXECUCAO: executavel <metodo> <texto> <padrao> [-P]\n";
        cout << "Metodos:\n1 - Forca Bruta\n2 - BM(Cadeia)\n3 - BMH\n4 - BMHS\n5 - ShiftAnd" << endl;
        exit(1);
    }        

	FILE *ftexto, *fpadrao;
	TipoTexto texto;
	TipoPadrao padrao;
	char ch;
	int tamTexto = 0, tamPadrao = 0;
	int metodo;

	// Recebendo os argumetnos do console
	metodo = atoi(argv[1]);
	strcpy(texto, argv[2]);
	strcpy(padrao, argv[3]);

	/* Abre o arquivo texto para leitura */
	if((ftexto = fopen(texto, "r")) == NULL){
		printf("\tNão foi possível abrir %s!\n", texto);
		exit(1);
	}

	// Transfere o arquivo de texto para a memória principal
	ch = getc(ftexto); // Lê o primeiro caracter do texto
	printf("ok1\n");
	while (ch != EOF){
		texto[tamTexto] = ch;
		ch = getc(ftexto); // Lê o próximo caracter
		tamTexto++; // Contador do tamanho do texto
	}

	
	printf("ok2\n");
	/* Abre o arquivo texto que guarda o padrao */
	if((fpadrao = fopen(padrao, "r")) == NULL){
		printf("\tNão foi possível abrir %s!\n", padrao);
		exit(1);
	}

	// Transfere o padrão para a memória principal
	ch = getc(fpadrao);
	while (ch != EOF){
		padrao[tamPadrao] = ch;
		ch = getc(fpadrao);
		tamPadrao++;
	}

	fclose(ftexto);
	fclose(fpadrao);

	printf("OK3\n");
    iniciaContadores();
    switch(metodo){
        case 1:
            ForcaBruta(texto, tamTexto, padrao, tamPadrao);
            break;
        case 2:
            BMC(texto, tamTexto, padrao, tamPadrao);
            break;
        case 3:
            BMH(texto, tamTexto, padrao, tamPadrao);
            break;
        case 4:
            BMHS(texto, tamTexto, padrao, tamPadrao);
            break;
        case 5:
        	ShiftAnd(texto, tamTexto, padrao, tamPadrao);
        	break;
        default:
            cout << "METODO INVALIDO\n";
            break;
        
    }
 	printf("ok4\n");   
    //verifica se o usuario deseja ver os dados de estatistica computados
    if(argc == 5){
        returnDados();
    }

    return 0;
}
