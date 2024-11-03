cmake_minimum_required(VERSION 3.29)
project(schLang)

set(CMAKE_CXX_STANDARD 20)

add_executable(schLang main.cpp
        src/ExprAST.h
        src/Lexer.h
        src/Lexer.cpp
        src/NumberExprAST.h
        src/VariableExprAST.h
        src/BinaryExprAST.h
        src/PrototypeAST.h
        src/FunctionAST.h
        src/Parser.cpp
        src/CallExprAST.h
        src/Parser.h
        src/IfExprAST.h
        src/ForExprAST.h
)


