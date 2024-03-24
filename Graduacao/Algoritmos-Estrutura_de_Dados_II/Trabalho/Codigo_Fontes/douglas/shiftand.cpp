#include "main.h"

void ShiftAnd(TipoTexto T, long n, TipoPadrao P, long m,int *deslocamento){
	long Masc[MAXCHAR]; // Vetor que armazenar� a m�scara de todos os caracteres do alfabeto
    long R = 0; // Vari�vel que far� o controle do caminhamento no texto
	long Ri = 1 << (m-1); // Constante que varia de acordo com o tamanho do padr�o
	for (int i = 0; i < MAXCHAR; i++ ){
		Masc[i] = 0; // Inicia a m�scara de todos os caracteres do alfabeto com 0
    }
    for (int i = 1; i <=m; i++){
        Masc[P[i-1] + 127] |= 1 << (m-i); // Modifica a m�scara dos caracteres do padr�o de acordo com sua ocorr�ncia no mesmo
    }
	for (int i = 0; i < n; i++){ // Caminha em todo o texto
		R = ((((unsigned long)R)>>1)|Ri)&Masc[T[i] + 127]; // A cada leitura de um caracter do texto � realizado o c�lculo do casamento exato
		(*deslocamento)++;
		if ((R & 1)!=0){ // Ao fim da leitura de um caracter e do c�lculo de casamento exato se o �ltimo caracter da m�scara for 1 teve um casamento
			cout<< "Casamento na posicao: " << i +1 << endl;
		}
	}
}