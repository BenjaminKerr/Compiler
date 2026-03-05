//**************************************
// main.cpp
//
// Main function for lang compiler
//
// Author: Benjamin Kerr
//
// Date: 2025
//

#include <cstdio>
#include <cstdlib>
#include <unistd.h> // no C++ equivalent for dup2, so we use the POSIX version
#include <iostream>
#include <fstream>
#include <map>
#include "lex.h"
#include "astnodes.h"
#include "langparse.h"
#include "cSymbolTable.h"
#include "cSemantics.h"
#include "cComputeSize.h"

// g_typeSymbols is defined in cSemantics.cpp and used during semantic analysis
// to resolve type names. It mirrors entries in g_symbolTable but provides
// direct name->symbol lookup without a full table traversal.
extern std::map<std::string, cSymbol*> g_typeSymbols;

// Global symbol table shared across all compilation phases
cSymbolTable g_symbolTable;

// Register a built-in primitive type in both the symbol table and type map
static void RegisterBuiltinType(const std::string &name, int size, bool isFloat)
{
    cSymbol *sym = new cSymbol(name);
    cBaseTypeNode *type = new cBaseTypeNode(name, size, isFloat);
    sym->SetDecl(type);
    g_symbolTable.Insert(sym);
    g_typeSymbols[name] = sym;
}

int main(int argc, char **argv)
{
    const char *outfile_name;
    int result = 0;

    // Redirect stdin to source file if provided
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == nullptr)
        {
            std::cerr << "ERROR: Unable to open file " << argv[1] << "\n";
            return 1;
        }
    }

    // Redirect stdout to output file if provided, using dup2 to ensure that
    // any code writing to fd 1 (including bison/flex internals) goes to the file
    if (argc > 2)
    {
        outfile_name = argv[2];
        FILE *output = fopen(outfile_name, "w");
        if (output == nullptr)
        {
            std::cerr << "Unable to open output file " << outfile_name << "\n";
            return 1;
        }
        int output_fd = fileno(output);
        if (dup2(output_fd, 1) != 1)
        {
            std::cerr << "Unable to configure output stream\n";
            return 1;
        }
    }

    // Register all built-in primitive types before parsing begins
    RegisterBuiltinType("char",   1, false);
    RegisterBuiltinType("int",    4, false);
    RegisterBuiltinType("float",  4, true);
    RegisterBuiltinType("long",   8, false);
    RegisterBuiltinType("double", 8, true);

    result = yyparse();

    if (yyast_root != nullptr && result == 0)
    {
        // Run semantic analysis pass (type checking, symbol resolution)
        cSemantics semantics;
        semantics.VisitAllNodes(yyast_root);

        result += yynerrs;

        if (result == 0)
        {
            // Run size/offset computation pass for memory layout
            cComputeSize sizer;
            sizer.VisitAllNodes(yyast_root);

            std::cout << yyast_root->ToString() << std::endl;
        }
    }

    if (yynerrs != 0)
    {
        std::cout << yynerrs << " Errors in compile\n";
    }

    // Call yylex() one more time to check for unconsumed tokens after parse
    if (result == 0 && yylex() != 0)
    {
        std::cerr << "Junk at end of program\n";
    }

    return result;
}