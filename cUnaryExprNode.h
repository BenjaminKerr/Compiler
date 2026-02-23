#pragma once
//**************************************
// cUnaryExprNode.h
//
// Defines AST node for unary expressions (expressions with one operand).
//
// Author: Benjamin Kerr
//
#include "cAstNode.h"
#include "cExprNode.h"
#include "cOpNode.h"
#include "cSymbolTable.h"

class cUnaryExprNode : public cExprNode
{
    public:
        // params are the operator and the expression
        cUnaryExprNode(cOpNode *op, cExprNode *expr) : cExprNode()
        {
            AddChild(op);
            AddChild(expr);
        }

        virtual cDeclNode* GetType() 
        {
            // Unary expression has same type as its operand
            cExprNode* expr = dynamic_cast<cExprNode*>(GetChild(1));
            if (expr != nullptr)
                return expr->GetType();
            return nullptr;
        }

        virtual string NodeType() { return string("unary"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};