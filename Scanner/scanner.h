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
    //Prints error message
    void printError(Token *token, string msg);
    //Prints Scanned tokens
    void printTokens();
    //Prints output to file
    void printToFile(string fileName);
    //construtor
    //Constructs the scanner from a given file
    Scanner(FileReader *file);
    private:
    FileReader *file;
};






#endif
