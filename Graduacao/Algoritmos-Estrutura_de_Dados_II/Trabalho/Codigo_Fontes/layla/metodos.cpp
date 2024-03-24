#include "metodos.h"

// CODIGO Forca Bruta
void forcaBruta (const char T[], long tamTexto, const char P[], long tamPadrao, int* ocorrencias, int* qtOcorrencias, int* comparacoes, int *deslocamentos)
{
	long caminhaTexto, caminhaPadrao, k;
	for (caminhaTexto = 1; caminhaTexto <= (tamTexto - tamPadrao + 1); caminhaTexto++)
	{//Enquanto houver letras do texto a percorrer, e caminhaTexto for menor que tamanho do padrao + 1
		k = caminhaTexto;
		caminhaPadrao = 1;
		*deslocamentos += 1;       //O processamento "linear" do texto conta um para cada deslocamento

		*comparacoes += 1;     //Incremento das comparações do while abaixo, no caso do while inválido
		while (T[k - 1] == P[caminhaPadrao - 1] && caminhaPadrao <= tamPadrao)
		{//Enquanto o caracter do texto for igual ao caracter do padrao e for possível caminhar no padrão
			*comparacoes += 1;     //Toda vez que entrar nesse while, houve uma comparação com while válido
			*deslocamentos += 1;    //Toda vez que há igualdade do caracter com o padrão, há um deslocamento de 1 posição no texto
			caminhaPadrao++;
			k++;
		}
		if (caminhaPadrao > tamPadrao)         //Se eu caminhei no padrão de forma a caminhaPadrao == tamPadrao, então houve um casamento
		{
			ocorrencias[*qtOcorrencias] = caminhaTexto - 1;      //-1 para contar a partir da posição 0
			(*qtOcorrencias)++;
		}
	}
}

// CODIGO BM
void BM_Ocorrencia(const char T[], long tamTexto, const char P[], long tamPadrao, int* ocorrencias, int* qtOcorrencias, int* comparacoes, int* deslocamentos)
{
	int i, j, k, desl = 1;

	for (i = tamPadrao - 1; i < tamTexto; i = i + desl)
	{
		k = i;
		j = tamPadrao - 1;

		while(j >= 0 && T[k] == P[j])
		{
			j--;
			k--;
			*comparacoes = *comparacoes + 1;
		}

		*comparacoes = *comparacoes + 1;
		if(j + 1 == 0)
			ocorrencias[(*qtOcorrencias)++] = i - (tamPadrao - 1);
		else
		{
			//CALCULO DO DESLOCAMENTO
			int l = j;
			desl = 1;
			while(T[k] != P[l-1] && l > 0)
			{
				desl++;
				l--;
				*comparacoes = *comparacoes + 1;
			}
			//A CADA VEZ QUE UM NOVO SALTO É REALIZADO, A VARIAVEL "DESLOCAMENTO" É INCREMENTADA
			*deslocamentos = *deslocamentos + 1;
		}
	}
}

// CODIGO BMH
void BMH (const char T[], long tamTexto, const char P[], long tamPadrao, int* ocorrencias, int* qtOcorrencias, int* comparacoes, int* deslocamentos, 
	int* ppComparacoes, int* ppDeslocamentos)
{
	long i, j, k, desloc[MAXCHAR + 1];
	for (j = 0; j <= MAXCHAR; j++)      //Gero a tabela de deslocamentos para cada letra do alfabeto que inicialmente é o tamanho do padrão
		desloc[j] = tamPadrao;
	
	for (j = 1; j < tamPadrao; j++)     //Para cada letra do padrão, existente no alfabeto, eu atribuo um novo deslocamento correspondente
	{
		desloc[(int)P[j - 1]] = tamPadrao - j;   //O acesso é feito pelo código ASCII do caracter
		(*ppDeslocamentos) += 1;                 //Eu efetuo alguns deslocamentos no padrão
	}
	i = tamPadrao;

	while (i <= tamTexto)    //Enquanto houver letras do texto para comparar com o padrão
	{
		k = i;
		j = tamPadrao;

		while (j > 0 && T[k - 1] == P[j - 1])    //Enquanto a letra do texto for igual ao padrão e eu não tiver varrido o padrão todo
		{
			*comparacoes += 1;     //Toda vez que o while for válido, mais uma comparação porque ocorreu mais um casamento de uma letra do padrão com o texto
			k--;                   //O padrão é percorrido de trás para frente, por isso os decrementos
			j--;
		}
		*comparacoes += 1;         //Mais uma comparação para toda vez que o while for por algum motivo, inválido
		if (j == 0)
			ocorrencias[(*qtOcorrencias)++] = k;
	
		i += desloc[(int)T[i - 1]];       //Encontro o valor do próximo deslocamento
		*deslocamentos += 1;         //Faço o deslocamento
	}
}

// CODIGO BMHS
void BMHS (const char T[], long tamTexto, const char P[], long tamPadrao, int* ocorrencias, int* qtOcorrencias, int* comparacoes, int* deslocamentos, 
	int* ppComparacoes, int* ppDeslocamentos)
{
	long i, j, k, desloc[MAXCHAR + 1];
	for (j = 0; j <= MAXCHAR; j++)   //Gero a tabela de deslocamentos de cada letra do alfabeto, que é igual ao tamanho do padrão + 1
		desloc[j] = tamPadrao + 1;

	for (j = 1; j <= tamPadrao; j++)   //Para cada letra do padrão, existente no alfabeto, eu atribuo um novo deslocamento correspondente
	{
		desloc[(int)P[j - 1]] = tamPadrao - j + 1;    ///Para cada letra do padrão, existente no alfabeto, eu atribuo um novo deslocamento correspondente
		(*ppDeslocamentos) += 1;      //Atribuo um número a cada letra existente no padrão, Desloco o padrão, utilizando a parte P[j - 1]
	}

	i = tamPadrao;

	while (i <= tamTexto)   //Enquanto houver caracteres do texto para verificar
	{
		k = i;
		j = tamPadrao;
		while (j > 0 && T[k - 1] == P[j - 1])
		{
			*comparacoes = *comparacoes + 1;   //Para cada vez que o while for verdadeiro (caracter x == caracterPadrao y) e houver letras no padrao a percorrer
			k--;                   //O padrão é verificado de trás pra frente
			j--;
		}
		*comparacoes = *comparacoes + 1;    //Para quando o while for inválido

		if (j == 0)             //Quando acontece o casamento
			ocorrencias[(*qtOcorrencias)++] = k;

		i += desloc[(int)T[i]];
		*deslocamentos += 1;         //Faço um deslocamento de acordo com o i calculado acima
	}
}

// CODIGO Shift-And Exato

void shiftAndExato(const char T[], long tamTexto, const char P[], long tamPadrao, int* ocorrencias, int* qtOcorrencias, int* comparacoes, int* deslocamentos,
	int* ppComparacoes,	int* ppDeslocamentos)
{
    long M[MAXCHAR], i;
    unsigned long R = 0; // R começa com 0 indicando que não há correspondencias

    /*Pré-processamento*/
    for (i = 0; i < MAXCHAR; ++i) // Inicializa os elementos do alfabeto com 0
        M[i] = 0;
    for (i = 1; i <= tamPadrao; ++i){ // Preenche os elementos do alfabeto conforme a ocorrencia no padrão
        M[P[i - 1] + 127] |= 1 << (tamPadrao - i);
		*ppComparacoes += 1;
		*ppDeslocamentos += 1;
	}


    /*Pesquisa*/
    for (i = 0; i < tamTexto; ++i)
    {
        R = ((R >> 1) | 1 << (tamPadrao - 1)) & M[T[i] + 127]; // R recebe a correspondencia
        *comparacoes += 1; // add 1 comparação pelo if a seguir
		
		if ((R & 1) != 0)    // Se achou o padrão
        	ocorrencias[(*qtOcorrencias)++] = i + 1 - tamPadrao;
	
		*deslocamentos += 1;
    }
}