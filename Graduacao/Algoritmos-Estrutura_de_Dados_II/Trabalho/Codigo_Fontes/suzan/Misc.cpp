#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Misc.hpp"

using namespace std;

void err() {
    printf("Uso: casamento <METODO> <TEXTO> <PADRAO> [-p] [-a]\n\n"
           "Argumento METODO:\n"
           "   Representa o metodo de casamento exato de cadeias a ser executado, podendo ser:\n"
           "   -f, --forca-bruta       Forca Bruta;\n"
           "   -b, --boyer-moore       Boyer-Moore (BM) com heuristica ocorrencia;\n"
           "   -m, --bm-horspool       Boyer-Moore-Horspool (BMH);\n"
           "   -h, --bmh-sunday        Boyer-Moore-Horspool-Sunday (BMHS);\n"
           "   -s, --shift-and         Shift-And Exato.\n"
           "Argumento TEXTO:\n"
           "   Representa o nome fisico do arquivo texto a ser utilizado pelo metodo.\n"
           "Argumento PADRAO:\n"
           "   Representa o padrao a ser procurado no arquivo texto.\n"
           "Argumentos opcionais [-p] [-a]:\n"
           "   -p, --print             Imprime na tela os valores obtidos referentes aos quesitos de analise \n"
           "                           (numero de comparacoes, numero de deslocamentos, tempo de execucao).\n"
           "   -a, --analise           Exporta os valores presentes nos contadores para o arquivo result.csv\n\n");
}

void imprimeContador(TipoContador cont) {
    printf("\n\n"
           "-----------------------------------------------\n"
           "Total de ocorrencias:       %lu \n\n"
           "Pre-Processamento: \n"
           "--Tempo de execucao:        %f seg\n"
           "--Numero de comparacoes:    %lu \n"
           "--Numero de deslocamentos:  %lu \n\n"
           "Pesquisa: \n"
           "--Tempo de execucao:        %f seg\n"
           "--Numero de comparacoes:    %lu\n"
           "--Numero de deslocamentos:  %lu\n"
           "-----------------------------------------------"
           "\n\n",
           cont.ocorrencias,
           (double)cont.tempoPre / CLOCKS_PER_SEC, cont.comparacoesPre, cont.deslocamentosPre,
           (double)cont.tempo / CLOCKS_PER_SEC, cont.comparacoes, cont.deslocamentos);
}

void zeraContador(TipoContador* cont) {
    cont->comparacoes = 0;
    cont->deslocamentos = 0;
    cont->tempo = 0;
    cont->comparacoesPre = 0;
    cont->deslocamentosPre = 0;
    cont->tempoPre = 0;
    cont->ocorrencias = 0;
}

size_t leTexto(FILE* arqTexto, TipoTexto* texto){
    //Move o ponteiro do tipo FILE para o final do arquivo
    fseek(arqTexto,0, SEEK_END);

    /*Obtem a posicao atual do ponteiro, que estando no final *
     * corresponde ao tamanho (nº de caracteres do arquivo)   */
    size_t tamanho = ftell(arqTexto);

    //Aloca dinamicamente um vetor do tipo char do tamanho encontrado
    *texto = (char *) malloc(tamanho * sizeof(char));

    //Rebobina o arquivo para o inicio
    rewind(arqTexto);

    //Faz a leitura do arquivo para o vetor criado
    while(fgets(*texto, tamanho, arqTexto));

    return tamanho;
}

void lePadrao(char* arg, TipoPadrao* padrao){
    //Aloca um dinamicamente vetor de char para o tamanho do argumento inserido
    *padrao = (char *) malloc( getTamanho(arg) * sizeof(char));

    //Copia o argumento para o vetor alocado
    strcpy(*padrao, arg);
}

size_t getTamanho(char* c){
    //Retorna o tamanho do vetor de char passado como argumento
    return strlen(c);
}

void desaloca(char* c){
    //Desaloca a memoria e aponta o ponteiro para NULL, por boa pratica de seguranca
    free (c);
    c = NULL;
}

//Funcao que retorna o maior entre dois numeros
long max(long a, long b) {
    return (a > b)? a : b;
}

//A funcao de preprocessamento para heuristica de ocorrencia (Caractere errado) do algoritmo BM.
void pre(char *str, size_t tam, int vet[NUM_CHARS], TipoContador* cont) {
    cont->tempoPre = clock();
    int i;

    //! Inicializa todas as ocorrencias com -1.
    for (i = 0; i < NUM_CHARS; i++)
        vet[i] = -1;

    //! Preenche o valor da ultima ocorrencia de um caractere.
    for (i = 0; i < tam; i++)
        vet[(int) str[i]] = i;

    cont->tempoPre = clock() - cont->tempoPre;
}

//Esta função exporta um aquivo na extensão .csv com os dados referentes à análise dos testes,
//facilitando assim que sejam inseridos no relatório
void exportToCSV(TipoContador cont){
    FILE* arq;
    arq = fopen("result.csv","a+");
    if (arq == NULL){
        perror("Erro ao abrir o arquivo result.csv para exportar os resultados");
        return;
    }
    fprintf(arq,"%lu,%lu,%f,%lu \n",cont.deslocamentosPre,cont.comparacoesPre,(double)cont.tempoPre / CLOCKS_PER_SEC,cont.ocorrencias);
    fprintf(arq,"%lu,%lu,%f,%lu \n",cont.deslocamentos,cont.comparacoes,(double)cont.tempo / CLOCKS_PER_SEC,cont.ocorrencias);
    fclose(arq);
}
