#include <iostream>
#include <fstream>
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
        print(child);
    }
    indentation = saveIndentation;
}

void TreeWalker::printLine()
{
    cout << line << endl;
    line = "";
}

void TreeWalker::printLineFile(string filename)
{
    ofstream printFile;
    printFile.open(filename, std::ios_base::app);
    if (printFile.fail())
    {
        cout << " COULD NOT OPEN THE FILE " << filename << endl;
        exit(1);
    }
    printFile << line << endl;
    line = "";
    printFile.close();
}

void TreeWalker::printToFile(ParserNode *node, string filename)
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
        printLineFile(filename);

        printChildrenFile(childrenList, filename);
        line += indentation;
        line += "</" + NODE_TYPE_STRINGS[(int) node->type] + ">";
    }
    else line += " />";

    printLineFile(filename);
}

void TreeWalker::printChildrenFile(vector<ParserNode *> children, string filename)
{
    string saveIndentation = indentation;
    indentation += INDENT_SIZE;
    for (ParserNode *child : children) 
    {
        printToFile(child, filename);
    }
    indentation = saveIndentation;
}