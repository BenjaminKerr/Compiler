#pragma once
//**************************************
// cSymbolTable.h
//
// Nested scope symbol table for the lang compiler.
//
// Scopes are managed as a stack of hash maps. The innermost (most recently
// opened) scope is at the back of the vector. Lookups search from innermost
// to outermost, implementing standard lexical scoping rules.
//
// Author: Phil Howard
// phil.howard@oit.edu
//
// Modified by: Benjamin Kerr
//
// Date: 2025
//

#include <string>
#include <vector>
#include <unordered_map>

class cSymbol;

// A single scope level: maps symbol names to their cSymbol instances
using scope_t = std::unordered_map<std::string, cSymbol*>;

class cSymbolTable
{
    public:
        // Construct an empty symbol table with one global scope
        cSymbolTable();

        // Open a new inner scope and return a pointer to it
        scope_t *IncreaseScope();

        // Close the innermost scope and return a pointer to the new innermost.
        // Returns nullptr if the table is now empty.
        //
        // NOTE: do NOT delete the popped scope. Parts of the AST may still
        // hold pointers to symbols that were declared in it.
        scope_t *DecreaseScope();

        // Insert a symbol into the innermost scope.
        // Assumes the symbol is not already present in the current scope.
        void Insert(cSymbol *sym);

        // Search all scopes from innermost to outermost for a symbol by name.
        // Returns the first (innermost) match, or nullptr if not found.
        cSymbol *Find(std::string name);

        // Search only the innermost scope for a symbol by name.
        // Returns nullptr if not found.
        cSymbol *FindLocal(std::string name);

    private:
        std::vector<scope_t> m_scopes;  // Stack of scopes; back() is innermost
};

// Global symbol table shared across all compilation phases; defined in main.cpp
extern cSymbolTable g_symbolTable;