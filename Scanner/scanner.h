#ifndef SCANNER_H
#define SCANNER_H
#include <iostream>
#include "..FileReader.h"
using namespace std;


enum class Token
{
    INVALID,
    EOF,

    AND,
    ARRAY,
    ASM,
    BEGIN,
    BREAK,
    CASE,
    CONST,
    //CONSTRUCTOR
    //CONTINUE
    //DESTRUCTOR
    //DIV
    DO,
    //DOWNTO
    ELSE,
    END,
    FALSE,
    //FILE
    FOR,
    FUNCTION,
    //GOTO
    IF,
    //IMPLEMENTATION
    //IN
    //INLINE
    //INTERFACE
    //LABEL
    //MOD
    //NIL
    NOT,
    //OBJECT
    OF,
    ON,
    OPERATOR,
    OR,
    //PACKED,
    //PROCEDURE,
    //PROGRAM,
    //RECORD,
    //REPEAT,
    //SET,
    //SHL,
    //SHR,
    STRING,
    THEN,
    TO,
    TRUE,
    //TYPE,
    UNIT,
    UNTIL,
    USES,
    VAR,
    WHILE,
    WITH,
    XOR,
    INTEGER,
    REAL,
    IDENTIFIER,
    PLUSOP,
    MINUSOP,
    MULTOP,
    DIVOP,
    ASSIGN,
    EQUAL,
    NE,
    LTEQ,
    GTEQ,
    LT,
    GT,
    PLUSEQUAL,
    MINUSEQUAL,
    MULTEQUAL,
    DIVEQUAL,
    CARAT,
    SEMICOLOR,
    COMMA,
    LPAREN,
    RPAREN,
    LBRACKET,
    RBRACKET,
    LBRACE,
    RBRACE,
    LCOMMENT,
    RCOMMENT,
};






class Scanner
{
    public:
    Token *nextToken();
    private:
    FileReader *file;
    char currentCh;
    Scanner(FileReader *file);
    void skipWhiteSpace();
};






#endif