//
// Created by Анастасия on 02.10.2024.
//
#include "token.h"
#include "tokenType.h"
#include <string>
Token::Token(tokenType* type, const std::string& text, const int position)
{
    this->type = type;
    this->text = text;
    this->position = position;
}
