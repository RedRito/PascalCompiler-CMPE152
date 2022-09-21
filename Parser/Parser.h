#ifndef PARSER_H_
#define PARSER_H_

#include "../Scanner/scanner.h"
#include "../Scanner/PToken.h"
#include "ParserNode.h"
//include symtab




using namespace std;

class Parser
{
    public:
    Parser(Scanner *scanner); //params scanner and symboltable,
    int getErrNum();                //gets number of errors,
    ParserNode *parseTheProgram();  //main parser program, checks for tokens and determines which parse function to call //returns ParserNode

    private:
    Scanner *scanner;       //scanner obj for reading tokens
    //symtab Symtab;        //Temp comment (waiting on symtab to complete)
    Token *readToken;       //currently read token
    int linenum;            //token's line num
    int errNum;             //current number of err
    //visit http://www.irietools.com/iriepascal/progref350.html //for how pascal statements are done, pls add them to the statement hash set.
    static set<PToken> statementStarters;          // what starts a statement   //begin, identifier, all the looping starters, while, repeat, do, write, writeln, case, for, with, goto, if,
    static set<PToken> statementFollowers;         // what follows a statement  //semicolon, end, until, EOF,
    
    
    static set<PToken> relationalOperators;        // relational operators          // = <> < <= > >=
    static set<PToken> simpleExpressionOperators;  // simple expression operators   // + - OR
    static set<PToken> termOperators;              // term operators                // * / DIV MOD AND
    static set<PToken> factorOperators;            // unique map of factor operators    //variable/identifer, number, string, NOT -> factor, ( -> expression -> )
    //Note, idk if you need to check for followers of relational, expression, term, and factor operators, will find out later

    
    
    //Initializing Set of Pascal Statements
    //was wrong, changing
    


    ParserNode *parseRealConstant();
    ParserNode *parseStringConstant();
    ParserNode *parseIntegerConstant();
    
    ParserNode *parseWhile();
    ParserNode *parseFor();
    ParserNode *parseIf();
    ParserNode *parseCase();
    
    ParserNode *parseTerm();
    ParserNode *parseFactor();
    ParserNode *parseVariable();
    
    void parseAllStatements(ParserNode *parent, PToken tokenType);
    void parseAllWrite(ParserNode *currentNode);
    void printSyntax(string msg);
    void printSematic(string msg);

    




};





#endif
