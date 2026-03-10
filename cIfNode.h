#pragma once
// cIfNode.h — AST node for if / if-else statements
// Child layout:
//   child(0): cExprNode*  — condition
//   child(1): cStmtsNode* — then-branch
//   child(2): cStmtsNode* — else-branch (optional, may be nullptr)

#include "cAstNode.h"
#include "cStmtNode.h"
#include "cExprNode.h"
#include "cStmtsNode.h"

class cIfNode : public cStmtNode
{
public:
    cIfNode(cExprNode *cond, cStmtsNode *thenBranch, cStmtsNode *elseBranch)
        : cStmtNode()
    {
        AddChild(cond);
        AddChild(thenBranch);
        if (elseBranch != nullptr) AddChild(elseBranch);
    }

    cExprNode*  GetCond()       { return (cExprNode*)GetChild(0); }
    cStmtsNode* GetThen()       { return (cStmtsNode*)GetChild(1); }
    cStmtsNode* GetElse()
    {
        if (NumChildren() > 2) return (cStmtsNode*)GetChild(2);
        return nullptr;
    }

    virtual string NodeType() { return string("if"); }
    virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};