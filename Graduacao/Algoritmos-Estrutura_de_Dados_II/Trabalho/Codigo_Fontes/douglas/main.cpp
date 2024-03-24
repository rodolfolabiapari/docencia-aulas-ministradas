#include "main.h"

using namespace std;

int main(int argc, char *argv[]){
	
	setlocale(LC_ALL, "Portuguese");

	if((argc==4)||(argc==5)){
		
		int Metodo=atoi(argv[1]); // Recebe o m�todo escolhido pelo usu�rio
		const char* TipoArquivo=argv[2]; // Recebe o nome do arquivo escolhido pelo usu�rio
		const char* Padrao1=argv[3]; // Recebe o padr�o a ser procurado
		
		// Inicia as vari�veis de comparacao, deslocamento e tempo
		int comparacoes = 0;
		int deslocamentos = 0;
		clock_t inicio,fim;
		
		FILE* arq; // Ponteiro pro arquivo do texto f�sico

		if((arq=fopen(TipoArquivo,"r"))== NULL){ 
        	cout << "N�o foi poss�vel abrir o arquivo" << endl;
    	}
    	else{

    		TipoTexto texto; 
	        TipoPadrao padrao;
	        
	        strcpy(padrao, Padrao1); // L� o padr�o e armazena na v�riavel padr�o
	        int tamanhoPadrao = strlen(padrao); // Recebe o tamanho do padr�o
	        
	        fgets(texto, 2000000, arq); // L� o arquivo e armazena na vari�vel texto
	        int tamanhoTexto = strlen(texto); // Recebe o tamanho do texto
			
			if(Metodo==1){
				inicio = clock(); // Inicia a contagem do tempo de processamento
				ForcaBruta(texto, tamanhoTexto, padrao, tamanhoPadrao,&comparacoes,&deslocamentos);
				fim = clock(); // Finaliza a contagem do tempo de processamento
			}
			else if(Metodo==2){
				inicio = clock();
				BoyerMoore(texto, tamanhoTexto, padrao, tamanhoPadrao,&comparacoes,&deslocamentos);
				fim = clock();
			}
			else if(Metodo==3){
				inicio = clock();
				BoyerMooreHorspool(texto, tamanhoTexto, padrao, tamanhoPadrao,&comparacoes,&deslocamentos);
				fim = clock();
			}	
			else if(Metodo==4){
				inicio = clock();
				BoyerMooreHorspoolSunday(texto, tamanhoTexto, padrao, tamanhoPadrao,&comparacoes,&deslocamentos);
				fim = clock();
			}
			else if(Metodo==5){
				inicio = clock();
				ShiftAnd(texto, tamanhoTexto, padrao, tamanhoPadrao,&deslocamentos);
				fim = clock();
			}
			else{
				cout << "Erro com os par�metros na chamada de fun��o.\n"; 
			}
			if(argc==5){ // Se o usu�rio inserir 5 argumentos na linha de comando as an�lises ser�o mostradas
				cout<<endl<<"An�lise:"<<endl;
				cout << "Compara��es  : " << comparacoes << endl;
                cout << "Deslocamentos: " << deslocamentos << endl;
                cout << "Tempo        : " << ((double) fim - inicio) / CLOCKS_PER_SEC<<" segundos.";cout<<endl;
			}
    	}
	}
	else{
		cout << "Erro com os par�metros na chamada de fun��o.\n";		
	}
	return 0;
}