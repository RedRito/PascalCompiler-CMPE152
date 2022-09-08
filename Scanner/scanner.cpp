#include "scanner.h"
#include <string>
using namespace std;

Scanner::Scanner(FileReader *file)
{
    this -> file = file;
}


Token *Scanner::nextToken()
{
    char ch = file -> nextChar();
    cout << ch << endl;
    while(isspace(ch))
    {
        ch = file -> nextChar();
    }
    if (isalpha(ch))      
        return Token::ReservedWord(ch, file);
    else if (isdigit(ch)) 
        return Token::Number(ch, file);
    else if (ch == '\'')  
        return Token::String(ch, file);
    else                  
        return Token::SpecialSymbols(ch, file);
}

void Scanner::printTokens()
{
    Token *token = nextToken();
    token = nextToken();
    //cout << Token::toString(token) << endl;
    /*
    stack <PToken> symbolStack;
    while(token -> datatype != PToken::END_OF_FILE)
    {
        if(token -> datatype == PToken::LPAREN || token -> datatype == PToken::LBRACKET || token -> datatype == PToken::LBRACE)
        {
            symbolStack.push(token -> datatype);
        }
        else if(token -> datatype == PToken::RPAREN || token -> datatype == PToken::RBRACKET || token ->datatype == PToken::RBRACE)
        {
            switch (token -> datatype)
            {
            case PToken::RPAREN:
            {
                if(symbolStack.top() != PToken::LPAREN)
                {
                    token -> datatype == PToken::INVALID;
                    Token::Error(token, "bye");
                }
                else
                {
                    symbolStack.pop();
                }
                break;
            }
            case PToken::RBRACKET:
            {
                if(symbolStack.top() != PToken::LBRACKET)
                {
                    token -> datatype == PToken::INVALID;
                    Token::Error(token, "bye");
                }
                else
                {
                    symbolStack.pop();
                }
                break;
            }
            case PToken::RBRACE:
            {
                if(symbolStack.top() != PToken::LBRACE)
                    {
                        token -> datatype == PToken::INVALID;
                        Token::Error(token, "bye");
                    }
                else
                {
                    symbolStack.pop();
                }
                break;
            }
            default:
                break;
            }
        }
        cout << token -> toString(token) << endl;
        
        token = nextToken();
    }
    */
}
