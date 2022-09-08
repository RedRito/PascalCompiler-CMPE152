#include "scanner.h"
#include <string>
#include <iostream>
#include <fstream>

Scanner::Scanner(FileReader *file)
{
    this -> file = file;
}


Token *Scanner::nextToken()
{
    char ch = file -> getCurrentChar();
    //Increment ch
    while(isspace(ch))
    {
        ch = file -> nextChar();
    }
    //Ch is a reserved word
    if (isalpha(ch))
    {
        return Token::ReservedWord(ch, file);
    }      
    //Ch is a number
    else if (isdigit(ch)) 
    {
        return Token::Number(ch, file);
    }
    //Ch is a string
    else if (ch == '\'')
    {
        return Token::String(ch, file);
    }  
    //Ch is a symbol
    else                  
        return Token::SpecialSymbols(ch, file);
}

void Scanner::printTokens()
{
    Token *token = nextToken();
    stack <PToken> symbolStack;
    while(token -> datatype != PToken::END_OF_FILE && file -> getCurrentChar() != EOF)
    {
        if(token->datatype == PToken::INVALID)
        {
            cout << token -> Error(token, "token");
        }
        if(token -> datatype == PToken::LPAREN || token -> datatype == PToken::LBRACKET || token -> datatype == PToken::LBRACE)
        {
            symbolStack.push(token -> datatype);
        }
        else if(token -> datatype == PToken::RPAREN || token -> datatype == PToken::RBRACKET || token ->datatype == PToken::RBRACE)
        {
            if(symbolStack.empty())
            {
                token -> datatype = PToken::INVALID;
                cout << token -> Error(token, "token");
            }
            switch (token -> datatype)
            {
            case PToken::RPAREN:
            {
                if(symbolStack.top() != PToken::LPAREN)
                {
                    token -> datatype = PToken::INVALID;
                    cout << token -> Error(token, "token");
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
                    token -> datatype = PToken::INVALID;
                    cout << token -> Error(token, "token");
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
                        token -> datatype = PToken::INVALID;
                        cout << token -> Error(token, "token");
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
    if(token->datatype == PToken::INVALID)
    {
        cout << token -> Error(token, "token");
    }
    cout << token -> toString(token) << endl;
}

void Scanner::printToFile(string filename)
{
    ofstream printFile;
    printFile.open(filename);
    if (printFile.fail())
    {
        cout << " COULD NOT OPEN THE FILE " << filename << endl;
        exit(1);
    }
    Token *token = nextToken();
    stack <PToken> symbolStack;
    while(token -> datatype != PToken::END_OF_FILE && file -> getCurrentChar() != EOF)
    {
        if(token->datatype == PToken::INVALID)
        {
            printFile << token -> Error(token, "token");
        }
        if(token -> datatype == PToken::LPAREN || token -> datatype == PToken::LBRACKET || token -> datatype == PToken::LBRACE)
        {
            symbolStack.push(token -> datatype);
        }
        else if(token -> datatype == PToken::RPAREN || token -> datatype == PToken::RBRACKET || token ->datatype == PToken::RBRACE)
        {
            if(symbolStack.empty())
            {
                token -> datatype = PToken::INVALID;
                printFile << token -> Error(token, "token");
            }
            switch (token -> datatype)
            {
            case PToken::RPAREN:
            {
                if(symbolStack.top() != PToken::LPAREN)
                {
                    token -> datatype = PToken::INVALID;
                    printFile << token -> Error(token, "token");
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
                    token -> datatype = PToken::INVALID;
                    printFile << token -> Error(token, "token");
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
                        token -> datatype = PToken::INVALID;
                        printFile << token -> Error(token, "token");
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
        printFile << token -> toString(token) << endl;
        
        token = nextToken();
    }
    printFile.close();

}
