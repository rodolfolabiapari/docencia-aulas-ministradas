#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "casamento.h"

using namespace std;

#define m 64

void shiftAnd(TipoPadrao padrao,TipoTexto texto, long tamanhoTexto, long tamPadrao, int* comp){

	long M[MAXCHAR];
    long R = 0;

	for (int i = 0; i < MAXCHAR; i++ ){
		M[i] = 0;
    }

    for (int i = 1; i < m; i++){
        M[((int)padrao[i-1]) + 127] |= 1 <<(tamPadrao- i);
    }

	for (int i = 0; i < tamanhoTexto; i++){
		R = ((((unsigned long) R ) >> 1) | (1 << (tamPadrao - 1))) & M[((int)texto[i]) + 127];
		(*comp)++;
		if ((R & 1)!=0){
			cout<< "Casamento na posicao: " << i - tamPadrao + 2 << endl;

		}
	}

}



