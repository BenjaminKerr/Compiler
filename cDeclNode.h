#pragma once
//**************************************
// cDeclNode
//
// Defines base class for all declarations.
// Future labs will add features to this class.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"

class cDeclNode : public cAstNode
{
    public:
        cDeclNode() : cAstNode() {}

        // Type checking methods - return false by default
        virtual bool IsArray()  { return false; }
        virtual bool IsStruct() { return false; }
        virtual bool IsType()   { return false; }
        virtual bool IsFunc()   { return false; }
        virtual bool IsVar()    { return false; }
        virtual bool IsFloat()  { return false; }
        virtual bool IsInt()    { return false; }
        virtual bool IsChar()   { return false; }
        virtual int  GetSize()  { return 0; }

        // Pure virtual - all decls must define what type they are/have
        virtual cDeclNode* GetType() = 0;

        // Return the declaration (for things that ARE declarations)
        virtual cDeclNode* GetDecl() { return this; }

        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        virtual string NodeType() { return string("decl"); }
};
