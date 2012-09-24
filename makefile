# Compile/Link
GCC = gcc
OPTMIZE = -g3 -O3
LIBS = -lc

#Objetos
OBJS =  src/tp0.c src/funcoes.c

# Nome do aplicativo
APPNAME = tp0

#valgrind
VALGRIND = valgrind --tool=memcheck
# --leak-check=yes --show-reachable=yes

#arquivos
INPUTFILE = input.txt
OUTPUTFILE = output.txt
GERAMATRIZES = src/geraMatrizes.c

release: ; $(GCC) $(OPTMIZE) $(LIBS) $(OBJS) -o $(APPNAME)

clean:
	rm -f $(APPNAME) $(INPUTFILE) geraMatrizes

run:
	gcc $(GERAMATRIZES) -o geraMatrizes
	./geraMatrizes
	make
	./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)

analysis:
	make
	$(VALGRIND) ./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)