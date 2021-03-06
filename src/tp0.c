/*
*	Produto de Kronecker
*		Autor: Lucas Silvestre (2010054665)
*		Data: 17/09/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(int argc, char *argv[]) {
	// Declara as variáveis
	char * inputFileName = argv[1];
	char * outputFileName = argv[2];
	int ** matrizA, ** matrizB, ** matrizResult;
	int numInstancias, numLinhasA, numLinhasB, numLinhasResult, numColunasA, numColunasB, numColunasResult, i, j, k, l, m;

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
	fscanf(inputFileOpen, "%d", &numInstancias);
	// Escreve o número de instâncias no arquivo de saída
	fprintf(outputFileOpen, "%d\n", numInstancias);

	for(m = 0; m < numInstancias; m++) {
		// Lê linhas e colunas da matriz A
		fscanf(inputFileOpen, "%d", &numLinhasA);
		fscanf(inputFileOpen, "%d", &numColunasA);	

		// Preenche a matriz A
		matrizA = preenche_matriz(inputFileOpen, numLinhasA, numColunasA);

		// Lê linhas e colunas da matriz B
		fscanf(inputFileOpen, "%d", &numLinhasB);
		fscanf(inputFileOpen, "%d", &numColunasB);

		// Preenche a matriz B
		matrizB = preenche_matriz(inputFileOpen, numLinhasB, numColunasB);

		// Seta linhas e colunas da matriz resultante
		numLinhasResult = numLinhasA * numLinhasB;
		numColunasResult = numColunasA * numColunasB;

		// Aloca a matriz resultante
		matrizResult = aloca_matriz(numLinhasResult, numColunasResult);

		// Preenche a matriz resultante (Produto de Kronecker)
		for (i = 0; i < numLinhasA; ++i) {
			for (j = 0; j < numColunasA; ++j) {
				for (k = 0; k < numLinhasB; ++k) {
					for (l = 0; l < numColunasB; ++l) {
						matrizResult[i * numLinhasB + k][j * numColunasB + l] = matrizA[i][j] * matrizB[k][l];
					}
				}
			}
		}

		// Libera as matrizes já utilizadas
		desaloca_matriz(matrizA, numLinhasA);
		desaloca_matriz(matrizB, numLinhasB);
		
		// Escreve o número de linhas e colunas no arquivo de saída
		fprintf(outputFileOpen, "%d ", numLinhasResult);
		fprintf(outputFileOpen, "%d\n", numColunasResult);

		// Escreve a matriz resultante no arquivo de saída
		for(i = 0; i < numLinhasResult; i++) {
			for(j = 0; j < numColunasResult; j++) {
				fprintf(outputFileOpen,"%d ", matrizResult[i][j]);
			}
			fprintf(outputFileOpen, "\n");
		}

		// Libera a matriz resultante
		desaloca_matriz(matrizResult, numLinhasResult);
	}

	// Retorna 0 se conseguiu fechar o arquivo com sucesso
	if(fclose(inputFileOpen) == 0) {
		printf("%s fechado com sucesso\n", inputFileName);
	}

	if(fclose(outputFileOpen) == 0) {
		printf("%s fechado com sucesso\n", outputFileName);
	}

	return 0;
}