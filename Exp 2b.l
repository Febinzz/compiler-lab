%{
    #include <stdio.h>
    int lines=0;
    int words=0;
    int charr=0;
%}
%%
[\n] {lines++;charr++;}
[\t]+ {charr+=yyleng;}
[^ \t\n]+ {words++;charr+=yyleng;}
%%
int yywrap()
{
    return 1;
}
int main()
{
    printf("enter the expressions\n");
    yylex();
    printf("lines:%d\n words:%d\nchar :%d",lines,words,charr);
    return 0;
}
