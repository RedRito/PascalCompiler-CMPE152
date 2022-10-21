#ifndef TREEVISITOR1_H_
#define TREEVISITOR1_H_

#include <iostream>
#include <string>
#include "antlr4-runtime.h"
#include "PassOne/Symtab.h"
#include "SymtabPrinter.h"
#include "target/generated-sources/ant4/PascalBaseVisitor.h"
#include "target/generated-sources/ant4/PascalVisitor.h"

typedef antlrcpp::Any Object;
class Symtab;
enum class Kind;
class TreeVisitor1 : public PascalBaseVisitor
{
private:
    map<string, Object> symtb;
    Symtab *symtab;
public:
    TreeVisitor1(){symtab = new Symtab();};
    
    virtual ~TreeVisitor1(){};
    
    Object visitProgram(PascalParser::ProgramContext *ctx) override{ return visitChildren(ctx); }; //yes

    Object visitProgramHead(PascalParser::ProgramHeadContext *ctx) override{ 
        cout << "VISITING PROGRAM HEAD" << endl;
        string programName = ctx->identifier()->getText();
        //symtab->enter(programName, Kind::PROGRAM); errors please help!!!!!!!!!
        cout << programName << endl;
        cout << "line " << ctx->getStart()->getLine() << endl;
        

    return visitChildren(ctx);};    //yes

    Object visitIdentifier(PascalParser::IdentifierContext *ctx) override{return visitChildren(ctx);};      //no

    Object visitLabel(PascalParser::LabelContext *ctx) override{return visitChildren(ctx);};                //no

    Object visitConstantVar(PascalParser::ConstantVarContext *ctx) override{return visitChildren(ctx);};    //no

    Object visitConstantChr(PascalParser::ConstantChrContext *ctx) override{return visitChildren(ctx);};    //no

    Object visitConstant(PascalParser::ConstantContext *ctx) override{return visitChildren(ctx);};          //no

    Object visitUnsignedNumber(PascalParser::UnsignedNumberContext *ctx) override{return visitChildren(ctx);};  //no

    Object visitUnsignedInteger(PascalParser::UnsignedIntegerContext *ctx) override{return visitChildren(ctx);};    //no

    Object visitUnsignedReal(PascalParser::UnsignedRealContext *ctx) override{return visitChildren(ctx);};      //no

    Object visitSign(PascalParser::SignContext *ctx) override{return visitChildren(ctx);};      //no

    Object visitBool_(PascalParser::Bool_Context *ctx) override{return visitChildren(ctx);};    //no

    Object visitTypeIdentifier(PascalParser::TypeIdentifierContext *ctx) override{return visitChildren(ctx);};      //no

    Object visitString(PascalParser::StringContext *ctx) override{return visitChildren(ctx);};                  //no
    
    Object visitSimpleType(PascalParser::SimpleTypeContext *ctx) override{return visitChildren(ctx);};         

    Object visitScalarType(PascalParser::ScalarTypeContext *ctx) override{return visitChildren(ctx);};

    Object visitStringtype(PascalParser::StringtypeContext *ctx) override{return visitChildren(ctx);};

    Object visitIdentifierList(PascalParser::IdentifierListContext *ctx) override{return visitChildren(ctx);};

    Object visitStatement(PascalParser::StatementContext *ctx) override{return visitChildren(ctx);}; 

    Object visitUnlabelledStatement(PascalParser::UnlabelledStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitSimpleStatement(PascalParser::SimpleStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitAssignmentStatement(PascalParser::AssignmentStatementContext *ctx) override{return visitChildren(ctx);}; 

    Object visitVariable(PascalParser::VariableContext *ctx) override{return visitChildren(ctx);}; 

    Object visitExpression(PascalParser::ExpressionContext *ctx) override{return visitChildren(ctx);};

    Object visitRelationaloperator(PascalParser::RelationaloperatorContext *ctx) override{return visitChildren(ctx);};
        
    Object visitSimpleExpression(PascalParser::SimpleExpressionContext *ctx) override{return visitChildren(ctx);};
        
    Object visitAdditiveoperator(PascalParser::AdditiveoperatorContext *ctx) override{return visitChildren(ctx);};

    Object visitTerm(PascalParser::TermContext *ctx) override{return visitChildren(ctx);}; 

    Object visitMultiplicativeoperator(PascalParser::MultiplicativeoperatorContext *ctx) override{return visitChildren(ctx);};

    Object visitSignedFactor(PascalParser::SignedFactorContext *ctx) override{return visitChildren(ctx);};
                    
    Object visitFactor(PascalParser::FactorContext *ctx) override{return visitChildren(ctx);};

    Object visitUnsignedConstant(PascalParser::UnsignedConstantContext *ctx) override{return visitChildren(ctx);};

    Object visitGotoStatement(PascalParser::GotoStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitStructuredStatement(PascalParser::StructuredStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitWriteArguments(PascalParser::WriteArgumentsContext *ctx) override{return visitChildren(ctx);};

    Object visitWriteArgs(PascalParser::WriteArgsContext *ctx) override{return visitChildren(ctx);};

    Object visitWriteStatement(PascalParser::WriteStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitWritelnStatement(PascalParser::WritelnStatementContext *ctx) override{return visitChildren(ctx);}; 

    Object visitCompoundStatement(PascalParser::CompoundStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitStatements(PascalParser::StatementsContext *ctx) override{return visitChildren(ctx);};

    Object visitIfStatement(PascalParser::IfStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitCaseStatement(PascalParser::CaseStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitCaseListElement(PascalParser::CaseListElementContext *ctx) override{return visitChildren(ctx);};

    Object visitWhileStatement(PascalParser::WhileStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitRepeatStatement(PascalParser::RepeatStatementContext *ctx) override{return visitChildren(ctx);};    
    
    Object visitForStatement(PascalParser::ForStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitWithStatement(PascalParser::WithStatementContext *ctx) override{return visitChildren(ctx);};    
                
     
                
     
        
     
        
     
};
#endif 