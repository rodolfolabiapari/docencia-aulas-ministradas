#include "BMHS.h"

int BMHS(TipoTexto texto, long tamTexto, TipoPadrao padrao, long tamPadrao, long *comp, long *desloc){
    long i, j, k, d[MAXCHAR + 1], achou = 0;
    for(j = 0; j <= MAXCHAR; j++){				//Pré-processamento para se obter a tabela de deslocamento
        d[j] = tamPadrao + 1;
    }
    for(j = 1; j <= tamPadrao; j++){
        d[padrao[j-1]] = tamPadrao - j +1;
    }
    i = tamPadrao;
    while(i <= tamTexto){
        k = i;
        j = tamPadrao;
        
        while(texto[k-1] == padrao[j-1] && j > 0){  //Pesquisa por um sufixo do texto (janela) que casa com um sufixo do padrão
            (*comp)++;
            k--;
            j--;
        }
        if(j == 0){
            printf(" - - Casamento na posicao %ld\n", k + 1);
            achou = 1;
        }
        (*desloc)+= i;
        i += d[texto[i]]; //Deslocamento da janela de acordo com o valor da tabela de deslocamentos 
						  //relativo ao caractere que está na i-ésima-1 posição do texto
    }
    return achou;
}
