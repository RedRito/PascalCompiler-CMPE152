#ifndef TREEVISITOR2_H_
#define TREEVISITOR2_H_

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
class TreeVisitor2 : public PascalBaseVisitor
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
    string output; //lazy
    int subCounter; // counter for routine labels
    int labCounter; // counter for local labels
    bool emptyLabel; // (hack): track if the last emited code was just label 
    


    void emit(const string label, const string code, const string value, const string comment="") {
        cout << ((label == "")? "" : label) << "\t";
        cout << code << "\t" << value;
        if (comment != "") 
            cout << "\t. " << comment;
        cout << endl;
        emptyLabel = (!label.empty() && code.empty());

        output += ((label == "")? "" : label) + "\t";
        output += code + "\t" + value;
        if (comment != "") output += "\t. " + comment;
        output += "\n";
    }

    void comment(const string text) {
        cout << "\t. " << text << endl;
        output += "\t. " + text + "\n";
    }

    void srcLine(int line, const string text, const string extra = "") {
        cout << ". LINE " << line << ": " << text;
        output +=  ". LINE " + to_string(line) + ": " + text;
        if (extra != "") cout << " " << extra;
        if (extra != "") output += " " + extra;
        cout << endl;
        output += "\n";
    }

public:
    //needs to create a symbol table stack and make a symbol table at stack(0)
    TreeVisitor2(): tabs(0), test(""), subCounter(0), labCounter(0) {
        symtab = new Symtab(1);
        symtabStack = new SymtabStack();
        symtabPrints.resize(0);
        initial = new Typespec();
        initial -> initialize(symtabStack);
        output = "";
    };
    
    virtual ~TreeVisitor2(){};
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
    void printCompile()
    {
        ofstream out;
        out.open("main.asm");
        if(out.fail())
        {
            cout << " COULD NOT OPEN THE FILE " << endl;
            exit(1);
        }
        out << output;
        out.close();
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
    //unused in treevisitor 2
    //prints the symtab stack at a given nesting level
    // param nestLevel the nesting level to string
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
    //unused
    // checks the type and returns as a string
    // param the typespec to stringify
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
    // gets the kind and converts to string
    // param kind, the kind to stringify
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
    //prints out certain amount of tabs
    void printTabs(){
        for(int i = 0; i < tabs; i++)
        {
            cout << "\t";
            test += "\t";
        }
    };

    // Generate code for subroutine (procedure or function) call
    void callSubroutine(antlr4::ParserRuleContext *ctx, bool isFunction) {

        int line = ctx->getStart()->getLine();
        srcLine(line, ctx->getText());

        PascalParser::IdentifierContext *identifier = (isFunction)?
            dynamic_cast<PascalParser::FunctionDesignatorContext*>(ctx)->identifier() :
            dynamic_cast<PascalParser::ProcedureStatementContext*>(ctx)->identifier();

        PascalParser::ParameterListContext* parameters = (isFunction)?
            dynamic_cast<PascalParser::FunctionDesignatorContext*>(ctx)->parameterList() :
            dynamic_cast<PascalParser::ProcedureStatementContext*>(ctx)->parameterList();

        string name = identifier->getText();       
        SymtabEntry *entry = symtabStack->lookup(name); // symbol to call
        if (entry == nullptr) {
            cout << "UNKNOWN IDENTIFIER \"" << name << "\"" << endl;
            return;
        }
        SymtabEntry *caller = symtabStack->getLocalSymtab()->getOwner();
        int curLevel = symtabStack->getCurrentNestingLevel();
        int procLevel = entry->getAttribute(SymtabKey::ROUTINE_NESTING_LEVEL);
        if (procLevel < curLevel) {
            // 
            cout << "CANNOT CALL OUTER ROUTINE \"" << name << "\"" << endl;
            return;
        }
        bool isNested = (procLevel > curLevel);
        
        // For nested call - save X to SMON[level]
        if (isNested && (curLevel > 1))
            emit("", "STX", "SMON[" + to_string(curLevel-1) + "]");

        // Parameters        
        if (parameters) {
            int count = parameters->actualParameter().size();
            int expandBytes = count*3;
            // Reserve stack space for the callee parameters
            emit("", "LDA", "#" + to_string(expandBytes));
            emit("", "SUBR", "A,X"); 
            // HACK: temporary increase caller's stack frame to cover the callee parameters area
            // This is required because parameter evaluation code may contain other routine calls
            // so take care and keep the stack integrity.
            int localBytes = caller->getAttribute(SymtabKey::ROUTINE_VARS_SIZE);
            caller->setAttribute(SymtabKey::ROUTINE_VARS_SIZE, (int)(localBytes + expandBytes));
            // Adjust local variables placement too
            for (auto item : symtabStack->getLocalSymtab()->sortEntries())
                if (item->getKind() == Kind::VARIABLE) {
                    int location = item->getAttribute(SymtabKey::LOCATION);
                    item->setAttribute(SymtabKey::LOCATION, location + expandBytes);
                }          

            // Parameters are expressions, they should be evaluated
            // So visit them to generate evaluation code
            for (int i = 0; i < count; i++) {
                auto param = parameters->actualParameter()[i];
                visit(param); // evaluate expression into A                
                // Save value
                emit("", "STA", to_string(i*3) + ",X", "value for \"" + name 
                    +"\" parameter " + to_string(i+1));
            }
            // Restore stack frame attributes
            caller->setAttribute(SymtabKey::ROUTINE_VARS_SIZE, localBytes);
            for (auto item : symtabStack->getLocalSymtab()->sortEntries())
                if (item->getKind() == Kind::VARIABLE) {
                    int location = item->getAttribute(SymtabKey::LOCATION);
                    item->setAttribute(SymtabKey::LOCATION, location - expandBytes);
                }          
        }
        // Actual call
        emit("", "JSUB", "SUB" + to_string((int)entry->getAttribute(SymtabKey::ROUTINE_SERIAL)),
            "call " + name);

        // No need to restore X, it is restored by callee
    }

    // Add subroutine parameters to the symtab and allocate them on stack frame
    void registerSubroutineParams(antlr4::ParserRuleContext *ctx) {

        PascalParser::FormalParameterListContext *params;
        SymtabEntry *entry;
        // Procedure?
        if (dynamic_cast<PascalParser::ProcedureDeclarationContext*>(ctx)) {
            params = dynamic_cast<PascalParser::ProcedureDeclarationContext*>(ctx)->formalParameterList();
            entry = dynamic_cast<PascalParser::ProcedureDeclarationContext*>(ctx)->entry;
        }
        // or function?
        if (dynamic_cast<PascalParser::FunctionDeclarationContext*>(ctx)) {
            params = dynamic_cast<PascalParser::FunctionDeclarationContext*>(ctx)->formalParameterList();
            entry = dynamic_cast<PascalParser::FunctionDeclarationContext*>(ctx)->entry;
        }
        int offset = 0; // position in parameters list in stack
        if(params != nullptr)
        {
                visit(params);                
                varCtx.resize(0);

                //this is used for declarations like i, j, k : integer; i,j,k is the var list
                int count = params->formalParameterSection().size();
                PascalParser::FormalParameterSectionContext *formalParamCtx = nullptr;
                for(int i = 0; i < count; i++)
                {
                    varList.resize(0);
                    formalParamCtx = params->formalParameterSection()[i];
                    
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
                        SymtabEntry *var = symtabStack->enterLocal(iden_array.at(i), Kind::VALUE_PARAMETER);                        
                        var->setAttribute(SymtabKey::LOCATION, offset); // set parameter position in stack
                        int size = 3; // default parameter size - change!
                        if (var->hasAttribute(SymtabKey::SIZE))
                            size = var->getAttribute(SymtabKey::SIZE);
                        offset += size;
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
        // Save amount of space allocated for parameters
        entry->setAttribute(SymtabKey::ROUTINE_PARMS_SIZE, offset);
        // Remember nesting level
        entry->setAttribute(SymtabKey::ROUTINE_NESTING_LEVEL, symtabStack->getCurrentNestingLevel());
    }

    Object visitProgram(PascalParser::ProgramContext *ctx) override{ 
        //visit the head of the program
        visit(ctx->programHead());
        //visit the block
        visit(ctx->block());         
        printCompile();
        return nullptr;
        };

    Object visitProgramHead(PascalParser::ProgramHeadContext *ctx) override{ 
        //enter program name into the symbol table
        string programName = toLowerCase(ctx->identifier()->getText());

        SymtabEntry *programHead = symtabStack->enterLocal(programName, Kind::PROGRAM);
        programHead->setKind(Kind::PROGRAM);
        programHead->setRoutineSymtab(symtabStack->push());
        symtabStack->setProgramId(programHead);
        symtabStack->getLocalSymtab()->setOwner(programHead);

        PascalParser::IdentifierContext *ctx1 = ctx->identifier();
        ctx1->entry = programHead;
        // Default attribute values for the main program block
        ctx1->entry->setAttribute(SymtabKey::ROUTINE_PARMS_SIZE, 0);
        ctx1->entry->setAttribute(SymtabKey::ROUTINE_VARS_SIZE, 0);
        ctx1->entry->setAttribute(SymtabKey::ROUTINE_SERIAL, 0);
        ctx1->entry->setAttribute(SymtabKey::ROUTINE_NESTING_LEVEL, 1);

        emit("main", "START", "3072");
        emit("", "LDX", "#3072", "initial stack pointer");
        emit("", "JSUB", "SUB0", "jump to the program's entry point");
        emit("STOP", "J", "STOP", "stop execution here");
        emit("DISP1", "WORD", "0", "stack frame pointers for 1..n nesting levels");
        emit("DISP2", "WORD", "0", "stack frame pointers for 1..n nesting levels");
        emit("DISP3", "WORD", "0", "stack frame pointers for 1..n nesting levels");
        emit("ZERO", "WORD", "0", "zero constant to compare with");


        //emitting print/writeln/write function
        emit("outdev", "BYTE", "5", "output device number");
        emit("pstr", "LDCH", "0,X", "A = character to output");
        emit("", "COMP", "#0", "check for null character");
        emit("", "JGT", "pstr1", "if not null go to print the character");
        emit("", "RSUB", "", "If null all done printing");

        emit("pstr1", "TD", "outdev", "test to see if output device is ready");
        emit("", "JEQ", "pstr1", "device not ready");
        emit("", "WD", "outdev", "output A register to output device");
        emit("", "TIX", "1", "increment X to point to next character");
        emit("", "J", "pstr", "loop");
        emit("newline", "WORD", "10", "NEWLINE constant");

        comment(" ");
       

    return nullptr;};  

    Object visitIdentifier(PascalParser::IdentifierContext *ctx) override{
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
        return nullptr;};

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
        //reset varList
        varList.resize(0);
        varCtx.resize(0);
        //this is used for declarations like i, j, k : integer; i,j,k is the var list
        string ident_list = toLowerCase(ctx->identifierList()->getText());

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
            // where variable is declared
            SymtabEntry *owner = var->getSymtab()->getOwner();            
            // define variable location in stack frame
            int offset = owner->getAttribute(SymtabKey::ROUTINE_VARS_SIZE);
            var->setAttribute(SymtabKey::LOCATION, offset);
            int size = 3; // TODO: replace with actual variable size, now assume that it is 3-byte integer
            offset += 3;
            owner->setAttribute(SymtabKey::ROUTINE_VARS_SIZE, offset);
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
        
        visit(ctx->identifier()); // visit procedure name identifier and add it to the symtab


        SymtabEntry *varEn = symtabStack->lookupLocal(procName);
        if(varEn != nullptr)
        {
            cout << "Redeclared identifier to function" << endl; // duplicated identifier
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
        
        registerSubroutineParams(ctx);
        // How many bytes allocated for local variables (for a procedure: initially - 0, for a function - 3)
        ctx->entry->setAttribute(SymtabKey::ROUTINE_VARS_SIZE, 0);

        visitChildren(ctx);

        //symtabPrints.push_back(printSymtabStackAtLevel(symtabStack->getCurrentNestingLevel()));
        symtabStack->pop();

        
        return nullptr;
    }
    Object visitFunctionDeclaration(PascalParser::FunctionDeclarationContext *ctx) override {
        string functionName = ctx->identifier()->getText();
        
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
        registerSubroutineParams(ctx);
        // How many bytes allocated for local variables (for a procedure: initially - 0, for a function - 3)
        ctx->entry->setAttribute(SymtabKey::ROUTINE_VARS_SIZE, 3);
        // Pseudo variable "result" to store return value
        SymtabEntry *result = symtabStack->enterLocal("result", Kind::VARIABLE);
        result->setType(funcType);
        result->setAttribute(SymtabKey::LOCATION, 0);
        result->setAttribute(SymtabKey::SIZE, 3);

        visitChildren(ctx);    

        //symtabPrints.push_back(printSymtabStackAtLevel(symtabStack->getCurrentNestingLevel()));
        symtabStack->pop();
        
        return nullptr;
    }


    Object visitType_(PascalParser::Type_Context *ctx) override {
        PascalParser::StructuredTypeContext *strType = ctx->structuredType();
        PascalParser::SimpleTypeContext *simType = ctx->simpleType();
        if(strType != nullptr)
        {
            visit(strType);
            ctx->type = strType->type;
            
        }
        else if(simType != nullptr)
        {
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
        PascalParser::ArrayTypeContext *ctx1 = ctx->arrayType(); //array ctx
        PascalParser::TypeListContext *ctx2 = ctx1->typeList(); // list ctx

        ctx->type = arr;
        int count = ctx2->simpleType().size();
        for(int i = 0; i < count; i++)
        {
            PascalParser::SimpleTypeContext *ctx3 = ctx2->simpleType()[i];
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
        SymtabEntry *en = arr->getIdentifier();
        return nullptr;
    }
    Object visitArrayType(PascalParser::ArrayTypeContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitTypeList(PascalParser::TypeListContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitPointerType(PascalParser::PointerTypeContext *ctx) override {
        return visitChildren(ctx);
    }
    Object visitLabel(PascalParser::LabelContext *ctx) override{return visitChildren(ctx);};                

    Object visitConstantVar(PascalParser::ConstantVarContext *ctx) override{return visitChildren(ctx);};    

    Object visitConstantChr(PascalParser::ConstantChrContext *ctx) override{
        string ch = ctx->getText();
        emit("", "BYTE", "C" + ch, "char " + ch);
        return visitChildren(ctx);};   

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
        };        
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

        return nullptr;}; 

    Object visitUnsignedInteger(PascalParser::UnsignedIntegerContext *ctx) override{
        string number = ctx->getText();
        emit("", "LDA", "#" + number); // load constant value to A

        return visitChildren(ctx);
        };   

    Object visitUnsignedReal(PascalParser::UnsignedRealContext *ctx) override{
        string number = ctx->getText();
        // emit("", "LDA", "") //emit real value to a register
        return nullptr;
        };   

    Object visitSign(PascalParser::SignContext *ctx) override{return visitChildren(ctx);};    

    Object visitBool_(PascalParser::Bool_Context *ctx) override{return visitChildren(ctx);}; 

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
    };    

    Object visitString(PascalParser::StringContext *ctx) override{
        string str = ctx->getText();
        int stringLabel = ++labCounter;
        emit("S" + to_string(stringLabel),"BYTE", "C" + str,"string " + str);
        emit("", "LDA", "#S" + to_string(stringLabel), "S"+ to_string(stringLabel) + "-> A");
        return nullptr;};                
    
    Object visitSimpleType(PascalParser::SimpleTypeContext *ctx) override{
        visit(ctx->typeIdentifier());
        ctx->type = ctx->typeIdentifier()->type;
        return nullptr;
    };         

    Object visitScalarType(PascalParser::ScalarTypeContext *ctx) override{return visitChildren(ctx);};

    Object visitStringtype(PascalParser::StringtypeContext *ctx) override{return visitChildren(ctx);};

    Object visitIdentifierList(PascalParser::IdentifierListContext *ctx) override{return visitChildren(ctx);};

    Object visitStatement(PascalParser::StatementContext *ctx) override{return visitChildren(ctx);}; 

    Object visitUnlabelledStatement(PascalParser::UnlabelledStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitSimpleStatement(PascalParser::SimpleStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitProcedureStatement(PascalParser::ProcedureStatementContext *ctx) override {
        // Procedure call
        callSubroutine(ctx, false);        
        return nullptr;
    }
    
    Object visitEmptyStatement_(PascalParser::EmptyStatement_Context *ctx) override {
        return visitChildren(ctx);
    }

    Object visitAssignmentStatement(PascalParser::AssignmentStatementContext *ctx) override{

        PascalParser::VariableContext *varCtx = ctx->variable();
        PascalParser::ExpressionContext *exprCtx = ctx->expression();

        string varName = ctx->variable()->getText();
        
        int line = ctx->getStart()->getLine();
        srcLine(line, ctx->getText());
        // Evaluate expression to A register
        visit(exprCtx);
        // Save A to the variable
        visit(varCtx);

        // Check assignment compatibility
        Typespec *lhs = varCtx->type;
        Typespec *rhs = exprCtx->type;
        if(!TypeChecker::areAssignmentCompatible(lhs, rhs, initial))
        {
            cout << "NOT ASSIGNMENT COMPATIBLE" << endl;
        }

        return nullptr;}; 

    Object visitVariable(PascalParser::VariableContext *ctx) override{
        //create a VARIABLE NODE
        PascalParser::VariableIdentifierContext *variCtx = ctx->variableIdentifier();
        visit(variCtx);
        ctx->entry = variCtx->entry;
        ctx->type = variableDataType(ctx, variCtx->type);        

        bool writeVar = false; // read or write variable?

        // If it is assignment - write to the var
        antlr4::tree::ParseTree *parent = ctx->parent;
        if (parent && (dynamic_cast<PascalParser::AssignmentStatementContext*>(parent)))
            writeVar = true;  

        //cout << "Variable: " << ctx->getText() << endl;
        int level = symtabStack->getCurrentNestingLevel();
        // Load variable value to A
        string name = ctx->getText();
        SymtabEntry *entry = symtabStack->lookup(name);
        if (entry == nullptr) {
            cout << "UNKNOWN IDENTIFIER \"" << name << "\"" << endl;
            return nullptr;
        }                
        // owner - routine where variable is declared
        SymtabEntry *owner = entry->getSymtab()->getOwner(); 
        int ownerLevel = owner->getAttribute(SymtabKey::ROUTINE_NESTING_LEVEL);
        // Access to non-local variable -> switch stack frame
        // TODO: consider direct access to global variables (ownerLevel == 1) to avoid
        // excessive stack switching
        bool switchStackFrame = (ownerLevel != level);
        if (switchStackFrame) {             
            emit("", "STX", "DISP" + to_string(level));
            emit("", "LDX", "DISP" + to_string(ownerLevel));
        }
        Kind kind = entry->getKind(); // kind of variable: regular variable, parameter, reference...
        int offset = entry->getAttribute(SymtabKey::LOCATION);
        // parameters are located after the return pointer, so add offset
        if (kind == Kind::VALUE_PARAMETER) 
            offset += 3 + (int)owner->getAttribute(SymtabKey::ROUTINE_VARS_SIZE);

        // Read or write value
        if (writeVar)
            emit("", "STA", to_string(offset) + ",X", "A -> " + name); // write variable
        else
            emit("", "LDA", to_string(offset) + ",X", name + " -> A"); // read variable

        if (switchStackFrame) {
            emit("", "LDX", "DISP" + to_string(level));
        }

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
            for(int i = 0; i < count; i++)
            {
                expCtx = modCtx->expression()[i];
            }
        }
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

                if(expr2 != nullptr)
                {
                    visit(ctx->simpleExpression());
                    simpExpr1 = ctx->simpleExpression()->type;
                    //simp expression 1 is stored in a
                    //move to B for comparison
                    emit("", "RMO", "A,B");

                    visit(expr2);
                    simpExpr2 = expr2->simpleExpression()->type;
                    //simp expression 2 is now stored in a


                    if(!TypeChecker::TypeChareComparisonCompatible(simpExpr1, simpExpr2, initial))
                    {
                        cout << "NOT COMPARABLE" << endl;
                    }
                    simpExpr1 = initial->booleanType;

                    //compare the two registers, determine the value, 1 or 0 / true or false
                    emit("","COMPR", "B,A", "comparing simp expression 1 to simp expression 2");
                    if(op == "EQUAL")
                    {
                        //both are equal the output is true
                        int equalLabel = ++labCounter;

                        emit("", "JEQ", "E"+to_string(equalLabel), "it is equal");
                        emit("", "LDA", "#0", "FALSE");
                        int endOf = ++labCounter;
                        emit("", "J", "E" + to_string(endOf), "end of expression check");
                        //true
                        emit("E"+to_string(equalLabel), "LDA", "#1", "TRUE");
                        //end
                        emit("E" + to_string(endOf), "RMO", "A,A", "end");
                    }
                    else if(op == "NE")
                    {
                        //both are equal the output is true
                        int equalLabel = ++labCounter;

                        emit("", "JEQ", "E"+to_string(equalLabel), "it is NOT equal");
                        emit("", "LDA", "#1", "TRUE");
                        int endOf = ++labCounter;
                        emit("", "J", "E" + to_string(endOf), "end of expression check");
                        //flase
                        emit("E"+to_string(equalLabel), "LDA", "#0", "FALSE");
                        //end
                        emit("E" + to_string(endOf), "RMO", "A,A", "end");
                    }
                    else if(op == "LT")
                    {
                        //both are equal the output is true
                        int equalLabel = ++labCounter;

                        emit("", "JLT", "E"+to_string(equalLabel), "it is less than");
                        emit("", "LDA", "#0", "FALSE");
                        int endOf = ++labCounter;
                        emit("", "J", "E" + to_string(endOf), "end of expression check");
                        //true
                        emit("E"+to_string(equalLabel), "LDA", "#1", "TRUE");
                        //end
                        emit("E" + to_string(endOf), "RMO", "A,A", "end");
                    }
                    else if(op == "GT")
                    {
                        //both are equal the output is true
                        int equalLabel = ++labCounter;

                        emit("", "JGT", "E"+to_string(equalLabel), "it is greater");
                        emit("", "LDA", "#0", "FALSE");
                        int endOf = ++labCounter;
                        emit("", "J", "E" + to_string(endOf), "end of expression check");
                        //true
                        emit("E"+to_string(equalLabel), "LDA", "#1", "TRUE");
                        //end
                        emit("E" + to_string(endOf), "RMO", "A,A", "end");
                    }
                    else if(op == "LTEQ")
                    {
                        //both are equal the output is true
                        int equalLabel = ++labCounter;

                        emit("", "JLT", "E"+to_string(equalLabel));
                        emit("", "LDA", "#0", "FALSE");
                        // NO LESS THAN EQUAL instruction
                        emit("E"+to_string(equalLabel),"","", "TRUE");

                        //now we check equality
                        equalLabel = ++labCounter;

                        emit("", "JEQ", "E"+to_string(equalLabel), "it is equal");
                        emit("", "LDA", "#0", "FALSE");
                        int endOf = ++labCounter;
                        emit("", "J", "E" + to_string(endOf), "end of expression check");
                        //true
                        emit("E"+to_string(equalLabel), "LDA", "#1", "TRUE");
                        //end
                        emit("E" + to_string(endOf), "RMO", "A,A", "end");
                    }
                    else if(op == "GTEQ")
                    {
                        //both are equal the output is true
                        int equalLabel = ++labCounter;

                        emit("", "JGT", "E"+to_string(equalLabel));
                        emit("", "LDA", "#0", "FALSE");
                        //true
                        emit("E"+to_string(equalLabel),"","", "TRUE");

                        //now we check equality
                        equalLabel = ++labCounter;

                        emit("", "JEQ", "E"+to_string(equalLabel), "it is equal");
                        emit("", "LDA", "#0", "FALSE");
                        int endOf = ++labCounter;
                        emit("", "J", "E" + to_string(endOf), "end of expression check");
                        //true
                        emit("E"+to_string(equalLabel), "LDA", "#1", "TRUE");
                        //end
                        emit("E" + to_string(endOf), "RMO", "A,A", "end");
                    }

                }
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
                if(simpExpr2 != nullptr)
                {
                    visit(simpExpr2);
                    term2 = simpExpr2->term()->type;
                    emit("", "RMO", "A,B");

                    visit(ctx->term());
                    term1 = ctx->term()->type;

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
                        emit("", "ADDR", "B,A");
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
                        emit("", "SUBR", "B,A");
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
            visitChildren(ctx);
        }else visitChildren(ctx);
        return nullptr;};
                    
    Object visitFactor(PascalParser::FactorContext *ctx) override{
        //cout << "FACTOR "<< ctx->getText() << endl;
        if(ctx->variable() != nullptr)
        {
            visit(ctx->variable());
            ctx->type = ctx->variable()->type;

        }
        else if (ctx->functionDesignator() != nullptr)
        {
            visit(ctx->functionDesignator());
            //ctx->type = ??? determine function result type
        }
        else if(ctx->expression() != nullptr)
        {
            visit(ctx->expression());
            ctx->type = ctx->expression()->type;
            
        }
        else if(ctx->unsignedConstant() != nullptr)
        {
            // cout << "UNSIGNED CONSTANT" << endl;
            visit(ctx->unsignedConstant());
            ctx->type = ctx->unsignedConstant()->type;
            
        }
        else if(ctx->NOT() != nullptr)
        {
            visit(ctx->factor());
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
            visit(ctx->constantChr());
            ctx->type = initial->charType;
        }
        else if(ctx->string() != nullptr)
        {
            visit(ctx->string());
            ctx->type = initial->stringType;
        }

        return nullptr;
    };

    Object visitFunctionDesignator(PascalParser::FunctionDesignatorContext *ctx) override {
        // function call
        callSubroutine(ctx, true);        
        return nullptr;
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
        visitChildren(ctx);
        return nullptr;};

    Object visitStructuredStatement(PascalParser::StructuredStatementContext *ctx) override{return visitChildren(ctx);};

    Object visitReptitiveStatement(PascalParser::ReptitiveStatementContext *ctx) override {return visitChildren(ctx);}

    Object visitWriteArguments(PascalParser::WriteArgumentsContext *ctx) override{
        //visit all the args
        PascalParser::WriteArgsContext *writeArgs = nullptr;
        int count = ctx->writeArgs().size();
        comment("visiting write args");
        for(int i = 0; i < count; i++)
        {
            visit(ctx->writeArgs()[i]);
            emit("", "JSUB", "pstr");
        }
        return nullptr;};

    Object visitWriteArgs(PascalParser::WriteArgsContext *ctx) override{return visitChildren(ctx);};

    Object visitWriteStatement(PascalParser::WriteStatementContext *ctx) override{
        comment("write statement");
        int line = ctx->getStart()->getLine();
        visitChildren(ctx);
        comment("end of write statment");
        return nullptr;};

    Object visitWritelnStatement(PascalParser::WritelnStatementContext *ctx) override{
        comment("writeln statement");
        int line = ctx->getStart()->getLine();
        visitChildren(ctx);

        //now we print the new line char
        emit("", "LDA", "newline", "newline");
        emit("", "JSUB", "pstr");
        comment("end of writeln statment");
        return nullptr;}; 

    Object visitCompoundStatement(PascalParser::CompoundStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();

        // Check if this compound is a subroutine body
        antlr4::tree::ParseTree *parent = ctx->parent;
        if (parent != NULL) parent = parent->parent;
        bool isFunction = false;
        bool isRoutineBody = (dynamic_cast<PascalParser::ProgramContext*>(parent) != NULL); // main?
        if (!isRoutineBody) {
            if (dynamic_cast<PascalParser::ProcedureDeclarationContext*>(parent)) 
                isRoutineBody = true;
            if (dynamic_cast<PascalParser::FunctionDeclarationContext*>(parent)) 
                isFunction = true;
            isRoutineBody |= isFunction;
        }            

        if (isRoutineBody) {
            // emit routine prologue code
            auto text = ctx->getStart()->getText();
            srcLine(line, text);
            int level = symtabStack->getCurrentNestingLevel();
            cout << ". subroutine body, nesting level " << level <<endl;
            output += ". subroutine body, nesting level " + to_string(level) + "\n";
            int subId = 0;
            // main body is called SUB0, so don't count on it
            if (level > 1) { 
                subCounter++;
                subId = subCounter;
            }
            Symtab* localSymtab = symtabStack->getLocalSymtab();
            SymtabEntry* owner = localSymtab->getOwner();
            owner->setAttribute(SymtabKey::ROUTINE_SERIAL, subId); // remember routine serial number            
            emit("SUB" + to_string(subId), "", ""); // label
            // List local symbols 
            int offsetToParams = 3 + (int)owner->getAttribute(SymtabKey::ROUTINE_VARS_SIZE);
            for (SymtabEntry* entry : localSymtab->sortEntries()) {
                Kind kind = entry->getKind();
                if ((kind == Kind::VALUE_PARAMETER) || (kind == Kind::REFERENCE_PARAMETER)) {
                    int location = offsetToParams + (int)entry->getAttribute(SymtabKey::LOCATION); 
                    comment("parameter \"" + entry->getName() + "\" at [X + " +
                        to_string(location) + "]");     
                }
            }
            for (SymtabEntry* entry : localSymtab->sortEntries()) 
                if (entry->getKind() == Kind::VARIABLE) 
                    comment("local variable \"" + entry->getName() + "\" at [X + " +
                        to_string((int)entry->getAttribute(SymtabKey::LOCATION)) + "]");      

            // How much stack space add for local variables
            int offset = owner->getAttribute(SymtabKey::ROUTINE_VARS_SIZE);
            // Emit entry code
            emit("", "LDA", "#" + to_string(offset+3)); // add 3 bytes to store return pointer (L)
            emit("", "SUBR", "A,X"); 
            emit("", "STL", to_string(offset) + ",X"); 
            // For main body only - save initial stack frame so don't need to do this for each call
            if (level == 1)
                emit("", "STX", "DISP1", "initial stack frame");
        }

        visitChildren(ctx);

        if (isRoutineBody) {
            // Subroutine epilogue
            Symtab* localSymtab = symtabStack->getLocalSymtab();
            SymtabEntry* owner = localSymtab->getOwner();    
            if (emptyLabel) {
                // Last line contains just only label, but unfortunately assembler doesn't allow
                // multiple consequtive labels without instructions. So insert a dummy NOP here to workaround.
                emit("", "RMO", "A,A");
            }
            int subId = owner->getAttribute(SymtabKey::ROUTINE_SERIAL);
            emit("END" + to_string(subId), "", ""); // exit label
            
            if (isFunction) // Load function result to A
                emit("", "LDA", "0,X", "result -> A");
            int offset = owner->getAttribute(SymtabKey::ROUTINE_VARS_SIZE);
            emit("", "LDL", to_string(offset) + ",X"); // load return address
            int frameSize = offset + 3 + (int)owner->getAttribute(SymtabKey::ROUTINE_PARMS_SIZE);
            emit("", "LDB", "#" + to_string(frameSize), "release stack frame");
            emit("", "ADDR", "B,X");
            emit("", "RSUB", "");
        }

        return nullptr;
        };

    Object visitStatements(PascalParser::StatementsContext *ctx) override{return visitChildren(ctx);};

    Object visitIfStatement(PascalParser::IfStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        srcLine(line, ctx->getStart()->getText() + 
            " " + ctx->expression()->getStart()->getText());
        visit(ctx->expression());

        /* TODO: Temporarily disabled to treat integer as boolean
        if(!TypeChecker::isBoolean(ctx->expression()->type, initial))
        {
            cout << "Expression type must be boolean for IF statement" << endl;
        }*/

        PascalParser::StatementContext *statement1 = ctx->statement(0);
        PascalParser::StatementContext *statement2 = ctx->statement(1);
        int elseLabel = ++labCounter;
        int endifLabel = ++labCounter;
        emit("", "COMP", "ZERO", "test if value is false");
        emit("", "JEQ", "L" + to_string((statement2 == nullptr)? endifLabel : elseLabel));
        comment("then statement");
        visit(statement1);
        // Is there ELSE part
        if (statement2 != nullptr) { 
            emit("", "J", "L" + to_string(endifLabel)); // omit ELSE part
            emit("L" + to_string(elseLabel), "", "");
            comment("else statement");
            visit(statement2);
        } 
        emit("L" + to_string(endifLabel), "", "", "end if");
        

        return nullptr;
    };

    Object visitCaseStatement(PascalParser::CaseStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        visitChildren(ctx);
        return nullptr;};

    Object visitCaseListElement(PascalParser::CaseListElementContext *ctx) override{return visitChildren(ctx);};

    Object visitWhileStatement(PascalParser::WhileStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();
        comment("start of while loop");
        //test condition
        int whileTest = ++labCounter;
        emit("W" + to_string(whileTest), "", "");
        visit(ctx->expression());
        emit("", "COMP", "ZERO", "test if value is false");
        //jump to end of loop if false
        
        int endOf = ++labCounter;
        emit("","JEQ", "W" + to_string(endOf), "jump to end");

        if(!TypeChecker::isBoolean(ctx->expression()->type, initial))
        {
            cout << "Type must be boolean" << endl;
        }
        visit(ctx->statement());
        emit("", "J", "W" + to_string(whileTest), "jump to start");

        emit("W" + to_string(endOf), "", "", "end of loop");
        return nullptr;};

    Object visitRepeatStatement(PascalParser::RepeatStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();

        PascalParser::StatementContext *statements = nullptr;
        int size = ctx->statements()->statement().size();
        int repeatLabel = ++labCounter;
        emit("R" + to_string(repeatLabel), "","", "Repeat statment");
        //visit all the statements in the loop
        visit(ctx->statements());

        //test condition
        visit(ctx->expression());
        //load test condition into A register
        emit("", "COMP", "ZERO", "test if value is false");
        //if condition is false go back to start
        //if value is not equal
        emit("", "JEQ", "R" + to_string(repeatLabel), "jump to start of repeat");
        comment("end of repeat statement");

        if(!TypeChecker::isBoolean(ctx->expression()->type, initial))
        {
            cout << "Type must be boolean" << endl;
        }
        return nullptr;};    
    
    Object visitForStatement(PascalParser::ForStatementContext *ctx) override{
        int line = ctx->getStart()->getLine();

        srcLine(line, ctx->getText());

        comment("For statment");

        string toOrDownTo;
        if(ctx->TO() != nullptr)
        {
            toOrDownTo = "TO";
            // emit to code
        }else toOrDownTo = "DOWNTO";
            //emit downto code

            visit(ctx->assignmentStatement());
            //variable in memory

                
                visit(ctx->expression());
                //test stored in A

                // just for now
                int level = symtabStack->getCurrentNestingLevel();
                string name = ctx->assignmentStatement()->variable()->getText();
                SymtabEntry *entry = symtabStack->lookup(name);
                if (entry == nullptr) {
                    cout << "UNKNOWN IDENTIFIER \"" << name << "\"" << endl;
                    return nullptr;
                }                
                // owner - routine where variable is declared
                SymtabEntry *owner = entry->getSymtab()->getOwner(); 
                int ownerLevel = owner->getAttribute(SymtabKey::ROUTINE_NESTING_LEVEL);
                // Access to non-local variable -> switch stack frame
                // TODO: consider direct access to global variables (ownerLevel == 1) to avoid
                // excessive stack switching
                bool switchStackFrame = (ownerLevel != level);
                if (switchStackFrame) {             
                    emit("", "STX", "DISP" + to_string(level));
                    emit("", "LDX", "DISP" + to_string(ownerLevel));
                }
                Kind kind = entry->getKind(); // kind of variable: regular variable, parameter, reference...
                int offset = entry->getAttribute(SymtabKey::LOCATION);
                // parameters are located after the return pointer, so add offset
                if (kind == Kind::VALUE_PARAMETER) 
                    offset += 3 + (int)owner->getAttribute(SymtabKey::ROUTINE_VARS_SIZE);

                emit("", "LDT", to_string(offset) + ",X", name + " -> T"); // read variable

                int testCondition = ++labCounter;

                emit("L" + to_string(testCondition), "COMPR", "A,T", "test if value is less than");
                
                int statementLabel = ++labCounter;
                if(toOrDownTo == "TO")
                {
                    //if condition not met
                    emit("", "JLT", "L" + to_string(statementLabel));
                }
                //if condition not met
                else emit("", "JGT", "L" + to_string(statementLabel));
                

                // if(!TypeChecker::isBoolean(ctx->expression()->type, initial))
                // {
                //     cout << "Type must be boolean" << endl;
                // }
            visit(ctx->statement());
            //increment or decrement //for now
            comment("incrementing / decrementing");

            emit("", "LDT", to_string(offset) + ",X", name + " -> T"); // read variable
            emit("", "LDS", "#1", "load 1 into register");
            toOrDownTo == "TO" ? emit("", "ADDR", "S,T", "Increment") : emit("", "SUBR", "S,T", "decrement");
            //store value back into memory
            emit("", "STT", to_string(offset) + ",X", "A -> " + name); // write variable
            visit(ctx->expression()); //restore test condition lazy way
            emit("", "J", "L"+ to_string(testCondition), "Retest condition");

            emit("L" + to_string(statementLabel), "", "", "end of for loop");
        comment("End of for statment");
        return nullptr;};
    //with statements will not be used in final check
    Object visitWithStatement(PascalParser::WithStatementContext *ctx) override{visitChildren(ctx);return nullptr;};      
};
#endif 