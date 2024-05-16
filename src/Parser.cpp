#include "Parser.hpp"

#include <iostream>
#include <cstring>

using namespace std;

template <class F1, class T_EL>
void from_stack(F1& st, T_EL& i) {
    i = st.top(); st.pop();
}

void Parser::output_poliz(){
    cout << "POLIZ:" << endl;
    for(Lex l : poliz) {
        cout << l;        
    }
    cout << endl;
}

void Parser::analyze() {
    gl();
    P();
    if(c_type != LEX_FIN) {
        throw curr_lex;        
    }
    output_poliz();
}

void Parser::P() {
    if(c_type == LEX_PROGRAM) {
        gl();
    } else {
        throw curr_lex;       
    }
    D1(nullptr);
    if(c_type == LEX_SEMICOLON) {
        gl();        
    } else {
        throw curr_lex;        
    }
    B();
}

void Parser::D1(const string& name_space ) {
    if(c_type == LEX_VAR) {
        gl();
        D();
        while(c_type == LEX_COMMA) {
            gl();
            D();
        }
    } else {
        throw curr_lex;        
    }
}

void Parser::D() {
    if(c_type != LEX_ID) {
        throw curr_lex;        
    } else {
        check_has_dot();
        st_int.push(c_val);
        gl();
        while(c_type == LEX_COMMA) {
            gl();
            if(c_type != LEX_ID) {
                throw curr_lex;                
            } else {
                check_has_dot();
                st_int.push(c_val);
                gl();
            }
        }
        if( c_type != LEX_COLON ) {
            throw curr_lex;            
        } else {
            gl();
            switch(c_type) {
                case LEX_INT:
                    declare( LEX_INT ); break;
                case LEX_BOOL:
                    declare( LEX_BOOL ); break;
                case LEX_RECORD:
                    declare( LEX_RECORD ); break;
                default:
                    throw curr_lex;
            }
            gl();
        }
    }
}

void Parser::B() {
    if(c_type == LEX_BEGIN) {
        gl();
        S();
        while(c_type == LEX_SEMICOLON) {
            gl();
            S();
        }
        if(c_type == LEX_END){
            gl();
        }
        else{
            throw curr_lex;
        }
    } else {
        throw curr_lex;        
    }
}

void Parser::S() {
    int pl0, pl1, pl2, pl3;

    if(c_type == LEX_IF) {
        gl();
        E();
        eq_bool();
        pl2 = poliz.size();
        poliz.push_back(Lex());
        poliz.push_back(Lex(POLIZ_FGO));
        if(c_type == LEX_THEN) {
            gl();
            S();
            pl3 = poliz.size();
            poliz.push_back(Lex());
            poliz.push_back(Lex(POLIZ_GO));
            poliz[pl2] = Lex(POLIZ_LABEL, poliz.size());
 
            if(c_type == LEX_ELSE) {
                gl();
                S();
                poliz[pl3] = Lex(POLIZ_LABEL, poliz.size());
            } else {
                throw curr_lex;                
            }
        }
        else {
            throw curr_lex;            
        }
    } else if(c_type == LEX_WHILE) {
        pl0 = poliz.size();
        gl();
        E();
        eq_bool();
        pl1 = poliz.size();
        poliz.push_back(Lex());
        poliz.push_back(Lex(POLIZ_FGO));
        if(c_type == LEX_DO) {
            gl();
            S();
            poliz.push_back(Lex(POLIZ_LABEL, pl0));
            poliz.push_back(Lex( POLIZ_GO));
            poliz[pl1] = Lex(POLIZ_LABEL, poliz.size());
        }
        else {
            throw curr_lex;            
        }
    } else if(c_type == LEX_READ) {
        gl();
        if(c_type == LEX_LPAREN) {
            gl();
            if(c_type == LEX_ID){
                check_declared_in_read();
                poliz.push_back(Lex(POLIZ_ADDRESS, c_val));
                gl();
            } else {
                throw curr_lex;                
            }
            if(c_type == LEX_RPAREN) {
                gl();
                poliz.push_back(Lex(LEX_READ));
            }    
            else {
                throw curr_lex;                
            }
        }
        else {
            throw curr_lex;            
        }
    } else if(c_type == LEX_WRITE) {
        gl();
        if(c_type == LEX_LPAREN) {
            gl();
            E();
            if(c_type == LEX_RPAREN) {
                gl();
                poliz.push_back(Lex(LEX_WRITE));
            } else {
                throw curr_lex;                
            }
        }
        else {
            throw curr_lex;            
        }
    } else if(c_type == LEX_ID) {
        check_declared();
        poliz.push_back(Lex(POLIZ_ADDRESS, c_val));
        gl();
        if(c_type == LEX_ASSIGN){
            gl();
            E();
            eq_type();
            poliz.push_back(Lex(LEX_ASSIGN));
        }
        else
            throw curr_lex;
    } else {
        B();        
    }
}

void Parser::E() {
    E1();
    if(c_type == LEX_EQ || c_type == LEX_LSS || c_type == LEX_GTR ||
        c_type == LEX_LEQ || c_type == LEX_GEQ || c_type == LEX_NEQ) {
        st_lex.push(c_type);
        gl(); 
        E1(); 
        check_op();
    }
}

void Parser::E1() {
    F1();
    while(c_type == LEX_PLUS || c_type == LEX_MINUS || c_type == LEX_OR) {
        st_lex.push(c_type);
        gl();
        F1();
        check_op();
    }
}

void Parser::F1() {
    F();
    while(c_type == LEX_TIMES || c_type == LEX_SLASH || c_type == LEX_AND) {
        st_lex.push(c_type);
        gl();
        F();
        check_op();
    }
}

void Parser::F() {
    switch (c_type) {
    case LEX_ID:
        check_declared();
        poliz.push_back(curr_lex);
        gl();
        break;
    case LEX_NUM:
        st_lex.push(LEX_INT);
        poliz.push_back(curr_lex);
        gl();
        break;
    case LEX_TRUE:
        st_lex.push(LEX_BOOL);
        poliz.push_back(Lex(LEX_TRUE, 1));
        gl();
        break;
    case LEX_FALSE:
        st_lex.push(LEX_BOOL);
        poliz.push_back(Lex(LEX_FALSE, 0));
        gl();
        break;
    case LEX_NOT:
        gl();
        F();
        check_not();
        break;
    case LEX_LPAREN:
        gl();
        E();
        if (c_type == LEX_RPAREN)
            gl();
        else {
            throw curr_lex;
        }
        break;
    default:
        throw curr_lex;
    }
}

void Parser::rename_with_namespace(const std::string& name_space){
  std::stack<int> tmp;
  while (!st_int.empty()) {
    tmp.push(st_int.top());
    TID[st_int.top()].add_namespace(name_space);
    st_int.pop();
  }
  while (!tmp.empty()) {
    st_int.push(tmp.top());
    tmp.pop();
  }
  std::cout << std::endl;
}

void Parser::declare(type_of_lex type) {
    int i;
    while(!st_int.empty()) {
        from_stack(st_int, i);
        if(TID[i].get_declare()) {
            throw "twice";
        } else {
            if(type == LEX_RECORD){
                gl();
                if(c_type != LEX_LBRACKET) throw curr_lex;
                D1(TID[i].get_name()); 
                if(c_type != LEX_RBRACKET) throw curr_lex;
            }
            TID[i].put_declare();
            TID[i].put_type(type);
        }
    }
}


void Parser::check_declared() {
    if(TID[c_val].get_declare()) {
        st_lex.push(TID[c_val].get_type());
    } else {
        throw (string)"name " + TID[c_val].get_name() + " is not declared";
    }
}

void Parser::check_op() {
    type_of_lex type1, type2, op, t = LEX_INT, r = LEX_BOOL;
 
    from_stack(st_lex, type2);
    from_stack(st_lex, op);
    from_stack(st_lex, type1);
 
    if(op == LEX_PLUS || op == LEX_MINUS || op == LEX_TIMES || op == LEX_SLASH)
        r = LEX_INT;
    else if(op == LEX_OR || op == LEX_AND)
        t = LEX_BOOL;
    if(type1 == type2 && type1 == t) 
        st_lex.push(r);
    else {
        throw "wrong types are in operation";
    }
    poliz.push_back(Lex(op));
}

void Parser::check_not() {
    if(st_lex.top() != LEX_BOOL) {
        throw "wrong type is in not";
    } else {
        poliz.push_back( Lex(LEX_NOT) );
    }
}

void Parser::eq_type(){
    type_of_lex t;
    from_stack(st_lex, t);
    if(t != st_lex.top()) {
        throw "wrong types are in :=";
    }
    st_lex.pop();
}
 
void Parser::eq_bool() {
    if(st_lex.top() != LEX_BOOL) {
        throw "expression is not boolean";
    }
    st_lex.pop();
}

void Parser::check_declared_in_read() {
    if(!TID[c_val].get_declare()) {
        throw (string)"name " + TID[c_val].get_name() + " is not declared";
    }
}

char* Parser::name_before_dot(){
    const char* str = TID[c_val].get_name().c_str();
    const char* dot_pos = strchr(str, '.');

    if (dot_pos == nullptr) return nullptr;

    char* result = new char[dot_pos - str + 1];
    strncpy(result, str, dot_pos - str);
    result[dot_pos - str] = '\0';
    return result;
}

void Parser::check_has_dot(){
    char * test = name_before_dot();
    if (test != nullptr) {
        delete[] test;
        throw curr_lex;
    }
    delete [] test;
}