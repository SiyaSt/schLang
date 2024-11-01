//
// Created by Анастасия on 01.11.2024.
//

#include "Lexer.h"

double Lexer::NumVal = 0;
std::string Lexer::IdentifierStr = " ";

/// gettok - Возвращает следующий токен из стандартного потока ввода.
int Lexer::getTok()
{
    static int LastChar = ' ';

    // Пропускаем пробелы.
    while (isspace(LastChar))
        LastChar = getchar();

    if (isalpha(LastChar))
    {
        // идентификатор: [a-zA-Z][a-zA-Z0-9]*
        IdentifierStr = std::to_string(LastChar);
        while (isalnum((LastChar = getchar())))
            IdentifierStr += std::to_string(LastChar);

        if (IdentifierStr == "def") return tok_def;
        if (IdentifierStr == "extern") return tok_extern;
        return tok_identifier;
    }

    if (isdigit(LastChar) || LastChar == '.')
    {
        // Число: [0-9.]+
        std::string NumStr;
        do
        {
            NumStr += std::to_string(LastChar);
            LastChar = getchar();
        }
        while (isdigit(LastChar) || LastChar == '.');

        NumVal = strtod(NumStr.c_str(), nullptr);
        return tok_number;
    }

    if (LastChar == '#')
    {
        // Комментарий до конца строки
        do LastChar = getchar();
        while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        if (LastChar != EOF)
            return getTok();
    }

    // Проверка конца файла.
    if (LastChar == EOF)
        return tok_eof;

    // В противном случае просто возвращаем символ как значение ASCII
    const int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}
