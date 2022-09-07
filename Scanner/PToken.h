#ifndef PTOKEN_H_
#define PTOKEN_H_

#include <iostream>
#include <string>
#include <map>
//#include "FileReader.h"
using namespace std;

enum class PToken
{
    INVALID,
    EOF,
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

constexpr PToken INVALID    = PToken::INVALID;
//constexpr PToken EOF        = PToken::EOF;
constexpr PToken AND        = PToken::AND;
constexpr PToken ARRAY      = PToken::ARRAY;
constexpr PToken ASM        = PToken::ASM;
constexpr PToken BEGIN      = PToken::BEGIN;
constexpr PToken CASE      = PToken::CASE;
constexpr PToken CONST      = PToken::CONST;
constexpr PToken CONSTRUCTOR      = PToken::CONSTRUCTOR;
constexpr PToken CONTINUE      = PToken::CONTINUE;
constexpr PToken DESTRUCTOR      = PToken::DESTRUCTOR;
constexpr PToken DIV      = PToken::DIV;
constexpr PToken DO      = PToken::DO;
constexpr PToken DOWNTO      = PToken::DOWNTO;
constexpr PToken ELSE      = PToken::ELSE;
constexpr PToken END      = PToken::END;
constexpr PToken FALSE      = PToken::FALSE;
constexpr PToken FILE      = PToken::FILE;
constexpr PToken FOR      = PToken::FOR;
constexpr PToken FUNCTION      = PToken::FUNCTION;
constexpr PToken GOTO      = PToken::GOTO;
constexpr PToken IF      = PToken::IF;
constexpr PToken IMPLEMENTATION      = PToken::IMPLEMENTATION;
constexpr PToken IN      = PToken::IN;
constexpr PToken INLINE      = PToken::INLINE;
constexpr PToken INTERFACE      = PToken::INTERFACE;
constexpr PToken LABEL      = PToken::LABEL;
constexpr PToken MOD      = PToken::MOD;
constexpr PToken NIL      = PToken::NIL;
constexpr PToken OBJECT      = PToken::NOT;
constexpr PToken OF      = PToken::OF;
constexpr PToken ON      = PToken::ON;
constexpr PToken OPERATOR      = PToken::OPERATOR;
constexpr PToken OR      = PToken::OR;
constexpr PToken PACKED      = PToken::PACKED;
constexpr PToken PROCEDURE      = PToken::PROCEDURE;
constexpr PToken PROGRAM      = PToken::PROGRAM;
constexpr PToken RECORD      = PToken::RECORD;
constexpr PToken REPEAT      = PToken::REPEAT;
constexpr PToken SET      = PToken::SET;
constexpr PToken SHL      = PToken::SHL;
constexpr PToken SHR      = PToken::SHR;
constexpr PToken STRING      = PToken::STRING;
constexpr PToken THEN      = PToken::THEN;
constexpr PToken TO      = PToken::TO;
constexpr PToken TRUE      = PToken::TRUE;
constexpr PToken TYPE      = PToken::TYPE;
constexpr PToken UNIT      = PToken::UNIT;
constexpr PToken UNTIL      = PToken::UNTIL;
constexpr PToken USES      = PToken::USES;
constexpr PToken VAR      = PToken::VAR;
constexpr PToken WHILE      = PToken::WHILE;
constexpr PToken WITH      = PToken::WITH;
constexpr PToken XOR      = PToken::XOR;
constexpr PToken INTEGER      = PToken::INTEGER;
constexpr PToken REAL      = PToken::REAL;
constexpr PToken IDENTIFIER      = PToken::IDENTIFIER;
constexpr PToken PLUSOP      = PToken::PLUSOP;
constexpr PToken MINUSOP      = PToken::MINUSOP;
constexpr PToken MULTOP      = PToken::MULTOP;
constexpr PToken DIVOP      = PToken::DIVOP;
constexpr PToken ASSIGN      = PToken::ASSIGN;
constexpr PToken EQUAL      = PToken::EQUAL;
constexpr PToken NE      = PToken::NE;
constexpr PToken LTEQ      = PToken::LTEQ;
constexpr PToken GTEQ      = PToken::GTEQ;
constexpr PToken LT      = PToken::LT;
constexpr PToken GT      = PToken::GT;
constexpr PToken PLUSEQUAL      = PToken::PLUSEQUAL;
constexpr PToken MINUSEQUAL      = PToken::MINUSEQUAL;
constexpr PToken MULTEQUAL      = PToken::MULTEQUAL;
constexpr PToken DIVEQUAL      = PToken::DIVEQUAL;
constexpr PToken CARAT      = PToken::CARAT;
constexpr PToken SEMICOLOR      = PToken::SEMICOLOR;
constexpr PToken COMMA      = PToken::COMMA;
constexpr PToken LPAREN      = PToken::LPAREN;
constexpr PToken RPAREN      = PToken::RPAREN;
constexpr PToken LBRACKET      = PToken::LBRACKET;
constexpr PToken RBRACKET      = PToken::RBRACKET;
constexpr PToken LBRACE      = PToken::LBRACE;
constexpr PToken RBRACE      = PToken::RBRACE;
constexpr PToken LCOMMENT      = PToken::LCOMMENT;
constexpr PToken RCOMMENT      = PToken::RCOMMENT;

class TokenMap
{
    private:
        static map<string, PToken> ReservedWords;
    public:
        static void initMap();
        PToken datatype;    //what's the token's datatype
        string datatext;    //the token's text
        int linenum;        //the current line number
};

#endif