#include "casamento.h"

using namespace std;

void forcaBruta(TipoTexto Texto, long tamTexto, TipoPadrao Padrao, long tamPadr, int *contComp){
	long j;
	long k;
	//Contador de ocorrencias
	int contOcorrencias=0;
	//Iniciando em 1 e indo ate o tamanho do texto menos tamanho do padrao +1
	for(int i=1; i<=(tamTexto-tamPadr+1); i++){
        (*contComp)++;
		k=i;
		j=1;
		//caminha pelo texto a partir de i ate enquanto a ocorrencia bater e atingir tamPadr
		while(Texto[k-1]==Padrao[j-1] && j<=tamPadr){
			(*contComp)++;
			j++;
			k++;
		}
		//Se J for maior que o tamPadr, achou!
		(*contComp)++;
		if(j>tamPadr){
			contOcorrencias++;
			cout<<"Casamento encontrado na posicao: "<<i<<endl;
		}
	}
	cout<<"Numero de ocorrencias: "<<contOcorrencias<<endl;
}
