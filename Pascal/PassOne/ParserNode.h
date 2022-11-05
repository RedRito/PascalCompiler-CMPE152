#ifndef PARSERNODE_H_
#define PARSERNODE_H_

#include <string>
#include <vector>

#include <Typespec.h>
#include "../Scanner/PToken.h"
#include "SymtabEntry.h"
using namespace std; //lazy

enum class NodeType //Type of tree nodes in parser tree, pulled form slides and online resources
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
//Strings for printing
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

/*Map for Node type names*/
static map<NodeType, string> NT_Names =
{
    {NodeType::PROGRAM, "PROGRAM"},
    {NodeType::COMPOUND, "COMPOUND"},
    {NodeType::ASSIGN, "ASSIGN"},
    {NodeType::WHILE, "WHILE"},
    {NodeType::LOOP, "LOOP"},
    {NodeType::TEST, "TEST"},
    {NodeType::FOR, "FOR"},
    {NodeType::IF, "IF"},
    {NodeType::SWITCH, "SWITCH"},
    {NodeType::VAR, "VAR"},
    {NodeType::VAR_DECLARATION, "VAR_DECLARATION"},
    {NodeType::INTEGER, "INTEGER"},
    {NodeType::WRITE, "WRITE"},
    {NodeType::WRITELN, "WRITELN"},
    {NodeType::ADD, "ADD"},
    {NodeType::SUBTRACT, "SUBTRACT"},
    {NodeType::OR, "OR"},
    {NodeType::MULTIPLY, "MULTIPLY"},
    {NodeType::DIVIDE, "DIVIDE"},
    {NodeType::NEGATE, "NEGATE"},
    {NodeType::FLOAT_DIVIDE, "FLOAT_DIVIDE"},
    {NodeType::AND, "AND"},
    {NodeType::NOT, "NOT"},
    {NodeType::SELECT_BRANCH, "SELECT_BRANCH"},
    {NodeType::SELECT_CONSTANTS, "SELECT_CONSTANTS"},
    {NodeType::EQ, "EQ"},
    {NodeType::LT, "LT"},
    {NodeType::GT, "GT"},
    {NodeType::NE, "NE"},   //Not Equal
    {NodeType::LTEQ, "LTEQ"},
    {NodeType::GTEQ, "GTEQ"},
    {NodeType::VARIABLE, "VARIABLE"},
    {NodeType::INTEGER_CONSTANT, "INTEGER_CONSTANT"},
    {NodeType::REAL_CONSTANT, "rEAL_CONSTANT"},
    {NodeType::STRING_CONSTANT, "STRING_CONSTANT"},
    {NodeType::BOOLEAN_CONSTANT, "BOOLEAN_CONSTANT"},
};

class ParserNode
{
public:
    //the type of parsernode
    NodeType type;
    int linenum;        //the linenumber of the node
    string datatext;    //the name of the node
    SymtabEntry* entry;

    NodeType* parent;   //parent node
    Typespec TS;        //data type's spec


    //values of the node
    object NodeObj;
    
    //list of node children
    vector<ParserNode*> childrenList;
    
    //constructor
    ParserNode(NodeType type);
    
    //adopt another ParserNode as its first child
    void adopt(ParserNode* childNode);


private:
    
};

#endif
