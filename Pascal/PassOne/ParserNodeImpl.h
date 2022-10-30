#pragma once
#ifndef PARSERNODEIMPL_H_
#define PARSERNODEIMPL_H_

#include "ParserNode.h"

class ParserNodeImpl : public ParserNode
{
public:
	//constructor
	ParserNodeImpl(const Nodetype type);
	//getter
	ParserNode* getParent();
	ParserNode* getRoot();
	Nodetype getType();

	//setter
	ParserNode* setRoot(ParserNode* node);

	ParserNode* addChild(ParserNode* node);


private:
	ParserNode* root;
	ParserNode* parent;

};

#endif