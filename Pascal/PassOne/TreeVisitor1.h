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
        
        
#endif 
