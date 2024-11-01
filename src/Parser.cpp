//
// Created by Анастасия on 01.11.2024.
//


//===----------------------------------------------------------------------===//
// Parser (Парсер или Синтаксический Анализатор)
//===----------------------------------------------------------------------===//

#include <map>
#include <utility>

#include "BinaryExprAST.h"
#include "CallExprAST.h"
#include "ExprAST.h"
#include "FunctionAST.h"
#include "Lexer.h"
#include "NumberExprAST.h"
#include "PrototypeAST.h"
#include "VariableExprAST.h"
#include "Parser.h"


int Parser::CurTok = 0;
std::map<char, int> Parser::BinopPrecedence = {};


/// CurTok/getNextToken - Предоставляет простой буфер токенов. CurTok - это текущий
/// токен, просматриваемый парсером. getNextToken получает следующий токен от
/// лексического анализатора и обновляет CurTok.


void Parser::setPriority(std::map<char, int> a)
{
    BinopPrecedence = std::move(a);
}

int Parser::getNextToken()
{
    return CurTok = Lexer::getTok();
}


/// GetTokPrecedence - Возвращает приоритет текущего бинарного оператора.
int Parser::GetTokPrecedence()
{
    if (!isascii(CurTok))
        return -1;

    // Удостоверимся, что это объявленный бинарный оператор.
    int TokPrec = BinopPrecedence[CurTok];
    if (TokPrec <= 0) return -1;
    return TokPrec;
}

/// Error* - Это небольшие вспомогательные функции для обработки ошибок.
ExprAST* Error(const char* Str)
{
    fprintf(stderr, "Error: %s\n", Str);
    return nullptr;
}

PrototypeAST* ErrorP(const char* Str)
{
    Error(Str);
    return nullptr;
}

FunctionAST* ErrorF(const char* Str)
{
    Error(Str);
    return nullptr;
}

/// identifierexpr
///   ::= identifier
///   ::= identifier '(' expression* ')'
ExprAST* Parser::ParseIdentifierExpr()
{
    std::string IdName = Lexer::IdentifierStr;

    getNextToken(); // получаем идентификатор.

    if (CurTok != '(') // Обычная переменная.
        return new VariableExprAST(IdName);

    // Вызов функции.
    getNextToken(); // получаем (
    std::vector<ExprAST*> Args;
    if (CurTok != ')')
    {
        while (true)
        {
            ExprAST* Arg = ParseExpression();
            if (!Arg) return nullptr;
            Args.push_back(Arg);

            if (CurTok == ')') break;

            if (CurTok != ',')
                return Error("Expected ')' or ',' in argument list");
            getNextToken();
        }
    }

    // Получаем ')'.
    getNextToken();

    return new CallExprAST(IdName, Args);
}

/// numberexpr ::= number
ExprAST* Parser::ParseNumberExpr()
{
    ExprAST* Result = new NumberExprAST(Lexer::NumVal);
    getNextToken(); // получаем число
    return Result;
}

/// parenexpr ::= '(' expression ')'
ExprAST* Parser::ParseParenExpr()
{
    getNextToken(); // получаем (.
    ExprAST* V = ParseExpression();
    if (!V) return nullptr;

    if (CurTok != ')')
        return Error("expected ')'");
    getNextToken(); // получаем ).
    return V;
}

/// primary
///   ::= identifierexpr
///   ::= numberexpr
///   ::= parenexpr
ExprAST* Parser::ParsePrimary()
{
    switch (CurTok)
    {
    case tok_identifier: return ParseIdentifierExpr();
    case tok_number: return ParseNumberExpr();
    case '(': return ParseParenExpr();
    default: return Error("unknown token when expecting an expression");
    }
}

/// binoprhs
///   ::= ('+' primary)*
ExprAST* Parser::ParseBinOpRHS(int ExprPrec, ExprAST* LHS)
{
    // Если это бинарный оператор, получаем его приоритет
    while (true)
    {
        int TokPrec = GetTokPrecedence();

        // Если этот бинарный оператор связывает выражения по крайней мере так же,
        // как текущий, то используем его
        if (TokPrec < ExprPrec)
            return LHS;

        // Отлично, мы знаем, что это бинарный оператор.
        int BinOp = CurTok;
        getNextToken(); // eat binop

        // Разобрать первичное выражение после бинарного оператора
        ExprAST* RHS = ParsePrimary();
        if (!RHS) return nullptr;

        // Если BinOp связан с RHS меньшим приоритетом, чем оператор после RHS,
        // то берём часть вместе с RHS как LHS.
        int NextPrec = GetTokPrecedence();
        if (TokPrec < NextPrec)
        {
            RHS = ParseBinOpRHS(TokPrec + 1, RHS);
            if (RHS == nullptr) return nullptr;
        }

        // Собираем LHS/RHS.
        LHS = new BinaryExprAST(BinOp, LHS, RHS);
    }
}

/// expression
///   ::= primary binoprhs
///
ExprAST* Parser::ParseExpression()
{
    ExprAST* LHS = ParsePrimary();
    if (!LHS) return nullptr;

    return ParseBinOpRHS(0, LHS);
}

/// prototype
///   ::= id '(' id* ')'
PrototypeAST* Parser::ParsePrototype()
{
    if (CurTok != tok_identifier)
        return ErrorP("Expected function name in prototype");

    std::string FnName = Lexer::IdentifierStr;
    getNextToken();

    if (CurTok != '(')
        return ErrorP("Expected '(' in prototype");

    // Считываем список наименований аргументов.
    std::vector<std::string> ArgNames;
    while (getNextToken() == tok_identifier)
        ArgNames.push_back(Lexer::IdentifierStr);
    if (CurTok != ')')
        return ErrorP("Expected ')' in prototype");

    // Все отлично.
    getNextToken(); // получаем ')'.

    return new PrototypeAST(FnName, ArgNames);
}

/// definition ::= 'def' prototype expression
FunctionAST* Parser::ParseDefinition()
{
    getNextToken(); // Получаем def.
    PrototypeAST* Proto = ParsePrototype();
    if (Proto == nullptr) return nullptr;

    if (ExprAST* E = ParseExpression())
        return new FunctionAST(Proto, E);
    return nullptr;
}

/// toplevelexpr ::= expression
FunctionAST* Parser::ParseTopLevelExpr()
{
    if (ExprAST* E = ParseExpression())
    {
        // Создаём анонимный прототип.
        auto* Proto = new PrototypeAST("", std::vector<std::string>());
        return new FunctionAST(Proto, E);
    }
    return nullptr;
}

/// external ::= 'extern' prototype
PrototypeAST* Parser::ParseExtern()
{
    getNextToken(); // получаем extern.
    return ParsePrototype();
}

//===----------------------------------------------------------------------===//
// Top-Level parsing (Парсинг верхнего уровня)
//===----------------------------------------------------------------------===//

void Parser::HandleDefinition()
{
    if (ParseDefinition())
    {
        fprintf(stderr, "Parsed a function definition.\n");
    }
    else
    {
        // Пропускаем токен для восстановления после ошибки.
        getNextToken();
    }
}

void Parser::HandleExtern()
{
    if (ParseExtern())
    {
        fprintf(stderr, "Parsed an extern\n");
    }
    else
    {
        // Пропускаем токен для восстановления после ошибки.
        getNextToken();
    }
}

void Parser::HandleTopLevelExpression()
{
    // Рассчитываем верхнеуровневое выражение в анонимной функции.
    if (ParseTopLevelExpr())
    {
        fprintf(stderr, "Parsed a top-level expr\n");
    }
    else
    {
        // Пропускаем токен для восстановления после ошибки.
        getNextToken();
    }
}

/// top ::= definition | external | expression | ';'
void Parser::MainLoop()
{
    while (true)
    {
        fprintf(stderr, "ready> ");
        switch (CurTok)
        {
        case tok_eof: return;
        case ';': getNextToken();
            break; // игнорируем верхнеуровневые точки с запятой.
        case tok_def: HandleDefinition();
            break;
        case tok_extern: HandleExtern();
            break;
        default: HandleTopLevelExpression();
            break;
        }
    }
}
