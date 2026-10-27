%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror();
%}
%token N D
%left '+''-'
%left '*''/'
%%
exp:exp'+'exp
|exp'-'exp
|exp'*'exp
|exp'/'exp
|'('exp')'
|'{'exp'}'
|'['exp']'
|N 
|D
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
    exit(1);
}
int yywrap()
{
    return 1;
}


