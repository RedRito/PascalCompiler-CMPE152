#ifndef PARSERNODE_H_
#define PARSERNODE_H_

#include <string>
#include <vector>

#include "../Scanner/PToken.h"

using namespace std; //lazy
//NOTE: NEED MORE/ NOT ENOUGH AT ALL
enum class NodeType //Type of tree nodes in parser tree, pulled form slides
{
    PROGRAM, 
    COMPOUND, 
    ASSIGN,
    WHILE, 
    LOOP, 
    TEST, 
    WRITE, 
    WRITELN,
    ADD, 
    SUBTRACT, 
    MULTIPLY, 
    DIVIDE,
    NEGATE,
    FLOAT_DIVIDE, 
    SELECT_BRANCH,
    SELECT_CONSTANTS,
    EQ, 
    LT,
    GT,
    VARIABLE, 
    INTEGER_CONSTANT, 
    REAL_CONSTANT, 
    STRING_CONSTANT,
    BOOLEAN_CONSTANT,
};

static const string NODE_TYPE_STRINGS[] =
{
    "PROGRAM", 
    "COMPOUND", 
    "ASSIGN",
    "WHILE", 
    "LOOP", 
    "TEST", 
    "WRITE", 
    "WRITELN",
    "ADD", 
    "SUBTRACT", 
    "MULTIPLY", 
    "DIVIDE", 
    "FLOAT_DIVIDE",
    "SELECT_BRANCH",
    "SELECT_CONSTANTS",
    "EQ", 
    "LT",
    "GT",
    "VARIABLE", 
    "INTEGER_CONSTANT", 
    "REAL_CONSTANT", 
    "STRING_CONSTANT",
    "BOOLEAN_CONSTANT"

};

class ParserNode
{
    private:
        NodeType type;
        int linenum;
        string datatext;
        //Symtab *tableEntry;
        //values of the node
        Token *TokenValue;
        //list of node children
        vector<ParserNode *> childrenList;
        //constructor
        ParserNode(NodeType type);
        //adopt another ParserNode as its first child
        void adopt(ParserNode *childNode);
    public:
        
};

#endif
