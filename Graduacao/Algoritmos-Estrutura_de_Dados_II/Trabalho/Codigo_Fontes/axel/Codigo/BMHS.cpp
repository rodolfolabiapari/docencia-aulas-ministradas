#include "casamento.h"

void BMHS (TipoTexto T, long n, TipoPadrao P, long m, int* comp, int* desloc) {
    
     /*Pre-processamento para se obter a tabela de deslocamentos */
     int i,j,k,d[MAXCHAR+1];

     
     for(j=0; j<MAXCHAR; j++) d[j] = m + 1;

     for(j=0; j<m; j++) d[P[j]]= m - j ;
     
     i = m - 1;
 
     /*Pesquisa*/
     while (i<n) { 
         
         k = i ;
         j = m - 1;

         while((j>=0) && (T[k] == P[j])){
                 (*comp)++;
                 j--; 
                 k--; 
         }
         
         (*comp)++;
	     if ( j < 0)
            cout<<"Casamento na posicao : "<<k+1<<endl;

	     i = i + d[T[i+1]];

	     (*desloc)++;
	 }
}