#ifndef PARSERNODE_H_
#define PARSERNODE_H_

#include <string>
#include <vector>

#include <Typespec.h>
#include "../Scanner/PToken.h"
#include "SymtabEntry.h"
#include "Object.h"
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
static map<string, NodeType> NT_Names =
{
    {"PROGRAM", NodeType::PROGRAM},
    {"COMPOUND", NodeType::COMPOUND},
    {"ASSIGN", NodeType::ASSIGN},
    {"WHILE", NodeType::WHILE},
    {"LOOP", NodeType::LOOP},
    {"TEST", NodeType::TEST},
    {"FOR", NodeType::FOR},
    {"IF", NodeType::IF},
    {"SWITCH", NodeType::SWITCH},
    {"VAR", NodeType::VAR},
    {"VAR_DECLARATION", NodeType::VAR_DECLARATION},
    {"INTEGER", NodeType::INTEGER},
    {"WRITE", NodeType::WRITE},
    {"WRITELN", NodeType::WRITELN},
    {"ADD", NodeType::ADD},
    {"SUBTRACT",NodeType::SUBTRACT},
    {"OR", NodeType::OR},
    {"MULTIPLY", NodeType::MULTIPLY},
    {"DIVIDE", NodeType::DIVIDE},
    {"NEGATE", NodeType::NEGATE},
    {"FLOAT_DIVIDE", NodeType::FLOAT_DIVIDE},
    {"AND", NodeType::AND},
    {"NOT", NodeType::NOT},
    {"SELECT_BRANCH", NodeType::SELECT_BRANCH},
    {"SELECT_CONSTANTS", NodeType::SELECT_CONSTANTS},
    {"EQ", NodeType::EQ},
    {"LT", NodeType::LT},
    {"GT", NodeType::GT},
    {"NE", NodeType::NE},   //Not Equal
    {"LTEQ", NodeType::LTEQ},
    {"GTEQ", NodeType::GTEQ},
    {"VARIABLE", NodeType::VARIABLE},
    {"INTEGER_CONSTANT", NodeType::INTEGER_CONSTANT},
    {"REAL_CONSTANT", NodeType::REAL_CONSTANT},
    {"STRING_CONSTANT", NodeType::STRING_CONSTANT},
    {"BOOLEAN_CONSTANT", NodeType::BOOLEAN_CONSTANT}
};

/*contents map*/
map<string, Object>contents;

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
    Object NodeObj;
    
    //list of node children
    vector<ParserNode*> childrenList;
    
    //constructor
    ParserNode(NodeType type)
    {
        this->type = type;
        datatext = "";
        linenum = 0;
        NodeValueBoolean = false;
        NodeValueInt = 0;
        NodeValueReal = 0.0;
        NodeValueString = "";
        entry = nullptr;
    }
    
    //adopt another ParserNode as its first child
    void adopt(ParserNode* childNode)
    {
        childrenList.push_back(childNode);
    }

    /*Content initialized*/
    ~ParserNode()
    {
        for (ParserNode* node : childrenList)
        {
            if (node != nullptr)
            {
                delete node;
            }
        }
        for (pair<string, Object>c : contents)
        {
            if (!c.second.empty())
            {
                if (instanceof(p.second, SymtabEntry*))
                {
                    SymtabEntry* id = cast(p.second, SymtabEntry*);
                    if (id != nullptr)
                    {
                        delete id;
                    }
                }
            }
        }
    }

    Object getAttribute(const string str)
    {
        return (contents.find(str) != contents.end()) ? contents[str]
            : Object();
    }

    map<string, Object>& getContents()
    {
        return contents;
    }

    Typespec getTS() const
    {
        return TS;
    }

    /*Setters:*/
    void setAttribute(const string str, Object val) 
    {
        contents[str] = val;
    }

    void setTS(Typespec* NewTS)
    {
        TS = NewTS;
    }

private:
    
};

#endif
