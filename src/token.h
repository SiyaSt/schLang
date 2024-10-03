//
// Created by Анастасия on 02.10.2024.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <string>

#include "tokenType.h"


class Token
{
    tokenType* type;
    std::string text;
    int position;
public:
    Token(tokenType* type, const std::string& text, int position);
};

#endif //TOKEN_H
