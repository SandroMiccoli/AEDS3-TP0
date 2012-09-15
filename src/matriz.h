/*
  Módulo de manipulação de matrizes alocando a memória dinâmicamente

  Funções de inserção, remoção, impressão e outras manipulações.

  Criação: 15/09/12
  Autor: Sandro Miccoli

*/

#ifndef MATRIZ_H_
#define MATRIZ_H_

typedef struct Matriz{
    int col, lin;
    int ** matriz;
} Matriz;

void criaMatriz(int col, int lin, Matriz *matriz);

int ** mallocaMatriz(int col, int lin);

void destroiMatriz(Matriz *matriz);

#endif /* MATRIZ_H_ */
