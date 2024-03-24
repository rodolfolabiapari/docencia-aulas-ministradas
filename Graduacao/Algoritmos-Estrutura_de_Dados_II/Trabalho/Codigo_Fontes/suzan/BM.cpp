#include <string.h>
#include <stdio.h>
#include "BM.hpp"


/*! Funcao de busca que utiliza a heuristica de ocorrencia. */
void boyerMoore(TipoContador *cont,  TipoTexto texto, TipoPadrao padrao, size_t tamTexto, size_t tamPadrao) {
    int vet[NUM_CHARS];

    pre(padrao, tamPadrao, vet,cont);

    cont->tempo = clock();

    long d = 0;  //! d é o deslocamento do padrao em relacao ao texto.
    while(d <= (tamTexto - tamPadrao)) {

        long j = tamPadrao - 1;

        //! Reduz o indice j do padrao enquanto os uma cadeia e o texto casam em um deslocamento d.
        while(cont->comparacoes++, j >= 0 && padrao[j] == texto[d + j]) {
            j--;
        }

        //! Se o padrao esta presente no deslocamento atual, entao o indice j sera -1 ao termino do loop acima
        if (j < 0) {
            printf("\nOcorrencia na posicao: %lu", d+1);
            cont->ocorrencias++;
            /*!
             * Desloca o padrao para que o proximo caractere no texto seja
             * alinhado com a ultima ocorrencia do mesmo no padrao.
             * A condicao d + tamPadrao < tamTexto é necessaria para
             * o caso em que o padrao ocorre no fim do texto.
             **/
            d += (d + tamPadrao < tamTexto)? tamPadrao - vet[texto[d + tamPadrao]] : 1;
            cont->deslocamentos++;
        }

            /*!
             * Desloca o padrao para que o caractere que colidiu no texto
             * seja alinhado com a ultima ocorrencia do mesmo no padrao.
             * A funcao max é usada para garantir um valor positivo para
             * o deslocamento. O valor poderia ser negativo caso a ultima
             * ocorrencia de colisao no padrao estivesse do lado direito
             * do caractere atual.
             **/
        else {
            d += max(1, j - vet[texto[d + j]]);
            cont->deslocamentos++;
        }
    }

    cont->tempo = clock() - cont->tempo;
}