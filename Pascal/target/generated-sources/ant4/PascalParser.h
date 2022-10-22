
// Generated from Pascal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  PascalParser : public antlr4::Parser {
public:
  enum {
    AND = 1, ARRAY = 2, ASM = 3, BEGIN = 4, BREAK = 5, BOOLEAN = 6, CASE = 7, 
    CHAR = 8, CHR = 9, CONST = 10, CONSTRUCTOR = 11, CONTINUE = 12, DESTRUCTOR = 13, 
    DIV = 14, DO = 15, DOWNTO = 16, ELSE = 17, END = 18, FILE = 19, FOR = 20, 
    FUNCTION = 21, GOTO = 22, IF = 23, IN = 24, INLINE = 25, INTEGER = 26, 
    LABEL = 27, MOD = 28, NIL = 29, OBJECT = 30, WRITE = 31, WRITELN = 32, 
    NOT = 33, OF = 34, ON = 35, OPERATOR = 36, OR = 37, PACKED = 38, PROCEDURE = 39, 
    PROGRAM = 40, REAL = 41, RECORD = 42, REPEAT = 43, SET = 44, THEN = 45, 
    TO = 46, TYPE = 47, UNTIL = 48, VAR = 49, WHILE = 50, WITH = 51, ASSIGN = 52, 
    COLON = 53, EQUAL = 54, LBRACKET2 = 55, RBRACKET2 = 56, AT = 57, DOT = 58, 
    DOTDOT = 59, UNIT = 60, INTERFACE = 61, USES = 62, STRING = 63, IMPLEMENTATION = 64, 
    TRUE = 65, FALSE = 66, WS = 67, COMMENT_1 = 68, COMMENT_2 = 69, IDENT = 70, 
    STRING_LITERAL = 71, NUM_INT = 72, NUM_REAL = 73, SHL = 74, SHR = 75, 
    XOR = 76, IDENTIFIER = 77, PLUSOP = 78, MINUSOP = 79, MULTOP = 80, DIVOP = 81, 
    NE = 82, LTEQ = 83, GTEQ = 84, LT = 85, GT = 86, PLUSEQUAL = 87, MINUSEQUAL = 88, 
    MULTEQUAL = 89, DIVEQUAL = 90, CARAT = 91, SEMICOLON = 92, COMMA = 93, 
    LPAREN = 94, RPAREN = 95, LBRACKET = 96, RBRACKET = 97, LBRACE = 98, 
    RBRACE = 99, LCOMMENT = 100, RCOMMENT = 101
  };

  enum {
    RuleProgram = 0, RuleProgramHead = 1, RuleIdentifier = 2, RuleLabel = 3, 
    RuleConstantVar = 4, RuleConstantChr = 5, RuleConstant = 6, RuleUnsignedNumber = 7, 
    RuleUnsignedInteger = 8, RuleUnsignedReal = 9, RuleSign = 10, RuleBool_ = 11, 
    RuleTypeIdentifier = 12, RuleString = 13, RuleSimpleType = 14, RuleScalarType = 15, 
    RuleStringtype = 16, RuleIdentifierList = 17, RuleStatement = 18, RuleUnlabelledStatement = 19, 
    RuleSimpleStatement = 20, RuleEmptyStatement_ = 21, RuleAssignmentStatement = 22, 
    RuleVariable = 23, RuleExpression = 24, RuleRelationaloperator = 25, 
    RuleSimpleExpression = 26, RuleAdditiveoperator = 27, RuleTerm = 28, 
    RuleMultiplicativeoperator = 29, RuleSignedFactor = 30, RuleFactor = 31, 
    RuleUnsignedConstant = 32, RuleGotoStatement = 33, RuleStructuredStatement = 34, 
    RuleReptitiveStatement = 35, RuleWriteArguments = 36, RuleWriteArgs = 37, 
    RuleWriteStatement = 38, RuleWritelnStatement = 39, RuleCompoundStatement = 40, 
    RuleStatements = 41, RuleIfStatement = 42, RuleCaseStatement = 43, RuleCaseListElement = 44, 
    RuleWhileStatement = 45, RuleRepeatStatement = 46, RuleForStatement = 47, 
    RuleWithStatement = 48
  };

  PascalParser(antlr4::TokenStream *input);
  ~PascalParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class ProgramHeadContext;
  class IdentifierContext;
  class LabelContext;
  class ConstantVarContext;
  class ConstantChrContext;
  class ConstantContext;
  class UnsignedNumberContext;
  class UnsignedIntegerContext;
  class UnsignedRealContext;
  class SignContext;
  class Bool_Context;
  class TypeIdentifierContext;
  class StringContext;
  class SimpleTypeContext;
  class ScalarTypeContext;
  class StringtypeContext;
  class IdentifierListContext;
  class StatementContext;
  class UnlabelledStatementContext;
  class SimpleStatementContext;
  class EmptyStatement_Context;
  class AssignmentStatementContext;
  class VariableContext;
  class ExpressionContext;
  class RelationaloperatorContext;
  class SimpleExpressionContext;
  class AdditiveoperatorContext;
  class TermContext;
  class MultiplicativeoperatorContext;
  class SignedFactorContext;
  class FactorContext;
  class UnsignedConstantContext;
  class GotoStatementContext;
  class StructuredStatementContext;
  class ReptitiveStatementContext;
  class WriteArgumentsContext;
  class WriteArgsContext;
  class WriteStatementContext;
  class WritelnStatementContext;
  class CompoundStatementContext;
  class StatementsContext;
  class IfStatementContext;
  class CaseStatementContext;
  class CaseListElementContext;
  class WhileStatementContext;
  class RepeatStatementContext;
  class ForStatementContext;
  class WithStatementContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramHeadContext *programHead();
    CompoundStatementContext *compoundStatement();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *EOF();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ProgramHeadContext : public antlr4::ParserRuleContext {
  public:
    ProgramHeadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROGRAM();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *LPAREN();
    IdentifierListContext *identifierList();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *UNIT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramHeadContext* programHead();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();

  class  LabelContext : public antlr4::ParserRuleContext {
  public:
    LabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedIntegerContext *unsignedInteger();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelContext* label();

  class  ConstantVarContext : public antlr4::ParserRuleContext {
  public:
    ConstantVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *EQUAL();
    ConstantContext *constant();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantVarContext* constantVar();

  class  ConstantChrContext : public antlr4::ParserRuleContext {
  public:
    ConstantChrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHR();
    antlr4::tree::TerminalNode *LPAREN();
    UnsignedIntegerContext *unsignedInteger();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantChrContext* constantChr();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedNumberContext *unsignedNumber();
    SignContext *sign();
    IdentifierContext *identifier();
    StringContext *string();
    ConstantChrContext *constantChr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantContext* constant();

  class  UnsignedNumberContext : public antlr4::ParserRuleContext {
  public:
    UnsignedNumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedIntegerContext *unsignedInteger();
    UnsignedRealContext *unsignedReal();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnsignedNumberContext* unsignedNumber();

  class  UnsignedIntegerContext : public antlr4::ParserRuleContext {
  public:
    UnsignedIntegerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUM_INT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnsignedIntegerContext* unsignedInteger();

  class  UnsignedRealContext : public antlr4::ParserRuleContext {
  public:
    UnsignedRealContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUM_REAL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnsignedRealContext* unsignedReal();

  class  SignContext : public antlr4::ParserRuleContext {
  public:
    SignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUSOP();
    antlr4::tree::TerminalNode *MINUSOP();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SignContext* sign();

  class  Bool_Context : public antlr4::ParserRuleContext {
  public:
    Bool_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bool_Context* bool_();

  class  TypeIdentifierContext : public antlr4::ParserRuleContext {
  public:
    TypeIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *BOOLEAN();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *REAL();
    antlr4::tree::TerminalNode *STRING();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeIdentifierContext* typeIdentifier();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING_LITERAL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringContext* string();

  class  SimpleTypeContext : public antlr4::ParserRuleContext {
  public:
    SimpleTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScalarTypeContext *scalarType();
    TypeIdentifierContext *typeIdentifier();
    StringtypeContext *stringtype();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleTypeContext* simpleType();

  class  ScalarTypeContext : public antlr4::ParserRuleContext {
  public:
    ScalarTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    IdentifierListContext *identifierList();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScalarTypeContext* scalarType();

  class  StringtypeContext : public antlr4::ParserRuleContext {
  public:
    StringtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    IdentifierContext *identifier();
    UnsignedNumberContext *unsignedNumber();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringtypeContext* stringtype();

  class  IdentifierListContext : public antlr4::ParserRuleContext {
  public:
    IdentifierListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierListContext* identifierList();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LabelContext *label();
    antlr4::tree::TerminalNode *COLON();
    UnlabelledStatementContext *unlabelledStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  UnlabelledStatementContext : public antlr4::ParserRuleContext {
  public:
    UnlabelledStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleStatementContext *simpleStatement();
    StructuredStatementContext *structuredStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnlabelledStatementContext* unlabelledStatement();

  class  SimpleStatementContext : public antlr4::ParserRuleContext {
  public:
    SimpleStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentStatementContext *assignmentStatement();
    GotoStatementContext *gotoStatement();
    EmptyStatement_Context *emptyStatement_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleStatementContext* simpleStatement();

  class  EmptyStatement_Context : public antlr4::ParserRuleContext {
  public:
    EmptyStatement_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EmptyStatement_Context* emptyStatement_();

  class  AssignmentStatementContext : public antlr4::ParserRuleContext {
  public:
    AssignmentStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentStatementContext* assignmentStatement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LBRACKET();
    antlr4::tree::TerminalNode* LBRACKET(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACKET();
    antlr4::tree::TerminalNode* RBRACKET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LBRACKET2();
    antlr4::tree::TerminalNode* LBRACKET2(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACKET2();
    antlr4::tree::TerminalNode* RBRACKET2(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CARAT();
    antlr4::tree::TerminalNode* CARAT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleExpressionContext *simpleExpression();
    RelationaloperatorContext *relationaloperator();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  RelationaloperatorContext : public antlr4::ParserRuleContext {
  public:
    RelationaloperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *NE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LTEQ();
    antlr4::tree::TerminalNode *GTEQ();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *IN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationaloperatorContext* relationaloperator();

  class  SimpleExpressionContext : public antlr4::ParserRuleContext {
  public:
    SimpleExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    AdditiveoperatorContext *additiveoperator();
    SimpleExpressionContext *simpleExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleExpressionContext* simpleExpression();

  class  AdditiveoperatorContext : public antlr4::ParserRuleContext {
  public:
    AdditiveoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUSOP();
    antlr4::tree::TerminalNode *MINUSOP();
    antlr4::tree::TerminalNode *OR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AdditiveoperatorContext* additiveoperator();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SignedFactorContext *signedFactor();
    MultiplicativeoperatorContext *multiplicativeoperator();
    TermContext *term();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();

  class  MultiplicativeoperatorContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeoperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MULTOP();
    antlr4::tree::TerminalNode *DIVOP();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *AND();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultiplicativeoperatorContext* multiplicativeoperator();

  class  SignedFactorContext : public antlr4::ParserRuleContext {
  public:
    SignedFactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FactorContext *factor();
    antlr4::tree::TerminalNode *PLUSOP();
    antlr4::tree::TerminalNode *MINUSOP();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SignedFactorContext* signedFactor();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    UnsignedConstantContext *unsignedConstant();
    antlr4::tree::TerminalNode *NOT();
    FactorContext *factor();
    Bool_Context *bool_();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FactorContext* factor();

  class  UnsignedConstantContext : public antlr4::ParserRuleContext {
  public:
    UnsignedConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedNumberContext *unsignedNumber();
    ConstantChrContext *constantChr();
    StringContext *string();
    antlr4::tree::TerminalNode *NIL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnsignedConstantContext* unsignedConstant();

  class  GotoStatementContext : public antlr4::ParserRuleContext {
  public:
    GotoStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GOTO();
    LabelContext *label();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GotoStatementContext* gotoStatement();

  class  StructuredStatementContext : public antlr4::ParserRuleContext {
  public:
    StructuredStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CompoundStatementContext *compoundStatement();
    ReptitiveStatementContext *reptitiveStatement();
    IfStatementContext *ifStatement();
    CaseStatementContext *caseStatement();
    WithStatementContext *withStatement();
    WriteStatementContext *writeStatement();
    WritelnStatementContext *writelnStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructuredStatementContext* structuredStatement();

  class  ReptitiveStatementContext : public antlr4::ParserRuleContext {
  public:
    ReptitiveStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    WhileStatementContext *whileStatement();
    RepeatStatementContext *repeatStatement();
    ForStatementContext *forStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReptitiveStatementContext* reptitiveStatement();

  class  WriteArgumentsContext : public antlr4::ParserRuleContext {
  public:
    WriteArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<WriteArgsContext *> writeArgs();
    WriteArgsContext* writeArgs(size_t i);
    antlr4::tree::TerminalNode *COMMA();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WriteArgumentsContext* writeArguments();

  class  WriteArgsContext : public antlr4::ParserRuleContext {
  public:
    WriteArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WriteArgsContext* writeArgs();

  class  WriteStatementContext : public antlr4::ParserRuleContext {
  public:
    WriteStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WRITE();
    antlr4::tree::TerminalNode *LPAREN();
    WriteArgumentsContext *writeArguments();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WriteStatementContext* writeStatement();

  class  WritelnStatementContext : public antlr4::ParserRuleContext {
  public:
    WritelnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WRITELN();
    antlr4::tree::TerminalNode *LPAREN();
    WriteArgumentsContext *writeArguments();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WritelnStatementContext* writelnStatement();

  class  CompoundStatementContext : public antlr4::ParserRuleContext {
  public:
    CompoundStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEGIN();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *END();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompoundStatementContext* compoundStatement();

  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementsContext* statements();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *THEN();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *ELSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStatementContext* ifStatement();

  class  CaseStatementContext : public antlr4::ParserRuleContext {
  public:
    CaseStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *OF();
    std::vector<CaseListElementContext *> caseListElement();
    CaseListElementContext* caseListElement(size_t i);
    antlr4::tree::TerminalNode *END();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    StatementsContext *statements();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseStatementContext* caseStatement();

  class  CaseListElementContext : public antlr4::ParserRuleContext {
  public:
    CaseListElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
    antlr4::tree::TerminalNode *COLON();
    StatementContext *statement();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseListElementContext* caseListElement();

  class  WhileStatementContext : public antlr4::ParserRuleContext {
  public:
    WhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *DO();
    StatementContext *statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStatementContext* whileStatement();

  class  RepeatStatementContext : public antlr4::ParserRuleContext {
  public:
    RepeatStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REPEAT();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *UNTIL();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RepeatStatementContext* repeatStatement();

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    AssignmentStatementContext *assignmentStatement();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *DO();
    StatementContext *statement();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *DOWNTO();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStatementContext* forStatement();

  class  WithStatementContext : public antlr4::ParserRuleContext {
  public:
    WithStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);
    antlr4::tree::TerminalNode *DO();
    StatementContext *statement();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WithStatementContext* withStatement();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

