%{
//**************************************
// lang.y
//
// Bison grammar file for the lang compiler.
//
// Defines the grammar for the lang language, which supports:
//   - Integer, float, and char primitive types
//   - Variable, array, and struct declarations
//   - Function declarations and definitions with typed parameters
//   - Arithmetic, relational, and logical expressions with C-style precedence
//   - If/else, while, print, return, and assignment statements
//   - Nested scopes via block constructs
//
// Author: Phil Howard
// phil.howard@oit.edu
//
// Modified by: Benjamin Kerr
//
// Date: 2025
//

#include <iostream>
#include "lex.h"
#include "astnodes.h"

// Tracks whether a semantic error occurred during the current grammar rule.
// Bison's yynerrs counts parse errors; this flag lets us detect semantic
// errors that happen mid-rule so we can decide whether to invoke YYERROR.
static bool g_semanticErrorHappened = false;

// Clear the semantic error flag after handling it. Use when the error is
// recoverable and parsing should continue normally.
#define CHECK_ERROR() { g_semanticErrorHappened = false; }

// Clear the semantic error flag and abort the current rule via YYERROR.
// Use when a semantic error makes the partially-built AST node unusable
// and continuing would cause cascading errors.
#define PROP_ERROR() { g_semanticErrorHappened = false; YYERROR; }

%}

%locations

// Union defines the possible types for semantic values ($$ / $1 etc.)
%union{
    int             int_val;        // integer literal value
    float           float_val;      // float literal value
    std::string*    str_val;        // string literal value
    cAstNode*       ast_node;       // generic AST node
    cProgramNode*   program_node;   // top-level program node
    cBlockNode*     block_node;     // scoped block
    cStmtsNode*     stmts_node;     // list of statements
    cPrintNode*     stmt_node;      // print statement
    cExprNode*      expr_node;      // expression
    cIntExprNode*   int_node;       // integer literal expression
    cSymbol*        symbol;         // symbol table entry
    cDeclsNode*     decls_node;     // list of declarations
    cParamNode*     param_node;     // single parameter declaration
    cParamsNode*    params_node;    // list of parameter declarations
    cFuncDeclNode*  func_decl_node; // function declaration/definition
    cReturnNode*    return_node;    // return statement
    cFuncCallNode*  func_call_node; // function call expression
    }

%{
    int yyerror(const char *msg);

    cAstNode *yyast_root;
%}

%start  program

%token <symbol>    IDENTIFIER
%token <symbol>    TYPE_ID
%token <int_val>   CHAR_VAL
%token <int_val>   INT_VAL
%token <float_val> FLOAT_VAL
%token <int_val>   LE
%token <int_val>   GE
%token <int_val>   AND
%token <int_val>   OR
%token <int_val>   EQUALS
%token <int_val>   NOT_EQUALS
%token <str_val>   STRING_LIT

%token  PROGRAM
%token  PRINT PRINTS
%token  WHILE IF ELSE ENDIF
%token  STRUCT ARRAY
%token  RETURN
%token  JUNK_TOKEN

%type <program_node> program
%type <block_node> block
%type <ast_node> open
%type <ast_node> close
%type <decls_node> decls
%type <ast_node> decl
%type <ast_node> var_decl
%type <ast_node> struct_decl
%type <ast_node> array_decl
%type <func_decl_node> func_decl
%type <func_decl_node> func_header
%type <ast_node> func_prefix
%type <func_call_node> func_call
%type <params_node> paramsspec
%type <ast_node> paramspec
%type <ast_node> params
%type <ast_node> param
%type <stmts_node> stmts
%type <ast_node> stmt
%type <ast_node> lval
%type <expr_node> expr
%type <expr_node> addit
%type <expr_node> term
%type <expr_node> fact
%type <ast_node> varref
%type <symbol> varpart
%type <expr_node> andexpr
%type <expr_node> relexpr
%type <expr_node> unary

%%

program: PROGRAM block
                                { $$ = new cProgramNode($2);
                                  yyast_root = $$;
                                  if (yynerrs == 0)
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
block:  open decls stmts close
                                { $$ = new cBlockNode($2, $3); }
    |   open stmts close
                                { $$ = new cBlockNode(nullptr, $2); }

// open/close use mid-rule actions to maintain the symbol table scope stack
// in sync with the syntactic block structure of the source program.
open:   '{'
                                { g_symbolTable.IncreaseScope(); }

close:  '}'
                                { g_symbolTable.DecreaseScope(); }

decls:      decls decl
                                { $$ = $1; $$->Insert((cDeclNode*)$2); }
        |   decl
                                { $$ = new cDeclsNode((cDeclNode*)$1); }

decl:       var_decl ';'
                                { $$ = $1; }
        |   array_decl ';'
                                { $$ = $1; }
        |   struct_decl ';'
                                { $$ = $1; }
        |   func_decl
                                { $$ = $1; }
        |   error ';'
                                { $$ = nullptr; }

var_decl:   TYPE_ID IDENTIFIER
                                {
                                    // Insert a fresh symbol into the current scope before
                                    // constructing the node so FindLocal detects redeclarations
                                    cSymbol *fresh = new cSymbol($2->GetName());
                                    g_symbolTable.Insert(fresh);
                                    $$ = new cVarDeclNode($1, fresh);
                                    CHECK_ERROR();
                                }

struct_decl:  STRUCT open decls close IDENTIFIER
                                { $$ = nullptr; /* TODO: implement struct declarations */ }

array_decl:   ARRAY TYPE_ID '[' INT_VAL ']' IDENTIFIER
                                { $$ = new cArrayDeclNode($2, $4, $6); }

func_decl:  func_header ';'
                                {
                                    // Forward declaration only -- no body
                                    g_symbolTable.DecreaseScope();
                                    $$ = $1;
                                    CHECK_ERROR();
                                }
        |   func_header  '{' decls stmts '}'
                                {
                                    $$ = $1;
                                    $$->AddChild($3);
                                    $$->AddChild($4);
                                    // child(1) is the function name symbol
                                    cSymbol *name = (cSymbol*)$$->GetChild(1);
                                    $$->CheckMultipleDefinitions(name);
                                    g_symbolTable.DecreaseScope();
                                    CHECK_ERROR();
                                }
        |   func_header  '{' stmts '}'
                                {
                                    $$ = $1;
                                    $$->AddChild($3);
                                    // child(1) is the function name symbol
                                    cSymbol *name = (cSymbol*)$$->GetChild(1);
                                    $$->CheckMultipleDefinitions(name);
                                    g_symbolTable.DecreaseScope();
                                    CHECK_ERROR();
                                }

func_header: func_prefix { g_symbolTable.IncreaseScope(); } paramsspec ')'
                                {
                                    // func_prefix holds child(0)=return type, child(1)=name
                                    cSymbol *returnType = (cSymbol*)((cAstNode*)$1)->GetChild(0);
                                    cSymbol *name       = (cSymbol*)((cAstNode*)$1)->GetChild(1);
                                    $$ = new cFuncDeclNode(returnType, name, $3);
                                }
        |    func_prefix { g_symbolTable.IncreaseScope(); } ')'
                                {
                                    cSymbol *returnType = (cSymbol*)((cAstNode*)$1)->GetChild(0);
                                    cSymbol *name       = (cSymbol*)((cAstNode*)$1)->GetChild(1);
                                    $$ = new cFuncDeclNode(returnType, name, nullptr);
                                }

func_prefix: TYPE_ID IDENTIFIER '('
                                {
                                    $$ = new cPrefixNode();
                                    $$->AddChild($1);
                                    $$->AddChild($2);
                                }

paramsspec: paramsspec ',' paramspec
                                { $$ = $1; $$->AddChild($3); }
        |   paramspec
                                { $$ = new cParamsNode($1); }

paramspec: var_decl
                                { $$ = $1; }

stmts:      stmts stmt
                                { $$ = $1; $$->Insert((cStmtNode*)$2); }
        |   stmt
                                { $$ = new cStmtsNode((cStmtNode*)$1); }

stmt:       IF '(' expr ')' stmts ENDIF ';'
                                { $$ = nullptr; /* TODO: implement if statement */ }
        |   IF '(' expr ')' stmts ELSE stmts ENDIF ';'
                                { $$ = nullptr; /* TODO: implement if/else statement */ }
        |   WHILE '(' expr ')' stmt
                                { $$ = nullptr; /* TODO: implement while statement */ }
        |   PRINT '(' expr ')' ';'
                                { $$ = new cPrintNode($3); }
        |   PRINTS '(' STRING_LIT ')' ';'
                                { $$ = nullptr; /* TODO: implement string print */ }
        |   lval '=' expr ';'
                                { $$ = new cAssignNode($1, $3); }
        |   func_call ';'
                                { $$ = nullptr; /* function called for side effects only */ }
        |   block
                                { $$ = $1; }
        |   RETURN expr ';'
                                { $$ = new cReturnNode($2); }
        |   error ';'
                                { $$ = nullptr; }

func_call:  IDENTIFIER '(' params ')'
                                {
                                    $$ = new cFuncCallNode($1, $3);
                                    CHECK_ERROR();
                                }
        |   IDENTIFIER '(' ')'
                                {
                                    $$ = new cFuncCallNode($1);
                                    CHECK_ERROR();
                                }

varref:   varref '.' varpart
                                { $$ = $1; ((cVarExprNode*)$$)->AddSymbol($3); }
        | varref '[' expr ']'
                                { $$ = $1; $$->AddChild($3); }
        | varpart
                                { $$ = new cVarExprNode($1); }

varpart:  IDENTIFIER
                                { $$ = $1; }

lval:     varref
                                { $$ = $1; }

params:   params ',' param
                                { $$ = $1; $$->AddChild($3); }
        |   param
                                {
                                    $$ = new cPrefixNode();
                                    $$->AddChild($1);
                                }

param:      expr
                                { $$ = $1; }

expr:       expr OR andexpr
                                { $$ = new cBinaryExprNode($1, new cOpNode(OR), $3); }
        |   andexpr
                                { $$ = $1; }

andexpr:    andexpr AND relexpr
                                { $$ = new cBinaryExprNode($1, new cOpNode(AND), $3); }
        |   relexpr
                                { $$ = $1; }

relexpr:    relexpr EQUALS addit
                                { $$ = new cBinaryExprNode($1, new cOpNode(EQUALS), $3); }
        |   relexpr NOT_EQUALS addit
                                { $$ = new cBinaryExprNode($1, new cOpNode(NOT_EQUALS), $3); }
        |   relexpr '<' addit
                                { $$ = new cBinaryExprNode($1, new cOpNode('<'), $3); }
        |   relexpr '>' addit
                                { $$ = new cBinaryExprNode($1, new cOpNode('>'), $3); }
        |   relexpr LE addit
                                { $$ = new cBinaryExprNode($1, new cOpNode(LE), $3); }
        |   relexpr GE addit
                                { $$ = new cBinaryExprNode($1, new cOpNode(GE), $3); }
        |   addit
                                { $$ = $1; }

addit:      addit '+' term
                                { $$ = new cBinaryExprNode($1, new cOpNode('+'), $3); }
        |   addit '-' term
                                { $$ = new cBinaryExprNode($1, new cOpNode('-'), $3); }
        |   term
                                { $$ = $1; }

term:       term '*' unary
                                { $$ = new cBinaryExprNode($1, new cOpNode('*'), $3); }
        |   term '/' unary
                                { $$ = new cBinaryExprNode($1, new cOpNode('/'), $3); }
        |   term '%' unary
                                { $$ = new cBinaryExprNode($1, new cOpNode('%'), $3); }
        |   unary
                                { $$ = $1; }

unary:      '-' unary
                                { $$ = new cUnaryExprNode(new cOpNode('-'), $2); }
        |   fact
                                { $$ = $1; }

fact:       '(' expr ')'
                                { $$ = $2; }
        |   INT_VAL
                                { $$ = new cIntExprNode($1); }
        |   FLOAT_VAL
                                { $$ = new cFloatExprNode($1); }
        |   varref
                                { $$ = (cExprNode*)$1; }
        |   func_call
                                { $$ = $1; }

%%

// Format and print a bison parse error to stderr
int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";
    return 0;
}

// Called when a semantic error is detected during parsing.
// Sets g_semanticErrorHappened so grammar rules can decide whether to
// propagate via PROP_ERROR() or recover via CHECK_ERROR().
void SemanticParseError(std::string error)
{
    std::cerr << "ERROR: " << error << " near line "
              << yylineno << "\n";
    g_semanticErrorHappened = true;
    yynerrs++;
}
