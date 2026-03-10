#pragma once
// cWhileNode.h — AST node for while loops
// Child layout:
//   child(0): cExprNode* — condition
//   child(1): cStmtNode* — body

#include "cAstNode.h"
#include "cStmtNode.h"
#include "cExprNode.h"

class cWhileNode : public cStmtNode
{
public:
    cWhileNode(cExprNode *cond, cStmtNode *body)
        : cStmtNode()
    {
        AddChild(cond);
        AddChild(body);
    }

    cExprNode* GetCond() { return (cExprNode*)GetChild(0); }
    cStmtNode* GetBody() { return (cStmtNode*)GetChild(1); }

    virtual string NodeType() { return string("while"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};