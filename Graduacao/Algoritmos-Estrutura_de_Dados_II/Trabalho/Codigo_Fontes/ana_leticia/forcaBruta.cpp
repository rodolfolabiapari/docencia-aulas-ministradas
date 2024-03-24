#include <iostream>
#include "casamento.h"

using namespace std;

void forcaBruta(TipoTexto texto, long n, TipoPadrao padrao, long m, int *comp){
	long j;
	long k;
	//Contador de ocorrencias
	int ocorrencia = 0;
	// começa do 1 caractere do texto e vai até o ultimo caractere do texto menos o padrão
	for(int i=1; i<=(n-m+1); i++){
        (*comp)++;
		k=i;
		j=1;
		//percorre o texto até achar um casamento, o j percorre o vetor do padrão enquanto o k percorre o texto

		while(texto[k-1]==padrao[j-1] && j<=m){
			(*comp)++;
			j++;
			k++;
		}
		//j percorre o vetor do padrão de tamanho m, se ele for maior que o m, quer dizer q achou um casamento
		(*comp)++;
		if(j>m){
			ocorrencia ++;
			cout<<"Casamento encontrado na posicao: "<<i<<endl;
		}
	}
	cout<<"Numero de ocorrencias: "<<ocorrencia <<endl;
}
