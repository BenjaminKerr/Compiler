#pragma once
//**************************************
// cComputeSize.h
//
// Visitor pass that computes sizes and frame offsets for all declarations.
//
// Local variables receive positive offsets from the frame base, allocated
// sequentially with 4-byte alignment. Parameters receive negative offsets
// relative to the frame pointer, reflecting the calling convention:
//
//   [return address]  at fp+0  (or similar, ABI-dependent)
//   [saved fp]        at fp-4
//   [return addr]     at fp-8
//   first param       at fp-12  <-- paramOffset starts here
//   second param      at fp-16 (or lower, depending on size)
//   ...
//   locals            at fp+0, fp+4, ...
//
// A scope stack tracks the current allocation offset as the visitor
// descends into nested blocks. The high-water mark across sibling blocks
// determines the total frame size needed for a function.
//
// Author: Benjamin Kerr
//
// Date: 2025
//

#include "cVisitor.h"
#include "astnodes.h"
#include <vector>

class cComputeSize : public cVisitor
{
    public:
        cComputeSize() : cVisitor()
        {
            m_scopeStack.push_back({0});
        }

        void VisitAllNodes(cAstNode *node) override
        {
            node->Visit(this);
        }

        void Visit(cVarDeclNode  *node) override;
        void Visit(cDeclsNode    *node) override;
        void Visit(cBlockNode    *node) override;
        void Visit(cVarExprNode  *node) override;
        void Visit(cFuncDeclNode *node) override;
        void Visit(cParamsNode   *node) override;

    protected:
        struct ScopeInfo
        {
            int currentOffset;  // Next available byte offset in this scope
        };

        std::vector<ScopeInfo> m_scopeStack;

        // Align offset to a 4-byte boundary for types larger than 1 byte
        int AlignOffset(int offset, int size)
        {
            if (size > 1)
            {
                int remainder = offset % 4;
                if (remainder != 0) offset += (4 - remainder);
            }
            return offset;
        }

        // Return the stack slot size for a parameter: minimum 4 bytes,
        // matching the calling convention's push-word granularity
        int GetParamSlotSize(cDeclNode *type)
        {
            int typeSize = (type != nullptr) ? type->GetSize() : 1;
            return (typeSize < 4) ? 4 : typeSize;
        }
};