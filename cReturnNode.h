#pragma once
//**************************************
// cReturnNode.h
//
// Defines AST node for return statements.
//
// Author: Benjamin Kerr
//
#include "cAstNode.h"
#include "cStmtNode.h"
#include "cExprNode.h"

class cReturnNode : public cStmtNode
{
    public:
        // param is the expression to return (can be nullptr for void returns)
        cReturnNode(cExprNode *expr) : cStmtNode()
        {
            if (expr != nullptr)
                AddChild(expr);
        }

        virtual string NodeType() { return string("return"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};