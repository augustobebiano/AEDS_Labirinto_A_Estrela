#ifndef PILHA_H 
#define PILHA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "matriz.h"

#define MAXTAM 50

typedef struct Pitem{
	int l;
	int c;
}Pitem;

typedef struct Pilha{
	Pitem vet[MAXTAM];
	int top;
	int base;
}Pilha;

void FPVazia(Pilha *p);
void PUSH(Pilha *p, Pitem d);
void POP(Pilha *p, Pitem *d);
void DFS(Pilha *l, Matriz *m);

#endif