#ifndef PARSER_HPP
#define PARSER_HPP

#include "type_of_lex.hpp"
#include "lex.hpp"
#include "scanner.hpp"

#include <stack>


class Parser {
public:
    std::vector<Lex> poliz;
    Parser(const char *program) : scan(program) {}
    void analyze();
private:
    Lex curr_lex;
    type_of_lex c_type;
    int c_val;
    Scanner scan;
    std::stack<int> st_int;
    std::stack<type_of_lex> st_lex;
    void P();
    void D1();
    void D();
    void B();
    void S();
    void E();
    void E1();
    void T();
    void F();
    void dec(type_of_lex type);
    void check_id();
    void check_op();
    void check_not();
    void eq_type();
    void eq_bool();
    void check_id_in_read();
    void gl();
};

#endif