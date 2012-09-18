# Compile/Link
GCC = gcc
OPTMIZE = -g3 -O3
LIBS = -lc 

#Objetos
OBJS =  src/tp0.c
# Nome do aplicativo
APPNAME = tp0
#valgrind
VALGRIND = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes
#arquivos de exemplo
INPUTFILE = input.txt
OUTPUTFILE = output.txt

release : ; $(GCC) $(OPTMIZE) $(LIBS) $(OBJS) -o $(APPNAME)

clean :
	rm -f $(APPNAME) $(OUTPUTFILE)

run :
	make
	./$(APPNAME) $(INPUTFILE)

analysis:
	make
	$(VALGRIND) ./$(APPNAME) $(INPUTFILE)
