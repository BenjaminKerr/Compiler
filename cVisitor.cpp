//**************************************
// cVisitor.cpp
//
// Default implementations for all visitor methods.
//
// Every Visit method simply calls VisitAllChildren, causing the traversal to
// descend into the node's children. Subclasses override specific Visit methods
// to perform analysis or transformation at those node types.
//
// Author: Phil Howard
// phil.howard@oit.edu
//
// Modified by: Benjamin Kerr
//
// Date: 2025
//

#include "cVisitor.h"
#include "astnodes.h"

void cVisitor::VisitAllNodes(cAstNode *node)    { node->Visit(this); }

void cVisitor::Visit(cArrayDeclNode *node)      { node->VisitAllChildren(this); }
void cVisitor::Visit(cAssignNode *node)         { node->VisitAllChildren(this); }
void cVisitor::Visit(cAstNode *node)            { node->VisitAllChildren(this); }
void cVisitor::Visit(cBaseTypeNode *node)       { node->VisitAllChildren(this); }
void cVisitor::Visit(cBinaryExprNode *node)     { node->VisitAllChildren(this); }
void cVisitor::Visit(cBlockNode *node)          { node->VisitAllChildren(this); }
void cVisitor::Visit(cDeclNode *node)           { node->VisitAllChildren(this); }
void cVisitor::Visit(cDeclsNode *node)          { node->VisitAllChildren(this); }
void cVisitor::Visit(cExprNode *node)           { node->VisitAllChildren(this); }
void cVisitor::Visit(cFloatExprNode *node)      { node->VisitAllChildren(this); }
void cVisitor::Visit(cFuncCallNode *node)       { node->VisitAllChildren(this); }
void cVisitor::Visit(cFuncDeclNode *node)       { node->VisitAllChildren(this); }
void cVisitor::Visit(cIntExprNode *node)        { node->VisitAllChildren(this); }
void cVisitor::Visit(cOpNode *node)             { node->VisitAllChildren(this); }
void cVisitor::Visit(cParamNode *node)          { node->VisitAllChildren(this); }
void cVisitor::Visit(cParamsNode *node)         { node->VisitAllChildren(this); }
void cVisitor::Visit(cPrintNode *node)          { node->VisitAllChildren(this); }
void cVisitor::Visit(cProgramNode *node)        { node->VisitAllChildren(this); }
void cVisitor::Visit(cReturnNode *node)         { node->VisitAllChildren(this); }
void cVisitor::Visit(cStmtNode *node)           { node->VisitAllChildren(this); }
void cVisitor::Visit(cStmtsNode *node)          { node->VisitAllChildren(this); }
void cVisitor::Visit(cSymbol *node)             { node->VisitAllChildren(this); }
void cVisitor::Visit(cUnaryExprNode *node)      { node->VisitAllChildren(this); }
void cVisitor::Visit(cVarDeclNode *node)        { node->VisitAllChildren(this); }
void cVisitor::Visit(cVarExprNode *node)        { node->VisitAllChildren(this); }