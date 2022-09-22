#include <iostream>

#include "ParserNode.h"
#include "TreeWalker.h"

using namespace std;

const string INDENT_SIZE = "    ";

void TreeWalker::print(ParserNode *node)
{
    line += indentation;
    line += "<" + NODE_TYPE_STRINGS[(int) node->type];
    if      (node->type == NodeType::PROGRAM)          
    {
        line += " " + node->datatext;
    }
    else if (node->type == NodeType::VARIABLE)
    {
        line += " " + node->datatext;
    }         
    else if (node->type == NodeType::INTEGER_CONSTANT)
    {
        line += " " + to_string(node->NodeValueInt);
    } 
    else if (node->type == NodeType::REAL_CONSTANT)    
    {
        line += " " + to_string(node->NodeValueReal);
    }
    else if (node->type == NodeType::STRING_CONSTANT)  
    {
        line += " '" + node->NodeValueString + "'";
    }
    if (node->linenum > 0)                
    {
        line += " line " + to_string(node->linenum);
    }
    
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
    for (ParserNode *child : children) 
    {
        // if      (child->type == NodeType::PROGRAM)          cout <<"PROGRAM" <<endl;
        // else if (child->type == NodeType::VARIABLE)         cout << "VAR" << endl;
        // else if (child->type == NodeType::INTEGER_CONSTANT) cout <<"INT" << endl;
        // else if (child->type == NodeType::REAL_CONSTANT)    cout << "REAL" << endl;
        // else if (child->type == NodeType::STRING_CONSTANT)  cout << "STRING" << endl;
        print(child);
    }
    indentation = saveIndentation;
}

void TreeWalker::printLine()
{
    cout << line << endl;
    line = "";
}