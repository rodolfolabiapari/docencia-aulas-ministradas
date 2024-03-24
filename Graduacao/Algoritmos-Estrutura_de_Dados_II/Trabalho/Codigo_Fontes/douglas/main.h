#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> 

using namespace std; 

#define MAXTAMTEXTO 2000000 // Tamanho máximo do texto
#define MAXTAMPADRAO 30 // Tamanho máximo do padrão
#define MAXCHAR 256 // Tamanho máximo do alfabeto
typedef char TipoTexto[MAXTAMTEXTO];
typedef char TipoPadrao[MAXTAMPADRAO];

void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m,int *comparacoes,int *deslocamentos);
void BoyerMoore(TipoTexto T, long n, TipoPadrao P, long m, int *comparacoes, int *deslocamentos);
void BoyerMooreHorspool(TipoTexto T, long n, TipoPadrao P, long m, int *comparacoes, int *deslocamentos);
void BoyerMooreHorspoolSunday(TipoTexto T, long n, TipoPadrao P, long m, int *comparacoes, int *deslocamentos);
void ShiftAnd(TipoTexto texto, long tamanhoTexto, TipoPadrao padrao, long tamPadrao, int *deslocamentos);

#endif