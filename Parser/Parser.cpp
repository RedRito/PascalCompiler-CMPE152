#include "../Scanner/PToken.h"
#include "Parser.h"

//Pascal statement syntax
/*
    compound statment and assignment statment
    a compound statment contains a begin, statmentList, and end;
    a statment contains itself and may contain a semicolon
    an assignment statment contains a variable/identifier, " := " assign token, and an expression
*/

//Pascal expressions
/*
    simple expression, PLUSOP or MINUSOP a term, OPTIONALLY (with PLUSOP, MINUSOP, OROP, and a TERM)
    a expression is 2 simple expressions together with a relational operator = <> < <= > >=


    A TERM
    contains a factor, or optionally
        MULTOP, DIVOP, DIV, MOD, ANDOP
        as well as any number of factors

    A FACTOR
    contains a variable, xor a number, or a string, or a NOT followed by a factor, or a LEFTPAREN, expression, RIGHTPAREN.  
*/


//types of statements cont.
/*
    compoundStatments
    assignmentStatement
    WHILE statment
    Repeat statement        syntax = REPEAT -> statementlist -> UNTIL -> expression
    for statment    
    if statement
    case statement

*/

Parser::Parser(Scanner *scanner, SymbolTable symtab)    //will cause issues cause not completed symbol table
{
    linenum = 1;
    this -> scanner = scanner;
    //this -> symtab = symtab;
    currentToken = nullptr;
    errNum = 0;
}

int Parser::getErrNum()
{
    return errNum;
}

ParserNode *Parser::parseStatement()
{
    Node *stmtNode = nullptr;
    int savedLineNumber = currentToken->lineNumber;
    lineNumber = savedLineNumber;

    switch (currentToken->type)
    {
        case IDENTIFIER : stmtNode = parseAssignmentStatement(); break;
        case BEGIN :      stmtNode = parseCompoundStatement();   break;
        case REPEAT :     stmtNode = parseRepeatStatement();     break;
        case WHILE :      stmtNode = parseWhileStatement();      break;
        case FOR :        stmtNode = parseForStatement();        break;
        case IF :         stmtNode = parseIfStatement();         break;
        case CASE :       stmtNode = parseCaseStatement();       break;
        case WRITE :      stmtNode = parseWriteStatement();      break;
        case WRITELN :    stmtNode = parseWritelnStatement();    break;
        case SEMICOLON :  stmtNode = nullptr; break;  // empty statement

        default : syntaxError("Unexpected token");
    }

    if (stmtNode != nullptr) stmtNode->lineNumber = savedLineNumber;
    return stmtNode;
}

ParserNode *Parser::parseAssignmentStatement()
{
    Node *assignmentNode = new Node(ASSIGN);
    string variableName = currentToken->text;
    SymtabEntry *variableId = symtab->lookup(toLowerCase(variableName));
    if (variableId == nullptr) variableId = symtab->enter(variableName);
    Node *lhsNode  = new Node(VARIABLE);
    lhsNode->text  = variableName;
    lhsNode->entry = variableId;
    assignmentNode->adopt(lhsNode);
    currentToken = scanner->nextToken();
    if (currentToken->type == COLON_EQUALS)
    {
        currentToken = scanner->nextToken();
    }
    else syntaxError("Missing :=");
    Node *rhsNode = parseExpression();
    assignmentNode->adopt(rhsNode);
    return assignmentNode;
}

ParserNode *Parser::parseCompoundStatement()
{
    Node *compoundNode = new Node(COMPOUND);
    compoundNode->lineNumber = currentToken->lineNumber;
    currentToken = scanner->nextToken();
    parseStatementList(compoundNode, END);
    if (currentToken->type == END)
    {
        currentToken = scanner->nextToken();
    }
    else syntaxError("Expecting END");
    return compoundNode;
}

ParserNode *Parser::parseRepeatStatement()
{
    Node *loopNode = new Node(LOOP);
    currentToken = scanner->nextToken();
    parseStatementList(loopNode, UNTIL);
    if (currentToken->type == UNTIL)
    {
        Node *testNode = new Node(TEST);
        lineNumber = currentToken->lineNumber;
        testNode->lineNumber = lineNumber;
        currentToken = scanner->nextToken();
        testNode->adopt(parseExpression());
        loopNode->adopt(testNode);
    }
    else syntaxError("Expecting UNTIL");
    return loopNode;
}

ParserNode * Parser::parseTheProgram()
{
    //do main parse here
}


/*
    Parse the current token which is a number of type real
*/
ParserNode *Parser::parseRealConstant()
{
    ParserNode *realConst = new ParserNode(NodeType::REAL_CONSTANT);
    realConst -> TokenValue -> tokenValueInt = readToken -> tokenValueInt;
    realConst -> TokenValue -> tokenValueReal = readToken -> tokenValueReal;
    realConst -> TokenValue -> tokenValueString = readToken -> tokenValueString;
    realConst -> TokenValue -> tokenValueBoolean = readToken -> tokenValueBoolean;

    readToken = scanner ->nextToken();
    return realConst;
}

/*
    Parse the current token which is a string
*/
ParserNode *Parser::parseStringConstant()
{
    ParserNode *realConst = new ParserNode(NodeType::REAL_CONSTANT);
    realConst -> TokenValue -> tokenValueInt = readToken -> tokenValueInt;
    realConst -> TokenValue -> tokenValueReal = readToken -> tokenValueReal;
    realConst -> TokenValue -> tokenValueString = readToken -> tokenValueString;
    realConst -> TokenValue -> tokenValueBoolean = readToken -> tokenValueBoolean;

    readToken = scanner ->nextToken();
    return realConst;
}

/*
    Parser::parseIntegerConstant()
*/
ParserNode *Parser::parseIntegerConstant()
{
    ParserNode *realConst = new ParserNode (NodeType::INTEGER_CONSTANT);
    realConst -> TokenValue -> tokenValueInt = readToken -> tokenValueInt;
    realConst -> TokenValue -> tokenValueReal = readToken -> tokenValueReal;
    realConst -> TokenValue -> tokenValueString = readToken -> tokenValueString;
    realConst -> TokenValue -> tokenValueBoolean = readToken -> tokenValueBoolean;

    readToken = scanner->nextToken();
    return realConst;
}

ParserNode *Parser::parseTerm()
{
    ParserNode *currTerm = parseFactor();
    while(termOperators.find(currentToken->type) != termOperators.end())
    {
        if(ParserNode *opNode = currentToken->type == STAR)
        {
            new ParserNode(NodeType::MULTIPLY);
        }
        else
        {
            new ParserNode(NodeType::DIVIDE);
        }
        currentToken = scanner->nextToken();   //consume the operator
        opNode->adopt(currTerm);
        opNode->adopt(parseFactor());
        termNode = opNode;
    }
    return currTerm;
}

ParserNode *Parser::parseFactor()
{
    if(currentToken->type == NodeType::IDENTIFIER)
    {
        return parseVariable();
    }
    else if(currentToken->type == NodeType::INTEGER)
    {
        return parseIntegerConstant();
    }
    else if(currentToken->type == NodeType::REAL)
    {
        return parseRealConstant();
    }
    else if(currentToken->type == NodeType::LPAREN)
    {
        currentToken->type = scanner->nextToken();
        //ParserNode *exprNode = parseExpression();     //add in after parseExpression is written!
        if(currentToken->type == NodeType::RPAREN)
        {
            currentToken = scanner->nextToken();
        }
        else
        {
            printSyntax("Expecting )");
        }
        //return exprNode;                        //add in after parseExpression is written!
    }
    else
    {
        printSyntax("Unexpected token");
    }
    return nullptr;
}

ParserNode *Parser::parseVariable()
{
    string varName = currentToken->text;
    Entry *varID = symtab->lookup(toLowerCase(varName));    //needs to test lookup func
    if(varID == nullptr)
    {
        printSematic("Undeclared identifier");
    }
    ParserNode *tempNode = new ParserNode(NodeType::VARIABLE);
    tempNode->text = varName;
    currentToken = scanner->nextToken();
    return tempNode;
}

void Parser::printSyntax(string msg)
{
    cout << "Syntax error at line " << linenum << " " << msg << " " << readToken -> toString();
    errNum ++;
    while (statementFollowers.find(currentToken->type) == statementFollowers.end())
    {
        readToken = scanner->nextToken();
    }
}

void Parser::printSematic(string msg)
{
    cout << "Sematic error at line " << linenum << " " << msg << " " << readToken -> toString();
    errNum++;
}

void Parser::parseAllStatements(ParserNode *parent, PToken tokenType)
{
    //parse all statments in statment list
    //while not end of file and not 
    while( (readToken -> datatype != PToken::END_OF_FILE) && (readToken -> datatype != tokenType))
    {
        ParserNode *node = parseStatement();
        if(node != nullptr)
        {
            parent -> adopt(node);
        }

        if(readToken -> datatype == PToken::SEMICOLOR)
        {
            readToken = scanner ->nextToken();
        }
        else if(statementStarters.find(readToken->datatype) != statementStarters.end())
        {
            printSyntax("missing a ;");
        }

    }
}
//ex. Writeln('this is a writeln statement and this is the integer ', num);
void Parser::parseAllWrite(ParserNode *currentNode)
{
    bool hasWriteArgument = false;
    if(readToken -> datatype == PToken::LPAREN)
    {
        readToken = scanner ->nextToken(); //eat the (
    }
    else
    {
        printSyntax("Missing a left parenthesis");
    }

    if(readToken -> datatype == PToken::IDENTIFIER)
    {
        currentNode -> adopt(parseVariable());
        hasWriteArgument = true;
    }
    else if(readToken ->datatype == PToken::STRING)
    {
        currentNode -> adopt(parseStringConstant());
        hasWriteArgument = true;
    }
    else
    {
        printSyntax("Invalid write or writeln");
    }

    if(hasWriteArgument)
    {
        if(readToken->datatype == PToken::COLON)    //if it is a colon
        {
            readToken = scanner -> nextToken(); //eat the ,

            if(readToken -> datatype == PToken::INTEGER)
            {
                currentNode -> adopt(parseIntegerConstant());

                if(readToken ->datatype == PToken::COLON)
                {
                    readToken = scanner ->nextToken(); //consume "","" again
                    
                    if(readToken -> datatype == PToken::INTEGER)
                    {
                        currentNode -> adopt(parseIntegerConstant());
                    }
                    else
                    {
                        printSyntax("Invalid decimal count");
                    }
                    
                }

            }
            else
            {
                printSyntax("Invalid width");
            }
        }
    }

    if(readToken ->datatype == PToken::RPAREN)
    {
        readToken = scanner ->nextToken(); //eat the right parenthesis
    }
    else
    {
        printSyntax("Missing a right parenthesis");
    }


}



