/******************************************************************************/
/*   PURPOSE: Contains functions to facilitate the parser with building and   */
/*            evaluating the tree that it builds.  Upon evaluation, the parser*/
/*            will create "bytecode" which can later be processed by a        */
/*            code generator into whatever the target language or markup may  */
/*            be.  In this case, the goal was to be able to target XML, so    */
/*            that is what has been implemented.                              */
/******************************************************************************/
#include "aol.h"

int main()
{
    int parseResult = 0;

    tempTelescope = newTelescopeInfo();

    parseResult = yyparse();

    free(tempTelescope);

    return parseResult;
}

void yyerror(const char *s, ...)
{
    fprintf(stderr, "\n/---------[Check your spelling on this line as well as nearby lines!!]---------\\\n");
    fprintf(stderr, "Line %d: ", yylineno);

    if(s == NULL)
        return;

    va_list ap;
    va_start(ap, s);

    if(ap == NULL)
        return;

    vfprintf(stderr, s, ap);
    va_end(ap);

    fprintf(stderr, "\n\n");
}


/******************************************************************************/
/**********************AST NODE INSTANTIATION FUNCTIONS************************/
/******************************************************************************/
/********************************PRIMITIVES************************************/
struct ast* newast(int nodetype, struct ast*l, struct ast*r)
{
    struct ast*a = calloc(1, sizeof(struct ast));

    if(!a)
        outOfSpaceError("struct ast");

    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
    return a;
}


struct ast* newint(int i)
{
    struct intval *a = calloc(1, sizeof(struct intval));

    if(!a)
        outOfSpaceError("struct intval");

    a->nodetype = (enum type)intval;
    a->value = i;
    return (struct ast*)a;
}

struct ast* newdouble(double d)
{
    struct doubleval *a = calloc(1, sizeof(struct doubleval));

    if(!a)
        outOfSpaceError("struct doubleval");

    a->nodetype = (enum type)doubleval;
    a->value = d;
    return (struct ast*)a;
}

struct ast* newchar(char c)
{
    struct charval *a = calloc(1, sizeof(struct charval));

    if(!a)
        outOfSpaceError("struct charval");

    a->nodetype = (enum type)charval;
    a->value = c;
    return (struct ast*)a;
}

struct ast* newstring(char* s)
{
    struct stringval *a = calloc(1, sizeof(struct stringval));

    if(!a)
        outOfSpaceError("struct stringval");

    a->nodetype = (enum type)stringval;
    a->value = s;

    return (struct ast*)a;
}

/********************************COMPLEX DATA TYPES****************************/
struct ast* newdate(int year, int month, int day)
{
    struct dateval *a = calloc(1, sizeof(struct dateval));

    if(!a)
        outOfSpaceError("struct dateval");

    a->nodetype = (enum type)dateval;
    a->year = year;
    a->month = month;
    a->day = day;
    return (struct ast*)a;
}

struct ast* newHorDMinSec(char plusMinus, int hourOrDegree, int minute,
                          double second)
{
    struct hOrDMinSecval *a = calloc(1, sizeof(struct hOrDMinSecval));

    if(!a)
        outOfSpaceError("struct hOrDMinSecval");

    a->nodetype = (enum type)hOrDMinSecval;
    a->sign = plusMinus;
    a->hourOrDegree = hourOrDegree;
    a->minute = minute;
    a->second = second;
    return (struct ast*)a;
}

struct ast* newwind(double velocity, char *velocityUnits, char *velocityDir)
{
    struct windval *a = calloc(1, sizeof(struct windval));

    if(!a)
        outOfSpaceError("struct windval");

    a->nodetype = (enum type)windval;
    a->velocity = velocity;
    a->velocityUnits = velocityUnits;
    a->velocityDirection = velocityDir;

    return (struct ast*)a;
}


/**********************REDECLARATION PREVENTION********************************/
struct telescopeInfo* newTelescopeInfo()
{
    struct telescopeInfo* telescope = calloc(1, sizeof(struct telescopeInfo));

    if(!telescope)
        outOfSpaceError("struct telescopeInfo");


    telescope->nameSet = FALSE;
    telescope->brandSet = FALSE;
    telescope->modelSet = FALSE;
    telescope->typeSet = FALSE;

    telescope->apertureValSet = FALSE;
    telescope->apertureUnitsSet = FALSE;

    telescope->focalLengthValSet = FALSE;
    telescope->focalLengthUnitsSet = FALSE;

    telescope->focalRatioSet = FALSE;
    telescope->mountSet = FALSE;

    return telescope;
}


void attemptDeclaration(char* infoType, short* tempAttribute, char* attributeName)
{
    if(*tempAttribute == FALSE)
        *tempAttribute = TRUE;
    else
        redeclarationError(infoType, attributeName);  //Exits on failure
}

void redeclarationError(char* infoType, char* attribute)
{
    yyerror("Redefined %s attribute in %s information type.", attribute, infoType);
    exit(0);
}


void outOfSpaceError(const char* type)
{
    perror(type);
    exit(0);
}


void treefree(struct ast*a)
{
    if(!a)
        return;

    switch((enum type)(a->nodetype))
    {
        /* two subtrees */
        case list: case telescope: case size: case observation: case target:
        case timeRange: case time: case latitude: case longitude: case degree:
        case temperature: case designation: case magnitude: case eyepiece:
        case directory: case image:
            treefree(a->r);

        /* one subtree */
        case name: case brand: case model: case type: case aperture:
        case focallength: case focalratio: case mount: case location:
        case weather: case seeing: case transparency: case humidity:
        case constellation: case filter: case telescopeid: case note:
            treefree(a->l);

        /* no subtree */
        case intval: case doubleval: case charval: case stringval: case dateval:
        case hOrDMinSecval: case windval:
        break;

        default:
            printf("Internal Error: Nodetype %c not found when ", a->nodetype);
            printf("attempting to free parse tree.");
    }

    free(a); /* always free the node itself */
}


void cleanString(char *str)
{
    int i, j; // array indexes
    int len; // length of string

    len = strlen(str);
    for (i = 0, j = 0; i < len; i++)
    {
        if ((str[i] != '"'))
        {
            str[j] = str[i];
            j++;
        } // end if
    } // end for
    str[j] = '\0';
} // end function cleanData


/******************************************************************************/
/*   Function name: char* createBytecode(char* address1, char* address2)      */
/*                                                                            */
/*   Description:   Create a line of two address bytecode.  This will place   */
/*                  separator, designated by BYTECODESEPARATOR at the         */
/*                  appropriate places between the addresses.                 */
/*                                                                            */
/*   Parameters:    const char* address1 - The first "address" to be added to */
/*                                         the line.                          */
/*                  const char* address2 - The first "address" to be added to */
/*                                         the line.                          */
/*                                                                            */
/*   Return Value:  The newly created line.                                   */
/******************************************************************************/
char* createBytecode(const char* address1, const char* address2)
{
    int sizeOfAddresses = -1;
    char* temp = NULL;

    if(address1 == NULL || address2 == NULL)
        return NULL;

    //Add an extra 2 bytes for newline and null terminator
    sizeOfAddresses = strlen(address1) + (2* strlen(BYTECODESEPARATOR)) +
                      strlen(address2) + 2;

    //Check if the addresses are too large
    if(sizeOfAddresses > CHARSPERFILELINE)
        return NULL;

    //Create the line
    temp = (char*)calloc(sizeOfAddresses, sizeof(char));

    sprintf(temp, "%s%s%s%s\n", strdup(address1), BYTECODESEPARATOR, strdup(address2),
            BYTECODESEPARATOR);


    //free(address1);
    //free(address2);

    return temp;
}

//Number parameter indicates index of a complex data type.  dataMemberNumber
//indicates the parameter to be converted to string for a complex data type.
//This is not checked for a simple and/orprimitive data tyoe (char, int, double,
//string)
char* dataToString(struct ast* a, int dataMemberNumber)
{
    if(!a)
    {
        fprintf(stderr, "Could not convert current node's data to string.\n");
        return NULL;
    }

    if(a->nodetype == stringval)
        return ((struct stringval *)a)->value;


    if(a->nodetype == intval)
        return intToString(((struct intval *)a)->value);
    else if(a->nodetype == doubleval)
        return doubleToString(((struct doubleval *)a)->value);
    else if(a->nodetype == charval)
        return charToString(((struct charval *)a)->value);
    else if(a->nodetype == dateval)
    {
        switch(dataMemberNumber)
        {
            case 0:
                return intToString(((struct dateval *)a)->year);
            case 1:
                return intToString(((struct dateval *)a)->month);
            case 2:
                return intToString(((struct dateval *)a)->day);
        }
    }
    else if(a->nodetype == hOrDMinSecval)
    {
        switch(dataMemberNumber)
        {
            case 0:
                return charToString(((struct hOrDMinSecval *)a)->sign);
            case 1:
                return intToString(((struct hOrDMinSecval *)a)->hourOrDegree);
            case 2:
                return intToString(((struct hOrDMinSecval *)a)->minute);
            case 3:
                return doubleToString(((struct hOrDMinSecval *)a)->second);
        }
    }
    else if(a->nodetype == windval)
    {
        switch(dataMemberNumber)
        {
            case 0:
                return doubleToString(((struct windval *)a)->velocity);
            case 1:
                return ((struct windval *)a)->velocityUnits;
            case 2:
                return ((struct windval *)a)->velocityDirection;
        }
    }
    else
    {
        fprintf(stderr, "Could not convert current node's data to string.\n");
        return NULL;
    }

    return NULL;
}

char* intToString(int intToConvert)
{
    char* buffer = NULL;

    if(-1 == asprintf(&buffer, "%d", intToConvert))
    {
        outOfSpaceError("dataToString buffer");
        exit(0);
    }

    return buffer;
}

char* charToString(char charToConvert)
{
    char* buffer;

    if(-1 == asprintf(&buffer, "%c", charToConvert))
    {
        outOfSpaceError("charToString buffer");
        exit(0);
    }

    return buffer;
}

char* doubleToString(double doubleToConvert)
{
    char* buffer;

    if(-1 == asprintf(&buffer, "%f", doubleToConvert))
    {
        outOfSpaceError("doubleToString buffer");
        exit(0);
    }



    return buffer;
}


char* typeToString(struct ast* a, int dataMemberNumber)
{
    char* buffer;

    if(!a)
    {
        fprintf(stderr, "Could not convert current node's type to string.\n");
        return NULL;
    }

    buffer = calloc(NODE_NAME_MAX_LENGTH+1, sizeof(char));

    if(!buffer)
    {
        outOfSpaceError("Creating node type to string buffer");
        return NULL;
    }



    switch(a->nodetype)
    {
        case hOrDMinSecval:
            switch(dataMemberNumber)
            {
                case 0:
                    strcpy(buffer, "character");
                    break;
                case 1:
                    strcpy(buffer, "integer");
                    break;
                case 2:
                    strcpy(buffer, "integer");
                    break;
                case 3:
                    strcpy(buffer, "double");
                    break;
            }
            break;
        case windval:
            switch(dataMemberNumber)
            {
                case 0:
                    strcpy(buffer, "double");
                    break;
                case 1:
                    strcpy(buffer, "string");
                    break;
                case 2:
                    strcpy(buffer, "string");
                    break;
            }
            break;
        case dateval:
            strcpy(buffer, "integer");
            break;
        case charval:
            strcpy(buffer, "character");
            break;
        case intval:
            strcpy(buffer, "integer");
            break;
        case doubleval:
            strcpy(buffer, "double");
            break;
        case stringval:
            strcpy(buffer, "string");
            break;
        default:
            strcpy(buffer, "UNKNOWN");
    }//end switch(nodetype)

    return buffer;
}



void generateIntermediateCode(struct ast* a)
{
    printf("%s", createBytecode(TAG_START, "AstronomyData"));
    evalast(a);
    printf("%s", createBytecode(TAG_END,   "AstronomyData"));
}


/******************************************************************************/
/*   Function name: void evalast(struct ast* a)                               */
/*                                                                            */
/*   Description:   Make a pass through the abstract syntax tree and generate */
/*                  bytecode which can be used to describe the data (or easily*/
/*                  rebuild the parse tree in another program if necessary)   */
/*                                                                            */
/*   Parameters:    struct ast* a - The current node of the parse tree.  Can  */
/*                   be used to evaluate as much or as little of the tree as  */
/*                  needed based on the passed node.                          */
/*                                                                            */
/*   Return Value:  NONE                                                      */
/******************************************************************************/
void evalast(struct ast* a)
{
    if(!a)
        return;

    switch((enum type)(a->nodetype))
    {
        /**********************TWO SUBTREES************************************/
        case list:
            //Not necessary to create tags to indicate a list.
            evalast(a->l);
            evalast(a->r);
            return;
        case telescope:
            printf("%s%s%s%s%s%s",
                   createBytecode(TAG_START,  "Telescope"),

                   createBytecode(TAG_START,  "ID"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "ID"));

            evalast(a->r);

            printf("%s",
                   createBytecode(TAG_END,    "Telescope"));
            return;

        case size:
            printf("%s%s%s%s%s%s%s",
                   createBytecode(TAG_START,  "Size"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(ATTR_NAME,  "Units"),
                   createBytecode(ATTR_VALUE, dataToString(a->r, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Size"));
            return;
        case observation:
            printf("%s",
                   createBytecode(TAG_START,  "Observation"));

            evalast(a->l);
            evalast(a->r);

            printf("%s",
                   createBytecode(TAG_END,    "Observation"));
            return;
        case target:
            printf("%s%s%s%s%s%s",
                   createBytecode(TAG_START,  "Target"),

                   createBytecode(TAG_START,  "ID"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "ID"));

            evalast(a->r);

            printf("%s",
                   createBytecode(TAG_END,    "Target"));
            return;
        case timeRange:
            printf("%s",
                   createBytecode(TAG_START,  "TimeRange"));
            evalast(a->l);
            evalast(a->r);
            printf("%s",
                   createBytecode(TAG_END,    "TimeRange"));
            return;
        case time:
            printf("%s%s%s%s%s%s%s%s%s%s%s%s",
                   createBytecode(TAG_START,  "Time"),

                   createBytecode(TAG_START,  "Hour"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Hour"),

                   createBytecode(TAG_START,  "Minute"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->r, 0)),
                   createBytecode(DATA,       dataToString(a->r, 0)),
                   createBytecode(TAG_END,    "Minute"),

                   createBytecode(TAG_END,    "Time"));
            return;
        case latitude:
            printf("%s%s%s",
                   createBytecode(TAG_START,  "Latitude"),
                   createBytecode(ATTR_NAME,  "Hemisphere"),
                   createBytecode(ATTR_VALUE, dataToString(a->r, 0)));
            evalast(a->l);
            printf("%s",
                   createBytecode(TAG_END,    "Latitude"));
            return;
        case longitude:
            printf("%s%s%s",
                   createBytecode(TAG_START,  "Longitude"),
                   createBytecode(ATTR_NAME,  "Hemisphere"),
                   createBytecode(ATTR_VALUE, dataToString(a->r, 0)));
            evalast(a->l);
            printf("%s",
                   createBytecode(TAG_END,    "Longitude"));
            return;
        case degree:
            printf("%s%s%s%s%s%s%s%s%s",
                   createBytecode(TAG_START,  "Angle"),
                   createBytecode(ATTR_NAME,  "Type"),
                   createBytecode(ATTR_VALUE, "decimal"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, "double"),
                   createBytecode(ATTR_NAME,  "Sign"),
                   createBytecode(ATTR_VALUE, dataToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->r, 0)),
                   createBytecode(TAG_END,    "Angle"));
            return;
        case temperature:
            printf("%s%s%s%s%s%s%s",
                   createBytecode(TAG_START,  "Temperature"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(ATTR_NAME,  "Units"),
                   createBytecode(ATTR_VALUE, dataToString(a->r, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Temperature"));
            return;
        case designation:
            printf("%s%s%s%s%s%s%s%s%s%s%s%s",
                   createBytecode(TAG_START,  "Designation"),

                   createBytecode(TAG_START,  "Catalog"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Catalog"),

                   createBytecode(TAG_START,  "Object"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->r, 0)),
                   createBytecode(DATA,       dataToString(a->r, 0)),
                   createBytecode(TAG_END,    "Object"),

                   createBytecode(TAG_END,    "Designation"));
            return;
        case magnitude:
            printf("%s%s%s%s%s%s%s",
                   createBytecode(TAG_START,  "Magnitude"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->r, 0)),
                   createBytecode(ATTR_NAME,  "Sign"),
                   createBytecode(ATTR_VALUE, dataToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->r, 0)),
                   createBytecode(TAG_END,    "Magnitude"));
            return;
        case eyepiece:

            printf("%s",
                   createBytecode(TAG_START,  "Eyepiece"));

            //Size node is a datatype on its own.  No need to print attributes.
            if(a->l->nodetype == size)
                evalast(a->l);
            //Data isn't contained in a size datatype
            else
            {
                printf("%s%s%s",
                       createBytecode(ATTR_NAME,  "DataType"),
                       createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                       createBytecode(DATA,       dataToString(a->l, 0)));
            }

            evalast(a->r);

            printf("%s",
                   createBytecode(TAG_END,    "Eyepiece"));
            return;
        case directory:
            printf("%s%s%s%s%s%s",
                   createBytecode(TAG_START,  "Directory"),
                   createBytecode(TAG_START,  "Path"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, "string"),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Path"));

            //Dump images
            evalast(a->r);

            printf("%s",
                   createBytecode(TAG_END,    "Directory"));
            return;
        case image:
            printf("%s%s%s%s%s%s",
                   createBytecode(TAG_START,  "Image"),
                   createBytecode(TAG_START,  "File"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, "string"),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "File"));

            evalast(a->r);

            printf("%s",
                   createBytecode(TAG_END, "Image"));
            return;

        /**********************ONE SUBTREE*************************************/

        case name:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Name"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, "string"),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Name"));
            return;
        case brand:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Brand"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, "string"),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,   "Brand"));
            return;
        case model:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Model"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, "string"),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Model"));
            return;
        case type:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Type"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Type"));
            return;
        case aperture:
            printf("%s",
                   createBytecode(TAG_START, "Aperture"));
            evalast(a->l);
            printf("%s",
                   createBytecode(TAG_END,   "Aperture"));
            return;
        case focallength:
            printf("%s",
                   createBytecode(TAG_START, "FocalLength"));
            evalast(a->l);
            printf("%s",
                   createBytecode(TAG_END,    "FocalLength"));
            return;
        case focalratio:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "FocalRatio"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "FocalRatio"));
            return;
        case mount:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Mount"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, "string"),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Mount"));
            return;
        case location:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Location"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, "string"),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,   "Location"));
            return;
        case weather:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Weather"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, "string"),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Weather"));
            return;
        case seeing:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Seeing"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Seeing"));
            return;
        case transparency:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Transparency"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Transparency"));
            return;
        case humidity:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Humidity"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Humidity"));
            return;
        case constellation:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Constellation"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Constellation"));
            return;
        case rightascension:
            printf("%s",
                   createBytecode(TAG_START,  "RightAscension"));
            evalast(a->l);
            printf("%s",
                   createBytecode(TAG_END,    "RightAscension"));
            return;
        case declination:
            printf("%s",
                   createBytecode(TAG_START,  "Declination"));
            evalast(a->l);
            printf("%s",
                   createBytecode(TAG_END,    "Declination"));
            return;
        case altitude:
            printf("%s",
                   createBytecode(TAG_START,  "Altitude"));
            evalast(a->l);
            printf("%s",
                   createBytecode(TAG_END,    "Altitude"));
            return;
        case azimuth:
            printf("%s",
                   createBytecode(TAG_START,  "Azimuth"));
            evalast(a->l);
            printf("%s",
                   createBytecode(TAG_END,    "Azimuth"));
            return;
        case filter:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Filter"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a->l, 0)),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Filter"));
            return;
        case telescopeid:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "TelescopeID"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, "string"),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "TelescopeID"));
            return;

        case note:
            printf("%s%s%s%s%s",
                   createBytecode(TAG_START,  "Note"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, "string"),
                   createBytecode(DATA,       dataToString(a->l, 0)),
                   createBytecode(TAG_END,    "Note"));
            return;
        /**********************NO SUBTREE**************************************/
        case intval:
        case doubleval:
        case charval:
        case stringval:
            printf("%s",
                   createBytecode(DATA,      dataToString(a, 0)));
            return;
        case dateval:
            printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
                   createBytecode(TAG_START,  "Date"),

                   createBytecode(TAG_START,  "Year"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a, 0)),
                   createBytecode(DATA,       dataToString(a, 0)),
                   createBytecode(TAG_END,    "Year"),

                   createBytecode(TAG_START,  "Month"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a, 1)),
                   createBytecode(DATA,       dataToString(a, 1)),
                   createBytecode(TAG_END,    "Month"),

                   createBytecode(TAG_START,  "Day"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a, 2)),
                   createBytecode(DATA,       dataToString(a, 2)),
                   createBytecode(TAG_END,    "Day"),

                   createBytecode(TAG_END,    "Date"));

            return;
        case hOrDMinSecval:

            //Degrees, minutes and seconds
            if(((struct hOrDMinSecval *)a)->sign == '+' ||
               ((struct hOrDMinSecval *)a)->sign == '-')
            {
                printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
                       createBytecode(TAG_START,  "Angle"),
                       createBytecode(ATTR_NAME,  "Type"),
                       createBytecode(ATTR_VALUE, "sexagesimal"),
                       createBytecode(ATTR_NAME,  "Sign"),
                       createBytecode(ATTR_VALUE, dataToString(a, 0)),

                       createBytecode(TAG_START,  "Degrees"),
                       createBytecode(ATTR_NAME,  "DataType"),
                       createBytecode(ATTR_VALUE, "integer"),
                       createBytecode(DATA,       dataToString(a, 1)),
                       createBytecode(TAG_END,    "Degrees"),

                       createBytecode(TAG_START,  "Minutes"),
                       createBytecode(ATTR_NAME,  "DataType"),
                       createBytecode(ATTR_VALUE, "integer"),
                       createBytecode(DATA,       dataToString(a, 2)),
                       createBytecode(TAG_END,    "Minutes"),

                       createBytecode(TAG_START,  "Seconds"),
                       createBytecode(ATTR_NAME,  "DataType"),
                       createBytecode(ATTR_VALUE, "double"),
                       createBytecode(DATA,       dataToString(a, 3)),
                       createBytecode(TAG_END,    "Seconds"),

                       createBytecode(TAG_END,    "Angle"));
            }
            //Hours, minutes, and seconds
            else
            {
                printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
                       createBytecode(TAG_START,  "Angle"),
                       createBytecode(ATTR_NAME,  "Type"),
                       createBytecode(ATTR_VALUE, "hours"),

                       createBytecode(TAG_START,  "Hours"),
                       createBytecode(ATTR_NAME,  "DataType"),
                       createBytecode(ATTR_VALUE, typeToString(a, 1)),
                       createBytecode(DATA,       dataToString(a, 1)),
                       createBytecode(TAG_END,    "Hours"),

                       createBytecode(TAG_START,  "Minutes"),
                       createBytecode(ATTR_NAME,  "DataType"),
                       createBytecode(ATTR_VALUE, typeToString(a, 2)),
                       createBytecode(DATA,       dataToString(a, 2)),
                       createBytecode(TAG_END,    "Minutes"),

                       createBytecode(TAG_START,  "Seconds"),
                       createBytecode(ATTR_NAME,  "DataType"),
                       createBytecode(ATTR_VALUE, typeToString(a, 3)),
                       createBytecode(DATA,       dataToString(a, 3)),
                       createBytecode(TAG_END,    "Seconds"),

                       createBytecode(TAG_END,    "Angle"));
            }
            return;
        case windval:
            printf("%s%s%s%s%s%s%s%s%s",
                   createBytecode(TAG_START,  "Wind"),
                   createBytecode(ATTR_NAME,  "DataType"),
                   createBytecode(ATTR_VALUE, typeToString(a, 0)),
                   createBytecode(ATTR_NAME,  "Units"),
                   createBytecode(ATTR_VALUE, dataToString(a, 1)),
                   createBytecode(ATTR_NAME,  "Direction"),
                   createBytecode(ATTR_VALUE, dataToString(a, 2)),

                   createBytecode(DATA,       dataToString(a, 0)),

                   createBytecode(TAG_END,    "Wind"));
            return;
        default:
            fprintf(stderr, "Node %c not found when evaluating tree. Stop!\n",
                    a->nodetype);
            exit(0);
  }
}


void dumpast(const struct ast*a, int level)
{
    printf("\n%*s", 2*level, "");	/* indent to this level */
    level++;

    if(!a)
    {
        printf("NULL");
        return;
    }

    switch((enum type)(a->nodetype))
    {
        /**********************TWO CHILDREN************************************/
        case list:
            printf("List");
            dumpLeftAndRight(a, level);
            return;
        case telescope:
            printf("Telescope");
            dumpLeftAndRight(a, level);
            return;
        case size:
            printf("Size");
            dumpLeftAndRight(a, level);
            return;
        case observation:
            printf("Observation");
            dumpLeftAndRight(a, level);
            return;
        case target:
            printf("Target");
            dumpLeftAndRight(a, level);
            return;
        case timeRange:
            printf("TimeRange");
            dumpLeftAndRight(a, level);
            return;
        case time:
            printf("Time");
            dumpLeftAndRight(a, level);
            return;
        case latitude:
            printf("Latitude");
            dumpLeftAndRight(a, level);
            return;
        case longitude:
            printf("Longitude");
            dumpLeftAndRight(a, level);
            return;
        case degree:
            printf("Degrees");
            dumpLeftAndRight(a, level);
            return;
        case temperature:
            printf("Temperature");
            dumpLeftAndRight(a, level);
            return;
        case designation:
            printf("designation");
            dumpLeftAndRight(a, level);
            return;
        case magnitude:
            printf("Magnitude");
            dumpLeftAndRight(a, level);
            return;
        case eyepiece:
            printf("Eyepiece");
            dumpLeftAndRight(a, level);
            return;
        case directory:
            printf("ImageDirectory");
            dumpLeftAndRight(a, level);
            return;
        case image:
            printf("Image");
            dumpLeftAndRight(a, level);

        /**********************ONE CHILDREN************************************/
        case name:
            printf("Name");
            dumpast(a->l, level);
            return;
        case brand:
            printf("Brand");
            dumpast(a->l, level);
            return;
        case model:
            printf("Model");
            dumpast(a->l, level);
            return;
        case type:
            printf("Type");
            dumpast(a->l, level);
            return;
        case aperture:
            printf("Aperture");
            dumpast(a->l, level);
            return;
        case focallength:
            printf("FocalLength");
            dumpast(a->l, level);
            return;
        case focalratio:
            printf("FocalRatio");
            dumpast(a->l, level);
            return;
        case mount:
            printf("Mount");
            dumpast(a->l, level);
            return;
        case location:
            printf("Location");
            dumpast(a->l, level);
            return;
        case weather:
            printf("Weather");
            dumpast(a->l, level);
            return;
        case seeing:
            printf("Seeing");
            dumpast(a->l, level);
            return;
        case transparency:
            printf("transparency");
            dumpast(a->l, level);
            return;
        case humidity:
            printf("Humidity");
            dumpast(a->l, level);
            return;
        case constellation:
            printf("Constellation");
            dumpast(a->l, level);
            return;
        case filter:
            printf("Filter");
            dumpast(a->l, level);
            return;
        case telescopeid:
            printf("TelescopeID");
            dumpast(a->l, level);
            return;
        case note:
            printf("Note");
            dumpast(a->l, level);
            return;

        /**********************NO CHILDREN*************************************/
        case intval:
            printf("Int: %i", ((struct intval *)a)->value);
            return;
        case doubleval:
            printf("Double: %f", ((struct doubleval *)a)->value);
            return;
        case charval:
            printf("Char: %c", ((struct charval *)a)->value);
            return;
        case stringval:
            printf("String: %s", ((struct stringval *)a)->value);
            return;
        case dateval:
            printf("Date: %i/", ((struct dateval *)a)->year);
            printf("%i/", ((struct dateval *)a)->month);
            printf("%i", ((struct dateval *)a)->day);
            return;
        case hOrDMinSecval:
            if(((struct hOrDMinSecval *)a)->sign == '+')
                printf("+");
            if(((struct hOrDMinSecval *)a)->sign == '-')
                printf("-");

            if(((struct hOrDMinSecval *)a)->sign == '+' ||
               ((struct hOrDMinSecval *)a)->sign == '-')
            {
                printf("%io ", ((struct hOrDMinSecval *)a)->hourOrDegree);
                printf("%i\'", ((struct hOrDMinSecval *)a)->minute);
                printf("%f\" ", ((struct hOrDMinSecval *)a)->second);
            }
            else
            {
                printf("%ih ", ((struct hOrDMinSecval *)a)->hourOrDegree);
                printf("%im ", ((struct hOrDMinSecval *)a)->minute);
                printf("%fs ", ((struct hOrDMinSecval *)a)->second);
            }
            return;
        case windval:
            printf("%f", ((struct windval *)a)->velocity);
            printf("%s", ((struct windval *)a)->velocityUnits);
            printf("%s", ((struct windval *)a)->velocityDirection);
            return;
        default:
            printf("Node %c not found when dumping tree.", a->nodetype);
            return;
  }
}

void dumpLeftAndRight(const struct ast*a, int level)
{
    dumpast(a->l, level);
    dumpast(a->r, level);
}
