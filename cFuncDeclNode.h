#pragma once
//**************************************
// cFuncDeclNode.h
//
// Defines AST node for function declarations and definitions.
//
// Author: Benjamin Kerr
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
        // Constructor
    
        cFuncDeclNode(cSymbol *returnType, cSymbol *name, cParamsNode *params)
            : cDeclNode()
        {
            AddChild(returnType);
            AddChild(name);
            if (params != nullptr) AddChild(params);
            
            // Semantic checking
            cSymbol* existing = g_symbolTable.FindLocal(name->GetName());
            
            if (existing != nullptr && existing->GetDecl() != nullptr) {
                // Symbol exists in current scope
                if (!existing->GetDecl()->IsFunc()) {
                    // Not a function - error
                    SemanticParseError("Symbol " + name->GetName() + 
                                    " already defined in current scope");
                    name->SetDecl(this);  // Set anyway to avoid cascading errors
                } else {
                    // It's a function - check compatibility
                    cFuncDeclNode* prevFunc = dynamic_cast<cFuncDeclNode*>(existing->GetDecl());
                    
                    // Check return type matches
                    if (prevFunc->GetType() != returnType->GetDecl()) {
                        SemanticParseError(name->GetName() + 
                                        " previously declared with different return type");
                    }
                    
                    // Check parameter count matches
                    int prevParamCount = prevFunc->GetParamCount();
                    int thisParamCount = GetParamCount();
                    if (prevParamCount != thisParamCount) {
                        SemanticParseError(name->GetName() + 
                                        " redeclared with a different number of parameters");
                    }
                    
                    // Don't set decl - reuse the existing symbol
                    // This makes all declarations share the same symbol ID
                }
            } else {
                // First declaration of this function
                name->SetDecl(this);
            }
        }

        virtual bool IsFunc() 
        { 
            return true; 
        }
        
        virtual cDeclNode* GetType() 
        { 
            cSymbol* returnTypeSym = dynamic_cast<cSymbol*>(GetChild(0));
            if (returnTypeSym != nullptr)
                return returnTypeSym->GetDecl();
            return nullptr;
        }
        
        virtual string NodeType() 
        { 
            return string("func"); 
        }

        virtual void Visit(cVisitor *visitor) 
        { 
            visitor->Visit(this); 
        }

        // Check if this function has a body (definition)
        bool HasBody() 
        {
            // If we have more than 2 children (return type + name), 
            // and the last child is cStmtsNode, we have a body
            if (NumChildren() > 2) {
                cStmtsNode* stmts = dynamic_cast<cStmtsNode*>(GetChild(NumChildren()-1));
                return (stmts != nullptr);
            }
            return false;
        }

        // Check for multiple definitions when body is added
        void CheckMultipleDefinitions(cSymbol* name) 
        {
            if (!HasBody()) return;  // No body, nothing to check
            
            cSymbol* existing = g_symbolTable.FindLocal(name->GetName());
            if (existing != nullptr && existing->GetDecl() != nullptr && 
                existing->GetDecl()->IsFunc() && existing->GetDecl() != this) {
                
                cFuncDeclNode* prevFunc = dynamic_cast<cFuncDeclNode*>(existing->GetDecl());
                if (prevFunc != nullptr && prevFunc->HasBody()) {
                    SemanticParseError(name->GetName() + " already has a definition");
                }
            }
        }
                // Helper to get parameter count
        int GetParamCount() 
        {
            // Return type is child 0, name is child 1, params (if exists) is child 2
            if (NumChildren() >= 3) {
                cParamsNode* params = dynamic_cast<cParamsNode*>(GetChild(2));
                if (params != nullptr)
                    return params->NumChildren();
            }
            return 0;
        }

        cParamsNode* GetParams()
        {
            // Params is child 2 (child 0 = return type, child 1 = name, child 2 = params)
            if (NumChildren() >= 3)
            {
                return dynamic_cast<cParamsNode*>(GetChild(2));
            }
            return nullptr;
        }

    protected:

        virtual string GetName() 
        { 
            cSymbol* nameSym = dynamic_cast<cSymbol*>(GetChild(1));
            if (nameSym != nullptr)
                return nameSym->GetName();
            return "";
        }
};