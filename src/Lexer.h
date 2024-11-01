//
// Created by Анастасия on 01.11.2024.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <string>


//===----------------------------------------------------------------------===//
// Lexer (Лексический анализатор)
//===----------------------------------------------------------------------===//

// Лексический анализатор возвращает токены [0-255], если это неизвестны,
// иначе одну из известных единиц кода
enum Token
{
    tok_eof = -1,

    // команды (ключевые слова)
    tok_def = -2, tok_extern = -3,

    // операнды (первичные выражения: идентификаторы, числа)
    tok_identifier = -4, tok_number = -5
};

class Lexer
{
public:
    static std::string IdentifierStr; // Заполняется, если tok_identifier
    static double NumVal; // Заполняется, если tok_number

    static int getTok();
};


#endif //TOKEN_H
