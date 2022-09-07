#ifndef SCANNER_H
#define SCANNER_H
#include <iostream>
#include <stack>
#include "FileReader.h"
#include "PToken.h"
using namespace std;



class Scanner
{
    public:
    //Scans for the next token
    Token *nextToken();
    void printError(Token *token, string msg);
    void printTokens();
    void printToFile(string fileName);
    //construtor
    //Constructs the scanner from a given file
    Scanner(FileReader *file);
    private:
    FileReader *file;
    //skips the whitespace characters
    void skipWhiteSpace();
};






#endif