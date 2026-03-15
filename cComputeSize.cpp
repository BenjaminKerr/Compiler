//**************************************
// cComputeSize.cpp
//
// Implementation of the size and offset computation pass.
//
// Author: Benjamin Kerr
//
// Date: 2025
//

#include "cComputeSize.h"

void cComputeSize::Visit(cVarDeclNode *node)
{
    // Visit type first to ensure struct sizes are computed
    cDeclNode *type = node->GetType();
    if (type != nullptr && (type->IsStruct() || type->IsArray()) && type->GetSize() == 0)
        type->Visit(this);
    
    node->VisitAllChildren(this);

    int typeSize = type->GetSize();
    int &currentOffset = m_scopeStack.back().currentOffset;

    currentOffset = AlignOffset(currentOffset, typeSize);

    node->SetOffset(currentOffset);
    node->SetSize(typeSize);
    // Always allocate at least 4 bytes on stack (word alignment required)
    currentOffset += (typeSize < 4) ? 4 : typeSize;
    
    // Track high water mark
    m_scopeStack.back().highWater = std::max(m_scopeStack.back().highWater, currentOffset);
}

void cComputeSize::Visit(cDeclsNode *node)
{
    int startOffset = m_scopeStack.back().currentOffset;
    node->VisitAllChildren(this);
    node->SetSize(m_scopeStack.back().currentOffset - startOffset);
}

void cComputeSize::Visit(cBlockNode *node)
{
    int savedOffset = m_scopeStack.back().currentOffset;
    int savedHighWater = m_scopeStack.back().highWater;
    
    // Set high water to at least savedOffset for this block
    m_scopeStack.back().highWater = savedOffset;
    
    node->VisitAllChildren(this);
    
    int myHighWater = m_scopeStack.back().highWater;
    node->SetSize(myHighWater - savedOffset);
    
    // Reclaim space, but update parent's high water mark
    m_scopeStack.back().currentOffset = savedOffset;
    m_scopeStack.back().highWater = std::max(savedHighWater, myHighWater);
}

void cComputeSize::Visit(cVarExprNode *node)
{
    node->VisitAllChildren(this);
    cSymbol *sym = dynamic_cast<cSymbol*>(node->GetChild(0));
    if (sym == nullptr || sym->GetDecl() == nullptr) return;

    int totalOffset = sym->GetDecl()->GetOffset();
    int finalSize   = sym->GetDecl()->GetSize();

    // Walk field access chain, accumulating offsets
    for (int i = 1; i < node->NumChildren(); i++)
    {
        cSymbol *fieldSym = dynamic_cast<cSymbol*>(node->GetChild(i));
        if (fieldSym == nullptr || fieldSym->GetDecl() == nullptr) break;
        totalOffset += fieldSym->GetDecl()->GetOffset();
        finalSize    = fieldSym->GetDecl()->GetSize();
    }

    node->SetSize(finalSize);
    node->SetOffset(totalOffset);

    // Compute rowsizes if this varref has subscript children (array access).
    // We count non-symbol children as subscripts.
    int numSubscripts = 0;
    for (int i = 1; i < node->NumChildren(); i++)
    {
        if (dynamic_cast<cSymbol*>(node->GetChild(i)) == nullptr)
            numSubscripts++;
    }

    if (numSubscripts > 0)
    {
        std::vector<int> rowsizes;
        cDeclNode *arrDecl = sym->GetDecl()->GetType(); // e.g. int_5 or int_5_20
        while (arrDecl != nullptr && arrDecl->IsArray())
        {
            cDeclNode *elem = arrDecl->GetType(); // element type of this array level
            if (elem == nullptr) break;
            rowsizes.push_back(elem->GetSize());
            arrDecl = elem; // descend
        }
        node->SetRowSizes(rowsizes);
    }
}

void cComputeSize::Visit(cFuncDeclNode *node)
{
    // Assign negative offsets to parameters, working downward from fp-12.
    // The frame layout reserves fp-4 (saved fp) and fp-8 (return address),
    // so the first parameter slot begins at fp-12.
    cParamsNode *params = node->GetParams();
    if (params != nullptr)
    {
        int paramOffset = -12;
        for (int i = 0; i < params->NumChildren(); i++)
        {
            cVarDeclNode *varDecl = dynamic_cast<cVarDeclNode*>(params->GetChild(i));
            if (varDecl != nullptr)
            {
                int slotSize = GetParamSlotSize(varDecl->GetType());
                varDecl->SetOffset(paramOffset);
                varDecl->SetSize((varDecl->GetType() != nullptr)
                                ? varDecl->GetType()->GetSize() : 1);
                paramOffset -= slotSize;
            }
        }
    params->SetSize(-paramOffset - 12);  // ← after loop
    }

    // Push a fresh scope for the function body's local variables
    m_scopeStack.push_back({0});

    // Visit all children except the params node (already handled above)
    for (int i = 0; i < node->NumChildren(); i++)
    {
        if (dynamic_cast<cParamsNode*>(node->GetChild(i)) == nullptr)
            node->GetChild(i)->Visit(this);
    }

    node->SetSize(m_scopeStack.back().currentOffset);
    m_scopeStack.pop_back();
}

void cComputeSize::Visit(cParamsNode *node)
{
    int total = 0;
    for (int i = 0; i < node->NumChildren(); i++)
    {
        cVarDeclNode* param = dynamic_cast<cVarDeclNode*>(node->GetChild(i));
        if (param != nullptr)
        {
            cDeclNode* type = param->GetType();
            int typeSize = (type != nullptr) ? type->GetSize() : 1;
            int paramSize = (typeSize < 4) ? 4 : typeSize;
            total += paramSize;
        }
    }
    node->SetSize(total);
}

void cComputeSize::Visit(cStructDeclNode *node)
{
    if (node->GetSize() > 0) return;  // already computed
    
    node->SetOffset(0);
    ScopeInfo structScope = {0, 0};
    m_scopeStack.push_back(structScope);
    node->VisitAllChildren(this);
    int structSize = m_scopeStack.back().highWater;
    node->SetSize(structSize);
    m_scopeStack.pop_back();
}

void cComputeSize::Visit(cCallParamsNode *node)
{
    node->VisitAllChildren(this);
    // Size = size of first argument (word-aligned)
    if (node->NumChildren() > 0)
    {
        cVarExprNode* first = dynamic_cast<cVarExprNode*>(node->GetChild(0));
        if (first != nullptr)
        {
            int s = first->GetSize();
            node->SetSize((s < 4) ? 4 : s);
        }
    }
}
void cComputeSize::Visit(cArrayDeclNode *node)
{
    int typeSize = node->GetSize();  // m_count * elemSize
    int &currentOffset = m_scopeStack.back().currentOffset;

    currentOffset = AlignOffset(currentOffset, 4);
    node->SetOffset(currentOffset);
    // SetSize is a no-op for cArrayDeclNode; GetSize() computes it
    currentOffset += typeSize;

    m_scopeStack.back().highWater = std::max(m_scopeStack.back().highWater, currentOffset);
}
