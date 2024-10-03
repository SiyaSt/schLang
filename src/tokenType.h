//
// Created by Анастасия on 02.10.2024.
//

#ifndef TOKENTYPE_H
#define TOKENTYPE_H
#include <string>
#include <regex>

class tokenType
{
    std::string name;
    std::regex regex;


public:
    tokenType(const std::string& name, const std::regex& regex);
};

enum tokenList
{       NUMBER = std::regex("[0-9]*"),
        VARIABLE = std::regex("[A-Za-z]*"),
        SEMICOLON = std::regex(";"),
        ASSIGN = std::regex(":"),
        LOG = std::regex("Console"),
        PLUS = std::regex("+"),
        MINUS = std::regex("-"),
        LPAR = std::regex("\\("),
        RPAR = std::regex("\\)"),
};

std::vector<std::pair<std::string, std::string>> tokenTypeList = {
    {"NUMBER", ("[0-9]*")},
    {"VARIABLE", ("[A-Za-z]*")},
    {"SEMICOLON", (";")},
    {"ASSIGN", (":")},
    {"LOG", ("Console")},
    {"PLUS", ("+")},
    {"MINUS", ("-")},
    {"LPAR", ("\\(")},
    {"RPAR", ("\\)")},
};
#endif //TOKENTYPE_H
