#include <stdio.h>
#include "ForcaBruta.hpp"

void forcaBruta(TipoContador* cont, TipoTexto texto, TipoPadrao padrao, size_t tamTexto, size_t tamPadrao){
    size_t j, k;

    cont->tempo = clock();
    
    /* Percorre toda a string ate tamTexto-tamPadrao+1, o que corresponde *
     * ao caractere inical de cada subcadeia possivel no texto            */
    for (size_t i = 1; i<=(tamTexto-tamPadrao+1); i++){
        j=1; //j sempre inicia com o indice do segundo caractere do padrao
        k=i; //k sempre inicia com o indice do segundo caractere da subcadeia do texto

        /* Compara caractere por caractere da subcadeia atual com o padrao *
         * parando quando o caractere e diferente ou ao atingir o ultimo   * 
         * caractere (j=tamPadrao)                                         */
        cont->comparacoes++;
        while(texto[k-1] == padrao[j-1] && j<=tamPadrao){
            cont->comparacoes++;
            j++;
            k++;
        }
        
        /* Comoe j inicia com 1 e vai sendo incrementado a cada caractere que do  *
         * padrao que casa com o da subcadeia, se ao final j for maior que o      *
         * tamanho do padrao, isso indica que houve uma ocorrencia                */
        if (j > tamPadrao){
            cont->ocorrencias++;
            printf("\nOcorrencia na posicao: %lu", i);
        }
    }

    cont->tempo = clock() - cont->tempo;
}