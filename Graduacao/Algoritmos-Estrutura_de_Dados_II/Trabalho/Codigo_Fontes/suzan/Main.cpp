#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Misc.hpp"
#include "BM.hpp"
#include "BMH.hpp"
#include "BMHS.hpp"
#include "ForcaBruta.hpp"
#include "ShiftAnd.hpp"

int main(int argc, char* argv[]) {
    FILE* arqTexto;
    TipoTexto texto;
    TipoPadrao padrao;
    TipoContador cont;
    size_t tamPadrao, tamTexto;

    //Verifica se o numero de argumentos inseridos e o minimo esperado
    if (argc < 4){
        err();
        return 0;
    }

    //Faz a abertura do arquivo texto, ou exibe erro caso não seja possivel
    arqTexto = fopen(argv[2], "r");
    if (arqTexto == NULL) {
        fprintf(stderr,"Nao foi possivel abrir o arquivo \"%s\": ", argv[2]);
        perror(""); //Imprime o tipo de erro gerado ao tentar abrir o arquivo
        printf("\n\n");
        return -1;
    }

    //Armazena o arquivo texto inserido e o fecha (a funcao tambem retorna o tamanho do texto)
    tamTexto = leTexto(arqTexto, &texto);
    fclose(arqTexto);

    //Armazena o padrao inserido
    lePadrao(argv[3], &padrao);

    //Verifica o tamanho do padrao (tamanho do padrao deve ser menor ou igual ao do texto)
    tamPadrao = getTamanho(padrao);

    if (tamPadrao>tamTexto) {
        printf("ERRO: Tamanho do padrao maior que tamanho do texto!\n");
        return -1;
    }

    /*  Verifica o metodo desejado, chamando sua respectiva funcao,  *
     *  ou apresenta erro caso nao seja inserido um metodo valido    */
    zeraContador(&cont);
    if (!strcmp(argv[1], "-f") || !strcmp(argv[1], "--forca-bruta") || !strcmp(argv[1], "1")){
        forcaBruta(&cont, texto, padrao, tamTexto, tamPadrao);
    }
    else if (!strcmp(argv[1], "-b") || !strcmp(argv[1], "--boyer-moore") || !strcmp(argv[1], "2")){
        boyerMoore(&cont, texto, padrao, tamTexto, tamPadrao);
    }
    else if (!strcmp(argv[1], "-m") || !strcmp(argv[1], "--bm-horspool") || !strcmp(argv[1], "3")){
        horspool(&cont, texto, padrao, tamTexto, tamPadrao);
    }
    else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--bmh-sunday") || !strcmp(argv[1], "4")){
        horspoolSunday(&cont, texto, padrao, tamTexto, tamPadrao);
    }
    else if (!strcmp(argv[1], "-s") || !strcmp(argv[1], "--shift-and") || !strcmp(argv[1], "5")){
        shiftAnd(&cont, texto, padrao, tamTexto, tamPadrao);
    }
    else{
        printf("Metodo Invalido! \n\n");
        err();
        desaloca(texto);
        desaloca(padrao);
        return 0;
    }

    printf("\n"); //Correção da saida quando nao é utilizado nenhum argumento opcional

    //Verifica o argumento -p ou --print, e se houver, imprime os contadores
    if (argc >= 5){
        if(!strcmp(argv[4], "-p") || !strcmp(argv[4], "--print")){
            imprimeContador(cont);
        }
    }

    //Verifica o argumento -a ou --analise
    if (argc >= 5){
        if(!strcmp(argv[4], "-a") || !strcmp(argv[4], "--analise")){
            exportToCSV(cont);
        }
    }

    desaloca(texto);
    desaloca(padrao);

    return 0;
}