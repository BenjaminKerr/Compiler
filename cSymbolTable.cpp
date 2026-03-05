//**************************************
// cSymbolTable.cpp
//
// Implementation of the nested scope symbol table.
//
// Author: Phil Howard
// phil.howard@oit.edu
//
// Modified by: Benjamin Kerr
//
// Date: 2025
//

#include "cSymbolTable.h"
#include "cSymbol.h"

cSymbolTable::cSymbolTable()
{
    // Open the initial global scope
    m_scopes.push_back(scope_t());
}

scope_t* cSymbolTable::IncreaseScope()
{
    m_scopes.push_back(scope_t());
    return &m_scopes.back();
}

scope_t* cSymbolTable::DecreaseScope()
{
    if (!m_scopes.empty())
    {
        m_scopes.pop_back();
    }
    return m_scopes.empty() ? nullptr : &m_scopes.back();
}

void cSymbolTable::Insert(cSymbol *sym)
{
    m_scopes.back()[sym->GetName()] = sym;
}

cSymbol* cSymbolTable::Find(std::string name)
{
    // Search from innermost scope outward to implement lexical scoping
    for (auto scopeIt = m_scopes.rbegin(); scopeIt != m_scopes.rend(); ++scopeIt)
    {
        auto it = scopeIt->find(name);
        if (it != scopeIt->end())
        {
            return it->second;
        }
    }
    return nullptr;
}

cSymbol* cSymbolTable::FindLocal(std::string name)
{
    auto it = m_scopes.back().find(name);
    return (it != m_scopes.back().end()) ? it->second : nullptr;
}