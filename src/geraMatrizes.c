/*
*	Produto de Kronecker
*		Autor: Lucas Silvestre (2010054665)
*		Data: 17/09/2012
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// Declara as variáveis
	char * inputFileName = argv[1];
	int linhas, colunas, i, j, inst;
	srand((unsigned)time(NULL));

	int instancias = 10;
	int maxLinhasDaMatriz = 8;
	int maxColunasDaMatriz = 8;
	int maxElementoDaMatriz = 10;

	// Abrir arquivo de saída
	FILE * inputFileOpen = NULL;
	if ((inputFileOpen = fopen(inputFileName, "w")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	} else {
		printf("Aberto arquivo de entrada %s \n", inputFileName);
	}

	fprintf(inputFileOpen, "%d\n", instancias);

	for (inst = 0; inst < instancias * 2; ++inst) {
		if(argc > 2) {
			linhas = atoi(argv[2]);
			colunas = atoi(argv[2]);
		} else {
			linhas = (rand() % maxLinhasDaMatriz)+1;
			colunas = (rand() % maxColunasDaMatriz)+1;
		}
		
		fprintf(inputFileOpen, "%d ", linhas);
		fprintf(inputFileOpen, "%d\n", colunas);

		for (i = 0; i < linhas; ++i) {
			for (j = 0; j < colunas; ++j) {
				fprintf(inputFileOpen, "%d ", rand() % maxElementoDaMatriz);
			}
			fprintf(inputFileOpen, "\n");
		}
	}

	fclose(inputFileOpen);
	return 0;
}