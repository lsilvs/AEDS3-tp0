/*
*	Produto de Kronecker
*		Autor: Lucas Silvestre (2010054665)
*		Data: 17/09/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include "tp0.h"

int main(int argc, char *argv[]) {
	// Declara as variáveis
	char *inputFileName = argv[1]; // "input.txt";
	char *outputFileName = argv[2]; // "output.txt";
	int **matrizA, **matrizB, **matrizResult;
	int numMatrizes, numLinhas1, numLinhas2, numLinhasResult, numColunas1, numColunas2, numColunasResult, i, j, k, l, m;

	// Abrir arquivo de entrada
	FILE * inputFileOpen;
	if ((inputFileOpen = fopen(inputFileName, "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	} else {
		printf("Aberto arquivo de entrada %s \n", inputFileName);
	}

	// Abrir arquivo de saída
	FILE * outputFileOpen;
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

		// Preenche a matriz A
		matrizA = preenche_matriz(inputFileOpen, numLinhas1, numColunas1);

		// Lê linhas e colunas da matriz
		fscanf(inputFileOpen, "%d", &numLinhas2);
		fscanf(inputFileOpen, "%d", &numColunas2);

		// Preenche a matriz B
		matrizB = preenche_matriz(inputFileOpen, numLinhas2, numColunas2);

		numLinhasResult = numLinhas1 * numLinhas2;
		numColunasResult = numColunas1 * numColunas2;

		// Aloca a matriz resultante
		matrizResult = aloca_matriz(numLinhasResult, numColunasResult);

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

		// Escreve o número de linhas e colunas no arquivo de saída
		fprintf(outputFileOpen, "%d ", numLinhasResult);
		fprintf(outputFileOpen, "%d\n", numColunasResult);

		// Escreve a matriz no arquivo de saída
		for(i = 0; i < numLinhasResult; i++) {
			for(j = 0; j < numColunasResult; j++) {
				fprintf(outputFileOpen,"%d ", matrizResult[i][j]);
			}
			fprintf(outputFileOpen, "\n");
		}

		// Libera a matriz
		for(i = 0; i < numLinhasResult; i++) {
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