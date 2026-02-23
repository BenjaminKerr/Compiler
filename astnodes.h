#pragma once
//**************************************
// astnodes.h
//
// Single place that includes all the ast nodes.
// Useful for lang.y and lang.l
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2015
//
#include "cAssignNode.h"
#include "cAstNode.h"
#include "cSymbol.h"
#include "cStmtNode.h"
#include "cStmtsNode.h"
#include "cDeclNode.h"
#include "cBaseTypeNode.h"
#include "cDeclsNode.h"
#include "cBlockNode.h"
#include "cProgramNode.h"
#include "cPrintNode.h"
#include "cExprNode.h"
#include "cIntExprNode.h"
#include "cFloatExprNode.h"
#include "cVarDeclNode.h"
#include "cVarExprNode.h"
#include "cOpNode.h"
#include "cBinaryExprNode.h"
#include "cParamNode.h"
#include "cParamsNode.h"
#include "cFuncDeclNode.h"
#include "cReturnNode.h"
#include "cFuncCallNode.h"
#include "cPrefixNode.h"
#include "cUnaryExprNode.h"
#include "cArrayDeclNode.h"