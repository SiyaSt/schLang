//
// Created by Анастасия on 02.10.2024.

#include <string>
#include "lexer.h"

#include <iostream>


lexer::lexer(const std::string& code)
{
    this->code = code;
}

Token* lexer::lexAnalysis()
{
    while(this->nextToken())
    {

    }
    return this->list;
}

bool lexer::nextToken()
{
    if(this->position >= this->code.length())
    {
        return false;
    }

    for(int i = 0; i< tokenTypeList.size(); i++)
    {
        auto tokenType = tokenTypeList[i].first;
        auto regex = std::regex("^" + tokenTypeList[i].second);
        auto result = std::regex_match(this->code.substr(this->position), regex);
        return true;
    }
}
