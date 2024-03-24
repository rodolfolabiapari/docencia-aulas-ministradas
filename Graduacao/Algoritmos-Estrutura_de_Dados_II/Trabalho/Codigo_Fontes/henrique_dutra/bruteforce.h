#ifndef BRUTEFORCE_H_
#define BRUTEFORCE_H_

using namespace std;


#include <iostream>
#include <cstdio>
#include "csvlogger.h"

void bruteForce(FILE* texto,char* padrao,int tamanho){
	char* c = new char;
	int qtd_comp=0;
	int read;
	long long pos=0;
	int i=0;
	FILE* temptexto;
	int ocorrencias=0;
	qtd_comp++;
	pos++;
	fprintf(csvfile,"\n");
	while(read!=-1){//Executa até o final do texto.
		for(i = 0; i<tamanho && read!=-1;i++){//compara caracter a caracter do texto com cada caracter do padrão, até ocorrer uma colisão.
			if(padrao[i]==*c){
				qtd_comp++;
				pos++;
			}
			else{
				i=-1;//retorna o padrão para o inicio e avança no texto.
				qtd_comp++;
				pos++;
			}
			read = fscanf(texto,"%c",c);
		}
		read = fscanf(texto,"%c",c);
		qtd_comp++;
		if(read!=-1){//caso o programa chegue a essa linha antes do final do arquivo, um casamento ocorreu.
		temptexto = texto;
		fseek(temptexto,-tamanho-2,SEEK_CUR);
		if(verbose)
			cout<<"Casamento em : "<<pos-tamanho<<" -> ";
		if(verbose)
			for(int k = 0;k<tamanho;k++){
				cout<<(char)fgetc(temptexto);
			}
		cout<<"\n";
		fprintf(csvfile,"%llu,",pos-tamanho);
		ocorrencias++;
		}
		pos++;
	}
	cout<<"\n"<<ocorrencias<<" Casamentos foram encontrados\n";
	cout<<"\n"<<qtd_comp<<" Leituras realizadas";
	delete c;
}


#endif /* BRUTEFORCE_H_ */
