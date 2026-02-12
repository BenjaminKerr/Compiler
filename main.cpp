//**************************************
// main.cpp
//
// Main function for lang compiler
//
// Author: Phil Howard 
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "lex.h"
#include "astnodes.h"
#include "langparse.h"
#include "cSymbolTable.h"
#include <map>

extern std::map<std::string, cSymbol*> g_typeSymbols;

// define global variables
cSymbolTable g_symbolTable;
long long cSymbol::nextId;

// takes two string args: input_file, and output_file
int main(int argc, char **argv)
{
    std::cout << "Benjamin Kerr" << std::endl;

    const char *outfile_name;
    int result = 0;

    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == nullptr)
        {
            std::cerr << "ERROR: Unable to open file " << argv[1] << "\n";
            exit(-1);
        }
    }

    // Setup the output. If empty, use stdout (which may be redirected)
    if (argc > 2)
    {
        outfile_name = argv[2];

        FILE *output = fopen(outfile_name, "w");
        if (output == nullptr)
        {
            std::cerr << "Unable to open output file " << outfile_name << "\n";
            exit(-1);
        }

        // redirect stdout to the output file
        int output_fd = fileno(output);
        if (dup2(output_fd, 1) != 1)
        {
            std::cerr << "Unable configure output stream\n";
            exit(-1);
        }
    }

    // Initialize pre-defined type symbols
    // Initialize pre-defined type symbols
    cSymbol *charSym = new cSymbol("char");
    cBaseTypeNode *charType = new cBaseTypeNode("char", 1, false);
    charSym->SetDecl(charType);

    cSymbol *intSym = new cSymbol("int");
    cBaseTypeNode *intType = new cBaseTypeNode("int", 4, false);
    intSym->SetDecl(intType);

    cSymbol *floatSym = new cSymbol("float");
    cBaseTypeNode *floatType = new cBaseTypeNode("float", 4, true);
    floatSym->SetDecl(floatType);

    cSymbol *longSym = new cSymbol("long");
    cBaseTypeNode *longType = new cBaseTypeNode("long", 8, false);
    longSym->SetDecl(longType);

    cSymbol *doubleSym = new cSymbol("double");
    cBaseTypeNode *doubleType = new cBaseTypeNode("double", 8, true);
    doubleSym->SetDecl(doubleType);

    g_typeSymbols["char"] = charSym;
    g_typeSymbols["int"] = intSym;
    g_typeSymbols["float"] = floatSym;
    g_typeSymbols["long"] = longSym;
    g_typeSymbols["double"] = doubleSym;
    
    result = yyparse();
    if (yyast_root != nullptr)
    {
        if (result == 0)
        {
            std::cout << yyast_root->ToString();
        } else {
            std::cout << yynerrs << " Errors in compile\n";
        }
    }

    if (result == 0 && yylex() != 0)
    {
        std::cout << "Junk at end of program\n";
    }

    return result;
}
