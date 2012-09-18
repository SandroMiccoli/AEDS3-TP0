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
        int k; // Instâncias de matrizes
        int i,j; // iteradores

        strcat(entrada,argv[1]);
        strcat(saida,argv[2]);

        FILE * inp = abreArquivoLeitura(entrada);
        FILE * out = abreArquivoEscrita(saida);

        fscanf(inp, "%d ", &k); // Lê as k instâncias de pares de matriz

        Matriz * matrizes;
        Matriz * matrizesResultado;

        matrizes = (struct Matriz*) malloc(k * 2 * sizeof(struct Matriz)); // Aloca espaço para todos as instãncias de matrizes
        matrizesResultado = (struct Matriz*) malloc(k * sizeof(struct Matriz)); // Aloca espaço para todos as instãncias de matrizes

        leMatrizes(inp, k, matrizes);

        // Realiza o produto de Kronecker entre todas as instâncias de matrizes
        // e insere no array matrizesResultado
        for (i = 0, j=0; i < k * 2; i+=2, j++){
            produtoKronecker(matrizes[i],matrizes[i+1],matrizesResultado, j);

        }

        // Imprime o resultado das operações no arquivo de saída.
        fprintf(out,"%d\n",k);
        for (i=0;i<k;i++)
            imprimeMatrizNoArquivo(out,matrizesResultado[i]);

        // Limpando a memória
        for (i = 0; i < k * 2; i++)
            destroiMatriz(&matrizes[i]);
        // Limpando a memória
        for (j = 0; j < k; j++)
            destroiMatriz(&matrizesResultado[j]);
        free(matrizes);
        free(matrizesResultado);
        fechaArquivo(inp);
        fechaArquivo(out);

    }
    else{
        printf("Número incorreto de parâmetros. Fazer seguir exemplo:\n\n\t./tp0 input.txt output.txt\n\n"); exit(0);
    }
    return 0;
}
