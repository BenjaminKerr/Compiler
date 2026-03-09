#pragma once
#include "cAstNode.h"
#include "cExprNode.h"

class cCallParamsNode : public cAstNode
{
public:
    cCallParamsNode(cAstNode *first) : cAstNode()
    {
        AddChild(first);
        m_size = 0;
    }

    void AddChild(cAstNode *node) { cAstNode::AddChild(node); }

    int GetSize() { return m_size; }
    void SetSize(int size) { m_size = size; }

    virtual string AttributesToString()
    {
        if (m_size != 0)
            return " size=\"" + std::to_string(m_size) + "\"";
        return "";
    }

    virtual string NodeType() { return string("params"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

protected:
    int m_size;
};