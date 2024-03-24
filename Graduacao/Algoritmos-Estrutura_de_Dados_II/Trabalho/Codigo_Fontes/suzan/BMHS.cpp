//
// Created by mateus on 10/08/2017.
//

#include "BMHS.hpp"

void horspoolSunday(TipoContador *cont, TipoTexto texto, TipoPadrao padrao, size_t tamTexto, size_t tamPadrao){
    size_t i, j, k, vet[NUM_CHARS+1];

    //Pre-Processamento
    cont->tempoPre = clock();

    for(j=0; j<=NUM_CHARS; j++) vet[j] = tamPadrao + 1;
    for(j=1; j<=tamPadrao; j++) vet[padrao[j-1]] = tamPadrao - j + 1;

    cont->tempoPre = clock() - cont->tempoPre;


    //Pesquisa
    cont->tempo = clock();

    i=tamPadrao;

    while(i<=tamTexto){
        k = i;
        j = tamPadrao;
        while(cont->comparacoes++,texto[k-1]==padrao[j-1] && j>0){
            k--;
            j--;
        }
        if(j==0) {
            printf("\nOcorrencia na posicao: %lu", k+1);
            cont->ocorrencias++;
        }
        i+=vet[texto[i]];
        cont->deslocamentos++;
    }

    cont->tempo = clock() - cont->tempo;
}