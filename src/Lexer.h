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
    tok_identifier = -4, tok_number = -5,

    // управление
    tok_if = -6, tok_then = -7, tok_else = -8,

    tok_for = -9, tok_in = -10
};

class Lexer
{
public:
    static std::string IdentifierStr; // Заполняется, если tok_identifier
    static double NumVal; // Заполняется, если tok_number

    static int getTok();
};


#endif //TOKEN_H
