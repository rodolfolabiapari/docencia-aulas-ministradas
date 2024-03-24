#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "metodos.hpp"

using namespace std;

int main(int argc, char const *argv[]){  
    short metodo;
    char texto[MAXTAMTEXTO];
    char padrao[MAXTAMPADRAO];
    char NomeTexto[50];
    char ent1;
    char ent2;
    unsigned long tamTexto, tamPadrao;
    FILE* arq;    
    
    if(argc == 4 || argc == 5){
        metodo = atoi(argv[1]);
        strcpy(NomeTexto, argv[2]);
        strcpy(padrao, argv[3]);
    }
    else{
        cout <<"FORMATO DE EXECUÇÃO: casamento <método> <texto> <padrão> [-P]\n";
        exit(1);
    }
    if((arq = fopen(NomeTexto,"r"))==NULL){
        cout << "Erro ao abrir arquivo de entrada " <<endl;
        exit(1);
    }
    
    //Careega o conteudo do texto para o vetor
    char aux;
    int i = 0;
    while (true) {
        aux = fgetc(arq);
        if (aux != EOF)
            texto[i] = aux;
        else
            break;
        i++;
    }
    texto[i] = '\0';
    
    //calcula os tamanhos do texto e padrão
    tamPadrao = strlen(padrao);
    tamTexto = strlen(texto);
    
    iniciaContadores();
    switch(metodo){
        case 1:
            ForcaBruta(texto, tamTexto, padrao, tamPadrao);
            break;
        case 2:
            BMC(texto, tamTexto, padrao, tamPadrao);
            break;
        case 3:
            BMH(texto, tamTexto, padrao, tamPadrao);
            break;
        case 4:
            BMHS(texto, tamTexto, padrao, tamPadrao);
            break;
        case 5:
            ShiftAnd(texto, tamTexto, padrao, tamPadrao);
            break;
        default:
            cout << "METODO INVALIDO\n";
            break;
        
    }
    
    //verifica se o usuario deseja ver os dados de estatistica computados
    if(argc == 5){
        ent1 = argv[4][0];
        ent2 = argv[4][1];
        if(ent1 == '-' && ent2 == 'P')
        {
            returnDados();
        }
        else
        {
            cout << "Metodo de entrada: ./casamento <metodo> <arquivo> <entrada> -P" << endl;
        } 
    }

    fclose(arq);
    return 0;
}