#ifndef TREEVISITOR1_H_
#define TREEVISITOR1_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "antlr4-runtime.h"
#include "PassOne/Typespec.h"
#include "PassOne/Symtab.h"
#include "PassOne/ParserNode.h"
#include "PassOne/SymtabStack.h"
#include "Object.h"



#include "target/generated-sources/ant4/PascalBaseVisitor.h"
#include "target/generated-sources/ant4/PascalVisitor.h"

using namespace std;
using namespace PassOne;

typedef antlrcpp::Any Object;
class TreeVisitor1 : public PascalBaseVisitor
{
private:
    Symtab *symtab;
    SymtabStack *symtabStack;
    vector<SymtabEntry *> varList;
    vector<PascalParser::IdentifierContext *>varCtx;
    Typespec *initial;
    int tabs;
    string test;
public:
    //needs to create a symbol table stack and make a symbol table at stack(0)
    TreeVisitor1(): tabs(0), test("") {
        symtab = new Symtab(1);
        symtabStack = new SymtabStack();
        initial = new Typespec();
        initial -> initialize(symtabStack);
    };
    
    virtual ~TreeVisitor1(){};
    void printToFile(string filename)
    {
        ofstream file;
        file.open(filename);
        if(file.fail())
        {
            cout << " COULD NOT OPEN THE FILE " << filename << endl;
            exit(1);
        }
        file << test;
        symtab->printSymtabToFile(filename);
        file.close();
    }
    void printSymtabStack()
    {
        int nestLevels = symtabStack->getCurrentNestingLevel();

        for(int i = 0; i <= nestLevels; i++)
        {
            cout << "LEVEL: " << i << endl;
            if( i == 0 )
            {
                Symtab* temp = symtabStack->getSymtabLevel(i);
                vector<SymtabEntry*> tabStack = temp->sortEntries();
                for(SymtabEntry* ent : tabStack)
                {
                    Typespec *temp2 = ent->getType();
                    cout << "Entry: " << ent->getName();
                    
                    cout << "\t\tkind: " << getKindString(ent->getKind());
                    cout << endl;
                }
            }
            else 
            {
                Symtab* temp = symtabStack->getSymtabLevel(i);
                vector<SymtabEntry*> tabStack = temp->sortEntries();
                for(SymtabEntry* ent : tabStack)
                {
                    Typespec *temp2 = ent->getType();
                    cout << "Entry: " << ent->getName();
                    cout << " type ";
                    
                    if(temp2->getForm() == TypeForm::SCALAR)
                    {
                        string typ = checkTypeString(temp2);
                        cout << typ;
                        
                        cout << " SCALAR ";
                        

                        
                    }
                    else if(temp2->getForm() == TypeForm::ARRAY)
                    {
                        cout << "ARRAY ";
                        Typespec *tempType = temp2->getArrayIndexType();
                        string strType;
                        strType = checkTypeString(tempType);

                        cout << "[" << strType << "] of";
                        Typespec *tempType2 = temp2->getArrayElementType();
                        while(tempType2->getForm() == TypeForm::ARRAY)
                        {
                            strType = checkTypeString(tempType2->getArrayIndexType());
                            cout << " ARRAY " << "[" << strType << "] of";
                            tempType2 = tempType2->getArrayElementType(); 
                        }
                        strType = checkTypeString(tempType2);
                        cout << " " << strType;
                    }

                    cout << "\t\tkind: " << getKindString(ent->getKind());


                    cout << endl;
                }
            }
            
            
        }
    }

    string checkTypeString(Typespec *type)
    {
        if(type == initial->integerType)
        {
            return "integer";
        }
        else if(type == initial->booleanType)
        {
            return "boolean";
        }
        else if(type == initial->realType)
        {
            return "real";
        }
        else if(type == initial->stringType)
        {
            return "string";
        }
        else if(type == initial->charType)
        {
            return "char";
        }
        else if(type == initial->voidType)
        {
            return "void";
        }
        else return "None";
    }

    string getKindString(Kind kind)
    {
        if(kind == Kind::CONSTANT)
        {
            return "CONSTANT";
        }
        else if(kind == Kind::FUNCTION)
        {
            return "FUNCTION";
        }
        else if(kind == Kind::VARIABLE)
        {
            return "VARIABLE";
        }
        else if(kind == Kind::PROCEDURE)
        {
            return "PROCEDURE";
        }
        else if(kind == Kind::TYPE)
        {
            return "TYPE";
        }
        else if(kind == Kind::UNDEFINED)
        {
            return "UNDEFINED";
        }
        else if(kind == Kind::PROGRAM)
        {
            return "PROGRAM";
        }
        else return "NONE";

    }

    void printTabs(){
        for(int i = 0; i < tabs; i++)
        {
            cout << "\t";
            test += "\t";
        }
    };

    Object visitProgram(PascalParser::ProgramContext *ctx) override{ 
        //create root node
        //set name of root node, set line etc.
        //pushback ctx->programhead as a child
        //pushback ctx->block as a child

        printTabs();
        cout << "<PROGRAM ";
        test += "<PROGRAM ";
        visit(ctx->programHead());
        visit(ctx->block()); 
        cout << "</PROGRAM>" << endl;
        test += "</PROGRAM>\n";
        tabs--;
        symtab->printSymtab();
        printSymtabStack();
        // Symtab *test = symtabStack->getLocalSymtab();
        
        // vector<SymtabEntry*> tabStack = test->sortEntries();
        // for(SymtabEntry* ent : tabStack)
        // {
        //     Typespec *temp = ent->getType();
        //     cout << "Entry: " << ent->getName();
        //     if(temp == initial->integerType)
        //     {
        //         cout << " type integer";
        //     }
        //     cout << endl;
        // }

        return nullptr;
        }; //yes

    Object visitProgramHead(PascalParser::ProgramHeadContext *ctx) override{ 
        
        //enter program name into the symbol table
        string programName = ctx->identifier()->getText();

        symtab->enter(programName, Kind::PROGRAM);
        

       
        cout << programName << ">" << endl;

        test += programName + ">\n";
        tabs++;

        SymtabEntry *programHead = symtabStack->enterLocal(programName, Kind::PROGRAM);
        programHead->setKind(Kind::PROGRAM);
        programHead->setValue(SymtabKey::ROUTINE_SYMTAB, symtabStack->push());
        symtabStack->setProgramId(programHead);
        symtabStack->getLocalSymtab()->setOwner(programHead);

        PascalParser::IdentifierContext *ctx1 = ctx->identifier();
        ctx1->entry = programHead;
        

    return nullptr;};    //yes

    Object visitIdentifier(PascalParser::IdentifierContext *ctx) override{
        return visitChildren(ctx);};      //no

    Object visitBlock(PascalParser::BlockContext *ctx) override{
        return visitChildren(ctx);
    }

    Object visitUsesUnitsPart(PascalParser::UsesUnitsPartContext *ctx) override {
        return visitChildren(ctx);
    }

    Object visitLabelDeclarationPart(PascalParser::LabelDeclarationPartContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitConstantDefinitionPart(PascalParser::ConstantDefinitionPartContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitConstantDefinition(PascalParser::ConstantDefinitionContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitConstantIdentifier(PascalParser::ConstantIdentifierContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitTypeDefinitionPart(PascalParser::TypeDefinitionPartContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitTypeDefinition(PascalParser::TypeDefinitionContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitFormalParameterList(PascalParser::FormalParameterListContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitFormalParameterSection(PascalParser::FormalParameterSectionContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitParameterGroup(PascalParser::ParameterGroupContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitFunctionType(PascalParser::FunctionTypeContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitProcedureType(PascalParser::ProcedureTypeContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitVariableDeclarationPart(PascalParser::VariableDeclarationPartContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitVariableDeclaration(PascalParser::VariableDeclarationContext *ctx) override {

        // PascalParser::Type_Context *typectx = ctx->type_();
        // visit(typectx);

        // PascalParser::IdentifierListContext *listCtx = ctx->identifierList();

        // for( PascalParser::IdentifierContext *idCtx : listCtx->identifier())
        // {
        //     int line = idCtx->getStart()->getLine();
        //     string varName = toLowerCase(idCtx->getText());
        //     cout << "VARNAME " << varName << endl;
        //     SymtabEntry *varId = symtabStack->lookupLocal(varName);
        //     if(varId == nullptr)
        //     {
        //         cout << "null " << endl;
        //         SymtabEntry *temp = symtabStack->enterLocal(varName, Kind::VARIABLE);
        //         // if(typectx->type != nullptr)
        //         // {
        //         //     cout << "integer" << endl;
        //         // }
        //         //varId->setType(typectx->type);
        //         //Symtab *tab = varId->getSymtab();
        //         //idCtx->entry = varId;
        //     }
        //     else
        //     {
        //         cout << "UNDECLARED " << endl;
        //     }
        //     //varId->appendLineNumber(line);

        // }
        
        

        
        cout << "VISITNG VARIABLE DELCARATION " << ctx->getText() << endl;
        //reset varList
        varList.resize(0);
        varCtx.resize(0);

        //this is used for declarations like i, j, k : integer; i,j,k is the var list


        string ident_list = ctx->identifierList()->getText();
        cout << ident_list << endl;

        vector<string> iden_array;
        stringstream iden_stream(ident_list);

        while(iden_stream.good())
        {
            string substr;
            getline(iden_stream, substr, ',');
            iden_array.push_back(substr);
        }

        for(int i = 0; i < iden_array.size(); i++)
        {
            SymtabEntry *var = symtabStack->enterLocal(iden_array.at(i), Kind::VARIABLE);
            varList.push_back(var);
        }

        Typespec *type;

        string tyName = ctx->type_()->getText();
        tyName = toLowerCase(tyName);
        string ArrayChecker = "array";
        

        if(tyName == "integer")
        {
            type = initial->integerType;
        }
        else if(tyName == "real")
        {
            type = initial->realType;
        }
        else if(tyName == "boolean")
        {
            type = initial->booleanType;
        }
        else if(tyName == "char")
        {
            type = initial->charType;
        }
        else if(tyName == "void")
        {
            type = initial->voidType;
        }
        else if(tyName == "String")
        {
            type = initial->stringType;
        }
        else type = initial->undefinedType;

        int dimensions = 0;
        std::string::size_type pos = 0;
        while((pos = tyName.find(ArrayChecker, pos)) != string::npos)
        {
            dimensions++;
            pos +=  ArrayChecker.length();
        }
        if(dimensions > 0)
        {
            visit(ctx->type_());
            type = ctx->type_()->type;
        }
        for( SymtabEntry *ent : varList)
        {
            ent->setType(type);
        }

        
        
        
        return nullptr;

        //type->





        
        //return nullptr;
    }
    Object visitProcedureAndFunctionDeclarationPart(PascalParser::ProcedureAndFunctionDeclarationPartContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitProcedureOrFunctionDeclaration(PascalParser::ProcedureOrFunctionDeclarationContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitProcedureDeclaration(PascalParser::ProcedureDeclarationContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitFunctionDeclaration(PascalParser::FunctionDeclarationContext *ctx) override {




        return visitChildren(ctx);
    }
    Object visitType_(PascalParser::Type_Context *ctx) override {
        PascalParser::StructuredTypeContext *strType = ctx->structuredType();
        PascalParser::SimpleTypeContext *simType = ctx->simpleType();
        if(strType != nullptr)
        {
            cout << "STRUCTURED TYPE" << endl;
            visit(strType);
            ctx->type = strType->type;
            
        }
        else if(simType != nullptr)
        {
            cout << "SIMP TYPE" << endl;
            visit(simType);
            ctx->type = simType->type;
            
        }
        

        //visitChildren(ctx);
        //ctx->type = 
        return nullptr;
    }
    Object visitStructuredType(PascalParser::StructuredTypeContext *ctx) override {
        visit(ctx->unpackedStructuredType());
        ctx->type = ctx->unpackedStructuredType()->type;
        return nullptr;
    }
    Object visitUnpackedStructuredType(PascalParser::UnpackedStructuredTypeContext *ctx) override {
        Typespec *arr = new Typespec(TypeForm::ARRAY);
        cout << "unpacked struc " << ctx->getText() << endl;
        PascalParser::ArrayTypeContext *ctx1 = ctx->arrayType(); //array ctx
        PascalParser::TypeListContext *ctx2 = ctx1->typeList(); // list ctx

        ctx->type = arr;
        int count = ctx2->simpleType().size();
        for(int i = 0; i < count; i++)
        {
            PascalParser::SimpleTypeContext *ctx3 = ctx2->simpleType()[i];
            cout << ctx3->getText() << endl;
            visit(ctx3);
            arr->setArrayIndexType(ctx3->type);
            arr->setArrayElementCount(1);
            if(i < count-1)
            {
                Typespec *ele = new Typespec(TypeForm::ARRAY);
                arr->setArrayElementType(ele);
                arr = ele;
            }
        }
        visit(ctx1->type_());
        Typespec *ele = ctx1->type_()->type;
        arr->setArrayElementType(ele);
        //SymtabEntry *testt = ele->getIdentifier();
        //cout << testt->getName() << endl;
        SymtabEntry *en = arr->getIdentifier();
        //cout << en->getName() << endl;


        return nullptr;
    }
    Object visitArrayType(PascalParser::ArrayTypeContext *ctx) override {
        Typespec *arr = new Typespec(TypeForm::ARRAY);
        
        PascalParser::TypeListContext *ctx1 = ctx->typeList();
        int count = ctx1->simpleType().size();
        for(int i = 0; i < count; i++)
        {
            PascalParser::SimpleTypeContext *ctx2 = ctx1->simpleType()[i];

            // Object temp = visit(ctx2);
            // ParserNode *test = Object::as<ParserNode*>(temp);

            
            // temp->getType();
            // if(temp->getType() == initial->integerType)
            // {
            //     cout << "ARRAY TYPE OF INT!" << endl;
            // }
            //arr->setArrayIndexType(ctx2->)
        }
        cout << "count: " << count << endl;


        return visitChildren(ctx);
    }
    Object visitTypeList(PascalParser::TypeListContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitPointerType(PascalParser::PointerTypeContext *ctx) override {
        return visitChildren(ctx);
    }





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
        test += "<INTEGER_CONSTANT " + number + "/>\n";

        return visitChildren(ctx);
        };    //no

    Object visitUnsignedReal(PascalParser::UnsignedRealContext *ctx) override{

        string number = ctx->getText();
        printTabs();
        cout << "<REAL_CONSTANT " << number << "/>" << endl;
        test += "<REAL_CONSTANT " + number + "/>\n";
        
        return nullptr;
        };      //no

    Object visitSign(PascalParser::SignContext *ctx) override{return visitChildren(ctx);};      //no

    Object visitBool_(PascalParser::Bool_Context *ctx) override{return visitChildren(ctx);};    //no

    Object visitTypeIdentifier(PascalParser::TypeIdentifierContext *ctx) override{
        string typeName = toLowerCase(ctx->getText());
        
        SymtabEntry *typeId = symtabStack->lookup(typeName);

        if(typeId != nullptr)
        {
            if(typeId->getKind() != Kind::TYPE)
            {
                //cout << "ERROR!" << endl;
                ctx->type = initial->integerType;
            }
            else
            {
                ctx->type = typeId->getType();
            }
            typeId->appendLineNumber(ctx->start->getLine());
        }
        else
        {
            //cout << "UNDECLARED" << endl;
            ctx->type = initial->integerType;
        }
        ctx->entry = typeId;

        return nullptr;
    };      //no

    Object visitString(PascalParser::StringContext *ctx) override{
        
        string str = ctx->getText();

        printTabs();
        cout << "<STRING_CONSTANT " << str << "/>" << endl;
        test += "<STRING_CONSTANT " + str + "/>\n";

        return nullptr;};                  //no
    
    Object visitSimpleType(PascalParser::SimpleTypeContext *ctx) override{
        visit(ctx->typeIdentifier());
        ctx->type = ctx->typeIdentifier()->type;

        return nullptr;
    };         

    Object visitScalarType(PascalParser::ScalarTypeContext *ctx) override{return visitChildren(ctx);};

    Object visitStringtype(PascalParser::StringtypeContext *ctx) override{return visitChildren(ctx);};

    Object visitIdentifierList(PascalParser::IdentifierListContext *ctx) override{return visitChildren(ctx);};

    Object visitStatement(PascalParser::StatementContext *ctx) override{
        //create parserNode of statement
        //adopt ->visitChildren(ctx);



        return visitChildren(ctx);
        
        }; 

    Object visitUnlabelledStatement(PascalParser::UnlabelledStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitSimpleStatement(PascalParser::SimpleStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitProcedureStatement(PascalParser::ProcedureStatementContext *ctx) override {
        return visitChildren(ctx);
    }
    
    
    Object visitEmptyStatement_(PascalParser::EmptyStatement_Context *ctx) override {
        return visitChildren(ctx);
    }


    Object visitAssignmentStatement(PascalParser::AssignmentStatementContext *ctx) override{

        PascalParser::VariableContext *varCtx = ctx->variable();
        PascalParser::ExpressionContext *exprCtx = ctx->expression();



        string varName = ctx->variable()->getText();
        symtab->enter(varName, Kind::VARIABLE);

        
        
        printTabs();
        cout << "<ASSIGN " << "line " << ctx->getStart()->getLine() << ">" << endl;
        int line = ctx->getStart()->getLine();
       
        test += "<ASSIGN line " + to_string(line) + ">\n";
        tabs++;
        visitChildren(ctx);
        tabs--;
        printTabs();
        cout << "</ASSIGN>" << endl;
        test += "</ASSIGN>\n";

        return nullptr;}; 

    Object visitVariable(PascalParser::VariableContext *ctx) override{
        //create a VARIABLE NODE
        //node ->text = varname
        //
        PascalParser::VariableIdentifierContext *variCtx = ctx->variableIdentifier();
        visit(variCtx);
        ctx->entry = variCtx->entry;
        ctx->type = variCtx->type;

        string varName = ctx->getText();
        int line = ctx->getStart()->getLine();
        printTabs();
        cout << "<VARIABLE " << varName << " line " << ctx->getStart()->getLine() << "/>" << endl;
        test += "<VARIABLE " + varName + " line " + to_string(line) + "/>\n";

        visitChildren(ctx);
        //ctx->type = ctx->identifier()->type;
        return nullptr;}; 

    Object visitModifier(PascalParser::ModifierContext *ctx) override {
        return visitChildren(ctx);
    }
    Typespec *variableDataType(PascalParser::VariableIdentifierContext *variCtx, Typespec *variableType)
    {
        Typespec *type = variableType;
        // for(PascalParser::ModifierContext *modCtx : variCtx->modifier())
        // {
        //     if(modCtx->expression() != nullptr)
        //     {
        //        if(type->getForm() == TypeForm::ARRAY)
        //        {
        //          Typespec *indType = type->getArrayIndexType();
        //          PascalParser::ExpressionContext *exCtx = modCtx->expression();
        //          visit(exCtx);
        //          if(indType->baseType() != exCtx->type->baseType())
        //          {
        //             cout << "ERROR" << endl;
        //          }
        //          type = type->getArrayElementType();
        //        }
        //        else
        //        {
        //          cout << "NOT ARRAY" << endl;
        //        }
        //     }
        // }
        return type;
    }

    Object visitVariableIdentifier(PascalParser::VariableIdentifierContext *ctx) override {
        string varName = toLowerCase(ctx->getText());
        SymtabEntry *varId = symtabStack->lookup(varName);
        if(varId != nullptr)
        {
            int linenum = ctx->getStart()->getLine();
            ctx->type = varId->getType();
            ctx->entry = varId;
            varId->appendLineNumber(linenum);
            Kind kind = varId->getKind();
            if(kind == Kind::UNDEFINED)
            {
                cout << "UNDEFINED KIND" << endl;
            }
        }
        else
        {
            ctx->type = initial->integerType;
        }

        return nullptr;
    }

    Object visitExpression(PascalParser::ExpressionContext *ctx) override{
        PascalParser::SimpleExpressionContext *simpExprCtx = ctx->simpleExpression();

        visit(simpExprCtx);
        Typespec *simpleType1 = simpExprCtx->type;
        ctx->type = simpleType1;


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
            test += "<" + toUpperCase(op) + ">\n";
            tabs++;
                visitChildren(ctx);
            tabs--;
            printTabs();
            cout << "</" << toUpperCase(op) << ">" << endl;
            test += "</" + toUpperCase(op) + ">\n";
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
            test += "<" + toUpperCase(op) + ">\n";
            tabs++;
                visitChildren(ctx);
            tabs--;
            printTabs();
            cout << "</" << toUpperCase(op) << ">" << endl;
            test += "</" + toUpperCase(op) + ">\n";
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
            test += "<" + toUpperCase(op) + ">\n";
            tabs++;
                visitChildren(ctx);
            tabs--;
            printTabs();
            cout << "</" << toUpperCase(op) << ">" << endl;
            test += "</" + toUpperCase(op) + ">\n";
        }else visitChildren(ctx);


        return nullptr;}; 

    Object visitMultiplicativeoperator(PascalParser::MultiplicativeoperatorContext *ctx) override{return visitChildren(ctx);};

    Object visitSignedFactor(PascalParser::SignedFactorContext *ctx) override{
        if(ctx->MINUSOP() != nullptr)
        {
            printTabs();
            cout << "<NEGATE>" << endl;
            test += "<NEGATE>\n";
            tabs++;
            visitChildren(ctx);
            tabs--;
            printTabs();
            cout << "</NEGATE>" << endl;
            test += "</NEGATE>\n";

        }else visitChildren(ctx);
        return nullptr;};
                    
    Object visitFactor(PascalParser::FactorContext *ctx) override{
        
        if(ctx->NOT() != nullptr)
        {
            printTabs();
            cout << "<NEGATE>" << endl;
            test += "<NEGATE>\n";

            tabs++;
            visitChildren(ctx);
            tabs--;
            printTabs();
            cout << "</NEGATE>" << endl;
            test += "<NEGATE>\n";
        }else visitChildren(ctx);

        return nullptr;};

    Object visitUnsignedConstant(PascalParser::UnsignedConstantContext *ctx) override{return visitChildren(ctx);};

    Object visitFunctionDesignator(PascalParser::FunctionDesignatorContext *ctx) override {
        return visitChildren(ctx);
    }

    Object visitParameterList(PascalParser::ParameterListContext *ctx) override {
        return visitChildren(ctx);
    }

    Object visitActualParameter(PascalParser::ActualParameterContext *ctx) override {
        return visitChildren(ctx);
    }

    Object visitParameterwidth(PascalParser::ParameterwidthContext *ctx) override {
        return visitChildren(ctx);
    }

    Object visitSet_(PascalParser::Set_Context *ctx) override {
        return visitChildren(ctx);
    }

    Object visitElement(PascalParser::ElementContext *ctx) override {
        return visitChildren(ctx);
    }



    Object visitGotoStatement(PascalParser::GotoStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        printTabs();
        cout << "<GOTO " << "line "<< ctx->getStart()->getLine() << ">" << endl;
        test += "<GOTO line " + to_string(line) + ">\n";

        tabs++;
        visitChildren(ctx);
        tabs--;

        printTabs();
        cout << "</GOTO>" << endl;
        test += "</GOTO>\n";


        return nullptr;};

    Object visitStructuredStatement(PascalParser::StructuredStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitReptitiveStatement(PascalParser::ReptitiveStatementContext *ctx) override {return visitChildren(ctx);}

    Object visitWriteArguments(PascalParser::WriteArgumentsContext *ctx) override{return visitChildren(ctx);};

    Object visitWriteArgs(PascalParser::WriteArgsContext *ctx) override{return visitChildren(ctx);};

    Object visitWriteStatement(PascalParser::WriteStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        printTabs();
        cout << "<WRITE " <<  "line "<< ctx->getStart()->getLine() << ">" << endl;
        test += "<WRITE line " + to_string(line) + ">\n";

        tabs++;
            visitChildren(ctx);
        tabs--;
        
        printTabs();
        cout << "</WRITE>" << endl;
        test += "</WRITE>\n";

        return nullptr;};

    Object visitWritelnStatement(PascalParser::WritelnStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        printTabs();
        cout << "<WRITELN " <<  "line "<< ctx->getStart()->getLine() << ">" << endl;
        test += "<WRITELN line " + to_string(line) + ">\n";
        tabs++;
            visitChildren(ctx);
        tabs--;
        
        printTabs();
        cout << "</WRITELN>" << endl;
        test += "</WRITELN>\n";
        return nullptr;}; 

    Object visitCompoundStatement(PascalParser::CompoundStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        printTabs();
        cout << "<COMPOUND " << "line "<< ctx->getStart()->getLine() << ">" << endl;
        test += "<COMPOUND line " + to_string(line) + ">\n";

        tabs++;         //increment tab
        visitChildren(ctx);
        tabs--;         //decrement tab

        printTabs();
        cout << "</COMPOUND>" << endl;
        test += "</COMPOUND>\n";
        return nullptr;
        };

    Object visitStatements(PascalParser::StatementsContext *ctx) override{return visitChildren(ctx);};

    Object visitIfStatement(PascalParser::IfStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        printTabs();
        cout << "<IF " << "line "<< ctx->getStart()->getLine() << ">" << endl;
        test += "<IF line " + to_string(line) + ">\n";
        tabs++;
            visitChildren(ctx);
        tabs--;

        printTabs();
        cout << "</IF>" << endl;
        test += "</IF>\n";

        return nullptr;};

    Object visitCaseStatement(PascalParser::CaseStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        printTabs();
        cout << "<CASE " << "line "<< ctx->getStart()->getLine() << ">" << endl;
        test += "<CASE line " + to_string(line) + ">\n";

        tabs++;
            visitChildren(ctx);
        tabs--;
        
        printTabs();
        cout << "</CASE>" << endl;
        test += "</CASE>\n";

        return nullptr;};

    Object visitCaseListElement(PascalParser::CaseListElementContext *ctx) override{return visitChildren(ctx);};

    Object visitWhileStatement(PascalParser::WhileStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        printTabs();
        cout << "<WHILE " << "line "<< ctx->getStart()->getLine() << ">" << endl;
        test += "<WHILE line " + to_string(line) + ">\n";

        tabs++;
            printTabs();
            cout << "<TEST>" << endl;
            test += "<TEST>\n";
                tabs++;
                visit(ctx->expression());
                tabs--;
            printTabs();
            cout << "</TEST>" << endl;
            test += "</TEST>\n";
        tabs--;
        
        printTabs();
        cout << "</WHILE>" << endl;
        test += "</WHILE>\n";

        return nullptr;};

    Object visitRepeatStatement(PascalParser::RepeatStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        printTabs();
        cout << "<REPEAT " << "line "<< ctx->getStart()->getLine() << ">" << endl;
        test += "<REPEAT line " + to_string(line) + ">\n";

        tabs++;
            
            visit(ctx->statements());

            printTabs();
            cout << "<TEST>" << endl;
            test += "<TEST>\n";
                tabs++;
                visit(ctx->expression());
                tabs--;
            printTabs();
            cout << "</TEST>" << endl;
            test += "</TEST>\n";
            
            
        tabs--;
        
        printTabs();
        cout << "</REPEAT>" << endl;
        test += "</REPEAT>\n";

        return nullptr;};    
    
    Object visitForStatement(PascalParser::ForStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        printTabs();
        cout << "<FOR " << "line "<< ctx->getStart()->getLine() << ">" << endl;
        test += "<FOR line " + to_string(line) + ">\n";

        string toOrDownTo;
        if(ctx->TO() != nullptr)
        {
            toOrDownTo = "TO";
        }else toOrDownTo = "DOWNTO";
        tabs++;
            visit(ctx->assignmentStatement());
            
            printTabs();
            cout << "<" << toOrDownTo << ">" <<  endl;
            test += "<" + toOrDownTo + ">\n";
                tabs++;
                visit(ctx->expression());
                tabs--;
            printTabs();
            cout << "</" << toOrDownTo << ">" << endl;
            test += "</" + toOrDownTo + ">\n";
            visit(ctx->statement());
        tabs--;

        printTabs();
        cout << "</FOR>" << endl;
        test += "</FOR>\n";

        return nullptr;};

    Object visitWithStatement(PascalParser::WithStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        printTabs();
        cout << "<WITH " << "line "<< ctx->getStart()->getLine() << ">" << endl;
        test += "<WITH line " + to_string(line) + ">\n";

        tabs++;
           visitChildren(ctx);
        tabs--;

        printTabs();
        cout << "</WITH>" << endl;
        test += "</WITH>\n";

        return nullptr;};    
                
     
                
     
        
     
        
     
};
#endif 