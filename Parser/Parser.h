#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <set>
#include "../Scanner/scanner.h"
#include "../Scanner/PToken.h"
#include "ParserNode.h"
#include "Symtab.h"



using namespace std;

/*
    Sets of hashsets that contain the token's used for statements and expressions.
*/
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

class Parser
{
    public:
    Parser(Scanner *scanner, Symtab *symtab); //params scanner and symboltable,
    int getErrNum();                //gets number of errors,
    ParserNode *parseTheProgram();  //main parser program, checks for tokens and determines which parse function to call //returns ParserNode
    Symtab *symtab;                 //the main symbol table of the parser
    private:
    Scanner *scanner;       //scanner obj for reading tokens
           
    Token *readToken;       //currently read token
    int linenum;            //token's line num
    int errNum;             //current number of err

    //visit http://www.irietools.com/iriepascal/progref350.html //for how pascal statements are done.
    
    void *parseDeclarationBlock(ParserNode *parent);        //parse declarations all as a integer
    /*
        parses a compound statement
        returns the node of statement
    */  
    ParserNode *parseStatement();                 
            
    /*
        parses a coumpand statement block
        returns the node of the compound block
    */
    ParserNode *parseCompoundStatement();   
    /*
        parses assignment statement
        returns assignment parsernode
    */
    ParserNode *parseAssignmentStatement();
    /*
        parses a repeat statement
        returns a loop / repeat node
    */
    ParserNode *parseRepeatStatement();     
    /*
        parses a write statment
        returns a node of write
    */
    ParserNode *parseWriteStatement();      
    /*
        parses a writeln statment
        returns a node of writeln
    */
    ParserNode *parseWritelnStatement();    
    /*
        parses an expression
        returns an expression node
    */
    ParserNode *parseExpression();          
    /*
        parses a simple expression
        returns an simple expression node
    */
    ParserNode *parseSimpleExpression();   
    /*
        parses a term
        returns a term node
    */
    ParserNode *parseTerm();                
    /*
        parses a factor which can be a variable, integer, real, or not, or negative num
        returns a factor
    */
    ParserNode *parseFactor();              
    /*
        parses a variable and finds its value on a symbol table
        returns the variable node
    */
    ParserNode *parseVariable();            
    /*
        parses a not factor
        returns the not node
    */
    ParserNode *parseNOT();                 
    /*
        parses a real constant, it sets the nodes value
        returns real node
    */
    ParserNode *parseRealConstant();      
    /*
        parses a string, it sets the nodes string value
        returns string node
    */
    ParserNode *parseStringConstant();     
    /*
        parses integer, it sets the nodes int value
        returns int node  
    */
    ParserNode *parseIntegerConstant();    
    /*
        parses while loop
        returns while node.
    */
    ParserNode *parseWhile();              
    /*
        parses for loop
        returns for node
    */
    ParserNode *parseFor();                 
    /*
        parses if condition
        returns if node
    */
    ParserNode *parseIf();                  
    /*
        parses a switch case
        returns case node
    */
    ParserNode *parseCase();                
    /*
        parses all statements given a starting node and a terminating tokentype
        returns void
    */
    void parseAllStatements(ParserNode *parent, PToken tokenType);  
    /*
        parses all write arguments of a write node
        returns void
    */
    void parseAllWrite(ParserNode *currentNode);                    
    /*
        print syntax based on current token's values
    */
    void printSyntax(string msg);                                   
    /*
        prints sematic error based on token's values
    */
    void printSematic(string msg);                                  
    /*
        converts a string to lowercase
        returns lowercase of a given string
    */
    string toLowerCase(string text);
};





#endif
