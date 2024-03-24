#ifndef MISC_HPP
#define MISC_HPP

#include <stdio.h>
#include <time.h>
#include <string.h>

using namespace std;

#define NUM_CHARS 256

typedef char* TipoPadrao;
typedef char* TipoTexto;

typedef struct TipoContador{
    time_t tempo;
    long comparacoes;
    long deslocamentos;
    time_t tempoPre;
    long comparacoesPre;
    long deslocamentosPre;
    long ocorrencias;
} TipoContador;

void err(); //Exibe a mensagem de ajuda com os argumentos esperados
void imprimeContador(TipoContador cont);
void zeraContador(TipoContador* cont);
size_t leTexto(FILE* arqTexto, TipoTexto* texto);
void lePadrao(char* arg, TipoPadrao* padrao);
size_t getTamanho(char* c);
void desaloca(char* c);
long max(long a, long b); //Funcao que retorna o maior entre dois numeros
void pre(char *str, size_t tam, int vet[NUM_CHARS], TipoContador* cont); //A funcao de preprocessamento para heuristica de ocorrencia (Caractere errado) do algoritmo BM.
void exportToCSV(TipoContador cont); //exporta contadores para result.csv

#endif //MISC_HPP