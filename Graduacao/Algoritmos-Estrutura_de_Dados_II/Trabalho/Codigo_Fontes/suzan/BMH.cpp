#include <string.h>
#include <stdio.h>
#include "BMH.hpp"

void horspool(TipoContador *cont, TipoTexto texto, TipoPadrao padrao, size_t tamTexto, size_t tamPadrao) {
    long i, j, k, vet[NUM_CHARS+1];
    
    //Pre-processamento
    cont->tempoPre = clock();

    for(j=0; j<=NUM_CHARS; j++) vet[j] = tamPadrao;
    for(j=1; j<tamPadrao; j++) vet[padrao[j-1]] = tamPadrao - j;

    cont->tempoPre = clock() - cont->tempoPre;

    //Pesquisa
    cont->tempo = clock();

    i=tamPadrao;

    while(i<=tamTexto){

        k=i;
        j=tamPadrao;

        while(cont->comparacoes++, texto[k-1]==padrao[j-1] && j>0){
            k--;
            j--;
        }

        if(j==0){
            printf("\nOcorrencia na posicao: %lu", k+1);
            cont->ocorrencias++;
        }

        i+=vet[texto[i-1]];
        cont->deslocamentos++;
    }

    cont->tempo = clock() - cont->tempo;
}