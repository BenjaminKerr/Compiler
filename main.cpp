//**************************************
// main.cpp
//
// main routine for lang compiler.
// This version only runs the lexer
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 23, 2015
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "cSymbol.h"
#include "cSymbolTable.h"

#include "lex.h"
#include "tokens.h"

cSymbolTable g_symbolTable;
long long cSymbol::nextId = 0;
yylval_t yylval;    // lexer value
int g_insert = 1;       // global to indicate that symbols should be
                            // inserted into the symbol table
int g_local = 0;         // global to indicate to do local lookups

// Uncomment the following line after integrating your symbol table with
// your scanner.
#define TEST2

//****************************************
// argv[1] contains the file to process
// argv[2] if given, contains the name of the output file
int main(int argc, char **argv)
{
    const char *outfile_name;
    int result = 0;
    int token;

    std::cout << "Benjamin Kerr\n";

    int do_test2 = 0;
    

    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            std::cerr << "Unable to open file " << argv[1] << "\n";
            exit(-1);
        }
    }

    if (argc > 2)
    {
        outfile_name = argv[2];
        FILE *output = fopen(outfile_name, "w");
        if (output == NULL)
        {
            std::cerr << "Unable to open output file " << outfile_name << "\n";
            exit(-1);
        }
        int output_fd = fileno(output);
        if (dup2(output_fd, 1) != 1)
        {
            std::cerr << "Unable to send output to " << outfile_name << "\n";
            exit(-2);
        }
    }

    
    if (argc > 3) do_test2 = 1;

    token = yylex();
    while (token != 0)
    {
                // if we found an identifier, print it out
        if (token == IDENTIFIER) 
        {
            cSymbol *sym;
            if (!g_insert)
            {
                if (g_local)
                    sym = g_symbolTable.FindLocal(yylval.symbol->GetName());
                else
                    sym = g_symbolTable.Find(yylval.symbol->GetName());

                if (sym != nullptr) yylval.symbol = sym;
            }

            // token output is handled by TEST2 printf below
        }
        else if (token == LOCAL)
        {
            g_local = 1;
        }
        else if (token == GLOBAL)
        {
            g_local = 0;
        }
        else if (token == LOOKUP)
        {
            g_insert = 0;
        }
        else if (token == INSERT)
        {
            g_insert = 1;
        }
        else if (token == '{')
        {
            g_symbolTable.IncreaseScope();
        }
        else if (token == '}')
        {
            g_symbolTable.DecreaseScope();
        }

#ifdef TEST2
        if (do_test2 && token == IDENTIFIER)
            printf("%d:%s:%lld\n", token, yytext, yylval.symbol->GetId());
        else
            printf("%d:%s\n", token, yytext);
#else
        if (do_test2)
        {
            fprintf(stderr, "Not compiled with TEST2 defined\n");
            return 0;
        }
        else
            printf("%d:%s\n", token, yytext);
#endif

        token = yylex();
    }

    
    return result;
}
