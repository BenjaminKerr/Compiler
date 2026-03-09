/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LANGPARSE_H_INCLUDED
# define YY_YY_LANGPARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    TYPE_ID = 259,                 /* TYPE_ID  */
    CHAR_VAL = 260,                /* CHAR_VAL  */
    INT_VAL = 261,                 /* INT_VAL  */
    FLOAT_VAL = 262,               /* FLOAT_VAL  */
    LE = 263,                      /* LE  */
    GE = 264,                      /* GE  */
    AND = 265,                     /* AND  */
    OR = 266,                      /* OR  */
    EQUALS = 267,                  /* EQUALS  */
    NOT_EQUALS = 268,              /* NOT_EQUALS  */
    STRING_LIT = 269,              /* STRING_LIT  */
    PROGRAM = 270,                 /* PROGRAM  */
    PRINT = 271,                   /* PRINT  */
    PRINTS = 272,                  /* PRINTS  */
    WHILE = 273,                   /* WHILE  */
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    ENDIF = 276,                   /* ENDIF  */
    STRUCT = 277,                  /* STRUCT  */
    ARRAY = 278,                   /* ARRAY  */
    RETURN = 279,                  /* RETURN  */
    JUNK_TOKEN = 280               /* JUNK_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "lang.y"

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
    

#line 110 "langparse.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_LANGPARSE_H_INCLUDED  */
