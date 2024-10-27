//
// Created by Анастасия on 27.10.2024.
//

#ifndef TOKEN_H
#define TOKEN_H

namespace tok
{
    enum TokenKind : unsigned short
    {
#define TOK(ID, TEXT) ID,
#include "TokenKinds.def"
    };
} // tok

#endif //TOKEN_H
