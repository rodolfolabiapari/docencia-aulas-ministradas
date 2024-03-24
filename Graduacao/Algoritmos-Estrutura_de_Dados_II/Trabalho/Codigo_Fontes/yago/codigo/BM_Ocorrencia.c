#include <stdio.h>
#include <stdlib.h>
#include "TADCasamentoCadeia.h"

void BM_Ocorrencia(char nmArq[], char p[], int tamPadrao, TComparacao *dado)
{
    
    FILE *pArq = fopen(nmArq, "r");
    if (!pArq) { 
        perror("Erro ao abrir o arquivo");
        exit(0);
    }
    fseek(pArq, 0, 2); // Ir para o fim do arquivo
    int tamArq = ftell(pArq); // Tamanho do arquivo
    rewind(pArq); // Volta o cursor do arquivo para o inicio

    char *texto = (char *) malloc(tamArq);   
    int i=0, k, j;

    while (!feof(pArq)) {
        texto[i] = fgetc(pArq);
        i++;
    }
    fclose(pArq);

    i=tamPadrao;
    printf("\nBoyer-Moore com heuristica de ocorrencia:\n");

    while (i<=tamArq) {
        k=i;
        j=tamPadrao;                        // Verificando igualdade entre os caracteres
                  
        dado->nComp++;
        while (texto[k-1] == p[j-1] && j>0) {  // busca por semelhantes
            j--;
            k--;
            dado->nDesloc++;
            dado->nComp++;
        }
        if (j == 0)
        {
            printf("Casamento exato na posicao: %d\n", k+1);
            i++;
            continue;
        }

        int salto=1;
        j--;

                                            // Calcula qual e o deslocamento para casamento exato no caracter distinto
        dado->nComp++;
        while (texto[k-1] != p[j-1] && j>0) {
            j--;                            // Leitura da direita para a esquerda no padrao
            salto++;
            dado->nDesloc++;
            dado->nComp++;
        }
        i+=salto;                           // Soma o salto (deslocamento)
    }
    dado->nDesloc+=tamArq;
    free(texto);
}