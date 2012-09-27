#!/usr/bin/python
# -*- coding: latin-1 -*-

import sys,os,random

ent = 'entrada/'
sai = 'saida/'
tempo = 'tempo/'
script = './testes/entrada.py '
arqAppend = ' >> '
arqNew = ' > '


for i in range(200):
	i+=1
	i*=5
	#teste1 = script+' 1 '+str(i)+' '+str(i)+' ' # Matrizes quadradas
	#teste2 = script+' 1 10 '+str(i) # linhas fixas em 10
	#teste3 = script+' 1 '+str(i)+' 10' # colunas fixas em 10
	teste = script+' '+str(i)+' 50 50' # linhas e colunas fixas em 50 + nº de instâncias variando
	arqEnt= 'ent'+str(i)+'.txt'
	arqSai= 'sai'+str(i)+'.txt'
	arqTmp= 'tmp'+str(i)+'.txt'
	os.system(teste+arqNew+ent+arqEnt)
	#os.system('./tp0 '+arqEnt+' '+arqSai)
	os.system('/usr/bin/./time -o '+tempo+arqTmp+' ./tp0 '+arqEnt+' '+arqSai)

os.system('ls '+ent)
os.system('ls '+sai)
os.system('ls '+tempo)
