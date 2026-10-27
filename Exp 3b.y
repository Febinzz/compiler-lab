%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror();
%}
%token N D
%%
exp:D
|exp D
|exp N 
;
%%
int main()
{
    printf("enter the expression\n");
    yyparse();
    printf("valid\n");
    return 0;
}
int yyerror()
{
    printf("invalid\n");
    exit(0);
}
int yywrap()
{
    return 1;
}
