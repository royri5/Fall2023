%{
#include <stdio.h>
#include <stdlib.h>
#include "gvlogo.tab.h"

extern void yyerror(const char* s);
%}

%%

penup        { return PENUP; }
pendown      { return PENDOWN; }
print\ \"[A-Za-z]+\"       { return PRINT; }
save        { return SAVE; }
color\ [0-255]\ [0-255]\ [0-255]       { return COLOR; }
clear       { return CLEAR; }
turn       { return TURN; }
move       { return MOVE; }
goto       { return GOTO; }
where      { return WHERE; }
[ \t\r\n]			;
.			{ yyerror("Lexing Syntax error.\n"); } 

%%
