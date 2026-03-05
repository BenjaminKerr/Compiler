//**************************************
// cSemantics.cpp
//
// Implementation of semantic analysis visitor.
//
// NOTE: Several places below use dynamic_cast to retrieve typed child nodes
// by index. This is necessary because cAstNode::GetChild() returns cAstNode*,
// and the AST node classes do not yet expose fully typed accessors for all
// children. Index comments document what each child position holds.
//
// Author: Benjamin Kerr
//
// Date: 2025
//

#include "cSemantics.h"

void cSemantics::Visit(cAssignNode *node)
{
    // Visit children first so their types are resolved before we check them
    node->VisitAllChildren(this);

    cAstNode  *lval = node->GetLval();
    cExprNode *expr = node->GetExpr();

    cDeclNode *lvalType = nullptr;
    cDeclNode *exprType = nullptr;

    // Currently only variable references are supported as lvalues.
    // TODO: extend to support array element and struct field lvalues.
    cVarExprNode *varExpr = dynamic_cast<cVarExprNode*>(lval);
    if (varExpr != nullptr)
    {
        lvalType = varExpr->GetType();
    }

    if (expr != nullptr)
    {
        exprType = expr->GetType();
    }

    if (lvalType != nullptr && exprType != nullptr)
    {
        if (!lvalType->IsCompatibleWith(exprType))
        {
            node->SemanticError("Cannot assign " +
                                exprType->GetName() + " to " +
                                lvalType->GetName());
        }
    }
}

void cSemantics::Visit(cVarExprNode *node)
{
    node->VisitAllChildren(this);

    // child(0) is the cSymbol for the variable being referenced
    cSymbol *sym = dynamic_cast<cSymbol*>(node->GetChild(0));
    if (sym == nullptr || sym->GetDecl() == nullptr)
        return;

    // A variable reference to a function name is a semantic error
    if (sym->GetDecl()->IsFunc())
    {
        node->SemanticError("Symbol " + sym->GetName() +
                            " is a function, not a variable");
        return;
    }

    // Children beyond index 0 are array subscripts or field accesses
    for (int i = 1; i < node->NumChildren(); i++)
    {
        cAstNode  *child     = node->GetChild(i);
        cExprNode *indexExpr = dynamic_cast<cExprNode*>(child);

        if (indexExpr != nullptr)
        {
            // Only validate the first subscript dimension against the base type.
            // TODO: support multi-dimensional array subscript validation.
            if (i > 1) continue;

            // Resolve base type: if the symbol is a var decl, get its type
            cDeclNode *baseDecl = sym->GetDecl();
            if (baseDecl != nullptr && baseDecl->IsVar())
            {
                baseDecl = baseDecl->GetType();
            }

            if (baseDecl != nullptr && !baseDecl->IsArray())
            {
                node->SemanticError(sym->GetName() + " is not an array");
                continue;
            }

            // Array subscripts must be integer-typed
            cDeclNode *indexType = indexExpr->GetType();
            if (indexType != nullptr && indexType->IsFloat())
            {
                node->SemanticError("Index of " + sym->GetName() +
                                    " is not an int");
            }
        }
    }
}

void cSemantics::Visit(cFuncCallNode *node)
{
    node->VisitAllChildren(this);

    // child(0) is the cSymbol for the function being called
    cSymbol *funcSym = dynamic_cast<cSymbol*>(node->GetChild(0));
    if (funcSym == nullptr || funcSym->GetDecl() == nullptr)
        return;

    cFuncDeclNode *funcDecl = dynamic_cast<cFuncDeclNode*>(funcSym->GetDecl());
    if (funcDecl == nullptr)
        return;

    // Calling a forward-declared function with no body is an error
    if (!funcDecl->HasBody())
    {
        node->SemanticError("Function " + funcSym->GetName() +
                            " is not fully defined");
        return;
    }

    // child(1), if present, is the cAstNode holding call arguments
    int        callArgCount = 0;
    cAstNode  *args         = nullptr;
    if (node->NumChildren() > 1)
    {
        args = node->GetChild(1);
        if (args != nullptr)
            callArgCount = args->NumChildren();
    }

    int declParamCount = funcDecl->GetParamCount();

    if (callArgCount != declParamCount)
    {
        node->SemanticError(funcSym->GetName() +
                            " called with wrong number of arguments");
        return;
    }

    // Check each argument's type against the corresponding parameter type
    cParamsNode *params = (args != nullptr && declParamCount > 0)
                          ? funcDecl->GetParams()
                          : nullptr;

    if (params != nullptr)
    {
        for (int i = 0; i < callArgCount; i++)
        {
            cExprNode *argExpr = dynamic_cast<cExprNode*>(args->GetChild(i));
            if (argExpr == nullptr) continue;

            cDeclNode *argType = argExpr->GetType();
            if (argType == nullptr) continue;

            // Each parameter is a cParamNode whose child(0) is a cVarDeclNode
            cParamNode    *param     = dynamic_cast<cParamNode*>(params->GetChild(i));
            if (param == nullptr) continue;

            cVarDeclNode  *paramDecl = dynamic_cast<cVarDeclNode*>(param->GetChild(0));
            if (paramDecl == nullptr) continue;

            cDeclNode *paramType = paramDecl->GetType();
            if (paramType == nullptr) continue;

            if (!paramType->IsCompatibleWith(argType))
            {
                // Report only the first incompatible argument to avoid cascading errors
                node->SemanticError(funcSym->GetName() +
                                    " called with incompatible argument");
                break;
            }
        }
    }
}