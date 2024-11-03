//
// Created by Анастасия on 03.11.2024.
//

#ifndef FOREXPRAST_H
#define FOREXPRAST_H
#include <string>
#include <utility>

#include "ExprAST.h"

/// ForExprAST - Класс узла выражения для for/in.
class ForExprAST : public ExprAST
{
    std::string VarName;
    ExprAST *Start, *End, *Step, *Body;

public:
    ForExprAST(std::string  varname, ExprAST* start, ExprAST* end,
               ExprAST* step, ExprAST* body)
        : VarName(std::move(varname)), Start(start), End(end), Step(step), Body(body)
    {
    }

    //virtual Value* Codegen();
};
#endif //FOREXPRAST_H
