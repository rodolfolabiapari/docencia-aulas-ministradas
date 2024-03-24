#include <iostream>              //Cin, cout
#include <stdio.h>               //Manipulação de arquivo: fopen, fclose, fscanf
#include <stdlib.h>              //Atoi
#include <string.h>              //strcmp
#include <iomanip>               //fixed, setw
#include <unistd.h>              //Essa e a próxima para controlar o tempo de execução
#include <time.h>
#include "metodos.h"             //Cabeçalhos das funções de casamento de padrão
#define maxTamTexto 2000000      //Macro para definir o tamanho do texto de forma fácil para evitar edição de código
using namespace std;

int main(int argc, char* argv[])
{
	int *metodoCasamento = new int(0), *contaLeitura = new int (0), comparacoesBusca = 0, deslocamentosBusca = 0, tempo = 0, contador = 0, ppComparacoes = 0;
	int *ocorrencias = new int [maxTamTexto], ppDeslocamentos = 0;
	FILE* arqEntrada;
	char* texto = new char [maxTamTexto];
	clock_t ticks[2];
	bool pp = true;

	if ((argc != 4) && (argc != 5))
	{
		cout << "Lista de argumentos de entrada invalida! Por favor siga o padrao:\n(nome do executavel) (metodo de casamento) (nome do arquivo TEXTO"
			 " a ser consultado) (padrao de busca) (Opcional: -P)" << endl;
		return 0;
	}
	
	*metodoCasamento = atoi (argv[1]);
	while ((*metodoCasamento < 1) || (*metodoCasamento > 5))
	{
		cout << "\nNumero atribuido ao METODO DE CASAMENTO DE PADRAO invalido. Por favor, insira uma das seguintes opcoes:\n1 - Forca Bruta\n2 - Boyer-Moore "
			"(BM)\n3 - Boyer-Moore-Horspool (BMH)\n4 - Boyer-Moore-Horspool-Sunday (BMHS)\n5 - Shift-And Exato" << endl << endl;
		cin >> *metodoCasamento;
	}

	if ((arqEntrada = fopen (argv[2], "r")) == NULL)
	{
		cout << "Nao foi possivel abrir o arquivo informado na entrada." << endl;
		delete (metodoCasamento);
		delete []texto;
		return 0;
	}

	if (argc == 5)
	{
		while (strcmp (argv[4], "-P") != 0)
		{
			cout << "O parametro opcional foi inserido de forma incorreta. Insira-o novamente (-P):\n";
			cin >> argv[4];
		}
	}

	while ((*contaLeitura < maxTamTexto) && ((texto[*contaLeitura] = fgetc(arqEntrada)) != EOF))
		(*contaLeitura)++;
	
	//Já acabei de utilizar o arquivo, então posso fechá-lo de uma vez e também deletar o auxiliar da leitura
	fclose (arqEntrada);
	delete (contaLeitura);

	switch (*metodoCasamento)
	{
		case 1:
		{
			ticks[0] = clock();
			forcaBruta (texto, maxTamTexto, argv[3], strlen(argv[3]), ocorrencias, &contador, &comparacoesBusca, &deslocamentosBusca);
			ticks[1] = clock();
			cout << "\n\nO metodo de casamento de padrao FORCA BRUTA finalizou a execucao." << endl << "Nao ha pre-processamento do padrao ou do texto neste"
				" metodo." << endl << endl;
			pp = false;
			break;
		}
		case 2:
		{
			ticks[0] = clock();
			BM_Ocorrencia(texto, maxTamTexto, argv[3], strlen(argv[3]), ocorrencias, &contador, &comparacoesBusca, &deslocamentosBusca);
			ticks[1] = clock();
			cout << "\n\nO metodo de casamento de padrao BM finalizou a execucao." << endl << "Nao ha pre-processamento do padrao ou do texto neste"
				" metodo." << endl << endl;
			pp = false;
			break;
		}
		case 3:
		{
			ticks[0] = clock();
			BMH (texto, maxTamTexto, argv[3], strlen(argv[3]), ocorrencias, &contador, &comparacoesBusca, &deslocamentosBusca, &ppComparacoes,&ppDeslocamentos);
			ticks[1] = clock();
			cout << "\n\nO metodo de casamento de padrao BMH finalizou a execucao." << endl;
			break;
		}
		case 4:
		{
			ticks[0] = clock();
			BMHS(texto, maxTamTexto, argv[3], strlen(argv[3]), ocorrencias, &contador, &comparacoesBusca, &deslocamentosBusca, &ppComparacoes,&ppDeslocamentos);
			ticks[1] = clock();
			cout << "\n\nO metodo de casamento de padrao BMHS finalizou a execucao." << endl;
			break;
		}
		case 5:
		{
			
			ticks[0] = clock();
			shiftAndExato(texto, maxTamTexto, argv[3], strlen(argv[3]), ocorrencias, &contador, &comparacoesBusca, &deslocamentosBusca, &ppComparacoes,	
				&ppDeslocamentos);
			ticks[1] = clock();
			cout << "\n\nO metodo de casamento de padrao SHIFT-AND EXATO finalizou a execucao." << endl;
			break;
		}
		default:
			break;
	}

	//Desaloco a memória que foi alocada dinamicamente
	delete (metodoCasamento);
	delete []texto;
	tempo = (ticks[1] - ticks[0]) * 1000 / CLOCKS_PER_SEC;

	cout << "Foram encontradas " << contador << " ocorrencias do padrao no texto, nas seguintes posicoes: " << endl;
	for (int i = 0; i < contador; i++)
	{
		if ((i != 0) && (i % 10 == 0))
			cout << endl;
		cout << fixed << setw (10) << ocorrencias[i];
	}
	cout << endl;

	if (argc == 5)      //Se houver o parâmetro opcional -P, que foi validado acima, imprimir os dados abaixo na tela
	{
		if (pp)
			cout << "Comparacoes do pre-processamento: " << ppComparacoes << endl << "Deslocamentos do pre-processamento: " << ppDeslocamentos << endl;
	
		cout << "Comparacoes entre o texto e o padrao durante a busca: " << comparacoesBusca << endl << "Deslocamentos do texto durante a busca: ";
		cout << deslocamentosBusca << endl << "Tempo de execucao: " << tempo << "ms" << endl;
	}
	
	delete []ocorrencias;
	return 0;
}