//
// Created by Анастасия on 01.11.2024.
//

#ifndef PROTOTYPEAST_H
#define PROTOTYPEAST_H
#include <string>
#include <utility>
#include <vector>


class PrototypeAST {
    std::string Name;
    std::vector<std::string> Args;
public:
    PrototypeAST(std::string name, const std::vector<std::string> &args)
      : Name(std::move(name)), Args(args) {}

};


#endif //PROTOTYPEAST_H
