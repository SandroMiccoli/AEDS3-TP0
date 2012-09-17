/*
  Trabalho Prático 0 - Produto de Kronecker

  Calcular o produto de Kronecker entre duas matrizes e gravar o resultado em um arquivo.

  Criação: 15/09/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include "arquivos.h"
#include "matriz.h"
#include "kronecker.h"


int main(){
    FILE * ent = abreArquivoLeitura("entrada/input.txt");
    FILE * out = abreArquivoEscrita("entrada/output.txt");
    int k;
    fscanf(ent, "%d ", &k); // Lê as k instâncias de pares de matriz
   // printf("%d\n",k);

    Matriz * matrizes;
    Matriz * matrizesResultado;

    matrizes = (struct Matriz*) malloc(k * 2 * sizeof(struct Matriz)); // Aloca espaço para todos as instãncias de matrizes
    matrizesResultado = (struct Matriz*) malloc(k * sizeof(struct Matriz)); // Aloca espaço para todos as instãncias de matrizes


    leMatrizes(ent, k, matrizes);

    imprimeMatriz(matrizes[2]);
    imprimeMatriz(matrizes[3]);

    produtoKronecker(matrizes[2],matrizes[3],matrizesResultado);

    // Limpando a memória
    for (int i = 0; i < k * 2; i++)
        destroiMatriz(&matrizes[i]);
    free(matrizes);
    fechaArquivo(ent);
    fechaArquivo(out);

    return 0;
}
