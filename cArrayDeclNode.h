#pragma once
//**************************************
// cArrayDeclNode.h
//
// Defines AST node for array declarations.
//
// Author: Benjamin Kerr
//
#include "cAstNode.h"
#include "cDeclNode.h"
#include "cSymbol.h"

class cArrayDeclNode : public cDeclNode
{
    public:
        // params are the element type, size, and array name
        cArrayDeclNode(cSymbol *type, int size, cSymbol *name) : cDeclNode()
        {
            AddChild(type);
            AddChild(name);
            m_count = size;   // rename m_size -> m_count
            name->SetDecl(this);
        }

        int GetCount() { return m_count; }

        virtual bool IsType() { return false; }

        virtual bool IsArray() { return true; }

        virtual cDeclNode* GetType() 
        { 
            cSymbol* typeSym = dynamic_cast<cSymbol*>(GetChild(0));
            if (typeSym != nullptr && typeSym->GetDecl() != nullptr)
                return typeSym->GetDecl();  // NOT ->GetType(), just ->GetDecl()
            return nullptr;
        }

        virtual string GetName() 
        { 
            cSymbol* nameSym = dynamic_cast<cSymbol*>(GetChild(1));
            if (nameSym != nullptr)
                return nameSym->GetName();
            return "";
        }

        virtual int GetSize() override
        {
            cDeclNode *elemType = GetType();
            int elemSize = (elemType != nullptr) ? elemType->GetSize() : 1;
            return m_count * elemSize;   // use m_count, not m_size
        }

        virtual void SetSize(int size) override { /* ignore — size is always computed */ }

        virtual string NodeType() { return string("array_decl"); }

        virtual string AttributesToString()
        {
            return " count=\"" + std::to_string(m_count) + "\"";
        }

        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

    protected:
        int m_count;  // Number of elements in the array
};