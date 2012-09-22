/*
*	Produto de Kronecker
*		Autor: Lucas Silvestre (2010054665)
*		Data: 17/09/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	// Declara as variáveis
	char * inputFileName = "input2.txt";
	char * outputFileName = "output.txt";
	int numMatrizes, numLinhas1, numLinhas2, numLinhasResult, numColunas1, numColunas2, numColunasResult, i, j, k, l, m;

	// Abrir arquivo de entrada
	FILE * inputFileOpen = NULL;
	if ((inputFileOpen = fopen(inputFileName, "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	} else {
		printf("Aberto arquivo de entrada %s \n", inputFileName);
	}

	// Abrir arquivo de saída
	FILE * outputFileOpen = NULL;
	if ((outputFileOpen = fopen(outputFileName, "w")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	} else {
		printf("Aberto arquivo de entrada %s \n", outputFileName);
	}

	// Lê o número de instâncias
	fscanf(inputFileOpen, "%d", &numMatrizes);
	// Escreve o número de instâncias no arquivo de saída
	fprintf(outputFileOpen, "%d\n", numMatrizes);

	for(m = 0; m < numMatrizes; m++) {
		// Lê linhas e colunas da matriz
		fscanf(inputFileOpen, "%d", &numLinhas1);
		fscanf(inputFileOpen, "%d", &numColunas1);

		// Aloca a matriz
		int ** matrizA = (int **) malloc(numLinhas1 * sizeof(int *));
		for(i = 0; i < numLinhas1; i++) {
			matrizA[i] = (int *) malloc(numColunas1 * sizeof(int));
		}

		// Preenche a matriz
		for(i = 0; i < numLinhas1; i++) {
			for(j = 0; j < numColunas1; j++) {
				fscanf(inputFileOpen, "%d", &matrizA[i][j]);
			}
		}

		// Lê linhas e colunas da matriz
		fscanf(inputFileOpen, "%d", &numLinhas2);
		fscanf(inputFileOpen, "%d", &numColunas2);

		// Aloca a matriz
		int ** matrizB = (int **) malloc(numLinhas2 * sizeof(int *));
		for(i = 0; i < numLinhas2; i++) {
			matrizB[i] = (int *) malloc(numColunas2 * sizeof(int));
		}

		// Preenche a matriz
		for(i = 0; i < numLinhas2; i++) {
			for(j = 0; j < numColunas2; j++) {
				fscanf(inputFileOpen, "%d", &matrizB[i][j]);
			}
		}

		// Aloca a matriz
		int ** matrizResult = (int **) malloc(numLinhas1 * numLinhas2 * sizeof(int *));
		for(i = 0; i < numLinhas1 * numLinhas2; i++) {
			matrizResult[i] = (int *) malloc(numColunas1 * numColunas2 * sizeof(int));
		}

		// Preenche a matriz
		for (i = 0; i < numLinhas1; ++i) {
			for (j = 0; j < numColunas1; ++j) {
				for (k = 0; k < numLinhas2; ++k) {
					for (l = 0; l < numColunas2; ++l) {
						matrizResult[i * numLinhas2 + k][j * numColunas2 + l] = matrizA[i][j] * matrizB[k][l];
					}
				}
			}
		}

		// Libera as matrizes não utilizadas
		for(i = 0; i < numLinhas1; i++) {
			free(matrizA[i]);
		}
		free(matrizA);

		for(i = 0; i < numLinhas2; i++) {
			free(matrizB[i]);
		}
		free(matrizB);

		numLinhasResult = numLinhas1 * numLinhas2;
		numColunasResult = numColunas1 * numColunas2;

		// Escreve o número de linhas e colunas no arquivo de saída
		fprintf(outputFileOpen, "%d ", numLinhasResult);
		fprintf(outputFileOpen, "%d\n", numColunasResult);

		// Escreve a matriz no arquivo de saída
		for(i = 0; i < numLinhas1 * numLinhas2; i++) {
			for(j = 0; j < numColunas1 *numColunas2; j++) {
				fprintf(outputFileOpen,"%d ", matrizResult[i][j]);
			}
			fprintf(outputFileOpen, "\n");
		}

		// Libera a matriz
		for(i = 0; i < numLinhas1 * numLinhas2; i++) {
			free(matrizResult[i]);
		}
		free(matrizResult);
	}

	//retorna 0 se conseguiu fechar o arquivo com sucesso
	printf("Fechando os arquivos...\n");
	printf("%d\n", fclose(inputFileOpen));
	printf("%d\n", fclose(outputFileOpen));
	return 0;
}