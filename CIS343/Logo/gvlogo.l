%{
#include <stdio.h>
#include <stdlib.h>
#include "gvlogo.tab.h"

extern void yyerror(const char* s);
%}

%%
[0-9]+                                { yylval.f = atoi(yytext); return NUMBER; }
penup                                 { return PENUP; }
pendown                               { return PENDOWN; }
print                                 { return PRINT; }
save                                  { return SAVE; }
color                                 { return COLOR; }
clear                                 { return CLEAR; }
turn                                  { return TURN; }
move                                  { return MOVE; }
goto                                  { return GOTO; }
where                                 { return WHERE; }
\+                                    { return PLUS; }
\-                                    { return SUB; }
\*                                    { return MULT; }
\/                                    { return DIV; }
=                                     { return EQUAL; }
;                                     { return SEP; }
\"[A-Za-z]+\"                         { yylval.s = yytext; return STRING; }
var0                                  { return VAR0; }
var1                                  { return VAR1; }
var2                                  { return VAR2; }
var3                                  { return VAR3; }
var4                                  { return VAR4; }
[ \t\r\n]			                  ;
var[5-9]*                             { yyerror("Invalid variable name.\n"); "\n"; }
.			                          { yyerror("Lexing Syntax error.\n"); } 

%%
//(var0|var1|var2|var3|var4)            { yylval.var = yytext; return VAR; }
https://prod.liveshare.vsengsaas.visualstudio.com/join?903C0EED949A1A85167EE26ECED58F4D8353