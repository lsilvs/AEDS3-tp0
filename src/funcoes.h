// .h

#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

// Aloca a matriz dinamicamente
int ** aloca_matriz(int linhas, int colunas);

int ** preenche_matriz(FILE *arquivo, int linhas, int colunas);

#endif