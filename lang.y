%{
//**************************************
// lang.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Phil Howard 
//

#include <iostream>
#include "lex.h"
#include "astnodes.h"

class cFloatExprNode;
class cBinaryExprNode;

static bool g_semanticErrorHappened = false;

#define CHECK_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; } }
#define PROP_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; YYERROR; } }

%}

%locations

 /* union defines the type for lexical values */
%union{
    int             int_val;
    float           float_val;
    std::string*    str_val;
    cAstNode*       ast_node;
    cProgramNode*   program_node;
    cBlockNode*     block_node;
    cStmtsNode*     stmts_node;
    cPrintNode*     stmt_node;
    cExprNode*      expr_node;
    cIntExprNode*   int_node;
    cSymbol*        symbol;
    cDeclsNode*     decls_node;
    cParamNode*     param_node;
    cParamsNode*    params_node;
    cFuncDeclNode*  func_decl_node;
    cReturnNode*    return_node;
    cFuncCallNode*  func_call_node;
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
%type <param_node> paramspec
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
                            {  }
        |   struct_decl ';'
                            {  }
        |   func_decl
                            {  }
        |   error ';'
                            {  }

var_decl:   TYPE_ID IDENTIFIER
                { $$ = new cVarDeclNode($1, $2); 
                  CHECK_ERROR(); }
struct_decl:  STRUCT open decls close IDENTIFIER
                                {  }
array_decl:   ARRAY TYPE_ID '[' INT_VAL ']' IDENTIFIER
                                {  }

func_decl:  func_header ';'
                                { $$ = $1; CHECK_ERROR(); }
        |   func_header  '{' decls stmts '}'
                                { 
                                    $$ = $1;
                                    $$->AddChild($4);  // Add stmts
                                    cSymbol* name = (cSymbol*)$$->GetChild(1);
                                    $$->CheckMultipleDefinitions(name);
                                    CHECK_ERROR(); 
                                }
        |   func_header  '{' stmts '}'
                                { 
                                    $$ = $1;
                                    $$->AddChild($3);  // Add stmts
                                    cSymbol* name = (cSymbol*)$$->GetChild(1);
                                    $$->CheckMultipleDefinitions(name);
                                    CHECK_ERROR(); 
                                }
                                
func_header: func_prefix paramsspec ')'
                                { 
                                    cSymbol *returnType = (cSymbol*)((cAstNode*)$1)->GetChild(0);
                                    cSymbol *name = (cSymbol*)((cAstNode*)$1)->GetChild(1);
                                    $$ = new cFuncDeclNode(returnType, name, $2);
                                }
        |    func_prefix ')'
                                { 
                                    cSymbol *returnType = (cSymbol*)((cAstNode*)$1)->GetChild(0);
                                    cSymbol *name = (cSymbol*)((cAstNode*)$1)->GetChild(1);
                                    $$ = new cFuncDeclNode(returnType, name, nullptr);
                                }
func_prefix: TYPE_ID IDENTIFIER '('
                                { 
                                    $$ = new cPrefixNode();
                                    $$->AddChild($1);
                                    $$->AddChild($2);
                                }
paramsspec:  paramsspec ',' paramspec
                                { $$ = $1; $$->AddParam($3); }
        |   paramspec
                                { $$ = new cParamsNode($1); }

paramspec:  var_decl
                                { $$ = new cParamNode((cVarDeclNode*)$1); }

stmts:      stmts stmt
                                { $$ = $1; $$->Insert((cStmtNode*)$2); }
        |   stmt
                            { $$ = new cStmtsNode((cStmtNode*)$1); }
                            
stmt:       IF '(' expr ')' stmts ENDIF ';'
                                {  }
        |   IF '(' expr ')' stmts ELSE stmts ENDIF ';'
                                {  }
        |   WHILE '(' expr ')' stmt
                                {  }
        |   PRINT '(' expr ')' ';'
                                { $$ = new cPrintNode($3); }
        |   PRINTS '(' STRING_LIT ')' ';'
                                { }
        |   lval '=' expr ';'
                            {  }
        |   func_call ';'
                            {  }
        |   block
                            {  }
        |   RETURN expr ';'
                            { $$ = new cReturnNode($2); }
        |   error ';'
                            {}

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
                            { $$ = $1; }
        | varpart
                            { $$ = new cVarExprNode($1); }

varpart:  IDENTIFIER
                                { $$ = $1; }

lval:     varref
                                {  }

params:   params ',' param
                                { $$ = $1; $$->AddChild($3); }
        |   param
                                { 
                                    $$ = new cPrefixNode();
                                    $$->AddChild($1);
                                }
                            
param:      expr
                                { $$ = $1; }

expr:       expr EQUALS addit
                                {  }
        |   addit
                            { $$ = $1; }

addit:      addit '+' term
                                { $$ = new cBinaryExprNode($1, new cOpNode('+'), $3); }
        |   addit '-' term
                            { $$ = new cBinaryExprNode($1, new cOpNode('-'), $3); }
        |   term
                            { $$ = $1; }

term:       term '*' fact
                                { $$ = new cBinaryExprNode($1, new cOpNode('*'), $3); }
        |   term '/' fact
                            { $$ = new cBinaryExprNode($1, new cOpNode('/'), $3); }
        |   term '%' fact
                            { $$ = new cBinaryExprNode($1, new cOpNode('%'), $3); }
        |   fact
                            { $$ = $1; }

fact:       '(' expr ')'
                                {  }
        |   INT_VAL
                            { $$ = new cIntExprNode($1); }
        |   FLOAT_VAL
                            { $$ = new cFloatExprNode($1); }
        |   varref
                            { $$ = (cExprNode*)$1; }
        |   func_call
                            {  }

%%

// Function to format error messages
int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

// Function that gets called when a semantic error happens
void SemanticParseError(std::string error)
{
    std::cout << "ERROR: " << error << " near line " 
              << yylineno << "\n";
    g_semanticErrorHappened = true;
    yynerrs++;
}
