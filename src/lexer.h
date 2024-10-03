//
// Created by Анастасия on 02.10.2024.
//

#ifndef LEXER_H
#define LEXER_H
#include <string>

#include "token.h"
#include "tokenType.h"

class lexer
{
    std::string code;
    int position = 0;
    Token* list = {};
public:
    explicit lexer(const std::string& code);
    Token* lexAnalysis();
    bool nextToken();
};

#endif //LEXER_H
