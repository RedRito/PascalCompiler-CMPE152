#include "ParserNodeImpl.h"
#include "ParserNode.h"

ParserNode* ParserNodeImpl::getRoot()
{
	return root;
}

ParserNode* ParserNodeImpl::getParent()
{
	return parent;
}

ParserNode* ParserNodeImpl::getType()
{
	return type;
}

ParserNode* ParserNodeImpl::setRoot(ParserNode* node)
{
	root = node;
	return node;
}

