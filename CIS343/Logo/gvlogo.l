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
print                  { return PRINT; }
save                                  { return SAVE; }
color      { return COLOR; }
clear                                 { return CLEAR; }
turn                         { return TURN; }
move                          { return MOVE; }
goto                  { return GOTO; }
where                                 { return WHERE; }
;                                     { return SEP; }
\"[A-Za-z]+\"                         { yylval.s = yytext; return STRING; }
[ \t\r\n]			                  ;
.			                          { yyerror("Lexing Syntax error.\n"); } 

%%
