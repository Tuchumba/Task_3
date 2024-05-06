#include "lex.hpp"

using namespace std;

type_of_lex lex::get_type() const { 
    return t_lex; 
}

int lex::get_value() const {
    return v_lex; 
}

ostream& operator<< (ostream &s, Lex l) {
    string t;
    if (l.t_lex <= LEX_WRITE)
        t = Scanner::TW[l.t_lex];
    else if (l.t_lex >= LEX_FIN && l.t_lex <= LEX_GEQ)
        t = Scanner::TD[l.t_lex - LEX_FIN];
    else if (l.t_lex == LEX_NUM)
        t = "NUMB";
    else if (l.t_lex == LEX_ID)
        t = TID[l.v_lex].get_name ();
    else if (l.t_lex == POLIZ_LABEL)
        t = "Label";
    else if (l.t_lex == POLIZ_ADDRESS)
        t = "Addr";
    else if (l.t_lex == POLIZ_GO)
        t = "!";
    else if (l.t_lex == POLIZ_FGO) 
        t = "!F";
    else
        throw l;
    s << '(' << t << ',' << l.v_lex << ");" << endl;
    return s;
}
