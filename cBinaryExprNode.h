#pragma once
//**************************************
// cBinaryExprNode.h
//
// AST node for binary expressions (two operands and an operator).
//
// Inherits from cExprNode so binary expressions can appear anywhere an
// expression is expected. Type resolution follows standard C promotion rules.
//
// Child layout:
//   child(0): cExprNode* -- left operand
//   child(1): cOpNode*   -- operator (token value from langparse.h)
//   child(2): cExprNode* -- right operand
//
// Author: Benjamin Kerr
//
// Date: 2025
//

#include "cAstNode.h"
#include "cExprNode.h"
#include "cOpNode.h"
#include "cSymbolTable.h"
#include "langparse.h"  // token constants: EQUALS, NOT_EQUALS, LE, GE, AND, OR

class cBinaryExprNode : public cExprNode
{
    public:
        cBinaryExprNode(cExprNode *left, cOpNode *op, cExprNode *right)
            : cExprNode()
        {
            AddChild(left);
            AddChild(op);
            AddChild(right);
        }

        // Determine the result type of this expression.
        // Relational and logical operators always yield int.
        // Arithmetic operators follow C-style type promotion:
        //   double > float > larger integer > smaller integer.
        cDeclNode* GetType() override
        {
            cOpNode *opNode = dynamic_cast<cOpNode*>(GetChild(1));
            if (opNode != nullptr)
            {
                int op = opNode->GetOp();

                // Relational and logical operators always return int
                if (op == EQUALS || op == NOT_EQUALS ||
                    op == '<'    || op == '>'         ||
                    op == LE     || op == GE           ||
                    op == AND    || op == OR)
                {
                    cSymbol *intSym = g_symbolTable.Find("int");
                    if (intSym != nullptr) return intSym->GetDecl();
                }
            }

            cExprNode *left  = dynamic_cast<cExprNode*>(GetChild(0));
            cExprNode *right = dynamic_cast<cExprNode*>(GetChild(2));

            if (left == nullptr || right == nullptr) return nullptr;

            cDeclNode *leftType  = left->GetType();
            cDeclNode *rightType = right->GetType();

            if (leftType == nullptr || rightType == nullptr) return nullptr;

            // Promote to double if either operand is double (float, size 8)
            if ((leftType->IsFloat()  && leftType->GetSize()  == 8) ||
                (rightType->IsFloat() && rightType->GetSize() == 8))
            {
                cSymbol *doubleSym = g_symbolTable.Find("double");
                if (doubleSym != nullptr) return doubleSym->GetDecl();
            }

            // Promote to float if either operand is float
            if (leftType->IsFloat() || rightType->IsFloat())
            {
                cSymbol *floatSym = g_symbolTable.Find("float");
                if (floatSym != nullptr) return floatSym->GetDecl();
            }

            // Both integers: return the wider type
            return (leftType->GetSize() >= rightType->GetSize()) ? leftType : rightType;
        }

        std::string NodeType() override { return std::string("expr"); }
        void Visit(cVisitor *visitor) override { visitor->Visit(this); }
};