#include <iostream>
#include <cstdio>
#include "bruteforce.h"
#include "BoyerMoore.h"
#include "BoyerMooreHorspool.h"
#include "BoyerMooreHorspoolSunday.h"
#include "ShiftAnd.h"
#include "csvlogger.h"

using namespace std;

int main(int argc, char* argv[]) {


	if(argc<4){//verifica se os argumentos estao em quantidade correta.
		cout<<"Quantidade de argumentos invalida";
	}
	else if(argc==5){
		verbose = (argv[4][0]=='-'&& argv[4][1]=='P');
	}

	FILE* arquivo = fopen(argv[2],"rw");//abre arquivo.
	fgetc(arquivo);
	int tam=0;
	while(argv[3][tam]!=0){//conta tamanho do padrao.
		tam++;
	}

	csvfile = fopen("log.csv","w");//arquivo output de ocorrencias.

	switch(*argv[1]-48){//selecao de metodo.
	case 1:
		bruteForce(arquivo,argv[3],tam);//força bruta
		break;
	case 2:
		BM(arquivo,argv[3],tam);//BoyerMoore
		break;

	case 3:
		BMH(arquivo,argv[3],tam);//BoyerMooreHorspool
		break;

	case 4:
		BMHS(arquivo,argv[3],tam);//BoyerMooreHorspoolSunday.
		break;

	case 5:
		ShiftAnd(arquivo,argv[3],tam);//ShiftAndExato.
		break;
	}
	return 0;
}
