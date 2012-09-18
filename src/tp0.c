/*
  Trabalho Prático 0 - Produto de Kronecker

  Calcular o produto de Kronecker entre duas matrizes e gravar o resultado em um arquivo.

  Criação: 15/09/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "matriz.h"
#include "kronecker.h"


int main(int argc, char *argv[]){


    if (argc == 3){ // Nome do arquivo (argv[0]) mais os dois parâmetros

        char entrada[20] = "entrada/";
        char saida[20] = "saida/";

        strcat(entrada,argv[1]);
        strcat(saida,argv[2]);

        FILE * ent = abreArquivoLeitura(entrada);
        FILE * out = abreArquivoEscrita(saida);


        int k;
        fscanf(ent, "%d ", &k); // Lê as k instâncias de pares de matriz
       // printf("%d\n",k);

        Matriz * matrizes;
        Matriz * matrizesResultado;

        matrizes = (struct Matriz*) malloc(k * 2 * sizeof(struct Matriz)); // Aloca espaço para todos as instãncias de matrizes
        matrizesResultado = (struct Matriz*) malloc(k * sizeof(struct Matriz)); // Aloca espaço para todos as instãncias de matrizes


        leMatrizes(ent, k, matrizes);

        imprimeMatriz(matrizes[0]);
        imprimeMatriz(matrizes[1]);
        printf("Resultado:\n");
        produtoKronecker(matrizes[0],matrizes[1],matrizesResultado);

        // Limpando a memória
        for (int i = 0; i < k * 2; i++)
            destroiMatriz(&matrizes[i]);
        free(matrizes);
        free(matrizesResultado);
        fechaArquivo(ent);
        fechaArquivo(out);

    }
    else{
        printf("Número incorreto de parâmetros. Fazer seguir exemplo:\n\n\t./tp0 input.txt output.txt\n\n"); exit(0);
    }
    return 0;
}
