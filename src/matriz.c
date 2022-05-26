#include "fila.h"
#include "pilha.h"
#include "matriz.h"

Matriz* criar_matriz(int rows, int cols){
    struct Matriz* matriz = malloc(sizeof(Matriz));
    matriz->rows = rows;
    matriz->cols = cols;
    int** data = malloc(sizeof(int*) * rows);
    int** vis = malloc(sizeof(int*) * rows); 
    for(int i = 0; i < rows; i++){
        data[i] = calloc(cols, sizeof(int));
        vis[i] = calloc(cols, sizeof(int));
    }
    matriz->data = data;
    matriz->vis = vis;
    return matriz;
}

Matriz* preenche_matriz(int rows, int cols) {
    struct Matriz *matriz = criar_matriz(rows, cols);
    for(int x = 0; x < rows; x++) {
        for(int y = 0; y < cols; y++) {
            matriz->data[x][y] = 0;
            matriz->vis[x][y] = -1;
        }
    }
    return matriz;    
}

void print_matriz(Matriz* m){
    for(int x = 0; x < m->rows; x++) {
        for(int y = 0; y < m->cols; y++) {
            if(m->vis[x][y] == -1){
                if(m->data[x][y]==0){
                    printf("O\t");
                }else{
                    printf("X\t");
                }
            }else{
                printf("%d\t", m->vis[x][y]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

Matriz* TokenizerM(FILE *ptr){
    char buff[MAXC] = "";
	char *token = NULL;
	const char *delim = " x[,]";
    int y = 0, cols = 0, rows = 0, counter = 0, x = 0;
    int auxl[60];
    int auxc[60];
    for(int i=0;i<60;i++){ auxl[i] = 0; auxc[i] = 0;}
    int l = 0, c = 0;

  

    if (!ptr){
		perror ("Abertura do arquivo falhou\n");
	}

	while(fgets(buff, MAXC, ptr) != NULL){
		size_t len = strlen(buff);
		if (len == MAXC - 1 && buff[len-1] != '\n'){
			fputs ("Erro: linha muito longa.\n", stderr);
		}
        if (counter == 0){
            for (token = strtok(buff, delim); token; token = strtok(NULL, delim)){
                if(y == 0){
                    rows = atoi(token);
                }
                if(y == 1){
                    cols = atoi(token);
                }
            y++;
            }
        }
        if(counter == 1){
            for (token = strtok(buff, delim); token; token = strtok(NULL, delim)){ 
                if(x % 2 == 0 || x==0){
                    auxl[l] = atoi(token);
                    l++;
                }else{
                    auxc[c] = atoi(token);
                    c++; 
                }
                x++;
		    }
        }
        counter++;
    }
	fclose (ptr);
    Matriz* m1 = preenche_matriz(rows, cols);
    //preencher obstaculos
    counter = 0;
    c = 0;
    l = 0;
    for(int i = 0; i<x/2;i++){
        m1->data[auxl[l]][auxc[c]] = -1;
        l++;
        c++;
    }
    //
    printf("\n\n");
    return m1;
}

void TipoCaminho(Matriz *m){
    int t = 0, n = 0;
    Pilha *p = malloc(sizeof(Pilha));
    Fila *l = malloc(sizeof(Fila));
    while(t!=1 && t!=2 && t!=3){
        printf("Defina o método a ser utilizado para percorrer a matriz (1 para DFS, 2 para BFS e 3 para A*): ");
		scanf("%d", &t);
        switch(t){
            case 1:
                FPVazia(p);
                DFS(p, m);
                break;
            case 2:
                FFVazia(l);
                BFS(l, m, n);
                break;
            case 3:
                while(n!=1 && n!=2){
                    printf("Defina a heurística a ser utilizada (1 para Manhattan e 2 para Euclidiana): ");
                    scanf("%d", &n);
                    if(n!=1 && n!=2){
                        printf("Número inválido.\n");
                    }
                }
                FFVazia(l);
                BFS(l, m, n);
                break;
            default:
                printf("Método inválido. ");
                break;
        }
    }
}