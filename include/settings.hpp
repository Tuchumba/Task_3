#ifndef SETTINGS_HPP
#define SETTINGS_HPP

enum type_of_lex {
    LEX_NULL,                                                                                   //0
    LEX_AND, LEX_BEGIN, LEX_BOOL, LEX_DO, LEX_ELSE, LEX_END, LEX_IF, LEX_FALSE, LEX_INT,        //1-9
    LEX_NOT, LEX_OR, LEX_PROGRAM, LEX_READ, LEX_THEN, LEX_TRUE, LEX_VAR, LEX_WHILE, LEX_WRITE,  //10-18
    LEX_FIN,                                                                                    //19
    LEX_SEMICOLON, LEX_COMMA, LEX_COLON, LEX_ASSIGN, LEX_LPAREN, LEX_RPAREN, LEX_EQ, LEX_LSS,   //20-27
    LEX_GTR, LEX_PLUS, LEX_MINUS, LEX_TIMES, LEX_SLASH, LEX_LEQ, LEX_NEQ, LEX_GEQ,              //28-35
    LEX_NUM,                                                                                    //36
    LEX_ID,                                                                                     //37
    POLIZ_LABEL,                                                                                //38
    POLIZ_ADDRESS,                                                                              //39
    POLIZ_GO,                                                                                   //40
    POLIZ_FGO                                                                                   //41
};


#endif