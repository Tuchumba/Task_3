#ifndef LEX_HPP
#define LEX_HPP

#include "type_of_lex.hpp"
#include "ident.hpp"

#include <vector>
#include <ostream>


extern std::vector<Ident> TID;

class Lex {
public:
    Lex (type_of_lex t = LEX_NULL, int v = 0) : t_lex (t), v_lex (v) {}
    type_of_lex  get_type() const;
    int get_value() const;
    friend std::ostream& operator<< (std::ostream &s, Lex l);
private:
    type_of_lex t_lex;
    int v_lex;
};

#endif