/******************************************************************************/
/*   PURPOSE: Provide rules for use by the Lex/Flex tools.  These rules will  */
/*            be used to generate lexical tokens which will be passed to the  */
/*            parser for further processing.                                  */
/******************************************************************************/

%option noyywrap nodefault yylineno
%{
# include "aol.h"
# include "aol.tab.h"
%}


whiteSpace            [ \t\r\f\n\v]+
comment               "\//".*
digit                 [0-9]

distanceUnits         mm|MM|cm|CM|m|M|in|IN|ft|FT|ly
temperatureUnits      [fF]|[cC]|[kK]
velocityUnits         [kK]?[mM](("/"[hH])|([pP][hH]))

latitudeDirection     [nN]|[sS]
longitudeDirection    [eE]|[wW]
direction             ({latitudeDirection}{longitudeDirection})|{latitudeDirection}|{longitudeDirection}

integer               {digit}+
double                ({digit}+"."{digit}+|"."?{digit}+)
string                \"(\\(.|\n)|[^\\"\n])*\"

%%
":"                   { return yytext[0]; }
"+"                   { return yytext[0]; }
"-"                   { return yytext[0]; }
"o"                   { return yytext[0]; }
"'"                   { return yytext[0]; }
"\""                  { return yytext[0]; }
"%"                   { return yytext[0]; }
"{"                   { return yytext[0]; }
"}"                   { return yytext[0]; }
"f"                   { return yytext[0]; }
"/"                   { return yytext[0]; }

"h"                   { return K_H; }
"H"                   { return K_H; }
"m"                   { return K_M; }
"M"                   { return K_M; }
"s"                   { return K_S; }
"S"                   { return K_S; }

"ngc"                 { return K_NGC; }
"NGC"                 { return K_NGC; }

"telescopeid"         { return K_TELESCOPEID; }
"telescope"           { return K_TELESCOPE; }
"name"                { return K_NAME; }
"brand"               { return K_BRAND; }
"model"               { return K_MODEL; }
"type"                { return K_TYPE; }
"aperture"            { return K_APERTURE; }
"focallength"         { return K_FOCALLENGTH; }
"focalratio"          { return K_FOCALRATIO; }
"mount"               { return K_MOUNT; }
"observation"         { return K_OBSERVATION; }
"time"                { return K_TIME; }
"location"            { return K_LOCATION; }
"latitude"            { return K_LATITUDE; }
"longitude"           { return K_LONGITUDE; }
"weather"             { return K_WEATHER; }
"seeing"              { return K_SEEING; }
"transparency"        { return K_TRANSPARENCY; }
"temperature"         { return K_TEMPERATURE; }
"humidity"            { return K_HUMIDITY; }
"wind"                { return K_WIND; }
"target"              { return K_TARGET; }
"designation"         { return K_DESIGNATION; }
"constellation"       { return K_CONSTELLATION; }
"rightascension"      { return K_RIGHTASCENSION; }
"declination"         { return K_DECLINATION; }
"altitude"            { return K_ALTITUDE; }
"azimuth"             { return K_AZIMUTH; }
"filter"              { return K_FILTER; }
"magnitude"           { return K_MAGNITUDE; }
"eyepiece"            { return K_EYEPIECE; }
"directory"           { return K_DIRECTORY; }
"image"               { return K_IMAGE; }
"note"                { return K_NOTE; }
"to"                  { return K_TO; }

{latitudeDirection}   { yylval.str = strdup(yytext); return LATDIRECTION; }
{longitudeDirection}  { yylval.str = strdup(yytext); return LONGDIRECTION; }
{direction}           { yylval.str = strdup(yytext); return DIRECTION; }


{temperatureUnits}    { yylval.str = strdup(yytext); return TEMPERATUREUNITS; }
{distanceUnits}       { yylval.str = strdup(yytext); return DISTANCEUNITS; }
{velocityUnits}       { yylval.str = strdup(yytext); return VELOCITYUNITS; }

{integer}             { yylval.i = atoi(yytext);     return INTEGER; }
{double}              { yylval.d = atof(yytext);     return DOUBLE; }
{string}              { yylval.str = strdup(yytext);
                        cleanString(yylval.str);     return STRING; }

{comment}             { /* ignore single-line comments*/}
{whiteSpace}          { /* ignore whitespace */ }

.                     { yyerror("unexpected character: %c", *yytext); }
%%
