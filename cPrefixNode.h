#pragma once
//**************************************
// cPrefixNode.h
//
// Temporary node used only during parsing to pass data between grammar rules.
// Not part of the final AST.
//
// Author: Benjamin Kerr
//
#include "cAstNode.h"

class cPrefixNode : public cAstNode
{
    public:
        cPrefixNode() : cAstNode() {}
        
        virtual string NodeType() { return string("prefix"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};