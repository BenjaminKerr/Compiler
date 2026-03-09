#pragma once
//**************************************
// cFuncDeclNode.h
//
// AST node for function declarations and definitions.
//
// A function may be declared multiple times (forward declarations) but defined
// only once (with a body). Each redeclaration is checked for return type and
// parameter count compatibility against the first declaration.
//
// Child layout:
//   child(0):           cSymbol*     -- return type symbol
//   child(1):           cSymbol*     -- function name symbol
//   child(2) [optional]: cParamsNode* -- parameter list
//   last child [if body]: cStmtsNode* -- function body
//
// Author: Benjamin Kerr
//
// Date: 2025
//

#include "cAstNode.h"
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cParamsNode.h"
#include "cStmtsNode.h"
#include "cSymbolTable.h"

class cFuncDeclNode : public cDeclNode
{
    public:
        // Declare or redefine a function.
        // Semantic checks performed here (rather than in cSemantics) because
        // the symbol table must be updated immediately at parse time so that
        // recursive calls and forward references resolve correctly.
        cFuncDeclNode(cSymbol *returnType, cSymbol *name, cParamsNode *params)
            : cDeclNode()
        {
            AddChild(returnType);
            AddChild(name);
            if (params != nullptr) AddChild(params);

            cSymbol *existing = g_symbolTable.FindLocal(name->GetName());

            if (existing != nullptr && existing->GetDecl() != nullptr)
            {
                if (!existing->GetDecl()->IsFunc())
                {
                    // A non-function symbol with this name already exists in scope
                    SemanticParseError("Symbol " + name->GetName() +
                                       " already defined in current scope");
                    name->SetDecl(this);
                }
                else
                {
                    // A prior function declaration exists -- check compatibility
                    cFuncDeclNode *prevFunc =
                        dynamic_cast<cFuncDeclNode*>(existing->GetDecl());

                    if (prevFunc->GetType() != returnType->GetDecl())
                    {
                        SemanticParseError(name->GetName() +
                                           " previously declared with different return type");
                    }

                    if (prevFunc->GetParamCount() != GetParamCount())
                    {
                        SemanticParseError(name->GetName() +
                                           " redeclared with a different number of parameters");
                    }

                    // Reuse the existing symbol so all declarations share one ID
                }
            }
            else
            {
                // First declaration of this function in the current scope
                name->SetDecl(this);
            }
        }

        bool IsFunc() override { return true; }

        // Return the declaration node for this function's return type
        cDeclNode* GetType() override
        {
            cSymbol *returnTypeSym = dynamic_cast<cSymbol*>(GetChild(0));
            if (returnTypeSym != nullptr) return returnTypeSym->GetDecl();
            return nullptr;
        }

        // Return true if this node includes a function body (cStmtsNode)
        bool HasBody()
        {
            if (NumChildren() > 2)
            {
                return dynamic_cast<cStmtsNode*>(GetChild(NumChildren() - 1)) != nullptr;
            }
            return false;
        }

        void CheckMultipleDefinitions(cSymbol* name) 
        {
            if (!HasBody()) return;
            cSymbol* existing = g_symbolTable.FindLocal(name->GetName());
            if (existing != nullptr && existing->GetDecl() != nullptr && 
                existing->GetDecl()->IsFunc() && existing->GetDecl() != this) {
                cFuncDeclNode* prevFunc = dynamic_cast<cFuncDeclNode*>(existing->GetDecl());
                if (prevFunc != nullptr && prevFunc->HasBody()) {
                    SemanticParseError(name->GetName() + " already has a definition");
                }
            }
        }

        // Return the number of declared parameters, or 0 if none
        int GetParamCount()
        {
            if (NumChildren() >= 3)
            {
                cParamsNode *params = dynamic_cast<cParamsNode*>(GetChild(2));
                if (params != nullptr) return params->NumChildren();
            }
            return 0;
        }

        // Return the parameter list node, or nullptr if none declared
        cParamsNode* GetParams()
        {
            if (NumChildren() >= 3)
            {
                return dynamic_cast<cParamsNode*>(GetChild(2));
            }
            return nullptr;
        }

        std::string NodeType() override { return std::string("func"); }
        void Visit(cVisitor *visitor) override { visitor->Visit(this); }

    protected:
        std::string GetName() override
        {
            cSymbol *nameSym = dynamic_cast<cSymbol*>(GetChild(1));
            if (nameSym != nullptr) return nameSym->GetName();
            return "";
        }
};