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
            // Get the operator to check if it's relational/logical
            cOpNode* opNode = dynamic_cast<cOpNode*>(GetChild(1));
            if (opNode != nullptr)
            {
                int op = opNode->GetOp();
                
                // Relational and logical operators ALWAYS return int
                if (op == EQUALS || op == NOT_EQUALS ||
                    op == '<' || op == '>' ||
                    op == LE || op == GE ||
                    op == AND || op == OR)
                {
                    cSymbol* intSym = g_symbolTable.Find("int");
                    if (intSym != nullptr)
                        return intSym->GetDecl();
                }
            }
            
            // For arithmetic operators, use type promotion rules
            cExprNode* left = dynamic_cast<cExprNode*>(GetChild(0));
            cExprNode* right = dynamic_cast<cExprNode*>(GetChild(2));
            
            if (left == nullptr || right == nullptr)
                return nullptr;
            
            cDeclNode* leftType = left->GetType();
            cDeclNode* rightType = right->GetType();
            
            if (leftType == nullptr || rightType == nullptr)
                return nullptr;
            
            // If either is double, result is double
            if ((leftType->IsFloat() && leftType->GetSize() == 8) ||
                (rightType->IsFloat() && rightType->GetSize() == 8))
            {
                cSymbol* doubleSym = g_symbolTable.Find("double");
                if (doubleSym != nullptr)
                    return doubleSym->GetDecl();
            }
            
            // If either is float, result is float
            if (leftType->IsFloat() || rightType->IsFloat())
            {
                cSymbol* floatSym = g_symbolTable.Find("float");
                if (floatSym != nullptr)
                    return floatSym->GetDecl();
            }
            
            // Both are integers - return the larger type
            if (leftType->GetSize() >= rightType->GetSize())
                return leftType;
            
            return rightType;
        }
        virtual string NodeType() { return string("expr"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};