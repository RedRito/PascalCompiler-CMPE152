#pragma once
#ifndef PARSERNODEIMPL_H_
#define PARSERNODEIMPL_H_

#include "ParserNode.h"

class ParserNodeImpl : public ParserNode
{
public:
	//constructor
	ParserNodeImpl(const NodeType type);
	//getter
	ParserNode* getParent();
	ParserNode* getRoot();
	NodeType getType();
	//Typespec* getTS();					//Typespec isn't set up yet

	//setter
	ParserNode* setRoot(ParserNode* node);
	//void setTS(Typespec* TS);				//Typespec isn't set up yet

	//Initialize map function   TOOK THIS OUT, AT ParserNode.h
    

private:
	ParserNode* root;
	ParserNode* parent;

};

#endif
