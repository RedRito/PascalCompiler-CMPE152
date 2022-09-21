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
    
    statementStarters.insert(PToken::BEGIN);
    statementStarters.insert(PToken::IDENTIFIER);
    statementStarters.insert(PToken::WHILE);
    statementStarters.insert(PToken::REPEAT);
    statementStarters.insert(PToken::DO);
    statementStarters.insert(PToken::CASE);
    statementStarters.insert(PToken::FOR);
    statementStarters.insert(PToken::WITH);
    statementStarters.insert(PToken::GOTO);
    statementStarters.insert(PToken::IF);
    statementStarters.insert(PToken::PROCEDURE);    //Add more if needed.
    
    static set<PToken> statementFollowers;         // what follows a statement  //semicolon, end, until, EOF,
    
    statementFollowers.insert(PToken::SEMICOLOR);
    statementFollowers.insert(PToken::END);
    statementFollowers.insert(PToken::END_OF_FILE);
    statementFollowers.insert(PToken::UNTIL);       //Add more if needed.
    
    static set<PToken> relationalOperators;        // relational operators          // = <> < <= > >=
    static set<PToken> simpleExpressionOperators;  // simple expression operators   // + - OR
    static set<PToken> termOperators;              // term operators                // * / DIV MOD AND
    static set<PToken> factorOperators;            // unique map of factor operators    //variable/identifer, number, string, NOT -> factor, ( -> expression -> )
    //Note, idk if you need to check for followers of relational, expression, term, and factor operators, will find out later
    
    ParserNode *parseDeclarationBlock();    //NOT DONE BUT IMMA SAY ITS DONE
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

    




};





#endif
