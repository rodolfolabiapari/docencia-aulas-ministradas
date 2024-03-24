#include "main.h"

void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m,int *comparacoes,int *deslocamentos){
	long i,j,k;
	for(i=1;i<=(n-m+1);i++){ // Percorre todo o texto
		(*deslocamentos)++;
		(*comparacoes)++;
		k=i;
		j=1;
		while(T[k-1]==P[j-1]&& j<=m){ // Enquanto o caracter do padrão bater com o caracter do texto e ainda tiver caracter do padrão pra caminhar
			(*comparacoes)++;
			j++; // Caminha no padrão
			k++; // Caminha no texto
		}
		(*comparacoes)++;
		if(j>m){ // Se chegou a caminhar em todo o padrão houve um casamento
			cout << "Casamento na posicao: " << i + 4 << endl;
		}
	}
}