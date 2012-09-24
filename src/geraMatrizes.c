/*
*	Produto de Kronecker
*		Autor: Lucas Silvestre (2010054665)
*		Data: 17/09/2012
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// Declara as variáveis
	char * outputFileName = "input.txt";
	int instancias = 865, i, j, inst;
	srand((unsigned)time(NULL));

	// Abrir arquivo de saída
	FILE * outputFileOpen = NULL;
	if ((outputFileOpen = fopen(outputFileName, "w")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	} else {
		printf("Aberto arquivo de entrada %s \n", outputFileName);
	}

	fprintf(outputFileOpen, "%d\n", instancias);

	for (inst = 0; inst < instancias * 2; ++inst) {
		int linhas = (rand()%22)+1;
		int colunas = (rand()%22)+1;
		
		fprintf(outputFileOpen, "%d ", linhas);
		fprintf(outputFileOpen, "%d\n", colunas);

		for (i = 0; i < linhas; ++i) {
			for (j = 0; j < colunas; ++j) {
				fprintf(outputFileOpen, "%d ", rand()%10);
			}
			fprintf(outputFileOpen, "\n");
		}
	}

	fclose(outputFileOpen);
	return 0;
}