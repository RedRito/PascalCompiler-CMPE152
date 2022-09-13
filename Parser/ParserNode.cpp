#include <string>
#include "ParserNode.h"

ParserNode::ParserNode(NodeType type)
{
    this -> type = type;
    linenum = 0;
    //entry = NULLPTR
}

void ParserNode::adopt(ParserNode *childNode)
{
    childrenList.push_back(childNode);
}