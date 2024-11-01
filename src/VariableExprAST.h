//
// Created by Анастасия on 01.11.2024.
//

#ifndef VARIABLEEXPRAST_H
#define VARIABLEEXPRAST_H
#include <string>
#include <utility>

#include "ExprAST.h"


class VariableExprAST : public ExprAST {
    std::string Name;
public:
    explicit VariableExprAST(std::string name) : Name(std::move(name)) {}
};


#endif //VARIABLEEXPRAST_H
