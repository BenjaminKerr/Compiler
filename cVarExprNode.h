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
        cVarExprNode(cSymbol *symbol) : cExprNode()
        {
            AddChild(symbol);
            m_size = 0;
            m_offset = 0;
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

        virtual string AttributesToString()
        {
            string result = "";
            // Always show size and offset for varrefs that have been processed
            // We know it's processed if we've visited it (check if we have a symbol child)
            if (NumChildren() > 0)
            {
                result += " size=\"" + std::to_string(m_size) + "\"";
                result += " offset=\"" + std::to_string(m_offset) + "\"";
            }
            return result;
        }

        int GetSize() { return m_size; }
        void SetSize(int size) { m_size = size; }
        int GetOffset() { return m_offset; }
        void SetOffset(int offset) { m_offset = offset; }

    protected:
        int m_size;
        int m_offset;
};