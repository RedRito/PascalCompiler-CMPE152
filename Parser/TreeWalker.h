#ifndef TREEWALKER_H_
#define TREEPWALKER_H_

#include <string>
#include <vector>

#include "ParserNode.h"


using namespace std;

class TreeWalker
{
private:
    string indentation;  
    string line;         

public:
    //constructor
    TreeWalker() : indentation(""), line("") {}
    //prints the current node
    void print(ParserNode *node);
    //prints the current node to file
    void printToFile(ParserNode *node, string filename);

private:
    //sets the indent size of the space
    void setIndentSize(string size);
    //prints the children of a given node
    void printChildren(vector<ParserNode *> children);
    //prints the line of the print() to stdout
    void printLine();
    //prints the line of the printToFile() to given file
    void printChildrenFile(vector<ParserNode *> children, string filename);
    //prints line to given file
    void printLineFile(string filename);
};

#endif /* TREEWALKER_H_ */