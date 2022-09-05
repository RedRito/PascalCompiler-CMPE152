#ifndef FILEREADER_H_
#define FILEREADER_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileReader{
    private:
        ifstream file;
        string fileName;
        int line;
        char currentCh;
        
    public:
        /*
            Constructor
        */
        FileReader(string fileName);
        //getter method, gets the current line of the program
        int getLine();
        // getter gets the current character
        char getCurrentChar();
        //consumes current character and points to next character
        char nextChar();

};
#endif