#pragma once
//**************************************
// cAssignNode.h
//
// Defines AST node for assignment statements.
//
// Author: Benjamin Kerr
//
#include "cAstNode.h"
#include "cStmtNode.h"
#include "cExprNode.h"

class cAssignNode : public cStmtNode
{
    public:
        // params are the left side (lval) and right side (expr)
        cAssignNode(cAstNode *lval, cExprNode *expr) : cStmtNode()
        {
            AddChild(lval);
            AddChild(expr);
        }

        // Get left side of assignment
        cAstNode* GetLval()  { return GetChild(0); }

        // Get right side of assignment
        cExprNode* GetExpr() { return (cExprNode*)GetChild(1); }

        virtual string NodeType() { return string("assign"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};