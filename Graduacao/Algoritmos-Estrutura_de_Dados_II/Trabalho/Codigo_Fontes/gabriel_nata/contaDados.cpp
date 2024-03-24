#include "contaDados.hpp"
#include "time.h"
#include <iostream>

using namespace std;

static long comparacoes;
static long deslocamentos;
static double tempo;
static clock_t c1, c2;

void iniciaContadores(){
    tempo = 0;
    deslocamentos = 0;
    comparacoes = 0;
    c1 = 0;
    c2 = 0;
}

void incrementaComparacoes(){
    comparacoes++;   
}

void incrementaDeslocamentos(){
    deslocamentos++;    
}

void iniciaTempo(){
    c1 = clock();
}

void fechaTempo(){
    c2 = clock();
    tempo = ((c2 - c1)*1.0)/CLOCKS_PER_SEC;
}

void returnDados(){
    cout << "Deslocamentos: " << deslocamentos << endl;
    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Tempo Total: " << tempo << "\n"<<endl;
}