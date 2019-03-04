/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_AOL_TAB_H_INCLUDED
# define YY_YY_AOL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    DOUBLE = 259,
    STRING = 260,
    LONGDIRECTION = 261,
    LATDIRECTION = 262,
    TEMPERATUREUNITS = 263,
    DISTANCEUNITS = 264,
    VELOCITYUNITS = 265,
    DIRECTION = 266,
    CATALOG = 267,
    K_TELESCOPEID = 268,
    K_TELESCOPE = 269,
    K_NAME = 270,
    K_BRAND = 271,
    K_MODEL = 272,
    K_TYPE = 273,
    K_APERTURE = 274,
    K_FOCALLENGTH = 275,
    K_FOCALRATIO = 276,
    K_MOUNT = 277,
    K_OBSERVATION = 278,
    K_TIME = 279,
    K_LOCATION = 280,
    K_LONGITUDE = 281,
    K_SEEING = 282,
    K_TRANSPARENCY = 283,
    K_WEATHER = 284,
    K_TEMPERATURE = 285,
    K_HUMIDITY = 286,
    K_WIND = 287,
    K_TARGET = 288,
    K_DESIGNATION = 289,
    K_CONSTELLATION = 290,
    K_RIGHTASCENSION = 291,
    K_DECLINATION = 292,
    K_ALTITUDE = 293,
    K_AZIMUTH = 294,
    K_FILTER = 295,
    K_MAGNITUDE = 296,
    K_EYEPIECE = 297,
    K_DIRECTORY = 298,
    K_IMAGE = 299,
    K_NOTE = 300,
    K_LATITUDE = 301,
    K_TO = 302,
    K_H = 303,
    K_M = 304,
    K_S = 305,
    K_NGC = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "aol.y" /* yacc.c:1909  */

    int i;
    double d;
    char* str;

    struct ast *a;

    /* Unnecessary without a symbol table */
    /*struct symbol *s;
     *struct symlist *sl; */

#line 118 "aol.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_AOL_TAB_H_INCLUDED  */
