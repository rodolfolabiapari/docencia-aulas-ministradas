typedef struct Comparacao
{
    int nComp, nDesloc;
} TComparacao;

void forcaBruta(char nmArq[],char p[],int m,TComparacao *dado);

void BM_Ocorrencia(char nmArq[], char p[], int tamPadrao, TComparacao *dado);

char *substr(char vetor[], int tamVetor, int n, int posIni);

int strCmp(char casamento[], char trecho[], int n, TComparacao *dado);

void BM_Casamento(char nmArq[], char p[], int tamPadrao, TComparacao *dado);

void BMH(char nmArq[],char p[],int m,TComparacao *dado);

void BMHS(char nmArq[],char p[],int m,TComparacao *dado);

void ShiftAndExato(char nmArq[], char p[], int tamPadrao, TComparacao *dado);
