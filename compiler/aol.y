/******************************************************************************/
/*   PURPOSE: Contains the grammar rules for the Astronomy Observation        */
/*            Language.  The best effort is made to keep the design documents */
/*            synchronized with the grammar rules that actually appear in this*/
/*            file.                                                           */
/******************************************************************************/

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "aol.h"

    int yylex(void);
    int yyparse(void);

    int debug = 0;
%}


%union
{
    int i;
    double d;
    char* str;

    struct ast *a;

    /* Unnecessary without a symbol table */
    /*struct symbol *s;
     *struct symlist *sl; */
}

%token <i> INTEGER
%token <d> DOUBLE
%token <str> STRING

%token <str> LONGDIRECTION
%token <str> LATDIRECTION
%token <str> TEMPERATUREUNITS
%token <str> DISTANCEUNITS
%token <str> VELOCITYUNITS
%token <str> DIRECTION
%token <str> CATALOG

/*Keyword tokens */
%token K_TELESCOPEID K_TELESCOPE K_NAME K_BRAND K_MODEL K_TYPE K_APERTURE
%token K_FOCALLENGTH  K_FOCALRATIO K_MOUNT K_OBSERVATION K_TIME K_LOCATION
%token K_LONGITUDE K_SEEING K_TRANSPARENCY K_WEATHER K_TEMPERATURE K_HUMIDITY
%token K_WIND K_TARGET K_DESIGNATION K_CONSTELLATION K_RIGHTASCENSION
%token K_DECLINATION K_ALTITUDE K_AZIMUTH K_FILTER K_MAGNITUDE K_EYEPIECE K_DIRECTORY
%token K_IMAGE K_NOTE K_LATITUDE K_TO K_H K_M K_S K_NGC

%type <a> start infoTypes infoType

          telescopeStmt teleOptStmts teleOptStmt size

          observationStmt date observationOptStmts observationOptStmt time
          latitude longitude coordinate hourMinSec arcDegree degree magnitude
          temperature wind catalog

          optTargetStmts optTargetStmt optImgStmts optImgStmt optString optStmt

%start start

%%

start: infoTypes                                                {
                                                                    if (debug)
                                                                        dumpast($1, 0);
                                                                    generateIntermediateCode($1);
                                                                    // Clean things up
                                                                    // treefree($1);
                                                                }
     | error                                                    {
                                                                    yyerrok;
                                                                    exit(0);
                                                                }
;

infoTypes: infoType infoTypes                                   { $$ = newast(list, $1, $2); }
         | /* nothing */                                        { $$ = NULL; }
;

infoType: telescopeStmt                                         { $$ = $1; }
        | observationStmt                                       { $$ = $1; }
;

telescopeStmt: K_TELESCOPE STRING '{' teleOptStmts '}'          { $$ = newast(telescope, newstring($2), $4);
                                                                  free(tempTelescope);
                                                                  tempTelescope = newTelescopeInfo();
                                                                }
;
teleOptStmts: teleOptStmt teleOptStmts                          { $$ = newast(list, $1, $2);  }
            | /* nothing */                                     { $$ = NULL; }
;
teleOptStmt: K_BRAND STRING                                     {
                                                                  attemptDeclaration("TELESCOPE", &tempTelescope->brandSet, "BRAND");
                                                                  $$ = newast(brand, newstring($2), NULL);
                                                                }
           | K_MODEL STRING                                     { $$ = newast(model, newstring($2), NULL); }
           | K_TYPE STRING                                      { $$ = newast(type, newstring($2), NULL); }
           | K_APERTURE size                                    { $$ = newast(aperture, $2, NULL); }
           | K_FOCALLENGTH size                                 { $$ = newast(focallength, $2, NULL); }
           | K_FOCALRATIO 'f' '/' DOUBLE                        { $$ = newast(focalratio, newdouble($4), NULL); }
           | K_FOCALRATIO 'f' '/' INTEGER                       { $$ = newast(focalratio, newint($4), NULL); }
           | K_MOUNT STRING                                     { $$ = newast(mount, newstring($2), NULL); }
           | optStmt                                            { $$ = $1; }
;

size: DOUBLE DISTANCEUNITS                                      { $$ = newast(size, newdouble($1), newstring($2));}
    | INTEGER DISTANCEUNITS                                     { $$ = newast(size, newint($1), newstring($2));}

;

observationStmt: K_OBSERVATION date '{' observationOptStmts '}' { $$ = newast(observation, $2, $4); }
;
date: INTEGER '/' INTEGER '/' INTEGER                           { $$ = newdate($1, $3, $5); }
;

observationOptStmts: observationOptStmt observationOptStmts     { $$ = newast(list, $1, $2); }
                   | /* nothing */                              { $$ = NULL; }
;
observationOptStmt: K_TIME time                                 { $$ = $2;  }
                  | K_LOCATION STRING                           { $$ = newast(location, newstring($2), NULL);  }
                  | K_LATITUDE latitude                         { $$ = $2; }
                  | K_LONGITUDE longitude                       { $$ = $2; }
                  | K_WEATHER STRING                            { $$ = newast(weather, newstring($2), NULL);  }
                  | K_SEEING INTEGER                            { $$ = newast(seeing, newint($2), NULL);  }
                  | K_TRANSPARENCY INTEGER                      { $$ = newast(transparency, newint($2), NULL);  }
                  | K_TEMPERATURE temperature                   { $$ = $2; }
                  | K_HUMIDITY DOUBLE '%'                       { $$ = newast(humidity, newdouble($2), NULL); }
                  | K_HUMIDITY INTEGER '%'                      { $$ = newast(humidity, newint($2), NULL); }
                  | K_WIND wind                                 { $$ = $2; }
                  | K_TARGET STRING '{' optTargetStmts '}'      { $$ = newast(target, newstring($2), $4); }
                  | optStmt                                     { $$ = $1; }
;

time: INTEGER ':' INTEGER K_TO INTEGER ':' INTEGER              { $$ = newast(timeRange, newast(time, newint($1), newint($3)),
                                                                              newast(time, newint($5), newint($7))); }
    | INTEGER ':' INTEGER                                       { $$ = newast(time, newint($1), newint($3)); }
;

latitude: coordinate LATDIRECTION                               { $$ = newast(latitude, $1, newstring($2)); }
;

longitude: coordinate LONGDIRECTION                             { $$ = newast(longitude, $1, newstring($2)); }
;

coordinate: arcDegree                                           { $$ = $1; }
          | degree                                              { $$ = $1; }
;

hourMinSec: INTEGER K_H INTEGER K_M DOUBLE K_S                  { $$ = newHorDMinSec(' ', $1, $3, $5); }
;

arcDegree: '+' INTEGER 'o' INTEGER '\'' DOUBLE '\"'             { $$ = newHorDMinSec('+', $2, $4, $6); }
         | '-' INTEGER 'o' INTEGER '\'' DOUBLE '\"'             { $$ = newHorDMinSec('-', $2, $4, $6); }
         |     INTEGER 'o' INTEGER '\'' DOUBLE '\"'             { $$ = newHorDMinSec('+', $1, $3, $5); }
;

degree:  '+' DOUBLE 'o'                                         { $$ = newast(degree, newchar('+'), newdouble($2)); }
      |  '-' DOUBLE 'o'                                         { $$ = newast(degree, newchar('-'), newdouble($2)); }
      | DOUBLE 'o'                                              { $$ = newast(degree, newchar('+'), newdouble($1)); }
;

/*           temperature ## F | C | K */
temperature: DOUBLE TEMPERATUREUNITS                            { $$ = newast(temperature, newdouble($1), newstring($2)); }
           | INTEGER TEMPERATUREUNITS                           { $$ = newast(temperature, newint($1), newstring($2)); }
;
/*    4.4mph NW, NE, etc*/
wind: DOUBLE VELOCITYUNITS DIRECTION                            { $$ = newwind($1, $2, $3); }
/*    4.4mph N or S*/
    | DOUBLE VELOCITYUNITS LATDIRECTION                         { $$ = newwind($1, $2, $3); }
/*    4.4mph E or W*/
    | DOUBLE VELOCITYUNITS LONGDIRECTION                        { $$ = newwind($1, $2, $3); }
;

optTargetStmts: optTargetStmt optTargetStmts                    { $$ = newast(list, $1, $2); }
              | /* nothing */                                   { $$ = NULL; }
;

optTargetStmt: K_TIME time                                      { $$ = $2; }
             | K_TYPE STRING                                    { $$ = newast(type, newstring($2), NULL); }
             | K_DESIGNATION catalog STRING                     { $$ = newast(designation, $2, newstring($3)); }
             | K_DESIGNATION catalog INTEGER                    { $$ = newast(designation, $2, newint($3)); }
             | K_CONSTELLATION STRING                           { $$ = newast(constellation, newstring($2), NULL); }
             | K_RIGHTASCENSION hourMinSec                      { $$ = newast(rightascension, $2, NULL); }
             | K_DECLINATION arcDegree                          { $$ = newast(declination, $2, NULL); }
             | K_ALTITUDE coordinate                            { $$ = newast(altitude, $2, NULL); }
             | K_AZIMUTH coordinate                             { $$ = newast(azimuth, $2, NULL); }
             | K_FILTER STRING                                  { $$ = newast(filter, newstring($2), NULL); }
             | K_MAGNITUDE magnitude                            { $$ = $2; }
             | K_TELESCOPEID STRING                             { $$ = newast(telescopeid, newstring($2), NULL); }

//TODO: change to eyepiece identifier and move this to being defined as equipment as is case with K_TELESCOPEID
             | K_EYEPIECE size optString                        { $$ = newast(eyepiece, $2, $3); }
             | K_EYEPIECE STRING optString                      { $$ = newast(eyepiece, newstring($2), $3); }
//END TODO
             | K_DIRECTORY STRING '{' optImgStmts '}'           { $$ = newast(directory, newstring($2), $4); }
             | optStmt                                          { $$ = $1; }
;

catalog: K_M                                                    { $$ = newstring("m"); }
       | K_NGC                                                  { $$ = newstring("ngc"); }
;

magnitude: '+' DOUBLE                                           { $$ = newast(magnitude, newchar('+'), newdouble($2)); }
         | '-' DOUBLE                                           { $$ = newast(magnitude, newchar('-'), newdouble($2)); }
         | DOUBLE                                               { $$ = newast(magnitude, newchar('+'), newdouble($1)); }

optImgStmts: optImgStmt optImgStmts                             { $$ = newast(list, $1, $2); }
           | /* nothing */                                      { $$ = NULL; }
;
optImgStmt: K_IMAGE STRING optString                            { $$ = newast(image, newstring($2), $3); }
          | optStmt                                             { $$ = $1; }
;
optString: STRING                                               { $$ = newast(note, newstring($1), NULL); }
         | /* nothing */                                        { $$ = NULL; }
;

//OptStmt is intended to be common to every infoType.
optStmt: K_NOTE STRING                                          { $$ = newast(note, newstring($2), NULL); }
;
%%
