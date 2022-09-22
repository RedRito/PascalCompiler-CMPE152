#include "../Scanner/PToken.h"
#include "Parser.h"
#include <algorithm>

Parser::Parser(Scanner *scanner, Symtab *symtab)    //will cause issues cause not completed symbol table
{
    linenum = 1;
    this -> scanner = scanner;
    this -> symtab = symtab;
    readToken = nullptr;
    errNum = 0;
}

int Parser::getErrNum()
{
    return errNum;
}

string Parser::toLowerCase(string text)
{
    string lower_case(text);
    transform(lower_case.begin(), lower_case.end(),
              lower_case.begin(), ::tolower);
    return lower_case;
}
ParserNode * Parser::parseTheProgram()
{
    //do main parse here
    
    ParserNode *program = new ParserNode(NodeType::PROGRAM);
    
    readToken = scanner->nextToken();
    //cout << "Reading PROGRAM" << endl;
    //cout << readToken ->toString(readToken) << endl;
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
        symtab -> entry(programName);
        program->datatext = programName;
        //read next token
        readToken = scanner->nextToken();
    }
    else
    {
        printSyntax("Expecting PROGRAM Identifier");
    }
    //after PROGRAM proName; there is a semicolon, consume it
    if(readToken->datatype == PToken::SEMICOLON)
    {
        readToken = scanner->nextToken();
    }
    else
    {
        printSyntax("Missing ; ");
    }
    //if there is var list, parse and adopt it
    if(readToken->datatype == PToken::VAR)
    {
        ParserNode *var = new ParserNode(NodeType::VAR);
        readToken = scanner->nextToken(); //consume var, we wont be doing declarations yet.
        if(readToken->datatype != PToken::IDENTIFIER)
        {
            printSyntax("Expected Identifier");
        }
        else
        {
            parseDeclarationBlock(var); //parse all the things between VAR and BEGIN which should
            program->adopt(var);
        }
    }
    //cout << "PARSING BEGIN NOW" << endl;
    if(readToken->datatype == PToken::BEGIN)
    {
        program->adopt(parseCompoundStatement());
        //cout << "I AM HERE NOW" << endl;
        //now should be end of the program check for the period "."
        if(readToken->datatype == PToken::SEMICOLON)
        {
            printSyntax("Expecting '.' ");
        }
        else
        readToken = scanner->nextToken(); //consume .
    }
    else printSyntax("MISSING BEGIN");

    return program;
}


void *Parser::parseDeclarationBlock(ParserNode* parent)
{
    while(readToken->datatype != PToken::BEGIN && readToken->datatype != PToken::END_OF_FILE && readToken->datatype == PToken::IDENTIFIER)
    {
        // cout << "PARSING DECLARATION" << endl;
        // cout << readToken ->toString(readToken) << endl;
        ParserNode* declare = new ParserNode(NodeType::VAR_DECLARATION);
        ParserNode* leftSide = new ParserNode(NodeType::VARIABLE);
        string variableName = readToken->datatext;
        SymtabEntry *varId = symtab->entry(toLowerCase(variableName));
        leftSide->datatext = variableName;
        leftSide->entry = varId;
        declare->adopt(leftSide);
        
        readToken = scanner->nextToken();   //consume variable identifier
        
        //cout << readToken ->toString(readToken) << endl;
        if(readToken->datatype == PToken::COLON)
        {
            readToken = scanner->nextToken(); //consume colon
        }
        else printSyntax("Missing : ");
        
        ParserNode *rightSide = new ParserNode(NodeType::INTEGER);
        readToken = scanner->nextToken(); //CONSUME TYPE
        declare->adopt(rightSide);
        
        parent->adopt(declare);
        //now read token should be a semicolon
        if(readToken->datatype == PToken::SEMICOLON)
        {
            readToken = scanner->nextToken(); //consume semicolon
        }
        else printSyntax("Missing ;");
        //cout << readToken ->toString(readToken) << endl;
    }
    if(readToken->datatype != PToken::IDENTIFIER && readToken->datatype != PToken::BEGIN && readToken->datatype != PToken::END_OF_FILE) printSyntax("missing identifier");
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
        case PToken::SEMICOLON :  statement = nullptr; break;  // empty statement
        default : printSyntax("Unexpected token");
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
    compoundNode->linenum = readToken->linenum;
    readToken = scanner->nextToken();  // consume BEGIN
    parseAllStatements(compoundNode, PToken::END);
    if (readToken->datatype == PToken::END)
    {
        readToken = scanner->nextToken();  // consume END
    }
    else printSyntax("Expecting END");
    return compoundNode;
}


ParserNode *Parser::parseAssignmentStatement()
{
    // The current token should now be the left-hand-side variable name.
    //cout << "PARSING ASSIGNMENT" << endl;
    ParserNode *assignmentNode = new ParserNode(NodeType::ASSIGN);
    // The assignment Node *adopts the variable Node *as its first child.
    ParserNode *lhsNode = new ParserNode(NodeType::VARIABLE);
    string variableName = readToken->datatext;
    SymtabEntry *variableId = symtab->entry(toLowerCase(variableName));
    
    lhsNode->datatext  = variableName;
    lhsNode->entry = variableId;
    lhsNode->linenum = readToken->linenum;
    assignmentNode->adopt(lhsNode);

    readToken = scanner->nextToken();  // consume the LHS variable;
    //cout << readToken ->toString(readToken) << endl;
    if (readToken->datatype == PToken::ASSIGN)
    {
        readToken = scanner->nextToken();  // consume :=
        
    }
    else printSyntax("Missing :=");
    // The assignment Node *adopts the expression Node *as its second child.
    //cout << "TOKEN AFTER ASIGN IS " << readToken->toString(readToken) << endl;
    ParserNode*rhsNode = parseExpression();
    assignmentNode->adopt(rhsNode);
    return assignmentNode; 
}



ParserNode *Parser::parseRepeatStatement()
{
    //cout << "PARSING REPEAT" << endl;
    // The current token should now be REPEAT.

    // Create a LOOP node->
    ParserNode *loopNode = new ParserNode(NodeType::LOOP);
    readToken = scanner->nextToken();  // consume REPEAT

    parseAllStatements(loopNode, PToken::UNTIL);

    if (readToken->datatype == PToken::UNTIL)
    {
        // Create a TEST node-> It adopts the test expression node->
        ParserNode *testNode = new ParserNode(NodeType::TEST);
        linenum = readToken->linenum;
        testNode->linenum = linenum;
        readToken = scanner->nextToken();  // consume UNTIL

        testNode->adopt(parseExpression());

        // The LOOP Node *adopts the TEST Node *as its final child.
        loopNode->adopt(testNode);
    }
    else printSyntax("Expecting UNTIL");

    return loopNode;
}

ParserNode* Parser::parseWriteStatement()
{
    // The current token should now be WRITE.

    // Create a WRITE node-> It adopts the variable or string node->
    ParserNode *writeNode = new ParserNode(NodeType::WRITE);
    readToken = scanner->nextToken();  // consume WRITE

    parseAllWrite(writeNode);
    if (writeNode->childrenList.size() == 0)
    {
        printSyntax("Invalid WRITE statement");
    }
    return writeNode;
}

ParserNode *Parser::parseWritelnStatement()
{
    // The current token should now be WRITELN.

    // Create a WRITELN node-> It adopts the variable or string node->
    ParserNode *writelnNode = new ParserNode(NodeType::WRITELN);
    readToken = scanner->nextToken();  // consume WRITELN

    if (readToken->datatype == PToken::LPAREN) parseAllWrite(writelnNode);
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
            
            default: printSyntax("Unexpected token");
        }

        //ParserNode *opNode = tokenType == PToken::EQUAL ? new ParserNode(NodeType::EQ): tokenType == PToken::LT ? new ParserNode(NodeType::LT): nullptr;

        readToken = scanner->nextToken();  // consume relational operator

        // The relational operator Node *adopts the first simple expression
        // Node *as its first child and the second simple expression node
        // as its second child. Then it becomes the expression's root node->
        if (opnode != nullptr)
        {
            opnode->adopt(exprNode);
            opnode->adopt(parseSimpleExpression());
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
    while (simpleExpressionOperators.find(readToken->datatype) != simpleExpressionOperators.end())
    {
        ParserNode *opNode;
        //ParserNode *opNode = readToken->datatype == PToken::PLUSOP ? new ParserNode(NodeType::ADD): new ParserNode(NodeType::SUBTRACT);
        //cout << "CURRENT SIMPLE EXPRESS OP IS " << readToken->toString(readToken) << endl;
        switch (readToken->datatype)
        {
            case PToken::PLUSOP: opNode = new ParserNode(NodeType::ADD); break;
            case PToken::MINUSOP: opNode = new ParserNode(NodeType::SUBTRACT); break;
            case PToken::OR: opNode = new ParserNode(NodeType::OR); break;
            
            default: printSyntax("Unexpected token");;
        }
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
    realConst -> NodeValueInt = readToken -> getInt();
    realConst -> NodeValueReal = readToken -> getReal();
    realConst -> NodeValueString = readToken -> getString();
    realConst -> NodeValueBoolean = readToken -> getBool();

    readToken = scanner ->nextToken();
    return realConst;
}

/*
    Parse the current token which is a string
*/
ParserNode *Parser::parseStringConstant()
{
    ParserNode *realConst = new ParserNode(NodeType::STRING_CONSTANT);
    realConst -> NodeValueInt = readToken -> getInt();
    realConst -> NodeValueReal = readToken -> getReal();
    realConst -> NodeValueString = readToken -> getString();
    realConst -> NodeValueBoolean = readToken -> getBool();

    readToken = scanner ->nextToken();
    return realConst;
}

/*
    Parser::parseIntegerConstant()
*/
ParserNode *Parser::parseIntegerConstant()
{
    ParserNode *realConst = new ParserNode (NodeType::INTEGER_CONSTANT);
    realConst -> NodeValueInt = readToken -> getInt();
    realConst -> NodeValueReal = readToken -> getReal();
    realConst -> NodeValueString = readToken -> getString();
    realConst -> NodeValueBoolean = readToken -> getBool();

    readToken = scanner->nextToken();
    return realConst;
}

ParserNode *Parser::parseTerm()
{
    ParserNode *currTerm = parseFactor();
    while(termOperators.find(readToken->datatype) != termOperators.end())
    {
        ParserNode *opNode;
        switch (readToken->datatype)
        {
            case PToken::MULTOP: opNode = new ParserNode(NodeType::MULTIPLY); break;
            case PToken::DIV: opNode = new ParserNode(NodeType::DIVIDE); break;
            case PToken::DIVOP: opNode = new ParserNode(NodeType::FLOAT_DIVIDE); break;
            case PToken::AND: opNode = new ParserNode(NodeType::AND); break;
            
            default: printSyntax("Unexpected token");
        }
        // if(ParserNode *opNode = currentToken->datatype == STAR)
        // {
        //     new ParserNode(NodeType::MULTIPLY);
        // }
        // else
        // {
        //     new ParserNode(NodeType::DIVIDE);
        // }
        readToken= scanner->nextToken();   //consume the operator
        opNode->adopt(currTerm);
        opNode->adopt(parseFactor());
        currTerm = opNode;
    }
    return currTerm;
}

ParserNode *Parser::parseFactor()
{
    if(readToken->datatype == PToken::IDENTIFIER)
    {
        return parseVariable();
    }
    else if(readToken->datatype == PToken::INTEGER)
    {
        return parseIntegerConstant();
    }
    else if(readToken->datatype == PToken::REAL)
    {
        return parseRealConstant();
    }
    else if(readToken->datatype == PToken::LPAREN)
    {
        readToken = scanner->nextToken();
        ParserNode *exprNode = parseExpression();     //add in after parseExpression is written!
        if(readToken->datatype == PToken::RPAREN)
        {
            readToken = scanner->nextToken();
        }
        else
        {
            printSyntax("Expecting )");
        }
        return exprNode;                        //add in after parseExpression is written!
    }
    else if(readToken ->datatype == PToken::NOT)
    {
        return parseNOT();
    }
    else if(readToken->datatype == PToken::MINUSOP)
    {
        //parsing a negative num
        ParserNode *negativeNum = new ParserNode(NodeType::NEGATE);
        readToken = scanner->nextToken(); //consume the negative op
        if(readToken -> datatype == PToken::INTEGER)
        {
            negativeNum->adopt(parseIntegerConstant());
            return negativeNum;
        }
        else if(readToken->datatype == PToken::REAL)
        {
            negativeNum->adopt(parseRealConstant());
            return negativeNum;
        }
        else printSyntax("UNEXPECTED MINUS");
    }
    else
    {
        printSyntax("Unexpected token");
    }
    return nullptr;
}

ParserNode *Parser::parseNOT()
{
    //current token should be NOT operator
    ParserNode *notNode = new ParserNode(NodeType::NOT);
    linenum = readToken->linenum;
    notNode->linenum = linenum;
    readToken = scanner->nextToken(); //consume NOT;
    //not adopts the factor as its first child
    notNode->adopt(parseExpression());
    return notNode;
}

ParserNode *Parser::parseVariable()
{
    //cout << "parsing variable " << readToken->toString(readToken) << endl;
    string varName = readToken->datatext;
    //cout << "variable text " << readToken->datatext << endl;
    SymtabEntry *varID = symtab->lookup(toLowerCase(varName));    //needs to test lookup func
    if(varID == nullptr)
    {
        printSematic("Undeclared identifier");
    }
    ParserNode *tempNode = new ParserNode(NodeType::VARIABLE);
    tempNode->datatext = varName;
    readToken = scanner->nextToken();
    //cout << "after variable next token is " << readToken->toString(readToken) << endl;
    return tempNode;
}

void Parser::printSyntax(string msg)
{
    cout << "Syntax error at line " << linenum << " " << msg << " " << readToken -> toString(readToken) << endl;
    errNum ++;
    while (statementFollowers.find(readToken->datatype) == statementFollowers.end())
    {
        //cout << "going to the next token ";
        readToken = scanner->nextToken();
        //cout << readToken->toString(readToken) << endl;
    }
}

void Parser::printSematic(string msg)
{
    cout << "Sematic error at line " << linenum << " " << msg << " " << readToken -> toString(readToken);
    errNum++;
}

void Parser::parseAllStatements(ParserNode *parent, PToken tokenType)
{
    //parse all statments in statment list
    //while not end of file and not 
    //cout << "PARSING ALL STATEMENTS" << endl;
    while( (readToken -> datatype != PToken::END_OF_FILE) && (readToken -> datatype != tokenType))
    {
        
        ParserNode *node = parseStatement();
        //cout << readToken ->toString(readToken) << endl;
        if(node != nullptr)
        {
            parent -> adopt(node);
        }

        if(readToken -> datatype == PToken::SEMICOLON)
        {
            while(readToken ->datatype == PToken::SEMICOLON)
            {
                readToken = scanner ->nextToken();
                //cout << "CONSUMING SEMICOLON" << endl;
                //cout << "next token after semicolon is " << readToken->toString(readToken) << endl;
            }
        }
        else if(statementStarters.find(readToken->datatype) == statementStarters.end())
        {
            //cout << "NO STATEMENT STARTER FOUND " << endl;
            printSyntax("missing a ;");
            break;
        }
        //cout << readToken ->toString(readToken) << endl;

    }
}
//ex. Writeln('this is a writeln statement and this is the integer ', num);
void Parser::parseAllWrite(ParserNode *currentNode)
{
    //cout << "PARSING ALL WRITE" << endl;
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
    else if(readToken ->datatype == PToken::STRING || readToken->datatype == PToken::CHARACTER)
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
        //while there are comma's parse the expression
        while(readToken->datatype == PToken::COMMA)
        {
            readToken = scanner -> nextToken(); //eat the ,
            //the next token is either a string or expression, parse it and add it to the parent's child.
            if(readToken->datatype == PToken::STRING)
            {
                currentNode->adopt(parseStringConstant()); 
            }
            else currentNode->adopt(parseExpression()); //parse what comes after the comma
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
    ParserNode *loop = new ParserNode(NodeType::WHILE);
    //consume while
    readToken = scanner -> nextToken();
    //the next token is the condition
    //test node tests the expression
    ParserNode *testCodition = new ParserNode(NodeType::TEST);
    //parse the expression in between while and do
    testCodition->adopt(parseExpression());
    linenum = readToken->linenum;
    testCodition->linenum = linenum;
    //parseAllStatements(loop, PToken::DO);
    //loop node first child should now be the condidion
    //current token is now DO //if not throw an error
    //cout << "I AM IN WHILE LOOP" << endl;
    loop->adopt(testCodition);
    if(readToken->datatype == PToken::DO)
    {
        readToken = scanner->nextToken(); //consumes DO
        //parse what comes after the DO,
        //dont have to worry about the BEGIN, END parseing the expression will solve that issue
        //test adopts the entire loop expression
        loop->adopt(parseStatement());
        //while loop adopts the expression as its second child.
        
    }
    else printSyntax("Expected DO");
    return loop;
}
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
    // Create IF node
    ParserNode *ifNode = new ParserNode(NodeType::IF);
    // Consume IF
    readToken = scanner->nextToken();  
    //IF adopts the expression subtree as its first child
    ifNode->adopt(parseExpression());

    if (readToken->datatype != PToken::THEN) 
        printSyntax("Look for THEN");
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
    ParserNode *switchNode = new ParserNode(NodeType::SWITCH);
    // Consume SWITCH
    readToken = scanner->nextToken();  

    //SWITCH adopts the expression subtree
    ParserNode *expr = parseExpression();
    switchNode->adopt(expr);

    if (readToken->datatype == PToken::OF)
    {
        // Consume OF
        readToken = scanner->nextToken();  
    }
    else printSyntax("Look for OF");

    while (   (readToken->datatype == PToken::INTEGER) 
    || (readToken->datatype == PToken::PLUSOP) || (readToken->datatype == PToken::MINUSOP))
    {
        // SWITCH adopts SELECT_BRANCH
        // SELECT_BRANCH adopts SELECT_CONSTANTS
        ParserNode *branch = new ParserNode(NodeType::SELECT_BRANCH);
        ParserNode *constant = new ParserNode(NodeType::SELECT_CONSTANTS);
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

            ParserNode *constantNode = parseIntegerConstant();
            if (negate) constantNode-> NodeValueInt = -(constantNode-> NodeValueInt);
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
        printSyntax("Missing END");
    }

    return switchNode;
}




