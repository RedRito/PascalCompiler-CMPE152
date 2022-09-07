#include "../scanner.h"
#include "FileReader.h"
#include <string>
using namespace std;

Scanner::Scanner(FileReader *file)
{
    this -> file = file;
}

void Scanner::skipWhiteSpace()
{
    while(!file.eof())
    {
        if(isspace(currentCh))
        {
            currentCh = file -> nextChar();
        }
    }
}

Token *Scanner::nextToken()
{
    char ch = nextNonblankCharacter();

    if (isalpha(ch))      return Token::Word(ch, source);
    else if (isdigit(ch)) return Token::Number(ch, source);
    else if (ch == '\'')  return Token::CharacterOrString(ch, source);
    else                  return Token::SpecialSymbol(ch, source);
}
