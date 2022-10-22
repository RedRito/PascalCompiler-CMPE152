#ifndef TREEVISITOR1_H_
#define TREEVISITOR1_H_

#include <iostream>
#include <string>
#include "antlr4-runtime.h"
#include "PassOne/Symtab.h"
#include "Object.h"
#include "SymtabPrinter.h"
#include "target/generated-sources/ant4/PascalBaseVisitor.h"
#include "target/generated-sources/ant4/PascalVisitor.h"

typedef antlrcpp::Any Object;
class TreeVisitor1 : public PascalBaseVisitor
{
private:
    map<string, Object> symtb;
    Symtab *symtab;
    int tabs;
public:
    TreeVisitor1(): tabs(0) {symtab = new Symtab();};
    
    virtual ~TreeVisitor1(){};

    void printTabs(){
        for(int i = 0; i < tabs; i++)
        {
            cout << "\t";
        }
    };

    Object visitProgram(PascalParser::ProgramContext *ctx) override{ 
        
        printTabs();
        cout << "<PROGRAM ";
        visit(ctx->programHead());
        visit(ctx->compoundStatement()); 
        cout << "</PROGRAM>" << endl;
        tabs--;
        return nullptr;
        }; //yes

    Object visitProgramHead(PascalParser::ProgramHeadContext *ctx) override{ 
        
        //cout << "VISITING PROGRAM HEAD" << endl;
        string programName = ctx->identifier()->getText();

        //symtab->enter(programName, Kind::PROGRAM);
        //cout << programName << endl;
        //cout << "line " << ctx->getStart()->getLine() << endl;

       
        cout << programName << ">" << endl;
        tabs++;

    return visitChildren(ctx);};    //yes

    Object visitIdentifier(PascalParser::IdentifierContext *ctx) override{return visitChildren(ctx);};      //no

    Object visitLabel(PascalParser::LabelContext *ctx) override{return visitChildren(ctx);};                //no

    Object visitConstantVar(PascalParser::ConstantVarContext *ctx) override{return visitChildren(ctx);};    //no

    Object visitConstantChr(PascalParser::ConstantChrContext *ctx) override{return visitChildren(ctx);};    //no

    Object visitConstant(PascalParser::ConstantContext *ctx) override{
        return visitChildren(ctx);};          //no

    Object visitUnsignedNumber(PascalParser::UnsignedNumberContext *ctx) override{return visitChildren(ctx);};  //no

    Object visitUnsignedInteger(PascalParser::UnsignedIntegerContext *ctx) override{
        
        string number = ctx->getText();
        printTabs();
        cout << "<INTEGER_CONSTANT " << number << "/>" << endl;

        return visitChildren(ctx);
        };    //no

    Object visitUnsignedReal(PascalParser::UnsignedRealContext *ctx) override{

        string number = ctx->getText();
        printTabs();
        cout << "<REAL_CONSTANT " << number << "/>" << endl;
        
        return nullptr;
        };      //no

    Object visitSign(PascalParser::SignContext *ctx) override{return visitChildren(ctx);};      //no

    Object visitBool_(PascalParser::Bool_Context *ctx) override{return visitChildren(ctx);};    //no

    Object visitTypeIdentifier(PascalParser::TypeIdentifierContext *ctx) override{return visitChildren(ctx);};      //no

    Object visitString(PascalParser::StringContext *ctx) override{
        
        string str = ctx->getText();

        printTabs();
        cout << "<STRING_CONSTANT " << str << "/>" << endl;

        return nullptr;};                  //no
    
    Object visitSimpleType(PascalParser::SimpleTypeContext *ctx) override{return visitChildren(ctx);};         

    Object visitScalarType(PascalParser::ScalarTypeContext *ctx) override{return visitChildren(ctx);};

    Object visitStringtype(PascalParser::StringtypeContext *ctx) override{return visitChildren(ctx);};

    Object visitIdentifierList(PascalParser::IdentifierListContext *ctx) override{return visitChildren(ctx);};

    Object visitStatement(PascalParser::StatementContext *ctx) override{return visitChildren(ctx);}; 

    Object visitUnlabelledStatement(PascalParser::UnlabelledStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitSimpleStatement(PascalParser::SimpleStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitAssignmentStatement(PascalParser::AssignmentStatementContext *ctx) override{
        
        // cout << "Visiting assignment statment" <<endl;
        // string varName = ctx->variable()->getText();
        // cout << "varName " << varName << endl;
        // string test = ctx->expression()->getText();
        // cout << "test " << test << endl;
        // cout << "line " << ctx->getStart()->getLine() << endl;

        printTabs();
        cout << "<ASSIGN " << "line " << ctx->getStart()->getLine() << ">" << endl;
        tabs++;
        visitChildren(ctx);
        tabs--;
        printTabs();
        cout << "</ASSIGN>" << endl;

        return nullptr;}; 

    Object visitVariable(PascalParser::VariableContext *ctx) override{

        string varName = ctx->getText();

        printTabs();
        cout << "<VARIABLE " << varName << " line " << ctx->getStart()->getLine() << "/>" << endl;

        visitChildren(ctx);

        return nullptr;}; 

    Object visitExpression(PascalParser::ExpressionContext *ctx) override{
        PascalParser::RelationaloperatorContext *ctx2 = ctx->relationaloperator();

        if(ctx2 != nullptr)
        {
            string op = ctx2->getText();
            if(op == "=")
            {
                op  =  "EQUAL";
            }
            else if(op == "<>")
            {
                op  =  "NE";
            }
            else if(op == "<")
            {
                op  =  "LT";
            }
            else if(op == ">")
            {
                op  =  "GT";
            }
            else if(op == "<=")
            {
                op  =  "LTEQ";
            }
            else if(op == ">=")
            {
                op  =  "GTEQ";
            }

            printTabs();
            cout << "<" << toUpperCase(op) << ">" << endl;
            tabs++;
                visitChildren(ctx);
            tabs--;
            printTabs();
            cout << "</" << toUpperCase(op) << ">" << endl;
        }
        else visitChildren(ctx);
        

        return nullptr;
        };

    Object visitRelationaloperator(PascalParser::RelationaloperatorContext *ctx) override{return visitChildren(ctx);};
        
    Object visitSimpleExpression(PascalParser::SimpleExpressionContext *ctx) override{

        PascalParser::AdditiveoperatorContext *ctx1 = ctx->additiveoperator();
        if(ctx1 != nullptr)
        {
            string op = ctx1->getText();
            if(op == "+")
            {
                op = "ADD";
            }
            else if(op == "-")
            {
                op = "SUBTRACT";
            }

            printTabs();
            cout << "<" << toUpperCase(op) << ">" << endl;
            tabs++;
                visitChildren(ctx);
            tabs--;
            printTabs();
            cout << "</" << toUpperCase(op) << ">" << endl;
        }else visitChildren(ctx);

        return nullptr;
        };
        
    Object visitAdditiveoperator(PascalParser::AdditiveoperatorContext *ctx) override{return visitChildren(ctx);};

    Object visitTerm(PascalParser::TermContext *ctx) override{

        PascalParser::MultiplicativeoperatorContext *ctx1 = ctx->multiplicativeoperator();

        if(ctx1 != nullptr)
        {
            string op = ctx1->getText();
            if(op == "*")
            {
                op = "MULTIPLY";
            }
            else if(op == "/")
            {
                op = "DIVIDE";
            }
            printTabs();
            cout << "<" << toUpperCase(op) << ">" << endl;
            tabs++;
                visitChildren(ctx);
            tabs--;
            printTabs();
            cout << "</" << toUpperCase(op) << ">" << endl;
        }else visitChildren(ctx);


        return nullptr;}; 

    Object visitMultiplicativeoperator(PascalParser::MultiplicativeoperatorContext *ctx) override{return visitChildren(ctx);};

    Object visitSignedFactor(PascalParser::SignedFactorContext *ctx) override{
        if(ctx->MINUSOP() != nullptr)
        {
            printTabs();
            cout << "<NEGATE>" << endl;
            
            tabs++;
            visitChildren(ctx);
            tabs--;
            printTabs();
            cout << "</NEGATE>" << endl;

        }else visitChildren(ctx);
        return nullptr;};
                    
    Object visitFactor(PascalParser::FactorContext *ctx) override{
        
        if(ctx->NOT() != nullptr)
        {
            printTabs();
            cout << "<NEGATE>" << endl;
            
            tabs++;
            visitChildren(ctx);
            tabs--;
            printTabs();
            cout << "</NEGATE>" << endl;
        }else visitChildren(ctx);

        return nullptr;};

    Object visitUnsignedConstant(PascalParser::UnsignedConstantContext *ctx) override{return visitChildren(ctx);};

    Object visitGotoStatement(PascalParser::GotoStatementContext *ctx) override{
        printTabs();
        cout << "<GOTO " << "line "<< ctx->getStart()->getLine() << ">" << endl;

        tabs++;
        visitChildren(ctx);
        tabs--;

        printTabs();
        cout << "</GOTO>" << endl;


        return nullptr;};

    Object visitStructuredStatement(PascalParser::StructuredStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitReptitiveStatement(PascalParser::ReptitiveStatementContext *ctx) override {return visitChildren(ctx);}

    Object visitWriteArguments(PascalParser::WriteArgumentsContext *ctx) override{return visitChildren(ctx);};

    Object visitWriteArgs(PascalParser::WriteArgsContext *ctx) override{return visitChildren(ctx);};

    Object visitWriteStatement(PascalParser::WriteStatementContext *ctx) override{
        
        printTabs();
        cout << "<WRITE " <<  "line "<< ctx->getStart()->getLine() << ">" << endl;

        tabs++;
            visitChildren(ctx);
        tabs--;
        
        printTabs();
        cout << "</WRITE>" << endl;

        return nullptr;};

    Object visitWritelnStatement(PascalParser::WritelnStatementContext *ctx) override{
        
        printTabs();
        cout << "<WRITELN " <<  "line "<< ctx->getStart()->getLine() << ">" << endl;

        tabs++;
            visitChildren(ctx);
        tabs--;
        
        printTabs();
        cout << "</WRITELN>" << endl;

        return nullptr;}; 

    Object visitCompoundStatement(PascalParser::CompoundStatementContext *ctx) override{
        printTabs();
        cout << "<COMPOUND " << "line "<< ctx->getStart()->getLine() << ">" << endl;

        tabs++;         //increment tab
        visitChildren(ctx);
        tabs--;         //decrement tab

        printTabs();
        cout << "</COMPOUND>" << endl;
        
        return nullptr;
        };

    Object visitStatements(PascalParser::StatementsContext *ctx) override{return visitChildren(ctx);};

    Object visitIfStatement(PascalParser::IfStatementContext *ctx) override{
        
        printTabs();
        cout << "<IF " << "line "<< ctx->getStart()->getLine() << ">" << endl;

        tabs++;
            visitChildren(ctx);
        tabs--;

        printTabs();
        cout << "</IF>" << endl;

        return nullptr;};

    Object visitCaseStatement(PascalParser::CaseStatementContext *ctx) override{
        
        printTabs();
        cout << "<CASE " << "line "<< ctx->getStart()->getLine() << ">" << endl;

        tabs++;
            visitChildren(ctx);
        tabs--;
        
        printTabs();
        cout << "</CASE>" << endl;

        return nullptr;};

    Object visitCaseListElement(PascalParser::CaseListElementContext *ctx) override{return visitChildren(ctx);};

    Object visitWhileStatement(PascalParser::WhileStatementContext *ctx) override{
        
        printTabs();
        cout << "<WHILE " << "line "<< ctx->getStart()->getLine() << ">" << endl;

        tabs++;
            printTabs();
            cout << "<TEST>" << endl;
                tabs++;
                visit(ctx->expression());
                tabs--;
            printTabs();
            cout << "</TEST>" << endl;
        tabs--;
        
        printTabs();
        cout << "</WHILE>" << endl;

        return nullptr;};

    Object visitRepeatStatement(PascalParser::RepeatStatementContext *ctx) override{
        
        printTabs();
        cout << "<REPEAT " << "line "<< ctx->getStart()->getLine() << ">" << endl;

        tabs++;
            
            visit(ctx->statements());

            printTabs();
            cout << "<TEST>" << endl;
                tabs++;
                visit(ctx->expression());
                tabs--;
            printTabs();
            cout << "</TEST>" << endl;
            
            
        tabs--;
        
        printTabs();
        cout << "</REPEAT>" << endl;

        return nullptr;};    
    
    Object visitForStatement(PascalParser::ForStatementContext *ctx) override{
        printTabs();
        cout << "<FOR " << "line "<< ctx->getStart()->getLine() << ">" << endl;

        string toOrDownTo;
        if(ctx->TO() != nullptr)
        {
            toOrDownTo = "TO";
        }else toOrDownTo = "DOWNTO";
        tabs++;
            visit(ctx->assignmentStatement());
            
            printTabs();
            cout << "<" << toOrDownTo << ">" <<  endl;
                tabs++;
                visit(ctx->expression());
                tabs--;
            printTabs();
            cout << "</" << toOrDownTo << ">" << endl;
            visit(ctx->statement());
        tabs--;

        return nullptr;};

    Object visitWithStatement(PascalParser::WithStatementContext *ctx) override{
        printTabs();
        cout << "<WITH " << "line "<< ctx->getStart()->getLine() << ">" << endl;

        tabs++;
           visitChildren(ctx);
        tabs--;

        printTabs();
        cout << "</WITH>" << endl;

        return nullptr;};    
                
     
                
     
        
     
        
     
};
#endif 