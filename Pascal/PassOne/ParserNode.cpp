#include <string>
#include "ParserNode.h"

ParserNode::ParserNode(NodeType type)
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

void ParserNode::adopt(ParserNode* childNode)
{
    childrenList.push_back(childNode);
}

/*Map of NodeType and Key names*/
bool ParserNode::initialize = false;
map<NodeType, string> NT_Names;
map<NodeKey, string> NT_Keys;
void ParserNode::initMap()
{
    if (initialize)
    {
        return;
    }
    vector<NodeType> Ntypes =
    {
        NodeType::PROGRAM,
        NodeType::COMPOUND,
        NodeType::ASSIGN,
        NodeType::WHILE,
        NodeType::LOOP,
        NodeType::TEST,
        NodeType::FOR,
        NodeType::IF,
        NodeType::SWITCH,
        NodeType::VAR,
        NodeType::VAR_DECLARATION,
        NodeType::INTEGER,
        NodeType::WRITE,
        NodeType::WRITELN,
        NodeType::ADD,
        NodeType::SUBTRACT,
        NodeType::OR,
        NodeType::MULTIPLY,
        NodeType::DIVIDE,
        NodeType::NEGATE,
        NodeType::FLOAT_DIVIDE,
        NodeType::AND,
        NodeType::NOT,
        NodeType::SELECT_BRANCH,
        NodeType::SELECT_CONSTANTS,
        NodeType::EQ,
        NodeType::LT,
        NodeType::GT,
        NodeType::NE,
        NodeType::LTEQ,
        NodeType::GTEQ,
        NodeType::VARIABLE,
        NodeType::INTEGER_CONSTANT,
        NodeType::REAL_CONSTANT,
        NodeType::STRING_CONSTANT,
        NodeType::BOOLEAN_CONSTANT,
    };

    vector<string> NtypesName =
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

    for (int i = 0; i < Ntypes.size(); i++)
    {
        NT_Names[Ntypes[i]] = NtypesName[i];
    }
    /*Finished NT_Names.
    Doing the Key map now*/

    vector<NodeKey> Nkeys =
    {
        NodeKey::LINE,
        NodeKey::ID,
        NodeKey::LEVEL,
        NodeKey::VALUE,
        NodeKey::TYPE_ID,
    };

    vector<string> NkeysName =
    {
        "LINE",
        "ID",
        "LEVEL",
        "VALUE",
        "TYPE_ID"
    };

    for (int j = 0; j < Nkeys.size(); j++)
    {
        NT_Keys[Nkeys[j]] = NkeysName[j];
    }
    //Now set initialize to true.
    initialize = true;
}


ParserNode::getRoot() const
{
    return root;
}

ParserNode::getParent() const
{
    return parent;
}

ParserNode::setRoot(ParserNode* node)
{
    root = node;
    return node;
}

