#include "pilha.h"


void FPVazia(Pilha *p){
	p->top   = 0;
	p->base  = 0;
}


void PUSH(Pilha *p, Pitem d){
	if (p->top >= MAXTAM){
		printf("PILHA CHEIA!\n");
	}else{
		p->vet[p->top] = d;
		p->top ++;
	}
}

void POP(Pilha *p, Pitem *d){
	if(p->base == p->top)
		printf("PILHA VAZIA!\n");
	else{
		p->top --;
		*d = p->vet[p->top-1];
	}
}

void DFS(Pilha *p, Matriz *m){
	Pitem aux;
	aux.l = 0;
	aux.c = 0;
	int i=p->base, j=p->base, obs=0;
    int count2=p->base+1;
	PUSH(p, aux);
	m->vis[aux.l][aux.c] = count2;
	while((i != m->rows-1 || j != m->cols-1) && obs==0){
		if (i == 0){
			if((i == 0 && j == 0) && ((m->data[i+1][j] == -1 || m->vis[i+1][j] != -1) && (m->data[i][j+1] == -1 || m->vis[i][j+1] != -1))){
				obs = 1;
			}else{
				if(m->data[(i)+1][j] != -1 && m->vis[i+1][j] == -1){
					i++;
					aux.l = i;	
					aux.c = j;
					PUSH(p, aux);
					count2++;
					m->vis[aux.l][aux.c] = count2;
				}else if(j < m->cols-1 && m->data[i][j+1] != -1 && m->vis[i][j+1] == -1){
					j++;
					aux.l = i;	
					aux.c = j;
					PUSH(p, aux);
					count2++;
					m->vis[aux.l][aux.c] = count2;
				}else if(m->data[i][j-1] != -1 && m->vis[i][j-1] == -1){
					j--;
					aux.l = i;	
					aux.c = j;
					PUSH(p, aux);
					count2++;
					m->vis[aux.l][aux.c] = count2;
				}else{
					POP(p, &aux);
					i = aux.l;	
					j = aux.c;
				}
			}
		}
		else if (j == 0){
			if(i < m->rows-1 && m->data[(i)+1][j] != -1 && m->vis[i+1][j] == -1){
				i++;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				count2++;
				m->vis[aux.l][aux.c] = count2;
			}else{
				if(m->data[i][j+1] != -1 && m->vis[i][j+1] == -1){
					j++;
					aux.l = i;	
					aux.c = j;
					PUSH(p, aux);
					count2++;
					m->vis[aux.l][aux.c] = count2;
				}else{
					if(m->data[i-1][j] != -1 && m->vis[i-1][j] == -1){
						i--;
						aux.l = i;	
						aux.c = j;
						PUSH(p, aux);
						count2++;
						m->vis[aux.l][aux.c] = count2;
					}else{
						POP(p, &aux);
						i = aux.l;	
						j = aux.c;
					}
				}
			}
		}else if(i != m->rows-1 && j == m->cols-1){
			if(i < m->rows-1 && m->data[i+1][j] != -1 && m->vis[i+1][j] == -1){
				i++;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				count2++;
				m->vis[aux.l][aux.c] = count2;
			}else{
				if(i < m->rows-1 && m->data[i][j-1] != -1 && m->vis[i][j-1] == -1){
					j--;
					aux.l = i;	
					aux.c = j;
					PUSH(p, aux);
					m->vis[aux.l][aux.c] = count2;
					count2++;
				}else{
					POP(p, &aux);
					i = aux.l;	
					j = aux.c;
				}
			}
		}else{
			if(i < m->rows-1 && m->data[i+1][j] != -1 && m->vis[i+1][j] == -1){
				i++;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				count2++;
				m->vis[aux.l][aux.c] = count2;
			}else if(m->data[i][j+1] != -1 && m->vis[i][j+1] == -1){
				j++;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				count2++;
				m->vis[aux.l][aux.c] = count2;
			}else if(m->data[i][j-1] != -1 && m->vis[i][j-1] == -1){
				j--;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				count2++;
				m->vis[aux.l][aux.c] = count2;
			}else if(m->data[i-1][j] != -1 && (m->vis[i-1][j] == -1 && i != 0)){
				i--;
				aux.l = i;	
				aux.c = j;
				PUSH(p, aux);
				count2++;
				m->vis[aux.l][aux.c] = count2;
			}else{
				POP(p, &aux);
				i = aux.l;	
				j = aux.c;
			}
		}
	}
	if(i == m->rows-1 && j == m->cols-1){
		printf("\nDFS: \n");
		print_matriz(m);
		printf("Numero de interacoes: %d\n", count2);
	}else{
		printf("Obstaculo no caminho, impossivel chegar ao fim.\n");
	}
}