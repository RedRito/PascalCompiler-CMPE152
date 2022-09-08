#include <iostream>
#include <string>
#include "PToken.h"
#include <algorithm>
using namespace std;

// Return strings with all uppercase letters
string Token::strToUpper(string str)
{
    string upper_case(str);
    transform(upper_case.begin(), upper_case.end(),
              upper_case.begin(), ::toupper);
    return upper_case;
}


Token *Token::ReservedWord(char currentCh, FileReader * file)
{
    Token *token = new Token(currentCh);
    token->linenum = file->getLine();

    if(isdigit(token -> datatext[0]))
    {
        token->datatype = PToken::INVALID;
        Error(token, "Identifier");
    }
    
    // Loop to get the remaining characters of the word
    for (char ch = file->nextChar(); isalnum(ch); ch = file->nextChar()) //ISSUE, CONSUMES THE LAST Character after the reserved word / identifier
    { 
        token->datatext += ch;
    }

    string upper = strToUpper(token->datatext);
    
    // Check if it is reserved words or identifiers
    if (ReservedWords.find(upper) != ReservedWords.end())
    {
        token->datatype = ReservedWords[upper];
    }
    else
    {
        token->datatype = PToken::IDENTIFIER;
    }

    return token;
}

Token *Token::Number(char currentCh, FileReader * file)
{
    Token *token = new Token(currentCh);
    token->linenum = file->getLine();
    int pointCount = 0;

    //Loop to get the remaining characters of number
    for (char ch = file->nextChar();
         isdigit(ch) || (ch == '.');
         ch = file->nextChar())
    {
        if (ch == '.') pointCount++;
        token->datatext += ch;
    }
 
    if (pointCount == 0)
    {
        token->datatype    = PToken::INTEGER;
        token->tokenValueInt = stol(token->datatext);
        token->tokenValueReal = token->tokenValueInt; 
    }
  
    else if (pointCount == 1)
    {
        token->datatype    = PToken::REAL;
        token->tokenValueReal = stod(token->datatext);
    }

    else
    {
        token->datatype = PToken::INVALID;
    }

    return token;
}
Token *Token::String(char currentCh, FileReader * file)
{
    Token *token = new Token(currentCh);  
    token->linenum = file->getLine();
    int length = 0;                       

    bool done = false;
    char ch = file->nextChar();
    do
    {
        // Append characters to the string until ' or EOF.
        while ((ch != '\'') && (ch != EOF))
        {
            token->datatext += ch;
            length++;
            ch = file->nextChar();  // consume the character
        }

        // End of file. An unclosed string.
        if (ch == EOF)
        {
            Error(token, "String not closed");
            done = true;
        }

        // Got a ' so it can be the closing ', or a ''
        else
        {
            ch = file->nextChar();  // consume the '

            // That was the closing '. Close the string.
            if (ch != '\'')
            {
                token->datatext += '\'';
                done = true;
            }

            // It's '' so append ' to the string.
            else
            {
                token->datatext += '\'';
                length++;
                ch = file->nextChar();  // consume second '
            }
        }
    } while (!done);
    token->datatype = (token->datatext.length() == 3) ? ReservedWords["CHARACTER"] : ReservedWords["STRING"];
    // Don't include the leading and trailing '.
    token->tokenValueString = token->datatext.substr(1, token->datatext.length() - 2);

    return token;
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
    token ->linenum = file ->getLine();
    //cout << "CURRENT CHAR IN SPECIAL SYMBOLS" << endl;
    //cout << currentCh;
    switch (currentCh)
    {
        case '+' : 
        {
            token->datatype = Symbols["PLUSOP"];
            break;
        }
        case '-' : 
        {
            token->datatype = Symbols["MINUSOP"];
            break;
        }
        case '*' : 
        {
            token->datatype = Symbols["MULTOP"];       
            break;
        }
        case '/' : 
        {
            token->datatype = Symbols["DIVOP"];      
            break;
        }
        case '=' : 
        {
            token->datatype = Symbols["EQUAL"];     
            break;
        }
        case '<' : 
        {
            token->datatype = Symbols["LT"];        
            break;
        }
        case '>' : 
        {
            token->datatype = Symbols["GT"];    
            break;
        }
        case '^' :
        {
            token->datatype = Symbols["CARAT"];
            break;
        }
        case ';' : 
        {
            token->datatype = Symbols["SEMICOLOR"];  
            break;
        }
        case ',' : 
        {
            token->datatype = Symbols["COMMA"];  
            break;
        }
        case '(' : 
        {
            token->datatype = Symbols["LPAREN"];     
            break;
        }
        case ')' : 
        {
            token->datatype = Symbols["RPAREN"];     
            break;
        }
        case '[' : 
        {
            token->datatype = Symbols["LBRACKET"];     
            break;
        }
        case ']' : 
        {
            token->datatype = Symbols["RBRACKET"];     
            break;
        }
        case '{' : 
        {
            token->datatype = Symbols["LBRACE"];     
            break;
        }
        case '}' : 
        {
            token->datatype = Symbols["RBRACE"];     
            break;
        }
        case ':' :
        {
            token->datatype = Symbols["COLON"];
            break;
        }
        case '.' :
        {
            token->datatype = Symbols["PERIOD"];
            break;
        }
        case EOF :
        {
            token->datatype = Symbols["EOF"];
            break;
        }
    default:
        break;
    }

    switch (token -> datatype)
    {
        case PToken::PLUSOP :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '=')
            {
                token->datatype = Symbols["PLUSEQUAL"]; //datatype = PLUSEQUAL
            }
            break;
        }
            
        case PToken::MINUSOP :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '=')
            {
                token->datatype = Symbols["MINUSEQUAL"]; //datatype = MINUSEQUAL
            }
            break;
        }
            
        case PToken::MULTOP :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '=')
            {
                token->datatype = Symbols["MULTEQUAL"]; //datatype = MULTEQUAL
            }
            else if(ch == ')')
            {
                token->datatype = Symbols["RCOMMENT"]; //datatype = RCOMMENT
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
                token->datatype = Symbols["DIVEQUAL"]; //datatype = DIVEQUAL
            }
            break;
        }
        case PToken::LT :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '=')
            {
                token->datatype = Symbols["LTEQ"]; //datatype = LTEQ
            }
            else if(ch == '>')
            {
                token->datatype = Symbols["NE"]; //datatype = NE
            }
            break;
        }
        case PToken::GT :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '=')
            {
                token->datatype = Symbols["GTEQ"]; //datatype = GTEQ
            }
            break;
        }
        case PToken::LPAREN :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '*')
            {
                token->datatype = Symbols["LCOMMENT"]; //datatype = LCOMMENT
            }
            break;
        }
        case PToken::COLON :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '=')
            {
                token->datatype = Symbols["ASSIGN"]; //datatype = ASSIGN
            }
            break;
        }
        case PToken::PERIOD :
        {
            char ch = file -> nextChar();
            token -> datatext += ch;
            if(ch == '.')
            {
                token->datatype = Symbols["DOT_DOT"]; //datatype = DOT_DOT
            }
            break;
        }
        default:
            break;
    }
    if(Symbols.find(PTOKEN_STR[(int) token -> datatype]) == Symbols.end())
    {
        token->datatype = Symbols["INVALID"];
    }
    return token;
    
}


string Token::toString(Token *token)
{
    return PTOKEN_STR[(int) token -> datatype] + " : " + token -> datatext;
}

string Token::Error(Token *token, string msg)
{
    return "TOKEN ERROR at " + to_string(token -> linenum) + ": " + "Invalid " + msg + " at " + token->datatext + '\n';
}

