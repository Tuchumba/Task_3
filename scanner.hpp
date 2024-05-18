#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "lex.hpp"

#include <string>

const bool STATUS_DEC = 0;
const bool STATUS_CODE = 1;



class Scanner {
public:
    static const char* TW[];
    static const char* TD[];
    Scanner(const char * program);
    Lex get_lex();
    void put_status(bool s);
    ~Scanner();
private:
    FILE* fp;
    char c;
    bool status;
    int look(const std::string buf, const char** list);
    void gc();
};


#endif