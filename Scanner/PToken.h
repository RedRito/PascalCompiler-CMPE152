#ifndef PTOKEN_H_
#define PTOKEN_H_

#include <iostream>
#include <string>
#include <map>
#include "FileReader.cpp"
using namespace std;

enum class PToken
{
    INVALID,
    END_OF_FILE,
    //Reserved
    AND,
    ARRAY,
    ASM,
    BEGIN,
    BREAK,
    CASE,
    CONST,
    CONSTRUCTOR,
    CONTINUE,
    DESTRUCTOR,
    DIV,
    DO,
    DOWNTO,
    ELSE,
    END,
    FALSE,
    FILE,
    FOR,
    FUNCTION,
    GOTO,
    IF,
    IMPLEMENTATION,
    IN,
    INLINE,
    INTERFACE,
    LABEL,
    MOD,
    NIL,
    NOT,
    OBJECT,
    OF, 
    ON, 
    OPERATOR, 
    OR, 
    PACKED, 
    PROCEDURE, 
    PROGRAM, 
    RECORD, 
    REPEAT, 
    SET, 
    SHL, 
    SHR, 
    STRING, 
    THEN, 
    TO, 
    TRUE, 
    TYPE, 
    UNIT, 
    UNTIL, 
    USES, 
    VAR, 
    WHILE, 
    WITH, 
    XOR, 
    //Values
    INTEGER,
    REAL,
    //Identifier
    IDENTIFIER,
    //Symbols
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

static const string PTOKEN_STR[] =
{
    "INVALID",
    "EOF",
    "AND",
    "ARRAY",
    "ASM",
    "BEGIN",
    "BREAK",
    "CASE",
    "CONST",
    "CONSTRUCTOR",
    "CONTINUE",
    "DESTRUCTOR",
    "DIV",
    "DO",
    "DOWNTO",
    "ELSE",
    "END",
    "FALSE",
    "FILE",
    "FOR",
    "FUNCTION",
    "GOTO",
    "IF",
    "IMPLEMENTATION",
    "IN",
    "INLINE",
    "INTERFACE",
    "LABEL",
    "MOD",
    "NIL",
    "NOT",
    "OBJECT",
    "OF",
    "ON",
    "OPERATOR",
    "OR",
    "PACKED",
    "PROCEDURE",
    "PROGRAM",
    "RECORD",
    "REPEAT",
    "SET",
    "SHL",
    "SHR",
    "STRING",
    "THEN",
    "TO",
    "TRUE",
    "TYPE",
    "UNIT",
    "UNTIL",
    "USES",
    "VAR",
    "WHILE",
    "WITH",
    "XOR",
    "INTEGER",
    "REAL",
    "IDENTIFIER",
    "PLUSOP",
    "MINUSOP",
    "MULTOP",
    "DIVOP",
    "ASSIGN",
    "EQUAL",
    "NE",
    "LTEQ",
    "GTEQ",
    "LT",
    "GT",
    "PLUSEQUAL",
    "MINUSEQUAL",
    "MULTEQUAL",
    "DIVEQUAL",
    "CARAT",
    "SEMICOLOR",
    "COMMA",
    "LPAREN",
    "RPAREN",
    "LBRACKET",
    "RBRACKET",
    "LBRACE",
    "RBRACE",
    "LCOMMENT",
    "RCOMMENT"
};


class Token
{
    private:
        static map<string, PToken> ReservedWords;
        static map<string, PToken> Symbols;
        
    public:
        static void initMaps();
        
        PToken datatype;    //what's the token's datatype
        string datatext;    //the token's text
        int linenum;        //the current line number
        /*
            The value of the token if it exists.
        */
        int tokenValueInt;
        double tokenValueReal;
        string tokenValueString;
        bool tokenValueBoolean;

        Token(char currentCh); //constructor
        //part of the class thus should be static
        static Token *ReservedWord(char currentCh, FileReader * file);
        static Token *Number(char currentCh, FileReader * file);
        static Token *String(char currentCh, FileReader * file);
        static Token *SpecialSymbols(char currentCh, FileReader * file);
        static void   Error(Token *token, string msg);
        static string toString(Token *token);


};

#endif
