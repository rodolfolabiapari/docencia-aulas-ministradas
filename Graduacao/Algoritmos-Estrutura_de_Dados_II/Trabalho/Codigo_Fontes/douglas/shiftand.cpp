#include "main.h"

void ShiftAnd(TipoTexto T, long n, TipoPadrao P, long m,int *deslocamento){
	long Masc[MAXCHAR]; // Vetor que armazenará a máscara de todos os caracteres do alfabeto
    long R = 0; // Variável que fará o controle do caminhamento no texto
	long Ri = 1 << (m-1); // Constante que varia de acordo com o tamanho do padrão
	for (int i = 0; i < MAXCHAR; i++ ){
		Masc[i] = 0; // Inicia a máscara de todos os caracteres do alfabeto com 0
    }
    for (int i = 1; i <=m; i++){
        Masc[P[i-1] + 127] |= 1 << (m-i); // Modifica a máscara dos caracteres do padrão de acordo com sua ocorrência no mesmo
    }
	for (int i = 0; i < n; i++){ // Caminha em todo o texto
		R = ((((unsigned long)R)>>1)|Ri)&Masc[T[i] + 127]; // A cada leitura de um caracter do texto é realizado o cálculo do casamento exato
		(*deslocamento)++;
		if ((R & 1)!=0){ // Ao fim da leitura de um caracter e do cálculo de casamento exato se o último caracter da máscara for 1 teve um casamento
			cout<< "Casamento na posicao: " << i +1 << endl;
		}
	}
}