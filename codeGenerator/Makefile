FLAGS = -Wall
FILES = codeGenerator.c
EXEC = aolCodeGen

clean:
	rm -f $(EXEC) out.xml

aolCodeGen: $(FILES)
	cc $(FLAGS) -o $(EXEC) $(FILES)

cleanmake:     clean aolCodeGen
