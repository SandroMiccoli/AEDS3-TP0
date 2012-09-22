#!/usr/bin/python
# -*- coding: latin-1 -*-

import sys,os,random

ent = 'entrada/'
sai = 'saida/'
tempo = 'tempo/'
script = './testes/entrada.py '
arqAppend = ' >> '
arqNew = ' > '


for i in range(20):
	i+=1
	i*=5
	teste = script+' 1 '+str(i)+' '+str(i)+' '
	arqEnt= 'ent'+str(i)+'.txt'
	arqSai= 'sai'+str(i)+'.txt'
	arqTmp= 'tmp'+str(i)+'.txt'
	os.system(teste+arqNew+ent+arqEnt)
	os.system('./tp0 '+arqEnt+' '+arqSai)
	os.system('/usr/bin/./time -o '+tempo+arqTmp+' ./tp0 '+arqEnt+' '+arqSai)
os.system('ls '+ent)
