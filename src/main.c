#include "lista.h"

int main(){
	FILE *myfile = fopen ("gameconfig.txt", "r");
	Matriz *m = TokenizerM(myfile);
	printf("Matriz Inicial: \n");
	print_matriz(m);
	Inicial(m);

	return 0;
}
