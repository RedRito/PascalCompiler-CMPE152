
   #include "PassOne/Typespec.h"
   #include "PassOne/Symtab.h"
   #include "PassOne/SymtabStack.h"
   #include "Object.h"
   using namespace PassOne::symtab;
   using namespace PassOne::type;


// Generated from Pascal.g4 by ANTLR 4.7.2


#include "PascalVisitor.h"

#include "PascalParser.h"


using namespace antlrcpp;
using namespace antlr4;

PascalParser::PascalParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PascalParser::~PascalParser() {
  delete _interpreter;
}

std::string PascalParser::getGrammarFileName() const {
  return "Pascal.g4";
}

const std::vector<std::string>& PascalParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PascalParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

PascalParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ProgramHeadContext* PascalParser::ProgramContext::programHead() {
  return getRuleContext<PascalParser::ProgramHeadContext>(0);
}

PascalParser::BlockContext* PascalParser::ProgramContext::block() {
  return getRuleContext<PascalParser::BlockContext>(0);
}

tree::TerminalNode* PascalParser::ProgramContext::DOT() {
  return getToken(PascalParser::DOT, 0);
}

tree::TerminalNode* PascalParser::ProgramContext::EOF() {
  return getToken(PascalParser::EOF, 0);
}


size_t PascalParser::ProgramContext::getRuleIndex() const {
  return PascalParser::RuleProgram;
}


antlrcpp::Any PascalParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProgramContext* PascalParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, PascalParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    programHead();
    setState(167);
    block();
    setState(168);
    match(PascalParser::DOT);
    setState(169);
    match(PascalParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramHeadContext ------------------------------------------------------------------

PascalParser::ProgramHeadContext::ProgramHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ProgramHeadContext::PROGRAM() {
  return getToken(PascalParser::PROGRAM, 0);
}

PascalParser::IdentifierContext* PascalParser::ProgramHeadContext::identifier() {
  return getRuleContext<PascalParser::IdentifierContext>(0);
}

tree::TerminalNode* PascalParser::ProgramHeadContext::SEMICOLON() {
  return getToken(PascalParser::SEMICOLON, 0);
}

tree::TerminalNode* PascalParser::ProgramHeadContext::LPAREN() {
  return getToken(PascalParser::LPAREN, 0);
}

PascalParser::IdentifierListContext* PascalParser::ProgramHeadContext::identifierList() {
  return getRuleContext<PascalParser::IdentifierListContext>(0);
}

tree::TerminalNode* PascalParser::ProgramHeadContext::RPAREN() {
  return getToken(PascalParser::RPAREN, 0);
}

tree::TerminalNode* PascalParser::ProgramHeadContext::UNIT() {
  return getToken(PascalParser::UNIT, 0);
}


size_t PascalParser::ProgramHeadContext::getRuleIndex() const {
  return PascalParser::RuleProgramHead;
}


antlrcpp::Any PascalParser::ProgramHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProgramHead(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProgramHeadContext* PascalParser::programHead() {
  ProgramHeadContext *_localctx = _tracker.createInstance<ProgramHeadContext>(_ctx, getState());
  enterRule(_localctx, 2, PascalParser::RuleProgramHead);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(185);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::PROGRAM: {
        enterOuterAlt(_localctx, 1);
        setState(171);
        match(PascalParser::PROGRAM);
        setState(172);
        identifier();
        setState(177);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PascalParser::LPAREN) {
          setState(173);
          match(PascalParser::LPAREN);
          setState(174);
          identifierList();
          setState(175);
          match(PascalParser::RPAREN);
        }
        setState(179);
        match(PascalParser::SEMICOLON);
        break;
      }

      case PascalParser::UNIT: {
        enterOuterAlt(_localctx, 2);
        setState(181);
        match(PascalParser::UNIT);
        setState(182);
        identifier();
        setState(183);
        match(PascalParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

PascalParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::IdentifierContext::IDENT() {
  return getToken(PascalParser::IDENT, 0);
}


size_t PascalParser::IdentifierContext::getRuleIndex() const {
  return PascalParser::RuleIdentifier;
}


antlrcpp::Any PascalParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::IdentifierContext* PascalParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 4, PascalParser::RuleIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    match(PascalParser::IDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

PascalParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::CompoundStatementContext* PascalParser::BlockContext::compoundStatement() {
  return getRuleContext<PascalParser::CompoundStatementContext>(0);
}

std::vector<PascalParser::LabelDeclarationPartContext *> PascalParser::BlockContext::labelDeclarationPart() {
  return getRuleContexts<PascalParser::LabelDeclarationPartContext>();
}

PascalParser::LabelDeclarationPartContext* PascalParser::BlockContext::labelDeclarationPart(size_t i) {
  return getRuleContext<PascalParser::LabelDeclarationPartContext>(i);
}

std::vector<PascalParser::ConstantDefinitionPartContext *> PascalParser::BlockContext::constantDefinitionPart() {
  return getRuleContexts<PascalParser::ConstantDefinitionPartContext>();
}

PascalParser::ConstantDefinitionPartContext* PascalParser::BlockContext::constantDefinitionPart(size_t i) {
  return getRuleContext<PascalParser::ConstantDefinitionPartContext>(i);
}

std::vector<PascalParser::TypeDefinitionPartContext *> PascalParser::BlockContext::typeDefinitionPart() {
  return getRuleContexts<PascalParser::TypeDefinitionPartContext>();
}

PascalParser::TypeDefinitionPartContext* PascalParser::BlockContext::typeDefinitionPart(size_t i) {
  return getRuleContext<PascalParser::TypeDefinitionPartContext>(i);
}

std::vector<PascalParser::ProcedureAndFunctionDeclarationPartContext *> PascalParser::BlockContext::procedureAndFunctionDeclarationPart() {
  return getRuleContexts<PascalParser::ProcedureAndFunctionDeclarationPartContext>();
}

PascalParser::ProcedureAndFunctionDeclarationPartContext* PascalParser::BlockContext::procedureAndFunctionDeclarationPart(size_t i) {
  return getRuleContext<PascalParser::ProcedureAndFunctionDeclarationPartContext>(i);
}

std::vector<PascalParser::VariableDeclarationPartContext *> PascalParser::BlockContext::variableDeclarationPart() {
  return getRuleContexts<PascalParser::VariableDeclarationPartContext>();
}

PascalParser::VariableDeclarationPartContext* PascalParser::BlockContext::variableDeclarationPart(size_t i) {
  return getRuleContext<PascalParser::VariableDeclarationPartContext>(i);
}

std::vector<PascalParser::UsesUnitsPartContext *> PascalParser::BlockContext::usesUnitsPart() {
  return getRuleContexts<PascalParser::UsesUnitsPartContext>();
}

PascalParser::UsesUnitsPartContext* PascalParser::BlockContext::usesUnitsPart(size_t i) {
  return getRuleContext<PascalParser::UsesUnitsPartContext>(i);
}

std::vector<tree::TerminalNode *> PascalParser::BlockContext::IMPLEMENTATION() {
  return getTokens(PascalParser::IMPLEMENTATION);
}

tree::TerminalNode* PascalParser::BlockContext::IMPLEMENTATION(size_t i) {
  return getToken(PascalParser::IMPLEMENTATION, i);
}


size_t PascalParser::BlockContext::getRuleIndex() const {
  return PascalParser::RuleBlock;
}


antlrcpp::Any PascalParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::BlockContext* PascalParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 6, PascalParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 10) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 10)) & ((1ULL << (PascalParser::CONST - 10))
      | (1ULL << (PascalParser::FUNCTION - 10))
      | (1ULL << (PascalParser::LABEL - 10))
      | (1ULL << (PascalParser::PROCEDURE - 10))
      | (1ULL << (PascalParser::TYPE - 10))
      | (1ULL << (PascalParser::VAR - 10))
      | (1ULL << (PascalParser::USES - 10))
      | (1ULL << (PascalParser::IMPLEMENTATION - 10)))) != 0)) {
      setState(196);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PascalParser::LABEL: {
          setState(189);
          labelDeclarationPart();
          break;
        }

        case PascalParser::CONST: {
          setState(190);
          constantDefinitionPart();
          break;
        }

        case PascalParser::TYPE: {
          setState(191);
          typeDefinitionPart();
          break;
        }

        case PascalParser::FUNCTION:
        case PascalParser::PROCEDURE: {
          setState(192);
          procedureAndFunctionDeclarationPart();
          break;
        }

        case PascalParser::VAR: {
          setState(193);
          variableDeclarationPart();
          break;
        }

        case PascalParser::USES: {
          setState(194);
          usesUnitsPart();
          break;
        }

        case PascalParser::IMPLEMENTATION: {
          setState(195);
          match(PascalParser::IMPLEMENTATION);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(200);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(201);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UsesUnitsPartContext ------------------------------------------------------------------

PascalParser::UsesUnitsPartContext::UsesUnitsPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::UsesUnitsPartContext::USES() {
  return getToken(PascalParser::USES, 0);
}

PascalParser::IdentifierListContext* PascalParser::UsesUnitsPartContext::identifierList() {
  return getRuleContext<PascalParser::IdentifierListContext>(0);
}

tree::TerminalNode* PascalParser::UsesUnitsPartContext::SEMICOLON() {
  return getToken(PascalParser::SEMICOLON, 0);
}


size_t PascalParser::UsesUnitsPartContext::getRuleIndex() const {
  return PascalParser::RuleUsesUnitsPart;
}


antlrcpp::Any PascalParser::UsesUnitsPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitUsesUnitsPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::UsesUnitsPartContext* PascalParser::usesUnitsPart() {
  UsesUnitsPartContext *_localctx = _tracker.createInstance<UsesUnitsPartContext>(_ctx, getState());
  enterRule(_localctx, 8, PascalParser::RuleUsesUnitsPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    match(PascalParser::USES);
    setState(204);
    identifierList();
    setState(205);
    match(PascalParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelDeclarationPartContext ------------------------------------------------------------------

PascalParser::LabelDeclarationPartContext::LabelDeclarationPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::LabelDeclarationPartContext::LABEL() {
  return getToken(PascalParser::LABEL, 0);
}

std::vector<PascalParser::LabelContext *> PascalParser::LabelDeclarationPartContext::label() {
  return getRuleContexts<PascalParser::LabelContext>();
}

PascalParser::LabelContext* PascalParser::LabelDeclarationPartContext::label(size_t i) {
  return getRuleContext<PascalParser::LabelContext>(i);
}

tree::TerminalNode* PascalParser::LabelDeclarationPartContext::SEMICOLON() {
  return getToken(PascalParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> PascalParser::LabelDeclarationPartContext::COMMA() {
  return getTokens(PascalParser::COMMA);
}

tree::TerminalNode* PascalParser::LabelDeclarationPartContext::COMMA(size_t i) {
  return getToken(PascalParser::COMMA, i);
}


size_t PascalParser::LabelDeclarationPartContext::getRuleIndex() const {
  return PascalParser::RuleLabelDeclarationPart;
}


antlrcpp::Any PascalParser::LabelDeclarationPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitLabelDeclarationPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::LabelDeclarationPartContext* PascalParser::labelDeclarationPart() {
  LabelDeclarationPartContext *_localctx = _tracker.createInstance<LabelDeclarationPartContext>(_ctx, getState());
  enterRule(_localctx, 10, PascalParser::RuleLabelDeclarationPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    match(PascalParser::LABEL);
    setState(208);
    label();
    setState(213);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(209);
      match(PascalParser::COMMA);
      setState(210);
      label();
      setState(215);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(216);
    match(PascalParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDefinitionPartContext ------------------------------------------------------------------

PascalParser::ConstantDefinitionPartContext::ConstantDefinitionPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ConstantDefinitionPartContext::CONST() {
  return getToken(PascalParser::CONST, 0);
}

std::vector<PascalParser::ConstantDefinitionContext *> PascalParser::ConstantDefinitionPartContext::constantDefinition() {
  return getRuleContexts<PascalParser::ConstantDefinitionContext>();
}

PascalParser::ConstantDefinitionContext* PascalParser::ConstantDefinitionPartContext::constantDefinition(size_t i) {
  return getRuleContext<PascalParser::ConstantDefinitionContext>(i);
}

std::vector<tree::TerminalNode *> PascalParser::ConstantDefinitionPartContext::SEMICOLON() {
  return getTokens(PascalParser::SEMICOLON);
}

tree::TerminalNode* PascalParser::ConstantDefinitionPartContext::SEMICOLON(size_t i) {
  return getToken(PascalParser::SEMICOLON, i);
}


size_t PascalParser::ConstantDefinitionPartContext::getRuleIndex() const {
  return PascalParser::RuleConstantDefinitionPart;
}


antlrcpp::Any PascalParser::ConstantDefinitionPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantDefinitionPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantDefinitionPartContext* PascalParser::constantDefinitionPart() {
  ConstantDefinitionPartContext *_localctx = _tracker.createInstance<ConstantDefinitionPartContext>(_ctx, getState());
  enterRule(_localctx, 12, PascalParser::RuleConstantDefinitionPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(PascalParser::CONST);
    setState(222); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(219);
      constantDefinition();
      setState(220);
      match(PascalParser::SEMICOLON);
      setState(224); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PascalParser::IDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDefinitionContext ------------------------------------------------------------------

PascalParser::ConstantDefinitionContext::ConstantDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ConstantIdentifierContext* PascalParser::ConstantDefinitionContext::constantIdentifier() {
  return getRuleContext<PascalParser::ConstantIdentifierContext>(0);
}

tree::TerminalNode* PascalParser::ConstantDefinitionContext::EQUAL() {
  return getToken(PascalParser::EQUAL, 0);
}

PascalParser::ConstantContext* PascalParser::ConstantDefinitionContext::constant() {
  return getRuleContext<PascalParser::ConstantContext>(0);
}


size_t PascalParser::ConstantDefinitionContext::getRuleIndex() const {
  return PascalParser::RuleConstantDefinition;
}


antlrcpp::Any PascalParser::ConstantDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantDefinition(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantDefinitionContext* PascalParser::constantDefinition() {
  ConstantDefinitionContext *_localctx = _tracker.createInstance<ConstantDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 14, PascalParser::RuleConstantDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    constantIdentifier();
    setState(227);
    match(PascalParser::EQUAL);
    setState(228);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantIdentifierContext ------------------------------------------------------------------

PascalParser::ConstantIdentifierContext::ConstantIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ConstantIdentifierContext::IDENT() {
  return getToken(PascalParser::IDENT, 0);
}


size_t PascalParser::ConstantIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleConstantIdentifier;
}


antlrcpp::Any PascalParser::ConstantIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantIdentifierContext* PascalParser::constantIdentifier() {
  ConstantIdentifierContext *_localctx = _tracker.createInstance<ConstantIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 16, PascalParser::RuleConstantIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(PascalParser::IDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefinitionPartContext ------------------------------------------------------------------

PascalParser::TypeDefinitionPartContext::TypeDefinitionPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::TypeDefinitionPartContext::TYPE() {
  return getToken(PascalParser::TYPE, 0);
}

std::vector<PascalParser::TypeDefinitionContext *> PascalParser::TypeDefinitionPartContext::typeDefinition() {
  return getRuleContexts<PascalParser::TypeDefinitionContext>();
}

PascalParser::TypeDefinitionContext* PascalParser::TypeDefinitionPartContext::typeDefinition(size_t i) {
  return getRuleContext<PascalParser::TypeDefinitionContext>(i);
}

std::vector<tree::TerminalNode *> PascalParser::TypeDefinitionPartContext::SEMICOLON() {
  return getTokens(PascalParser::SEMICOLON);
}

tree::TerminalNode* PascalParser::TypeDefinitionPartContext::SEMICOLON(size_t i) {
  return getToken(PascalParser::SEMICOLON, i);
}


size_t PascalParser::TypeDefinitionPartContext::getRuleIndex() const {
  return PascalParser::RuleTypeDefinitionPart;
}


antlrcpp::Any PascalParser::TypeDefinitionPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypeDefinitionPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TypeDefinitionPartContext* PascalParser::typeDefinitionPart() {
  TypeDefinitionPartContext *_localctx = _tracker.createInstance<TypeDefinitionPartContext>(_ctx, getState());
  enterRule(_localctx, 18, PascalParser::RuleTypeDefinitionPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(PascalParser::TYPE);
    setState(236); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(233);
      typeDefinition();
      setState(234);
      match(PascalParser::SEMICOLON);
      setState(238); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::BOOLEAN)
      | (1ULL << PascalParser::CHAR)
      | (1ULL << PascalParser::INTEGER)
      | (1ULL << PascalParser::REAL)
      | (1ULL << PascalParser::STRING))) != 0) || _la == PascalParser::IDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDefinitionContext ------------------------------------------------------------------

PascalParser::TypeDefinitionContext::TypeDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::TypeIdentifierContext* PascalParser::TypeDefinitionContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}

tree::TerminalNode* PascalParser::TypeDefinitionContext::EQUAL() {
  return getToken(PascalParser::EQUAL, 0);
}

PascalParser::Type_Context* PascalParser::TypeDefinitionContext::type_() {
  return getRuleContext<PascalParser::Type_Context>(0);
}

PascalParser::FunctionTypeContext* PascalParser::TypeDefinitionContext::functionType() {
  return getRuleContext<PascalParser::FunctionTypeContext>(0);
}

PascalParser::ProcedureTypeContext* PascalParser::TypeDefinitionContext::procedureType() {
  return getRuleContext<PascalParser::ProcedureTypeContext>(0);
}


size_t PascalParser::TypeDefinitionContext::getRuleIndex() const {
  return PascalParser::RuleTypeDefinition;
}


antlrcpp::Any PascalParser::TypeDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypeDefinition(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TypeDefinitionContext* PascalParser::typeDefinition() {
  TypeDefinitionContext *_localctx = _tracker.createInstance<TypeDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 20, PascalParser::RuleTypeDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    typeIdentifier();
    setState(241);
    match(PascalParser::EQUAL);
    setState(245);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::ARRAY:
      case PascalParser::BOOLEAN:
      case PascalParser::CHAR:
      case PascalParser::INTEGER:
      case PascalParser::PACKED:
      case PascalParser::REAL:
      case PascalParser::STRING:
      case PascalParser::IDENT:
      case PascalParser::CARAT:
      case PascalParser::LPAREN: {
        setState(242);
        type_();
        break;
      }

      case PascalParser::FUNCTION: {
        setState(243);
        functionType();
        break;
      }

      case PascalParser::PROCEDURE: {
        setState(244);
        procedureType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterListContext ------------------------------------------------------------------

PascalParser::FormalParameterListContext::FormalParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::FormalParameterListContext::LPAREN() {
  return getToken(PascalParser::LPAREN, 0);
}

std::vector<PascalParser::FormalParameterSectionContext *> PascalParser::FormalParameterListContext::formalParameterSection() {
  return getRuleContexts<PascalParser::FormalParameterSectionContext>();
}

PascalParser::FormalParameterSectionContext* PascalParser::FormalParameterListContext::formalParameterSection(size_t i) {
  return getRuleContext<PascalParser::FormalParameterSectionContext>(i);
}

tree::TerminalNode* PascalParser::FormalParameterListContext::RPAREN() {
  return getToken(PascalParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> PascalParser::FormalParameterListContext::SEMICOLON() {
  return getTokens(PascalParser::SEMICOLON);
}

tree::TerminalNode* PascalParser::FormalParameterListContext::SEMICOLON(size_t i) {
  return getToken(PascalParser::SEMICOLON, i);
}


size_t PascalParser::FormalParameterListContext::getRuleIndex() const {
  return PascalParser::RuleFormalParameterList;
}


antlrcpp::Any PascalParser::FormalParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFormalParameterList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FormalParameterListContext* PascalParser::formalParameterList() {
  FormalParameterListContext *_localctx = _tracker.createInstance<FormalParameterListContext>(_ctx, getState());
  enterRule(_localctx, 22, PascalParser::RuleFormalParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    match(PascalParser::LPAREN);
    setState(248);
    formalParameterSection();
    setState(253);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::SEMICOLON) {
      setState(249);
      match(PascalParser::SEMICOLON);
      setState(250);
      formalParameterSection();
      setState(255);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(256);
    match(PascalParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterSectionContext ------------------------------------------------------------------

PascalParser::FormalParameterSectionContext::FormalParameterSectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ParameterGroupContext* PascalParser::FormalParameterSectionContext::parameterGroup() {
  return getRuleContext<PascalParser::ParameterGroupContext>(0);
}

tree::TerminalNode* PascalParser::FormalParameterSectionContext::VAR() {
  return getToken(PascalParser::VAR, 0);
}

tree::TerminalNode* PascalParser::FormalParameterSectionContext::FUNCTION() {
  return getToken(PascalParser::FUNCTION, 0);
}

tree::TerminalNode* PascalParser::FormalParameterSectionContext::PROCEDURE() {
  return getToken(PascalParser::PROCEDURE, 0);
}


size_t PascalParser::FormalParameterSectionContext::getRuleIndex() const {
  return PascalParser::RuleFormalParameterSection;
}


antlrcpp::Any PascalParser::FormalParameterSectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFormalParameterSection(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FormalParameterSectionContext* PascalParser::formalParameterSection() {
  FormalParameterSectionContext *_localctx = _tracker.createInstance<FormalParameterSectionContext>(_ctx, getState());
  enterRule(_localctx, 24, PascalParser::RuleFormalParameterSection);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(265);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(258);
        parameterGroup();
        break;
      }

      case PascalParser::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(259);
        match(PascalParser::VAR);
        setState(260);
        parameterGroup();
        break;
      }

      case PascalParser::FUNCTION: {
        enterOuterAlt(_localctx, 3);
        setState(261);
        match(PascalParser::FUNCTION);
        setState(262);
        parameterGroup();
        break;
      }

      case PascalParser::PROCEDURE: {
        enterOuterAlt(_localctx, 4);
        setState(263);
        match(PascalParser::PROCEDURE);
        setState(264);
        parameterGroup();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterGroupContext ------------------------------------------------------------------

PascalParser::ParameterGroupContext::ParameterGroupContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IdentifierListContext* PascalParser::ParameterGroupContext::identifierList() {
  return getRuleContext<PascalParser::IdentifierListContext>(0);
}

tree::TerminalNode* PascalParser::ParameterGroupContext::COLON() {
  return getToken(PascalParser::COLON, 0);
}

PascalParser::TypeIdentifierContext* PascalParser::ParameterGroupContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}


size_t PascalParser::ParameterGroupContext::getRuleIndex() const {
  return PascalParser::RuleParameterGroup;
}


antlrcpp::Any PascalParser::ParameterGroupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameterGroup(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParameterGroupContext* PascalParser::parameterGroup() {
  ParameterGroupContext *_localctx = _tracker.createInstance<ParameterGroupContext>(_ctx, getState());
  enterRule(_localctx, 26, PascalParser::RuleParameterGroup);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    identifierList();
    setState(268);
    match(PascalParser::COLON);
    setState(269);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionTypeContext ------------------------------------------------------------------

PascalParser::FunctionTypeContext::FunctionTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::FunctionTypeContext::FUNCTION() {
  return getToken(PascalParser::FUNCTION, 0);
}

tree::TerminalNode* PascalParser::FunctionTypeContext::COLON() {
  return getToken(PascalParser::COLON, 0);
}

PascalParser::TypeIdentifierContext* PascalParser::FunctionTypeContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}

PascalParser::FormalParameterListContext* PascalParser::FunctionTypeContext::formalParameterList() {
  return getRuleContext<PascalParser::FormalParameterListContext>(0);
}


size_t PascalParser::FunctionTypeContext::getRuleIndex() const {
  return PascalParser::RuleFunctionType;
}


antlrcpp::Any PascalParser::FunctionTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFunctionType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FunctionTypeContext* PascalParser::functionType() {
  FunctionTypeContext *_localctx = _tracker.createInstance<FunctionTypeContext>(_ctx, getState());
  enterRule(_localctx, 28, PascalParser::RuleFunctionType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    match(PascalParser::FUNCTION);
    setState(273);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::LPAREN) {
      setState(272);
      formalParameterList();
    }
    setState(275);
    match(PascalParser::COLON);
    setState(276);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureTypeContext ------------------------------------------------------------------

PascalParser::ProcedureTypeContext::ProcedureTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ProcedureTypeContext::PROCEDURE() {
  return getToken(PascalParser::PROCEDURE, 0);
}

PascalParser::FormalParameterListContext* PascalParser::ProcedureTypeContext::formalParameterList() {
  return getRuleContext<PascalParser::FormalParameterListContext>(0);
}


size_t PascalParser::ProcedureTypeContext::getRuleIndex() const {
  return PascalParser::RuleProcedureType;
}


antlrcpp::Any PascalParser::ProcedureTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProcedureType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProcedureTypeContext* PascalParser::procedureType() {
  ProcedureTypeContext *_localctx = _tracker.createInstance<ProcedureTypeContext>(_ctx, getState());
  enterRule(_localctx, 30, PascalParser::RuleProcedureType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    match(PascalParser::PROCEDURE);
    setState(280);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::LPAREN) {
      setState(279);
      formalParameterList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationPartContext ------------------------------------------------------------------

PascalParser::VariableDeclarationPartContext::VariableDeclarationPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::VariableDeclarationPartContext::VAR() {
  return getToken(PascalParser::VAR, 0);
}

std::vector<PascalParser::VariableDeclarationContext *> PascalParser::VariableDeclarationPartContext::variableDeclaration() {
  return getRuleContexts<PascalParser::VariableDeclarationContext>();
}

PascalParser::VariableDeclarationContext* PascalParser::VariableDeclarationPartContext::variableDeclaration(size_t i) {
  return getRuleContext<PascalParser::VariableDeclarationContext>(i);
}

std::vector<tree::TerminalNode *> PascalParser::VariableDeclarationPartContext::SEMICOLON() {
  return getTokens(PascalParser::SEMICOLON);
}

tree::TerminalNode* PascalParser::VariableDeclarationPartContext::SEMICOLON(size_t i) {
  return getToken(PascalParser::SEMICOLON, i);
}


size_t PascalParser::VariableDeclarationPartContext::getRuleIndex() const {
  return PascalParser::RuleVariableDeclarationPart;
}


antlrcpp::Any PascalParser::VariableDeclarationPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableDeclarationPartContext* PascalParser::variableDeclarationPart() {
  VariableDeclarationPartContext *_localctx = _tracker.createInstance<VariableDeclarationPartContext>(_ctx, getState());
  enterRule(_localctx, 32, PascalParser::RuleVariableDeclarationPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(282);
    match(PascalParser::VAR);
    setState(283);
    variableDeclaration();
    setState(288);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(284);
        match(PascalParser::SEMICOLON);
        setState(285);
        variableDeclaration(); 
      }
      setState(290);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
    setState(291);
    match(PascalParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

PascalParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IdentifierListContext* PascalParser::VariableDeclarationContext::identifierList() {
  return getRuleContext<PascalParser::IdentifierListContext>(0);
}

tree::TerminalNode* PascalParser::VariableDeclarationContext::COLON() {
  return getToken(PascalParser::COLON, 0);
}

PascalParser::Type_Context* PascalParser::VariableDeclarationContext::type_() {
  return getRuleContext<PascalParser::Type_Context>(0);
}


size_t PascalParser::VariableDeclarationContext::getRuleIndex() const {
  return PascalParser::RuleVariableDeclaration;
}


antlrcpp::Any PascalParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableDeclarationContext* PascalParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 34, PascalParser::RuleVariableDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    identifierList();
    setState(294);
    match(PascalParser::COLON);
    setState(295);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureAndFunctionDeclarationPartContext ------------------------------------------------------------------

PascalParser::ProcedureAndFunctionDeclarationPartContext::ProcedureAndFunctionDeclarationPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ProcedureOrFunctionDeclarationContext* PascalParser::ProcedureAndFunctionDeclarationPartContext::procedureOrFunctionDeclaration() {
  return getRuleContext<PascalParser::ProcedureOrFunctionDeclarationContext>(0);
}

tree::TerminalNode* PascalParser::ProcedureAndFunctionDeclarationPartContext::SEMICOLON() {
  return getToken(PascalParser::SEMICOLON, 0);
}


size_t PascalParser::ProcedureAndFunctionDeclarationPartContext::getRuleIndex() const {
  return PascalParser::RuleProcedureAndFunctionDeclarationPart;
}


antlrcpp::Any PascalParser::ProcedureAndFunctionDeclarationPartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProcedureAndFunctionDeclarationPart(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProcedureAndFunctionDeclarationPartContext* PascalParser::procedureAndFunctionDeclarationPart() {
  ProcedureAndFunctionDeclarationPartContext *_localctx = _tracker.createInstance<ProcedureAndFunctionDeclarationPartContext>(_ctx, getState());
  enterRule(_localctx, 36, PascalParser::RuleProcedureAndFunctionDeclarationPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    procedureOrFunctionDeclaration();
    setState(298);
    match(PascalParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureOrFunctionDeclarationContext ------------------------------------------------------------------

PascalParser::ProcedureOrFunctionDeclarationContext::ProcedureOrFunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ProcedureDeclarationContext* PascalParser::ProcedureOrFunctionDeclarationContext::procedureDeclaration() {
  return getRuleContext<PascalParser::ProcedureDeclarationContext>(0);
}

PascalParser::FunctionDeclarationContext* PascalParser::ProcedureOrFunctionDeclarationContext::functionDeclaration() {
  return getRuleContext<PascalParser::FunctionDeclarationContext>(0);
}


size_t PascalParser::ProcedureOrFunctionDeclarationContext::getRuleIndex() const {
  return PascalParser::RuleProcedureOrFunctionDeclaration;
}


antlrcpp::Any PascalParser::ProcedureOrFunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProcedureOrFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProcedureOrFunctionDeclarationContext* PascalParser::procedureOrFunctionDeclaration() {
  ProcedureOrFunctionDeclarationContext *_localctx = _tracker.createInstance<ProcedureOrFunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 38, PascalParser::RuleProcedureOrFunctionDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(302);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::PROCEDURE: {
        enterOuterAlt(_localctx, 1);
        setState(300);
        procedureDeclaration();
        break;
      }

      case PascalParser::FUNCTION: {
        enterOuterAlt(_localctx, 2);
        setState(301);
        functionDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureDeclarationContext ------------------------------------------------------------------

PascalParser::ProcedureDeclarationContext::ProcedureDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ProcedureDeclarationContext::PROCEDURE() {
  return getToken(PascalParser::PROCEDURE, 0);
}

PascalParser::IdentifierContext* PascalParser::ProcedureDeclarationContext::identifier() {
  return getRuleContext<PascalParser::IdentifierContext>(0);
}

tree::TerminalNode* PascalParser::ProcedureDeclarationContext::SEMICOLON() {
  return getToken(PascalParser::SEMICOLON, 0);
}

PascalParser::BlockContext* PascalParser::ProcedureDeclarationContext::block() {
  return getRuleContext<PascalParser::BlockContext>(0);
}

PascalParser::FormalParameterListContext* PascalParser::ProcedureDeclarationContext::formalParameterList() {
  return getRuleContext<PascalParser::FormalParameterListContext>(0);
}


size_t PascalParser::ProcedureDeclarationContext::getRuleIndex() const {
  return PascalParser::RuleProcedureDeclaration;
}


antlrcpp::Any PascalParser::ProcedureDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProcedureDeclaration(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProcedureDeclarationContext* PascalParser::procedureDeclaration() {
  ProcedureDeclarationContext *_localctx = _tracker.createInstance<ProcedureDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 40, PascalParser::RuleProcedureDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    match(PascalParser::PROCEDURE);
    setState(305);
    identifier();
    setState(307);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::LPAREN) {
      setState(306);
      formalParameterList();
    }
    setState(309);
    match(PascalParser::SEMICOLON);
    setState(310);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

PascalParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::FunctionDeclarationContext::FUNCTION() {
  return getToken(PascalParser::FUNCTION, 0);
}

PascalParser::IdentifierContext* PascalParser::FunctionDeclarationContext::identifier() {
  return getRuleContext<PascalParser::IdentifierContext>(0);
}

tree::TerminalNode* PascalParser::FunctionDeclarationContext::COLON() {
  return getToken(PascalParser::COLON, 0);
}

PascalParser::TypeIdentifierContext* PascalParser::FunctionDeclarationContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}

tree::TerminalNode* PascalParser::FunctionDeclarationContext::SEMICOLON() {
  return getToken(PascalParser::SEMICOLON, 0);
}

PascalParser::BlockContext* PascalParser::FunctionDeclarationContext::block() {
  return getRuleContext<PascalParser::BlockContext>(0);
}

PascalParser::FormalParameterListContext* PascalParser::FunctionDeclarationContext::formalParameterList() {
  return getRuleContext<PascalParser::FormalParameterListContext>(0);
}


size_t PascalParser::FunctionDeclarationContext::getRuleIndex() const {
  return PascalParser::RuleFunctionDeclaration;
}


antlrcpp::Any PascalParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FunctionDeclarationContext* PascalParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 42, PascalParser::RuleFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    match(PascalParser::FUNCTION);
    setState(313);
    identifier();
    setState(315);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::LPAREN) {
      setState(314);
      formalParameterList();
    }
    setState(317);
    match(PascalParser::COLON);
    setState(318);
    typeIdentifier();
    setState(319);
    match(PascalParser::SEMICOLON);
    setState(320);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_Context ------------------------------------------------------------------

PascalParser::Type_Context::Type_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::SimpleTypeContext* PascalParser::Type_Context::simpleType() {
  return getRuleContext<PascalParser::SimpleTypeContext>(0);
}

PascalParser::StructuredTypeContext* PascalParser::Type_Context::structuredType() {
  return getRuleContext<PascalParser::StructuredTypeContext>(0);
}

PascalParser::PointerTypeContext* PascalParser::Type_Context::pointerType() {
  return getRuleContext<PascalParser::PointerTypeContext>(0);
}


size_t PascalParser::Type_Context::getRuleIndex() const {
  return PascalParser::RuleType_;
}


antlrcpp::Any PascalParser::Type_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitType_(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::Type_Context* PascalParser::type_() {
  Type_Context *_localctx = _tracker.createInstance<Type_Context>(_ctx, getState());
  enterRule(_localctx, 44, PascalParser::RuleType_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(325);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::BOOLEAN:
      case PascalParser::CHAR:
      case PascalParser::INTEGER:
      case PascalParser::REAL:
      case PascalParser::STRING:
      case PascalParser::IDENT:
      case PascalParser::LPAREN: {
        enterOuterAlt(_localctx, 1);
        setState(322);
        simpleType();
        break;
      }

      case PascalParser::ARRAY:
      case PascalParser::PACKED: {
        enterOuterAlt(_localctx, 2);
        setState(323);
        structuredType();
        break;
      }

      case PascalParser::CARAT: {
        enterOuterAlt(_localctx, 3);
        setState(324);
        pointerType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructuredTypeContext ------------------------------------------------------------------

PascalParser::StructuredTypeContext::StructuredTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::StructuredTypeContext::PACKED() {
  return getToken(PascalParser::PACKED, 0);
}

PascalParser::UnpackedStructuredTypeContext* PascalParser::StructuredTypeContext::unpackedStructuredType() {
  return getRuleContext<PascalParser::UnpackedStructuredTypeContext>(0);
}


size_t PascalParser::StructuredTypeContext::getRuleIndex() const {
  return PascalParser::RuleStructuredType;
}


antlrcpp::Any PascalParser::StructuredTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStructuredType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StructuredTypeContext* PascalParser::structuredType() {
  StructuredTypeContext *_localctx = _tracker.createInstance<StructuredTypeContext>(_ctx, getState());
  enterRule(_localctx, 46, PascalParser::RuleStructuredType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(330);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::PACKED: {
        enterOuterAlt(_localctx, 1);
        setState(327);
        match(PascalParser::PACKED);
        setState(328);
        unpackedStructuredType();
        break;
      }

      case PascalParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(329);
        unpackedStructuredType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnpackedStructuredTypeContext ------------------------------------------------------------------

PascalParser::UnpackedStructuredTypeContext::UnpackedStructuredTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ArrayTypeContext* PascalParser::UnpackedStructuredTypeContext::arrayType() {
  return getRuleContext<PascalParser::ArrayTypeContext>(0);
}


size_t PascalParser::UnpackedStructuredTypeContext::getRuleIndex() const {
  return PascalParser::RuleUnpackedStructuredType;
}


antlrcpp::Any PascalParser::UnpackedStructuredTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitUnpackedStructuredType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::UnpackedStructuredTypeContext* PascalParser::unpackedStructuredType() {
  UnpackedStructuredTypeContext *_localctx = _tracker.createInstance<UnpackedStructuredTypeContext>(_ctx, getState());
  enterRule(_localctx, 48, PascalParser::RuleUnpackedStructuredType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    arrayType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

PascalParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ArrayTypeContext::ARRAY() {
  return getToken(PascalParser::ARRAY, 0);
}

tree::TerminalNode* PascalParser::ArrayTypeContext::LBRACKET() {
  return getToken(PascalParser::LBRACKET, 0);
}

PascalParser::TypeListContext* PascalParser::ArrayTypeContext::typeList() {
  return getRuleContext<PascalParser::TypeListContext>(0);
}

tree::TerminalNode* PascalParser::ArrayTypeContext::RBRACKET() {
  return getToken(PascalParser::RBRACKET, 0);
}

tree::TerminalNode* PascalParser::ArrayTypeContext::OF() {
  return getToken(PascalParser::OF, 0);
}

PascalParser::Type_Context* PascalParser::ArrayTypeContext::type_() {
  return getRuleContext<PascalParser::Type_Context>(0);
}

tree::TerminalNode* PascalParser::ArrayTypeContext::LBRACKET2() {
  return getToken(PascalParser::LBRACKET2, 0);
}

tree::TerminalNode* PascalParser::ArrayTypeContext::RBRACKET2() {
  return getToken(PascalParser::RBRACKET2, 0);
}


size_t PascalParser::ArrayTypeContext::getRuleIndex() const {
  return PascalParser::RuleArrayType;
}


antlrcpp::Any PascalParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ArrayTypeContext* PascalParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 50, PascalParser::RuleArrayType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(348);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(334);
      match(PascalParser::ARRAY);
      setState(335);
      match(PascalParser::LBRACKET);
      setState(336);
      typeList();
      setState(337);
      match(PascalParser::RBRACKET);
      setState(338);
      match(PascalParser::OF);
      setState(339);
      type_();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(341);
      match(PascalParser::ARRAY);
      setState(342);
      match(PascalParser::LBRACKET2);
      setState(343);
      typeList();
      setState(344);
      match(PascalParser::RBRACKET2);
      setState(345);
      match(PascalParser::OF);
      setState(346);
      type_();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeListContext ------------------------------------------------------------------

PascalParser::TypeListContext::TypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::SimpleTypeContext *> PascalParser::TypeListContext::simpleType() {
  return getRuleContexts<PascalParser::SimpleTypeContext>();
}

PascalParser::SimpleTypeContext* PascalParser::TypeListContext::simpleType(size_t i) {
  return getRuleContext<PascalParser::SimpleTypeContext>(i);
}

std::vector<tree::TerminalNode *> PascalParser::TypeListContext::COMMA() {
  return getTokens(PascalParser::COMMA);
}

tree::TerminalNode* PascalParser::TypeListContext::COMMA(size_t i) {
  return getToken(PascalParser::COMMA, i);
}


size_t PascalParser::TypeListContext::getRuleIndex() const {
  return PascalParser::RuleTypeList;
}


antlrcpp::Any PascalParser::TypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypeList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TypeListContext* PascalParser::typeList() {
  TypeListContext *_localctx = _tracker.createInstance<TypeListContext>(_ctx, getState());
  enterRule(_localctx, 52, PascalParser::RuleTypeList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    simpleType();
    setState(355);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(351);
      match(PascalParser::COMMA);
      setState(352);
      simpleType();
      setState(357);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PointerTypeContext ------------------------------------------------------------------

PascalParser::PointerTypeContext::PointerTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::PointerTypeContext::CARAT() {
  return getToken(PascalParser::CARAT, 0);
}

PascalParser::TypeIdentifierContext* PascalParser::PointerTypeContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}


size_t PascalParser::PointerTypeContext::getRuleIndex() const {
  return PascalParser::RulePointerType;
}


antlrcpp::Any PascalParser::PointerTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitPointerType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::PointerTypeContext* PascalParser::pointerType() {
  PointerTypeContext *_localctx = _tracker.createInstance<PointerTypeContext>(_ctx, getState());
  enterRule(_localctx, 54, PascalParser::RulePointerType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(358);
    match(PascalParser::CARAT);
    setState(359);
    typeIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelContext ------------------------------------------------------------------

PascalParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::UnsignedIntegerContext* PascalParser::LabelContext::unsignedInteger() {
  return getRuleContext<PascalParser::UnsignedIntegerContext>(0);
}


size_t PascalParser::LabelContext::getRuleIndex() const {
  return PascalParser::RuleLabel;
}


antlrcpp::Any PascalParser::LabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitLabel(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::LabelContext* PascalParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 56, PascalParser::RuleLabel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    unsignedInteger();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantVarContext ------------------------------------------------------------------

PascalParser::ConstantVarContext::ConstantVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IdentifierContext* PascalParser::ConstantVarContext::identifier() {
  return getRuleContext<PascalParser::IdentifierContext>(0);
}

tree::TerminalNode* PascalParser::ConstantVarContext::EQUAL() {
  return getToken(PascalParser::EQUAL, 0);
}

PascalParser::ConstantContext* PascalParser::ConstantVarContext::constant() {
  return getRuleContext<PascalParser::ConstantContext>(0);
}


size_t PascalParser::ConstantVarContext::getRuleIndex() const {
  return PascalParser::RuleConstantVar;
}


antlrcpp::Any PascalParser::ConstantVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantVar(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantVarContext* PascalParser::constantVar() {
  ConstantVarContext *_localctx = _tracker.createInstance<ConstantVarContext>(_ctx, getState());
  enterRule(_localctx, 58, PascalParser::RuleConstantVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    identifier();
    setState(364);
    match(PascalParser::EQUAL);
    setState(365);
    constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantChrContext ------------------------------------------------------------------

PascalParser::ConstantChrContext::ConstantChrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ConstantChrContext::CHR() {
  return getToken(PascalParser::CHR, 0);
}

tree::TerminalNode* PascalParser::ConstantChrContext::LPAREN() {
  return getToken(PascalParser::LPAREN, 0);
}

PascalParser::UnsignedIntegerContext* PascalParser::ConstantChrContext::unsignedInteger() {
  return getRuleContext<PascalParser::UnsignedIntegerContext>(0);
}

tree::TerminalNode* PascalParser::ConstantChrContext::RPAREN() {
  return getToken(PascalParser::RPAREN, 0);
}


size_t PascalParser::ConstantChrContext::getRuleIndex() const {
  return PascalParser::RuleConstantChr;
}


antlrcpp::Any PascalParser::ConstantChrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstantChr(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantChrContext* PascalParser::constantChr() {
  ConstantChrContext *_localctx = _tracker.createInstance<ConstantChrContext>(_ctx, getState());
  enterRule(_localctx, 60, PascalParser::RuleConstantChr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    match(PascalParser::CHR);
    setState(368);
    match(PascalParser::LPAREN);
    setState(369);
    unsignedInteger();
    setState(370);
    match(PascalParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

PascalParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::UnsignedNumberContext* PascalParser::ConstantContext::unsignedNumber() {
  return getRuleContext<PascalParser::UnsignedNumberContext>(0);
}

PascalParser::SignContext* PascalParser::ConstantContext::sign() {
  return getRuleContext<PascalParser::SignContext>(0);
}

PascalParser::IdentifierContext* PascalParser::ConstantContext::identifier() {
  return getRuleContext<PascalParser::IdentifierContext>(0);
}

PascalParser::StringContext* PascalParser::ConstantContext::string() {
  return getRuleContext<PascalParser::StringContext>(0);
}

PascalParser::ConstantChrContext* PascalParser::ConstantContext::constantChr() {
  return getRuleContext<PascalParser::ConstantChrContext>(0);
}


size_t PascalParser::ConstantContext::getRuleIndex() const {
  return PascalParser::RuleConstant;
}


antlrcpp::Any PascalParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ConstantContext* PascalParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 62, PascalParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(382);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(372);
      unsignedNumber();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(373);
      sign();
      setState(374);
      unsignedNumber();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(376);
      identifier();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(377);
      sign();
      setState(378);
      identifier();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(380);
      string();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(381);
      constantChr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedNumberContext ------------------------------------------------------------------

PascalParser::UnsignedNumberContext::UnsignedNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::UnsignedIntegerContext* PascalParser::UnsignedNumberContext::unsignedInteger() {
  return getRuleContext<PascalParser::UnsignedIntegerContext>(0);
}

PascalParser::UnsignedRealContext* PascalParser::UnsignedNumberContext::unsignedReal() {
  return getRuleContext<PascalParser::UnsignedRealContext>(0);
}


size_t PascalParser::UnsignedNumberContext::getRuleIndex() const {
  return PascalParser::RuleUnsignedNumber;
}


antlrcpp::Any PascalParser::UnsignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitUnsignedNumber(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::UnsignedNumberContext* PascalParser::unsignedNumber() {
  UnsignedNumberContext *_localctx = _tracker.createInstance<UnsignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 64, PascalParser::RuleUnsignedNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(386);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::NUM_INT: {
        enterOuterAlt(_localctx, 1);
        setState(384);
        unsignedInteger();
        break;
      }

      case PascalParser::NUM_REAL: {
        enterOuterAlt(_localctx, 2);
        setState(385);
        unsignedReal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedIntegerContext ------------------------------------------------------------------

PascalParser::UnsignedIntegerContext::UnsignedIntegerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::UnsignedIntegerContext::NUM_INT() {
  return getToken(PascalParser::NUM_INT, 0);
}


size_t PascalParser::UnsignedIntegerContext::getRuleIndex() const {
  return PascalParser::RuleUnsignedInteger;
}


antlrcpp::Any PascalParser::UnsignedIntegerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitUnsignedInteger(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::UnsignedIntegerContext* PascalParser::unsignedInteger() {
  UnsignedIntegerContext *_localctx = _tracker.createInstance<UnsignedIntegerContext>(_ctx, getState());
  enterRule(_localctx, 66, PascalParser::RuleUnsignedInteger);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    match(PascalParser::NUM_INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedRealContext ------------------------------------------------------------------

PascalParser::UnsignedRealContext::UnsignedRealContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::UnsignedRealContext::NUM_REAL() {
  return getToken(PascalParser::NUM_REAL, 0);
}


size_t PascalParser::UnsignedRealContext::getRuleIndex() const {
  return PascalParser::RuleUnsignedReal;
}


antlrcpp::Any PascalParser::UnsignedRealContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitUnsignedReal(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::UnsignedRealContext* PascalParser::unsignedReal() {
  UnsignedRealContext *_localctx = _tracker.createInstance<UnsignedRealContext>(_ctx, getState());
  enterRule(_localctx, 68, PascalParser::RuleUnsignedReal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    match(PascalParser::NUM_REAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

PascalParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::SignContext::PLUSOP() {
  return getToken(PascalParser::PLUSOP, 0);
}

tree::TerminalNode* PascalParser::SignContext::MINUSOP() {
  return getToken(PascalParser::MINUSOP, 0);
}


size_t PascalParser::SignContext::getRuleIndex() const {
  return PascalParser::RuleSign;
}


antlrcpp::Any PascalParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::SignContext* PascalParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 70, PascalParser::RuleSign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(392);
    _la = _input->LA(1);
    if (!(_la == PascalParser::PLUSOP

    || _la == PascalParser::MINUSOP)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bool_Context ------------------------------------------------------------------

PascalParser::Bool_Context::Bool_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::Bool_Context::TRUE() {
  return getToken(PascalParser::TRUE, 0);
}

tree::TerminalNode* PascalParser::Bool_Context::FALSE() {
  return getToken(PascalParser::FALSE, 0);
}


size_t PascalParser::Bool_Context::getRuleIndex() const {
  return PascalParser::RuleBool_;
}


antlrcpp::Any PascalParser::Bool_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitBool_(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::Bool_Context* PascalParser::bool_() {
  Bool_Context *_localctx = _tracker.createInstance<Bool_Context>(_ctx, getState());
  enterRule(_localctx, 72, PascalParser::RuleBool_);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    _la = _input->LA(1);
    if (!(_la == PascalParser::TRUE

    || _la == PascalParser::FALSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeIdentifierContext ------------------------------------------------------------------

PascalParser::TypeIdentifierContext::TypeIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IdentifierContext* PascalParser::TypeIdentifierContext::identifier() {
  return getRuleContext<PascalParser::IdentifierContext>(0);
}

tree::TerminalNode* PascalParser::TypeIdentifierContext::CHAR() {
  return getToken(PascalParser::CHAR, 0);
}

tree::TerminalNode* PascalParser::TypeIdentifierContext::BOOLEAN() {
  return getToken(PascalParser::BOOLEAN, 0);
}

tree::TerminalNode* PascalParser::TypeIdentifierContext::INTEGER() {
  return getToken(PascalParser::INTEGER, 0);
}

tree::TerminalNode* PascalParser::TypeIdentifierContext::REAL() {
  return getToken(PascalParser::REAL, 0);
}

tree::TerminalNode* PascalParser::TypeIdentifierContext::STRING() {
  return getToken(PascalParser::STRING, 0);
}


size_t PascalParser::TypeIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleTypeIdentifier;
}


antlrcpp::Any PascalParser::TypeIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TypeIdentifierContext* PascalParser::typeIdentifier() {
  TypeIdentifierContext *_localctx = _tracker.createInstance<TypeIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 74, PascalParser::RuleTypeIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(398);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(396);
        identifier();
        break;
      }

      case PascalParser::BOOLEAN:
      case PascalParser::CHAR:
      case PascalParser::INTEGER:
      case PascalParser::REAL:
      case PascalParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(397);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PascalParser::BOOLEAN)
          | (1ULL << PascalParser::CHAR)
          | (1ULL << PascalParser::INTEGER)
          | (1ULL << PascalParser::REAL)
          | (1ULL << PascalParser::STRING))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

PascalParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::StringContext::STRING_LITERAL() {
  return getToken(PascalParser::STRING_LITERAL, 0);
}


size_t PascalParser::StringContext::getRuleIndex() const {
  return PascalParser::RuleString;
}


antlrcpp::Any PascalParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StringContext* PascalParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 76, PascalParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(400);
    match(PascalParser::STRING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleTypeContext ------------------------------------------------------------------

PascalParser::SimpleTypeContext::SimpleTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ScalarTypeContext* PascalParser::SimpleTypeContext::scalarType() {
  return getRuleContext<PascalParser::ScalarTypeContext>(0);
}

PascalParser::TypeIdentifierContext* PascalParser::SimpleTypeContext::typeIdentifier() {
  return getRuleContext<PascalParser::TypeIdentifierContext>(0);
}

PascalParser::StringtypeContext* PascalParser::SimpleTypeContext::stringtype() {
  return getRuleContext<PascalParser::StringtypeContext>(0);
}


size_t PascalParser::SimpleTypeContext::getRuleIndex() const {
  return PascalParser::RuleSimpleType;
}


antlrcpp::Any PascalParser::SimpleTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSimpleType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::SimpleTypeContext* PascalParser::simpleType() {
  SimpleTypeContext *_localctx = _tracker.createInstance<SimpleTypeContext>(_ctx, getState());
  enterRule(_localctx, 78, PascalParser::RuleSimpleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(405);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(402);
      scalarType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(403);
      typeIdentifier();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(404);
      stringtype();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarTypeContext ------------------------------------------------------------------

PascalParser::ScalarTypeContext::ScalarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ScalarTypeContext::LPAREN() {
  return getToken(PascalParser::LPAREN, 0);
}

PascalParser::IdentifierListContext* PascalParser::ScalarTypeContext::identifierList() {
  return getRuleContext<PascalParser::IdentifierListContext>(0);
}

tree::TerminalNode* PascalParser::ScalarTypeContext::RPAREN() {
  return getToken(PascalParser::RPAREN, 0);
}


size_t PascalParser::ScalarTypeContext::getRuleIndex() const {
  return PascalParser::RuleScalarType;
}


antlrcpp::Any PascalParser::ScalarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitScalarType(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ScalarTypeContext* PascalParser::scalarType() {
  ScalarTypeContext *_localctx = _tracker.createInstance<ScalarTypeContext>(_ctx, getState());
  enterRule(_localctx, 80, PascalParser::RuleScalarType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    match(PascalParser::LPAREN);
    setState(408);
    identifierList();
    setState(409);
    match(PascalParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringtypeContext ------------------------------------------------------------------

PascalParser::StringtypeContext::StringtypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::StringtypeContext::STRING() {
  return getToken(PascalParser::STRING, 0);
}

tree::TerminalNode* PascalParser::StringtypeContext::LBRACKET() {
  return getToken(PascalParser::LBRACKET, 0);
}

tree::TerminalNode* PascalParser::StringtypeContext::RBRACKET() {
  return getToken(PascalParser::RBRACKET, 0);
}

PascalParser::IdentifierContext* PascalParser::StringtypeContext::identifier() {
  return getRuleContext<PascalParser::IdentifierContext>(0);
}

PascalParser::UnsignedNumberContext* PascalParser::StringtypeContext::unsignedNumber() {
  return getRuleContext<PascalParser::UnsignedNumberContext>(0);
}


size_t PascalParser::StringtypeContext::getRuleIndex() const {
  return PascalParser::RuleStringtype;
}


antlrcpp::Any PascalParser::StringtypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStringtype(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StringtypeContext* PascalParser::stringtype() {
  StringtypeContext *_localctx = _tracker.createInstance<StringtypeContext>(_ctx, getState());
  enterRule(_localctx, 82, PascalParser::RuleStringtype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(411);
    match(PascalParser::STRING);
    setState(412);
    match(PascalParser::LBRACKET);
    setState(415);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::IDENT: {
        setState(413);
        identifier();
        break;
      }

      case PascalParser::NUM_INT:
      case PascalParser::NUM_REAL: {
        setState(414);
        unsignedNumber();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(417);
    match(PascalParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

PascalParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::IdentifierContext *> PascalParser::IdentifierListContext::identifier() {
  return getRuleContexts<PascalParser::IdentifierContext>();
}

PascalParser::IdentifierContext* PascalParser::IdentifierListContext::identifier(size_t i) {
  return getRuleContext<PascalParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> PascalParser::IdentifierListContext::COMMA() {
  return getTokens(PascalParser::COMMA);
}

tree::TerminalNode* PascalParser::IdentifierListContext::COMMA(size_t i) {
  return getToken(PascalParser::COMMA, i);
}


size_t PascalParser::IdentifierListContext::getRuleIndex() const {
  return PascalParser::RuleIdentifierList;
}


antlrcpp::Any PascalParser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::IdentifierListContext* PascalParser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 84, PascalParser::RuleIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(419);
    identifier();
    setState(424);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(420);
      match(PascalParser::COMMA);
      setState(421);
      identifier();
      setState(426);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

PascalParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::LabelContext* PascalParser::StatementContext::label() {
  return getRuleContext<PascalParser::LabelContext>(0);
}

tree::TerminalNode* PascalParser::StatementContext::COLON() {
  return getToken(PascalParser::COLON, 0);
}

PascalParser::UnlabelledStatementContext* PascalParser::StatementContext::unlabelledStatement() {
  return getRuleContext<PascalParser::UnlabelledStatementContext>(0);
}

PascalParser::ProcedureAndFunctionDeclarationPartContext* PascalParser::StatementContext::procedureAndFunctionDeclarationPart() {
  return getRuleContext<PascalParser::ProcedureAndFunctionDeclarationPartContext>(0);
}


size_t PascalParser::StatementContext::getRuleIndex() const {
  return PascalParser::RuleStatement;
}


antlrcpp::Any PascalParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StatementContext* PascalParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 86, PascalParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(433);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::NUM_INT: {
        enterOuterAlt(_localctx, 1);
        setState(427);
        label();
        setState(428);
        match(PascalParser::COLON);
        setState(429);
        unlabelledStatement();
        break;
      }

      case PascalParser::BEGIN:
      case PascalParser::CASE:
      case PascalParser::ELSE:
      case PascalParser::END:
      case PascalParser::FOR:
      case PascalParser::GOTO:
      case PascalParser::IF:
      case PascalParser::WRITE:
      case PascalParser::WRITELN:
      case PascalParser::REPEAT:
      case PascalParser::UNTIL:
      case PascalParser::WHILE:
      case PascalParser::WITH:
      case PascalParser::AT:
      case PascalParser::IDENT:
      case PascalParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);
        setState(431);
        unlabelledStatement();
        break;
      }

      case PascalParser::FUNCTION:
      case PascalParser::PROCEDURE: {
        enterOuterAlt(_localctx, 3);
        setState(432);
        procedureAndFunctionDeclarationPart();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnlabelledStatementContext ------------------------------------------------------------------

PascalParser::UnlabelledStatementContext::UnlabelledStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::SimpleStatementContext* PascalParser::UnlabelledStatementContext::simpleStatement() {
  return getRuleContext<PascalParser::SimpleStatementContext>(0);
}

PascalParser::StructuredStatementContext* PascalParser::UnlabelledStatementContext::structuredStatement() {
  return getRuleContext<PascalParser::StructuredStatementContext>(0);
}


size_t PascalParser::UnlabelledStatementContext::getRuleIndex() const {
  return PascalParser::RuleUnlabelledStatement;
}


antlrcpp::Any PascalParser::UnlabelledStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitUnlabelledStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::UnlabelledStatementContext* PascalParser::unlabelledStatement() {
  UnlabelledStatementContext *_localctx = _tracker.createInstance<UnlabelledStatementContext>(_ctx, getState());
  enterRule(_localctx, 88, PascalParser::RuleUnlabelledStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(437);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::ELSE:
      case PascalParser::END:
      case PascalParser::GOTO:
      case PascalParser::UNTIL:
      case PascalParser::AT:
      case PascalParser::IDENT:
      case PascalParser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(435);
        simpleStatement();
        break;
      }

      case PascalParser::BEGIN:
      case PascalParser::CASE:
      case PascalParser::FOR:
      case PascalParser::IF:
      case PascalParser::WRITE:
      case PascalParser::WRITELN:
      case PascalParser::REPEAT:
      case PascalParser::WHILE:
      case PascalParser::WITH: {
        enterOuterAlt(_localctx, 2);
        setState(436);
        structuredStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleStatementContext ------------------------------------------------------------------

PascalParser::SimpleStatementContext::SimpleStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::AssignmentStatementContext* PascalParser::SimpleStatementContext::assignmentStatement() {
  return getRuleContext<PascalParser::AssignmentStatementContext>(0);
}

PascalParser::ProcedureStatementContext* PascalParser::SimpleStatementContext::procedureStatement() {
  return getRuleContext<PascalParser::ProcedureStatementContext>(0);
}

PascalParser::GotoStatementContext* PascalParser::SimpleStatementContext::gotoStatement() {
  return getRuleContext<PascalParser::GotoStatementContext>(0);
}

PascalParser::EmptyStatement_Context* PascalParser::SimpleStatementContext::emptyStatement_() {
  return getRuleContext<PascalParser::EmptyStatement_Context>(0);
}


size_t PascalParser::SimpleStatementContext::getRuleIndex() const {
  return PascalParser::RuleSimpleStatement;
}


antlrcpp::Any PascalParser::SimpleStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSimpleStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::SimpleStatementContext* PascalParser::simpleStatement() {
  SimpleStatementContext *_localctx = _tracker.createInstance<SimpleStatementContext>(_ctx, getState());
  enterRule(_localctx, 90, PascalParser::RuleSimpleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(443);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(439);
      assignmentStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(440);
      procedureStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(441);
      gotoStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(442);
      emptyStatement_();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureStatementContext ------------------------------------------------------------------

PascalParser::ProcedureStatementContext::ProcedureStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IdentifierContext* PascalParser::ProcedureStatementContext::identifier() {
  return getRuleContext<PascalParser::IdentifierContext>(0);
}

tree::TerminalNode* PascalParser::ProcedureStatementContext::LPAREN() {
  return getToken(PascalParser::LPAREN, 0);
}

PascalParser::ParameterListContext* PascalParser::ProcedureStatementContext::parameterList() {
  return getRuleContext<PascalParser::ParameterListContext>(0);
}

tree::TerminalNode* PascalParser::ProcedureStatementContext::RPAREN() {
  return getToken(PascalParser::RPAREN, 0);
}


size_t PascalParser::ProcedureStatementContext::getRuleIndex() const {
  return PascalParser::RuleProcedureStatement;
}


antlrcpp::Any PascalParser::ProcedureStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitProcedureStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ProcedureStatementContext* PascalParser::procedureStatement() {
  ProcedureStatementContext *_localctx = _tracker.createInstance<ProcedureStatementContext>(_ctx, getState());
  enterRule(_localctx, 92, PascalParser::RuleProcedureStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(445);
    identifier();
    setState(450);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::LPAREN) {
      setState(446);
      match(PascalParser::LPAREN);
      setState(447);
      parameterList();
      setState(448);
      match(PascalParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatement_Context ------------------------------------------------------------------

PascalParser::EmptyStatement_Context::EmptyStatement_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PascalParser::EmptyStatement_Context::getRuleIndex() const {
  return PascalParser::RuleEmptyStatement_;
}


antlrcpp::Any PascalParser::EmptyStatement_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement_(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::EmptyStatement_Context* PascalParser::emptyStatement_() {
  EmptyStatement_Context *_localctx = _tracker.createInstance<EmptyStatement_Context>(_ctx, getState());
  enterRule(_localctx, 94, PascalParser::RuleEmptyStatement_);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

PascalParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::VariableContext* PascalParser::AssignmentStatementContext::variable() {
  return getRuleContext<PascalParser::VariableContext>(0);
}

tree::TerminalNode* PascalParser::AssignmentStatementContext::ASSIGN() {
  return getToken(PascalParser::ASSIGN, 0);
}

PascalParser::ExpressionContext* PascalParser::AssignmentStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::AssignmentStatementContext::getRuleIndex() const {
  return PascalParser::RuleAssignmentStatement;
}


antlrcpp::Any PascalParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::AssignmentStatementContext* PascalParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 96, PascalParser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
    variable();
    setState(455);
    match(PascalParser::ASSIGN);
    setState(456);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

PascalParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::VariableContext::AT() {
  return getToken(PascalParser::AT, 0);
}

PascalParser::VariableIdentifierContext* PascalParser::VariableContext::variableIdentifier() {
  return getRuleContext<PascalParser::VariableIdentifierContext>(0);
}

std::vector<PascalParser::ModifierContext *> PascalParser::VariableContext::modifier() {
  return getRuleContexts<PascalParser::ModifierContext>();
}

PascalParser::ModifierContext* PascalParser::VariableContext::modifier(size_t i) {
  return getRuleContext<PascalParser::ModifierContext>(i);
}


size_t PascalParser::VariableContext::getRuleIndex() const {
  return PascalParser::RuleVariable;
}


antlrcpp::Any PascalParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableContext* PascalParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 98, PascalParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(461);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::AT: {
        setState(458);
        match(PascalParser::AT);
        setState(459);
        variableIdentifier();
        break;
      }

      case PascalParser::IDENT: {
        setState(460);
        variableIdentifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(466);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 55) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 55)) & ((1ULL << (PascalParser::LBRACKET2 - 55))
      | (1ULL << (PascalParser::DOT - 55))
      | (1ULL << (PascalParser::CARAT - 55))
      | (1ULL << (PascalParser::LBRACKET - 55)))) != 0)) {
      setState(463);
      modifier();
      setState(468);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableIdentifierContext ------------------------------------------------------------------

PascalParser::VariableIdentifierContext::VariableIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::VariableIdentifierContext::IDENT() {
  return getToken(PascalParser::IDENT, 0);
}


size_t PascalParser::VariableIdentifierContext::getRuleIndex() const {
  return PascalParser::RuleVariableIdentifier;
}


antlrcpp::Any PascalParser::VariableIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::VariableIdentifierContext* PascalParser::variableIdentifier() {
  VariableIdentifierContext *_localctx = _tracker.createInstance<VariableIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 100, PascalParser::RuleVariableIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(469);
    match(PascalParser::IDENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModifierContext ------------------------------------------------------------------

PascalParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ModifierContext::LBRACKET() {
  return getToken(PascalParser::LBRACKET, 0);
}

std::vector<PascalParser::ExpressionContext *> PascalParser::ModifierContext::expression() {
  return getRuleContexts<PascalParser::ExpressionContext>();
}

PascalParser::ExpressionContext* PascalParser::ModifierContext::expression(size_t i) {
  return getRuleContext<PascalParser::ExpressionContext>(i);
}

tree::TerminalNode* PascalParser::ModifierContext::RBRACKET() {
  return getToken(PascalParser::RBRACKET, 0);
}

std::vector<tree::TerminalNode *> PascalParser::ModifierContext::COMMA() {
  return getTokens(PascalParser::COMMA);
}

tree::TerminalNode* PascalParser::ModifierContext::COMMA(size_t i) {
  return getToken(PascalParser::COMMA, i);
}

tree::TerminalNode* PascalParser::ModifierContext::LBRACKET2() {
  return getToken(PascalParser::LBRACKET2, 0);
}

tree::TerminalNode* PascalParser::ModifierContext::RBRACKET2() {
  return getToken(PascalParser::RBRACKET2, 0);
}

tree::TerminalNode* PascalParser::ModifierContext::DOT() {
  return getToken(PascalParser::DOT, 0);
}

PascalParser::IdentifierContext* PascalParser::ModifierContext::identifier() {
  return getRuleContext<PascalParser::IdentifierContext>(0);
}

tree::TerminalNode* PascalParser::ModifierContext::CARAT() {
  return getToken(PascalParser::CARAT, 0);
}


size_t PascalParser::ModifierContext::getRuleIndex() const {
  return PascalParser::RuleModifier;
}


antlrcpp::Any PascalParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ModifierContext* PascalParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 102, PascalParser::RuleModifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(496);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::LBRACKET: {
        enterOuterAlt(_localctx, 1);
        setState(471);
        match(PascalParser::LBRACKET);
        setState(472);
        expression();
        setState(477);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PascalParser::COMMA) {
          setState(473);
          match(PascalParser::COMMA);
          setState(474);
          expression();
          setState(479);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(480);
        match(PascalParser::RBRACKET);
        break;
      }

      case PascalParser::LBRACKET2: {
        enterOuterAlt(_localctx, 2);
        setState(482);
        match(PascalParser::LBRACKET2);
        setState(483);
        expression();
        setState(488);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PascalParser::COMMA) {
          setState(484);
          match(PascalParser::COMMA);
          setState(485);
          expression();
          setState(490);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(491);
        match(PascalParser::RBRACKET2);
        break;
      }

      case PascalParser::DOT: {
        enterOuterAlt(_localctx, 3);
        setState(493);
        match(PascalParser::DOT);
        setState(494);
        identifier();
        break;
      }

      case PascalParser::CARAT: {
        enterOuterAlt(_localctx, 4);
        setState(495);
        match(PascalParser::CARAT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

PascalParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::SimpleExpressionContext* PascalParser::ExpressionContext::simpleExpression() {
  return getRuleContext<PascalParser::SimpleExpressionContext>(0);
}

std::vector<PascalParser::RelationaloperatorContext *> PascalParser::ExpressionContext::relationaloperator() {
  return getRuleContexts<PascalParser::RelationaloperatorContext>();
}

PascalParser::RelationaloperatorContext* PascalParser::ExpressionContext::relationaloperator(size_t i) {
  return getRuleContext<PascalParser::RelationaloperatorContext>(i);
}

std::vector<PascalParser::ExpressionContext *> PascalParser::ExpressionContext::expression() {
  return getRuleContexts<PascalParser::ExpressionContext>();
}

PascalParser::ExpressionContext* PascalParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<PascalParser::ExpressionContext>(i);
}


size_t PascalParser::ExpressionContext::getRuleIndex() const {
  return PascalParser::RuleExpression;
}


antlrcpp::Any PascalParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ExpressionContext* PascalParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 104, PascalParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(498);
    simpleExpression();
    setState(504);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(499);
        relationaloperator();
        setState(500);
        expression(); 
      }
      setState(506);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationaloperatorContext ------------------------------------------------------------------

PascalParser::RelationaloperatorContext::RelationaloperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::RelationaloperatorContext::EQUAL() {
  return getToken(PascalParser::EQUAL, 0);
}

tree::TerminalNode* PascalParser::RelationaloperatorContext::NE() {
  return getToken(PascalParser::NE, 0);
}

tree::TerminalNode* PascalParser::RelationaloperatorContext::LT() {
  return getToken(PascalParser::LT, 0);
}

tree::TerminalNode* PascalParser::RelationaloperatorContext::LTEQ() {
  return getToken(PascalParser::LTEQ, 0);
}

tree::TerminalNode* PascalParser::RelationaloperatorContext::GTEQ() {
  return getToken(PascalParser::GTEQ, 0);
}

tree::TerminalNode* PascalParser::RelationaloperatorContext::GT() {
  return getToken(PascalParser::GT, 0);
}

tree::TerminalNode* PascalParser::RelationaloperatorContext::IN() {
  return getToken(PascalParser::IN, 0);
}


size_t PascalParser::RelationaloperatorContext::getRuleIndex() const {
  return PascalParser::RuleRelationaloperator;
}


antlrcpp::Any PascalParser::RelationaloperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRelationaloperator(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RelationaloperatorContext* PascalParser::relationaloperator() {
  RelationaloperatorContext *_localctx = _tracker.createInstance<RelationaloperatorContext>(_ctx, getState());
  enterRule(_localctx, 106, PascalParser::RuleRelationaloperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(507);
    _la = _input->LA(1);
    if (!(((((_la - 24) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 24)) & ((1ULL << (PascalParser::IN - 24))
      | (1ULL << (PascalParser::EQUAL - 24))
      | (1ULL << (PascalParser::NE - 24))
      | (1ULL << (PascalParser::LTEQ - 24))
      | (1ULL << (PascalParser::GTEQ - 24))
      | (1ULL << (PascalParser::LT - 24))
      | (1ULL << (PascalParser::GT - 24)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleExpressionContext ------------------------------------------------------------------

PascalParser::SimpleExpressionContext::SimpleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::TermContext* PascalParser::SimpleExpressionContext::term() {
  return getRuleContext<PascalParser::TermContext>(0);
}

std::vector<PascalParser::AdditiveoperatorContext *> PascalParser::SimpleExpressionContext::additiveoperator() {
  return getRuleContexts<PascalParser::AdditiveoperatorContext>();
}

PascalParser::AdditiveoperatorContext* PascalParser::SimpleExpressionContext::additiveoperator(size_t i) {
  return getRuleContext<PascalParser::AdditiveoperatorContext>(i);
}

std::vector<PascalParser::SimpleExpressionContext *> PascalParser::SimpleExpressionContext::simpleExpression() {
  return getRuleContexts<PascalParser::SimpleExpressionContext>();
}

PascalParser::SimpleExpressionContext* PascalParser::SimpleExpressionContext::simpleExpression(size_t i) {
  return getRuleContext<PascalParser::SimpleExpressionContext>(i);
}


size_t PascalParser::SimpleExpressionContext::getRuleIndex() const {
  return PascalParser::RuleSimpleExpression;
}


antlrcpp::Any PascalParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::SimpleExpressionContext* PascalParser::simpleExpression() {
  SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, getState());
  enterRule(_localctx, 108, PascalParser::RuleSimpleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(509);
    term();
    setState(515);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(510);
        additiveoperator();
        setState(511);
        simpleExpression(); 
      }
      setState(517);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AdditiveoperatorContext ------------------------------------------------------------------

PascalParser::AdditiveoperatorContext::AdditiveoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::AdditiveoperatorContext::PLUSOP() {
  return getToken(PascalParser::PLUSOP, 0);
}

tree::TerminalNode* PascalParser::AdditiveoperatorContext::MINUSOP() {
  return getToken(PascalParser::MINUSOP, 0);
}

tree::TerminalNode* PascalParser::AdditiveoperatorContext::OR() {
  return getToken(PascalParser::OR, 0);
}


size_t PascalParser::AdditiveoperatorContext::getRuleIndex() const {
  return PascalParser::RuleAdditiveoperator;
}


antlrcpp::Any PascalParser::AdditiveoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitAdditiveoperator(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::AdditiveoperatorContext* PascalParser::additiveoperator() {
  AdditiveoperatorContext *_localctx = _tracker.createInstance<AdditiveoperatorContext>(_ctx, getState());
  enterRule(_localctx, 110, PascalParser::RuleAdditiveoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(518);
    _la = _input->LA(1);
    if (!(((((_la - 37) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 37)) & ((1ULL << (PascalParser::OR - 37))
      | (1ULL << (PascalParser::PLUSOP - 37))
      | (1ULL << (PascalParser::MINUSOP - 37)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

PascalParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::SignedFactorContext* PascalParser::TermContext::signedFactor() {
  return getRuleContext<PascalParser::SignedFactorContext>(0);
}

std::vector<PascalParser::MultiplicativeoperatorContext *> PascalParser::TermContext::multiplicativeoperator() {
  return getRuleContexts<PascalParser::MultiplicativeoperatorContext>();
}

PascalParser::MultiplicativeoperatorContext* PascalParser::TermContext::multiplicativeoperator(size_t i) {
  return getRuleContext<PascalParser::MultiplicativeoperatorContext>(i);
}

std::vector<PascalParser::TermContext *> PascalParser::TermContext::term() {
  return getRuleContexts<PascalParser::TermContext>();
}

PascalParser::TermContext* PascalParser::TermContext::term(size_t i) {
  return getRuleContext<PascalParser::TermContext>(i);
}


size_t PascalParser::TermContext::getRuleIndex() const {
  return PascalParser::RuleTerm;
}


antlrcpp::Any PascalParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::TermContext* PascalParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 112, PascalParser::RuleTerm);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(520);
    signedFactor();
    setState(526);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(521);
        multiplicativeoperator();
        setState(522);
        term(); 
      }
      setState(528);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeoperatorContext ------------------------------------------------------------------

PascalParser::MultiplicativeoperatorContext::MultiplicativeoperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::MultiplicativeoperatorContext::MULTOP() {
  return getToken(PascalParser::MULTOP, 0);
}

tree::TerminalNode* PascalParser::MultiplicativeoperatorContext::DIVOP() {
  return getToken(PascalParser::DIVOP, 0);
}

tree::TerminalNode* PascalParser::MultiplicativeoperatorContext::DIV() {
  return getToken(PascalParser::DIV, 0);
}

tree::TerminalNode* PascalParser::MultiplicativeoperatorContext::MOD() {
  return getToken(PascalParser::MOD, 0);
}

tree::TerminalNode* PascalParser::MultiplicativeoperatorContext::AND() {
  return getToken(PascalParser::AND, 0);
}


size_t PascalParser::MultiplicativeoperatorContext::getRuleIndex() const {
  return PascalParser::RuleMultiplicativeoperator;
}


antlrcpp::Any PascalParser::MultiplicativeoperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeoperator(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::MultiplicativeoperatorContext* PascalParser::multiplicativeoperator() {
  MultiplicativeoperatorContext *_localctx = _tracker.createInstance<MultiplicativeoperatorContext>(_ctx, getState());
  enterRule(_localctx, 114, PascalParser::RuleMultiplicativeoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(529);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::AND)
      | (1ULL << PascalParser::DIV)
      | (1ULL << PascalParser::MOD))) != 0) || _la == PascalParser::MULTOP

    || _la == PascalParser::DIVOP)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignedFactorContext ------------------------------------------------------------------

PascalParser::SignedFactorContext::SignedFactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::FactorContext* PascalParser::SignedFactorContext::factor() {
  return getRuleContext<PascalParser::FactorContext>(0);
}

tree::TerminalNode* PascalParser::SignedFactorContext::PLUSOP() {
  return getToken(PascalParser::PLUSOP, 0);
}

tree::TerminalNode* PascalParser::SignedFactorContext::MINUSOP() {
  return getToken(PascalParser::MINUSOP, 0);
}


size_t PascalParser::SignedFactorContext::getRuleIndex() const {
  return PascalParser::RuleSignedFactor;
}


antlrcpp::Any PascalParser::SignedFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSignedFactor(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::SignedFactorContext* PascalParser::signedFactor() {
  SignedFactorContext *_localctx = _tracker.createInstance<SignedFactorContext>(_ctx, getState());
  enterRule(_localctx, 116, PascalParser::RuleSignedFactor);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(532);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::PLUSOP

    || _la == PascalParser::MINUSOP) {
      setState(531);
      _la = _input->LA(1);
      if (!(_la == PascalParser::PLUSOP

      || _la == PascalParser::MINUSOP)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(534);
    factor();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

PascalParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::VariableContext* PascalParser::FactorContext::variable() {
  return getRuleContext<PascalParser::VariableContext>(0);
}

tree::TerminalNode* PascalParser::FactorContext::LPAREN() {
  return getToken(PascalParser::LPAREN, 0);
}

PascalParser::ExpressionContext* PascalParser::FactorContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalParser::FactorContext::RPAREN() {
  return getToken(PascalParser::RPAREN, 0);
}

PascalParser::FunctionDesignatorContext* PascalParser::FactorContext::functionDesignator() {
  return getRuleContext<PascalParser::FunctionDesignatorContext>(0);
}

PascalParser::UnsignedConstantContext* PascalParser::FactorContext::unsignedConstant() {
  return getRuleContext<PascalParser::UnsignedConstantContext>(0);
}

PascalParser::Set_Context* PascalParser::FactorContext::set_() {
  return getRuleContext<PascalParser::Set_Context>(0);
}

tree::TerminalNode* PascalParser::FactorContext::NOT() {
  return getToken(PascalParser::NOT, 0);
}

PascalParser::FactorContext* PascalParser::FactorContext::factor() {
  return getRuleContext<PascalParser::FactorContext>(0);
}

PascalParser::Bool_Context* PascalParser::FactorContext::bool_() {
  return getRuleContext<PascalParser::Bool_Context>(0);
}


size_t PascalParser::FactorContext::getRuleIndex() const {
  return PascalParser::RuleFactor;
}


antlrcpp::Any PascalParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FactorContext* PascalParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 118, PascalParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(547);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(536);
      variable();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(537);
      match(PascalParser::LPAREN);
      setState(538);
      expression();
      setState(539);
      match(PascalParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(541);
      functionDesignator();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(542);
      unsignedConstant();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(543);
      set_();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(544);
      match(PascalParser::NOT);
      setState(545);
      factor();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(546);
      bool_();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedConstantContext ------------------------------------------------------------------

PascalParser::UnsignedConstantContext::UnsignedConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::UnsignedNumberContext* PascalParser::UnsignedConstantContext::unsignedNumber() {
  return getRuleContext<PascalParser::UnsignedNumberContext>(0);
}

PascalParser::ConstantChrContext* PascalParser::UnsignedConstantContext::constantChr() {
  return getRuleContext<PascalParser::ConstantChrContext>(0);
}

PascalParser::StringContext* PascalParser::UnsignedConstantContext::string() {
  return getRuleContext<PascalParser::StringContext>(0);
}

tree::TerminalNode* PascalParser::UnsignedConstantContext::NIL() {
  return getToken(PascalParser::NIL, 0);
}


size_t PascalParser::UnsignedConstantContext::getRuleIndex() const {
  return PascalParser::RuleUnsignedConstant;
}


antlrcpp::Any PascalParser::UnsignedConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitUnsignedConstant(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::UnsignedConstantContext* PascalParser::unsignedConstant() {
  UnsignedConstantContext *_localctx = _tracker.createInstance<UnsignedConstantContext>(_ctx, getState());
  enterRule(_localctx, 120, PascalParser::RuleUnsignedConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(553);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::NUM_INT:
      case PascalParser::NUM_REAL: {
        enterOuterAlt(_localctx, 1);
        setState(549);
        unsignedNumber();
        break;
      }

      case PascalParser::CHR: {
        enterOuterAlt(_localctx, 2);
        setState(550);
        constantChr();
        break;
      }

      case PascalParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(551);
        string();
        break;
      }

      case PascalParser::NIL: {
        enterOuterAlt(_localctx, 4);
        setState(552);
        match(PascalParser::NIL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDesignatorContext ------------------------------------------------------------------

PascalParser::FunctionDesignatorContext::FunctionDesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IdentifierContext* PascalParser::FunctionDesignatorContext::identifier() {
  return getRuleContext<PascalParser::IdentifierContext>(0);
}

tree::TerminalNode* PascalParser::FunctionDesignatorContext::LPAREN() {
  return getToken(PascalParser::LPAREN, 0);
}

PascalParser::ParameterListContext* PascalParser::FunctionDesignatorContext::parameterList() {
  return getRuleContext<PascalParser::ParameterListContext>(0);
}

tree::TerminalNode* PascalParser::FunctionDesignatorContext::RPAREN() {
  return getToken(PascalParser::RPAREN, 0);
}


size_t PascalParser::FunctionDesignatorContext::getRuleIndex() const {
  return PascalParser::RuleFunctionDesignator;
}


antlrcpp::Any PascalParser::FunctionDesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitFunctionDesignator(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::FunctionDesignatorContext* PascalParser::functionDesignator() {
  FunctionDesignatorContext *_localctx = _tracker.createInstance<FunctionDesignatorContext>(_ctx, getState());
  enterRule(_localctx, 122, PascalParser::RuleFunctionDesignator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(555);
    identifier();
    setState(556);
    match(PascalParser::LPAREN);
    setState(557);
    parameterList();
    setState(558);
    match(PascalParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

PascalParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ActualParameterContext *> PascalParser::ParameterListContext::actualParameter() {
  return getRuleContexts<PascalParser::ActualParameterContext>();
}

PascalParser::ActualParameterContext* PascalParser::ParameterListContext::actualParameter(size_t i) {
  return getRuleContext<PascalParser::ActualParameterContext>(i);
}

std::vector<tree::TerminalNode *> PascalParser::ParameterListContext::COMMA() {
  return getTokens(PascalParser::COMMA);
}

tree::TerminalNode* PascalParser::ParameterListContext::COMMA(size_t i) {
  return getToken(PascalParser::COMMA, i);
}


size_t PascalParser::ParameterListContext::getRuleIndex() const {
  return PascalParser::RuleParameterList;
}


antlrcpp::Any PascalParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParameterListContext* PascalParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 124, PascalParser::RuleParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(560);
    actualParameter();
    setState(565);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(561);
      match(PascalParser::COMMA);
      setState(562);
      actualParameter();
      setState(567);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActualParameterContext ------------------------------------------------------------------

PascalParser::ActualParameterContext::ActualParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ExpressionContext* PascalParser::ActualParameterContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

std::vector<PascalParser::ParameterwidthContext *> PascalParser::ActualParameterContext::parameterwidth() {
  return getRuleContexts<PascalParser::ParameterwidthContext>();
}

PascalParser::ParameterwidthContext* PascalParser::ActualParameterContext::parameterwidth(size_t i) {
  return getRuleContext<PascalParser::ParameterwidthContext>(i);
}


size_t PascalParser::ActualParameterContext::getRuleIndex() const {
  return PascalParser::RuleActualParameter;
}


antlrcpp::Any PascalParser::ActualParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitActualParameter(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ActualParameterContext* PascalParser::actualParameter() {
  ActualParameterContext *_localctx = _tracker.createInstance<ActualParameterContext>(_ctx, getState());
  enterRule(_localctx, 126, PascalParser::RuleActualParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(568);
    expression();
    setState(572);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COLON) {
      setState(569);
      parameterwidth();
      setState(574);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterwidthContext ------------------------------------------------------------------

PascalParser::ParameterwidthContext::ParameterwidthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ParameterwidthContext::COLON() {
  return getToken(PascalParser::COLON, 0);
}

PascalParser::ExpressionContext* PascalParser::ParameterwidthContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::ParameterwidthContext::getRuleIndex() const {
  return PascalParser::RuleParameterwidth;
}


antlrcpp::Any PascalParser::ParameterwidthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitParameterwidth(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ParameterwidthContext* PascalParser::parameterwidth() {
  ParameterwidthContext *_localctx = _tracker.createInstance<ParameterwidthContext>(_ctx, getState());
  enterRule(_localctx, 128, PascalParser::RuleParameterwidth);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(575);
    match(PascalParser::COLON);
    setState(576);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_Context ------------------------------------------------------------------

PascalParser::Set_Context::Set_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::Set_Context::LBRACKET() {
  return getToken(PascalParser::LBRACKET, 0);
}

std::vector<PascalParser::ElementContext *> PascalParser::Set_Context::element() {
  return getRuleContexts<PascalParser::ElementContext>();
}

PascalParser::ElementContext* PascalParser::Set_Context::element(size_t i) {
  return getRuleContext<PascalParser::ElementContext>(i);
}

tree::TerminalNode* PascalParser::Set_Context::RBRACKET() {
  return getToken(PascalParser::RBRACKET, 0);
}

std::vector<tree::TerminalNode *> PascalParser::Set_Context::COMMA() {
  return getTokens(PascalParser::COMMA);
}

tree::TerminalNode* PascalParser::Set_Context::COMMA(size_t i) {
  return getToken(PascalParser::COMMA, i);
}

tree::TerminalNode* PascalParser::Set_Context::LBRACKET2() {
  return getToken(PascalParser::LBRACKET2, 0);
}

tree::TerminalNode* PascalParser::Set_Context::RBRACKET2() {
  return getToken(PascalParser::RBRACKET2, 0);
}


size_t PascalParser::Set_Context::getRuleIndex() const {
  return PascalParser::RuleSet_;
}


antlrcpp::Any PascalParser::Set_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitSet_(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::Set_Context* PascalParser::set_() {
  Set_Context *_localctx = _tracker.createInstance<Set_Context>(_ctx, getState());
  enterRule(_localctx, 130, PascalParser::RuleSet_);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(600);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::LBRACKET: {
        enterOuterAlt(_localctx, 1);
        setState(578);
        match(PascalParser::LBRACKET);
        setState(579);
        element();
        setState(584);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PascalParser::COMMA) {
          setState(580);
          match(PascalParser::COMMA);
          setState(581);
          element();
          setState(586);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(587);
        match(PascalParser::RBRACKET);
        break;
      }

      case PascalParser::LBRACKET2: {
        enterOuterAlt(_localctx, 2);
        setState(589);
        match(PascalParser::LBRACKET2);
        setState(590);
        element();
        setState(595);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PascalParser::COMMA) {
          setState(591);
          match(PascalParser::COMMA);
          setState(592);
          element();
          setState(597);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(598);
        match(PascalParser::RBRACKET2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementContext ------------------------------------------------------------------

PascalParser::ElementContext::ElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ExpressionContext *> PascalParser::ElementContext::expression() {
  return getRuleContexts<PascalParser::ExpressionContext>();
}

PascalParser::ExpressionContext* PascalParser::ElementContext::expression(size_t i) {
  return getRuleContext<PascalParser::ExpressionContext>(i);
}

tree::TerminalNode* PascalParser::ElementContext::DOTDOT() {
  return getToken(PascalParser::DOTDOT, 0);
}


size_t PascalParser::ElementContext::getRuleIndex() const {
  return PascalParser::RuleElement;
}


antlrcpp::Any PascalParser::ElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitElement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ElementContext* PascalParser::element() {
  ElementContext *_localctx = _tracker.createInstance<ElementContext>(_ctx, getState());
  enterRule(_localctx, 132, PascalParser::RuleElement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(602);
    expression();
    setState(605);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::DOTDOT) {
      setState(603);
      match(PascalParser::DOTDOT);
      setState(604);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GotoStatementContext ------------------------------------------------------------------

PascalParser::GotoStatementContext::GotoStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::GotoStatementContext::GOTO() {
  return getToken(PascalParser::GOTO, 0);
}

PascalParser::LabelContext* PascalParser::GotoStatementContext::label() {
  return getRuleContext<PascalParser::LabelContext>(0);
}


size_t PascalParser::GotoStatementContext::getRuleIndex() const {
  return PascalParser::RuleGotoStatement;
}


antlrcpp::Any PascalParser::GotoStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitGotoStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::GotoStatementContext* PascalParser::gotoStatement() {
  GotoStatementContext *_localctx = _tracker.createInstance<GotoStatementContext>(_ctx, getState());
  enterRule(_localctx, 134, PascalParser::RuleGotoStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    match(PascalParser::GOTO);
    setState(608);
    label();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructuredStatementContext ------------------------------------------------------------------

PascalParser::StructuredStatementContext::StructuredStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::CompoundStatementContext* PascalParser::StructuredStatementContext::compoundStatement() {
  return getRuleContext<PascalParser::CompoundStatementContext>(0);
}

PascalParser::ReptitiveStatementContext* PascalParser::StructuredStatementContext::reptitiveStatement() {
  return getRuleContext<PascalParser::ReptitiveStatementContext>(0);
}

PascalParser::IfStatementContext* PascalParser::StructuredStatementContext::ifStatement() {
  return getRuleContext<PascalParser::IfStatementContext>(0);
}

PascalParser::CaseStatementContext* PascalParser::StructuredStatementContext::caseStatement() {
  return getRuleContext<PascalParser::CaseStatementContext>(0);
}

PascalParser::WithStatementContext* PascalParser::StructuredStatementContext::withStatement() {
  return getRuleContext<PascalParser::WithStatementContext>(0);
}

PascalParser::WriteStatementContext* PascalParser::StructuredStatementContext::writeStatement() {
  return getRuleContext<PascalParser::WriteStatementContext>(0);
}

PascalParser::WritelnStatementContext* PascalParser::StructuredStatementContext::writelnStatement() {
  return getRuleContext<PascalParser::WritelnStatementContext>(0);
}


size_t PascalParser::StructuredStatementContext::getRuleIndex() const {
  return PascalParser::RuleStructuredStatement;
}


antlrcpp::Any PascalParser::StructuredStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStructuredStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StructuredStatementContext* PascalParser::structuredStatement() {
  StructuredStatementContext *_localctx = _tracker.createInstance<StructuredStatementContext>(_ctx, getState());
  enterRule(_localctx, 136, PascalParser::RuleStructuredStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(617);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::BEGIN: {
        enterOuterAlt(_localctx, 1);
        setState(610);
        compoundStatement();
        break;
      }

      case PascalParser::FOR:
      case PascalParser::REPEAT:
      case PascalParser::WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(611);
        reptitiveStatement();
        break;
      }

      case PascalParser::IF: {
        enterOuterAlt(_localctx, 3);
        setState(612);
        ifStatement();
        break;
      }

      case PascalParser::CASE: {
        enterOuterAlt(_localctx, 4);
        setState(613);
        caseStatement();
        break;
      }

      case PascalParser::WITH: {
        enterOuterAlt(_localctx, 5);
        setState(614);
        withStatement();
        break;
      }

      case PascalParser::WRITE: {
        enterOuterAlt(_localctx, 6);
        setState(615);
        writeStatement();
        break;
      }

      case PascalParser::WRITELN: {
        enterOuterAlt(_localctx, 7);
        setState(616);
        writelnStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReptitiveStatementContext ------------------------------------------------------------------

PascalParser::ReptitiveStatementContext::ReptitiveStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::WhileStatementContext* PascalParser::ReptitiveStatementContext::whileStatement() {
  return getRuleContext<PascalParser::WhileStatementContext>(0);
}

PascalParser::RepeatStatementContext* PascalParser::ReptitiveStatementContext::repeatStatement() {
  return getRuleContext<PascalParser::RepeatStatementContext>(0);
}

PascalParser::ForStatementContext* PascalParser::ReptitiveStatementContext::forStatement() {
  return getRuleContext<PascalParser::ForStatementContext>(0);
}


size_t PascalParser::ReptitiveStatementContext::getRuleIndex() const {
  return PascalParser::RuleReptitiveStatement;
}


antlrcpp::Any PascalParser::ReptitiveStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitReptitiveStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ReptitiveStatementContext* PascalParser::reptitiveStatement() {
  ReptitiveStatementContext *_localctx = _tracker.createInstance<ReptitiveStatementContext>(_ctx, getState());
  enterRule(_localctx, 138, PascalParser::RuleReptitiveStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(622);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::WHILE: {
        enterOuterAlt(_localctx, 1);
        setState(619);
        whileStatement();
        break;
      }

      case PascalParser::REPEAT: {
        enterOuterAlt(_localctx, 2);
        setState(620);
        repeatStatement();
        break;
      }

      case PascalParser::FOR: {
        enterOuterAlt(_localctx, 3);
        setState(621);
        forStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WriteArgumentsContext ------------------------------------------------------------------

PascalParser::WriteArgumentsContext::WriteArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::WriteArgsContext *> PascalParser::WriteArgumentsContext::writeArgs() {
  return getRuleContexts<PascalParser::WriteArgsContext>();
}

PascalParser::WriteArgsContext* PascalParser::WriteArgumentsContext::writeArgs(size_t i) {
  return getRuleContext<PascalParser::WriteArgsContext>(i);
}

tree::TerminalNode* PascalParser::WriteArgumentsContext::COMMA() {
  return getToken(PascalParser::COMMA, 0);
}


size_t PascalParser::WriteArgumentsContext::getRuleIndex() const {
  return PascalParser::RuleWriteArguments;
}


antlrcpp::Any PascalParser::WriteArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWriteArguments(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WriteArgumentsContext* PascalParser::writeArguments() {
  WriteArgumentsContext *_localctx = _tracker.createInstance<WriteArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 140, PascalParser::RuleWriteArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(624);
    writeArgs();
    setState(627);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::COMMA) {
      setState(625);
      match(PascalParser::COMMA);
      setState(626);
      writeArgs();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WriteArgsContext ------------------------------------------------------------------

PascalParser::WriteArgsContext::WriteArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::ExpressionContext* PascalParser::WriteArgsContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::WriteArgsContext::getRuleIndex() const {
  return PascalParser::RuleWriteArgs;
}


antlrcpp::Any PascalParser::WriteArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWriteArgs(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WriteArgsContext* PascalParser::writeArgs() {
  WriteArgsContext *_localctx = _tracker.createInstance<WriteArgsContext>(_ctx, getState());
  enterRule(_localctx, 142, PascalParser::RuleWriteArgs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(629);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WriteStatementContext ------------------------------------------------------------------

PascalParser::WriteStatementContext::WriteStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::WriteStatementContext::WRITE() {
  return getToken(PascalParser::WRITE, 0);
}

tree::TerminalNode* PascalParser::WriteStatementContext::LPAREN() {
  return getToken(PascalParser::LPAREN, 0);
}

PascalParser::WriteArgumentsContext* PascalParser::WriteStatementContext::writeArguments() {
  return getRuleContext<PascalParser::WriteArgumentsContext>(0);
}

tree::TerminalNode* PascalParser::WriteStatementContext::RPAREN() {
  return getToken(PascalParser::RPAREN, 0);
}


size_t PascalParser::WriteStatementContext::getRuleIndex() const {
  return PascalParser::RuleWriteStatement;
}


antlrcpp::Any PascalParser::WriteStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWriteStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WriteStatementContext* PascalParser::writeStatement() {
  WriteStatementContext *_localctx = _tracker.createInstance<WriteStatementContext>(_ctx, getState());
  enterRule(_localctx, 144, PascalParser::RuleWriteStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(631);
    match(PascalParser::WRITE);
    setState(632);
    match(PascalParser::LPAREN);
    setState(633);
    writeArguments();
    setState(634);
    match(PascalParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WritelnStatementContext ------------------------------------------------------------------

PascalParser::WritelnStatementContext::WritelnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::WritelnStatementContext::WRITELN() {
  return getToken(PascalParser::WRITELN, 0);
}

tree::TerminalNode* PascalParser::WritelnStatementContext::LPAREN() {
  return getToken(PascalParser::LPAREN, 0);
}

PascalParser::WriteArgumentsContext* PascalParser::WritelnStatementContext::writeArguments() {
  return getRuleContext<PascalParser::WriteArgumentsContext>(0);
}

tree::TerminalNode* PascalParser::WritelnStatementContext::RPAREN() {
  return getToken(PascalParser::RPAREN, 0);
}


size_t PascalParser::WritelnStatementContext::getRuleIndex() const {
  return PascalParser::RuleWritelnStatement;
}


antlrcpp::Any PascalParser::WritelnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWritelnStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WritelnStatementContext* PascalParser::writelnStatement() {
  WritelnStatementContext *_localctx = _tracker.createInstance<WritelnStatementContext>(_ctx, getState());
  enterRule(_localctx, 146, PascalParser::RuleWritelnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(636);
    match(PascalParser::WRITELN);
    setState(637);
    match(PascalParser::LPAREN);
    setState(638);
    writeArguments();
    setState(639);
    match(PascalParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

PascalParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::CompoundStatementContext::BEGIN() {
  return getToken(PascalParser::BEGIN, 0);
}

PascalParser::StatementsContext* PascalParser::CompoundStatementContext::statements() {
  return getRuleContext<PascalParser::StatementsContext>(0);
}

tree::TerminalNode* PascalParser::CompoundStatementContext::END() {
  return getToken(PascalParser::END, 0);
}


size_t PascalParser::CompoundStatementContext::getRuleIndex() const {
  return PascalParser::RuleCompoundStatement;
}


antlrcpp::Any PascalParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CompoundStatementContext* PascalParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 148, PascalParser::RuleCompoundStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(641);
    match(PascalParser::BEGIN);
    setState(642);
    statements();
    setState(643);
    match(PascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

PascalParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::StatementContext *> PascalParser::StatementsContext::statement() {
  return getRuleContexts<PascalParser::StatementContext>();
}

PascalParser::StatementContext* PascalParser::StatementsContext::statement(size_t i) {
  return getRuleContext<PascalParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> PascalParser::StatementsContext::SEMICOLON() {
  return getTokens(PascalParser::SEMICOLON);
}

tree::TerminalNode* PascalParser::StatementsContext::SEMICOLON(size_t i) {
  return getToken(PascalParser::SEMICOLON, i);
}


size_t PascalParser::StatementsContext::getRuleIndex() const {
  return PascalParser::RuleStatements;
}


antlrcpp::Any PascalParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::StatementsContext* PascalParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 150, PascalParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(645);
    statement();
    setState(650);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::SEMICOLON) {
      setState(646);
      match(PascalParser::SEMICOLON);
      setState(647);
      statement();
      setState(652);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

PascalParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::IfStatementContext::IF() {
  return getToken(PascalParser::IF, 0);
}

PascalParser::ExpressionContext* PascalParser::IfStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalParser::IfStatementContext::THEN() {
  return getToken(PascalParser::THEN, 0);
}

std::vector<PascalParser::StatementContext *> PascalParser::IfStatementContext::statement() {
  return getRuleContexts<PascalParser::StatementContext>();
}

PascalParser::StatementContext* PascalParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<PascalParser::StatementContext>(i);
}

tree::TerminalNode* PascalParser::IfStatementContext::ELSE() {
  return getToken(PascalParser::ELSE, 0);
}


size_t PascalParser::IfStatementContext::getRuleIndex() const {
  return PascalParser::RuleIfStatement;
}


antlrcpp::Any PascalParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::IfStatementContext* PascalParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 152, PascalParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(653);
    match(PascalParser::IF);
    setState(654);
    expression();
    setState(655);
    match(PascalParser::THEN);
    setState(656);
    statement();
    setState(659);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(657);
      match(PascalParser::ELSE);
      setState(658);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

PascalParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::CaseStatementContext::CASE() {
  return getToken(PascalParser::CASE, 0);
}

PascalParser::ExpressionContext* PascalParser::CaseStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalParser::CaseStatementContext::OF() {
  return getToken(PascalParser::OF, 0);
}

std::vector<PascalParser::CaseListElementContext *> PascalParser::CaseStatementContext::caseListElement() {
  return getRuleContexts<PascalParser::CaseListElementContext>();
}

PascalParser::CaseListElementContext* PascalParser::CaseStatementContext::caseListElement(size_t i) {
  return getRuleContext<PascalParser::CaseListElementContext>(i);
}

tree::TerminalNode* PascalParser::CaseStatementContext::END() {
  return getToken(PascalParser::END, 0);
}

std::vector<tree::TerminalNode *> PascalParser::CaseStatementContext::SEMICOLON() {
  return getTokens(PascalParser::SEMICOLON);
}

tree::TerminalNode* PascalParser::CaseStatementContext::SEMICOLON(size_t i) {
  return getToken(PascalParser::SEMICOLON, i);
}

tree::TerminalNode* PascalParser::CaseStatementContext::ELSE() {
  return getToken(PascalParser::ELSE, 0);
}

PascalParser::StatementsContext* PascalParser::CaseStatementContext::statements() {
  return getRuleContext<PascalParser::StatementsContext>(0);
}


size_t PascalParser::CaseStatementContext::getRuleIndex() const {
  return PascalParser::RuleCaseStatement;
}


antlrcpp::Any PascalParser::CaseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCaseStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CaseStatementContext* PascalParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 154, PascalParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(661);
    match(PascalParser::CASE);
    setState(662);
    expression();
    setState(663);
    match(PascalParser::OF);
    setState(664);
    caseListElement();
    setState(669);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(665);
        match(PascalParser::SEMICOLON);
        setState(666);
        caseListElement(); 
      }
      setState(671);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    }
    setState(675);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::SEMICOLON) {
      setState(672);
      match(PascalParser::SEMICOLON);
      setState(673);
      match(PascalParser::ELSE);
      setState(674);
      statements();
    }
    setState(677);
    match(PascalParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseListElementContext ------------------------------------------------------------------

PascalParser::CaseListElementContext::CaseListElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PascalParser::ConstantContext *> PascalParser::CaseListElementContext::constant() {
  return getRuleContexts<PascalParser::ConstantContext>();
}

PascalParser::ConstantContext* PascalParser::CaseListElementContext::constant(size_t i) {
  return getRuleContext<PascalParser::ConstantContext>(i);
}

tree::TerminalNode* PascalParser::CaseListElementContext::COLON() {
  return getToken(PascalParser::COLON, 0);
}

PascalParser::StatementContext* PascalParser::CaseListElementContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}

std::vector<tree::TerminalNode *> PascalParser::CaseListElementContext::COMMA() {
  return getTokens(PascalParser::COMMA);
}

tree::TerminalNode* PascalParser::CaseListElementContext::COMMA(size_t i) {
  return getToken(PascalParser::COMMA, i);
}


size_t PascalParser::CaseListElementContext::getRuleIndex() const {
  return PascalParser::RuleCaseListElement;
}


antlrcpp::Any PascalParser::CaseListElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitCaseListElement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::CaseListElementContext* PascalParser::caseListElement() {
  CaseListElementContext *_localctx = _tracker.createInstance<CaseListElementContext>(_ctx, getState());
  enterRule(_localctx, 156, PascalParser::RuleCaseListElement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(679);
    constant();
    setState(684);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(680);
      match(PascalParser::COMMA);
      setState(681);
      constant();
      setState(686);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(687);
    match(PascalParser::COLON);
    setState(688);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

PascalParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::WhileStatementContext::WHILE() {
  return getToken(PascalParser::WHILE, 0);
}

PascalParser::ExpressionContext* PascalParser::WhileStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalParser::WhileStatementContext::DO() {
  return getToken(PascalParser::DO, 0);
}

PascalParser::StatementContext* PascalParser::WhileStatementContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}


size_t PascalParser::WhileStatementContext::getRuleIndex() const {
  return PascalParser::RuleWhileStatement;
}


antlrcpp::Any PascalParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WhileStatementContext* PascalParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 158, PascalParser::RuleWhileStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(690);
    match(PascalParser::WHILE);
    setState(691);
    expression();
    setState(692);
    match(PascalParser::DO);
    setState(693);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RepeatStatementContext ------------------------------------------------------------------

PascalParser::RepeatStatementContext::RepeatStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::RepeatStatementContext::REPEAT() {
  return getToken(PascalParser::REPEAT, 0);
}

PascalParser::StatementsContext* PascalParser::RepeatStatementContext::statements() {
  return getRuleContext<PascalParser::StatementsContext>(0);
}

tree::TerminalNode* PascalParser::RepeatStatementContext::UNTIL() {
  return getToken(PascalParser::UNTIL, 0);
}

PascalParser::ExpressionContext* PascalParser::RepeatStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}


size_t PascalParser::RepeatStatementContext::getRuleIndex() const {
  return PascalParser::RuleRepeatStatement;
}


antlrcpp::Any PascalParser::RepeatStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitRepeatStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::RepeatStatementContext* PascalParser::repeatStatement() {
  RepeatStatementContext *_localctx = _tracker.createInstance<RepeatStatementContext>(_ctx, getState());
  enterRule(_localctx, 160, PascalParser::RuleRepeatStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(695);
    match(PascalParser::REPEAT);
    setState(696);
    statements();
    setState(697);
    match(PascalParser::UNTIL);
    setState(698);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

PascalParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::ForStatementContext::FOR() {
  return getToken(PascalParser::FOR, 0);
}

PascalParser::AssignmentStatementContext* PascalParser::ForStatementContext::assignmentStatement() {
  return getRuleContext<PascalParser::AssignmentStatementContext>(0);
}

PascalParser::ExpressionContext* PascalParser::ForStatementContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
}

tree::TerminalNode* PascalParser::ForStatementContext::DO() {
  return getToken(PascalParser::DO, 0);
}

PascalParser::StatementContext* PascalParser::ForStatementContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}

tree::TerminalNode* PascalParser::ForStatementContext::TO() {
  return getToken(PascalParser::TO, 0);
}

tree::TerminalNode* PascalParser::ForStatementContext::DOWNTO() {
  return getToken(PascalParser::DOWNTO, 0);
}


size_t PascalParser::ForStatementContext::getRuleIndex() const {
  return PascalParser::RuleForStatement;
}


antlrcpp::Any PascalParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::ForStatementContext* PascalParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 162, PascalParser::RuleForStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(700);
    match(PascalParser::FOR);
    setState(701);
    assignmentStatement();
    setState(702);
    _la = _input->LA(1);
    if (!(_la == PascalParser::DOWNTO

    || _la == PascalParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(703);
    expression();
    setState(704);
    match(PascalParser::DO);
    setState(705);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithStatementContext ------------------------------------------------------------------

PascalParser::WithStatementContext::WithStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PascalParser::WithStatementContext::WITH() {
  return getToken(PascalParser::WITH, 0);
}

std::vector<PascalParser::VariableContext *> PascalParser::WithStatementContext::variable() {
  return getRuleContexts<PascalParser::VariableContext>();
}

PascalParser::VariableContext* PascalParser::WithStatementContext::variable(size_t i) {
  return getRuleContext<PascalParser::VariableContext>(i);
}

tree::TerminalNode* PascalParser::WithStatementContext::DO() {
  return getToken(PascalParser::DO, 0);
}

PascalParser::StatementContext* PascalParser::WithStatementContext::statement() {
  return getRuleContext<PascalParser::StatementContext>(0);
}

std::vector<tree::TerminalNode *> PascalParser::WithStatementContext::COMMA() {
  return getTokens(PascalParser::COMMA);
}

tree::TerminalNode* PascalParser::WithStatementContext::COMMA(size_t i) {
  return getToken(PascalParser::COMMA, i);
}


size_t PascalParser::WithStatementContext::getRuleIndex() const {
  return PascalParser::RuleWithStatement;
}


antlrcpp::Any PascalParser::WithStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PascalVisitor*>(visitor))
    return parserVisitor->visitWithStatement(this);
  else
    return visitor->visitChildren(this);
}

PascalParser::WithStatementContext* PascalParser::withStatement() {
  WithStatementContext *_localctx = _tracker.createInstance<WithStatementContext>(_ctx, getState());
  enterRule(_localctx, 164, PascalParser::RuleWithStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(707);
    match(PascalParser::WITH);
    setState(708);
    variable();
    setState(713);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(709);
      match(PascalParser::COMMA);
      setState(710);
      variable();
      setState(715);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(716);
    match(PascalParser::DO);
    setState(717);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> PascalParser::_decisionToDFA;
atn::PredictionContextCache PascalParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PascalParser::_atn;
std::vector<uint16_t> PascalParser::_serializedATN;

std::vector<std::string> PascalParser::_ruleNames = {
  "program", "programHead", "identifier", "block", "usesUnitsPart", "labelDeclarationPart", 
  "constantDefinitionPart", "constantDefinition", "constantIdentifier", 
  "typeDefinitionPart", "typeDefinition", "formalParameterList", "formalParameterSection", 
  "parameterGroup", "functionType", "procedureType", "variableDeclarationPart", 
  "variableDeclaration", "procedureAndFunctionDeclarationPart", "procedureOrFunctionDeclaration", 
  "procedureDeclaration", "functionDeclaration", "type_", "structuredType", 
  "unpackedStructuredType", "arrayType", "typeList", "pointerType", "label", 
  "constantVar", "constantChr", "constant", "unsignedNumber", "unsignedInteger", 
  "unsignedReal", "sign", "bool_", "typeIdentifier", "string", "simpleType", 
  "scalarType", "stringtype", "identifierList", "statement", "unlabelledStatement", 
  "simpleStatement", "procedureStatement", "emptyStatement_", "assignmentStatement", 
  "variable", "variableIdentifier", "modifier", "expression", "relationaloperator", 
  "simpleExpression", "additiveoperator", "term", "multiplicativeoperator", 
  "signedFactor", "factor", "unsignedConstant", "functionDesignator", "parameterList", 
  "actualParameter", "parameterwidth", "set_", "element", "gotoStatement", 
  "structuredStatement", "reptitiveStatement", "writeArguments", "writeArgs", 
  "writeStatement", "writelnStatement", "compoundStatement", "statements", 
  "ifStatement", "caseStatement", "caseListElement", "whileStatement", "repeatStatement", 
  "forStatement", "withStatement"
};

std::vector<std::string> PascalParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "':='", 
  "':'", "'='", "'(.'", "'.)'", "'@'", "'.'", "'..'", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "'+'", "'-'", "'*'", 
  "'/'", "'<>'", "'<='", "'>='", "'<'", "'>'", "'+='", "'-='", "'*='", "'/='", 
  "'^'", "';'", "','", "'('", "')'", "'['", "']'", "'{'", "'}'", "'(*'", 
  "'*)'"
};

std::vector<std::string> PascalParser::_symbolicNames = {
  "", "AND", "ARRAY", "ASM", "BEGIN", "BREAK", "BOOLEAN", "CASE", "CHAR", 
  "CHR", "CONST", "CONSTRUCTOR", "CONTINUE", "DESTRUCTOR", "DIV", "DO", 
  "DOWNTO", "ELSE", "END", "FILE", "FOR", "FUNCTION", "GOTO", "IF", "IN", 
  "INLINE", "INTEGER", "LABEL", "MOD", "NIL", "OBJECT", "WRITE", "WRITELN", 
  "NOT", "OF", "ON", "OPERATOR", "OR", "PACKED", "PROCEDURE", "PROGRAM", 
  "REAL", "RECORD", "REPEAT", "SET", "THEN", "TO", "TYPE", "UNTIL", "VAR", 
  "WHILE", "WITH", "ASSIGN", "COLON", "EQUAL", "LBRACKET2", "RBRACKET2", 
  "AT", "DOT", "DOTDOT", "UNIT", "INTERFACE", "USES", "STRING", "IMPLEMENTATION", 
  "TRUE", "FALSE", "WS", "COMMENT_1", "COMMENT_2", "IDENT", "STRING_LITERAL", 
  "NUM_INT", "NUM_REAL", "SHL", "SHR", "XOR", "IDENTIFIER", "PLUSOP", "MINUSOP", 
  "MULTOP", "DIVOP", "NE", "LTEQ", "GTEQ", "LT", "GT", "PLUSEQUAL", "MINUSEQUAL", 
  "MULTEQUAL", "DIVEQUAL", "CARAT", "SEMICOLON", "COMMA", "LPAREN", "RPAREN", 
  "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "LCOMMENT", "RCOMMENT"
};

dfa::Vocabulary PascalParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PascalParser::_tokenNames;

PascalParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x67, 0x2d2, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x5, 0x3, 0xb4, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0xbc, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x7, 0x5, 0xc7, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xca, 0xb, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0xd6, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xd9, 
    0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x6, 0x8, 0xe1, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0xe2, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x6, 0xb, 0xef, 0xa, 0xb, 0xd, 0xb, 0xe, 0xb, 0xf0, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xf8, 0xa, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xfe, 0xa, 0xd, 0xc, 0xd, 
    0xe, 0xd, 0x101, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x10c, 0xa, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0x114, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0x11b, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x7, 0x12, 0x121, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x124, 0xb, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x131, 
    0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x136, 0xa, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 
    0x17, 0x13e, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x148, 0xa, 0x18, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x14d, 0xa, 0x19, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x15f, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x7, 0x1c, 0x164, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x167, 
    0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 
    0x181, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x185, 0xa, 0x22, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 
    0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x191, 0xa, 0x27, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x198, 
    0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 
    0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x1a2, 0xa, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x1a9, 0xa, 0x2c, 
    0xc, 0x2c, 0xe, 0x2c, 0x1ac, 0xb, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x1b4, 0xa, 0x2d, 0x3, 0x2e, 
    0x3, 0x2e, 0x5, 0x2e, 0x1b8, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x5, 0x2f, 0x1be, 0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x1c5, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x5, 0x33, 0x1d0, 0xa, 0x33, 0x3, 0x33, 0x7, 0x33, 0x1d3, 0xa, 
    0x33, 0xc, 0x33, 0xe, 0x33, 0x1d6, 0xb, 0x33, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x1de, 0xa, 0x35, 
    0xc, 0x35, 0xe, 0x35, 0x1e1, 0xb, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x1e9, 0xa, 0x35, 0xc, 0x35, 
    0xe, 0x35, 0x1ec, 0xb, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x35, 0x5, 0x35, 0x1f3, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x3, 0x36, 0x7, 0x36, 0x1f9, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x1fc, 
    0xb, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x38, 0x7, 0x38, 0x204, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x207, 0xb, 
    0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x7, 0x3a, 0x20f, 0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 0x212, 0xb, 0x3a, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x5, 0x3c, 0x217, 0xa, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 
    0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 
    0x226, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 
    0x22c, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x236, 0xa, 0x40, 0xc, 0x40, 
    0xe, 0x40, 0x239, 0xb, 0x40, 0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x23d, 
    0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 0x240, 0xb, 0x41, 0x3, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x249, 
    0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x24c, 0xb, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x254, 0xa, 0x43, 
    0xc, 0x43, 0xe, 0x43, 0x257, 0xb, 0x43, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 
    0x25b, 0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x260, 
    0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 
    0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x26c, 
    0xa, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x5, 0x47, 0x271, 0xa, 0x47, 
    0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 0x276, 0xa, 0x48, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 
    0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 
    0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x7, 0x4d, 0x28b, 
    0xa, 0x4d, 0xc, 0x4d, 0xe, 0x4d, 0x28e, 0xb, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 
    0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x296, 0xa, 0x4e, 
    0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x7, 
    0x4f, 0x29e, 0xa, 0x4f, 0xc, 0x4f, 0xe, 0x4f, 0x2a1, 0xb, 0x4f, 0x3, 
    0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x2a6, 0xa, 0x4f, 0x3, 0x4f, 
    0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x7, 0x50, 0x2ad, 0xa, 0x50, 
    0xc, 0x50, 0xe, 0x50, 0x2b0, 0xb, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 
    0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 0x3, 
    0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
    0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 
    0x54, 0x3, 0x54, 0x7, 0x54, 0x2ca, 0xa, 0x54, 0xc, 0x54, 0xe, 0x54, 
    0x2cd, 0xb, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x2, 0x2, 
    0x55, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
    0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 
    0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 
    0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 
    0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0x2, 
    0x9, 0x3, 0x2, 0x50, 0x51, 0x3, 0x2, 0x43, 0x44, 0x7, 0x2, 0x8, 0x8, 
    0xa, 0xa, 0x1c, 0x1c, 0x2b, 0x2b, 0x41, 0x41, 0x5, 0x2, 0x1a, 0x1a, 
    0x38, 0x38, 0x54, 0x58, 0x4, 0x2, 0x27, 0x27, 0x50, 0x51, 0x6, 0x2, 
    0x3, 0x3, 0x10, 0x10, 0x1e, 0x1e, 0x52, 0x53, 0x4, 0x2, 0x12, 0x12, 
    0x30, 0x30, 0x2, 0x2d6, 0x2, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x4, 0xbb, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x8, 0xc8, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0xdc, 0x3, 0x2, 0x2, 0x2, 0x10, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x12, 0xe8, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0xea, 0x3, 0x2, 0x2, 0x2, 0x16, 0xf2, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x10b, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x111, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x118, 0x3, 0x2, 0x2, 0x2, 0x22, 0x11c, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0x127, 0x3, 0x2, 0x2, 0x2, 0x26, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x28, 
    0x130, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x132, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x13a, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x147, 0x3, 0x2, 0x2, 0x2, 0x30, 0x14c, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x34, 0x15e, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x160, 0x3, 0x2, 0x2, 0x2, 0x38, 0x168, 0x3, 0x2, 0x2, 
    0x2, 0x3a, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x16d, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x171, 0x3, 0x2, 0x2, 0x2, 0x40, 0x180, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x184, 0x3, 0x2, 0x2, 0x2, 0x44, 0x186, 0x3, 0x2, 0x2, 0x2, 0x46, 0x188, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x18c, 0x3, 
    0x2, 0x2, 0x2, 0x4c, 0x190, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x192, 0x3, 0x2, 
    0x2, 0x2, 0x50, 0x197, 0x3, 0x2, 0x2, 0x2, 0x52, 0x199, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1a5, 0x3, 0x2, 0x2, 0x2, 
    0x58, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x5c, 
    0x1bd, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1c6, 
    0x3, 0x2, 0x2, 0x2, 0x62, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1cf, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1f2, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x1fd, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x70, 0x208, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x74, 0x213, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x216, 0x3, 0x2, 0x2, 0x2, 0x78, 0x225, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x22b, 
    0x3, 0x2, 0x2, 0x2, 0x7c, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x232, 0x3, 
    0x2, 0x2, 0x2, 0x80, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x82, 0x241, 0x3, 0x2, 
    0x2, 0x2, 0x84, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x86, 0x25c, 0x3, 0x2, 0x2, 
    0x2, 0x88, 0x261, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x26b, 0x3, 0x2, 0x2, 0x2, 
    0x8c, 0x270, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x272, 0x3, 0x2, 0x2, 0x2, 0x90, 
    0x277, 0x3, 0x2, 0x2, 0x2, 0x92, 0x279, 0x3, 0x2, 0x2, 0x2, 0x94, 0x27e, 
    0x3, 0x2, 0x2, 0x2, 0x96, 0x283, 0x3, 0x2, 0x2, 0x2, 0x98, 0x287, 0x3, 
    0x2, 0x2, 0x2, 0x9a, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x297, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x2b4, 0x3, 0x2, 0x2, 
    0x2, 0xa2, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x2be, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x5, 0x4, 0x3, 0x2, 0xa9, 
    0xaa, 0x5, 0x8, 0x5, 0x2, 0xaa, 0xab, 0x7, 0x3c, 0x2, 0x2, 0xab, 0xac, 
    0x7, 0x2, 0x2, 0x3, 0xac, 0x3, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x7, 
    0x2a, 0x2, 0x2, 0xae, 0xb3, 0x5, 0x6, 0x4, 0x2, 0xaf, 0xb0, 0x7, 0x60, 
    0x2, 0x2, 0xb0, 0xb1, 0x5, 0x56, 0x2c, 0x2, 0xb1, 0xb2, 0x7, 0x61, 0x2, 
    0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb5, 
    0xb6, 0x7, 0x5e, 0x2, 0x2, 0xb6, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 
    0x7, 0x3e, 0x2, 0x2, 0xb8, 0xb9, 0x5, 0x6, 0x4, 0x2, 0xb9, 0xba, 0x7, 
    0x5e, 0x2, 0x2, 0xba, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xad, 0x3, 0x2, 
    0x2, 0x2, 0xbb, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0xbd, 0xbe, 0x7, 0x48, 0x2, 0x2, 0xbe, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xc7, 0x5, 0xc, 0x7, 0x2, 0xc0, 0xc7, 0x5, 0xe, 0x8, 0x2, 0xc1, 
    0xc7, 0x5, 0x14, 0xb, 0x2, 0xc2, 0xc7, 0x5, 0x26, 0x14, 0x2, 0xc3, 0xc7, 
    0x5, 0x22, 0x12, 0x2, 0xc4, 0xc7, 0x5, 0xa, 0x6, 0x2, 0xc5, 0xc7, 0x7, 
    0x42, 0x2, 0x2, 0xc6, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc0, 0x3, 0x2, 
    0x2, 0x2, 0xc6, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc2, 0x3, 0x2, 0x2, 
    0x2, 0xc6, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 
    0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc8, 
    0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x5, 
    0x96, 0x4c, 0x2, 0xcc, 0x9, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x40, 
    0x2, 0x2, 0xce, 0xcf, 0x5, 0x56, 0x2c, 0x2, 0xcf, 0xd0, 0x7, 0x5e, 0x2, 
    0x2, 0xd0, 0xb, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x1d, 0x2, 0x2, 
    0xd2, 0xd7, 0x5, 0x3a, 0x1e, 0x2, 0xd3, 0xd4, 0x7, 0x5f, 0x2, 0x2, 0xd4, 
    0xd6, 0x5, 0x3a, 0x1e, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd9, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 
    0x2, 0x2, 0xda, 0xdb, 0x7, 0x5e, 0x2, 0x2, 0xdb, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0xdc, 0xe0, 0x7, 0xc, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x10, 0x9, 0x2, 
    0xde, 0xdf, 0x7, 0x5e, 0x2, 0x2, 0xdf, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0xdd, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 
    0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x12, 0xa, 0x2, 0xe5, 0xe6, 0x7, 0x38, 
    0x2, 0x2, 0xe6, 0xe7, 0x5, 0x40, 0x21, 0x2, 0xe7, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0xe9, 0x7, 0x48, 0x2, 0x2, 0xe9, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0xea, 0xee, 0x7, 0x31, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x16, 0xc, 0x2, 0xec, 
    0xed, 0x7, 0x5e, 0x2, 0x2, 0xed, 0xef, 0x3, 0x2, 0x2, 0x2, 0xee, 0xeb, 
    0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 
    0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0xf2, 0xf3, 0x5, 0x4c, 0x27, 0x2, 0xf3, 0xf7, 0x7, 0x38, 0x2, 
    0x2, 0xf4, 0xf8, 0x5, 0x2e, 0x18, 0x2, 0xf5, 0xf8, 0x5, 0x1e, 0x10, 
    0x2, 0xf6, 0xf8, 0x5, 0x20, 0x11, 0x2, 0xf7, 0xf4, 0x3, 0x2, 0x2, 0x2, 
    0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x60, 0x2, 0x2, 0xfa, 0xff, 
    0x5, 0x1a, 0xe, 0x2, 0xfb, 0xfc, 0x7, 0x5e, 0x2, 0x2, 0xfc, 0xfe, 0x5, 
    0x1a, 0xe, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x101, 0x3, 0x2, 
    0x2, 0x2, 0xff, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 
    0x2, 0x100, 0x102, 0x3, 0x2, 0x2, 0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 
    0x102, 0x103, 0x7, 0x61, 0x2, 0x2, 0x103, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x104, 0x10c, 0x5, 0x1c, 0xf, 0x2, 0x105, 0x106, 0x7, 0x33, 0x2, 0x2, 
    0x106, 0x10c, 0x5, 0x1c, 0xf, 0x2, 0x107, 0x108, 0x7, 0x17, 0x2, 0x2, 
    0x108, 0x10c, 0x5, 0x1c, 0xf, 0x2, 0x109, 0x10a, 0x7, 0x29, 0x2, 0x2, 
    0x10a, 0x10c, 0x5, 0x1c, 0xf, 0x2, 0x10b, 0x104, 0x3, 0x2, 0x2, 0x2, 
    0x10b, 0x105, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x107, 0x3, 0x2, 0x2, 0x2, 
    0x10b, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x10d, 
    0x10e, 0x5, 0x56, 0x2c, 0x2, 0x10e, 0x10f, 0x7, 0x37, 0x2, 0x2, 0x10f, 
    0x110, 0x5, 0x4c, 0x27, 0x2, 0x110, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x111, 
    0x113, 0x7, 0x17, 0x2, 0x2, 0x112, 0x114, 0x5, 0x18, 0xd, 0x2, 0x113, 
    0x112, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 0x2, 0x2, 0x2, 0x114, 
    0x115, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x7, 0x37, 0x2, 0x2, 0x116, 
    0x117, 0x5, 0x4c, 0x27, 0x2, 0x117, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x11a, 0x7, 0x29, 0x2, 0x2, 0x119, 0x11b, 0x5, 0x18, 0xd, 0x2, 0x11a, 
    0x119, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11b, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0x33, 0x2, 0x2, 0x11d, 
    0x122, 0x5, 0x24, 0x13, 0x2, 0x11e, 0x11f, 0x7, 0x5e, 0x2, 0x2, 0x11f, 
    0x121, 0x5, 0x24, 0x13, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x121, 
    0x124, 0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 0x2, 0x122, 
    0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x125, 0x3, 0x2, 0x2, 0x2, 0x124, 
    0x122, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x7, 0x5e, 0x2, 0x2, 0x126, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x5, 0x56, 0x2c, 0x2, 0x128, 
    0x129, 0x7, 0x37, 0x2, 0x2, 0x129, 0x12a, 0x5, 0x2e, 0x18, 0x2, 0x12a, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x28, 0x15, 0x2, 0x12c, 
    0x12d, 0x7, 0x5e, 0x2, 0x2, 0x12d, 0x27, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x131, 0x5, 0x2a, 0x16, 0x2, 0x12f, 0x131, 0x5, 0x2c, 0x17, 0x2, 0x130, 
    0x12e, 0x3, 0x2, 0x2, 0x2, 0x130, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x131, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x7, 0x29, 0x2, 0x2, 0x133, 
    0x135, 0x5, 0x6, 0x4, 0x2, 0x134, 0x136, 0x5, 0x18, 0xd, 0x2, 0x135, 
    0x134, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x3, 0x2, 0x2, 0x2, 0x136, 
    0x137, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x7, 0x5e, 0x2, 0x2, 0x138, 
    0x139, 0x5, 0x8, 0x5, 0x2, 0x139, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 
    0x7, 0x17, 0x2, 0x2, 0x13b, 0x13d, 0x5, 0x6, 0x4, 0x2, 0x13c, 0x13e, 
    0x5, 0x18, 0xd, 0x2, 0x13d, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 
    0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 
    0x7, 0x37, 0x2, 0x2, 0x140, 0x141, 0x5, 0x4c, 0x27, 0x2, 0x141, 0x142, 
    0x7, 0x5e, 0x2, 0x2, 0x142, 0x143, 0x5, 0x8, 0x5, 0x2, 0x143, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0x144, 0x148, 0x5, 0x50, 0x29, 0x2, 0x145, 0x148, 
    0x5, 0x30, 0x19, 0x2, 0x146, 0x148, 0x5, 0x38, 0x1d, 0x2, 0x147, 0x144, 
    0x3, 0x2, 0x2, 0x2, 0x147, 0x145, 0x3, 0x2, 0x2, 0x2, 0x147, 0x146, 
    0x3, 0x2, 0x2, 0x2, 0x148, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x7, 
    0x28, 0x2, 0x2, 0x14a, 0x14d, 0x5, 0x32, 0x1a, 0x2, 0x14b, 0x14d, 0x5, 
    0x32, 0x1a, 0x2, 0x14c, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14b, 0x3, 
    0x2, 0x2, 0x2, 0x14d, 0x31, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x5, 0x34, 
    0x1b, 0x2, 0x14f, 0x33, 0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 0x7, 0x4, 
    0x2, 0x2, 0x151, 0x152, 0x7, 0x62, 0x2, 0x2, 0x152, 0x153, 0x5, 0x36, 
    0x1c, 0x2, 0x153, 0x154, 0x7, 0x63, 0x2, 0x2, 0x154, 0x155, 0x7, 0x24, 
    0x2, 0x2, 0x155, 0x156, 0x5, 0x2e, 0x18, 0x2, 0x156, 0x15f, 0x3, 0x2, 
    0x2, 0x2, 0x157, 0x158, 0x7, 0x4, 0x2, 0x2, 0x158, 0x159, 0x7, 0x39, 
    0x2, 0x2, 0x159, 0x15a, 0x5, 0x36, 0x1c, 0x2, 0x15a, 0x15b, 0x7, 0x3a, 
    0x2, 0x2, 0x15b, 0x15c, 0x7, 0x24, 0x2, 0x2, 0x15c, 0x15d, 0x5, 0x2e, 
    0x18, 0x2, 0x15d, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x150, 0x3, 0x2, 
    0x2, 0x2, 0x15e, 0x157, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x160, 0x165, 0x5, 0x50, 0x29, 0x2, 0x161, 0x162, 0x7, 0x5f, 0x2, 
    0x2, 0x162, 0x164, 0x5, 0x50, 0x29, 0x2, 0x163, 0x161, 0x3, 0x2, 0x2, 
    0x2, 0x164, 0x167, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 
    0x2, 0x165, 0x166, 0x3, 0x2, 0x2, 0x2, 0x166, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x167, 0x165, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x7, 0x5d, 0x2, 0x2, 
    0x169, 0x16a, 0x5, 0x4c, 0x27, 0x2, 0x16a, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x16b, 0x16c, 0x5, 0x44, 0x23, 0x2, 0x16c, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x16d, 0x16e, 0x5, 0x6, 0x4, 0x2, 0x16e, 0x16f, 0x7, 0x38, 0x2, 0x2, 
    0x16f, 0x170, 0x5, 0x40, 0x21, 0x2, 0x170, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x171, 0x172, 0x7, 0xb, 0x2, 0x2, 0x172, 0x173, 0x7, 0x60, 0x2, 0x2, 
    0x173, 0x174, 0x5, 0x44, 0x23, 0x2, 0x174, 0x175, 0x7, 0x61, 0x2, 0x2, 
    0x175, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x176, 0x181, 0x5, 0x42, 0x22, 0x2, 
    0x177, 0x178, 0x5, 0x48, 0x25, 0x2, 0x178, 0x179, 0x5, 0x42, 0x22, 0x2, 
    0x179, 0x181, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x181, 0x5, 0x6, 0x4, 0x2, 
    0x17b, 0x17c, 0x5, 0x48, 0x25, 0x2, 0x17c, 0x17d, 0x5, 0x6, 0x4, 0x2, 
    0x17d, 0x181, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x181, 0x5, 0x4e, 0x28, 0x2, 
    0x17f, 0x181, 0x5, 0x3e, 0x20, 0x2, 0x180, 0x176, 0x3, 0x2, 0x2, 0x2, 
    0x180, 0x177, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17a, 0x3, 0x2, 0x2, 0x2, 
    0x180, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 
    0x180, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x181, 0x41, 0x3, 0x2, 0x2, 0x2, 0x182, 
    0x185, 0x5, 0x44, 0x23, 0x2, 0x183, 0x185, 0x5, 0x46, 0x24, 0x2, 0x184, 
    0x182, 0x3, 0x2, 0x2, 0x2, 0x184, 0x183, 0x3, 0x2, 0x2, 0x2, 0x185, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x7, 0x4a, 0x2, 0x2, 0x187, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x7, 0x4b, 0x2, 0x2, 0x189, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x9, 0x2, 0x2, 0x2, 0x18b, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x9, 0x3, 0x2, 0x2, 0x18d, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x18e, 0x191, 0x5, 0x6, 0x4, 0x2, 0x18f, 0x191, 0x9, 
    0x4, 0x2, 0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18f, 0x3, 
    0x2, 0x2, 0x2, 0x191, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x192, 0x193, 0x7, 0x49, 
    0x2, 0x2, 0x193, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x194, 0x198, 0x5, 0x52, 
    0x2a, 0x2, 0x195, 0x198, 0x5, 0x4c, 0x27, 0x2, 0x196, 0x198, 0x5, 0x54, 
    0x2b, 0x2, 0x197, 0x194, 0x3, 0x2, 0x2, 0x2, 0x197, 0x195, 0x3, 0x2, 
    0x2, 0x2, 0x197, 0x196, 0x3, 0x2, 0x2, 0x2, 0x198, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x199, 0x19a, 0x7, 0x60, 0x2, 0x2, 0x19a, 0x19b, 0x5, 0x56, 0x2c, 
    0x2, 0x19b, 0x19c, 0x7, 0x61, 0x2, 0x2, 0x19c, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x19d, 0x19e, 0x7, 0x41, 0x2, 0x2, 0x19e, 0x1a1, 0x7, 0x62, 0x2, 
    0x2, 0x19f, 0x1a2, 0x5, 0x6, 0x4, 0x2, 0x1a0, 0x1a2, 0x5, 0x42, 0x22, 
    0x2, 0x1a1, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a0, 0x3, 0x2, 0x2, 
    0x2, 0x1a2, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0x7, 0x63, 0x2, 
    0x2, 0x1a4, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1aa, 0x5, 0x6, 0x4, 0x2, 
    0x1a6, 0x1a7, 0x7, 0x5f, 0x2, 0x2, 0x1a7, 0x1a9, 0x5, 0x6, 0x4, 0x2, 
    0x1a8, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1ac, 0x3, 0x2, 0x2, 0x2, 
    0x1aa, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x3, 0x2, 0x2, 0x2, 
    0x1ab, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ad, 
    0x1ae, 0x5, 0x3a, 0x1e, 0x2, 0x1ae, 0x1af, 0x7, 0x37, 0x2, 0x2, 0x1af, 
    0x1b0, 0x5, 0x5a, 0x2e, 0x2, 0x1b0, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b1, 
    0x1b4, 0x5, 0x5a, 0x2e, 0x2, 0x1b2, 0x1b4, 0x5, 0x26, 0x14, 0x2, 0x1b3, 
    0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b3, 
    0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b8, 
    0x5, 0x5c, 0x2f, 0x2, 0x1b6, 0x1b8, 0x5, 0x8a, 0x46, 0x2, 0x1b7, 0x1b5, 
    0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x1b9, 0x1be, 0x5, 0x62, 0x32, 0x2, 0x1ba, 0x1be, 0x5, 
    0x5e, 0x30, 0x2, 0x1bb, 0x1be, 0x5, 0x88, 0x45, 0x2, 0x1bc, 0x1be, 0x5, 
    0x60, 0x31, 0x2, 0x1bd, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1ba, 0x3, 
    0x2, 0x2, 0x2, 0x1bd, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1bc, 0x3, 
    0x2, 0x2, 0x2, 0x1be, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c4, 0x5, 0x6, 
    0x4, 0x2, 0x1c0, 0x1c1, 0x7, 0x60, 0x2, 0x2, 0x1c1, 0x1c2, 0x5, 0x7e, 
    0x40, 0x2, 0x1c2, 0x1c3, 0x7, 0x61, 0x2, 0x2, 0x1c3, 0x1c5, 0x3, 0x2, 
    0x2, 0x2, 0x1c4, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x3, 0x2, 
    0x2, 0x2, 0x1c5, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 0x3, 0x2, 0x2, 
    0x2, 0x1c7, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0x5, 0x64, 0x33, 
    0x2, 0x1c9, 0x1ca, 0x7, 0x36, 0x2, 0x2, 0x1ca, 0x1cb, 0x5, 0x6a, 0x36, 
    0x2, 0x1cb, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x7, 0x3b, 0x2, 
    0x2, 0x1cd, 0x1d0, 0x5, 0x66, 0x34, 0x2, 0x1ce, 0x1d0, 0x5, 0x66, 0x34, 
    0x2, 0x1cf, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1ce, 0x3, 0x2, 0x2, 
    0x2, 0x1d0, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d3, 0x5, 0x68, 0x35, 
    0x2, 0x1d2, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d6, 0x3, 0x2, 0x2, 
    0x2, 0x1d4, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d5, 0x3, 0x2, 0x2, 
    0x2, 0x1d5, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d4, 0x3, 0x2, 0x2, 0x2, 
    0x1d7, 0x1d8, 0x7, 0x48, 0x2, 0x2, 0x1d8, 0x67, 0x3, 0x2, 0x2, 0x2, 
    0x1d9, 0x1da, 0x7, 0x62, 0x2, 0x2, 0x1da, 0x1df, 0x5, 0x6a, 0x36, 0x2, 
    0x1db, 0x1dc, 0x7, 0x5f, 0x2, 0x2, 0x1dc, 0x1de, 0x5, 0x6a, 0x36, 0x2, 
    0x1dd, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e1, 0x3, 0x2, 0x2, 0x2, 
    0x1df, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x3, 0x2, 0x2, 0x2, 
    0x1e0, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1df, 0x3, 0x2, 0x2, 0x2, 
    0x1e2, 0x1e3, 0x7, 0x63, 0x2, 0x2, 0x1e3, 0x1f3, 0x3, 0x2, 0x2, 0x2, 
    0x1e4, 0x1e5, 0x7, 0x39, 0x2, 0x2, 0x1e5, 0x1ea, 0x5, 0x6a, 0x36, 0x2, 
    0x1e6, 0x1e7, 0x7, 0x5f, 0x2, 0x2, 0x1e7, 0x1e9, 0x5, 0x6a, 0x36, 0x2, 
    0x1e8, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ec, 0x3, 0x2, 0x2, 0x2, 
    0x1ea, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 0x2, 0x2, 0x2, 
    0x1eb, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ea, 0x3, 0x2, 0x2, 0x2, 
    0x1ed, 0x1ee, 0x7, 0x3a, 0x2, 0x2, 0x1ee, 0x1f3, 0x3, 0x2, 0x2, 0x2, 
    0x1ef, 0x1f0, 0x7, 0x3c, 0x2, 0x2, 0x1f0, 0x1f3, 0x5, 0x6, 0x4, 0x2, 
    0x1f1, 0x1f3, 0x7, 0x5d, 0x2, 0x2, 0x1f2, 0x1d9, 0x3, 0x2, 0x2, 0x2, 
    0x1f2, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1ef, 0x3, 0x2, 0x2, 0x2, 
    0x1f2, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1f4, 
    0x1fa, 0x5, 0x6e, 0x38, 0x2, 0x1f5, 0x1f6, 0x5, 0x6c, 0x37, 0x2, 0x1f6, 
    0x1f7, 0x5, 0x6a, 0x36, 0x2, 0x1f7, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1f8, 
    0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fa, 
    0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fb, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 
    0x9, 0x5, 0x2, 0x2, 0x1fe, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x205, 0x5, 
    0x72, 0x3a, 0x2, 0x200, 0x201, 0x5, 0x70, 0x39, 0x2, 0x201, 0x202, 0x5, 
    0x6e, 0x38, 0x2, 0x202, 0x204, 0x3, 0x2, 0x2, 0x2, 0x203, 0x200, 0x3, 
    0x2, 0x2, 0x2, 0x204, 0x207, 0x3, 0x2, 0x2, 0x2, 0x205, 0x203, 0x3, 
    0x2, 0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x207, 0x205, 0x3, 0x2, 0x2, 0x2, 0x208, 0x209, 0x9, 0x6, 
    0x2, 0x2, 0x209, 0x71, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x210, 0x5, 0x76, 
    0x3c, 0x2, 0x20b, 0x20c, 0x5, 0x74, 0x3b, 0x2, 0x20c, 0x20d, 0x5, 0x72, 
    0x3a, 0x2, 0x20d, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20b, 0x3, 0x2, 
    0x2, 0x2, 0x20f, 0x212, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20e, 0x3, 0x2, 
    0x2, 0x2, 0x210, 0x211, 0x3, 0x2, 0x2, 0x2, 0x211, 0x73, 0x3, 0x2, 0x2, 
    0x2, 0x212, 0x210, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x9, 0x7, 0x2, 
    0x2, 0x214, 0x75, 0x3, 0x2, 0x2, 0x2, 0x215, 0x217, 0x9, 0x2, 0x2, 0x2, 
    0x216, 0x215, 0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x3, 0x2, 0x2, 0x2, 
    0x217, 0x218, 0x3, 0x2, 0x2, 0x2, 0x218, 0x219, 0x5, 0x78, 0x3d, 0x2, 
    0x219, 0x77, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x226, 0x5, 0x64, 0x33, 0x2, 
    0x21b, 0x21c, 0x7, 0x60, 0x2, 0x2, 0x21c, 0x21d, 0x5, 0x6a, 0x36, 0x2, 
    0x21d, 0x21e, 0x7, 0x61, 0x2, 0x2, 0x21e, 0x226, 0x3, 0x2, 0x2, 0x2, 
    0x21f, 0x226, 0x5, 0x7c, 0x3f, 0x2, 0x220, 0x226, 0x5, 0x7a, 0x3e, 0x2, 
    0x221, 0x226, 0x5, 0x84, 0x43, 0x2, 0x222, 0x223, 0x7, 0x23, 0x2, 0x2, 
    0x223, 0x226, 0x5, 0x78, 0x3d, 0x2, 0x224, 0x226, 0x5, 0x4a, 0x26, 0x2, 
    0x225, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x225, 0x21b, 0x3, 0x2, 0x2, 0x2, 
    0x225, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x225, 0x220, 0x3, 0x2, 0x2, 0x2, 
    0x225, 0x221, 0x3, 0x2, 0x2, 0x2, 0x225, 0x222, 0x3, 0x2, 0x2, 0x2, 
    0x225, 0x224, 0x3, 0x2, 0x2, 0x2, 0x226, 0x79, 0x3, 0x2, 0x2, 0x2, 0x227, 
    0x22c, 0x5, 0x42, 0x22, 0x2, 0x228, 0x22c, 0x5, 0x3e, 0x20, 0x2, 0x229, 
    0x22c, 0x5, 0x4e, 0x28, 0x2, 0x22a, 0x22c, 0x7, 0x1f, 0x2, 0x2, 0x22b, 
    0x227, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x228, 0x3, 0x2, 0x2, 0x2, 0x22b, 
    0x229, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22c, 
    0x7b, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 0x5, 0x6, 0x4, 0x2, 0x22e, 0x22f, 
    0x7, 0x60, 0x2, 0x2, 0x22f, 0x230, 0x5, 0x7e, 0x40, 0x2, 0x230, 0x231, 
    0x7, 0x61, 0x2, 0x2, 0x231, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x232, 0x237, 
    0x5, 0x80, 0x41, 0x2, 0x233, 0x234, 0x7, 0x5f, 0x2, 0x2, 0x234, 0x236, 
    0x5, 0x80, 0x41, 0x2, 0x235, 0x233, 0x3, 0x2, 0x2, 0x2, 0x236, 0x239, 
    0x3, 0x2, 0x2, 0x2, 0x237, 0x235, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 
    0x3, 0x2, 0x2, 0x2, 0x238, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x239, 0x237, 0x3, 
    0x2, 0x2, 0x2, 0x23a, 0x23e, 0x5, 0x6a, 0x36, 0x2, 0x23b, 0x23d, 0x5, 
    0x82, 0x42, 0x2, 0x23c, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x240, 0x3, 
    0x2, 0x2, 0x2, 0x23e, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 0x3, 
    0x2, 0x2, 0x2, 0x23f, 0x81, 0x3, 0x2, 0x2, 0x2, 0x240, 0x23e, 0x3, 0x2, 
    0x2, 0x2, 0x241, 0x242, 0x7, 0x37, 0x2, 0x2, 0x242, 0x243, 0x5, 0x6a, 
    0x36, 0x2, 0x243, 0x83, 0x3, 0x2, 0x2, 0x2, 0x244, 0x245, 0x7, 0x62, 
    0x2, 0x2, 0x245, 0x24a, 0x5, 0x86, 0x44, 0x2, 0x246, 0x247, 0x7, 0x5f, 
    0x2, 0x2, 0x247, 0x249, 0x5, 0x86, 0x44, 0x2, 0x248, 0x246, 0x3, 0x2, 
    0x2, 0x2, 0x249, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x248, 0x3, 0x2, 
    0x2, 0x2, 0x24a, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24d, 0x3, 0x2, 
    0x2, 0x2, 0x24c, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 0x7, 0x63, 
    0x2, 0x2, 0x24e, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 0x7, 0x39, 
    0x2, 0x2, 0x250, 0x255, 0x5, 0x86, 0x44, 0x2, 0x251, 0x252, 0x7, 0x5f, 
    0x2, 0x2, 0x252, 0x254, 0x5, 0x86, 0x44, 0x2, 0x253, 0x251, 0x3, 0x2, 
    0x2, 0x2, 0x254, 0x257, 0x3, 0x2, 0x2, 0x2, 0x255, 0x253, 0x3, 0x2, 
    0x2, 0x2, 0x255, 0x256, 0x3, 0x2, 0x2, 0x2, 0x256, 0x258, 0x3, 0x2, 
    0x2, 0x2, 0x257, 0x255, 0x3, 0x2, 0x2, 0x2, 0x258, 0x259, 0x7, 0x3a, 
    0x2, 0x2, 0x259, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x244, 0x3, 0x2, 
    0x2, 0x2, 0x25a, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x25c, 0x25f, 0x5, 0x6a, 0x36, 0x2, 0x25d, 0x25e, 0x7, 0x3d, 0x2, 
    0x2, 0x25e, 0x260, 0x5, 0x6a, 0x36, 0x2, 0x25f, 0x25d, 0x3, 0x2, 0x2, 
    0x2, 0x25f, 0x260, 0x3, 0x2, 0x2, 0x2, 0x260, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x261, 0x262, 0x7, 0x18, 0x2, 0x2, 0x262, 0x263, 0x5, 0x3a, 0x1e, 0x2, 
    0x263, 0x89, 0x3, 0x2, 0x2, 0x2, 0x264, 0x26c, 0x5, 0x96, 0x4c, 0x2, 
    0x265, 0x26c, 0x5, 0x8c, 0x47, 0x2, 0x266, 0x26c, 0x5, 0x9a, 0x4e, 0x2, 
    0x267, 0x26c, 0x5, 0x9c, 0x4f, 0x2, 0x268, 0x26c, 0x5, 0xa6, 0x54, 0x2, 
    0x269, 0x26c, 0x5, 0x92, 0x4a, 0x2, 0x26a, 0x26c, 0x5, 0x94, 0x4b, 0x2, 
    0x26b, 0x264, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x265, 0x3, 0x2, 0x2, 0x2, 
    0x26b, 0x266, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x267, 0x3, 0x2, 0x2, 0x2, 
    0x26b, 0x268, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x269, 0x3, 0x2, 0x2, 0x2, 
    0x26b, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x26d, 
    0x271, 0x5, 0xa0, 0x51, 0x2, 0x26e, 0x271, 0x5, 0xa2, 0x52, 0x2, 0x26f, 
    0x271, 0x5, 0xa4, 0x53, 0x2, 0x270, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x270, 
    0x26e, 0x3, 0x2, 0x2, 0x2, 0x270, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x271, 
    0x8d, 0x3, 0x2, 0x2, 0x2, 0x272, 0x275, 0x5, 0x90, 0x49, 0x2, 0x273, 
    0x274, 0x7, 0x5f, 0x2, 0x2, 0x274, 0x276, 0x5, 0x90, 0x49, 0x2, 0x275, 
    0x273, 0x3, 0x2, 0x2, 0x2, 0x275, 0x276, 0x3, 0x2, 0x2, 0x2, 0x276, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 0x5, 0x6a, 0x36, 0x2, 0x278, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27a, 0x7, 0x21, 0x2, 0x2, 0x27a, 
    0x27b, 0x7, 0x60, 0x2, 0x2, 0x27b, 0x27c, 0x5, 0x8e, 0x48, 0x2, 0x27c, 
    0x27d, 0x7, 0x61, 0x2, 0x2, 0x27d, 0x93, 0x3, 0x2, 0x2, 0x2, 0x27e, 
    0x27f, 0x7, 0x22, 0x2, 0x2, 0x27f, 0x280, 0x7, 0x60, 0x2, 0x2, 0x280, 
    0x281, 0x5, 0x8e, 0x48, 0x2, 0x281, 0x282, 0x7, 0x61, 0x2, 0x2, 0x282, 
    0x95, 0x3, 0x2, 0x2, 0x2, 0x283, 0x284, 0x7, 0x6, 0x2, 0x2, 0x284, 0x285, 
    0x5, 0x98, 0x4d, 0x2, 0x285, 0x286, 0x7, 0x14, 0x2, 0x2, 0x286, 0x97, 
    0x3, 0x2, 0x2, 0x2, 0x287, 0x28c, 0x5, 0x58, 0x2d, 0x2, 0x288, 0x289, 
    0x7, 0x5e, 0x2, 0x2, 0x289, 0x28b, 0x5, 0x58, 0x2d, 0x2, 0x28a, 0x288, 
    0x3, 0x2, 0x2, 0x2, 0x28b, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28a, 
    0x3, 0x2, 0x2, 0x2, 0x28c, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x99, 0x3, 
    0x2, 0x2, 0x2, 0x28e, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x290, 0x7, 
    0x19, 0x2, 0x2, 0x290, 0x291, 0x5, 0x6a, 0x36, 0x2, 0x291, 0x292, 0x7, 
    0x2f, 0x2, 0x2, 0x292, 0x295, 0x5, 0x58, 0x2d, 0x2, 0x293, 0x294, 0x7, 
    0x13, 0x2, 0x2, 0x294, 0x296, 0x5, 0x58, 0x2d, 0x2, 0x295, 0x293, 0x3, 
    0x2, 0x2, 0x2, 0x295, 0x296, 0x3, 0x2, 0x2, 0x2, 0x296, 0x9b, 0x3, 0x2, 
    0x2, 0x2, 0x297, 0x298, 0x7, 0x9, 0x2, 0x2, 0x298, 0x299, 0x5, 0x6a, 
    0x36, 0x2, 0x299, 0x29a, 0x7, 0x24, 0x2, 0x2, 0x29a, 0x29f, 0x5, 0x9e, 
    0x50, 0x2, 0x29b, 0x29c, 0x7, 0x5e, 0x2, 0x2, 0x29c, 0x29e, 0x5, 0x9e, 
    0x50, 0x2, 0x29d, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x2a1, 0x3, 0x2, 
    0x2, 0x2, 0x29f, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x2a0, 0x3, 0x2, 
    0x2, 0x2, 0x2a0, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x29f, 0x3, 0x2, 
    0x2, 0x2, 0x2a2, 0x2a3, 0x7, 0x5e, 0x2, 0x2, 0x2a3, 0x2a4, 0x7, 0x13, 
    0x2, 0x2, 0x2a4, 0x2a6, 0x5, 0x98, 0x4d, 0x2, 0x2a5, 0x2a2, 0x3, 0x2, 
    0x2, 0x2, 0x2a5, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a7, 0x3, 0x2, 
    0x2, 0x2, 0x2a7, 0x2a8, 0x7, 0x14, 0x2, 0x2, 0x2a8, 0x9d, 0x3, 0x2, 
    0x2, 0x2, 0x2a9, 0x2ae, 0x5, 0x40, 0x21, 0x2, 0x2aa, 0x2ab, 0x7, 0x5f, 
    0x2, 0x2, 0x2ab, 0x2ad, 0x5, 0x40, 0x21, 0x2, 0x2ac, 0x2aa, 0x3, 0x2, 
    0x2, 0x2, 0x2ad, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2ac, 0x3, 0x2, 
    0x2, 0x2, 0x2ae, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b1, 0x3, 0x2, 
    0x2, 0x2, 0x2b0, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b2, 0x7, 0x37, 
    0x2, 0x2, 0x2b2, 0x2b3, 0x5, 0x58, 0x2d, 0x2, 0x2b3, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0x2b4, 0x2b5, 0x7, 0x34, 0x2, 0x2, 0x2b5, 0x2b6, 0x5, 0x6a, 
    0x36, 0x2, 0x2b6, 0x2b7, 0x7, 0x11, 0x2, 0x2, 0x2b7, 0x2b8, 0x5, 0x58, 
    0x2d, 0x2, 0x2b8, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2ba, 0x7, 0x2d, 
    0x2, 0x2, 0x2ba, 0x2bb, 0x5, 0x98, 0x4d, 0x2, 0x2bb, 0x2bc, 0x7, 0x32, 
    0x2, 0x2, 0x2bc, 0x2bd, 0x5, 0x6a, 0x36, 0x2, 0x2bd, 0xa3, 0x3, 0x2, 
    0x2, 0x2, 0x2be, 0x2bf, 0x7, 0x16, 0x2, 0x2, 0x2bf, 0x2c0, 0x5, 0x62, 
    0x32, 0x2, 0x2c0, 0x2c1, 0x9, 0x8, 0x2, 0x2, 0x2c1, 0x2c2, 0x5, 0x6a, 
    0x36, 0x2, 0x2c2, 0x2c3, 0x7, 0x11, 0x2, 0x2, 0x2c3, 0x2c4, 0x5, 0x58, 
    0x2d, 0x2, 0x2c4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x7, 0x35, 
    0x2, 0x2, 0x2c6, 0x2cb, 0x5, 0x64, 0x33, 0x2, 0x2c7, 0x2c8, 0x7, 0x5f, 
    0x2, 0x2, 0x2c8, 0x2ca, 0x5, 0x64, 0x33, 0x2, 0x2c9, 0x2c7, 0x3, 0x2, 
    0x2, 0x2, 0x2ca, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2c9, 0x3, 0x2, 
    0x2, 0x2, 0x2cb, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2ce, 0x3, 0x2, 
    0x2, 0x2, 0x2cd, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cf, 0x7, 0x11, 
    0x2, 0x2, 0x2cf, 0x2d0, 0x5, 0x58, 0x2d, 0x2, 0x2d0, 0xa7, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0xb3, 0xbb, 0xc6, 0xc8, 0xd7, 0xe2, 0xf0, 0xf7, 0xff, 
    0x10b, 0x113, 0x11a, 0x122, 0x130, 0x135, 0x13d, 0x147, 0x14c, 0x15e, 
    0x165, 0x180, 0x184, 0x190, 0x197, 0x1a1, 0x1aa, 0x1b3, 0x1b7, 0x1bd, 
    0x1c4, 0x1cf, 0x1d4, 0x1df, 0x1ea, 0x1f2, 0x1fa, 0x205, 0x210, 0x216, 
    0x225, 0x22b, 0x237, 0x23e, 0x24a, 0x255, 0x25a, 0x25f, 0x26b, 0x270, 
    0x275, 0x28c, 0x295, 0x29f, 0x2a5, 0x2ae, 0x2cb, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PascalParser::Initializer PascalParser::_init;
