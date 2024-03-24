#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include "casamento.h"

#define FORCA_BRUTA 1
#define BOOYER_MOORE 2
#define BOOYERMH 3
#define BOOYERMH_S 4
#define SHIFT_AND 5

using namespace std;

int main(int argc, char* argv[]){
    
    int metodo = strtol(argv[1], NULL, 10);
    const char* nome_arquivo = argv[2];
    const char* pattern = argv[3];
    string imprimir = argv[4];

    FILE* arquivo;
    
    int comparacoes = 0;
    int deslocamentos = 0;
    double tempo_execucao = -1;
    
    if((arquivo = fopen(nome_arquivo, "r")) == NULL){
        
        cout << "Não foi possível abrir o arquivo" << endl;
    }else{
        TipoTexto texto;
        TipoPadrao padrao;
        
        //criando o padrao a partir do argumento
        strcpy(padrao, pattern);
        int tamanhoPadrao = strlen(padrao);
        
        //criando o texto a partir do argumento
        fgets(texto, 3000000, arquivo);
        int tamanhoTexto = strlen(texto);
        
        clock_t inicio;
        switch (metodo) {
        
            case FORCA_BRUTA:
                inicio = clock();
                
                forcaBruta(texto, tamanhoTexto, padrao, tamanhoPadrao, &comparacoes);
                
                tempo_execucao = ((double) clock() - inicio) / CLOCKS_PER_SEC;
                break;

            case BOOYER_MOORE:
                inicio = clock();
                
                booyerMoore(texto, tamanhoTexto, padrao, tamanhoPadrao, &comparacoes, &deslocamentos);
                
                tempo_execucao = ((double) clock() - inicio) / CLOCKS_PER_SEC;
                break;

            case BOOYERMH:
                inicio = clock();
                
                BMH(texto, tamanhoTexto, padrao, tamanhoPadrao, &comparacoes, &deslocamentos);
                
                tempo_execucao = ((double) clock() - inicio) / CLOCKS_PER_SEC;
                break;

            case BOOYERMH_S:
                inicio = clock();
                
                BMHS(texto, tamanhoTexto, padrao, tamanhoPadrao, &comparacoes, &deslocamentos);
                
                tempo_execucao = ((double) clock() - inicio) / CLOCKS_PER_SEC;
                break;

            case SHIFT_AND:
                inicio = clock();
                
                shiftAnd(padrao, texto, tamanhoTexto, tamanhoPadrao, &comparacoes);
                
                tempo_execucao = ((double) clock() - inicio) / CLOCKS_PER_SEC;
                break;

            default:
                cout << "Método inválido" << endl;
        }
        
        //Argumento -P foi informado
        if(imprimir == "[-P]"){
            if(tempo_execucao == -1){
                cout << "Não há o que mostrar" << endl;
            }else{
                cout << "Comparações: " << comparacoes << endl;
                cout << "Deslocamentos: " << deslocamentos << endl;
                cout << "Tempo (s) : " << tempo_execucao << endl;
            }
        }
    }
    
    fclose(arquivo);
    return 0;
}