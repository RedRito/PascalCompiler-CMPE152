#include "FileReader.h"
#include <string>

FileReader::FileReader(string fileName)
{
    line = 1;
    file.open(fileName);
    if (file.fail())
    {
       std::cout << " COULD NOT OPEN THE FILE " << fileName << endl;
        exit(1);
    }
    currentCh = nextChar();
}

int FileReader::getLine()
{
    return line;
}

char FileReader::getCurrentChar()
{
    return currentCh;
}

char FileReader::nextChar()
{   
    file.get(currentCh);
    //End Of File Token
    if(file.eof())
    {
        currentCh = EOF;
    }
    //Go to next line
    else if (currentCh == '\n')
    {
        line++;
    }
    //Error Handling
    else if(file.fail())
    {
        std::cout << "Something went wrong with  " << fileName << endl;
    }
    return currentCh;
}
