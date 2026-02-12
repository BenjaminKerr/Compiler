%{
#include <stdio.h>
#include "cSymbol.h"
#include "cSymbolTable.h"
#include "lex.h"
#include "langparse.h"
#include "cDeclNode.h"

#include <map>
std::map<std::string, cSymbol*> g_typeSymbols;

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
"struct"             DO_RETURN(STRUCT);
"array"              DO_RETURN(ARRAY);
"return"             DO_RETURN(RETURN);

[a-zA-Z_][a-zA-Z0-9_]* { DO_RETURN(Process_ID(yytext)); }

[0-9]+               {
                         yylval.int_val = atoi(yytext);
                         DO_RETURN(INT_VAL);
                       }

[0-9]+"."[0-9]+      {
                         yylval.float_val = atof(yytext);
                         DO_RETURN(FLOAT_VAL);
                       }


\"([^\\"]|\\.)*\"    { return STRING_LIT; }

.                    { return JUNK_TOKEN; }

%%

int Process_ID(const char *id) {
    // Check if this is a predefined type
    auto it = g_typeSymbols.find(id);
    if (it != g_typeSymbols.end()) {
        yylval.symbol = it->second;
        return TYPE_ID;
    }
    
    // Check if this identifier already exists in the symbol table
    cSymbol *sym = g_symbolTable.Find(id);
    if (sym != nullptr) {
        yylval.symbol = sym;
        // Check if it's a user-defined type (struct)
        if (sym->GetDecl() != nullptr && sym->GetDecl()->IsType()) {
            return TYPE_ID;
        }
        return IDENTIFIER;
    }
    
    // Create a new symbol and add it to the table
    cSymbol *newSym = new cSymbol(id);
    g_symbolTable.Insert(newSym);
    yylval.symbol = newSym;
    return IDENTIFIER;
}

// This function allows us to do extra processing on each token
int Return(int val) {
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}
