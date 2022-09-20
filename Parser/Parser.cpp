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


ParserNode * Parser::parseTheProgram()
{
    //do main parse here
    ParserNode *program = new Node(NodeType::PROGRAM);
    readToken = scanner->nextToken();

    //if first token == program, read the next token
    if(readToken->datatype == PToken::PROGRAM)
    {
        readToken = scanner->nextToken();
    }
    else
    {
        printSyntax("Missing PROGRAM");
    }

    //if next token is identifier, it is the name of the program
    if(readToken->datatype == PToken::IDENTIFIER)
    {
        string programName = readToken->datatext;
        //enter a entry into the symbol table of the ParserNode
        //Symtab -> tabEntry(programName);
        program->text = programName;
        //read next token
        readToken = scanner->nextToken();
    }
    else
    {
        printSyntax("Expecting PROGRAM Identifier");
    }
    //after PROGRAM proName; there is a semicolon, consume it
    if(readToken->datatype == PToken::SEMICOLOR)
    {
        readToken = scanner->nextToken();
    }
    else
    {
        printSyntax("Missing ; ");
    }

    //Usually we would check for VAR, USES,procedure, method, and whatnot. however, since we are not handling decaration and types
    //we do not need to worry about those
    //Simply look for the BEGIN
    if(readToken->datatype == PToken::BEGIN)
    {
        program->adopt(parseCompoundStatement());
        //now should be end of the program check for the period "."
        if(readToken->datatype == PToken::SEMICOLOR)
        {
            printSyntax("Expecting '.' ");
        }
    }
    else printSyntax("MISSING BEGIN");

    return program;
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
        //for my understanding
        // currterm = a factor
        // opnode = a term operator
        //so tree becomes
        //      operator
        //factor1       factor2
        //the current term becomes operator and it is the base of the tree
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
// Parser *test = new Parser(TEST);
    // Parser *notNode = new Parser(Nodetype::NOT);
    // loop -> adopt(test);
    // test -> adopt(notNode);

    // notNode -> adopt (parseExpression());

    // if (readToken -> type != DO)
    // syntaxError ("Look for DO");
    // else 
    // {
    //     readToken = scanner -> nextToken();
    // }
    // loop -> adopt(parseStatement);
ParserNode *Parser::parseWhile()
{
    ParserNode *loop = new ParserNode(NodeType::WHILE);
    //consume while
    readToken = scanner -> nextToken();
    //the next token is the condition
    //test node tests the expression
    ParserNode *testCodition = new ParserNode(NodeType::TEST);
    //parse the expression in between while and do
    parseAllStatements(loop, PToken::DO);
    //loop node first child should now be the condidion
    //current token is now DO //if not throw an error
    if(readToken->datatype == PToken::DO)
    {
        linenum = readToken->linenum;
        testCodition->linenum = linenum;
        readToken = scanner->nextToken(); //consumes DO
        //parse what comes after the DO,
        //dont have to worry about the BEGIN, END parseing the expression will solve that issue
        //test adopts the entire loop expression
        testCodition->adopt(parseExpression());
        //while loop adopts the expression as its second child.
        loop->adopt(testCodition);
    }
    else printSyntax("Expected DO");
    return loop;
}
// Parser *compound = new Parser(COMPOUND);
    // readToken = scanner -> nextToken();

    // Parser *assign = parseAssignmentStatement();
    // compound -> adopt(assign);

    // Parser *control = assign ->children[0];

    // Parser *loop = new Parser(LOOP);
    // compound -> adopt(loop);

    // Parser *test = new Parser(TEST);
    // loop -> adopt(test);

    // bool countUp = true;
    // if (readToken -> type == TO)
    // {
    //     readToken = scanner -> nextToken();
    // }
    // else if (readToken -> type == DOWNTO)
    // {
    //     countUp = false;
    //     readToken = scanner -> nextToken();
    // }
    // else syntaxError("Look for TO or DOWNTO");

    // Parser *compare = countUp ? new Parser(GT) : new Parser(LT);
    // test -> adopt(compare);
    // compare -> adopt(parseExpression());

    // if (readToken -> type == DO)
    // {
    //     readToken = scanner -> nextToken();
    // }
    // else syntaxError("Look for DO");

    // loop -> adopt(parseStatement());

    // assign = new Parser(ASSIGN);
    // loop->adopt(assign);
    // assign->adopt(control->copy());
    // Parser *op = countUp ? new Parser(ADD) : new Parser(SUBTRACT);
    // assign->adopt(op);
    // // op->adopt(control->copy());
    // // Parser *one = new Parser(INTEGER_CONSTANT);
    // // one -> tokenValueInt = 1;
    // // op->adopt(one);

    // return compound;
ParserNode *Parser::parseFor()
{
    //create a node for the FOR loop
    ParserNode *forLoop = new ParserNode(NodeType::FOR);
    //read consume the FOR
    readToken = scanner -> nextToken();
    //parse the inital assignment 
    forLoop->adopt(parseAssignmentStatement());
    //now read token should be at to or DOWNTO
    if(readToken->datatype == PToken::TO || readToken->datatype == PToken::DOWNTO)
    {
        readToken = scanner->nextToken(); //consumes TO or DOWNTO
        //now we need to parse the final value, which is a SMALLINT according to other compilers
        //Thus we need to check if the token is a value, which can be either a plain integer or a identifer that is a value
        if(readToken ->datatype == PToken::IDENTIFIER)
        {
            forLoop->adopt(parseVariable());
        }
        else if(readToken ->datatype == PToken::INTEGER)
        {
            forLoop->adopt(parseIntegerConstant());
        }
        else printSyntax("EXPECTED INTEGER");
    }
    //now current token should be DO
    if(readToken->datatype == PToken::DO)
    {
        readToken = scanner->nextToken();   //CONSUME DO
    }
    else printSyntax("Expected DO");
    //now parse the body of the for loop which is a statment or a group of statements
    //adopt that statement as the loops third child.
    forLoop->adopt(parseStatement());
    return forLoop;
}

ParserNode *Parser::parseIf()
{
    Parser *ifNode = new Parser(Nodetype::IF);
    readToken = scanner->nextToken();  

    ifNode->adopt(parseExpression());

    if (readToken->type != THEN) syntaxError("Look for THEN");
    else
    {
        readToken = scanner->nextToken();  
    }

    ifNode->adopt(parseStatement());

    if (readToken->type == ELSE)
    {
        readToken = scanner->nextToken();  
        ifNode->adopt(parseStatement());
    }

    return ifNode;
}

ParserNode *Parser::parseCase()
{
    Parser *switchNode = new Parser(SWITCH);
    readToken = scanner->nextToken();  

    Parser *expr = parseExpression();
    switchNode->adopt(expr);

    if (readToken->type == OF)
    {
        readToken = scanner->nextToken();  
    }
    else syntaxError("Look for OF");

    while (   (readToken->type == INTEGER)
           || (readToken->type == PLUS) || (readToken->type == MINUS))
    {
        Parser *branch = new Parser(SELECT_BRANCH);
        Parser *constant = new Parser(SELECT_CONSTANTS);
        switchNode->adopt(branch);
        branch->adopt(constant);

        do
        {
            bool negate = false;
            if ((readToken->type == PLUS) || (readToken->type == MINUS))
            {
                negate = readToken->type == MINUS;
                readToken = scanner->nextToken();  
            }

            Parser *realConstant = parseIntegerConstant();
            if (negate) realConstant-> TokenValue = -(realConstant-> tokenValueInt);
            realConstant->adopt(realConstant);

            if (readToken->type == COMMA)
            {
                readToken = scanner->nextToken(); 
            }
        } while (readToken->type != COLON);

        readToken = scanner->nextToken();  

        branch->adopt(parseStatement());

        if (readToken->type == SEMICOLON)
        {
            do
            {
                readToken = scanner->nextToken();  
            } while (readToken->type == SEMICOLON);
        }
    }

    if (readToken->type == END)
    {
        readToken = scanner->nextToken();  
    }
    else if (statementStarters.find(readToken->type) != statementStarters.end())
    {
        syntaxError("Missing END");
    }

    return switchNode;
}



