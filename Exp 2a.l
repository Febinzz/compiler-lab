letter [a-zA-Z]
digit [0-9]
%%
#.* {printf("\n%s is a preprocessor directive",yytext);}
{digit}+("E"("+"|"-")?{digit}+)? {printf("\n%s\tis real number",yytext);}
{digit}+"."{digit}+("E"("+"|"-")?{digit}+)? {printf("\n%s\t is floating pt no ",yytext);}
"void"|"if"|"else"|"int"|"char"|"switch"|"return"|"struct"|"do"|"while"|"for"|"float" {printf("\n%s\t is keywords",yytext);}
"\a"|"\\n"|"\\b"|"\t"|"\\t"|"\b"|"\\a" {printf("\n%s\tis Escape sequences",yytext);}
{letter}({letter}|{digit})* {printf("\n%s\tis identifier",yytext);}
"&&"|"<"|">"|"<="|">="|"="|"+"|"-"|"?"|"*"|"/"|"%"|"&"|"||" {printf("\n%s\toperator ",yytext);}
"{"|"}"|"["|"]"|"("|")"|"#"|"'"|"."|"\""|"\\"|";"|"," {printf("\n%s\t is a special character",yytext);}
"%d"|"%s"|"%c"|"%f"|"%e" {printf("\n%s\tis a format specifier",yytext);}
[ \t]+ ;
\n ;
%%
int yywrap()
{
    return 1;
}
int main()
{
    printf("Enter the input (Ctrl+D to stop):\n");
    yylex();
    return 0;
}
