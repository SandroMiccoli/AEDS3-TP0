/*
  Módulo responsável por fazer o produto de Kronecker entre duas matrizes.

  Criação: 16/09/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include "kronecker.h"

void produtoKronecker (Matriz A, Matriz B, Matriz * matrizesResultado, int i){
    int m, n; // Dimensões matriz A
    int p, q; // DImensões matriz B

    int produto;

    m = A.col;
    n = A.lin;

    p = B.col;
    q = B.lin;

    int mp, nq;

    Matriz C;
    criaMatriz(m*p, n*q, &C);

    // Vasculha todas as linhas e colunas da matriz A
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){

            // Vasculha todas as linhas e colunas da matriz B
            for (int k = 0; k < p; k++){
                for (int l = 0; l < q; l++){

                    produto = A.matriz[i][j] * B.matriz[k][l];

                    mp = (p*i+k+1)-1; // Definição da posição alterada pois
                    nq = (q*j+l+1)-1; // aqui começamos de 00.

                    C.matriz[mp][nq] = produto;
                }
            }
        }
    }

    matrizesResultado[i] = C;


}
