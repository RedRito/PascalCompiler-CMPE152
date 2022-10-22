#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>


using namespace std;
using namespace std::chrono;

antlrcpp::Any TreeVisitor1::visitProgram(PascalParser::ProgramContext *ctx)
{
    cout << "Visiting program" << endl;
    return visit(ctx->block());
}

antlrcpp::Any TreeVisitor1::visitStatement(PascalParser::StatementContext *ctx) 
{
    cout << "Line " << ctx->getStart()->getLine() << ": ";
    return visitChildren(ctx);
}

antlrcpp::Any TreeVisitor1::visitAssignmentStatement(PascalParser::AssignmentStatementContext *ctx) 
{
    cout << "Visiting Assignment Statement" << endl;
    string variableName = ctx->variable()->getText();
    visit(ctx->variable());
    ParserNode value = visit(ctx->expression());

    cout << "Will assign value " << value.as<int>()
         << " to variable " << variableName << endl;
    return nullptr;
}

antlrcpp::Any TreeVisitor1::visitVariable(PascalParser::VariableContext *ctx) 
{
    /* Incomplete */
}

antlrcpp::Any TreeVisitor1::visitExpression(PascalParser::ExpressionContext *ctx) 
{
    /* Need revision */
    cout << "Visiting expression statement" << endl;

    PascalParser::SimpleExpressionContext *simpleCtx1 = ctx->simpleExpression(0);
    PascalParser::RelOpContext *relOpCtx = ctx->relationaloperator();
    string operand1 = visit(simpleCtx1).as<string>();

    if (relOpCtx != nullptr) {
        string op = relOpCtx->getText();
        PascalParser::SimpleExpressionContext *simpleCtx2 = ctx->simpleExpression(1);
        string operand2 = visit(simpleCtx2).as<string>();

        double val1 = stod(operand1);
        double val2 = stod(operand2);
        bool result=false;

        if(op == "=")
            result = (val1 == val2);
        else if (op == "<>")
            result = (val1 != val2);
        else if (op == "<")
            result = (val1 < val2);
        else if (op == ">")
            result = (val1 > val2);
        else if (op == "<=")
            result = (val1 <= val2);
        else if (op == ">=")
            result = val1 >= val2;
        //no default case

        if(result)
            return string("T");
        return string("F");
    }

    return operand1; //occurs if the expr was just a simple expr

}

antlrcpp::Any TreeVisitor1::visitTerm(PascalParser::TermContext *ctx) 
{
    //number of factors
    int count = ctx->signedFactor().size();

    PascalParser::FactorContext *factorCtx1 = ctx->signedFactor(0);
    string operand1 = visit(factorCtx1).as<string>();

    for(int i=1; i<count; i++) {
        string op = toLowerCase(ctx->multiplicativeoperator(i-1)->getText());
        PascalParser::FactorContext *factorCtx2 = ctx->signedFactor(i);
        string operand2 = visit(factorCtx2).as<string>();

        //possible operators are only AND, *, / DIV, MOD
        if( (operand2=="T")||(operand2=="F") ) { //if opd2 is a bool
            if( (operand1=="T") && (operand2=="T") ) //AND op1 and op2
                operand1 = string("T");
            else 
                operand1 = string("F"); 
        }
        else {
            double val1 = stod(operand1);
            double val2 = stod(operand2);

            if(op=="MULTOP") {
                operand1 = to_string( val1*val2 );
            }
            else if(op=="DIVOP") { //check /, DIV, MOD operations
                operand1 = to_string( val1/val2 );
            }
            else if(op=="DIV") {
                operand1 = to_string( trunc(val1/val2) );
            }
            else if(op=="MOD") {
                operand1 = to_string (int(val1) % int(val2));
            }
        }
    }
    return operand1;

} 
 
antlrcpp::Any TreeVisitor1::visitWriteStatement(PascalParser::WriteStatementContext *ctx) 
{
    /* Need revision */
    cout << "Visiting WRITE statement" << endl;
    visitChildren(ctx);
    return nullptr;

} 
    
antlrcpp::Any TreeVisitor1::visitWritelnStatement(PascalParser::WritelnStatementContext *ctx) 
{
    /* Need revision */
    cout << "Visiting WRITELN statement" << endl;
    visitChildren(ctx);
    cout << endl;
    return nullptr;

} 
    
antlrcpp::Any TreeVisitor1::visitCompoundStatement(PascalParser::CompoundStatementContext *ctx) 
{
    cout << "Visiting Compound Statement" << endl;
    return visit(ctx->statements());

} 
            
antlrcpp::Any TreeVisitor1::visitIfStatement(PascalParser::IfStatementContext *ctx) 
{
    //ifStatement: IF expression THEN statement (: ELSE statement)?;
	cout << "Visiting if statement" << endl;

	PascalParser::ExpressionContext *ctx1 = ctx->expression();
	PascalParser::TruestatementContext *truectx = ctx->statement();
	PascalParser::FalsestatementContext *falsectx = ctx->statement();

	visit(ctx1);

	visit(truectx);

	if(falsectx != nullptr)
		visit(falsectx);

	return nullptr;

} 
    
antlrcpp::Any TreeVisitor1::visitCaseStatement(PascalParser::CaseStatementContext *ctx) 
{
    /* Need revision */
    //caseStatement: CASE expression OF caseListElement (SEMICOLON caseListElement)* (SEMICOLON ELSE statements)? END;
    cout << "Visiting case statement" << endl;

    bool match = false;
    long caseValue = (long) stod(visit(ctx->expression()).as<string>());

    PascalParser::CaseBranchListContext *branchlistCtx = ctx->caseBranchList();
    for (PascalParser::CaseBranchContext *branchCtx : branchlistCtx->caseBranch())
    {
        PascalParser::CaseConstantListContext *constListCtx = branchCtx->caseConstantList();

        for (PascalParser::CaseConstantContext *caseConstCtx : constListCtx->caseConstant())
        {
            bool negate = (caseConstCtx->sign() != nullptr) && (caseConstCtx->sign()->getText() == "-");
            long constValue = (long) stod(visit(caseConstCtx->unsignedNumber()).as<string>());
            if (negate)
            {
                constValue = -constValue;
            }

            if (caseValue == constValue)
            {
                visit(branchCtx->statement());
                match = true;
                break;
            }
        }

        if (match)
        {
            break;
        }
    }
    return nullptr;

} 
            
antlrcpp::Any TreeVisitor1::visitWhileStatement(PascalParser::WhileStatementContext *ctx) 
{
    //whileStatement: WHILE expression DO statement;
    cout << "Visiting WHILE statement" << endl;

    PascalParser::StatementContext *stmtCtx = ctx->statement();
    bool value = visit(ctx->expression()).as<string>() == "T";
    while (value) {
        visit(stmtCtx);
        value = visit(ctx->expression()).as<string>() == "T";
    }
    return nullptr;
} 
    
antlrcpp::Any TreeVisitor1::visitRepeatStatement(PascalParser::RepeatStatementContext *ctx) 
{
    //repeatStatement: REPEAT statements UNTIL expression;
    cout << "Visiting REPEAT statement" << endl;

    PascalParser::StatementListContext *listCtx = ctx->statements();
    bool value = false;

    do {
        visit(listCtx);
        string PascalValue = visit(ctx->expression()).as<string>();
        value = (PascalValue=="T");
    } while(!value);

    return nullptr;

} 
    
antlrcpp::Any TreeVisitor1::visitForStatement(PascalParser::ForStatementContext *ctx) 
{
    /* Need Revision */
    //forStatement: FOR identifier ASSIGN forList DO statement;
    //forList: initialValue (TO | DOWNTO) finalValue;
    cout << "Visiting FOR statement" << endl;

	PascalParser::ExpressionContext *ctx1 = ctx->expression(0);

    int start = stoi(ctx1->getText());
    cout << "Will assign value " << start;

    PascalParser::ExpressionContext *simpleCtx = ctx->expression(0); /
    int end = stoi(simpleCtx->getText());
    cout << "Will assign value " << end;

    if(ctx->TO()->getText() == "TO")
    {
    	for(int i = start; i < end; i++)
    	{
    		PascalParser::StatementContext *stmtCtx = ctx->statement();
    		visit(stmtCtx);
    	}
    }
    else if(ctx->DOWNTO()->getText()=="DOWNTO")
    {
    	for(int i = start; i < end; i--)
    	{
    	    PascalParser::StatementContext *stmtCtx = ctx->statement();
    	    visit(stmtCtx);
    	}
    }

    return nullptr;

} 

antlrcpp::Any visitProgramHead(PascalParser::ProgramHeadContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitBlock(PascalParser::BlockContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitIdentifier(PascalParser::IdentifierContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitLabel(PascalParser::LabelContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitConstantVar(PascalParser::ConstantVarContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitConstantChr(PascalParser::ConstantChrContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitConstant(PascalParser::ConstantContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitUnsignedNumber(PascalParser::UnsignedNumberContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitUnsignedInteger(PascalParser::UnsignedIntegerContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitUnsignedReal(PascalParser::UnsignedRealContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitSign(PascalParser::SignContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitBool_(PascalParser::Bool_Context *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitTypeIdentifier(PascalParser::TypeIdentifierContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitString(PascalParser::StringContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitSimpleType(PascalParser::SimpleTypeContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitScalarType(PascalParser::ScalarTypeContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitStringtype(PascalParser::StringtypeContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitIdentifierList(PascalParser::IdentifierListContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitConstList(PascalParser::ConstListContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitUnlabelledStatement(PascalParser::UnlabelledStatementContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitSimpleStatement(PascalParser::SimpleStatementContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitRelationaloperator(PascalParser::RelationaloperatorContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitSimpleExpression(PascalParser::SimpleExpressionContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitAdditiveoperator(PascalParser::AdditiveoperatorContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitMultiplicativeoperator(PascalParser::MultiplicativeoperatorContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitSignedFactor(PascalParser::SignedFactorContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitFactor(PascalParser::FactorContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitUnsignedConstant(PascalParser::UnsignedConstantContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitSet_(PascalParser::Set_Context *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitElementList(PascalParser::ElementListContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitElement(PascalParser::ElementContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitGotoStatement(PascalParser::GotoStatementContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitEmptyStatement_(PascalParser::EmptyStatement_Context *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitEmpty_(PascalParser::Empty_Context *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitStructuredStatement(PascalParser::StructuredStatementContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitWriteArguments(PascalParser::WriteArgumentsContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitWriteArgs(PascalParser::WriteArgsContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitStatements(PascalParser::StatementsContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitConditionalStatement(PascalParser::ConditionalStatementContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitCaseListElement(PascalParser::CaseListElementContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitRepetetiveStatement(PascalParser::RepetetiveStatementContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitForList(PascalParser::ForListContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitInitialValue(PascalParser::InitialValueContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitFinalValue(PascalParser::FinalValueContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitWithStatement(PascalParser::WithStatementContext *ctx) {
    return visitChildren(ctx);
  }

antlrcpp::Any visitRecordVariableList(PascalParser::RecordVariableListContext *ctx) {
    return visitChildren(ctx);
  }






    













