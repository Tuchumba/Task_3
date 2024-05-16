cmake_minimum_required(VERSION 3.6)

project(Task3)

add_executable(${PROJECT_NAME} main.cpp interpretator.cpp executer.cpp scanner.cpp ident.cpp lex.cpp parser.cpp)