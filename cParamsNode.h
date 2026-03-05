#pragma once
//**************************************
// cParamsNode.h
//
// Defines AST node for a list of function parameters.
//
// Author: Benjamin Kerr
//
#include "cAstNode.h"
#include "cParamNode.h"

class cParamsNode : public cAstNode
{
    public:
        cParamsNode(cAstNode *param) : cAstNode()
        {
            AddChild(param);
            m_size = 0;
        }

        virtual string AttributesToString()
        {
            if (m_size != 0)
                return " size=\"" + std::to_string(m_size) + "\"";
            return "";
        }

        // Add a parameter to the list
        void AddParam(cAstNode *param)
        {
            AddChild(param);
        }

        virtual string NodeType() { return string("args"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        

        int GetSize() { return m_size; }
        void SetSize(int size) { m_size = size; }

    protected:
        int m_size;
};