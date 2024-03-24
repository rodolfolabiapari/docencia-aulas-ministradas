#include "ShiftAnd.hpp"
#include <stdio.h>

using namespace std;

void shiftAnd(TipoContador* cont, TipoTexto texto, TipoPadrao padrao, size_t tamTexto, size_t tamPadrao){
    long Masc[NUM_CHARS]; //Armazena a mascara de bits
    long R=0;

    //Pre-Processamento
    cont->tempoPre = clock();

    //Inicia todos os valores da mascara de bits com 0
    for(size_t i=0; i<NUM_CHARS; i++)
        Masc[i] = 0;

    for(size_t i=0; i<=tamPadrao; i++){
        Masc[padrao[i-1] + 127] |= 1 << (tamPadrao-i);
        cont->deslocamentosPre++;
    }

    cont->tempoPre = clock() - cont->tempoPre;

    //Pesquisa
    cont->tempo = clock();

    for(size_t i=0; i<tamTexto; i++){

        R = ((((unsigned long)R) >> 1) | (1 << (tamPadrao - 1))) & Masc[texto[i] + 127];

        if((R & 1) != 0) {
            cont->ocorrencias++;
            printf("\nOcorrencia na posicao: %lu", i-tamPadrao+2);
        }
    }

    cont->tempo = clock() - cont->tempo;
}