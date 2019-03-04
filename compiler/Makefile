FLAGS = -g -O
EXEC = aol

#Clean up the LEX/YACC compiler files, compile the AOL Compiler, then run the
#aol compiler with the contents of the file TestData as input.

clean:
	rm -f $(EXEC) \
	aol.tab.c aol.tab.h aol.lex.c \
    *.abc

aol:	aol.l aol.y aol.h aolfuncs.c
		bison -d aol.y && \
		flex -o aol.lex.c aol.l && \
		cc $(FLAGS) -o $@ aol.tab.c aol.lex.c aolfuncs.c -lm

cleanmake:	clean aol
