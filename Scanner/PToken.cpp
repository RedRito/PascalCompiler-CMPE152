#include <iostream>
#include <string>
#include "PToken.h"
using namespace std;
//map<string, PToken> Symbols;
//map<string, Token> ReservedWords;
//Initialize symbols map:
/*
void Token::initMaps()
{
    ReservedWords["AND"] = PToken::AND;
    ReservedWords["ARRAY"] = PToken::ARRAY;
    ReservedWords["ASM"] = PToken::ASM;
    ReservedWords["BEGIN"] = PToken::BEGIN;
    ReservedWords["BREAK"] = PToken::BREAK;
    ReservedWords["CASE"] = PToken::CASE;
    ReservedWords["CONST"] = PToken::CONST;
    ReservedWords["CONSTRUCTOR"] = PToken::CONSTRUCTOR;
    ReservedWords["CONTINUE"] = PToken::CONTINUE;
    ReservedWords["DESTRUCTOR"] = PToken::DESTRUCTOR;
    ReservedWords["DIV"] = PToken::DIV;
    ReservedWords["DO"] = PToken::DO;
    ReservedWords["DOWNTO"] = PToken::DOWNTO;
    ReservedWords["ELSE"] = PToken::ELSE;
    ReservedWords["END"] = PToken::END;
    ReservedWords["FALSE"] = PToken::FALSE;
    ReservedWords["FILE"] = PToken::FILE;
    ReservedWords["FOR"] = PToken::FOR;
    ReservedWords["FUNCTION"] = PToken::FUNCTION;
    ReservedWords["GOTO"] = PToken::GOTO;
    ReservedWords["IF"] = PToken::IF;
    ReservedWords["IMPLEMENTATION"] = PToken::IMPLEMENTATION;
    ReservedWords["IN"] = PToken::IN;
    ReservedWords["INLINE"] = PToken::INLINE;
    ReservedWords["INTERFACE"] = PToken::INTERFACE;
    ReservedWords["LABEL"] = PToken::LABEL;
    ReservedWords["MOD"] = PToken::MOD;
    ReservedWords["NIL"] = PToken::NIL;
    ReservedWords["NOT"] = PToken::NOT;
    ReservedWords["OBJECT"] = PToken::OBJECT;
    ReservedWords["OF"] = PToken::OF;
    ReservedWords["ON"] = PToken::ON;
    ReservedWords["OPERATOR"] = PToken::OPERATOR;
    ReservedWords["OR"] = PToken::OR;
    ReservedWords["PACKED"] = PToken::PACKED;
    ReservedWords["PROCEDURE"] = PToken::PROCEDURE;
    ReservedWords["PROGRAM"] = PToken::PROGRAM;
    ReservedWords["RECORD"] = PToken::RECORD;
    ReservedWords["REPEAT"] = PToken::REPEAT;
    ReservedWords["SET"] = PToken::SET;
    ReservedWords["SHL"] = PToken::SHL;
    ReservedWords["SHR"] = PToken::SHR;
    ReservedWords["STRING"] = PToken::STRING;
    ReservedWords["THEN"] = PToken::THEN;
    ReservedWords["TO"] = PToken::TO;
    ReservedWords["TRUE"] = PToken::TRUE;
    ReservedWords["TYPE"] = PToken::TYPE;
    ReservedWords["UNIT"] = PToken::UNIT;
    ReservedWords["UNTIL"] = PToken::UNTIL;
    ReservedWords["USES"] = PToken::USES;
    ReservedWords["VAR"] = PToken::VAR;
    ReservedWords["WHILE"] = PToken::WHILE;
    ReservedWords["WITH"] = PToken::WITH;
    ReservedWords["XOR"] = PToken::XOR;

    Symbols["PLUSOP"] = PToken::PLUSOP;
    Symbols["MINUSOP"] = PToken::MINUSOP;
    Symbols["MULTOP"] = PToken::MULTOP;
    Symbols["DIVOP"] = PToken::DIVOP;
    Symbols["ASSIGN"] = PToken::ASSIGN;
    Symbols["EQUAL"] = PToken::EQUAL;
    Symbols["NE"] = PToken::NE;
    Symbols["LTEQ"] = PToken::LTEQ;
    Symbols["GTEQ"] = PToken::GTEQ;
    Symbols["LT"] = PToken::LT;
    Symbols["GT"] = PToken::GT;
    Symbols["PLUSEQUAL"] = PToken::PLUSEQUAL;
    Symbols["MINUSEQUAL"] = PToken::MINUSEQUAL;
    Symbols["MULTEQUAL"] = PToken::MULTEQUAL;
    Symbols["DIVEQUAL"] = PToken::DIVEQUAL;
    Symbols["CARAT"] = PToken::CARAT;
    Symbols["SEMICOLOR"] = PToken::SEMICOLOR;
    Symbols["COMMA"] = PToken::COMMA;
    Symbols["LPAREN"] = PToken::LPAREN;
    Symbols["RPAREN"] = PToken::RPAREN;
    Symbols["LBRACKET"] = PToken::LBRACKET;
    Symbols["RBRACKET"] = PToken::RBRACKET;
    Symbols["LBRACE"] = PToken::LBRACE;
    Symbols["RBRACE"] = PToken::RBRACE;
    Symbols["LCOMMENT"] = PToken::LCOMMENT;
    Symbols["RCOMMENT"] = PToken::RCOMMENT;
    
}
*/
/*
Token *Token::Word(char firstChar, FileReader *file)
{
    Token *token = new Token(firstChar);
    token->lineNumber = file->lineNumber();

    // Loop to get the rest of the characters of the word token.
    // Append letters and digits to the token.
    for (char ch = file->nextChar(); isalnum(ch); ch = file->nextChar())
    {
        token->text += ch;
    }

    // Is it a reserved word or an identifier?
    string upper = toUpperCase(token->text);
    if (Token::reservedWords.find(upper) != Token::reservedWords.end())
    {
        token->type = Token::reservedWords[upper];
    }
    else
    {
        token->type = TokenType::IDENTIFIER;
    }

    return token;
}

Token *Token::Number(char firstChar, FileReader *file)
{
    Token *token = new Token(firstChar);
    token->lineNumber = file->lineNumber();
    int pointCount = 0;

    // Loop to get the rest of the characters of the number token.
    // Append digits to the token.
    for (char ch = file->nextChar();
         isdigit(ch) || (ch == '.');
         ch = file->nextChar())
    {
        if (ch == '.') pointCount++;
        token->text += ch;
    }

    // Integer constant.
    if (pointCount == 0)
    {
        token->type    = TokenType::INTEGER;
        token->value.L = stol(token->text);
        token->value.D = token->value.L;  // allow using integer value as double
    }

    // Real constant.
    else if (pointCount == 1)
    {
        token->type    = TokenType::REAL;
        token->value.D = stod(token->text);
    }

    else
    {
        token->type = TokenType::ERROR;
        tokenError(token, "Invalid number");
    }

    return token;
}

Token *Token::CharacterOrString(char firstChar, FileReader *file)
{
    Token *token = new Token(firstChar);  // the leading '
    token->lineNumber = file->lineNumber();
    int length = 0;                       // string length

    // Loop to append the rest of the characters of the string,
    // up to but not including the closing quote.
    bool done = false;
    char ch = file->nextChar();
    do
    {
        // Append characters to the string until ' or EOF.
        while ((ch != '\'') && (ch != EOF))
        {
            token->text += ch;
            length++;
            ch = file->nextChar();  // consume the character
        }

        // End of file. An unclosed string.
        if (ch == EOF)
        {
            tokenError(token, "String not closed");
            done = true;
        }

        // Got a ' so it can be the closing ', or a ''
        else
        {
            ch = file->nextChar();  // consume the '

            // That was the closing '. Close the string.
            if (ch != '\'')
            {
                token->text += '\'';
                done = true;
            }

            // It's '' so append ' to the string.
            else
            {
                token->text += '\'';
                length++;
                ch = file->nextChar();  // consume second '
            }
        }
    } while (!done);

    // It's a character token if the string length is 1.
    // Otherwise, it's a string token.
    token->type = length == 1 ? TokenType::CHARACTER : TokenType::STRING;

    // Don't include the leading and trailing '.
    token->value.S = token->text.substr(1, token->text.length() - 2);

    return token;
}


Token *Token::SpecialSymbols(char currentCh, FileReader * file)
{
    Token *token = new Token(currentCh);
    if(Symbols.find(currentCh) != Symbols.end())
    {
        token->datatype = Token::Symbols[currentCh];
    }
    if()
    for(char currentCh = file -> getNextChar(); Symbols.find(currentCh) != Symbols.end(); currentCh = file -> getNextChar())
    {
        token -> datatext += currentCh;
    }
    switch(currentCh)
    {
        case '.' : token->type = TokenType::PERIOD;     break;
        case ';' : token->type = TokenType::SEMICOLON;  break;
        case '+' : token->type = TokenType::PLUS;       break;
        case '-' : token->type = TokenType::MINUS;      break;
        case '*' : token->type = TokenType::STAR;       break;
        case '/' : token->type = TokenType::SLASH;      break;
        case '=' : token->type = TokenType::EQUALS;     break;
        case '<' : token->type = TokenType::LESS_THAN;  break;
        case '(' : token->type = TokenType::LPAREN;     break;
        case ')' : token->type = TokenType::RPAREN;     break;


        case ':' :
        {
            char nextChar = file->nextChar();
            token->text += nextChar;

            // Is it the := symbol?
            if (nextChar == '=')
            {
                token->type = TokenType::COLON_EQUALS;
            }

            // No, it's just the : symbol.
            else
            {
                token->type = TokenType::COLON;
                return token;  // already consumed :
            }

            break;
        }

        case EOF : token->type = END_OF_FILE; break;

        default: token->type = TokenType::ERROR;
    }
}
*/
Token *Token::ReservedWord(char currentCh, FileReader * file)
{

}
Token *Token::Number(char currentCh, FileReader * file)
{
    
}
Token *Token::String(char currentCh, FileReader * file)
{
    
}

Token::Token(char currentChar)
{
    linenum = 0;
    datatype = PToken::INVALID;
    datatext = "";
    tokenValueInt = 0;
    tokenValueReal = 0.0;
    tokenValueString = "";
    tokenValueBoolean = false;
    datatext += currentChar;
}
Token *Token::SpecialSymbols(char currentCh, FileReader * file)
{
    
    Token *token = new Token(currentCh);
    token -> datatext += currentCh;
    if (currentCh == ':')
    {
        char ch = file -> nextChar();
        token -> datatext += ch;
        if(ch == '=')
        {
            token->datatype = Symbols.at(token->datatext); //datatype = ASSIGN
        }
    }
    else if(Symbols.find(token -> datatext) != Symbols.end())
    {
        token->datatype = Symbols.at(token->datatext);
    }
    else if (currentCh == EOF)
    {
        token->datatype = Symbols.at("EOF");
    }
    else
    {
        token->datatype = Symbols.at("INVALID");
    }



    switch (token -> datatype)
    {
        case PToken::PLUSOP :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '=')
            {
                token->datatype = Symbols.at(token->datatext); //datatype = PLUSEQUAL
                if(token->datatype == PToken::PLUSEQUAL)
                {
                    cout << "works fine" << endl;
                }
            }
            break;
        }
            
        case PToken::MINUSOP :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '=')
            {
                token->datatype = Symbols.at(token->datatext); //datatype = MINUSEQUAL
            }
            break;
        }
            
        case PToken::MULTOP :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '=')
            {
                token->datatype = Symbols.at(token->datatext); //datatype = MULTEQUAL
            }
            else if(ch == ')')
            {
                token->datatype = Symbols.at(token->datatext); //datatype = RCOMMENT
            }
            break;
        }
            break;
        case PToken::DIVOP :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '=')
            {
                token->datatype = Symbols.at(token->datatext); //datatype = DIVEQUAL
            }
            break;
        }
        case PToken::LT :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '=')
            {
                token->datatype = Symbols.at(token->datatext); //datatype = LTEQ
            }
            else if(ch == '>')
            {
                token->datatype = Symbols.at(token->datatext); //datatype = NE
            }
            break;
        }
        case PToken::GT :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '=')
            {
                token->datatype = Symbols.at(token->datatext); //datatype = GTEQ
            }
            break;
        }
        case PToken::LBRACE :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '*')
            {
                token->datatype = Symbols.at(token->datatext); //datatype = LCOMMENT
            }
            break;
        }
        default:
            break;
    }
    return token;
    
}


string Token::toString(Token *token)
{
    return PTOKEN_STR[(int) token -> datatype] + " : " + token -> datatext;
}

void Token::Error(Token *token, string msg)
{
    cout << "TOKEN ERROR at " << token -> linenum << ": " << "Invalid " << PTOKEN_STR[(int) token -> datatype] << "at " << token->datatext << endl;
    return;
}

