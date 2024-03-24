#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TADCasamentoCadeia.h"

void forcaBruta(char nmArq[],char p[],int m, TComparacao *dado)
{

    FILE *pArq = fopen(nmArq, "r");
    if (!pArq)
    {                                       // Verificando a abertura do arquivo
        perror("Erro ao abrir o arquivo");
        exit(0);
    }
    fseek(pArq, 0, 2);                      // Deslocando o ponteiro para o final do arquivo;
    int n = ftell(pArq);                    // Tamanho do arquivo;
    rewind(pArq);                           // Deslocando o ponteiro para o inicio do arquivo;
    char *t = (char *) malloc(n);
    int i=0;
    printf("\n\nForca Bruta:\n");
    while (!feof(pArq))
    {
        t[i] = fgetc(pArq);                 // Copia todo o texto para t
        i++;
    }
    fclose(pArq);
    long j,k;
    for (i=1; i<=(n-m+1); i++)
    {
        k=i;
        j=1;
        dado->nComp++;
        while (t[k-1] == p[j-1] && j<=m)
        {
            j++;
            k++;
            dado->nComp++;
            dado->nDesloc++;
        }
	dado->nDesloc++;
        if (j>m)                                // o j caso ocorra casamento será maior pois a comparação é feita até j<=m;
        {
            printf("Casamento na posicao: %d\n",i);
        }
    }

}
