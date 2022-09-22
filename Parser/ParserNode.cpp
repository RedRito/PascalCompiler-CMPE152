#include <string>
#include "ParserNode.h"

ParserNode::ParserNode(NodeType type)
{
    this -> type = type;
    datatext = "";
    linenum = 0;
    NodeValueBoolean = false;
    NodeValueInt = 0;
    NodeValueReal = 0.0;
    NodeValueString = "";
    entry = nullptr;
}

void ParserNode::adopt(ParserNode *childNode)
{
    childrenList.push_back(childNode);
}