/*
*	Produto de Kronecker
*		Autor: Lucas Silvestre (2010054665)
*		Data: 17/09/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

	char * inputFile = "input.txt";
	char * outputFile = "output.txt";
	int numMatrizes, numLinhas, numColunas;

	//Ler arquivo de entrada
	FILE * filePointer = NULL;
	if ((filePointer = fopen(inputFile, "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	} else {
		printf("Aberto arquivo de entrada %s \n", inputFile);
	}

	fscanf(filePointer, "%d", &numMatrizes);


	fscanf(filePointer, "%d", &numLinhas);
	fscanf(filePointer, "%d", &numColunas);

	int * vetor = (int *) malloc(numLinhas * numColunas * sizeof(int));	

	int i;
	for(i = 0; i < numLinhas * numColunas; i++) {
		//for(int j = 0, j < numColunas, j++) {
			fscanf(filePointer, "%d", &vetor[i]);
		// }
	}

	for(i = 0; i < numLinhas * numColunas; i++) {
		printf("%d\n", vetor[i]);
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
	printf("%d\n", fclose(filePointer));
	return 0;

}