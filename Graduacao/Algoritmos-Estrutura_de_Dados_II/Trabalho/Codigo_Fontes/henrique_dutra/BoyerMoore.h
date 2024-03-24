#ifndef BOYERMOORE_H_
#define BOYERMOORE_H_
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "csvlogger.h"
#define TAM_ASCII 256

using namespace std;

void Ocorrencia( char *str, int size,int tabelaDesloc[TAM_ASCII]){//Criação da tabela de deslocamento com base na ocorrencia dentro do padrão
	for (int i = 0; i < TAM_ASCII; i++){
		tabelaDesloc[i] = -1;
	}
	int temp;
	for (int i = 0; i < size; i++){
		temp = int(str[i]);
		tabelaDesloc[temp] = i;
	}
}

void BM(FILE* texto,char* padrao,int tam){
	int qtdComp=0;//inicio da declaração de variaveis.
	int qtd_ocorrencias = 0;
	rewind(texto);
	FILE* tempFile = texto;
	char* tempChar;
	tempChar = new char;
	fseek(texto,0,SEEK_END);
	int n = ftell(texto)/sizeof(char);
	rewind(texto);
	int d = 0; //deslocamento
	int tabelaDesloc[TAM_ASCII];//fim da declaração de variaveis
	Ocorrencia(padrao, tam, tabelaDesloc);//gera tabela de deslocamento
	char* c = new char;
	fprintf(csvfile,"\n");
	while(d <= (n - tam)){//executa até o final do texto.
		int j = tam-1;
		fseek(texto,d+tam-1,SEEK_SET);
		*c = (char)fgetc(texto);
		qtdComp++;
		while(j >= 0 && padrao[j] == *c){//casa os caracteres do texto com o padrao a partir do ultimo caracter do padrao.
			fseek(texto,-2,SEEK_CUR);//volta o ponteiro de leitura do texto para a proxima leitura ser feita.
			*c = (char)fgetc(texto);
			qtdComp++;
			j--;
		}
		if (j < 0){//se for menor que 0, foi encontrada uma ocorrencia.
			if(verbose)
				printf("\nCasamento em : %d -> ", d);
			fprintf(csvfile,"%d,",d);
			qtd_ocorrencias++;
			FILE* tempPrint = texto;
			if(verbose)
				for(int k = 0; k< tam;k++)
					cout<<(char)fgetc(tempPrint);
			if(d+tam<n){
				fseek(tempFile,d+tam,SEEK_SET);
				*tempChar = fgetc(tempFile);
				qtdComp++;
				d+=tam-tabelaDesloc[(int)*tempChar];
			}
		}
		else{//caso contrario, irá calcular o deslocamento e prosseguirá a execução.
			fseek(tempFile,d+j,SEEK_SET);
			*tempChar = fgetc(tempFile);
			qtdComp++;
			if(j-tabelaDesloc[(int)*tempChar]>1){
				d+=j - tabelaDesloc[(int)*tempChar];
			}
			else{
				d+=1;
			}
		}
	}
	delete tempChar;
	delete c;
	if(verbose)
	cout<<"\n"<<qtd_ocorrencias<<" Casamentos foram encontrados";
	cout<<"\n"<<qtdComp<<" Acessos ao disco";
}



#endif /* BOYERMOORE_H_ */
