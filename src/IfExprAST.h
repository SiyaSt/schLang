//
// Created by Анастасия on 03.11.2024.
//

#ifndef IFEXPRAST_H
#define IFEXPRAST_H
#include "ExprAST.h"

class IfExprAST : public ExprAST {
    ExprAST *Cond, *Then, *Else;
public:
    IfExprAST(ExprAST *cond, ExprAST *then, ExprAST *_else)
      : Cond(cond), Then(then), Else(_else) {}
    //virtual Value *Codegen();
};

#endif //IFEXPRAST_H
