%{
//**************************************
// calc.l
//
// Scanner for CST 320 Lab 3
//
// Author: Benjamin Kerr
//

#include "lex.h"

// Define token values
#define END_TOKEN 256
#define NUM_TOKEN 257
#define IDENT_TOKEN 258

%}

%option yylineno
%option noyywrap

%%

"end"           { return END_TOKEN; }

[0-9]+          { return NUM_TOKEN; }

[a-zA-Z_][a-zA-Z0-9_]*  { return IDENT_TOKEN; }

"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"("             { return '('; }
")"             { return ')'; }
"["             { return '['; }
"]"             { return ']'; }
"{"             { return '{'; }
"}"             { return '}'; }
";"             { return ';'; }
"="             { return '='; }

"//".*          { /* C++ style comment - ignore */ }

[ \t\n\r]+      { /* whitespace - ignore */ }

.               { return yytext[0]; }

%%