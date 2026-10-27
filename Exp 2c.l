%{
#include <stdio.h>
int vo=0;
int con=0; 
%}
%%
[aeiouAEIOU] {vo++;}
[a-zA-Z] {con++;}
[\t];
[\n];
[.];
%%
int yywrap()
{
    return 1;
}
int main()
{
    printf("enter the expression\n");
    yylex();
    printf("vowels:%d\n consonants:%d\n",vo,con);
    return 0;
}
