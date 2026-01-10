#include "cSymbolTable.h"
#include "cSymbol.h"
#include <vector>
#include <unordered_map>

cSymbolTable::cSymbolTable()
{
    m_scopes.push_back(std::unordered_map<std::string, cSymbol*>());
}

symbolTable_t* cSymbolTable::IncreaseScope()
{
    m_scopes.push_back(std::unordered_map<std::string, cSymbol*>());
    return reinterpret_cast<symbolTable_t*>(&m_scopes.back());
}

symbolTable_t* cSymbolTable::DecreaseScope()
{
    if (!m_scopes.empty())
    {
        m_scopes.pop_back();
    }
    return m_scopes.empty() ? nullptr :
        reinterpret_cast<symbolTable_t*>(&m_scopes.back());
}

void cSymbolTable::Insert(cSymbol *sym)
{
    if (m_scopes.empty())
    {
        m_scopes.push_back(std::unordered_map<std::string, cSymbol*>());
    }
    m_scopes.back()[sym->GetName()] = sym;
}

cSymbol* cSymbolTable::Find(string name)
{
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

cSymbol* cSymbolTable::FindLocal(string name)
{
    if (m_scopes.empty())
    {
        return nullptr;
    }
    auto it = m_scopes.back().find(name);
    return (it != m_scopes.back().end()) ? it->second : nullptr;
}
