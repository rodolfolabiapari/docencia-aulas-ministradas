#include "casamento.h"


void booyerMoore(TipoTexto T, long n, TipoPadrao P, long m, int* comp, int* desloc) {
    
    long i, j, k;
    
    while(i <= n) {
        k = i;
        j = m;
        
        //busca o sufixo
        while(T[k-1] == P[j-1] && j > 0) {
            
            (*comp)++;
            k--;
            j--;
        }
        
        //a comparação que fez o programa sair do while precisa ser contabilizada
        (*comp)++;
        
        //o sufixo casado é exatamente o padrão e deve-se deslocar apenas 1 caracter
        if (j==0){ 
            cout << "Casamento na posição: " << k + 1 << endl;
            i++;
            (*desloc)++;
        }else {
            
            //desloca a janela até que o caracter que causou a colisão case com um caracter do padrão
            while(T[k-1] != P[j-1] && j > 0){
                j--;
                i++;
                (*desloc)++;
                (*comp)++;
            }
            
            //a comparação que fez o programa sair do while precisa ser contabilizada
            (*comp)++;
        }
    }
}