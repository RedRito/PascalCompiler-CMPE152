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
    if(readToken->datatype == PToken::VAR)
    {
        //program->adopt(parseVarDeclarations());
        ParserNode *var = new ParserNode(NodeType::VAR)
        readToken = scanner->nextToken(); //consume var, we wont be doing declarations yet.
        if(readToken->datatype != PToken::IDENTIFIER)
        {
            printSyntax("Expected Identifier");
        }
        else
        {
            parseDeclarationBlock(var, PToken::BEGIN); //parse all the things between VAR and BEGIN which should
            program->adopt(var);
        }
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


ParserNode *Parser::parseDeclarationBlock(ParserNode* parent)
{
    while(readToken->datatype != PToken::BEGIN && readToken->datatype != PToken::END_OF_FILE && readToken->datatype == PToken::IDENTIFIER)
    {
        ParserNode* declare = new ParserNode(NodeType::VAR_DECLARATION);
        ParserNode* leftSide = new ParserNode(NodeType::VARIABLE);
        string variableName = readToken->datatext;
        SymtableEntry *varId = symtab->enter(toLowerCase(variableName));
        leftSide->datatext = variableName;
        leftSide->entry = varId;
        declare->adopt(leftSide);
        
        readToken = scanner->nextToken();   //consume variable identifier
        

        if(readToken->datatype == PToken::COLON)
        {
            readToken = scanner->nextToken(); //consume colon
        }
        else printSyntax("Missing : ");
        
        ParserNode *rightSide = new Parser(NodeType::INTEGER);
        declare->adopt(rightSide);
        
        parent->adopt(declare);
        //now read token should be a semicolon
        if(readToken->datatype == PToken::SEMICOLOR)
        {
            readToken = scanner->nextToken(); //consume semicolon
        }
        else printSyntax("Missing ;");
    }
    else printSyntax("missing identifier");
}


ParserNode *Parser::parseStatement()
{
    ParserNode *statement = nullptr;
    int savedLine = readToken->linenum;
    linenum = savedLine;
    switch (readToken->datatype)
    {
        case PToken::IDENTIFIER : statement = parseAssignmentStatement(); break;    //done
        case PToken::BEGIN :      statement = parseCompoundStatement();   break;   
        case PToken::REPEAT :     statement = parseRepeatStatement();     break;
        case PToken::WHILE :      statement = parseWhile();               break;
        case PToken::IF :         statement = parseIf();                  break;
        case PToken::FOR :        statement = parseFor();                 break;
        case PToken::CASE :       statement = parseCase();                break;
        case PToken::WRITE :      statement = parseWriteStatement();      break;
        case PToken::WRITELN :    statement = parseWritelnStatement();    break;
        case PToken::SEMICOLOR :  statement = nullptr; break;  // empty statement
        default : syntaxError("Unexpected token");
    }

    if(statement != nullptr)
    {
        statement->linenum = savedLine;
    }
    return statement;
}

ParserNode *Parser::parseCompoundStatement()
{
    ParserNode *compoundNode = new ParserNode(NodeType::COMPOUND);
    compoundNode->lineNumber = currentToken->lineNumber;

    readToken = scanner->nextToken();  // consume BEGIN
    parseAllStatements(compoundNode, PToken::END);

    if (readToken->type == PToken::END)
    {
        readToken = scanner->nextToken();  // consume END
    }
    else syntaxError("Expecting END");

    return compoundNode;
}


ParserNode *Parser::parseAssignmentStatement()
{
    // The current token should now be the left-hand-side variable name.

    ParserNode *assignmentNode = new ParserNode(NodeType::ASSIGN);

    // The assignment Node *adopts the variable Node *as its first child.
    ParserNode *lhsNode = new ParserNode(NodeType::VARIABLE);
    string variableName = readToken->datatext;
    SymtabEntry *variableId = symtab->enter(toLowerCase(variableName));

    lhsNode->text  = variableName;
    lhsNode->entry = variableId;
    assignmentNode->adopt(lhsNode);

    readToken = scanner->nextToken();  // consume the LHS variable;

    if (readToken->type == PToken::ASSIGN)
    {
        readToken = scanner->nextToken();  // consume :=
    }
    else syntaxError("Missing :=");

    // The assignment Node *adopts the expression Node *as its second child.
    ParserNode*rhsNode = parseExpression();
    assignmentNode->adopt(rhsNode);

    return assignmentNode; 
}



ParserNode *Parser::parseRepeatStatement()
{
    // The current token should now be REPEAT.

    // Create a LOOP node->
    ParserNode *loopNode = new ParserNode(NodeType::LOOP);
    readToken = scanner->nextToken();  // consume REPEAT

    parseStatementList(loopNode, PToken::UNTIL);

    if (currentToken->type == PToken::UNTIL)
    {
        // Create a TEST node-> It adopts the test expression node->
        ParserNode *testNode = new ParserNode(NodeType::TEST);
        linenum = currentToken->lineNumber;
        testNode->lineNumber = linenum;
        readToken = scanner->nextToken();  // consume UNTIL

        testNode->adopt(parseExpression());

        // The LOOP Node *adopts the TEST Node *as its final child.
        loopNode->adopt(testNode);
    }
    else syntaxError("Expecting UNTIL");

    return loopNode;
}

ParserNode* Parser::parseWriteStatement()
{
    // The current token should now be WRITE.

    // Create a WRITE node-> It adopts the variable or string node->
    ParserNode *writeNode = new ParserNode(NodeType::WRITE);
    readToken = scanner->nextToken();  // consume WRITE

    parseAllWrite(writeNode);
    if (writeNode->children.size() == 0)
    {
        syntaxError("Invalid WRITE statement");
    }
    return writeNode;
}

ParserNode *Parser::parseWritelnStatement()
{
    // The current token should now be WRITELN.

    // Create a WRITELN node-> It adopts the variable or string node->
    ParserNode *writelnNode = new ParserNode(NodeType::WRITELN);
    readToken = scanner->nextToken();  // consume WRITELN

    if (currentToken->type == PToken::LPAREN) parseAllWrite(writelnNode);
    return writelnNode;
}

ParserNode *Parser::parseExpression()
{
    // The expression's root node->
    ParserNode *exprNode = parseSimpleExpression();

    // The current token might now be a relational operator.
    if (relationalOperators.find(readToken->datatype) != relationalOperators.end())
    {
        PToken tokenType = readToken->datatype;
        ParserNode *opnode;
        switch (tokenType)
        {
            case PToken::EQUAL: opnode = new ParserNode(NodeType::EQ); break;
            case PToken::NE: opnode = new ParserNode(NodeType::NE); break;
            case PToken::LT: opnode = new ParserNode(NodeType::LT); break;
            case PToken::LTEQ: opnode = new ParserNode(NodeType::LTEQ); break;
            case PToken::GT: opnode = new ParserNode(NodeType::GT); break;
            case PToken::GTEQ: opnode = new ParserNode(NodeType::GTEQ); break;
            
            default: syntaxError("Unexpected token");
        }

        //ParserNode *opNode = tokenType == PToken::EQUAL ? new ParserNode(NodeType::EQ): tokenType == PToken::LT ? new ParserNode(NodeType::LT): nullptr;

        readToken = scanner->nextToken();  // consume relational operator

        // The relational operator Node *adopts the first simple expression
        // Node *as its first child and the second simple expression node
        // as its second child. Then it becomes the expression's root node->
        if (opnode != nullptr)
        {
            opNode->adopt(exprNode);
            opNode->adopt(parseSimpleExpression());
            exprNode = opnode;
        }
    }

    return exprNode;
}

ParserNode *Parser::parseSimpleExpression()
{
    // The current token should now be an identifier or a number.

    // The simple expression's root node->
    ParserNode *simpExprNode = parseTerm();

    // Keep parsing more terms as long as the current token
    // is a + or - operator.
    while (simpleExpressionOperators.find(readToken->datatype) !=
                                                simpleExpressionOperators.end())
    {
        ParserNode *opNode = readToken->datatype == PToken::PLUSOP ? new ParserNode(NodeType::ADD)
                                                : new ParserNode(NodeType::SUBTRACT);

        readToken = scanner->nextToken();  // consume the operator

        // The add or subtract Node *adopts the first term Node *as its
        // first child and the next term Node *as its second child.
        // Then it becomes the simple expression's root node->
        opNode->adopt(simpExprNode);
        opNode->adopt(parseTerm());
        simpExprNode = opNode;
    }

    return simpExprNode;
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
    while(termOperators.find(currentToken->datatype) != termOperators.end())
    {
        if(ParserNode *opNode = currentToken->datatype == STAR)
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
    if(currentToken->datatype == NodeType::IDENTIFIER)
    {
        return parseVariable();
    }
    else if(currentToken->datatype == NodeType::INTEGER)
    {
        return parseIntegerConstant();
    }
    else if(currentToken->datatype == NodeType::REAL)
    {
        return parseRealConstant();
    }
    else if(currentToken->datatype == NodeType::LPAREN)
    {
        currentToken->datatype = scanner->nextToken();
        //ParserNode *exprNode = parseExpression();     //add in after parseExpression is written!
        if(currentToken->datatype == NodeType::RPAREN)
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
    while (statementFollowers.find(currentToken->datatype) == statementFollowers.end())
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

ParserNode *Parser::parseWhile()
{
    Parser *loop = new Parser(LOOP);
    readToken = scanner -> nextToken();

    Parser *test = new Parser(TEST);
    Parser *notNode = new Parser(Nodetype::NOT);
    loop -> adopt(test);
    test -> adopt(notNode);

    notNode -> adopt (parseExpression());

    if (readToken -> datatype != DO)
    syntaxError ("Look for DO");
    else 
    {
        readToken = scanner -> nextToken();
    }
    loop -> adopt(parseStatement);
    return loop;
}

ParserNode *Parser::parseFor()
{
    Parser *compound = new Parser(COMPOUND);
    readToken = scanner -> nextToken();

    Parser *assign = parseAssignmentStatement();
    compound -> adopt(assign);

    Parser *control = assign ->children[0];

    Parser *loop = new Parser(LOOP);
    compound -> adopt(loop);

    Parser *test = new Parser(TEST);
    loop -> adopt(test);

    bool countUp = true;
    if (readToken -> datatype == TO)
    {
        readToken = scanner -> nextToken();
    }
    else if (readToken -> datatype == DOWNTO)
    {
        countUp = false;
        readToken = scanner -> nextToken();
    }
    else syntaxError("Look for TO or DOWNTO");

    Parser *compare = countUp ? new Parser(GT) : new Parser(LT);
    test -> adopt(compare);
    compare -> adopt(parseExpression());

    if (readToken -> datatype == DO)
    {
        readToken = scanner -> nextToken();
    }
    else syntaxError("Look for DO");

    loop -> adopt(parseStatement());

    assign = new Parser(ASSIGN);
    loop->adopt(assign);
    assign->adopt(control->copy());
    Parser *op = countUp ? new Parser(ADD) : new Parser(SUBTRACT);
    assign->adopt(op);
    op->adopt(control->copy());
    Parser *one = new Parser(INTEGER_CONSTANT);
    one -> tokenValueInt = 1;
    op->adopt(one);

    return compound;

}

ParserNode *Parser::parseIf()
{
    // Create IF node
    Parser *ifNode = new Parser(Nodetype::IF);
    // Consume IF
    readToken = scanner->nextToken();  
    //IF adopts the expression subtree as its first child
    ifNode->adopt(parseExpression());

    if (readToken->datatype != PToken::THEN) 
        syntaxError("Look for THEN");
    else
    {
        // Consume THEN
        readToken = scanner->nextToken();  
    }

    //IF adopts THEN as its second child
    ifNode->adopt(parseStatement());

    //if ELSE appears as a reserved word
    //IF adopts ELSE as its third child
    if (readToken->datatype == PToken::ELSE)
    {
        // Consume ELSE
        readToken = scanner->nextToken();  
        ifNode->adopt(parseStatement());
    }

    return ifNode;
}

ParserNode *Parser::parseCase()
{
    // Create SWITCH node
    Parser *switchNode = new Parser(NodeType::SWITCH);
    // Consume SWITCH
    readToken = scanner->nextToken();  

    //SWITCH adopts the expression subtree
    Parser *expr = parseExpression();
    switchNode->adopt(expr);

    if (readToken->datatype == PToken::OF)
    {
        // Consume OF
        readToken = scanner->nextToken();  
    }
    else syntaxError("Look for OF");

    while (   (readToken->datatype == PToken::INTEGER) 
    || (readToken->datatype == PToken::PLUSOP) || (readToken->datatype == PToken::MINUSOP))
    {
        // SWITCH adopts SELECT_BRANCH
        // SELECT_BRANCH adopts SELECT_CONSTANTS
        Parser *branch = new Parser(NodeType::SELECT_BRANCH);
        Parser *constant = new Parser(NodeType::SELECT_CONSTANTS);
        switchNode->adopt(branch);
        branch->adopt(constant);

        do
        {
            bool negate = false;
            if ((readToken->datatype == PToken::PLUSOP) || (readToken->datatype == PToken::MINUSOP))
            {
                negate = readToken->datatype == PToken::MINUSOP;
                // Consume plus or minus
                readToken = scanner->nextToken();  
            }

            Parser *constantNode = parseIntegerConstant();
            if (negate) constantNode-> TokenValue = -(constantNode-> tokenValueInt);
            constant->adopt(constantNode);

            if (readToken->datatype == PToken::COMMA)
            {
                // Consume comma
                readToken = scanner->nextToken(); 
            }
        } while (readToken->datatype != PToken::COLON);
        // Consume :
        readToken = scanner->nextToken();  

        branch->adopt(parseStatement());

        if (readToken->datatype == PToken::SEMICOLON)
        {
            do
            {
                // Consume semicolon
                readToken = scanner->nextToken();  
            } while (readToken->datatype == PToken::SEMICOLON);
        }
    }

    if (readToken->datatype == PToken::END)
    {
        // Consume END
        readToken = scanner->nextToken();  
    }
    else if (statementStarters.find(readToken->datatype) != statementStarters.end())
    {
        syntaxError("Missing END");
    }

    return switchNode;
}




