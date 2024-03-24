#include "main.h"

void BoyerMoore(TipoTexto T, long n, TipoPadrao P, long m,int *comparacoes,int *deslocamentos) {
    long i=m, j, k;
	(*comparacoes)++;
    while(i <= n) { // Caminha em todo o texto
        k = i; // Inicia a v�riavel de caminhamento no texto com o tamanho do padr�o pois o caminhamento � da direita pra esquerda
        j = m; // O mesmo vale pra v�riavel de caminhamento no padr�o.
		(*comparacoes)++;
        while(T[k-1] == P[j-1] && j > 0) { // Enquanto o caracter do padr�o bater com o caracter do texto e ainda tiver caracter do padr�o pra caminhar
			(*comparacoes)++;
            k--; // Caminha pra esquerda no texto
            j--; // Caminha pra esquerda no padr�o
        }
        if (j==0){ // Se j chegar a 0 significa que caminhou em todo o padr�o e houve um casamento
			(*deslocamentos)++;
            cout << "Casamento na posicao: " << k + 5 << endl;
            i++; // Desloca o texto uma posi��o
        }else { // Se n�o houver casamento 
			(*comparacoes)++;
            while(T[k-1] != P[j-1] && j > 0){ // Procura o caracter do texto que n�o correspondeu com um do padr�o dentro do resto do padr�o
				(*comparacoes)++;
                j--; // Caminha no padr�o pra esquerda
                i++; // Desloca o texto uma posi��o
            }
			(*deslocamentos)++;
        }
    }
}