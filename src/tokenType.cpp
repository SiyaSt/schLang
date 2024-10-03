//
// Created by Анастасия on 02.10.2024.
//

#include "tokenType.h"
#include <string>
#include <regex>

tokenType::tokenType(const std::string& name, const std::regex& regex)
{
    this->name = name;
    this->regex = regex;
}


