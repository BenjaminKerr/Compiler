#pragma once
#include "cDeclNode.h"
#include "cDeclsNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"

class cStructDeclNode : public cDeclNode
{
public:
    cStructDeclNode(cDeclsNode *decls, cSymbol *name) : cDeclNode()
    {
        AddChild(decls);
        AddChild(name);
        name->SetDecl(this);
        g_symbolTable.Insert(name);
    }

    virtual bool IsType()   { return true; }
    virtual bool IsStruct() { return true; }

    virtual cDeclNode* GetType() { return this; }

    virtual string GetName()
    {
        cSymbol *nameSym = dynamic_cast<cSymbol*>(GetChild(1));
        if (nameSym != nullptr) return nameSym->GetName();
        return "";
    }

    cDeclsNode* GetDecls()
    {
        return dynamic_cast<cDeclsNode*>(GetChild(0));
    }

    virtual string NodeType() { return string("struct_decl"); }
    virtual void Visit(cVisitor *visitor) { 
        visitor->Visit(this); 
    }

    virtual string AttributesToString()
    {
        string result = "";
        if (m_size != 0)
            result += " size=\"" + std::to_string(m_size) + "\"";
        if (m_size != 0 || m_offset != 0)
            result += " offset=\"" + std::to_string(m_offset) + "\"";
        return result;
    }
};