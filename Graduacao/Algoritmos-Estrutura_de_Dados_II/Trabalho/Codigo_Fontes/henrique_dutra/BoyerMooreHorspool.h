/*
 * BoyerMooreHorspool.h
 *
 *  Created on: Aug 8, 2017
 *      Author: henrique
 */

#ifndef BOYERMOOREHORSPOOL_H_
#define BOYERMOOREHORSPOOL_H_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "csvlogger.h"
#define TAM_ASCII 256

using namespace std;

void OcorrenciaBMH( char *padrao, int size,int tabelaDesloc[TAM_ASCII])//gera a tabela de deslocamento de acordo com o ultimo caracter do padrão
{
	for (int i = 0; i < TAM_ASCII; i++){
		tabelaDesloc[i] = size;
	}
	int temp;
	for (int i = 1; i < size; i++){
		temp = int(padrao[i-1]);
		tabelaDesloc[temp] = size-i;
	}
}
void BMH(FILE* texto,char* padrao,int tam){//Muitas linhas são similares ao metodo BM, a maior alteração foi na tabela de deslocamento.
	int qtdComp=0;
	int qtd_ocorrencias = 0;
	rewind(texto);
	FILE* tempFile = texto;
	char* tempChar;
	tempChar = new char;
	int m = tam;
	fseek(texto,0,SEEK_END);
	int n = ftell(texto)/sizeof(char);
	rewind(texto);
	int d = tam; //deslocamento
	int tabelaDesloc[TAM_ASCII];
	OcorrenciaBMH(padrao, tam, tabelaDesloc);
	char* c = new char;
	fprintf(csvfile,"\n");
	while(d <= n){
		int j = m-1;
		fseek(texto,d+m-1,SEEK_SET);
		*c = (char)fgetc(texto);
		qtdComp++;
		while(j > 0 && padrao[j-1] == *c){
			fseek(texto,-2,SEEK_CUR);
			qtdComp++;
			*c = (char)fgetc(texto);
			j--;
		}
		if (j <= 0){
			if(verbose)
				printf("\nCasamento em : %d -> ", d+1);
			fprintf(csvfile,"%d,",d+1);
			qtd_ocorrencias++;
			FILE* tempPrint = texto;
			if(verbose)
				for(int k = 0; k< tam;k++)
					cout<<(char)fgetc(tempPrint);
			if(d+m<n){
				fseek(tempFile,d+m-1,SEEK_SET);
				*tempChar = fgetc(tempFile);
				qtdComp++;
				d+=tabelaDesloc[(int)*tempChar];
			}
		}
		else{
			fseek(tempFile,d+m,SEEK_SET);
			*tempChar = fgetc(tempFile);
			qtdComp++;
			if(tabelaDesloc[(int)*tempChar]-1>1){
				d+=tabelaDesloc[(int)*tempChar]-1;
			}
			else{
				d+=1;
			}

		}
	}
	delete tempChar;
	delete c;
	if(verbose)
		cout<<"\n"<<qtd_ocorrencias<<" casamentos foram encontrados";
	cout<<"\n"<<qtdComp<<" Acessos ao disco";
}


#endif /* BOYERMOOREHORSPOOL_H_ */
