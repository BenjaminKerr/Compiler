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
        // param is first parameter in the list
        cParamsNode(cParamNode *param) : cAstNode()
        {
            AddChild(param);
        }

        // Add a parameter to the list
        void AddParam(cParamNode *param)
        {
            AddChild(param);
        }

        virtual string NodeType() { return string("params"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};