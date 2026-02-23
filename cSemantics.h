#pragma once
//**************************************
// cSemantics.h
//
// Visitor class that performs semantic analysis on the AST.
// All semantic checking for Lab 5B is done here.
//
// Author: Benjamin Kerr
//
#include "cVisitor.h"
#include "astnodes.h"

class cSemantics : public cVisitor
{
    public:
        cSemantics() : cVisitor() {}

        // Entry point - start visiting from root node
        virtual void VisitAllNodes(cAstNode *node)
        {
            node->Visit(this);
        }

        // We will add Visit overrides here as we implement each check
        virtual void Visit(cAssignNode *node);

        virtual void Visit(cVarExprNode *node);

        virtual void Visit(cFuncCallNode *node);
};