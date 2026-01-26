#pragma once
//**************************************
// lex.h
//
// Defines global symbols used the the flex generated lexer 
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

// Token definitions
#define END_TOKEN 256
#define NUM_TOKEN 257
#define IDENT_TOKEN 258

int yylex();
extern char *yytext;
extern int yylineno;
extern int yynerrs;
extern FILE *yyin;