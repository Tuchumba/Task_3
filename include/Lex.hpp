#ifndef LEX_HPP
#define LEX_HPP

#include "settings.hpp"
#include "Ident.hpp"

#include <vector>
#include <ostream>


extern std::vector<Ident> TID;

class Lex {
    type_of_lex t_lex;
    int v_lex;
public:
    Lex (type_of_lex t = LEX_NULL, int v = 0) : t_lex (t), v_lex (v) {}
    type_of_lex  get_type() const;
    int get_value() const;
    friend std::ostream& operator<< (std::ostream &s, Lex l);
};

#endif