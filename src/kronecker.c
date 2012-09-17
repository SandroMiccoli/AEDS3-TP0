/*
  Módulo responsável por fazer o produto de Kronecker entre duas matrizes.

  Criação: 16/09/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include "kronecker.h"

void produtoKronecker (Matriz A, Matriz B, Matriz * matrizes){
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

    //printf("m = %d, n = %d\n p = %d, q = %d\n",m,n,p,q);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < p; k++){
                for (int l = 0; l < q; l++){
                    //printf("_%d_\n", A.matriz[i][j] * B.matriz[k][l]);

                    produto = A.matriz[i][j] * B.matriz[k][l];
                    mp = (p*i+k+1)-1; // Definição da posição
                    nq = (q*j+l+1)-1;
                    //printf(" %d(%d-1)+%d = %d\n",p,i,k,mp);
                    //printf(" %d(%d-1)+%d = %d\n",q,j,l,nq);

                    C.matriz[mp][nq] = produto;
                }
                //printf("\n");
            }
        }
                //printf("\n");
    }

    imprimeMatriz(C);

    destroiMatriz(&C);

}
