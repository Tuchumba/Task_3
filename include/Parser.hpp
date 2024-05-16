#ifndef PARSER_HPP
#define PARSER_HPP

#include "settings.hpp"
#include "Lex.hpp"
#include "Scanner.hpp"

#include <iostream>
#include <stack>


class Parser {
    Lex curr_lex;
    type_of_lex c_type;
    int c_val;
    Scanner scan;
    std::stack<int> st_int;
    std::stack<type_of_lex> st_lex;
    void P();
    void D1(const std::string& name_space);
    void D();
    void B();
    void S();
    void E();
    void E1();
    void F1();
    void F();
    void declare(type_of_lex type);
    void check_declared();
    void check_op();
    void check_not();
    void eq_type();
    void eq_bool();
    void check_declared_in_read();
    void gl() {
        curr_lex = scan.get_lex();
        c_type = curr_lex.get_type();
        std::cout << c_type << std::endl;
        c_val = curr_lex.get_value();
    }
    char* name_before_dot();
    void check_has_dot();
    void rename_with_namespace(const std::string& name_space);
public:
    std::vector<Lex> poliz;
    void output_poliz();
    Parser(const char *program) : scan(program) {}
    void analyze();
};

#endif