#pragma once
//**************************************
// cVarExprNode.h
//
// Defines an AST node for variable references.
//
// Author: Benjamin Kerr
//
#include "cAstNode.h"
#include "cExprNode.h"
#include "cSymbol.h"

class cVarExprNode : public cExprNode
{
    public:
        // param is the variable symbol (or list for struct field refs)
        cVarExprNode(cSymbol *var) : cExprNode()
        {
            AddChild(var);
            
            // Semantic check: Check if variable is defined
            if (var->GetDecl() == nullptr) {
                SemanticParseError("Symbol " + var->GetName() + " not defined");
            }
        }
        virtual cDeclNode* GetType() 
        {
            // Get the first symbol (variable name)
            cSymbol* varSym = dynamic_cast<cSymbol*>(GetChild(0));
            if (varSym != nullptr && varSym->GetDecl() != nullptr) {
                return varSym->GetDecl()->GetType();
            }
            
            return nullptr;
        }        
        // Add another symbol (for struct field access like a.b.c)
        void AddSymbol(cSymbol *var)
        {
            AddChild(var);
        }        
        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};