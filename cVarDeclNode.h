#pragma once
//**************************************
// cVarDeclNode.h
//
// Defines an AST node for variable declarations.
//
// Author: Benjamin Kerr
//
#include "cAstNode.h"
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"

class cVarDeclNode : public cDeclNode
{
    public:
        // params are the type and variable name
        cVarDeclNode(cSymbol *type, cSymbol *name) : cDeclNode()
        {
            AddChild(type);
            AddChild(name);
            
            // Semantic check: Check for duplicate definition in current scope
            cSymbol* existing = g_symbolTable.FindLocal(name->GetName());
            if (existing != nullptr && existing->GetDecl() != nullptr) {
                SemanticParseError("Symbol " + name->GetName() + 
                                " already defined in current scope");
            } else {
                // Set this declaration as the symbol's decl
                name->SetDecl(this);
            }
        }
        virtual string NodeType() { return string("var_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        virtual bool IsVar() { return true; }

        virtual cDeclNode* GetType() 
        { 
            // First child is the type symbol
            cSymbol* typeSym = dynamic_cast<cSymbol*>(GetChild(0));
            if (typeSym != nullptr)
                return typeSym->GetDecl();
            return nullptr;
        }
};