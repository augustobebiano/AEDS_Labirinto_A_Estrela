#ifndef FILA_H 
#define FILA_H

#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define MAXLIST 100

typedef struct Item{
	int l;
	int c;
	double f;
}Item;

typedef struct Fila{
	Item vet[MAXLIST];
	int first;
	int last;
}Fila;

void FFVazia(Fila *l);
void Enfilera(Fila *l, Item d, Matriz *m, int n);
void Desenfilera(Fila *l);
void FSort(Fila *l);
void FImprime(Fila *l);
void Manhattan(Fila *l, Matriz *m);
void Euclidean(Fila *l, Matriz *m);
void BFS(Fila *l, Matriz *m, int n);

#endif