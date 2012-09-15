#!/usr/bin/python
# -*- coding: latin-1 -*-
'''
Arquivo gerador de matrizes.

A seguir uma explicação de como será a saída do script, que será usado como entrada no TP0:

A primeira linha do arquivo consiste no número k de instâncias (pares de matrizes) que o arquivo contém.

A linha seguinte contém as dimenções m e n da matriz A1. As m próximas linhas contém os elementos de cada linha de A1 separados por um espaço. E assim por diante.

Um exemplo:

2   -----> k
1 3 -----> m n
4 0 1
2 2 -----> m n
3 2
0 5
3 3 -----> m n
1 0 0
0 1 0
0 0 1
2 1 -----> m n
1
1

argv[0] = nome do arquivo
argv[1] = pares de matrizes

'''

import random
import sys

#print random.randint(0,50)

k = int(sys.argv[1]) # pares de matrizes

print k

for i in range(k)*2: # Multiplica por 2 pois são pares
    m = random.randint(1,4)
    n = random.randint(1,4)
    print m,n
    for j in range(m):
        for l in range(n):
            print random.randint(0,9),
        print ''
















