%{
 #include "y.tab.h"
%}
%%
[0-9]+ {return N;}
[a-zA-Z][_a-zA-Z0-9]* {return D;}
[\n] {return 0;}
[\t] {}
[.] {return yytext[0];}
%%
