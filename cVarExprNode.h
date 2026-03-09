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
            cSymbol* varSym = dynamic_cast<cSymbol*>(GetChild(0));
            if (varSym == nullptr || varSym->GetDecl() == nullptr) return nullptr;

            cDeclNode* type = varSym->GetDecl()->GetType();

            // For each subscript child, dereference one array level
            for (int i = 1; i < NumChildren(); i++)
            {
                cSymbol* fieldSym = dynamic_cast<cSymbol*>(GetChild(i));
                if (fieldSym != nullptr)
                {
                    // Struct field access — resolve to field's type
                    if (fieldSym->GetDecl() != nullptr)
                        type = fieldSym->GetDecl()->GetType();
                }
                else
                {
                    // Array subscript — dereference one level
                    if (type != nullptr && type->IsArray())
                        type = type->GetType();
                }
            }
            return type;
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
            if (NumChildren() > 0)
            {
                result += " size=\"" + std::to_string(m_size) + "\"";
                result += " offset=\"" + std::to_string(m_offset) + "\"";
                if (!m_rowsizes.empty())
                {
                    result += " rowsizes=\"";
                    for (size_t i = 0; i < m_rowsizes.size(); i++)
                    {
                        if (i > 0) result += " ";
                        result += std::to_string(m_rowsizes[i]);
                    }
                    result += "\"";
                }
            }
            return result;
        }

        void SetRowSizes(const std::vector<int>& rs) { m_rowsizes = rs; }
        const std::vector<int>& GetRowSizes() const  { return m_rowsizes; }

        int GetSize() { return m_size; }
        void SetSize(int size) { m_size = size; }
        int GetOffset() { return m_offset; }
        void SetOffset(int offset) { m_offset = offset; }

    protected:
        int m_size;
        int m_offset;
        std::vector<int> m_rowsizes;
};