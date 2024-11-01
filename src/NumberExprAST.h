//
// Created by Анастасия on 01.11.2024.
//

#ifndef NUMBEREXPRAST_H
#define NUMBEREXPRAST_H
#include "ExprAST.h"


class NumberExprAST : public ExprAST {
    double Val;
public:
    NumberExprAST(double val) : Val(val) {}
};


#endif //NUMBEREXPRAST_H
