#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "Cadeia.h"
#include "ForcaBruta.h"
#include "BM.h"
#include "BMHS.h"
#include "ShiftAnd.h"

int main(int argc, char* argv[]){
    if(argc<4 || argc>5){
        printf("\nFormato de entrada via linha de comando invalido!\n");
        printf("Formato esperado: <executavel> <metodo> <texto> <padrao> [-P](opcional)\n\n");
        return 0;
    }
    
    clock_t inicio, fim, total;
	double tempo;
    int op;
    char nome[20];
    long comp=0, desloc=0;
    op = atoi(argv[1]);
    strcpy(nome,argv[2]);
    
    while(op<1 || op>4){
		printf("\n  METODO INVALIDO. FAVOR ESCOLHER UMA OPCAO ABAIXO...\n");
		printf(" 1 - Forca Bruta; 2 - Boyer-Moore(BM) com a heuristica ocorrencia. 3 - Boyer-Moore-Horspool-Sunday(BHMS). 4 - Shift-And Exato. \n");
		fflush(stdin);
		scanf("%d",&op);
	}
	while(strcmp(nome ,"texto_pequeno") != 0 && strcmp(nome,"texto_medio") != 0 && strcmp(nome,"texto_grande") != 0){
		printf("\n  NOME DO ARQUIVO INVALIDO. FAVOR DIGITAR UM NOME REFERENTE AS OPCOES ABAIXO...\n\n");
		printf("  || - texto_pequeno - texto_medio - texto_grande \n");
		fflush(stdin);
		scanf("%s",nome);
	}
    
    strcat(nome,".txt");
    TipoTexto tipoTexto;
    
    tipoTexto = lerTexto(nome);
    
    //padrão a ser pesquisado
    TipoPadrao tipoPadrao = malloc(sizeof(argv[3]));
    strcpy(tipoPadrao, argv[3]);

    //avalia qual método vai ser usado
    switch(op){
        case 1:{ //força bruta
            inicio = clock();
            printf("\nMetodo Forca Bruta:\n");
            if(!ForcaBruta(tipoTexto, strlen(tipoTexto), tipoPadrao, strlen(tipoPadrao),&comp,&desloc)){
                printf("\nPadrao nao encontrado\n");
            }
            
            fim = clock();
            total = fim - inicio;
            tempo = ((double)total)/CLOCKS_PER_SEC;
            if(argv[4] != NULL)
            {
                if(strcmp(argv[4],"[-P]") ==0 || strcmp(argv[4],"[-p]")==0)
                {
					printf( "\n RESULTADOS \n"); 
					printf("Metodo de casamento exato de cadeias: Forca Bruta \n");
                    printf("Comparacoes entre os caracteres do texto e do padrao: %-7ld \n",comp);
                    printf("Deslocamentos realizados na varredura de todo o texto: %-7ld \n",desloc);
                    printf("Tempo de execucao do Forca Bruta: %.3f segundos. \n",tempo);					
                }
            }
            break;
        }
        case 2: {//boyer-moore
            inicio = clock();
            printf("\nMetodo Boyer-Moore com a heuristica ocorrencia:\n");
            if(!BM(tipoTexto, strlen(tipoTexto), tipoPadrao, strlen(tipoPadrao),&comp,&desloc)){
                printf("\nPadrao nao encontrado\n");
            }
            
            fim = clock();
            total = fim - inicio;
            tempo = ((double)total)/CLOCKS_PER_SEC;
            if(argv[4] != NULL)
            {
                if(strcmp(argv[4],"[-P]") ==0 || strcmp(argv[4],"[-p]")==0)
                {
                    printf("\n RESULTADOS \n");
                    printf("Metodo de casamento exato de cadeias: Boyer-Moore \n");
                    printf("Comparacoes entre os caracteres do texto e do padrao: %-7ld \n",comp);
                    printf("Deslocamentos realizados na varredura de todo o texto: %-7ld \n",desloc);
                    printf("Tempo de execucao do Boyer-Moore: %.3f segundos. \n",tempo);					
                }
            }
            break;
        }
        case 3:{ //boyer-moore-horspool-sunday
            inicio = clock();
            printf("\nMetodo Boyer-Moore-Horspool-Sunday(BMHS):\n");
            if(!BMHS(tipoTexto, strlen(tipoTexto), tipoPadrao, strlen(tipoPadrao),&comp,&desloc)){
                printf("\nPadrao nao encontrado\n");
            }
            
            fim = clock();
            total = fim - inicio;
            tempo = ((double)total)/CLOCKS_PER_SEC;
            if(argv[4] != NULL)
            {
                if(strcmp(argv[4],"[-P]") ==0 || strcmp(argv[4],"[-p]")==0)
                {
                    printf("\n RESULTADOS \n");
                    printf("Metodo de casamento exato de cadeias: Boyer-Moore-Horspool-Sunday \n");
                    printf("Comparacoes entre os caracteres do texto e do padrao: %-7ld \n",comp);
                    printf("Deslocamentos realizados na varredura de todo o texto: %-7ld \n",desloc);
                    printf("Tempo de execucao do Boyer-Moore-Horspool-Sunday: %.3f segundos. \n",tempo);					
                }
            }
            break;
        }
        case 4:{ //shift-and exato
            inicio = clock();
            printf("\nMetodo Shift-And Exato:\n");
            if(!ShiftAnd(tipoTexto, strlen(tipoTexto), tipoPadrao, strlen(tipoPadrao),&comp,&desloc)){
                printf("\nPadrao nao encontrado\n");
            }
            
            fim = clock();
            total = fim - inicio;
            tempo = ((double)total)/CLOCKS_PER_SEC;
            if(argv[4] != NULL)
            {
                if(strcmp(argv[4],"[-P]") ==0 || strcmp(argv[4],"[-p]")==0)
                {
                    printf("\n RESULTADOS \n");
                    printf("Metodo de casamento exato de cadeias: Shift-And Exato \n");
                    printf("Comparacoes entre os caracteres do texto e do padrao: %-7ld  \n",comp);
                    printf("Deslocamentos realizados na varredura de todo o texto: %-7ld \n",desloc);
                    printf("Tempo de execucao do Shift-And Exato: %.3f segundos. \n",tempo);
                }
            }
            break;
        }
    }
    
    free(tipoTexto);
    free(tipoPadrao);
    return 0;
}
