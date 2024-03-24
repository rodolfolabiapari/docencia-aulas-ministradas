#include <iostream>
#include "casamento.h"

using namespace std;
void BMH(TipoTexto T, long n, TipoPadrao P, long m, int* comp, int* desloc) {
	
	/*Pre-processamento para se obter a tabela de deslocamentos */
   
   long i, j, k, d[MAXCHAR + 1];
    for (j=0; j <= MAXCHAR; j++)
        d[j] = m;
    for (j=1; j<m; j++)
        d[P[j-1]] = m-j;
    i = m;
    
	//Pesquisa
    while(i <= n) {
        k = i;
        j = m;
        while (T[k-1] == P[j-1] && j > 0) {
			(*comp)++;
            k--;
            j--;
        }
		
		
        if (j==0){
            (*comp)++;
            cout<<"Casamento na posicao: "<< k+1<<endl;           
        } 

		//Faz o deslocamento
        i += d[T[i-1]];
		(*desloc)++;
        (*comp)++;
    }

	
}


