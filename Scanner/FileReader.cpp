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
    //End Of File token at the end of the file
    if(file.eof())
    {
        currentCh = EOF;
    }
    //move to the next line
    else if (currentCh == '\n')
    {
        line++;
    }
    //Error handling
    else if(file.fail())
    {
        cout << "Something went wrong with  " << fileName << endl;
    }
    return currentCh;
}
