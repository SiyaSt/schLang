//
// Created by Анастасия on 01.11.2024.
//

#ifndef CALLEXPRAST_H
#define CALLEXPRAST_H
#include <string>
#include <utility>
#include <vector>

#include "ExprAST.h"

class CallExprAST : public ExprAST {
    std::string Callee;
    std::vector<ExprAST*> Args;
public:
    CallExprAST(std::string callee, std::vector<ExprAST*> &args)
      : Callee(std::move(callee)), Args(args) {}
};

#endif //CALLEXPRAST_H
