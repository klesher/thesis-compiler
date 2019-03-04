#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/bytecode.h"
#include "../common/oftenUsedDefines.h"

//***************File info********************/
#define INPUTFILEMODE  "r"
#define OUTPUTFILEMODE "w"


//The number of spaces each tag nesting should be indented in the output
#define SPACESPERTAGDEPTH  2


void processCommandLineArgs(int argc, char* argv[]);
FILE* openFile(char* fileName, char* fileMode);

int processByteCodes(FILE* inputFile, FILE* outputFile);

char* parseAttributeList(FILE* inputFile);
char* attributeFromBytecode(char* bytecode, char* bytecodeType);

char* peekNextBytecodeAddress(FILE* inputFile, int addressNum);
char* peekNextBytecode(FILE* inputFile);
char* getAddress(char* bytecode, int addressNum);

char* createXMLStartTag(int* tagDepth, char* name, char* attributes);
char* createAttribute(char* name, char* value);
char* createXMLEndTag(int* tagDepth, char* name);

char* buildXMLTag(int numSpaces, char* prefix, char* name, char* attributes,
                  char* suffix);
