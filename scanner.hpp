#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "lex.hpp"

#include <string>


class Scanner {
public:
    static const char* TW[];
    static const char* TD[];
    Scanner(const char * program);
    Lex get_lex();
private:
    FILE* fp;
    char c;
    int look(const std::string buf, const char** list);
    void gc();
};


#endif