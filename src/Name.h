//
// Created by Анастасия on 24.10.2024.
//

#ifndef NAME_H
#define NAME_H
#include "TokenKind.h"
#include <llvm/ADT/StringMap.h>
#include <llvm/Support/raw_ostream.h>


struct  Name {
    const char *Id;
    int Kind;
    size_t Length;
};

class NamesMap {
    bool IsInit;
    llvm::StringMap<Name> HashTable;
    Name *addName(StringRef Id, tok::TokenKind TokenCode);
public:
    NamesMap(): IsInit(false) { }
    void addKeywords();
    Name *getName(StringRef Id);
};



#endif //NAME_H
