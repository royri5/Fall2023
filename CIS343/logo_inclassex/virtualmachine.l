%{
    #include <stdio.h>
%}
 

 
%%

\[                  { return LEFT_BRACK; }
\]                  { return RIGHT_BRACK; }
\(                  { return LEFT_PAREN; }
\)                  { return RIGHT_PAREN; }
,                   { return COMMA; }
=                   { return EQUALS; }
RAM                 { return RAM; }
OS                  { return OS; }
CORES               { return CORES; }
USERS               { return USERS; }
[a-z]{1}[A-Za-z\.]+     

%%
