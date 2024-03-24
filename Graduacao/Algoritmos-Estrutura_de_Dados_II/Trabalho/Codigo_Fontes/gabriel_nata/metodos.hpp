#ifndef METODOS_HPP_
#define METODOS_HPP_

#include "contaDados.hpp"

// Metodos e constantes dos métodos de casamentos de cadeia
#define MAXTAMTEXTO 3000001
#define MAXTAMPADRAO 250
#define MAXCHAR 256

typedef char TipoTexto[MAXTAMTEXTO];
typedef char TipoPadrao[MAXTAMPADRAO];

void BMHS(TipoTexto T, long n, TipoPadrao P, long m);
void ForcaBruta (TipoTexto, long, TipoPadrao, long);
void ShiftAnd(TipoTexto, long,TipoPadrao, long);
void BMH (TipoTexto, long, TipoPadrao, long);
void BMC(TipoTexto, int, TipoPadrao, int);

//funcões auxiliares para preprocessametno do metodo BMC
void preBmGs(char*, int, int*);
void suffixes(char*, int, int*);

#endif
