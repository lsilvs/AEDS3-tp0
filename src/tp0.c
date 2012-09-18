/*
*	Produto de Kronecker
*		Autor: Lucas Silvestre (2010054665)
*		Data: 17/09/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

	char * inputFileName = "input.txt";
	char * outputFileName = "output.txt";
	int numMatrizes, numLinhas1, numLinhas2, numLinhasResult, numColunas1, numColunas2, numColunasResult, i, j, k, l, m;

	//Abrir arquivo de entrada
	FILE * inputFileOpen = NULL;
	if ((inputFileOpen = fopen(inputFileName, "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	} else {
		printf("Aberto arquivo de entrada %s \n", inputFileName);
	}

	//Abrir arquivo de saída
	FILE * outputFileOpen = NULL;
	if ((outputFileOpen = fopen(outputFileName, "w")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	} else {
		printf("Aberto arquivo de entrada %s \n", outputFileName);
	}

	fscanf(inputFileOpen, "%d", &numMatrizes);
	fprintf(outputFileOpen, "%d\n", numMatrizes);

	for(m = 0; m < numMatrizes; m++) {
		fscanf(inputFileOpen, "%d", &numLinhas1);
		fscanf(inputFileOpen, "%d", &numColunas1);

		int * vetor1 = (int *) malloc(numLinhas1 * numColunas1 * sizeof(int));

		for(i = 0; i < numLinhas1 * numColunas1; i++) {
			fscanf(inputFileOpen, "%d", &vetor1[i]);
		}

		fscanf(inputFileOpen, "%d", &numLinhas2);
		fscanf(inputFileOpen, "%d", &numColunas2);

		int * vetor2 = (int *) malloc(numLinhas2 * numColunas2 * sizeof(int));

		for(i = 0; i < numLinhas2 * numColunas2; i++) {
			fscanf(inputFileOpen, "%d", &vetor2[i]);
		}

		numLinhasResult = numLinhas1 * numLinhas2;
		numColunasResult = numColunas1 * numColunas2;

		fprintf(outputFileOpen, "%d ", numLinhasResult);
		fprintf(outputFileOpen, "%d\n", numColunasResult);

		
	}
	



	/* Allocate space for an array with ten elements of type int. */
	// int * vetor = (int *) malloc(n * sizeof(int));
	
	// free(vetor);
	
	// 	fprintf(file, "%s", value);

	// FEOF
	//retorna se é o fim do arquivo ou não
	//return feof(file);

	//retorna 0 se conseguiu fechar o arquivo com sucesso
	printf("Fechando arquivo...\n");
	printf("%d\n", fclose(inputFileOpen));
	printf("%d\n", fclose(outputFileOpen));
	return 0;

}