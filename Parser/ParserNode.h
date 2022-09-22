#ifndef PARSERNODE_H_
#define PARSERNODE_H_

#include <string>
#include <vector>

#include "../Scanner/PToken.h"
#include "SymtabEntry.h"
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
    FOR,
    IF,
    SWITCH,
    VAR,
    VAR_DECLARATION,
    INTEGER, 
    WRITE, 
    WRITELN,
    ADD, 
    SUBTRACT,
    OR, 
    MULTIPLY, 
    DIVIDE,
    NEGATE,
    FLOAT_DIVIDE,
    AND, 
    NOT,
    SELECT_BRANCH,
    SELECT_CONSTANTS,
    EQ, 
    LT,
    GT,
    NE,
    LTEQ,
    GTEQ,
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
    "FOR",
    "IF",
    "SWITCH",
    "VAR",
    "VAR_DECLARATION",
    "INTEGER",   
    "WRITE", 
    "WRITELN",
    "ADD", 
    "SUBTRACT",
    "OR", 
    "MULTIPLY", 
    "DIVIDE", 
    "NEGATE",
    "FLOAT_DIVIDE",
    "AND",
    "NOT",
    "SELECT_BRANCH",
    "SELECT_CONSTANTS",
    "EQ", 
    "LT",
    "GT",
    "NE",
    "LTEQ",
    "GTEQ",
    "VARIABLE", 
    "INTEGER_CONSTANT", 
    "REAL_CONSTANT", 
    "STRING_CONSTANT",
    "BOOLEAN_CONSTANT"
};

class ParserNode
{
    public:
        NodeType type;
        int linenum;
        string datatext;
        SymtabEntry *entry;
        //values of the node
        Token *TokenValue;
        double NodeValueReal;
        int NodeValueInt;
        string NodeValueString;
        bool NodeValueBoolean;
        //list of node children
        vector<ParserNode *> childrenList;
        //constructor
        ParserNode(NodeType type);
        //adopt another ParserNode as its first child
        void adopt(ParserNode *childNode);
    private:
        
};

#endif
