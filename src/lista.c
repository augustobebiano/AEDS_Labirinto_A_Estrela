#include "lista.h"

void FLVazia(Lista *l){
	l->first = 0;
	l->last  = 0;
}

void LInsert(Lista *l, Item d, Matriz *m, int n){
	if (l->last >= MAXLIST){
		printf("LISTA CHEIA!\n");
	}else{
		l->vet[l->last] = d;
		if(n == 1){
			Manhattan(l, m);
		}else{
			Euclidean(l, m);
		}
		LSort(l);
		l->last ++;
	}
}

void LRemove(Lista *l){
	if(l->first == l->last){
		printf("LISTA VAZIA!\n");
	}else{
		l->first++;
	}
}

void LSort(Lista *l){
	Item pos;
	pos.l = 0;
	pos.c = 0;
	pos.f = 0;
	for(int x = l->first+1; x < l->last; x++) {
        for(int y = l->first+1; y < l->last; y++) {
			if(l->vet[y].f>l->vet[y+1].f){
				pos = l->vet[y];
				l->vet[y] = l->vet[y+1];
				l->vet[y+1] = pos;
			}
		}
	}
}

void LImprime(Lista *l){
	printf("\n");
	for(int i=l->first; i<l->last; i++){
		printf("(%d,%d)\t", l->vet[i].l, l->vet[i].c);
	}
	printf("\n\n");
}

void Manhattan(Lista *l, Matriz *m){
	l->vet[l->last].f = abs((l->vet[l->last].l) - (m->rows-1)) + abs((l->vet[l->last].c) - (m->cols-1));
}

void Euclidean(Lista *l, Matriz *m){
	l->vet[l->last].f = sqrt(pow(((l->vet[l->last].l) - (m->rows-1)), 2) + pow(((l->vet[l->last].c) - (m->cols-1)), 2));
}

void AEstrela(Lista *l, Matriz *m, int n){
	Item pos;
	pos.l = 0;
	pos.c = 0;
	pos.f = 0;
	LInsert(l, pos, m, n);
	int cont2 = l->first+1;
	m->vis[pos.l][pos.c] = cont2;
	cont2++;
	while(l->vet[l->first].f != 0 && l->first < l->last){
		if((l->vet[l->first].l)+1 < m->rows && m->data[(l->vet[l->first].l)+1][l->vet[l->first].c] != -1 && m->vis[l->vet[l->first].l+1][l->vet[l->first].c] == -1){
			pos.l = l->vet[l->first].l+1;
			pos.c = l->vet[l->first].c;
			LInsert(l, pos, m, n);
			m->vis[pos.l][pos.c] = cont2;
			cont2++;
		}
		if(l->vet[l->first].c+1 < m->cols && m->data[l->vet[l->first].l][l->vet[l->first].c+1] != -1 && m->vis[l->vet[l->first].l][l->vet[l->first].c+1] == -1){
			pos.l = l->vet[l->first].l;
			pos.c = l->vet[l->first].c+1;
			LInsert(l, pos, m, n);
			m->vis[pos.l][pos.c] = cont2;
			cont2++;
		}
		if(l->vet[l->first].c-1 >= 0 && m->data[l->vet[l->first].l][l->vet[l->first].c-1] != -1 && m->vis[l->vet[l->first].l][l->vet[l->first].c-1] == -1){
			pos.l = l->vet[l->first].l;
			pos.c = l->vet[l->first].c-1;
			LInsert(l, pos, m, n);
			m->vis[pos.l][pos.c] = cont2;
			cont2++;
		}
		if((l->vet[l->first].l)-1 >= 0 && m->data[(l->vet[l->first].l)-1][l->vet[l->first].c] != -1 && m->vis[l->vet[l->first].l-1][l->vet[l->first].c] == -1){
			pos.l = l->vet[l->first].l-1;
			pos.c = l->vet[l->first].c;
			LInsert(l, pos, m, n);
			m->vis[pos.l][pos.c] = cont2;
			cont2++;
		}
		LRemove(l);
	}
	if(l->vet[l->first].l == m->rows-1 && l->vet[l->first].c == m->cols-1){
		if(n == 1){
			printf("\nHeurística de Manhattan: \n");
		}else{
			printf("\nHeurística Euclidiana: \n");
		}
		print_matriz(m);
		printf("Número de interações: %d\n", cont2-1);
	}else{
		print_matriz(m);
		printf("Obstáculo no caminho, impossível chegar ao fim.\n");
	}
}


