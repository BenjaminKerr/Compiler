#include "cSemantics.h"

void cSemantics::Visit(cAssignNode *node)
{    
    // First visit children to check them
    node->VisitAllChildren(this);

    // Get the left and right sides
    cAstNode *lval = node->GetLval();
    cExprNode *expr = node->GetExpr();

    // Get their types
    cDeclNode *lvalType = nullptr;
    cDeclNode *exprType = nullptr;

    // Left side could be a varref
    cVarExprNode *varExpr = dynamic_cast<cVarExprNode*>(lval);
    if (varExpr != nullptr)
    {
        lvalType = varExpr->GetType();
    }

    // Right side is an expression
    if (expr != nullptr)
    {
        exprType = expr->GetType();
    }

    // Check compatibility
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
    // First visit children
    node->VisitAllChildren(this);
    
    // Get the first symbol (the variable being referenced)
    cSymbol* sym = dynamic_cast<cSymbol*>(node->GetChild(0));
    if (sym == nullptr || sym->GetDecl() == nullptr)
        return;
    
    // Check if it's actually a function
    if (sym->GetDecl()->IsFunc())
    {
        node->SemanticError("Symbol " + sym->GetName() + 
                           " is a function, not a variable");
        return;
    }
    
    // Check for array subscripting
    // If there are more than 1 child, we have subscripts or field accesses
    for (int i = 1; i < node->NumChildren(); i++)
    {
        cAstNode* child = node->GetChild(i);
        
        // Check if this is an expression (array subscript)
        cExprNode* indexExpr = dynamic_cast<cExprNode*>(child);
        if (indexExpr != nullptr)
        {
            // This is an array subscript - check parent is an array
            cDeclNode* baseDecl = nullptr;
            
            if (i == 1)
            {
                // First subscript - check the base symbol
                baseDecl = sym->GetDecl();
                
                // If it's a variable, get its type
                if (baseDecl != nullptr && baseDecl->IsVar())
                {
                    baseDecl = baseDecl->GetType();
                }
            }
            else
            {
                // Nested subscript - would need to track previous type
                // For now, skip
                continue;
            }
            
            if (baseDecl != nullptr && !baseDecl->IsArray())
            {
                node->SemanticError(sym->GetName() + " is not an array");
                continue;
            }
            
            // Check index is an integer
            cDeclNode* indexType = indexExpr->GetType();
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
    // First visit children
    node->VisitAllChildren(this);
    
    // Get the function symbol
    cSymbol* funcSym = dynamic_cast<cSymbol*>(node->GetChild(0));
    if (funcSym == nullptr || funcSym->GetDecl() == nullptr)
        return;
    
    cFuncDeclNode* funcDecl = dynamic_cast<cFuncDeclNode*>(funcSym->GetDecl());
    if (funcDecl == nullptr)
        return;
    
    // Check if function is fully defined (has a body)
    if (!funcDecl->HasBody())
    {
        node->SemanticError("Function " + funcSym->GetName() + 
                           " is not fully defined");
        return;
    }
    
    // Count the arguments in the call
    int callArgCount = 0;
    cAstNode* args = nullptr;
    if (node->NumChildren() > 1)
    {
        args = node->GetChild(1);
        if (args != nullptr)
            callArgCount = args->NumChildren();
    }
    
    // Get the expected parameter count
    int declParamCount = funcDecl->GetParamCount();
    
    // Check if counts match
    if (callArgCount != declParamCount)
    {
        node->SemanticError(funcSym->GetName() + 
                           " called with wrong number of arguments");
        return;  // Don't check types if count is wrong
    }
    
    // Check argument types match parameter types
    if (args != nullptr && declParamCount > 0)
    {
        // Get the params node from function declaration
        cParamsNode* params = funcDecl->GetParams();
        if (params != nullptr)
        {
            for (int i = 0; i < callArgCount; i++)
            {
                // Get the call argument
                cExprNode* argExpr = dynamic_cast<cExprNode*>(args->GetChild(i));
                if (argExpr == nullptr)
                    continue;
                
                cDeclNode* argType = argExpr->GetType();
                if (argType == nullptr)
                    continue;
                
                // Get the parameter declaration
                cParamNode* param = dynamic_cast<cParamNode*>(params->GetChild(i));
                if (param == nullptr)
                    continue;
                
                cVarDeclNode* paramDecl = dynamic_cast<cVarDeclNode*>(param->GetChild(0));
                if (paramDecl == nullptr)
                    continue;
                
                cDeclNode* paramType = paramDecl->GetType();
                if (paramType == nullptr)
                    continue;
                
                // Check compatibility
                if (!paramType->IsCompatibleWith(argType))
                {
                    node->SemanticError(funcSym->GetName() + 
                                       " called with incompatible argument");
                    break;  // Only report first incompatible argument
                }
            }
        }
    }
}