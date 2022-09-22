#ifndef TREEWALKER_H_
#define TREEPWALKER_H_

#include <string>
#include <vector>

#include "ParserNode.h"


using namespace std;

class TreeWalker
{
private:
    //static const string INDENT_SIZE;

    string indentation;  
    string line;         

public:
    TreeWalker() : indentation(""), line("") {}
    void print(ParserNode *node);
    void printToFile(ParserNode *node, string filename);

private:
    void setIndentSize(string size);
    void printChildren(vector<ParserNode *> children);
    void printLine();
    void printChildrenFile(vector<ParserNode *> children, string filename);
    void printLineFile(string filename);
};

#endif /* TREEWALKER_H_ */