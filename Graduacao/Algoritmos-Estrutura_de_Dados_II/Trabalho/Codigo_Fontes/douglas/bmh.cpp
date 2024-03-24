#include "main.h"

void BoyerMooreHorspool (TipoTexto T, long n, TipoPadrao P, long m, int *comparacoes, int *deslocamentos) {
	long i, j, k, d[MAXCHAR + 1];
    for (j=0; j <= MAXCHAR; j++){ d[j] = m; } // Inicia a tabela de deslocamento de todos os caracteres do alfabeto com o tamanho do padrão
    for (j=1; j<m; j++){  d[P[j-1]] = m-j; }  // Altera o deslocamento dos caracteres que estão contidos no padrão para o deslocamento correto
    i = m; 
	(*comparacoes)++;
    while(i <= n) {
        k = i; // Inicia a váriavel de caminhamento no texto com o tamanho do padrão pois o caminhamento é da direita pra esquerda
        j = m; // O mesmo vale pra váriavel de caminhamento no padrão.
		(*comparacoes)++;
        while (T[k-1] == P[j-1] && j > 0) { // Enquanto o caracter do padrão bater com o caracter do texto e ainda tiver caracter do padrão pra caminhar
			(*comparacoes)++;
            k--; // Caminha pra esquerda no texto
            j--; // Caminha pra esquerda no padrão
        }
		// Se j chegar a 0 significa que caminhou em todo o padrão e houve um casamento
        if (j==0){ cout<<"Casamento na posicao: "<< k+5<<endl; }
        (*deslocamentos)++;
		// Se não houve casamento o texto é deslocado de acordo com o deslocamento referente ao caracter do texto que não bateu com um do padrão
		i += d[T[i-1]];
    }
}
