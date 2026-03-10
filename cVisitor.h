#pragma once
//**************************************
// cVisitor.h
//
// Base class for all AST visitors.
//
// Implements the Visitor pattern over the AST. Each Visit method defaults to
// calling VisitAllChildren, so subclasses only need to override the node types
// they care about. To add a new node type, add a forward declaration below and
// a corresponding virtual Visit method to the class.
//
// Author: Phil Howard
// phil.howard@oit.edu
//
// Modified by: Benjamin Kerr
//
// Date: 2025
//

// Forward declarations for all AST node types
class cArrayDeclNode;
class cAssignNode;
class cAstNode;
class cBaseTypeNode;
class cBinaryExprNode;
class cBlockNode;
class cDeclNode;
class cDeclsNode;
class cExprNode;
class cFloatExprNode;
class cFuncCallNode;
class cFuncDeclNode;
class cIntExprNode;
class cOpNode;
class cParamNode;
class cParamsNode;
class cPrintNode;
class cProgramNode;
class cReturnNode;
class cStmtNode;
class cStmtsNode;
class cStructDeclNode;
class cSymbol;
class cUnaryExprNode;
class cVarDeclNode;
class cVarExprNode;
class cCallParamsNode;
class cIfNode;
class cWhileNode;

class cVisitor
{
    public:
        cVisitor() {}
        virtual ~cVisitor() {}

        // Begin traversal from the given root node
        virtual void VisitAllNodes(cAstNode *node);

        // Default Visit implementations call VisitAllChildren on the node.
        // Subclasses override only the node types they need to inspect.
        virtual void Visit(cArrayDeclNode *node);
        virtual void Visit(cAssignNode *node);
        virtual void Visit(cAstNode *node);
        virtual void Visit(cBaseTypeNode *node);
        virtual void Visit(cBinaryExprNode *node);
        virtual void Visit(cBlockNode *node);
        virtual void Visit(cDeclNode *node);
        virtual void Visit(cDeclsNode *node);
        virtual void Visit(cExprNode *node);
        virtual void Visit(cFloatExprNode *node);
        virtual void Visit(cFuncCallNode *node);
        virtual void Visit(cFuncDeclNode *node);
        virtual void Visit(cIntExprNode *node);
        virtual void Visit(cOpNode *node);
        virtual void Visit(cParamNode *node);
        virtual void Visit(cParamsNode *node);
        virtual void Visit(cPrintNode *node);
        virtual void Visit(cProgramNode *node);
        virtual void Visit(cReturnNode *node);
        virtual void Visit(cStmtNode *node);
        virtual void Visit(cStmtsNode *node);
        virtual void Visit(cStructDeclNode *node);
        virtual void Visit(cSymbol *node);
        virtual void Visit(cUnaryExprNode *node);
        virtual void Visit(cVarDeclNode *node);
        virtual void Visit(cVarExprNode *node);
        virtual void Visit(cCallParamsNode *node);
        virtual void Visit(cIfNode *node);
        virtual void Visit(cWhileNode *node);
};