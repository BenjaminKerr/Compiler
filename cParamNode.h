#pragma once
//**************************************
// cParamNode.h
//
// Defines AST node for a function parameter.
//
// Author: Benjamin Kerr
//
#include "cAstNode.h"
#include "cVarDeclNode.h"

class cParamNode : public cAstNode
{
    public:
        // param is the variable declaration for this parameter
        cParamNode(cVarDeclNode *varDecl) : cAstNode()
        {
            AddChild(varDecl);
        }
        
        virtual string NodeType() { return string("param"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};