%{
#include <stdio.h>
#include "cSymbol.h"
#include "cSymbolTable.h"
#include "lex.h"
#include "tokens.h"

#ifdef DEBUG_OUTPUT
    #define DO_RETURN(a) { return Return(a); }
#else
    #define DO_RETURN(a) { return (a); }
#endif

int Return(int val);
int Process_ID(const char *id);
%}

%option noyywrap
%option noinput
%option nounput
%option yylineno

%%

[\t\n\r ]+           {} // Ignore whitespace
"//".*                {} // Ignore single-line comments

"{"                   { return '{'; } // return ASCII for punctuation
"}"                   { return '}'; } // return ASCII for punctuation
"("                   { return '('; }
")"                   { return ')'; }
"["                   { return '['; }
"]"                   { return ']'; }
";"                   { return ';'; }
","                   { return ','; }
"."                   { return '.'; }

"!="                  { return NOT_EQUALS; }
"=="                  { return EQUALS; }
"&&"                  { return AND; }
"||"                  { return OR; }
">="                  { return GE; }
"<="                  { return LE; }
">"                   { return '>'; }
"<"                   { return '<'; }
"+"                   { return '+'; }
"-"                   { return '-'; }
"*"                   { return '*'; }
"/"                   { return '/'; }
"%"                   { return '%'; }
"="                   { return '='; }

"program"            DO_RETURN(PROGRAM);
"if"                 DO_RETURN(IF);
"else"               DO_RETURN(ELSE);
"endif"              DO_RETURN(ENDIF);
"while"              DO_RETURN(WHILE);
"print"              DO_RETURN(PRINT);
"char"               DO_RETURN(CHAR);
"int"                DO_RETURN(INT);
"long"               DO_RETURN(LONG);
"float"              DO_RETURN(FLOAT);
"double"             DO_RETURN(DOUBLE);
"struct"             DO_RETURN(STRUCT);
"array"              DO_RETURN(ARRAY);
"return"             DO_RETURN(RETURN);

[a-zA-Z_][a-zA-Z0-9_]* { DO_RETURN(Process_ID(yytext)); }

[0-9]+               { 
                        yylval.symbol = new cSymbol(yytext); 
                        return INT_VAL; 
                      }

[0-9]+"."[0-9]+     { return FLOAT_VAL; }


\"([^\\"]|\\.)*\"    { return STRING_LIT; }

.                    { return JUNK_TOKEN; }

%%

// Process identifier: lookup/insert into symbol table and return token
int Process_ID(const char *id) {
    cSymbol *tempSym = g_symbolTable.FindLocal(id);
    if (tempSym == nullptr) {
        tempSym = new cSymbol(id);
        g_symbolTable.Insert(tempSym);
    }
    yylval.symbol = tempSym;
    return IDENTIFIER;
}

// This function allows us to do extra processing on each token
int Return(int val) {
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}
