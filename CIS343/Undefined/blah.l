%{
            #include <stdio.h>
            #include <stdlib.h>
            long long total = 0;
%}

%%
\"[A-Za-z]*\"                       { printf("OSTRING %s\n", yytext);}
-?[0-9]+                            { total += atoi(yytext); printf("%lld\n", total); }
[ \n\t\r]                           {;}
.                                   {;}

%%

int main(int argc, char** argv) {
    yylex();
}