#pragma once
//**************************************
// cVarDeclNode.h
//
// AST node for variable declarations (e.g. "int x;").
//
// Child layout:
//   child(0): cSymbol* -- the type of the variable
//   child(1): cSymbol* -- the name of the variable
//
// Author: Benjamin Kerr
//
// Date: 2025
//

#include "cAstNode.h"
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"

class cVarDeclNode : public cDeclNode
{
    public:
        // Declare a variable of the given type and name.
        // Reports a semantic error if the name is already declared in the
        // current (innermost) scope.
        cVarDeclNode(cSymbol *type, cSymbol *name) : cDeclNode()
        {
            AddChild(type);
            AddChild(name);

            // Use FindLocal to restrict redeclaration check to the current
            // scope only -- shadowing an outer-scope symbol is allowed.
            if (g_symbolTable.FindLocal(name->GetName()) != nullptr)
            {
                SemanticParseError("Symbol " + name->GetName() +
                                   " already defined in current scope");
            }
            else
            {
                name->SetDecl(this);
            }
        }

        bool IsVar() override { return true; }

        // Return the declaration node for this variable's type
        cDeclNode* GetType() override
        {
            cSymbol *typeSym = dynamic_cast<cSymbol*>(GetChild(0));
            if (typeSym != nullptr) return typeSym->GetDecl();
            return nullptr;
        }

        std::string GetName() override
        {
            cSymbol *nameSym = dynamic_cast<cSymbol*>(GetChild(1));
            if (nameSym != nullptr) return nameSym->GetName();
            return "";
        }

        std::string NodeType() override { return std::string("var_decl"); }
        void Visit(cVisitor *visitor) override { visitor->Visit(this); }
};