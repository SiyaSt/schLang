//
// Created by Анастасия on 01.11.2024.
//

#ifndef PARSER_H
#define PARSER_H
#include "ExprAST.h"
#include "FunctionAST.h"
#include "PrototypeAST.h"
#include "Parser.h"

class Parser
{
    static int CurTok;
    /// BinopPrecedence - Содержит приоритеты для бинарных операторов
    static std::map<char, int> BinopPrecedence;

public:
    static void setPriority(std::map<char, int> BinopPrecedence);
    static int getNextToken();
    static int GetTokPrecedence();
    static ExprAST *ParseIdentifierExpr();
    static ExprAST *ParseNumberExpr();
    static ExprAST* ParseParenExpr();
    static ExprAST* ParsePrimary();
    static ExprAST* ParseBinOpRHS(int ExprPrec, ExprAST* LHS);
    static ExprAST* ParseExpression();
    static ExprAST *ParseIfExpr();
    static ExprAST *ParseForExpr();
    static PrototypeAST* ParsePrototype();
    static FunctionAST* ParseDefinition();
    static FunctionAST* ParseTopLevelExpr();
    static PrototypeAST* ParseExtern();
    static void HandleDefinition();
    static void HandleExtern();
    static void HandleTopLevelExpression();
    static void MainLoop();
};

#endif //PARSER_H
