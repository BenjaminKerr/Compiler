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
    node->VisitAllChildren(this);

    cDeclNode *type = node->GetType();
    if (type == nullptr) return;

    int typeSize = type->GetSize();
    int &currentOffset = m_scopeStack.back().currentOffset;

    currentOffset = AlignOffset(currentOffset, typeSize);

    node->SetOffset(currentOffset);
    node->SetSize(typeSize);
    currentOffset += typeSize;
}

void cComputeSize::Visit(cDeclsNode *node)
{
    // Record offset before declarations so we can compute total size added
    int startOffset = m_scopeStack.back().currentOffset;
    node->VisitAllChildren(this);
    node->SetSize(m_scopeStack.back().currentOffset - startOffset);
}

void cComputeSize::Visit(cBlockNode *node)
{
    // Save the offset at block entry so we can restore it after visiting,
    // allowing sibling blocks to reuse the same stack space.
    int savedOffset = m_scopeStack.back().currentOffset;

    node->VisitAllChildren(this);

    // Record the peak offset reached inside this block (high-water mark),
    // which determines how much stack space this block needs at runtime.
    int highWater = m_scopeStack.back().currentOffset;
    node->SetSize(highWater);

    // Restore offset so the next sibling block starts from the same base,
    // but preserve the high-water mark if it exceeded the saved value.
    m_scopeStack.back().currentOffset = savedOffset;
    if (highWater > m_scopeStack.back().currentOffset)
        m_scopeStack.back().currentOffset = highWater;
}

void cComputeSize::Visit(cVarExprNode *node)
{
    node->VisitAllChildren(this);

    // child(0) is the cSymbol for the referenced variable
    cSymbol *sym = dynamic_cast<cSymbol*>(node->GetChild(0));
    if (sym == nullptr || sym->GetDecl() == nullptr) return;

    cDeclNode *decl = sym->GetDecl();
    node->SetSize(decl->GetSize());
    node->SetOffset(decl->GetOffset());
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
    // Compute the total stack space consumed by all parameters.
    // Each parameter occupies at least one word (4 bytes) on the stack
    // per the calling convention, regardless of its declared size.
    int total = 0;
    for (int i = 0; i < node->NumChildren(); i++)
    {
        cVarDeclNode *param = dynamic_cast<cVarDeclNode*>(node->GetChild(i));
        if (param != nullptr)
            total += GetParamSlotSize(param->GetType());
    }
    node->SetSize(total);
}