#ifndef MATRIZ_H 
#define MATRIZ_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAXC 1024

typedef struct SearchType{
    char searchtype[20];
}SearchType;


struct Matriz {
    int rows;
    int cols;
    int** data;
    int** vis;
};
typedef struct Matriz Matriz;

Matriz* criar_matriz(int rows, int cols);
Matriz* preenche_matriz(int rows, int cols);
void print_matriz(Matriz* m);
Matriz* TokenizerM(FILE *ptr);
void TipoCaminho(Matriz *m);

 

#endif