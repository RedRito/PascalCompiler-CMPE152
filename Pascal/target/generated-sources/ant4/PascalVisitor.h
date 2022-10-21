
// Generated from Pascal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "PascalParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PascalParser.
 */
class  PascalVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PascalParser.
   */
    virtual antlrcpp::Any visitProgram(PascalParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitProgramHead(PascalParser::ProgramHeadContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(PascalParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitLabel(PascalParser::LabelContext *context) = 0;

    virtual antlrcpp::Any visitConstantVar(PascalParser::ConstantVarContext *context) = 0;

    virtual antlrcpp::Any visitConstantChr(PascalParser::ConstantChrContext *context) = 0;

    virtual antlrcpp::Any visitConstant(PascalParser::ConstantContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedNumber(PascalParser::UnsignedNumberContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedInteger(PascalParser::UnsignedIntegerContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedReal(PascalParser::UnsignedRealContext *context) = 0;

    virtual antlrcpp::Any visitSign(PascalParser::SignContext *context) = 0;

    virtual antlrcpp::Any visitBool_(PascalParser::Bool_Context *context) = 0;

    virtual antlrcpp::Any visitTypeIdentifier(PascalParser::TypeIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitString(PascalParser::StringContext *context) = 0;

    virtual antlrcpp::Any visitSimpleType(PascalParser::SimpleTypeContext *context) = 0;

    virtual antlrcpp::Any visitScalarType(PascalParser::ScalarTypeContext *context) = 0;

    virtual antlrcpp::Any visitStringtype(PascalParser::StringtypeContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierList(PascalParser::IdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitStatement(PascalParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitUnlabelledStatement(PascalParser::UnlabelledStatementContext *context) = 0;

    virtual antlrcpp::Any visitSimpleStatement(PascalParser::SimpleStatementContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentStatement(PascalParser::AssignmentStatementContext *context) = 0;

    virtual antlrcpp::Any visitVariable(PascalParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitExpression(PascalParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationaloperator(PascalParser::RelationaloperatorContext *context) = 0;

    virtual antlrcpp::Any visitSimpleExpression(PascalParser::SimpleExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveoperator(PascalParser::AdditiveoperatorContext *context) = 0;

    virtual antlrcpp::Any visitTerm(PascalParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeoperator(PascalParser::MultiplicativeoperatorContext *context) = 0;

    virtual antlrcpp::Any visitSignedFactor(PascalParser::SignedFactorContext *context) = 0;

    virtual antlrcpp::Any visitFactor(PascalParser::FactorContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedConstant(PascalParser::UnsignedConstantContext *context) = 0;

    virtual antlrcpp::Any visitGotoStatement(PascalParser::GotoStatementContext *context) = 0;

    virtual antlrcpp::Any visitStructuredStatement(PascalParser::StructuredStatementContext *context) = 0;

    virtual antlrcpp::Any visitWriteArguments(PascalParser::WriteArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitWriteArgs(PascalParser::WriteArgsContext *context) = 0;

    virtual antlrcpp::Any visitWriteStatement(PascalParser::WriteStatementContext *context) = 0;

    virtual antlrcpp::Any visitWritelnStatement(PascalParser::WritelnStatementContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(PascalParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitStatements(PascalParser::StatementsContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(PascalParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseStatement(PascalParser::CaseStatementContext *context) = 0;

    virtual antlrcpp::Any visitCaseListElement(PascalParser::CaseListElementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(PascalParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitRepeatStatement(PascalParser::RepeatStatementContext *context) = 0;

    virtual antlrcpp::Any visitForStatement(PascalParser::ForStatementContext *context) = 0;

    virtual antlrcpp::Any visitWithStatement(PascalParser::WithStatementContext *context) = 0;


};

