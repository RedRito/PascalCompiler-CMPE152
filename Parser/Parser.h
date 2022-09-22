#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <set>
#include "../Scanner/scanner.h"
#include "../Scanner/PToken.h"
#include "ParserNode.h"
#include "Symtab.h"



using namespace std;


static const set<PToken> statementStarters          // what starts a statement   //begin, identifier, all the looping starters, while, repeat, do, write, writeln, case, for, with, goto, if,
{
    PToken::BEGIN, PToken:: IDENTIFIER, PToken::WHILE, PToken::WHILE, PToken::REPEAT, PToken::DO,
    PToken::CASE, PToken::FOR, PToken::WITH, PToken::GOTO, PToken::IF, PToken::PROCEDURE
};
static const set<PToken> statementFollowers        // what follows a statement  //semicolon, end, until, EOF,
{
    PToken::SEMICOLON, PToken::END, PToken::END_OF_FILE, PToken::UNTIL
};
static const set<PToken> relationalOperators        // relational operators          // = <> < <= > >=
{
    PToken::EQUAL, PToken::NE, PToken::LT, PToken::GT, PToken::LTEQ, PToken::GTEQ
};
static const set<PToken> simpleExpressionOperators  // simple expression operators   // + - OR
{
    PToken::PLUSOP, PToken::MINUSOP, PToken::OR, PToken::XOR,
    PToken::PLUSEQUAL, PToken::MINUSEQUAL, PToken::MULTEQUAL, PToken::DIVEQUAL
};
static const set<PToken> termOperators              // term operators                // * / DIV MOD AND
{
    PToken::AND, PToken::MOD, PToken::DIV, PToken::NOT, PToken::MULTOP, PToken::DIVOP
};
static const set<PToken> factorOperators;            // unique map of factor operators    //variable/identifer, number, string, NOT -> factor, ( -> expression -> )

class Parser
{
    public:
    Parser(Scanner *scanner, Symtab *symtab); //params scanner and symboltable,
    int getErrNum();                //gets number of errors,
    ParserNode *parseTheProgram();  //main parser program, checks for tokens and determines which parse function to call //returns ParserNode
    
    private:
    Scanner *scanner;       //scanner obj for reading tokens
    Symtab *symtab;        //Temp comment (waiting on symtab to complete)
    Token *readToken;       //currently read token
    int linenum;            //token's line num
    int errNum;             //current number of err
    //visit http://www.irietools.com/iriepascal/progref350.html //for how pascal statements are done, pls add them to the statement hash set.
    
    void *parseDeclarationBlock(ParserNode *parent);    //NOT DONE BUT IMMA SAY ITS DONE
    ParserNode *parseStatement();           //done
    ParserNode *parseCompoundStatement();   //done
    ParserNode *parseAssignmentStatement(); //done
    ParserNode *parseRepeatStatement();     //done

    ParserNode *parseWriteStatement();      //done
    ParserNode *parseWritelnStatement();    //done
    ParserNode *parseExpression();          //done //please add stuff to nodetype
    ParserNode *parseSimpleExpression();    //NOT DONE

    ParserNode *parseTerm();                //NOT DONE
    ParserNode *parseFactor();              //NOT DONE
    ParserNode *parseVariable();            //DONE
    ParserNode *parseNOT();                 //DONE

    ParserNode *parseRealConstant();       //done
    ParserNode *parseStringConstant();     //done
    ParserNode *parseIntegerConstant();    //done

    ParserNode *parseWhile();              //done
    ParserNode *parseFor();                 //done
    ParserNode *parseIf();                  //IDK
    ParserNode *parseCase();                //IDK
    
    void parseAllStatements(ParserNode *parent, PToken tokenType);  //done
    void parseAllWrite(ParserNode *currentNode);                    //done
    void printSyntax(string msg);                                   //done
    void printSematic(string msg);                                  //done
    string toLowerCase(string text);

    




};





#endif
