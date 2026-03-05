#pragma once
//**************************************
// cDeclsNode.h
//
// Defines a class to represent a list of declarations.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"
#include "cDeclNode.h"

class cDeclsNode : public cAstNode
{
    public:
        // param is the first decl in this decls
        cDeclsNode(cDeclNode *decl) : cAstNode()
        {
            AddChild(decl);
            m_size = 0;
        }

        // Add a decl to the list
        void Insert(cDeclNode *decl)
        {
            AddChild(decl);
        }

        virtual string NodeType() { return string("decls"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        int GetSize() { return m_size; }
        void SetSize(int size) { m_size = size; }

        virtual string AttributesToString()
        {
            if (m_size != 0)
                return " size=\"" + std::to_string(m_size) + "\"";
            return "";
        }
    
    protected:
        int m_size;
};
