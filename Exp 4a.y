%{
#include <stdio.h>
int yylex();
int yyerror();
int flag=0;
%}
%token N 
%left '+''-'
%left '*''/''%'
%%
ArithmeticExpression:E{
    printf("result:%d\n",$$);
    return 0;
    };
E:E'+'E{$$=$1+$3;}
|E'-'E{$$=$1-$3;}
|E'*'E{$$=$1*$3;}
|E'/'E{$$=$1/$3;}
|E'%'E{$$=$1%$3;}
|'('E')'{$$=$2;}
|N{$$=$1;}
;
%%
int yyerror()
{
    printf("invald\n");
    flag=1;
    return 0;
}
int main()
{
    printf("enter the expression\n");
    yyparse();
    if(flag==0)
    printf("valid\n");
    return 0;
}
int yywrap()
{
    return 1;
}
