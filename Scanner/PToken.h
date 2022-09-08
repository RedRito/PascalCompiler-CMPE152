#ifndef PTOKEN_H_
#define PTOKEN_H_

#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <map>
#include "FileReader.h"
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
static map<string, PToken> ReservedWords = 
        {
            //{"a", 1},
            {"AND", PToken::AND},
            {"ARRAY", PToken::ARRAY},
            {"ASM", PToken::ASM},
            {"BEGIN", PToken::BEGIN},
            {"BREAK", PToken::BREAK},
            {"CASE", PToken::CASE},
            {"CONST", PToken::CONST},
            {"CONSTRUCTOR", PToken::CONSTRUCTOR},
            {"CONTINUE", PToken::CONTINUE},
            {"DESTRUCTOR", PToken::DESTRUCTOR},
            {"DIV", PToken::DIV},
            {"DO", PToken::DO},
            {"DOWNTO", PToken::DOWNTO},
            {"ELSE", PToken::ELSE},
            {"END", PToken::END},
            {"FALSE", PToken::FALSE},
            {"FILE", PToken::FILE},
            {"FOR", PToken::FOR},
            {"FUNCTION", PToken::FUNCTION},
            {"GOTO", PToken::GOTO},
            {"IF", PToken::IF},
            {"IMPLEMENTATION", PToken::IMPLEMENTATION},
            {"IN", PToken::IN},
            {"INLINE", PToken::INLINE},
            {"INTERFACE", PToken::INTERFACE},
            {"LABEL", PToken::LABEL},
            {"MOD", PToken::MOD},
            {"NIL", PToken::NIL},
            {"NOT", PToken::NOT},
            {"OBJECT", PToken::OBJECT},
            {"OF", PToken::OF},
            {"ON", PToken::ON},
            {"OPERATOR", PToken::OPERATOR},
            {"OR", PToken::OR},
            {"PACKED", PToken::PACKED},
            {"PROCEDURE", PToken::PROCEDURE},
            {"PROGRAM", PToken::PROGRAM},
            {"RECORD", PToken::RECORD},
            {"REPEAT", PToken::REPEAT},
            {"SET", PToken::SET},
            {"SHL", PToken::SHL},
            {"SHR", PToken::SHR},
            {"STRING", PToken::STRING},
            {"THEN", PToken::THEN},
            {"TO", PToken::TO},
            {"TRUE", PToken::TRUE},
            {"TYPE", PToken::TYPE},
            {"UNIT", PToken::UNIT},
            {"UNTIL", PToken::UNTIL},
            {"USES", PToken::USES},
            {"VAR", PToken::VAR},
            {"WHILE", PToken::WHILE},
            {"WITH", PToken::WITH},
            {"XOR", PToken::XOR},
        };
static map<string, PToken> Symbols =
        {
            {"PLUSOP", PToken::PLUSOP},
            {"MINUSOP", PToken::MINUSOP},
            {"MULTOP", PToken::MULTOP},
            {"DIVOP", PToken::DIVOP},
            {"ASSIGN", PToken::ASSIGN},
            {"EQUAL", PToken::EQUAL},
            {"NE", PToken::NE},
            {"LTEQ", PToken::LTEQ},
            {"GTEQ", PToken::GTEQ},
            {"LT", PToken::LT},
            {"GT", PToken::GT},
            {"PLUSEQUAL", PToken::PLUSEQUAL},
            {"MINUSEQUAL", PToken::MINUSEQUAL},
            {"MULTEQUAL", PToken::MULTEQUAL},
            {"DIVEQUAL", PToken::DIVEQUAL},
            {"CARAT", PToken::CARAT},
            {"SEMICOLOR", PToken::SEMICOLOR},
            {"COMMA", PToken::COMMA},
            {"LPAREN", PToken::LPAREN},
            {"RPAREN", PToken::RPAREN},
            {"LBRACKET", PToken::LBRACKET},
            {"RBRACKET", PToken::RBRACKET},
            {"LBRACE", PToken::LBRACE},
            {"RBRACE", PToken::RBRACE},
            {"LCOMMENT", PToken::LCOMMENT},
            {"RCOMMENT", PToken::RCOMMENT},
        };

class Token
{
    private:
        
    public:
        static void initMaps();
    /*
        static map<string, PToken> ReservedWords;
        static map<string, PToken> Symbols;
    */
            
        
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
        static void Error(Token *token, string msg);
        static string toString(Token *token);
        static string strToUpper (string str);


};

#endif
