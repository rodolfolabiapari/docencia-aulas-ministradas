#ifndef funcoes_h
#define funcoes_h

#define MAXTAMTEXTO 5000000
#define MAXTAMPADRAO 30
#define MAXCHAR 256

typedef char TipoTexto [MAXTAMTEXTO];
typedef char TipoPadrao [MAXTAMPADRAO];

// Conjunto de funções de casamento de cadeia

void ForcaBruta (TipoTexto, long, TipoPadrao, long);
void BMH (TipoTexto, long, TipoPadrao, long);
void BMHS (TipoTexto, long, TipoPadrao, long);
void ShiftAnd (TipoTexto, long, TipoPadrao, long);
void BMC(TipoTexto, int, TipoPadrao, int);

//funcões auxiliares para preprocessametno do metodo BMC
void preBmGs(char*, int, int*);
void suffixes(char*, int, int*);

#endif
