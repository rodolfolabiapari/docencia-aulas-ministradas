#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "casamento.h"

using namespace std;

#define m 64

void shiftAnd(TipoPadrao padrao,TipoTexto texto, long n, long tamPadrao, int* comp){
	
	long M[MAXCHAR];
    long R = 0;
    // constr~ção da mascar de bits
	for (int c = 0; c < tamPadrao; c++ ){
		M[((int) padrao[c])] = 0;
    }

    for (int i = 1; i < m; i++){
        M[((int)padrao[i-1]) + 127] = M[((int)padrao[i-1]) + 127] | 1 <<(tamPadrao- i);
    }

	for (int i = 0; i < n; i++){
		R = ((((unsigned long) R ) >> 1) | (1 << (tamPadrao - i))) & M[((int)texto[i]) + 127];
		(*comp)++;
		if ((R & 1)!=0){
			cout<< "Casamento na posicao: " << i - tamPadrao + 2 << endl;

		}
	}
	
}


