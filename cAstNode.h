#pragma once
//**************************************
// cAstNode.h
//
// Pure virtual base class for all AST nodes.
//
// Nodes form a tree structure where each node may have zero or more children.
// The tree is serialized to XML-style output via ToString(). Semantic analysis
// and other passes traverse the tree using the Visitor pattern (cVisitor).
//
// Author: Phil Howard
// phil.howard@oit.edu
//
// Modified by: Benjamin Kerr
//
// Date: 2025
//

#include <string>
#include <vector>
using std::string;
#include <iostream>

#include "cVisitor.h"

// Defined in lex.h -- included here to avoid circular dependency
extern int yylineno;    // Source line number at time of node creation
extern int yynerrs;     // Incremented on each semantic error

// SemanticParseError is used during parsing (in .y grammar rules) to report
// errors. It is distinct from SemanticError() below, which is called during
// visitor-based analysis passes after the parse is complete.
void SemanticParseError(std::string error);

class cAstNode
{
    public:
        //**************************************
        // Constructor: captures source line number at time of node creation
        cAstNode() : m_LineNum(yylineno), m_hasSemanticError(false) {}

        //**************************************
        // Append a child node to the end of the children list
        void AddChild(cAstNode *child)
        {
            m_children.push_back(child);
        }

        //**************************************
        // Return child node at the given index, or nullptr if out of range
        cAstNode* GetChild(int child)
        {
            if (child >= (int)m_children.size()) return nullptr;
            return m_children[child];
        }

        //**************************************
        // Return the number of direct children of this node
        int NumChildren() { return (int)m_children.size(); }

    //**************************************
    // Protected methods are restricted to use within the same class only.
    // Even subclasses may not call these on nodes of a different type.
    // Example: code in cExprNode may not call HasChildren() on a cVarExprNode.
    protected:

        //**************************************
        // Copy all children from another node into this node.
        // Used when a grammar rule consolidates children from a temporary node.
        void AddAllChildren(cAstNode *node)
        {
            if (node != nullptr && node->HasChildren())
            {
                for (auto* child : node->m_children)
                {
                    AddChild(child);
                }
            }
        }

        //**************************************
        // Returns true if this node has at least one child
        bool HasChildren() { return !m_children.empty(); }

        //**************************************
        // Replace the child at the given index. Index must already exist.
        void SetChild(int index, cAstNode *child)
        {
            m_children[index] = child;
        }

        //**************************************
        // Returns the name of the concrete node type (e.g. "varDecl").
        // Used by ToString() to produce XML tags.
        virtual std::string NodeType() = 0;

        //**************************************
        // Returns an XML attribute string for this node (e.g. " name='x'").
        // Override in subclasses that have attributes; default returns empty.
        virtual std::string AttributesToString() { return std::string(""); }

    public:
        //**************************************
        // Usage restrictions for the following public methods:
        //   ToString()          -- call only from main
        //   VisitAllChildren()  -- call only from cVisitor and its derivatives
        //   Visit()             -- call only from cVisitor and its derivatives
        //   SemanticError()     -- call only from cVisitor and its derivatives
        //   HasSemanticError()  -- call only from cVisitor and its derivatives
        //**************************************

        //**************************************
        // Serialize this node and all descendants to an XML-style string
        std::string ToString()
        {
            std::string result("");

            result += "<" + NodeType();
            result += AttributesToString();

            if (HasChildren())
            {
                result += ">";
                for (auto* child : m_children)
                {
                    if (child != nullptr) result += child->ToString();
                }
                result += "</" + NodeType() + ">\n";
            }
            else
            {
                result += " />";
            }

            return result;
        }

        //**************************************
        // Report a semantic error on this node. Increments the global error
        // count and marks this node so HasSemanticError() returns true.
        void SemanticError(std::string message)
        {
            std::cerr << "ERROR: " << message << " near line " << m_LineNum
                << "\n";
            yynerrs++;
            m_hasSemanticError = true;
        }

        //**************************************
        // Invoke visitor->Visit() on each direct child of this node.
        // Should only be called from cVisitor or its derivatives.
        void VisitAllChildren(cVisitor* visitor)
        {
            for (auto* child : m_children)
            {
                if (child != nullptr) child->Visit(visitor);
            }
        }

        //**************************************
        // Entry point for the visitor pattern. Every concrete subclass must
        // override with: virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        virtual void Visit(cVisitor *visitor) = 0;

        //**************************************
        // Returns true if this node or any descendant has a semantic error.
        // Allows passes to skip subtrees that already have errors.
        bool HasSemanticError()
        {
            if (m_hasSemanticError) return true;

            for (auto* child : m_children)
            {
                if (child != nullptr && child->HasSemanticError()) return true;
            }

            return false;
        }

    private:
        std::vector<cAstNode *> m_children;     // Ordered list of child nodes
        int m_LineNum;                           // Source line when node was created
        bool m_hasSemanticError;                 // True if a semantic error was reported on this node
};