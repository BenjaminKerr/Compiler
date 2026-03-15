#pragma once
//**************************************
// cCodeGen.h
//
// Visitor that emits stackl assembly from the AST.
//
// Pipeline position: cComputeSize must run before this visitor so that
// every cVarDeclNode and cVarExprNode already has size and offset set.
//
// Author: Benjamin Kerr
//
#include "cVisitor.h"
#include "astnodes.h"
#include "cIfNode.h"
#include "cWhileNode.h"
#include "emit.h"

#include <string>

class cCodeGen : public cVisitor
{
    public:
        cCodeGen(const std::string &filename)
        {
            InitOutput(filename);
        }

        ~cCodeGen()
        {
            FinalizeOutput();
        }

        //------------------------------------------------------------------
        // Program — becomes ".function main" with locals allocated
        //------------------------------------------------------------------
        void Visit(cProgramNode *node) override
        {
            cBlockNode *block = dynamic_cast<cBlockNode*>(node->GetChild(0));

            // Emit all function declarations before main
            if (block != nullptr && block->GetDecls() != nullptr)
                block->GetDecls()->Visit(this);

            // Now emit main
            EmitString(".function main\n");
            EmitString("main:\n");

            if (block != nullptr)
            {
                EmitString("ADJSP " + std::to_string(block->GetSize()) + "\n");
                // Visit stmts only (decls already handled above)
                if (block->GetStmts() != nullptr)
                    block->GetStmts()->Visit(this);
            }

            EmitString("PUSH 0\n");
            EmitString("RETURNV\n");
        }

        //------------------------------------------------------------------
        // Block — visit decls (no code) then statements
        //------------------------------------------------------------------
        void Visit(cBlockNode *node) override
        {
            // Visit decls for any nested function declarations
            if (node->GetDecls() != nullptr)
                node->GetDecls()->Visit(this);
            cStmtsNode *stmts = node->GetStmts();
            if (stmts != nullptr) stmts->Visit(this);
        }

        //------------------------------------------------------------------
        // Integer literal
        //------------------------------------------------------------------
        void Visit(cIntExprNode *node) override
        {
            EmitString("PUSH " + std::to_string(node->GetValue()) + "\n");
        }

        //------------------------------------------------------------------
        // Print — evaluate expression, then CALL @print
        //------------------------------------------------------------------
        void Visit(cPrintNode *node) override
        {
            node->GetChild(0)->Visit(this);
            EmitString("CALL @print\n");
        }

        //------------------------------------------------------------------
        // Variable reference — push VALUE of the variable onto the stack.
        // For arrays with subscripts, compute address then dereference.
        //------------------------------------------------------------------
        void Visit(cVarExprNode *node) override
        {
            int numChildren = node->NumChildren();

            // Count subscript (non-symbol) children
            int numSubscripts = 0;
            for (int i = 1; i < numChildren; i++)
            {
                if (dynamic_cast<cSymbol*>(node->GetChild(i)) == nullptr)
                    numSubscripts++;
            }

            if (numSubscripts > 0)
            {
                // Array access: push address, then dereference
                EmitArrayAddress(node);
                int elemSize = node->GetSize();
                if (elemSize == 1)
                    EmitString("PUSHCVARIND\n");
                else
                    EmitString("PUSHVARIND\n");
            }
            else
            {
                // Simple var (or struct field chain — offset already summed by cComputeSize)
                int offset = node->GetOffset();
                int size   = node->GetSize();
                if (size == 1)
                {
                    // char: push address then use byte-load
                    EmitString("PUSH " + std::to_string(offset) + "\n");
                    EmitString("PUSHFP\n");
                    EmitString("PLUS\n");
                    EmitString("PUSHCVARIND\n");
                }
                else
                {
                    EmitString("PUSHVAR " + std::to_string(offset) + "\n");
                }
            }
        }

        //------------------------------------------------------------------
        // Assignment
        //------------------------------------------------------------------
        void Visit(cAssignNode *node) override
        {
            // Evaluate RHS first — leaves value on stack
            node->GetExpr()->Visit(this);

            // Now store into LHS
            cVarExprNode *lval = dynamic_cast<cVarExprNode*>(node->GetLval());
            if (lval == nullptr) return;

            int numSubscripts = 0;
            for (int i = 1; i < lval->NumChildren(); i++)
            {
                if (dynamic_cast<cSymbol*>(lval->GetChild(i)) == nullptr)
                    numSubscripts++;
            }

            if (numSubscripts > 0)
            {
                // Array lval: push address, then indirect store
                EmitArrayAddress(lval);
                int elemSize = lval->GetSize();
                if (elemSize == 1)
                    EmitString("POPCVARIND\n");
                else
                    EmitString("POPVARIND\n");
            }
            else
            {
                int offset = lval->GetOffset();
                int size   = lval->GetSize();
                if (size == 1)
                {
                    // char: push address then byte-store
                    EmitString("PUSH " + std::to_string(offset) + "\n");
                    EmitString("PUSHFP\n");
                    EmitString("PLUS\n");
                    EmitString("POPCVARIND\n");
                }
                else
                {
                    EmitString("POPVAR " + std::to_string(offset) + "\n");
                }
            }
        }

        //------------------------------------------------------------------
        // Binary expression — evaluate both sides, emit operator
        //------------------------------------------------------------------
        void Visit(cBinaryExprNode *node) override
        {
            node->GetChild(0)->Visit(this);   // left
            node->GetChild(2)->Visit(this);   // right

            cOpNode *op = dynamic_cast<cOpNode*>(node->GetChild(1));
            if (op == nullptr) return;

            switch (op->GetOp())
            {
                case '+':        EmitString("PLUS\n");   break;
                case '-':        EmitString("MINUS\n");  break;
                case '*':        EmitString("TIMES\n");  break;
                case '/':        EmitString("DIVIDE\n"); break;
                case '%':        EmitString("MOD\n");    break;
                case EQUALS:     EmitString("EQ\n");     break;
                case NOT_EQUALS: EmitString("NE\n");     break;
                case '<':        EmitString("LT\n");     break;
                case '>':        EmitString("GT\n");     break;
                case LE:         EmitString("LE\n");     break;
                case GE:         EmitString("GE\n");     break;
                case AND:        EmitString("AND\n");    break;
                case OR:         EmitString("OR\n");     break;
                default:
                    EmitString("// unknown op\n");
                    break;
            }
        }

        //------------------------------------------------------------------
        // Unary negation:  -expr  →  PUSH 0 / expr / MINUS
        //------------------------------------------------------------------
        void Visit(cUnaryExprNode *node) override
        {
            EmitString("PUSH 0\n");
            node->GetChild(1)->Visit(this);
            EmitString("MINUS\n");
        }

        //------------------------------------------------------------------
        // Return statement
        //------------------------------------------------------------------
        void Visit(cReturnNode *node) override
        {
            if (node->NumChildren() > 0)
            {
                node->GetChild(0)->Visit(this);
                EmitString("RETURNV\n");
            }
            else
            {
                EmitString("RETURN\n");
            }
        }

        //------------------------------------------------------------------
        // Function declaration — emit label, ADJSP, body
        //------------------------------------------------------------------
        void Visit(cFuncDeclNode *node) override
        {
            if (!node->HasBody()) return;   // forward declaration, no code

            std::string name = node->GetFuncName();

            EmitString(".function " + name + "\n");
            EmitString(name + ":\n");

            // Local size comes from the body block (last child = cStmtsNode
            // whose parent block has the size; we stored it in node via cComputeSize)
            int localSize = node->GetSize();
            EmitString("ADJSP " + std::to_string(localSize) + "\n");

            // Visit body — skip params node, visit everything else
            for (int i = 0; i < node->NumChildren(); i++)
            {
                cParamsNode *p = dynamic_cast<cParamsNode*>(node->GetChild(i));
                if (p == nullptr)
                    node->GetChild(i)->Visit(this);
            }

            // Safety RETURN in case no explicit return (avoids fall-off)
            EmitString("RETURN\n");
        }

        //------------------------------------------------------------------
        // Function call — push args right-to-left, CALL, leave return val
        //------------------------------------------------------------------
        void Visit(cFuncCallNode *node) override
        {
            cSymbol *funcSym = dynamic_cast<cSymbol*>(node->GetChild(0));
            if (funcSym == nullptr) return;
            std::string name = funcSym->GetName();

            // Push arguments left-to-right (stackl pushes in call order)
            if (node->NumChildren() > 1)
            {
                cCallParamsNode *params =
                    dynamic_cast<cCallParamsNode*>(node->GetChild(1));
                if (params != nullptr)
                {
                    for (int i = 0; i < params->NumChildren(); i++)
                        params->GetChild(i)->Visit(this);
                }
            }

            EmitString("CALL @" + name + "\n");
            // Return value is left on the stack for the caller to use or discard
        }

        //------------------------------------------------------------------
        // If statement
        //------------------------------------------------------------------
        virtual void Visit(cIfNode *node)
        {
            std::string endLabel = GenerateLabel();

            node->GetCond()->Visit(this);

            cStmtsNode *elseBranch = node->GetElse();
            if (elseBranch != nullptr)
            {
                std::string elseLabel = GenerateLabel();
                EmitString("JUMPE @" + elseLabel + "\n");
                node->GetThen()->Visit(this);
                EmitString("JUMP @" + endLabel + "\n");
                EmitString(elseLabel + ":\n");
                elseBranch->Visit(this);
            }
            else
            {
                EmitString("JUMPE @" + endLabel + "\n");
                node->GetThen()->Visit(this);
            }

            EmitString(endLabel + ":\n");
        }

        //------------------------------------------------------------------
        // While loop
        //------------------------------------------------------------------
        virtual void Visit(cWhileNode *node)
        {
            std::string topLabel = GenerateLabel();
            std::string endLabel = GenerateLabel();

            EmitString(topLabel + ":\n");
            node->GetCond()->Visit(this);
            EmitString("JUMPE @" + endLabel + "\n");
            node->GetBody()->Visit(this);
            EmitString("JUMP @" + topLabel + "\n");
            EmitString(endLabel + ":\n");
        }

        //------------------------------------------------------------------
        // Stmts — just visit all children
        //------------------------------------------------------------------
        void Visit(cStmtsNode *node) override
        {
            node->VisitAllChildren(this);
        }

        //------------------------------------------------------------------
        // Decls / VarDecl — no code emitted (sizes/offsets already set)
        //------------------------------------------------------------------
        void Visit(cDeclsNode  *node) override
        {
            // Emit code for any function declarations in this decls list
            node->VisitAllChildren(this);
        }
        void Visit(cVarDeclNode *node) override { /* no code */ }

    private:
        //------------------------------------------------------------------
        // Helper: emit code that leaves the ADDRESS of an array element on
        // the stack.  Handles 1-D arrays; rowsizes[0] is the element size.
        //
        // address = fp + base_offset + (subscript * rowsize)
        //------------------------------------------------------------------
        void EmitArrayAddress(cVarExprNode *node)
        {
            int baseOffset = node->GetOffset();
            const std::vector<int> &rowsizes = node->GetRowSizes();

            // Push base address: fp + base_offset
            EmitString("PUSH " + std::to_string(baseOffset) + "\n");
            EmitString("PUSHFP\n");
            EmitString("PLUS\n");

            // For each subscript child (non-symbol), add offset
            int rsIdx = 0;
            for (int i = 1; i < node->NumChildren(); i++)
            {
                if (dynamic_cast<cSymbol*>(node->GetChild(i)) != nullptr)
                    continue;   // struct field — already in baseOffset

                int rowSize = (rsIdx < (int)rowsizes.size()) ? rowsizes[rsIdx] : 4;
                rsIdx++;

                node->GetChild(i)->Visit(this);     // subscript value
                EmitString("PUSH " + std::to_string(rowSize) + "\n");
                EmitString("TIMES\n");
                EmitString("PLUS\n");
            }
        }
};