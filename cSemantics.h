#pragma once
//**************************************
// cSemantics.h
//
// Visitor class that performs semantic analysis on the AST.
//
// Checks performed:
//   - Assignment type compatibility (cAssignNode)
//   - Variable reference validity and array subscript checking (cVarExprNode)
//   - Function call argument count and type compatibility (cFuncCallNode)
//
// Author: Benjamin Kerr
//
// Date: 2025
//

#include "cVisitor.h"
#include "astnodes.h"

class cSemantics : public cVisitor
{
    public:
        cSemantics() : cVisitor() {}

        // Begin semantic analysis traversal from the given root node
        virtual void VisitAllNodes(cAstNode *node)
        {
            node->Visit(this);
        }

        // Check that the right-hand expression type is compatible with the
        // left-hand variable type
        void Visit(cAssignNode *node) override;

        // Check that the referenced variable is not a function, and that
        // any array subscripts are integer-typed
        void Visit(cVarExprNode *node) override;

        // Check that the function is fully defined and called with the correct
        // number and types of arguments
        void Visit(cFuncCallNode *node) override;
};