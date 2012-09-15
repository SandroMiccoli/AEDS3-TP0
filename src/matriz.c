/*
  Módulo de manipulação de matrizes alocando a memória dinâmicamente

  Funções de inserção, remoção, impressão e outras manipulações.

  Criação: 15/09/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

// Cria a matriz
void criaMatriz(int col, int lin, Matriz *matriz){
    matriz->col = col;
    matriz->lin = lin;
    matriz->matriz = mallocaMatriz(col, lin);
}

// Maloca todas as linhas e colunas da matriz
int ** mallocaMatriz(int col, int lin){
    int ** matriz;
    matriz = (int **) malloc (col * sizeof(int));
    for (int i = 0; i < col; i++){
        matriz[i] = (int *) malloc (lin * sizeof(int));
    }
    return matriz;

}

// Dá free em todos os vetores alocados pela matriz
void destroiMatriz(Matriz *matriz){
    for (int i = 0; i < matriz->col; i++){
        free(matriz->matriz[i]);
    }
    free(matriz->matriz);
}

