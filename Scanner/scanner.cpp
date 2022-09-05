#include "scanner.h"
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

}
