#ifndef TREEVISITOR1_H_
#define TREEVISITOR1_H_

#include <iostream>
#include <string>
#include "Pascal/target/generated-sources/ant4/PascalBaseVisitor.h"


class TreeVisitor1 : public PascalBaseVisitor

private:
   

public:
    
    antlrcpp::Any visitProgram(PascalParser::ProgramContext *ctx) override; 
        
    antlrcpp::Any visitStatement(PascalParser::StatementContext *ctx) override; 
                
    antlrcpp::Any visitAssignmentStatement(PascalParser::AssignmentStatementContext *ctx) override; 
        
    antlrcpp::Any visitVariable(PascalParser::VariableContext *ctx) override; 
        
    antlrcpp::Any visitExpression(PascalParser::ExpressionContext *ctx) override; 
                    
    antlrcpp::Any visitTerm(PascalParser::TermContext *ctx) override; 
                          
    antlrcpp::Any visitWriteStatement(PascalParser::WriteStatementContext *ctx) override; 
        
    antlrcpp::Any visitWritelnStatement(PascalParser::WritelnStatementContext *ctx) override; 
        
    antlrcpp::Any visitCompoundStatement(PascalParser::CompoundStatementContext *ctx) override; 
                
    antlrcpp::Any visitIfStatement(PascalParser::IfStatementContext *ctx) override; 
        
    antlrcpp::Any visitCaseStatement(PascalParser::CaseStatementContext *ctx) override; 
                
    antlrcpp::Any visitWhileStatement(PascalParser::WhileStatementContext *ctx) override; 
        
    antlrcpp::Any visitRepeatStatement(PascalParser::RepeatStatementContext *ctx) override; 
        
    antlrcpp::Any visitForStatement(PascalParser::ForStatementContext *ctx) override; 

    antlrcpp::Any visitProgramHead(PascalParser::ProgramHeadContext *ctx) override;

    antlrcpp::Any visitBlock(PascalParser::BlockContext *ctx) override;

    antlrcpp::Any visitIdentifier(PascalParser::IdentifierContext *ctx) override;

    antlrcpp::Any visitLabel(PascalParser::LabelContext *ctx) override;

    antlrcpp::Any visitConstantVar(PascalParser::ConstantVarContext *ctx) override;

    antlrcpp::Any visitConstantChr(PascalParser::ConstantChrContext *ctx) override;

    antlrcpp::Any visitConstant(PascalParser::ConstantContext *ctx) override;

    antlrcpp::Any visitUnsignedNumber(PascalParser::UnsignedNumberContext *ctx) override;

    antlrcpp::Any visitUnsignedInteger(PascalParser::UnsignedIntegerContext *ctx) override;

    antlrcpp::Any visitUnsignedReal(PascalParser::UnsignedRealContext *ctx) override;

    antlrcpp::Any visitSign(PascalParser::SignContext *ctx) override;

    antlrcpp::Any visitBool_(PascalParser::Bool_Context *ctx) override;

    antlrcpp::Any visitTypeIdentifier(PascalParser::TypeIdentifierContext *ctx) override;

    antlrcpp::Any visitString(PascalParser::StringContext *ctx) override;

    antlrcpp::Any visitSimpleType(PascalParser::SimpleTypeContext *ctx) override;

    antlrcpp::Any visitScalarType(PascalParser::ScalarTypeContext *ctx) override;

    antlrcpp::Any visitStringtype(PascalParser::StringtypeContext *ctx) override;

    antlrcpp::Any visitIdentifierList(PascalParser::IdentifierListContext *ctx) override;

    antlrcpp::Any visitConstList(PascalParser::ConstListContext *ctx) override;

    antlrcpp::Any visitUnlabelledStatement(PascalParser::UnlabelledStatementContext *ctx) override;

    antlrcpp::Any visitSimpleStatement(PascalParser::SimpleStatementContext *ctx) override;

    antlrcpp::Any visitExpression(PascalParser::ExpressionContext *ctx) override;

    antlrcpp::Any visitRelationaloperator(PascalParser::RelationaloperatorContext *ctx) override;

    antlrcpp::Any visitSimpleExpression(PascalParser::SimpleExpressionContext *ctx) override;

    antlrcpp::Any visitAdditiveoperator(PascalParser::AdditiveoperatorContext *ctx) override;

    antlrcpp::Any visitMultiplicativeoperator(PascalParser::MultiplicativeoperatorContext *ctx) override;

    antlrcpp::Any visitSignedFactor(PascalParser::SignedFactorContext *ctx) override;

    antlrcpp::Any visitFactor(PascalParser::FactorContext *ctx) override;

    antlrcpp::Any visitUnsignedConstant(PascalParser::UnsignedConstantContext *ctx) override;

    antlrcpp::Any visitSet_(PascalParser::Set_Context *ctx) override;

    antlrcpp::Any visitElementList(PascalParser::ElementListContext *ctx) override;

    antlrcpp::Any visitElement(PascalParser::ElementContext *ctx) override;

    antlrcpp::Any visitGotoStatement(PascalParser::GotoStatementContext *ctx) override;

    antlrcpp::Any visitEmptyStatement_(PascalParser::EmptyStatement_Context *ctx) override;

    antlrcpp::Any visitEmpty_(PascalParser::Empty_Context *ctx) override;

    antlrcpp::Any visitStructuredStatement(PascalParser::StructuredStatementContext *ctx) override;

    antlrcpp::Any visitWriteArguments(PascalParser::WriteArgumentsContext *ctx) override;

    antlrcpp::Any visitWriteArgs(PascalParser::WriteArgsContext *ctx) override;

    antlrcpp::Any visitStatements(PascalParser::StatementsContext *ctx) override;

    antlrcpp::Any visitConditionalStatement(PascalParser::ConditionalStatementContext *ctx) override;

    antlrcpp::Any visitCaseListElement(PascalParser::CaseListElementContext *ctx) override;

    antlrcpp::Any visitRepetetiveStatement(PascalParser::RepetetiveStatementContext *ctx) override;

    antlrcpp::Any visitForList(PascalParser::ForListContext *ctx) override;

    antlrcpp::Any visitInitialValue(PascalParser::InitialValueContext *ctx) override;

    antlrcpp::Any visitFinalValue(PascalParser::FinalValueContext *ctx) override;

    antlrcpp::Any visitWithStatement(PascalParser::WithStatementContext *ctx) override;

    antlrcpp::Any visitRecordVariableList(PascalParser::RecordVariableListContext *ctx) override;
        
        
#endif 
