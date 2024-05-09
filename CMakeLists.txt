cmake_minimum_required(VERSION 3.6)

project(Task3)

add_executable(${PROJECT_NAME} main.cpp executer.cpp ident.cpp interpretator.cpp lex.cpp parser.cpp scanner.cpp)