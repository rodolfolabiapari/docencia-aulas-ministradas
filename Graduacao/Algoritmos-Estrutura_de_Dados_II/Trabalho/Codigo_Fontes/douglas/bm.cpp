#include "main.h"

void BoyerMoore(TipoTexto T, long n, TipoPadrao P, long m,int *comparacoes,int *deslocamentos) {
    long i=m, j, k;
	(*comparacoes)++;
    while(i <= n) { // Caminha em todo o texto
        k = i; // Inicia a váriavel de caminhamento no texto com o tamanho do padrão pois o caminhamento é da direita pra esquerda
        j = m; // O mesmo vale pra váriavel de caminhamento no padrão.
		(*comparacoes)++;
        while(T[k-1] == P[j-1] && j > 0) { // Enquanto o caracter do padrão bater com o caracter do texto e ainda tiver caracter do padrão pra caminhar
			(*comparacoes)++;
            k--; // Caminha pra esquerda no texto
            j--; // Caminha pra esquerda no padrão
        }
        if (j==0){ // Se j chegar a 0 significa que caminhou em todo o padrão e houve um casamento
			(*deslocamentos)++;
            cout << "Casamento na posicao: " << k + 5 << endl;
            i++; // Desloca o texto uma posição
        }else { // Se não houver casamento 
			(*comparacoes)++;
            while(T[k-1] != P[j-1] && j > 0){ // Procura o caracter do texto que não correspondeu com um do padrão dentro do resto do padrão
				(*comparacoes)++;
                j--; // Caminha no padrão pra esquerda
                i++; // Desloca o texto uma posição
            }
			(*deslocamentos)++;
        }
    }
}