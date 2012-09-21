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

		int ** matrizA = (int **) malloc(numLinhas1 * sizeof(int *));

		for(i = 0; i < numLinhas1; i++) {
			matrizA[i] = (int *) malloc(numColunas1 * sizeof(int));
		}	

		for(i = 0; i < numLinhas1; i++) {
			for(j = 0; j < numColunas1; j++) {
				fscanf(inputFileOpen, "%d", &matrizA[i][j]);
			}
		}

		fscanf(inputFileOpen, "%d", &numLinhas2);
		fscanf(inputFileOpen, "%d", &numColunas2);

		int ** matrizB = (int **) malloc(numLinhas2 * sizeof(int *));

		for(i = 0; i < numLinhas2; i++) {
			matrizB[i] = (int *) malloc(numColunas2 * sizeof(int));
		}	

		for(i = 0; i < numLinhas2; i++) {
			for(j = 0; j < numColunas2; j++) {
				fscanf(inputFileOpen, "%d", &matrizB[i][j]);
			}
		}

		int ** matrizResult = (int **) malloc(numLinhas1 * numLinhas2 * sizeof(int *));

		for(i = 0; i < numLinhas1 * numLinhas2; i++) {
			matrizResult[i] = (int *) malloc(numColunas1 * numColunas2 * sizeof(int));
		}

		for (i = 0; i < numLinhas1; ++i) {
			for (j = 0; j < numColunas1; ++j) {
				for (k = 0; k < numLinhas2; ++k) {
					for (l = 0; l < numColunas2; ++l) {
						matrizResult[i * numLinhas2 + k][j * numColunas2 + l] = matrizA[i][j] * matrizB[k][l];
						// printf("%s\n", matrizA[i][j] * matrizB[k][l]);
					}
				}
			}
		}


		// Imprime a matriz
		for(i = 0; i < numLinhas1 * numLinhas2; i++) {
			for(j = 0; j < numColunas1 *numColunas2; j++) {
				printf("%d ", matrizResult[i][j]);
			}
			printf("\n");
		}

		// numLinhasResult = numLinhas1 * numLinhas2;
		// numColunasResult = numColunas1 * numColunas2;

		// fprintf(outputFileOpen, "%d ", numLinhasResult);
		// fprintf(outputFileOpen, "%d\n", numColunasResult);

		// for (i = 0; i < numColunas1; i++) {
		// 	for (j = 0; j < numColunas2; j++) {
		// 		fprintf(outputFileOpen, "%d ", matrizA[i] * matrizB[j]);
		// 	}
		// }

		// fprintf(outputFileOpen, "\n");

		// for (i = 0; i < numColunas1; i++) {
		// 	for (j; j < numColunasResult; j++) {
		// 		fprintf(outputFileOpen, "%d ", matrizA[i] * matrizB[j]);
		// 	}
		// }

		fprintf(outputFileOpen, "\n");
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