/******************************************************************************/
/*   PURPOSE: Process bytecode which was created by the compiler.  The        */
/*            bytecode will be translated into another target language or     */
/*            markup.  In this case, it is translated into XML, but it would  */
/*            not be difficult to support other targets as well.  These       */
/*            bytecodes are assumed to be separated by a series of symbols    */
/*            indicated by BYTECODESEPARATOR.  This is to prevent incorrect   */
/*            tokenization of the bytecode at an unintended position because  */
/*            of a space or other common symbol.                              */
/******************************************************************************/
#include "codeGenerator.h"

int main(int argc, char* argv[])
{
    FILE* inputFile = NULL;
    FILE* outputFile = NULL;

    //Check the validity of the command line arguments
    processCommandLineArgs(argc, argv);

    //Open the input file for reading
    inputFile = openFile(argv[1], INPUTFILEMODE);
    //Open the output file for writing
    outputFile = openFile(argv[2], OUTPUTFILEMODE);
    processByteCodes(inputFile, outputFile);

    //Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

/******************************************************************************/
/*   Function name: int processCommandLineArgs(int argc, char* argv[])        */
/*                                                                            */
/*   Description:   Check the validity of the command line arguments          */
/*                                                                            */
/*   Parameters:    int argc     - The number of arguments passed             */
/*                                 from the command line.                     */
/*                  char *argv[] - A pointer to an array of character         */
/*                                 passed from the command line.              */
/*                                                                            */
/*   Return Value:  NONE                                                      */
/******************************************************************************/
void processCommandLineArgs(int argc, char* argv[])
{
    //TODO: ADD File extension checking
    if((argc != 3) || (argv[1] == NULL) || (argv[2] == NULL))
    {
        printf("Usage: %s <AOL Bytecode File [.abc]> <Output File [.xml]>\n",
               argv[0]);
        exit(EXIT_FAILURE);
    }
}

/******************************************************************************/
/*   Function name: FILE* openFile(char* fileName)                            */
/*                                                                            */
/*   Description:   Opens a file and checks it for errors                     */
/*                                                                            */
/*   Parameters:    char* - The file to be opened                             */
/*                  char* - The mode of the file to be opened                 */
/*                                                                            */
/*   Return Value:  FILE* - An open file to log information to.               */
/******************************************************************************/
FILE* openFile(char* fileName, char* fileMode)
{
    FILE* file = fopen(fileName, fileMode);
    if(file == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    return file;
}

/******************************************************************************/
/*   Function name: void processByteCodes(FILE* inputFile, FILE* outputFile)  */
/*                                                                            */
/*   Description:   Read bytecodes from a file and write the result to the    */
/*                  output file.                                              */
/*                                                                            */
/*   Parameters:    FILE* inputFile  - The file to read bytecodes from.       */
/*                  FILE* outputFile - The file to write the target output to.*/
/*                                                                            */
/*   Return Value:  0 on success, -1 on failure                               */
/******************************************************************************/
int processByteCodes(FILE* inputFile, FILE* outputFile)
{
    int tagDepth = 0;

    char* attributes = NULL;

    char currentLine[CHARSPERFILELINE] = "";
    char tempLine[CHARSPERFILELINE] = "";

    char* currentBytecodeType = NULL;
    char* currentBytecodeData = NULL;

    char* nextBytecodeType = NULL;

    if(!inputFile || !outputFile)
    {
        fprintf(stderr, "Input or outputfile is null in processByteCodes().");
        return FAILURE;
    }

    fprintf(outputFile, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    //*****************ENTER START STATE****************************************
    nextBytecodeType = peekNextBytecodeAddress(inputFile, 0);

    if(!nextBytecodeType)
    {
        fprintf(stderr, "Could not peek at first bytecode in input file.");
        return FAILURE;
    }

    //Found the bytecode expected to exit the start state
    if(strcmp(nextBytecodeType, TAG_START) == 0)
        currentBytecodeType = nextBytecodeType;
    else
    {
        fprintf(stderr, "Bad first bytecode[%s] in input file.\n",
        nextBytecodeType);
        return FAILURE;
    }
    //******************EXIT START STATE****************************************

    //Read through the whole file
    while(fgets (currentLine, CHARSPERFILELINE, inputFile) != (char *)0)
    {
        strcpy(tempLine, currentLine);
        currentBytecodeType = getAddress(tempLine, 0);

        nextBytecodeType = peekNextBytecodeAddress(inputFile, 0);

        //*********************TAG_START STATE**********************************
        if(strcmp(currentBytecodeType, TAG_START) == 0)
        {
            strcpy(tempLine, currentLine);
            currentBytecodeData = getAddress(tempLine, 1);
            //No attributes for this tag.  Output the tag now.
            if(strcmp(nextBytecodeType, TAG_START) == 0 || strcmp(nextBytecodeType, DATA) == 0 )
            {
               fprintf(outputFile, "%s\n", createXMLStartTag(&tagDepth, currentBytecodeData, NULL));
            }
            //There are attributes.  Grab all of them first before creating the
            //XML tag
            else if(strcmp(nextBytecodeType, ATTR_NAME) == 0)
            {
                attributes = parseAttributeList(inputFile);
                if(!attributes)
                {
                    fprintf(stderr, "Could not read attributes!\n");
                    return FAILURE;
                }

                fprintf(outputFile, "%s\n", createXMLStartTag(&tagDepth, currentBytecodeData, attributes));
                free(attributes);
            }
            else
            {
                fprintf(stderr, "Bad bytecode[%s] following a TAG_START tag.  ",
                        peekNextBytecode(inputFile));
                fprintf(stderr, "Expected TAG_START, DATA or ATTR_NAME.\n");
            }

        }
        //*********************DATA STATE***************************************
        else if(strcmp(currentBytecodeType, DATA) == 0)
        {
           //Data must always be followed by an ending tag
           if(strcmp(nextBytecodeType, TAG_END) == 0)
            {
               strcpy(tempLine, currentLine);
               currentBytecodeData = getAddress(tempLine, 1);
               fprintf(outputFile, "%s\n", buildXMLTag(tagDepth * SPACESPERTAGDEPTH, NULL, currentBytecodeData, NULL, NULL));
            }
            else
            {
                fprintf(stderr, "Bad bytecode[%s] following a DATA tag.  ",
                        peekNextBytecode(inputFile));
                fprintf(stderr, "Expected TAG_END.\n");
            }
        }
        //*********************TAG_END STATE************************************
        else if(strcmp(currentBytecodeType, TAG_END) == 0)
        {
            //***********FINISH STATE********
            if(nextBytecodeType == (char *)0 || strcmp(nextBytecodeType, TAG_START) == 0 || strcmp(nextBytecodeType, TAG_END) == 0)
            {
                strcpy(tempLine, currentLine);
                currentBytecodeData = getAddress(tempLine, 1);
                fprintf(outputFile, "%s\n", createXMLEndTag(&tagDepth, currentBytecodeData));
            }
            else
            {
                fprintf(stderr, "Bad bytecode[%s] following a TAG_END tag.  ",
                        peekNextBytecode(inputFile));
                fprintf(stderr, "Expected EOF, TAG_END or TAG_START.\n");
            }
        }

        currentBytecodeType = nextBytecodeType;
    }

    return SUCCESS;
}

char* parseAttributeList(FILE* inputFile)
{
    int attributeListSize = 0;

    char currentLine[CHARSPERFILELINE] = "";
    char tempLine[CHARSPERFILELINE] = "";

    char* currentAttribute = NULL;
    char* attributeList = NULL;

    char* tempAttributeList = NULL;

    char* attributeName = NULL;
    char* attributeValue = NULL;

    if(inputFile == NULL)
    {
        fprintf(stderr, "Invalid file passed to parseAttributeList.\n");
        return NULL;
    }
    while(fgets (currentLine, CHARSPERFILELINE, inputFile) != (char *)0)
    {
        attributeName = attributeFromBytecode(currentLine, ATTR_NAME);

        if(fgets (tempLine, CHARSPERFILELINE, inputFile) != (char *)0)
            attributeValue = attributeFromBytecode(tempLine, ATTR_VALUE);
        else
        {
            fprintf(stderr, "Could not parse attribute value.\n");
            return NULL;
        }


        currentAttribute = createAttribute(attributeName, attributeValue);

        if(attributeList == NULL)
            attributeList = strdup(currentAttribute);
        else
        {


            tempAttributeList = strdup(attributeList);
            attributeListSize = strlen(attributeList) +
                                strlen(currentAttribute) + 2;

            attributeList = calloc(attributeListSize, sizeof(char));

            sprintf(attributeList, "%s %s", tempAttributeList, currentAttribute);
            free(tempAttributeList);
        }

        free(attributeName);
        free(attributeValue);
        free(currentAttribute);

        //Check if we should continue processing attributes
        currentAttribute = peekNextBytecodeAddress(inputFile, 0);

        if(strcmp(currentAttribute, ATTR_NAME) != 0)
            break;
    }

    tempAttributeList = strdup(attributeList);
    free(attributeList);
    attributeList = NULL;

    return tempAttributeList;
}

char* attributeFromBytecode(char* bytecode, char* bytecodeType)
{
    char* tempLine = NULL;

    char* readBytecodeType = NULL;

    tempLine = strdup(bytecode);
    readBytecodeType = getAddress(tempLine, 0);

    if(readBytecodeType != NULL && strcmp(readBytecodeType, bytecodeType) != 0)
    {
        fprintf(stderr, "attributeFromBytecode() expected to read an ");
        fprintf(stderr, "%s but read a %s.\n", bytecodeType, readBytecodeType);
        return NULL;
    }

    tempLine = strdup(bytecode);
    return getAddress(tempLine, 1);
}

char* peekNextBytecodeAddress(FILE* inputFile, int addressNum)
{
    char* byteCode = NULL;

    byteCode = peekNextBytecode(inputFile);

    return getAddress(byteCode, addressNum);
}


char* peekNextBytecode(FILE* inputFile)
{
    char* currentLine = NULL;

    currentLine = calloc(CHARSPERFILELINE+1, sizeof(char));

    if(!currentLine)
    {
        perror("peekNextBytecode buffer");
        return NULL;
    }

    //End of file reached
    if(fgets (currentLine, CHARSPERFILELINE, inputFile) == (char *)0)
        return NULL;

    // put read line into read stream
    fseek(inputFile, strlen(currentLine) * -1, SEEK_CUR);

    return currentLine;
}


char* createAttribute(char* name, char* value)
{
    char* attribute = NULL;

    if(name == NULL || value == NULL || strlen(name) <= 0 || strlen(value) <= 0)
        return NULL;

    if(-1 == asprintf(&attribute, "%s=\"%s\"", name, value))
        return NULL;

    return attribute;
}

char* getAddress(char* bytecode, int addressNum)
{
    int remainingAddresses = -1;
    char* tokenPtr = NULL;

    if(bytecode == NULL || addressNum < 0)
        return NULL;

    //This will pull the first "address" of the bytecode from the line.
    tokenPtr = strtok (bytecode, BYTECODESEPARATOR);

    if(!tokenPtr)
        return NULL;
    //We want the first address, and this is it.
    else if(addressNum == 0)
        return strdup(tokenPtr);
    //We want an address greater than the first
    else
    {
        //Account for the token we already removed
        remainingAddresses = addressNum;

        while(remainingAddresses > 0)
        {
            //Get the bytecode's value
            tokenPtr = strtok (NULL, BYTECODESEPARATOR);

            if(!tokenPtr)
                return NULL;

            --remainingAddresses;
        }


        return strdup(tokenPtr);
    }
}

/******************************************************************************/
/*   Function name: char* createXMLStartTag(int* tagDepth, char* name,        */
/*                                          char* attributes)                 */
/*                                                                            */
/*   Description:   Create an XML starting tag with name as its node name.    */
/*                                                                            */
/*   Parameters:    int* tagDepth - How many tags are currently nested within */
/*                                  each other.  Used to determine how many   */
/*                                  spaces should go before a tag.            */
/*                                                                            */
/*                  char* name    - The name of the XML tag.                  */
/*                                                                            */
/*                  char* attributes - The attributes of the XML tag.         */
/*                                                                            */
/*   Return Value:  char* - The XML starting tag.                             */
/******************************************************************************/
char* createXMLStartTag(int* tagDepth, char* name, char* attributes)
{
    char* tag = NULL;

    tag = buildXMLTag((*tagDepth) * SPACESPERTAGDEPTH, "<", name, attributes,
                      ">");

    *tagDepth += 1;

    return tag;
}

/******************************************************************************/
/*   Function name: char* createXMLEndTag(int* tagDepth, char* name)          */
/*                                                                            */
/*   Description:   Create an XML ending tag with name as its node name.      */
/*                                                                            */
/*   Parameters:    int* tagDepth - How many tags are currently nested within */
/*                                  each other.  Used to determine how many   */
/*                                  spaces should go before a tag.            */
/*                                                                            */
/*                  char* name    - The name of the end tag.                  */
/*                                                                            */
/*   Return Value:  char* - The XML ending tag.                               */
/******************************************************************************/
char* createXMLEndTag(int* tagDepth, char* name)
{
    char* tag = NULL;

    *tagDepth -= 1;
    tag = buildXMLTag(*tagDepth * SPACESPERTAGDEPTH, "</", name, NULL, ">");

    return tag;
}

/******************************************************************************/
/*   Function name: char* buildXMLTag(int numSpaces, char* prefix, char* name,*/
/*                  char* attributes, char* suffix)                           */
/*                                                                            */
/*   Description:   Create an XML starting or ending tag.                     */
/*                                                                            */
/*   Parameters:    int numSpaces    - How many spaces should preface the tag.*/
/*                  char* prefix     - The "prefix" of the tag ("<" or "</")  */
/*                  char* name       - The tag's name.                        */
/*                  char* attributes - The attributes of the tag.             */
/*                  char* suffix     - The "suffix of the tag (">").          */
/*                                                                            */
/*   Return Value:  char* - The newly created XML tag.                        */
/******************************************************************************/
char* buildXMLTag(int numSpaces, char* prefix, char* name, char* attributes,
                  char* suffix)
{
/****
 * TODO: sizeOfTag unused - can this be deleted?
    int sizeOfTag = -1;
 */
    char* line = NULL;

    //Create a spacer to indicate the depth of tag nesting is
    char* spacing = calloc(numSpaces+1, sizeof(char));
    spacing = memset(spacing, ' ', numSpaces);

/****
 * TODO: sizeOfTag unused - can this be deleted?
    if(prefix == NULL && suffix == NULL)
        sizeOfTag = strlen(spacing) + strlen(name) + 1;
    else
    {

        //Add an extra byte for null terminator
        sizeOfTag = strlen(spacing) + strlen(prefix) + strlen(name) +
                    strlen(suffix) + 1;
    }
*/

    if(prefix == NULL && attributes == NULL && suffix == NULL)
        asprintf(&line, "%s%s", spacing, name);
    else if(attributes == NULL)
        asprintf(&line, "%s%s%s%s", spacing, prefix, name, suffix);
    else
        asprintf(&line, "%s%s%s %s%s", spacing, prefix, name, attributes, suffix);

    free(spacing);

    return line;
}
