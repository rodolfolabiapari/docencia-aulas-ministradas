#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <iomanip> 
#include "casamento.h"

using namespace std;

int main(int argc, char* argv[]){
    
    int metodo = atoi(argv[1]);
    int arq = atoi(argv[2]);
    const char* pattern = argv[3];
   // cout<<"metodo:"<<metodo<<endl;
   // cout<<"arqNum:"<<arq<<endl;

    FILE* arquivo;
    const char * nome_arquivo;
    int comp = 0;
    int deslocamentos = 0;
    double tempo = -1;
    if(arq == 1){
        nome_arquivo = "pequeno.txt";
    }else if(arq==2){
       nome_arquivo = "medio.txt";
    }else if(arq ==3){
       nome_arquivo = "grande.txt";
    }
   // cout<<"nome_arquivo:"<<nome_arquivo<<endl;
  
    if((arquivo = fopen(nome_arquivo, "r")) == NULL){
        
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }else{
        
       
        TipoTexto texto;
        TipoPadrao padrao;
       

        char ch;int cont = 0;
        ch = getc(arquivo); //lê o 1o caractere do arquivo
        while (ch != EOF) { //varre o arquivo
            texto[cont]=ch;
            cont++;
            //putchar(ch); //imprime na tela o caractere lido
            ch = getc(arquivo); //lê o próximo caractere
        }        
        
  
        fseek(arquivo, 0, SEEK_END);
        long tamanhoTexto = ftell(arquivo);
       // cout<<"tam:"<<tamanhoTexto;

        strcpy(padrao, pattern);
        long tamanhoPadrao = strlen(padrao);
       // cout<<"tam padrao:"<<tamanhoPadrao;
        clock_t inicio;
       
        if(metodo ==1){
            inicio = clock();
            
            forcaBruta(texto, tamanhoTexto, padrao, tamanhoPadrao, &comp);
            
            tempo = ((double)clock() - inicio) / CLOCKS_PER_SEC;
           
        }else if(metodo ==2){
            inicio = clock();
                
            BM(texto, tamanhoTexto, padrao, tamanhoPadrao, &comp, &deslocamentos);
              
            tempo = ((double)clock() - inicio) / CLOCKS_PER_SEC;
        }else if(metodo ==3){
            inicio = clock();
            
            BMH(texto, tamanhoTexto, padrao, tamanhoPadrao, &comp, &deslocamentos);
            
            tempo = ((double) clock() - inicio) / CLOCKS_PER_SEC;
        }else if(metodo ==4){
            inicio = clock();
            BMHS(texto, tamanhoTexto, padrao, tamanhoPadrao, &comp, &deslocamentos);
            tempo = ((double) clock() - inicio) / CLOCKS_PER_SEC;
        }else if(metodo ==5){
            inicio = clock();
            shiftAnd(padrao, texto, tamanhoTexto, tamanhoPadrao, &comp);
            
            tempo = ((double) clock() - inicio) / CLOCKS_PER_SEC;
        }else{
            cout << "Metodo invalido" << endl;
        }
 
        //Argumento -P foi informado
        if(argc == 5 ){
            if(tempo == -1){
                cout << "Nao ha o que mostrar" << endl;
            }else{
                cout << "Comparacoes: " << comp << endl;
                cout << "Deslocamentos: " << deslocamentos << endl;
                cout << "Tempo (s) : " <<setprecision(5)<< tempo << endl;
            }
        }
       

        
    }
    
    fclose(arquivo);

    
    return 0;
}