#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADCasamentoCadeia.h"

void visu()
{
	printf("\n");
	for(int i=0; i<75; i++)
	{
		printf("_");
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
    if (atoi(argv[1]) < 1 || atoi(argv[1])>5)
    {
        printf("Metodo invalido. Programa encerrado");
        return 0;
    }
    if (argc < 4)
    {
        printf("Falta parametros. Programa encerrado");
        return 0;
    }
    /*if (strcmpi(argv[2], "-P") == 0 || strcmpi(argv[3], "-P") == 0)
    {
        printf("Parametro invalido. Programa encerrado");
        return 0;
    }*/

    clock_t inicio, fim;
    inicio = clock();
    TComparacao dado;
    dado.nComp = dado.nDesloc = 0;
    
    switch (atoi(argv[1]))
	{
		case 1:
			visu();
			forcaBruta(argv[2],argv[3],strlen(argv[3]),&dado);
			fim = clock();
			break;
		case 2:
			visu();
			BM_Ocorrencia(argv[2], argv[3], strlen(argv[3]), &dado);
			fim = clock();
			break;
		case 3:
			visu();
			BMH(argv[2],argv[3],strlen(argv[3]),&dado);
			fim = clock();
			break;
		case 4:
			visu();
			ShiftAndExato(argv[2], argv[3], strlen(argv[3]), &dado);
			fim = clock();
			break;
		case 5:
			visu();
			BMHS(argv[2],argv[3],strlen(argv[3]),&dado);
			fim = clock();
			break;
		default:
			printf("\nValor invalido\n");
			break;
    }
   // if (strcmpi(argv[4], "-P") == 0)
	{
        printf("\nTempo de execucao %.2f milisegundos.\nForam realizadas %d comparacoes e %d deslocamento.\n", difftime(fim, inicio), dado.nComp, dado.nDesloc);
        visu();
    }
	return 0;
}
