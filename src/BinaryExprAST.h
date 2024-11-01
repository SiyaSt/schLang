//
// Created by Анастасия on 01.11.2024.
//

#ifndef BINARYEXPRAST_H
#define BINARYEXPRAST_H
#include "ExprAST.h"


class BinaryExprAST : public ExprAST {
    char Op;
    ExprAST *LHS, *RHS;
public:
    BinaryExprAST(char op, ExprAST *lhs, ExprAST *rhs)
      : Op(op), LHS(lhs), RHS(rhs) {}
};



#endif //BINARYEXPRAST_H
