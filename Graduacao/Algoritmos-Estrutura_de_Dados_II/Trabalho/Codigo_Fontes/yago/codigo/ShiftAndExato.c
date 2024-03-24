#include <stdio.h>
#include <stdlib.h>
#include "TADCasamentoCadeia.h"

#define MAXCHAR 256

void ShiftAndExato(char nmArq[], char p[], int tamPadrao, TComparacao *dado)
{
    printf("\n\nShift And Exato:\n");
    FILE *pArq = fopen(nmArq, "r");
    if (!pArq)
    { //Checando a abertura do arquivo;
        perror("Erro ao abrir o arquivo");
        exit(0);
    }

    long Masc[MAXCHAR], R = 0;
    fseek(pArq, 0, 2);                  //O ponteiro e deslocado para o final do arquivo;
    int tamArq = ftell(pArq);
    int i=0;
    rewind(pArq);                       //O ponteiro e deslocado para o inicio do arquivo;

    char *t = (char *) malloc(tamArq);   // vetor texto

    while (!feof(pArq)) {
        t[i] = fgetc(pArq);
        i++;
    }
    fclose(pArq);


    for (i=0; i<MAXCHAR; i++)
        Masc[i] = 0;
    for (i=1; i<=tamPadrao; i++)
        Masc[p[i-1] + 127] |= 1 << (tamPadrao - i);
    for (i=0; i<tamArq; i++) {
        R = ((((unsigned long) R)>>1) | (1<<(tamPadrao-1))) & Masc[t[i] + 127];
        dado->nComp++;
        dado->nDesloc++;
        if ((R & 1) != 0)
        {
            printf("Casamento na posicao: %d\n", i-tamPadrao+2);
        }
    }
}