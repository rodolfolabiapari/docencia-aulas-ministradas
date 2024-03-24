#ifndef casamento_h
#define casamento_h
    #define TAMTEXTO 1000000
    #define TAMPADRAO 250
    #define MAXCHAR 256
    #define NUMMAXERROS 10

    typedef char TipoTexto[TAMTEXTO];
    typedef char TipoPadrao[TAMPADRAO];
    
    void forcaBruta(TipoTexto, long, TipoPadrao, long, int*);
    void BM(TipoTexto , long , TipoPadrao , long , int* , int* ); 
    void BMH(TipoTexto , long , TipoPadrao , long , int* , int* );
    void BMHS(TipoTexto , long , TipoPadrao , long , int* , int* );
    void shiftAnd(TipoPadrao ,TipoTexto , long , long , int* );

#endif

