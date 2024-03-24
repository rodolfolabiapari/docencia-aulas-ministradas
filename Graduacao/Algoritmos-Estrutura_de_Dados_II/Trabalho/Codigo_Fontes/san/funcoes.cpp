#include "funcoes.h"
#include "comparacao.h"
#include <iostream>

using namespace std;

void ForcaBruta (TipoTexto T, long n, TipoPadrao P, long m){
    iniciaTempo();
    long i, j, k;
    for (i=1; i<=(n-m+1); i++){ //varre o texto
        k=i; 
        j=1;
        incrementaComparacoes();
        while (T[k-1]==P[j-1] && j<=m){ // compara os caracteres do texto com o padrão até o fim do mesmo ou até que ocorra colisão
            j++;
            k++;
            incrementaComparacoes();
        }
        if (j>m){
            cout << "Casamento na posicao: " << i <<endl;            
        }
        incrementaDeslocamentos();         
    }
    fechaTempo();
}

void BMH (TipoTexto T, long n, TipoPadrao P, long m){
    iniciaTempo();
    long i, j, k, d[MAXCHAR + 1];
    //preprocessamento
    for (j = 0; j <= MAXCHAR; j++){// Cria a tabela para o alfabeto
        d[j] = m;
    }
    for (j = 1; j < m; j++) { //Atualiza a tabela criada para o padrão
        d[P[j - 1]] = m - j;
    }
    i = m;
    // Pesquisa
    while (i <= n){
        k = i;
        j = m;
        incrementaComparacoes();
        while (T[k - 1] == P[j - 1] && j > 0) {
            k--;
            j--;
            incrementaComparacoes();
        }
        if (j == 0){
            cout << "Casamento na posicao: " << k + 1 <<endl;
        }
        i += d[T[i - 1]];  // Calcula o deslocamento no texto em relação ao último caractere do texto que se encontra na mesma posição do último caractere do padrão
        incrementaDeslocamentos();
    }
    fechaTempo();
}

void BMHS (TipoTexto T, long n, TipoPadrao P, long m){
	iniciaTempo();
	long i, j, k, d[MAXCHAR + 1];
	for (j = 0; j <= MAXCHAR; j++) // Cria a tabela para o alfabeto
		d[j] = m + 1;
	for (j = 1; j <= m; j++) // Atualiza a tabela criada para o padrão
		d[P[j - 1]] = m - j + 1;
	i = m;
	// Pesquisa
	while (i <= n){
		k = i;
		j = m;
		incrementaComparacoes();
		while (T[k-1] == P[j - 1] && j > 0){
			k--;
			j--;
		}
		if ( j == 0)
			cout << "Casamento no posicao: " << k + 1 << endl;
		i += d[T[i]];
		incrementaDeslocamentos();
	}
	fechaTempo();
}

void ShiftAnd(TipoTexto T, long n, TipoPadrao P, long m){
    iniciaTempo();
    unsigned long Masc[MAXCHAR], i, R = 0;
    
    //preprocessamento das mascaras do texto e do padrão
    for (i = 0; i < MAXCHAR; i++)
        Masc[i] = 0;
    for (i = 1; i <= m; i++)
        Masc[P[i - 1] + 127] |= 1 << (m - i);
    //pesquisa
    for (i = 0; i < n; i++) {
        R = ((((unsigned long) R) >> 1) | (1 << (m - 1))) & Masc[T[i] + 127];
        incrementaComparacoes();
        incrementaDeslocamentos();
        if ((R & 1) != 0){
            cout << "Casamento na posicao: " << i - m + 2<<endl;
        }
    }
    fechaTempo();
}

//Boyer Moore com heuristica de casamento
void BMC(TipoTexto T, int n, TipoPadrao P, int m) {
    iniciaTempo();
    int i, j, bmGs[MAXTAMPADRAO];
    preBmGs(P, m, bmGs); //Preprocessamento
    j = 0;
    //pesquisa
    while (j <= n - m) {
        for (i = m - 1; i >= 0 && P[i] == T[i + j]; --i) {
            incrementaComparacoes();
        }
        if (i < 0) {
            cout << "Casamento na posicao: " << j + 1 << endl;
            j += bmGs[0];
        } else{
            j += bmGs[i];
        }
        incrementaDeslocamentos();
    }
    fechaTempo();
}

void preBmGs(char *x, int m, int bmGs[]) {
    int i, j, suff[MAXTAMPADRAO];
    suffixes(x, m, suff);
    for (i = 0; i < m; ++i){
        bmGs[i] = m;
    }
    j = 0;
    for (i = m-1; i >= 0; --i)
        if (suff[i] == i+1){
            for (; j < m-1-i; ++j)
                if (bmGs[j] == m) {
                    incrementaComparacoes();
                    bmGs[j] = m-1-i;    
                }
            incrementaComparacoes();
        }
    for (i = 0; i <= m-2; ++i){
        bmGs[m-1-suff[i]] = m-1-i;
    }
}

void suffixes(char *x, int m, int *suff) {
    int f, g, i;
    suff[m-1] = m;
    g = m-1;
    for (i = m - 2; i >= 0; --i) {
        if (i > g && suff[i+m-1-f] < i-g) {
            incrementaComparacoes();
            suff[i] = suff[i+m-1-f];        
        } else {
            if (i < g) {
                incrementaComparacoes();
                g = i;
            }
            f = i;
            while (g >= 0 && x[g] == x[g+m-1-f]){
                --g;
            }
            suff[i] = f-g;
        }
    }
}