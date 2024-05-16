#ifndef TYPE_OF_LEX_HPP
#define TYPE_OF_LEX_HPP

enum type_of_lex {
    LEX_NULL,                                                                                               //0
    LEX_AND, LEX_BEGIN, LEX_BOOL, LEX_DO, LEX_ELSE, LEX_END, LEX_IF, LEX_FALSE, LEX_INT,                    //1-9
    LEX_NOT, LEX_OR, LEX_PROGRAM, LEX_READ, LEX_THEN, LEX_TRUE, LEX_VAR, LEX_WHILE, LEX_WRITE, LEX_RECORD,  //10-19
    LEX_FIN,                                                                                                //20
    LEX_SEMICOLON, LEX_COMMA, LEX_DOT, LEX_COLON, LEX_ASSIGN, LEX_LPAREN, LEX_RPAREN, LEX_EQ, LEX_LSS,               //21-29
    LEX_GTR, LEX_PLUS, LEX_MINUS, LEX_TIMES, LEX_SLASH, LEX_LEQ, LEX_NEQ, LEX_GEQ,                          //30-37
    LEX_NUM,                                                                                                //38
    LEX_ID,                                                                                                 //39
    POLIZ_LABEL,                                                                                            //40
    POLIZ_ADDRESS,                                                                                          //41
    POLIZ_GO,                                                                                               //42
    POLIZ_FGO                                                                                               //43
};


#endif