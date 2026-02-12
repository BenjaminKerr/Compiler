#pragma once
//**************************************
// cBinaryExprNode.h
//
// Defines an AST node for binary expressions (expressions with two operands).
//
// Inherits from cExprNode so that binary expressions can be used anywhere 
// expressions are used.
//
// Author: Benjamin Kerr
//
#include "cAstNode.h"
#include "cExprNode.h"
#include "cOpNode.h"
#include "cSymbolTable.h"

class cBinaryExprNode : public cExprNode
{
    public:
        // params are the left expression, operator, and right expression
        cBinaryExprNode(cExprNode *left, cOpNode *op, cExprNode *right) 
            : cExprNode()
        {
            AddChild(left);
            AddChild(op);
            AddChild(right);
        }
        virtual cDeclNode* GetType() 
        {
            // Get left and right expression types
            cExprNode* left = dynamic_cast<cExprNode*>(GetChild(0));
            cExprNode* right = dynamic_cast<cExprNode*>(GetChild(2));
            
            if (left == nullptr || right == nullptr)
                return nullptr;
            
            cDeclNode* leftType = left->GetType();
            cDeclNode* rightType = right->GetType();
            
            if (leftType == nullptr || rightType == nullptr)
                return nullptr;
            
            // If either operand is float, result is float
            if (leftType->IsFloat() || rightType->IsFloat()) {
                cSymbol* floatSym = g_symbolTable.Find("float");
                if (floatSym != nullptr)
                    return floatSym->GetDecl();
            }
            
            // If either is int, result is int
            if (leftType->IsInt() || rightType->IsInt()) {
                cSymbol* intSym = g_symbolTable.Find("int");
                if (intSym != nullptr)
                    return intSym->GetDecl();
            }
            
            // Otherwise return char
            cSymbol* charSym = g_symbolTable.Find("char");
            if (charSym != nullptr)
                return charSym->GetDecl();
            
            return nullptr;
        }
        virtual string NodeType() { return string("expr"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};