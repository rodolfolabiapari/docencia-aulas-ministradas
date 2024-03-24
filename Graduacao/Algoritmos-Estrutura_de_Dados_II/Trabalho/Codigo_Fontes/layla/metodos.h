#ifndef METODOS_H_
#define METODOS_H_
#define MAXCHAR 256            //Tamanho do alfabeto em questao

void forcaBruta (const char T[], long tamTexto, const char P[], long tamPadrao, int* ocorrencias, int* qtOcorrencias, int* comparacoes, int *deslocamentos);
void BM_Ocorrencia(const char T[], long n, const char P[], long m, int* ocorrencias, int* qtOcorrencias, int* comparacoes, int* deslocamentos);
void BMH (const char T[], long tamTexto, const char P[], long tamPadrao, int* ocorrencias, int* qtOcorrencias, int* comparacoes, int* deslocamentos, 
	int* ppComparacoes, int* ppDeslocamentos);
void BMHS (const char T[], long tamTexto, const char P[], long tamPadrao, int* ocorrencias, int* qtOcorrencias, int* comparacoes, int* deslocamentos, 
	int* ppComparacoes, int* ppDeslocamentos);
void shiftAndExato(const char T[], long tamTexto, const char P[], long tamPadrao, int* ocorrencias, int* qtOcorrencias, int* comparacoes, int* deslocamentos,
	int* ppComparacoes,	int* ppDeslocamentos);

#endif // _METODOS_H
