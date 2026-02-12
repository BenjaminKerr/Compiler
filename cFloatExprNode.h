#pragma once
//**************************************
// cFloatExprNode.h
//
// Defines an AST node for a float constant (literals).
//
// Inherits from cExprNode so that float constants can be used anywhere 
// expressions are used.
//
// Author: Benjamin Kerr
//
#include "cAstNode.h"
#include "cExprNode.h"
#include "cSymbolTable.h"

class cFloatExprNode : public cExprNode
{
    public:
        // param is the value of the float constant
        cFloatExprNode(double value) : cExprNode()
        {
            m_value = value;
        }
        virtual cDeclNode* GetType() 
        {
            // Float literals are always float type
            cSymbol* floatSym = g_symbolTable.Find("float");
            if (floatSym != nullptr)
                return floatSym->GetDecl();
            
            return nullptr;
        }
        virtual string AttributesToString() 
        {
            return " value=\"" + std::to_string(m_value) + "\"";
        }
        virtual string NodeType() { return string("float"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
        double m_value;        // value of float constant (literal)
};
