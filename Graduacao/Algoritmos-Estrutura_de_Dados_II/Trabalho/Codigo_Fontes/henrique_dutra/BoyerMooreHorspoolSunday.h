/*
 * BoyerMooreHorspoolSunday.h
 *
 *  Created on: Aug 8, 2017
 *      Author: henrique
 */

#ifndef BOYERMOOREHORSPOOLSUNDAY_H_
#define BOYERMOOREHORSPOOLSUNDAY_H_
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "csvlogger.h"
#define TAM_ASCII 256

using namespace std;

void OcorrenciaBMHS( char *padrao, int size,int tabelaDesloc[TAM_ASCII])//Gera a tabela de deslocamento a partir do ultimo caracter do padrão +1, gerando um deslocamento extra.
{
	for (int i = 0; i < TAM_ASCII; i++){
		tabelaDesloc[i] = size-1;
	}
	int temp;
	for (int i = 1; i < size; i++){
		temp = int(padrao[i-1]);
		tabelaDesloc[temp] = size-i+1;
	}
}
void BMHS(FILE* texto,char* padrao,int tam){//Maior mudança foi na geração da tabela de deslocamento, muito similar ao metodo BM
	int qtdComp = 0;
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

	OcorrenciaBMHS(padrao, tam, tabelaDesloc);
	char* c = new char;
	fprintf(csvfile,"\n");
	while(d <= n){
		int j = m;
		fseek(texto,d+m-1,SEEK_SET);
		qtdComp++;
		*c = (char)fgetc(texto);
		while(j > 0 && (padrao[j-1]==*c)){
			fseek(texto,-2,SEEK_CUR);
			qtdComp++;
			*c = (char)fgetc(texto);
			j--;
		}

		if (j == 0){
			if(verbose)
				printf("\nCasamento em : %d -> ", d);
			fprintf(csvfile,"%d,",d);
			qtd_ocorrencias++;
			FILE* tempPrint = texto;
			if(verbose)
				for(int k = 0; k< tam;k++)
					cout<<(char)fgetc(tempPrint);
			if(d+m<n){
				fseek(tempFile,d+m,SEEK_SET);
				qtdComp++;
				*tempChar = fgetc(tempFile);
				d+=tabelaDesloc[(int)*tempChar];
			}
		}
		else{
			fseek(tempFile,d+m,SEEK_SET);
			*tempChar = fgetc(tempFile);
			qtdComp++;
			if(tabelaDesloc[(int)*tempChar]>1){
				d+=tabelaDesloc[(int)*tempChar];
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
		cout<<"\n"<<qtdComp<<" Acessos a Disco";
}



#endif /* BOYERMOOREHORSPOOLSUNDAY_H_ */
