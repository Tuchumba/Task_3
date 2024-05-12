#ifndef SETTINGS_HPP
#define SETTINGS_HPP

enum type_of_lex {

    //in Scanner::TW
    LEX_NULL, LEX_AND, LEX_BEGIN, LEX_FALSE, LEX_DO, LEX_ELSE, LEX_END, LEX_IF, LEX_BOOL, LEX_INT, LEX_RECORD,
    LEX_NOT, LEX_OR, LEX_PROGRAM, LEX_READ, LEX_THEN, LEX_TRUE, LEX_VAR, LEX_WHILE, LEX_WRITE,
    //in Scanner::TD
    LEX_FIN, LEX_SEMICOLON, LEX_COMMA, LEX_COLON, LEX_ASSIGN, LEX_LPAREN, LEX_RPAREN, LEX_EQ, LEX_LSS,
    LEX_GTR, LEX_PLUS, LEX_MINUS, LEX_TIMES, LEX_SLASH, LEX_LEQ, LEX_NEQ, LEX_GEQ, LEX_LCURLY, LEX_RCURLY,

    LEX_NUM,
    LEX_ID, // for variables
    POLIZ_LABEL,
    POLIZ_ADDRESS,
    POLIZ_GO,
    POLIZ_FGO
};
/*  
Scanner::TW
    { "", "and", "begin", "false", "do", "else", "end", "if",
    "bool", "int", "record", "not", "or", "program",
    "read", "then", "true", "var", "while", "write", NULL };

Scanner::TD
    { "@", ";", ",", ":", ":=", "(", ")", "=", "<", ">", "+", "-",
    "*", "/", "<=", "!=", ">=", "{", "}", NULL };
*/

#endif