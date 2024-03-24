#include "main.h"

void BoyerMooreHorspool (TipoTexto T, long n, TipoPadrao P, long m, int *comparacoes, int *deslocamentos) {
	long i, j, k, d[MAXCHAR + 1];
    for (j=0; j <= MAXCHAR; j++){ d[j] = m; } // Inicia a tabela de deslocamento de todos os caracteres do alfabeto com o tamanho do padr�o
    for (j=1; j<m; j++){  d[P[j-1]] = m-j; }  // Altera o deslocamento dos caracteres que est�o contidos no padr�o para o deslocamento correto
    i = m; 
	(*comparacoes)++;
    while(i <= n) {
        k = i; // Inicia a v�riavel de caminhamento no texto com o tamanho do padr�o pois o caminhamento � da direita pra esquerda
        j = m; // O mesmo vale pra v�riavel de caminhamento no padr�o.
		(*comparacoes)++;
        while (T[k-1] == P[j-1] && j > 0) { // Enquanto o caracter do padr�o bater com o caracter do texto e ainda tiver caracter do padr�o pra caminhar
			(*comparacoes)++;
            k--; // Caminha pra esquerda no texto
            j--; // Caminha pra esquerda no padr�o
        }
		// Se j chegar a 0 significa que caminhou em todo o padr�o e houve um casamento
        if (j==0){ cout<<"Casamento na posicao: "<< k+5<<endl; }
        (*deslocamentos)++;
		// Se n�o houve casamento o texto � deslocado de acordo com o deslocamento referente ao caracter do texto que n�o bateu com um do padr�o
		i += d[T[i-1]];
    }
}
