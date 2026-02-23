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
            m_size = size;
            
            // Set the declaration for the name symbol
            name->SetDecl(this);
        }

        virtual bool IsType() { return true; }

        virtual bool IsArray() { return true; }

        virtual cDeclNode* GetType() 
        { 
            // Array's type is the element type
            cSymbol* typeSym = dynamic_cast<cSymbol*>(GetChild(0));
            if (typeSym != nullptr)
                return typeSym->GetDecl();
            return nullptr;
        }

        virtual string GetName() 
        { 
            cSymbol* nameSym = dynamic_cast<cSymbol*>(GetChild(1));
            if (nameSym != nullptr)
                return nameSym->GetName();
            return "";
        }

        int GetSize() { return m_size; }

        virtual string NodeType() { return string("array"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

    protected:
        int m_size;  // Number of elements in the array
};