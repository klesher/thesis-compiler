/******************************************************************************/
/*   PURPOSE: Provide declarations for functions declared in aolfuncs.c. Some */
/*            of these functions are used by the lexer/parser to facilitate   */
/*            communication of data between the two.                          */
/******************************************************************************/
/*  This code to build a symbol table and AST was adapted from: Companion     */
/*  source code for "flex & bison", ISBN 978-0-596-15597-1                    */
/******************************************************************************/

#define _GNU_SOURCE  #Needed for asprintf()
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

#include "../common/bytecode.h"
#include "../common/oftenUsedDefines.h"


#define FALSE 0
#define TRUE  1

#define NODE_NAME_MAX_LENGTH 40

#define MAX_DATA_DIGITS      80



/******************************************************************************/
/**********************ABSTRACT SYNTAX TREE************************************/
/******************************************************************************/
enum type {
              /* Primitive data types: */
              ast = 1, intval, doubleval, charval, stringval,

              /* Complex data Types: */
              dateval, hOrDMinSecval, windval,

              /* Helper types */
              list,

              /* Telescope node types */
              telescope, name, brand, model, type, aperture, focallength,
              focalratio, mount, size,

              /* Observation node types */
              observation, timeRange, time, location, latitude, longitude,
              weather, seeing, transparency, temperature, humidity, wind,
              degree,

              /* target node types */
              target, designation, constellation, rightascension, declination,
              altitude, azimuth, filter, magnitude, eyepiece, telescopeid,

              /* file node types */
              directory, file, image,

              /* optional statement node types */
              note
          };

/******************************************************************************/
/**********************AST NODE INSTANTIATION FUNCTIONS************************/
/********************************PRIMITIVES************************************/
struct ast
{
    enum type nodetype;
    struct ast *l;
    struct ast *r;
};

struct intval
{
    enum type nodetype;
    int value;
};

struct doubleval
{
    enum type nodetype;
    double value;
};

struct charval
{
    enum type nodetype;
    char value;
};

struct stringval
{
    enum type nodetype;
    char* value;
};


/********************************COMPLEX DATA TYPES****************************/
struct dateval
{
    enum type nodetype;
    int year;
    int month;
    int day;
};

/* Use one struct to represent either Hours, Minutes, Seconds or  */
/* Degrees, ArcMinutes and Arcseconds.  Both have the same formatting, so there  */
/* wasn't a point in making two separate structures.  */
struct hOrDMinSecval
{
    enum type nodetype;
    char sign;
    int hourOrDegree;
    int minute;
    double second;
};

/* Keep track of the wind's velocity, its units (mph, km/h, etc) and the  */
/* direction the wind is blowing.  */
struct windval
{
    enum type nodetype;
    double velocity;
    char *velocityUnits;
    char *velocityDirection;
};


/* Used to help prevent redeclaration of attributes  */
struct telescopeInfo
{
    short nameSet;
    short brandSet;
    short modelSet;
    short typeSet;

    short apertureValSet;
    short apertureUnitsSet;

    short focalLengthValSet;
    short focalLengthUnitsSet;

    short focalRatioSet;

    short mountSet;

};


/******************************************************************************/
/**********************AST NODE INSTANTIATION FUNCTIONS************************/
/******************************************************************************/
/********************************PRIMITIVES************************************/
struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newint(int i);
struct ast *newdouble(double d);
struct ast *newchar(char c);
struct ast *newstring(char *s);

/********************************COMPLEX DATA TYPES****************************/
struct ast *newdate(int year, int month, int day);
struct ast *newHorDMinSec(char plusMinus, int hourOrDegree, int minute,
                          double second);
struct ast *newwind(double velocity, char *velocityUnits, char *velocityDir);

/********************************REDECLARATION PREVENTION**********************/
struct telescopeInfo* newTelescopeInfo();
struct telescopeInfo* tempTelescope;

void attemptDeclaration(char* infoType, short* tempAttribute, char* attributeName);
void redeclarationError(char* infoType, char* attribute);

/***************************UTILITY FUNCTIONS**********************************/
void cleanString(char *str);

/******************************Bytecode Generation*****************************/
void generateIntermediateCode(struct ast* a);
void evalast(struct ast* a);
void evalLeftAndRight(struct ast* a);

char* createBytecode(const char* address1, const char* address2);

char* nodeTypeToString(int type);

char* dataToString(struct ast* a, int dataNum);
char* intToString(int intToConvert);
char* charToString(char charToConvert);
char* doubleToString(double doubleToConvert);

/* delete and free an AST */
void treefree(struct ast *);

/***********************DEBUGGING FUNCTIONS************************************/
struct telescopeInfo* tempTelescope;
void dumpast(const struct ast *a, int level);
void dumpLeftAndRight(const struct ast*a, int level);

void outOfSpaceError();

/* interface to the lexer */
extern int yylineno; /* from lexer */
extern char* yytext;
void yyerror(const char *s, ...);
int yyparse(void);
