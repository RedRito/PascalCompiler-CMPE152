#include "FileReader.h"
#include <string>
using namespace std;

FileReader::FileReader(string fileName)
{
    line = 1;
    file.open(fileName);
    if (file.fail())
    {
        cout << " COULD NOT OPEN THE FILE " << fileName << endl;
        exit(1);
    }
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
    currentCh = file.get();
    if(file.eof())
    {
        currentCh = EOF;
    }
    else if (currentCh == '\n')
    {
        line++;
    }
    else if(file.fail())
    {
        cout << "Something went wrong with  " << fileName << endl;
    }
    return currentCh;
}