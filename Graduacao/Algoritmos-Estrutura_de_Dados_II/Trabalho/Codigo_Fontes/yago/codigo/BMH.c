#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TADCasamentoCadeia.h"

#define MAXCHAR 256

void BMH(char nmArq[],char p[],int m,TComparacao *dado)
{
    FILE *pArq = fopen(nmArq, "r");
    if (!pArq) 
    {
        perror("Erro ao abrir o arquivo");
        exit(0);
    }

    fseek(pArq, 0, 2); // Ir para o fim do arquivo.
    int n = ftell(pArq); // Tamanho do arquivo.
    rewind(pArq); // Volta o cursor do arquivo para o inicio.

    char *texto = (char *) malloc(n);
    int x=0;
    while (!feof(pArq)) {
        texto[x] = fgetc(pArq);
        x++;
    }
    fclose(pArq); 
    printf("\n\nBoyer Moore Horspool:\n");

    long i,j,k;
    long d[MAXCHAR + 1];

    for (j=0; j<=MAXCHAR; j++)                        //Para todos os valores fora do padrão o valor de deslocamento é igual a "m".

        d[j] = m;                             
    for (j=1; j<m; j++)                               //Calcula o valor de deslocamento para os caracteres dentro do padrão "p".
        d[(unsigned char)p[j-1]] = m-j;
    i=m;
    while (i<=n) 
    {
        k=i;
        j=m;
        dado->nComp++;
        while (texto[k-1] == p[j-1] && j>0) {
            k--;
            j--;
            dado->nComp++;
            dado->nDesloc++;
        }
        if (j == 0)
            printf("Casamento na posicao: %3ld\n",k+1);
        i += d[(unsigned char)texto[i-1]];
    }
}