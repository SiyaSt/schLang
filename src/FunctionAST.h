//
// Created by Анастасия on 01.11.2024.
//

#ifndef FUNCTIONAST_H
#define FUNCTIONAST_H
#include "ExprAST.h"
#include "PrototypeAST.h"


class FunctionAST {
    PrototypeAST *Proto;
    ExprAST *Body;
public:
    FunctionAST(PrototypeAST *proto, ExprAST *body)
      : Proto(proto), Body(body) {}

};


#endif //FUNCTIONAST_H
