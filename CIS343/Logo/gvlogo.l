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
;                                     { return SEP; }
\"[A-Za-z]+\"                         { yylval.s = yytext; return STRING; }
(var0|var1|var2|var3|var4)            { yylval.var = yytext; return VAR; }
[ \t\r\n]			                  ;
.			                          { yyerror("Lexing Syntax error.\n"); } 

%%
