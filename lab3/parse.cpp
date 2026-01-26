//**************************************
// parse.cpp
//
// Recursive descent parser for CST 320 Lab 3
//
// Author: Benjamin Kerr
//
#include <iostream>
#include "lex.h"
#include "parse.h"
#include "utils.h"

// Track if we've reported an error for the current statement
static bool g_stmt_error = false;

// Wrapper for Error that tracks if we've already reported an error
void StmtError(std::string expecting)
{
    if (!g_stmt_error)
    {
        Error(expecting);
        g_stmt_error = true;
    }
}

//*******************************************
// PROG -> STMTS end
bool FindPROG()
{
    if (!FindSTMTS()) return false;
    
    int token = PeekToken();
    if (token != END_TOKEN)
    {
        StmtError("end");
        return false;
    }
    AdvanceToken(); // consume 'end'
    
    return true;
}

//*******************************************
// STMTS -> STMT STMTS
//       -> λ (lambda/empty)
bool FindSTMTS()
{
    // Check if we can find a STMT
    // If not, that's okay - STMTS can be empty (lambda production)
    while (FindSTMT())
    {
        // Keep finding statements (tail recursion as a loop)
    }
    
    return true;
}

//*******************************************
// STMT -> EXPR ;
//      -> identifier = EXPR ;
bool FindSTMT()
{
    int token = PeekToken();
    
    // Reset error flag for this statement
    g_stmt_error = false;
    
    // Check for identifier at the start (might be assignment)
    if (token == IDENT_TOKEN)
    {
        AdvanceToken(); // consume identifier
        
        token = PeekToken();
        if (token == '=')
        {
            // identifier = EXPR ;
            AdvanceToken(); // consume '='
            
            // Try to parse expression
            FindEXPR();
            
            token = PeekToken();
            if (token != ';')
            {
                StmtError("';'");
                // Error recovery: skip to semicolon
                while (PeekToken() != ';' && PeekToken() != END_TOKEN && PeekToken() != 0)
                    AdvanceToken();
            }
            
            if (PeekToken() == ';') 
            {
                AdvanceToken(); // consume ';'
            }
            
            // Only print if no error occurred
            if (!g_stmt_error)
                std::cout << "Found a statement\n";
            return true;
        }
        else
        {
            // We consumed an identifier but it's not followed by '='
            StmtError("'='");
            // Error recovery: skip to semicolon
            while (PeekToken() != ';' && PeekToken() != END_TOKEN && PeekToken() != 0)
                AdvanceToken();
            if (PeekToken() == ';') AdvanceToken();
            
            // Don't print "Found a statement" because there was an error
            return true;
        }
    }
    else if (token == '(' || token == '[' || token == NUM_TOKEN || token == '{')
    {
        // STMT -> EXPR ;
        FindEXPR();
        
        token = PeekToken();
        if (token != ';')
        {
            StmtError("';'");
            // Error recovery: skip to semicolon
            while (PeekToken() != ';' && PeekToken() != END_TOKEN && PeekToken() != 0)
                AdvanceToken();
        }
        
        if (PeekToken() == ';')
        {
            AdvanceToken(); // consume ';'
        }
        
        // Only print if no error occurred
        if (!g_stmt_error)
            std::cout << "Found a statement\n";
        return true;
    }
    else
    {
        // Not the start of a statement
        return false;
    }
}

//*******************************************
// EXPR -> (EXPR) EXPR'
//      -> TERM
bool FindEXPR()
{
    int token = PeekToken();
    
    if (token == '(')
    {
        // EXPR -> (EXPR) EXPR'
        AdvanceToken(); // consume '('
        
        if (!FindEXPR())
        {
            StmtError("expression");
            return false;
        }
        
        token = PeekToken();
        if (token != ')')
        {
            StmtError("')'");
            return false;
        }
        AdvanceToken(); // consume ')'
        
        if (!FindEXPR_P())
        {
            return false;
        }
        
        return true;
    }
    else
    {
        // EXPR -> TERM
        return FindTERM();
    }
}

//*******************************************
// EXPR' -> PLUSOP (EXPR) EXPR'
//       -> λ
bool FindEXPR_P()
{
    int token = PeekToken();
    
    // Check if we have a PLUSOP
    if (token == '+' || token == '-')
    {
        // EXPR' -> PLUSOP (EXPR) EXPR'
        if (!FindPLUSOP()) return false;
        
        token = PeekToken();
        if (token != '(')
        {
            StmtError("'('");
            return false;
        }
        AdvanceToken(); // consume '('
        
        if (!FindEXPR())
        {
            StmtError("expression");
            return false;
        }
        
        token = PeekToken();
        if (token != ')')
        {
            StmtError("')'");
            return false;
        }
        AdvanceToken(); // consume ')'
        
        if (!FindEXPR_P())
        {
            return false;
        }
        
        return true;
    }
    else
    {
        // EXPR' -> λ (empty production)
        return true;
    }
}

//*******************************************
// PLUSOP -> +
//        -> -
bool FindPLUSOP()
{
    int token = PeekToken();
    
    if (token == '+' || token == '-')
    {
        AdvanceToken(); // consume the operator
        return true;
    }
    else
    {
        StmtError("'+' or '-'");
        return false;
    }
}

//*******************************************
// TERM -> [EXPR] TERM'
//      -> num
//      -> { identifier }
bool FindTERM()
{
    int token = PeekToken();
    
    if (token == '[')
    {
        // TERM -> [EXPR] TERM'
        AdvanceToken(); // consume '['
        
        if (!FindEXPR())
        {
            StmtError("expression");
            return false;
        }
        
        token = PeekToken();
        if (token != ']')
        {
            StmtError("']'");
            return false;
        }
        AdvanceToken(); // consume ']'
        
        if (!FindTERM_P())
        {
            return false;
        }
        
        return true;
    }
    else if (token == NUM_TOKEN)
    {
        // TERM -> num
        AdvanceToken(); // consume num
        return true;
    }
    else if (token == '{')
    {
        // TERM -> { identifier }
        AdvanceToken(); // consume '{'
        
        token = PeekToken();
        if (token != IDENT_TOKEN)
        {
            StmtError("identifier");
            return false;
        }
        AdvanceToken(); // consume identifier
        
        token = PeekToken();
        if (token != '}')
        {
            StmtError("'}'");
            return false;
        }
        AdvanceToken(); // consume '}'
        
        return true;
    }
    else
    {
        StmtError("'[', number, or '{'");
        return false;
    }
}

//*******************************************
// TERM' -> TIMESOP [EXPR] TERM'
//       -> λ
bool FindTERM_P()
{
    int token = PeekToken();
    
    // Check if we have a TIMESOP
    if (token == '*' || token == '/')
    {
        // TERM' -> TIMESOP [EXPR] TERM'
        if (!FindTIMESOP()) return false;
        
        token = PeekToken();
        if (token != '[')
        {
            StmtError("'['");
            return false;
        }
        AdvanceToken(); // consume '['
        
        if (!FindEXPR())
        {
            StmtError("expression");
            return false;
        }
        
        token = PeekToken();
        if (token != ']')
        {
            StmtError("']'");
            return false;
        }
        AdvanceToken(); // consume ']'
        
        if (!FindTERM_P())
        {
            return false;
        }
        
        return true;
    }
    else
    {
        // TERM' -> λ (empty production)
        return true;
    }
}

//*******************************************
// TIMESOP -> *
//         -> /
bool FindTIMESOP()
{
    int token = PeekToken();
    
    if (token == '*' || token == '/')
    {
        AdvanceToken(); // consume the operator
        return true;
    }
    else
    {
        StmtError("'*' or '/'");
        return false;
    }
}