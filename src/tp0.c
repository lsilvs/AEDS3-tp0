// .c

#include <stdio.h>
#include <stdlib.h>

#include "tp0.h"

int **aloca_matriz(int linhas, int colunas) {
	// // Aloca a matriz
	int **matriz = (int **) malloc(linhas * sizeof(int *));
	int i;
	for(i = 0; i < linhas; i++) {
		matriz[i] = (int*)malloc(colunas*sizeof(int));	
	}
	return matriz;
}

int **preenche_matriz(FILE *arquivo, int linhas, int colunas) {
	// Aloca a matriz
	int **matriz = alocaMatriz(linhas, colunas);
	int i, j;

	// Preenche a matriz
	for(i = 0; i < linhas; i++) {
		for(j = 0; j < colunas; j++) {
			fscanf(arquivo, "%d", &matriz[i][j]);
		}
	}
	return matriz;
}