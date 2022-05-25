#ifndef LISTA_H 
#define LISTA_H

#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define MAXLIST 80

typedef struct Item{
	int l;
	int c;
	double f;
}Item;

typedef struct Lista{
	Item vet[MAXLIST];
	int first;
	int last;
}Lista;

void FLVazia(Lista *l);
void LInsert(Lista *l, Item d, Matriz *m, int n);
void LRemove(Lista *l);
void LSort(Lista *l);
void LImprime(Lista *l);
void Manhattan(Lista *l, Matriz *m);
void Euclidean(Lista *l, Matriz *m);
void AEstrela(Lista *l, Matriz *m, int n);

#endif