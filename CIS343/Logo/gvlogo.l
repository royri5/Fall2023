%{
// Author: Richard Roy
#include <stdio.h>
#include <stdlib.h>
#include "gvlogo.tab.h"

extern void yyerror(const char* s);
%}

%%
[0-9]+                                { yylval.f = atoi(yytext); return NUMBER; }
penup                                 { return PENUP; }                             // done
pendown                               { return PENDOWN; }                           // done
print                                 { return PRINT; }                             // done
save                                  { return SAVE; }                              // done
color                                 { return COLOR; }                             // done
clear                                 { return CLEAR; }                             // done
turn                                  { return TURN; }                              // done
move                                  { return MOVE; }                              // done
goto                                  { return GOTO; }                              // done
where                                 { return WHERE; }                             // done
\+                                    { return PLUS; }
\-                                    { return SUB; }
\*                                    { return MULT; }
\/                                    { return DIV; }
=                                     { return EQUAL; }
;                                     { return SEP; }
\"[A-Za-z]+\"                         { yylval.s = yytext; return STRING; }
[A-Za-z0-9]+\.bmp                     { yylval.s = yytext; return PATHNAME; }
var0                                  { return VAR0; }
var1                                  { return VAR1; }
var2                                  { return VAR2; }
var3                                  { return VAR3; }
var4                                  { return VAR4; }
[ \t\r\n]			                  ;
.			                          { yyerror("Lexing Syntax error."); } 

%%