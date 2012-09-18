/*
*	Produto de Kronecker
*		Autor: Lucas Silvestre (2010054665)
*		Data: 17/09/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

	char * fileName = "input.txt";

	//Ler arquivo de entrada
	FILE * filePointer = NULL;
	if ((filePointer = fopen(fileName, "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	} else {
		printf("Aberto arquivo de entrada %s \n", fileName);
	}


	unsigned int stringSize = INITIAL_BUFFER_SIZE;
	char * string = (char*) malloc(stringSize);
	stringSize = getline(&string, &stringSize, file);

	String * newString = CreateString(string);
	free(string);
	return newString;

	// 	fprintf(file, "%s", value);

	// //Fechar
	// int IsEndOfFile(FILE * file) {
	// 	//retorna se é o fim do arquivo ou não
	// 	return feof(file);
	// }

	//retorna 0 se conseguiu fechar o arquivo com sucesso
	printf("Fechando arquivo...\n");
	printf("%d\n", fclose(filePointer));

}