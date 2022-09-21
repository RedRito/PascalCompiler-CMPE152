
#ifndef TREEWALKER_H_
#define TREEPWALKER_H_

#include <string>
#include <vector>

#include "ParserNode.h"

namespace intermediate {

using namespace std;

class ParseTreePrinter
{
private:
    static const string INDENT_SIZE;

    string indentation;  
    string line;         

public:
    ParseTreePrinter() : indentation(""), line("") {}
    void print(Node *node);

private:
    void printChildren(vector<Node *> children);
    void printLine();
};

}
#endif /* TREEWALKER_H_ */
