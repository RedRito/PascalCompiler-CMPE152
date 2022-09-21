#include <iostream>

#include "ParserNode.h"
#include "TreeWalker.h"

using namespace std;

const string INDENT_SIZE = "    ";

void TreeWalker::print(ParserNode *node)
{
    line += indentation;
    line += "<" + NODE_TYPE_STRINGS[(int) node->type];
    if      (node->type == NodeType::PROGRAM)          line += " " + node->datatext;
    else if (node->type == NodeType::VARIABLE)         line += " " + node->datatext;
    //else if (node->type == NodeType::VAR_DECLARATION)
    else if (node->type == NodeType::INTEGER_CONSTANT) line += " " + to_string(node->TokenValue->tokenValueInt);
    else if (node->type == NodeType::REAL_CONSTANT)    line += " " + to_string(node->TokenValue->tokenValueReal);
    else if (node->type == NodeType::STRING_CONSTANT)  line += " '" + node->TokenValue->tokenValueString + "'";
    if (node->linenum > 0)                line += " line " + to_string(node->linenum);
    
    vector<ParserNode *> childrenList = node->childrenList;
    if (childrenList.size() > 0)
    {
        line += ">";
        printLine();

        printChildren(childrenList);
        line += indentation;
        line += "</" + NODE_TYPE_STRINGS[(int) node->type] + ">";
    }
    else line += " />";

    printLine();
}

void TreeWalker::printChildren(vector<ParserNode *> children)
{
    string saveIndentation = indentation;
    indentation += INDENT_SIZE;
    for (ParserNode *child : children) print(child);
    indentation = saveIndentation;
}

void TreeWalker::printLine()
{
    cout << line << endl;
    line = "";
}