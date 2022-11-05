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

	//Initialize map function
    static bool initialize;
    initialize = false;
    static void initMap()
    {
        if (initialize == true)
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
        /*Finished NT_Names. --No longer needed*/
        //Now set initialize to true.
        initialize = true;
    }

private:
	ParserNode* root;
	ParserNode* parent;

};

#endif
