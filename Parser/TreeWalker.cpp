#include <iostream>

#include "ParserNode.h"
#include "TreeWalker.h"

namespace intermediate {

using namespace std;

const string TreeWalker::INDENT_SIZE = "    ";

void TreeWalker::print(Node *node)
{
    line += indentation;
    line += "<" + NODE_TYPE_STRINGS[(int) node->type];
    if      (node->type == PROGRAM)          line += " " + node->text;
    else if (node->type == VARIABLE)         line += " " + node->text;
    else if (node->type == INTEGER_CONSTANT) line += " " + to_string(node->value.L);
    else if (node->type == REAL_CONSTANT)    line += " " + to_string(node->value.D);
    else if (node->type == STRING_CONSTANT)  line += " '" + node->value.S + "'";
    if (node->lineNumber > 0)                line += " line " + to_string(node->lineNumber);
    
    vector<Node *> children = node->children;
    if (children.size() > 0)
    {
        line += ">";
        printLine();

        printChildren(children);
        line += indentation;
        line += "</" + NODE_TYPE_STRINGS[(int) node->type] + ">";
    }
    else line += " />";

    printLine();
}

void TreeWalker::printChildren(vector<Node *> children)
{
    string saveIndentation = indentation;
    indentation += INDENT_SIZE;
    for (Node *child : children) print(child);
    indentation = saveIndentation;
}

void TreeWalker::printLine()
{
    cout << line << endl;
    line = "";
}

}  // namespace intermediate
