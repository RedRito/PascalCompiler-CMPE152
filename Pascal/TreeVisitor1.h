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
#include "PassOne/TypeChecker.h"
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
    vector<string> symtabPrints;
    string test;
public:
    //needs to create a symbol table stack and make a symbol table at stack(0)
    TreeVisitor1(): tabs(0), test("") {
        symtab = new Symtab(1);
        symtabStack = new SymtabStack();
        symtabPrints.resize(0);
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
        file.close();
    }
    void printSymtabStack()
    {
        int nestLevels = symtabStack->getCurrentNestingLevel();

        for(int i = 0; i <= nestLevels; i++)
        {
            cout << printSymtabStackAtLevel(i);
            test += printSymtabStackAtLevel(i);
        }
        for(string tabs : symtabPrints)
        {
            cout << tabs;
            test += tabs;
        }

    }
    string printSymtabStackAtLevel(int nestLevel)
    {
        string result = "";
        string level = to_string(nestLevel);
        //cout << "LEVEL: " << level << endl;
        result += "LEVEL: " + level + "\n";
        if(nestLevel == 0)
        {
            Symtab* temp = symtabStack->getSymtabLevel(nestLevel);
            SymtabEntry* owner = temp->getOwner();
            if(owner != nullptr)
            {
                //cout << owner->getName() << endl;
                result += "Owner:" + owner->getName() + "\n";
            }
            vector<SymtabEntry*> tabStack = temp->sortEntries();
            for(SymtabEntry* ent : tabStack)
            {
                //Typespec *temp2 = ent->getType();
                //cout << "Entry: " << ent->getName();
                result += "Entry: " + ent->getName();
                
                //cout << "\t\tkind: " << getKindString(ent->getKind());
                result += "\t\tkind: " + getKindString(ent->getKind()) + "\n";

                //cout << endl;
            }
        }
        else
        {
            Symtab* temp = symtabStack->getSymtabLevel(nestLevel);
            SymtabEntry* owner = temp->getOwner();
            if(owner != nullptr)
            {
                //cout << owner->getName() << endl;
                result += "Owner:" +  owner->getName() + "\n";
            }
            vector<SymtabEntry*> tabStack = temp->sortEntries();
            for(SymtabEntry* ent : tabStack)
            {
                Typespec *temp2 = ent->getType();
                //cout << "Entry: " << ent->getName();
                //cout << " type ";
                result +=  "Entry: " + ent->getName() + " type ";
                
                if(temp2->getForm() == TypeForm::SCALAR)
                {
                    string typ = checkTypeString(temp2);
                    result += typ + " SCALAR ";
                    // cout << typ;
                    
                    // cout << " SCALAR ";
                    
                }
                else if(temp2->getForm() == TypeForm::ARRAY)
                {
                    //cout << "ARRAY ";
                    result += "ARRAY ";
                    Typespec *tempType = temp2->getArrayIndexType();
                    string strType;
                    strType = checkTypeString(tempType);

                    //cout << "[" << strType << "] of";
                    result += "[" + strType + "] of";
                    Typespec *tempType2 = temp2->getArrayElementType();
                    while(tempType2->getForm() == TypeForm::ARRAY)
                    {
                        strType = checkTypeString(tempType2->getArrayIndexType());
                        //cout << " ARRAY " << "[" << strType << "] of";
                        result += " ARRAY [" + strType + "] of";
                        tempType2 = tempType2->getArrayElementType(); 
                    }
                    strType = checkTypeString(tempType2);
                    //cout << " " << strType;
                    result += " " + strType;
                }
                

                //cout << "\t\tkind: " << getKindString(ent->getKind());
                result += "\t\tkind: " + getKindString(ent->getKind()) + "\n";


                //cout << endl;
            }
        }
        return result;
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
        

        printTabs();
        cout << "<PROGRAM ";
        test += "<PROGRAM ";
        visit(ctx->programHead());
        visit(ctx->block()); 
        cout << "</PROGRAM>" << endl;
        test += "</PROGRAM>\n";
        tabs--;
        printSymtabStack();
        

        return nullptr;
        }; //yes

    Object visitProgramHead(PascalParser::ProgramHeadContext *ctx) override{ 
        
        //enter program name into the symbol table
        string programName = toLowerCase(ctx->identifier()->getText());
       
        cout << programName << ">" << endl;

        test += programName + ">\n";
        tabs++;

        SymtabEntry *programHead = symtabStack->enterLocal(programName, Kind::PROGRAM);
        programHead->setKind(Kind::PROGRAM);
        programHead->setRoutineSymtab(symtabStack->push());
        symtabStack->setProgramId(programHead);
        symtabStack->getLocalSymtab()->setOwner(programHead);

        PascalParser::IdentifierContext *ctx1 = ctx->identifier();
        ctx1->entry = programHead;
        

    return nullptr;};    //yes

    Object visitIdentifier(PascalParser::IdentifierContext *ctx) override{
        string varName = toLowerCase(ctx->getText());
        SymtabEntry *varId = symtabStack->lookup(varName);
        if(varId != nullptr)
        {
            // Typespec *temp = varId->getType();
            // if(temp->getForm() == TypeForm::ARRAY)
            // {
            //     cout << "ARRAY TYPE IN VARIABLE IDENTIFIER" << endl;
            // }
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

        return nullptr;};      //no

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
        PascalParser::ConstantIdentifierContext *constId = ctx->constantIdentifier();
        string constName = toLowerCase(constId->getText());
        SymtabEntry* constIdEntry = symtabStack->lookup(constName);
        if(constIdEntry == nullptr)
        {
            PascalParser::ConstantContext *constCtx = ctx->constant();
            Object constValue = visit(constCtx);
            constIdEntry = symtabStack->enterLocal(constName, Kind::CONSTANT);
            constIdEntry->setValue(constValue);
            constIdEntry->setType(constCtx->type);

            constId->entry = constIdEntry;
            constId->type  = constCtx->type;
        }
        else
        {
            cout << "Redeclared Identifier" << endl;
            constId->entry = constIdEntry;
            constId->type = initial->integerType;
        }

        constIdEntry->appendLineNumber(ctx->getStart()->getLine());

        
        return nullptr;
    }
    Object visitConstantIdentifier(PascalParser::ConstantIdentifierContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitTypeDefinitionPart(PascalParser::TypeDefinitionPartContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitTypeDefinition(PascalParser::TypeDefinitionContext *ctx) override {
        PascalParser::TypeIdentifierContext *typeIdCtx = ctx->typeIdentifier();
        string typeName = toLowerCase(typeIdCtx->getText());
        SymtabEntry *typeEntry = symtabStack->lookupLocal(typeName);
        Typespec *typespecCtx = nullptr;

        if(typeEntry != nullptr)
        {
            if(ctx->type_() != nullptr)
            {
                visit(ctx->type_());
                typeEntry = symtabStack->enterLocal(typeName, Kind::TYPE);
                typeEntry->setType(ctx->type_()->type);
                ctx->type_()->type->setIdentifier(typeEntry);
                typespecCtx = ctx->type_()->type;
            }
            else if(ctx->functionType() != nullptr)
            {
                visit(ctx->functionType());
                typeEntry = symtabStack->enterLocal(typeName, Kind::TYPE);
                typeEntry->setType(ctx->functionType()->type);
                ctx->functionType()->type->setIdentifier(typeEntry);
                typespecCtx = ctx->functionType()->type;
            }
        }
        else
        {
            cout << "REDECLARED IDENTIFIER" << endl;
        }

        typeIdCtx->entry = typeEntry;
        typeIdCtx->type = typespecCtx;
        typeEntry->appendLineNumber(ctx->getStart()->getLine());

        return nullptr;
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
        visitChildren(ctx);
        ctx->type = ctx->typeIdentifier()->type;
        
        return nullptr;
    }
    Object visitProcedureType(PascalParser::ProcedureTypeContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitVariableDeclarationPart(PascalParser::VariableDeclarationPartContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitVariableDeclaration(PascalParser::VariableDeclarationContext *ctx) override {

        
        //cout << "VISITNG VARIABLE DELCARATION " << ctx->getText() << endl;
        //reset varList
        varList.resize(0);
        varCtx.resize(0);

        //this is used for declarations like i, j, k : integer; i,j,k is the var list


        string ident_list = toLowerCase(ctx->identifierList()->getText());
        //cout << ident_list << endl;

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
    }
    Object visitProcedureAndFunctionDeclarationPart(PascalParser::ProcedureAndFunctionDeclarationPartContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitProcedureOrFunctionDeclaration(PascalParser::ProcedureOrFunctionDeclarationContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitProcedureDeclaration(PascalParser::ProcedureDeclarationContext *ctx) override {
        string procName = ctx->identifier()->getText();
        
        printTabs();
        cout << "<PROCEDURE " << procName << " line " << ctx->getStart()->getLine() << ">" << endl;
        test += "<PROCEDURE " + procName + " line " + to_string(ctx->getStart()->getLine()) + ">\n";

        tabs++;

        visit(ctx->identifier());


        SymtabEntry *varEn = symtabStack->lookupLocal(procName);
        if(varEn != nullptr)
        {
            cout << "Redeclared identifier to function" << endl;
        }
        else
        {
            SymtabEntry *newProc = symtabStack->enterLocal(procName, Kind::PROCEDURE);
            newProc->setKind(Kind::PROCEDURE);
            newProc->setType(initial->voidType);
            newProc->setRoutineSymtab(symtabStack->push());
            symtabStack->getLocalSymtab()->setOwner(newProc);
            
            ctx->entry = newProc;
        }
        

        if(ctx->formalParameterList() != nullptr)
        {
                visit(ctx->formalParameterList());
                
                varCtx.resize(0);

                //this is used for declarations like i, j, k : integer; i,j,k is the var list

                int count = ctx->formalParameterList()->formalParameterSection().size();
                PascalParser::FormalParameterSectionContext *formalParamCtx = nullptr;
                for(int i = 0; i < count; i++)
                {
                    varList.resize(0);
                    formalParamCtx = ctx->formalParameterList()->formalParameterSection()[i];
                    
                    string ident_list = toLowerCase(formalParamCtx->parameterGroup()->identifierList()->getText());
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

                    string tyName = formalParamCtx->parameterGroup()->typeIdentifier()->getText();
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

                    for( SymtabEntry *ent : varList)
                    {
                        ent->setType(type);
                    }

                }
        }
        visitChildren(ctx);

        tabs--;
        printTabs();
        cout << "<PROCEDURE />" << endl;
        test += "<PROCEDURE />\n";
        //cout << printSymtabStackAtLevel(symtabStack->getCurrentNestingLevel());



        //vector<SymtabEntry *> *parameters = 
        symtabPrints.push_back(printSymtabStackAtLevel(symtabStack->getCurrentNestingLevel()));
        symtabStack->pop();





        
        return nullptr;
    }
    Object visitFunctionDeclaration(PascalParser::FunctionDeclarationContext *ctx) override {
        string functionName = ctx->identifier()->getText();
        
        printTabs();
        cout << "<FUNCTION " << functionName << " line " << ctx->getStart()->getLine() << ">" << endl;
        test += "<FUNCTION " + functionName + " line " + to_string(ctx->getStart()->getLine()) + ">\n";
        
        tabs++;


        

        visit(ctx->identifier());
        visit(ctx->typeIdentifier());

        SymtabEntry *varEn = symtabStack->lookupLocal(functionName);
        Typespec *funcType = ctx->typeIdentifier()->type;
        if(varEn != nullptr)
        {
            cout << "Redeclared identifier to function" << endl;
        }
        else
        {
            SymtabEntry *newFunction = symtabStack->enterLocal(functionName, Kind::FUNCTION);
            newFunction->setKind(Kind::FUNCTION);
            newFunction->setRoutineSymtab(symtabStack->push());
            
            symtabStack->getLocalSymtab()->setOwner(newFunction);
            ctx->entry = newFunction;
            ctx->type = funcType;
            newFunction->setType(funcType);

        }


        if(ctx->formalParameterList() != nullptr)
        {
            visit(ctx->formalParameterList());
                varCtx.resize(0);

                //this is used for declarations like i, j, k : integer; i,j,k is the var list

                int count = ctx->formalParameterList()->formalParameterSection().size();
                PascalParser::FormalParameterSectionContext *formalParamCtx = nullptr;
                for(int i = 0; i < count; i++)
                {
                    varList.resize(0);
                    formalParamCtx = ctx->formalParameterList()->formalParameterSection()[i];
                    
                    string ident_list = toLowerCase(formalParamCtx->parameterGroup()->identifierList()->getText());
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

                    string tyName = formalParamCtx->parameterGroup()->typeIdentifier()->getText();
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

                    for( SymtabEntry *ent : varList)
                    {
                        ent->setType(type);
                    }

                }
        }
        visitChildren(ctx);
        
        tabs--;
        printTabs();
        cout << "<FUNCTION />" << endl;
        test += "<FUNCTION />\n";



        //vector<SymtabEntry *> *parameters = 
        symtabPrints.push_back(printSymtabStackAtLevel(symtabStack->getCurrentNestingLevel()));
        symtabStack->pop();
        




        return nullptr;
    }
    Object visitType_(PascalParser::Type_Context *ctx) override {
        PascalParser::StructuredTypeContext *strType = ctx->structuredType();
        PascalParser::SimpleTypeContext *simType = ctx->simpleType();
        if(strType != nullptr)
        {
            //cout << "STRUCTURED TYPE" << endl;
            visit(strType);
            ctx->type = strType->type;
            
        }
        else if(simType != nullptr)
        {
            //cout << "SIMP TYPE" << endl;
            visit(simType);
            ctx->type = simType->type;
        }
        else if(ctx->pointerType() != nullptr)
        {
            visit(ctx->pointerType());
            ctx->type = ctx->pointerType()->typeIdentifier()->type;
        } 
        return nullptr;
    }
    Object visitStructuredType(PascalParser::StructuredTypeContext *ctx) override {
        visit(ctx->unpackedStructuredType());
        ctx->type = ctx->unpackedStructuredType()->type;
        return nullptr;
    }
    Object visitUnpackedStructuredType(PascalParser::UnpackedStructuredTypeContext *ctx) override {
        Typespec *arr = new Typespec(TypeForm::ARRAY);
        //cout << "unpacked struc " << ctx->getText() << endl;
        PascalParser::ArrayTypeContext *ctx1 = ctx->arrayType(); //array ctx
        PascalParser::TypeListContext *ctx2 = ctx1->typeList(); // list ctx

        ctx->type = arr;
        int count = ctx2->simpleType().size();
        for(int i = 0; i < count; i++)
        {
            PascalParser::SimpleTypeContext *ctx3 = ctx2->simpleType()[i];
            //cout << ctx3->getText() << endl;
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
        //cout << "count: " << count << endl;


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
        if(ctx->identifier() != nullptr)
        {
            string constName = toLowerCase(ctx->identifier()->getText());
            SymtabEntry *constId = symtabStack->lookup(constName);
            
            if(constId != nullptr)
            {
                Kind kind = constId->getKind();
                if((kind != Kind::CONSTANT))
                {
                    cout << "Invalid Constant" << endl;
                }
                ctx->type = constId->getType();
                ctx->value = constId->getValue();
                constId->appendLineNumber(ctx->getStart()->getLine());
            }
            else
            {
                cout << "undeclared identifier" << endl;
                ctx->type = initial->integerType;
                ctx->value = 0;
            }

        }
        else if(ctx->string() !=nullptr)
        {
            string pascalString = ctx->string()->getText();
            string unquoted = pascalString.substr(1, pascalString.length()-2);
            size_t pos = 0;
            while ((pos = unquoted.find("''", pos)) != string::npos)
            {
                unquoted.replace(pos++, 2, "'");
            }

            pos = 0;
            while ((pos = unquoted.find("\"", pos)) != string::npos)
            {
                unquoted.replace(pos++, 2, "\\\"");
            }

            ctx->type = initial->stringType;
            ctx->value = new string(unquoted);
        }
        else if(ctx->constantChr() != nullptr)
        {
            ctx->type = initial->charType;
            ctx->value = ctx->constantChr()->unsignedInteger()->getText();
        }
        else if(ctx->unsignedNumber() != nullptr)
        {
            PascalParser::UnsignedNumberContext *unsignedCtx = ctx->unsignedNumber();
            if (unsignedCtx->unsignedInteger() != nullptr)
            {
                ctx->type = initial->integerType;
                ctx->value = stoi(ctx->getText());
            }
            else
            {
                ctx->type = initial->realType;
                ctx->value = stod(ctx->getText());
            }
        }
        return Object(ctx->value);

        };          //no

    Object visitUnsignedNumber(PascalParser::UnsignedNumberContext *ctx) override{
        if(ctx->unsignedInteger() != nullptr)
        {
            ctx->type = initial->integerType;
        }
        else if(ctx->unsignedReal() != nullptr)
        {
            ctx->type = initial->realType;
        }
        visitChildren(ctx);

        return nullptr;};  //no

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
                cout << "ERROR!" << endl;
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
            cout << "UNDECLARED" << endl;
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
        
        printTabs();
        cout << "<ASSIGN " << "line " << ctx->getStart()->getLine() << ">" << endl;
        int line = ctx->getStart()->getLine();
       
        test += "<ASSIGN line " + to_string(line) + ">\n";
        tabs++;
            visitChildren(ctx);
            Typespec *lhs = varCtx->type;
            Typespec *rhs = exprCtx->type;
            if(!TypeChecker::areAssignmentCompatible(lhs, rhs, initial))
            {
                cout << "NOT ASSIGNMENT COMPATIBLE" << endl;
            }
            //I THINK THIS NEEDS WORK I THINK IT SHOULD SET THE VALUE OF THE GIVEN VARIABLE


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
        ctx->type = variableDataType(ctx, variCtx->type);

        string varName = ctx->getText();
        int line = ctx->getStart()->getLine();
        printTabs();
        cout << "<VARIABLE " << varName << " line " << ctx->getStart()->getLine() << "/>" << endl;
        test += "<VARIABLE " + varName + " line " + to_string(line) + "/>\n";

        // visitChildren(ctx);
        //ctx->type = ctx->identifier()->type;
        return nullptr;}; 

    Object visitModifier(PascalParser::ModifierContext *ctx) override {
        return visitChildren(ctx);
    }
    Typespec *variableDataType(PascalParser::VariableContext *variCtx, Typespec *variableType)
    {
        Typespec *type = variableType;

        for(PascalParser::ModifierContext *modCtx : variCtx->modifier())
        {
            int count = modCtx->expression().size();
            PascalParser::ExpressionContext *expCtx = nullptr;
            // cout << "TESTING THIS NOW" << endl;
            // cout << count << endl;
            for(int i = 0; i < count; i++)
            {
                expCtx = modCtx->expression()[i];
            }
            // if(type->getForm() == TypeForm::ARRAY)
            // {
            //     cout << "VARIABLE DATA TYPE ARRAY" << endl;
            // }

            // if(modCtx->expression()[0] != nullptr){}
            // {
            //    if(type->getForm() == TypeForm::ARRAY)
            //    {
            //      Typespec *indType = type->getArrayIndexType();
            //      PascalParser::ExpressionContext *exCtx = modCtx->expression();
            //      visit(exCtx);
            //      if(indType->baseType() != exCtx->type->baseType())
            //      {
            //         cout << "ERROR" << endl;
            //      }
            //      type = type->getArrayElementType();
            //    }
            //    else
            //    {
            //      cout << "NOT ARRAY" << endl;
            //    }
            // }
        }
        return type;
    }

    Object visitVariableIdentifier(PascalParser::VariableIdentifierContext *ctx) override {
        string varName = toLowerCase(ctx->getText());
        SymtabEntry *varId = symtabStack->lookup(varName);
        if(varId != nullptr)
        {
            // Typespec *temp = varId->getType();
            // if(temp->getForm() == TypeForm::ARRAY)
            // {
            //     cout << "ARRAY TYPE IN VARIABLE IDENTIFIER" << endl;
            // }
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
        //cout << "EXPRESSION " << ctx->getText() << endl;
        PascalParser::SimpleExpressionContext *simpExprCtx = ctx->simpleExpression();

        //Typespec *simpleType1 = simpExprCtx->type;

        //check for second expression
        int count = ctx->relationaloperator().size();
        PascalParser::RelationaloperatorContext *ctx2 = nullptr;
        for(int i = 0; i < count; i++)
        {
            ctx2 = ctx->relationaloperator()[i];
        }

        Typespec *simpExpr1 = nullptr;


        if(ctx2 != nullptr)
        {
            //second expr
            int count2 = ctx->expression().size();
            PascalParser::ExpressionContext *expr2 = nullptr;
            for(int i = 0; i < count2; i++)
            {
                expr2 = ctx->expression()[i];
            }
            //cout << "SECOND EXPRESSION " << expr2->getText() << endl;

            Typespec *simpExpr2 = nullptr;


            //used for printing xml
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
                if(expr2 != nullptr)
                {
                    visit(ctx->simpleExpression());
                    simpExpr1 = ctx->simpleExpression()->type;
                    visit(expr2);
                    simpExpr2 = expr2->simpleExpression()->type;

                    if(!TypeChecker::TypeChareComparisonCompatible(simpExpr1, simpExpr2, initial))
                    {
                        cout << "NOT COMPARABLE" << endl;
                    }
                    simpExpr1 = initial->booleanType;

                }
            tabs--;
            printTabs();
            cout << "</" << toUpperCase(op) << ">" << endl;
            test += "</" + toUpperCase(op) + ">\n";
        }
        else
        {
            visit(ctx->simpleExpression());
            simpExpr1 = ctx->simpleExpression()->type;
        }

        ctx->type = simpExpr1;
        
        

        return nullptr;
        };

    Object visitRelationaloperator(PascalParser::RelationaloperatorContext *ctx) override{return visitChildren(ctx);};
        
    Object visitSimpleExpression(PascalParser::SimpleExpressionContext *ctx) override{
        //cout << "SIMPLE EXPRESSION "<< ctx->getText() << endl;
        PascalParser::AdditiveoperatorContext *ctx1 = nullptr;
        int count = ctx->additiveoperator().size();
        for(int i = 0; i < count; i++)
        {
            ctx1 = ctx->additiveoperator()[i];
        }
        
        Typespec *term1 = nullptr;

        if(ctx1 != nullptr)
        {
            // second simp expr
            count = ctx->simpleExpression().size();
            
            PascalParser::SimpleExpressionContext *simpExpr2 = nullptr;
            for(int i = 0; i < count; i++)
            {
                simpExpr2 = ctx->simpleExpression()[i];
            }
            //cout << "SECOND SIMPLE EXPRESSION "<< simpExpr2->getText() << endl;
            Typespec *term2 = nullptr;

            string op = ctx1->getText();
            op = toLowerCase(op);
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
                if(simpExpr2 != nullptr)
                {
                    visit(ctx->term());
                    term1 = ctx->term()->type;
                    visit(simpExpr2);
                    term2 = simpExpr2->term()->type;

                    if(op == "ADD")
                    {
                        //if both are int the result is int
                        if(TypeChecker::areBothInteger(term1, term2, initial))
                        {
                            term2 = initial->integerType;
                        }
                        //if atleast one is a real the result is a real
                        else if(TypeChecker::isAtLeastOneReal(term1, term2, initial))
                        {
                            term2 = initial->realType;
                        }
                        //string concating
                        else if(TypeChecker::areBothString(term1, term2, initial))
                        {
                            term2 = initial->stringType;
                        }
                        else
                        {
                            if (!TypeChecker::isIntegerOrReal(term1, initial))
                            {
                                cout << "Type mismatch factor 1" << endl;
                                term2 = initial->integerType;
                            }
                            if (!TypeChecker::isIntegerOrReal(term2, initial))
                            {
                                cout << "Type mismatch factor 2" << endl;
                                term2 = initial->integerType;
                            }
                        }

                    }
                    else if(op == "SUBTRACT")
                    {
                        //if both are int the result is int
                        if(TypeChecker::areBothInteger(term1, term2, initial))
                        {
                            term2 = initial->integerType;
                        }
                        //if atleast one is a real the result is a real
                        else if(TypeChecker::isAtLeastOneReal(term1, term2, initial))
                        {
                            term2 = initial->realType;
                        }
                        else
                        {
                            if (!TypeChecker::isIntegerOrReal(term1, initial))
                            {
                                cout << "Type mismatch factor 1" << endl;
                                term2 = initial->integerType;
                            }
                            if (!TypeChecker::isIntegerOrReal(term2, initial))
                            {
                                cout << "Type mismatch factor 2" << endl;
                                term2 = initial->integerType;
                            }
                        }

                    }
                    else if(op == "or")
                    {
                        if (!TypeChecker::isBoolean(term1, initial))
                        {
                            cout << "Type mismatch factor 1" << endl;
                            term2 = initial->booleanType;
                        }
                        if (!TypeChecker::isBoolean(term2, initial))
                        {
                            cout << "Type mismatch factor 2" << endl;
                            term2 = initial->booleanType;
                        }
                    }
                    //finished checking result
                    term1 = term2;

                }
                
            tabs--;
            printTabs();
            cout << "</" << toUpperCase(op) << ">" << endl;
            test += "</" + toUpperCase(op) + ">\n";
        }
        else
        {
            visit(ctx->term());
            term1 = ctx->term()->type;
        } 
        ctx->type = term1;

        return nullptr;
        };
        
    Object visitAdditiveoperator(PascalParser::AdditiveoperatorContext *ctx) override{return visitChildren(ctx);};

    Object visitTerm(PascalParser::TermContext *ctx) override{
        //cout << "TERM " << ctx->getText() << endl;
        int count = ctx->multiplicativeoperator().size();
        PascalParser::MultiplicativeoperatorContext *ctx1 = nullptr;
        for(int i = 0; i < count; i++)
        {
            ctx1 = ctx->multiplicativeoperator()[i];
        }

        PascalParser::FactorContext *facCtx = nullptr;
        Typespec *factor1 = nullptr;
        if(ctx1 != nullptr)
        {
            count = ctx->term().size();
            PascalParser::TermContext *termCtx = nullptr;
            for(int i = 0; i < count; i++)
            {
                termCtx = ctx->term()[i];
            }
            //cout << "SECOND TERM " << termCtx->getText() << endl;

            Typespec *factor2 = nullptr;


            string op = ctx1->getText();
            op = toLowerCase(op);
            //cout << "OP " << op << endl;
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
                if(termCtx != nullptr)
                {
                    visit(ctx->signedFactor());
                    factor1 = ctx->signedFactor()->factor()->type; 
                    visit(termCtx);
                    factor2 = termCtx->signedFactor()->factor()->type;

                    if(op == "MULTIPLY")
                    {
                        //result is int if both are int else if one is a real the result is a real
                        if(TypeChecker::areBothInteger(factor1, factor2, initial))
                        {
                            factor2 = initial->integerType;
                        }
                        else if(TypeChecker::isAtLeastOneReal(factor1, factor2, initial))
                        {
                            factor2 = initial->realType;
                        }
                        else
                        {
                            if (!TypeChecker::isIntegerOrReal(factor1, initial))
                            {
                                cout << "Type mismatch factor 1" << endl;
                                factor2 = initial->integerType;
                            }
                            if (!TypeChecker::isIntegerOrReal(factor2, initial))
                            {
                                cout << "Type mismatch factor 2" << endl;
                                factor2 = initial->integerType;
                            }
                        }

                    }
                    else if(op == "DIVIDE")
                    {
                        //result is always an real;
                        cout << "dividing!";
                        if(TypeChecker::areBothInteger(factor1, factor2, initial))
                        {
                            cout << " both are int" << endl;
                            factor2 = initial->realType;
                        }
                        else if(TypeChecker::isAtLeastOneReal(factor1, factor2, initial))
                        {
                            cout << " one is real " <<endl;
                            factor2 = initial->realType;
                        }
                        else
                        {
                            if (!TypeChecker::isIntegerOrReal(factor1, initial))
                            {
                                cout << "Type mismatch factor 1" << endl;
                                factor2 = initial->integerType;
                            }
                            if (!TypeChecker::isIntegerOrReal(factor2, initial))
                            {
                                cout << "Type mismatch factor 2" << endl;
                                factor2 = initial->integerType;
                            }
                        }

                    }
                    else if((op == "div") || (op == "mod"))
                    {
                        //result is an int
                        if (!TypeChecker::isInteger(factor1, initial))
                        {
                            cout << "Type mismatch factor 1" << endl;
                            factor2 = initial->integerType;
                        }
                        if (!TypeChecker::isInteger(factor2, initial))
                        {
                            cout << "Type mismatch factor 2" << endl;
                            factor2 = initial->integerType;
                        }
                        
                    }
                    else if(op == "and")
                    {
                        if (!TypeChecker::isBoolean(factor1, initial))
                        {
                            cout << "Type mismatch factor 1" << endl;
                            factor2 = initial->booleanType;
                        }
                        if (!TypeChecker::isBoolean(factor2, initial))
                        {
                            cout << "Type mismatch factor 2" << endl;
                            factor2 = initial->booleanType;
                        }
                    }

                    //finished checking the resulting type
                    factor1 = factor2;

                }
            tabs--;
            printTabs();
            cout << "</" << toUpperCase(op) << ">" << endl;
            test += "</" + toUpperCase(op) + ">\n";
        }
        else
        {
            visit(ctx->signedFactor());
            factor1 = ctx->signedFactor()->factor()->type;
        } 
        ctx->type = factor1;


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
        //cout << "FACTOR "<< ctx->getText() << endl;
        if(ctx->variable() != nullptr)
        {
            visit(ctx->variable());
            ctx->type = ctx->variable()->type;
            // cout << "variable type ";
            // string ty = checkTypeString(ctx->type);
            // cout << ty << endl;

        }
        else if(ctx->expression() != nullptr)
        {
            visit(ctx->expression());
            ctx->type = ctx->expression()->type;
            // cout << "FACTOR EXPRESSION" << endl;
            // cout << checkTypeString(ctx->type) << endl;
        }
        else if(ctx->unsignedConstant() != nullptr)
        {
            visit(ctx->unsignedConstant());
            ctx->type = ctx->unsignedConstant()->type;
            // cout << "unsigned const type ";
            // string ty = checkTypeString(ctx->type);
            // cout << ty << endl;
        }
        else if(ctx->NOT() != nullptr)
        {
            printTabs();
            cout << "<NEGATE>" << endl;
            test += "<NEGATE>\n";

            tabs++;

            visit(ctx->factor());

            tabs--;
            printTabs();
            cout << "</NEGATE>" << endl;
            test += "<NEGATE>\n";

            if(ctx->factor()->type != initial->booleanType)
            {
                cout << "Must be boolean" << endl;
            }
            ctx->type = initial->booleanType;
        }
        else if(ctx->bool_() != nullptr)
        {
            ctx->type = initial->booleanType;
        }

        return nullptr;};

    Object visitUnsignedConstant(PascalParser::UnsignedConstantContext *ctx) override{
        if(ctx->unsignedNumber() != nullptr)
        {
            visit(ctx->unsignedNumber());
            ctx->type = ctx->unsignedNumber()->type;
        }
        else if(ctx->constantChr() != nullptr)
        {
            ctx->type = initial->charType;
        }
        else if(ctx->string() != nullptr)
        {
            ctx->type = initial->stringType;
        }

        return nullptr;
    };

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
            if(!TypeChecker::isBoolean(ctx->expression()->type, initial))
            {
                cout << "Type must be boolean" << endl;
            }
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
                if(!TypeChecker::isBoolean(ctx->expression()->type, initial))
                {
                    cout << "Type must be boolean" << endl;
                }
                tabs--;
            printTabs();
            cout << "</TEST>" << endl;
            test += "</TEST>\n";
        tabs--;
            visit(ctx->statement());
        
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
                if(!TypeChecker::isBoolean(ctx->expression()->type, initial))
                {
                    cout << "Type must be boolean" << endl;
                }
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
                if(!TypeChecker::isBoolean(ctx->expression()->type, initial))
                {
                    cout << "Type must be boolean" << endl;
                }
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