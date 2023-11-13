%{
#include <stdio.h>
#include <stdlib.h>
#include "gvlogo.tab.h"

extern void yyerror(const char* s);
%}

%option yylineno

%%
[0-9]+                                { yylval.n = atoi(yytext); return NUMBER; }
penup                                 { return PENUP; }
pendown                               { return PENDOWN; }
print\ \"[A-Za-z]+\"                  { return PRINT; }
save                                  { return SAVE; }
color\ [0-255]\ [0-255]\ [0-255]      { return COLOR; }
clear                                 { return CLEAR; }
turn\ [0-360]                         { return TURN; }
move\ [0-9]+                          { return MOVE; }
goto\ [0-9]+\ [0-9]+                  { return GOTO; }
where                                 { return WHERE; }
\"[A-Za-z]+\"                         { yylval.s = yytext; return QSTRING; }
[ \t\r\n]			                  ;
.			                          { yyerror("Lexing Syntax error.\n"); } 

%%
