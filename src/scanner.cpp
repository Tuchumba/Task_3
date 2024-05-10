#include "scanner.hpp"

using namespace std;

const char *
Scanner::TW [] = { "", "and", "begin", "bool", "do", "else", "end", "if", "false", "int", "not", "or", "program",
                      "read", "then", "true", "var", "while", "write", NULL };
 
const char *
Scanner::TD [] = { "@", ";", ",", ":", ":=", "(", ")", "=", "<", ">", "+", "-", "*", "/", "<=", "!=", ">=", NULL };


int Scanner::look(const string buf, const char** list) {
    int i = 0;
    while(list[i]) {
        if (buf == list[i])
            return i;
        ++i;
    }
    return 0;
}

void Scanner::gc() {
    c = fgetc(fp);
}

Scanner::Scanner(const char * program) {
    if (!(fp = fopen(program, "r"))) {
        throw "can't open file";
    }
}

Lex Scanner::get_lex() {
    enum state {H, IDENT, NUMB, COM, ALE, NEQ};
    int d, j;
    string buf;
    state CS = H;
    do {
        gc();
        switch(CS) {
            case H:
                if (c==' ' || c == '\n' || c== '\r' || c == '\t'); 
                else if (isalpha(c)) {
                    buf.push_back(c);
                    CS = IDENT;
                }
                else if (isdigit(c)) {
                    d = c - '0';
                    CS = NUMB;
                } 
                else if (c== '{') { 
                    CS = COM;
                }
                else if (c == ':' || c == '<' || c == '>') { 
                    buf.push_back(c);
                    CS = ALE; 
                }
                else if (c == '@')
                    return Lex(LEX_FIN);
                else if (c == '!') {
                    buf.push_back(c);
                    CS = NEQ;
                }
                else {
                    buf.push_back(c);
                    if ((j = look(buf, TD))){
                        return Lex((type_of_lex)(j + (int)LEX_FIN), j);
                    }
                    else {
                        throw c;
                    }  
                }
                break;
            case IDENT:
                if (isalpha(c) || isdigit(c)) {
                    buf.push_back(c);
                }
                else {
                    ungetc(c, fp);
                    if ((j = look(buf, TW))) {
                        return Lex((type_of_lex)j, j);
                        }
                    else {
                        j = put(buf);
                        return Lex(LEX_ID, j);
                    }
                }
                break;
            case NUMB:
                if (isdigit(c)) {
                    d = d * 10 + (c - '0');
                }
                else {
                    ungetc(c, fp);
                    return Lex(LEX_NUM, d);
                }
                break;
            case COM:
                if (c == '}') {
                    CS = H;
                }
                else if (c == '@' || c == '{') {
                    throw c;
                }
                break;
            case ALE:
                if (c == '=') {
                    buf.push_back(c);
                    j = look(buf,TD);
                    return Lex((type_of_lex)(j + (int)LEX_FIN), j);
                }
                else {
                    ungetc(c, fp);
                    j = look(buf, TD);
                    return Lex((type_of_lex)(j + (int)LEX_FIN), j);
                }
                break;
            case NEQ:
                if (c == '=') {
                    buf.push_back(c);
                    j = look(buf, TD);
                    return Lex(LEX_NEQ, j);
                }
                else {
                    throw '!';
                }
                break;
        }
    } while(true);
}