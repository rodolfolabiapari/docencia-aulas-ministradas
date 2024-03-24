/*
 * ShiftAnd.h
 *
 *  Created on: Aug 8, 2017
 *      Author: henrique
 */

#ifndef SHIFTAND_H_
#define SHIFTAND_H_

#include<cstdio>
#include<iostream>
#include "csvlogger.h"

#define TAM_ASCII 256

using namespace std;

void ShiftAnd(FILE* texto,char* padrao,int tam){

	int qtdComp=0;
	int text_tam;
	int qtd_casamentos=0;
	FILE* texttemp=texto;
	fseek(texto,0,SEEK_END);
	text_tam = ftell(texto)/sizeof(char);
	rewind(texto);
	unsigned long Masc[TAM_ASCII],R,Ri;
	fprintf(csvfile,"\n");
	char* c = new char;

	for(int i = 0;i<TAM_ASCII;i++)//Inicializando as mascaras.
		Masc[i]=0;

	for(int i = 1;i<=tam;i++)
		Masc[padrao[i-1]+127]|=1<<(tam-i);//Gera uma mascara de bits para cada caracter do padrão de acordo com suas ocorrencias no padrão.

	R=0;
	Ri=1<<(tam-1);

	for(int i = 0; i < text_tam;i++){//Executa até o final do texto;

		qtdComp++;
		*c = (char)fgetc(texto);

		R=(R>>1|Ri)&Masc[(int)*c+127];//Utiliza as operações binarias comparando a mascara inicial Ri, a mascara atual R e o valor da mascara do caracter atualmente sendo lido.
		if((R&1)!=0){//caso o ultimo caracter de R seja diferente de 0, significa que um casamento foi encontrado.
			qtd_casamentos++;
			texttemp=texto;
			fseek(texttemp,-tam,SEEK_CUR);
			if(verbose)
				cout<<"\nCasamento em : "<<i+1-tam<<" -> ";
			fprintf(csvfile,"%d,",i+1-tam);
			if(verbose)
				for(int j = 0;j<tam;j++){
					cout<<(char)fgetc(texttemp);
				}
		}

	}

	if(verbose)
		cout<<"\n"<<qtd_casamentos<<" Casamentos foram encontrados";
	cout<<qtdComp<<" Acessos a disco";
	delete c;

}


#endif /* SHIFTAND_H_ */
