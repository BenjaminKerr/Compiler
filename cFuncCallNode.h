#pragma once
//**************************************
// cFuncCallNode.h
//
// Defines AST node for function calls.
//
// Author: Benjamin Kerr
//
#include "cAstNode.h"
#include "cExprNode.h"
#include "cSymbol.h"
#include "cDeclNode.h"

class cFuncCallNode : public cExprNode
{
    public:
        // Constructor with parameters
        cFuncCallNode(cSymbol *funcName, cAstNode *params) : cExprNode()
        {
            AddChild(funcName);
            if (params != nullptr)
                AddChild(params);
            
            // Semantic check: verify function is defined
            if (funcName->GetDecl() == nullptr) {
                SemanticParseError("Symbol " + funcName->GetName() + " not defined");
            }
        }
        
        // Constructor without parameters
        cFuncCallNode(cSymbol *funcName) : cExprNode()
        {
            AddChild(funcName);
            
            // Semantic check: verify function is defined
            if (funcName->GetDecl() == nullptr) {
                SemanticParseError("Symbol " + funcName->GetName() + " not defined");
            }
        }
        
        virtual cDeclNode* GetType() 
        {
            cSymbol* funcSym = dynamic_cast<cSymbol*>(GetChild(0));
            if (funcSym != nullptr && funcSym->GetDecl() != nullptr) {
                return funcSym->GetDecl()->GetType();
            }
            return nullptr;
        }

        virtual string NodeType() { return string("funcCall"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};