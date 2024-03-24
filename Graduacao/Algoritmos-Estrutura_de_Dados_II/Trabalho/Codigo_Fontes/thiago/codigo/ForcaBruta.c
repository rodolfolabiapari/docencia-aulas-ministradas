#include "ForcaBruta.h"               

int ForcaBruta(TipoTexto texto, long tamTexto, TipoPadrao padrao, long tamPadrao, long *comp, long *desloc){
    long i, j, k, achou = 0;
    for(i = 1; i <= (tamTexto - tamPadrao + 1); i++){ // desloca o ponteiro para varrer o texto e procurar subcadeias idênticas ao padrão
        (*desloc)++; // variavel que conta o deslocamennto do ponteiro 
        k = i;
        j = 1;
        (*comp)++;
        while(texto[k-1] == padrao[j-1] && j <= tamPadrao){ // pesquisa o padrão P a partir da K-ésima posição do texto TipoTexto
            (*comp)++;
            (*desloc)++;
            j++;
            k++;
        }
        if(j > tamPadrao){ //uma ocorrencia exata do padrão foi identificada no texto, e a posição dessa ocorrência é impressa na tela 
            printf(" - - Casamento na posicao %ld\n", i);
            achou = 1;
        }
    }
    return achou;
}