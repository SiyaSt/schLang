cmake_minimum_required(VERSION 3.29)
project(schLang)

set(CMAKE_CXX_STANDARD 20)

add_executable(schLang main.cpp
        src/Name.cpp
        src/Name.h
        src/TokenKind.h
        src/TokenKind.cpp)

# Укажите путь к LLVM
# set(LLVM_DIR "C:/Program Files/LLVM/lib/cmake/llvm")

# find_package(LLVM REQUIRED CONFIG)
# include_directories(${LLVM_INCLUDE_DIRS})

# target_link_libraries(schLang ${LLVM_LIBS})
