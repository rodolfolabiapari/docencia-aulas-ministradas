#ifndef casamento_h
#define casamento_h
    
    #include <iostream>
    #include <iostream>
    #include <cstdlib>
    #include <cstdio>
    #include <ctime>
    #include <cstring>

    using namespace std;

    #define MAXTAMTEXTO 3000000
    #define MAXTAMPADRAO 250
    #define MAXCHAR 256
    #define NUMMAXERROS 10

    typedef char TipoTexto[MAXTAMTEXTO];
    typedef char TipoPadrao[MAXTAMPADRAO];
    
    void booyerMoore(TipoTexto T, long n, TipoPadrao P, long m, int* comp, int* desloc);
    void BMH(TipoTexto T, long n, TipoPadrao P, long m, int* comp, int* desloc);
    void BMHS(TipoTexto T, long n, TipoPadrao P, long m, int* comp, int* desloc);
    void forcaBruta(TipoTexto, long, TipoPadrao, long, int*);
    void shiftAnd(TipoPadrao padrao,TipoTexto texto, long tamanhoTexto, long tamPadrao, int* comp);

#endif

