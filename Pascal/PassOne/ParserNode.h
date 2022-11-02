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

/*The key emun class*/
enum class NodeKey
{
    LINE,
    ID,
    LEVEL,
    VALUE,
    TYPE_ID,
};

static const string NODE_KEY_STRINGS[] =
{
    "LINE",
    "ID",
    "LEVEL",
    "VALUE",
    "TYPE_ID"
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
    TypeSpec TS;        //data type's spec


    //values of the node
    double NodeValueReal;
    int NodeValueInt;
    string NodeValueString;
    bool NodeValueBoolean;
    
    //list of node children
    vector<ParserNode*> childrenList;
    
    //constructor
    ParserNode(NodeType type);
    
    //adopt another ParserNode as its first child
    void adopt(ParserNode* childNode);

    //--
    //getting map contents
    map<NodeKey, Object>& getContent();
    map<NodeKey, Object> contents;

    Object getAttribute(const NodeKey key);

    /*Map for Node type names and key names*/
    static map<NodeType, string> NT_Names;
    static map<NodeKey, string> NT_Keys;

    static bool initialize;
    static void initMap();

    /*Getter & Setter for Parent/Root/TS*/
    //getter
    ParserNode* getParent();
    ParserNode* getRoot();
    NodeType getType();
    TypeSpec* getTS();

    //setter
    ParserNode* setRoot(ParserNode* node);
    void setTS(TypeSpec* TS);

private:
    //map<NodeKey, Object> contents;
};

#endif
