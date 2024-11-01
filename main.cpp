//
// Created by Анастасия on 24.10.2024.
//

#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include "src/Parser.h"

//===----------------------------------------------------------------------===//
// Main driver code (Код основной программы)
//===----------------------------------------------------------------------===//

int main() {
  // Задаём стандартные бинарные операторы.
  // 1 - наименьший приоритет.
  std::map<char, int> BinopPrecedence;
  BinopPrecedence['+'] = 20;
  BinopPrecedence['-'] = 20;
  BinopPrecedence['*'] = 40;  // highest.

  Parser::setPriority(BinopPrecedence);

  fprintf(stderr, "ready> ");
  Parser::getNextToken();

  // Теперь запускаем основной "цикл интерпретатора".
  Parser::MainLoop();

  return 0;
}