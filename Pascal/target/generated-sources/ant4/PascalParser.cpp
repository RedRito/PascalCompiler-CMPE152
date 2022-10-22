
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

PascalParser::CompoundStatementContext* PascalParser::ProgramContext::compoundStatement() {
  return getRuleContext<PascalParser::CompoundStatementContext>(0);
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
    setState(98);
    programHead();
    setState(99);
    compoundStatement();
    setState(100);
    match(PascalParser::DOT);
    setState(101);
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
    setState(117);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::PROGRAM: {
        enterOuterAlt(_localctx, 1);
        setState(103);
        match(PascalParser::PROGRAM);
        setState(104);
        identifier();
        setState(109);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PascalParser::LPAREN) {
          setState(105);
          match(PascalParser::LPAREN);
          setState(106);
          identifierList();
          setState(107);
          match(PascalParser::RPAREN);
        }
        setState(111);
        match(PascalParser::SEMICOLON);
        break;
      }

      case PascalParser::UNIT: {
        enterOuterAlt(_localctx, 2);
        setState(113);
        match(PascalParser::UNIT);
        setState(114);
        identifier();
        setState(115);
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
    setState(119);
    match(PascalParser::IDENT);
   
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
  enterRule(_localctx, 6, PascalParser::RuleLabel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
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
  enterRule(_localctx, 8, PascalParser::RuleConstantVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    identifier();
    setState(124);
    match(PascalParser::EQUAL);
    setState(125);
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
  enterRule(_localctx, 10, PascalParser::RuleConstantChr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(PascalParser::CHR);
    setState(128);
    match(PascalParser::LPAREN);
    setState(129);
    unsignedInteger();
    setState(130);
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
  enterRule(_localctx, 12, PascalParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(142);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(132);
      unsignedNumber();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(133);
      sign();
      setState(134);
      unsignedNumber();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(136);
      identifier();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(137);
      sign();
      setState(138);
      identifier();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(140);
      string();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(141);
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
  enterRule(_localctx, 14, PascalParser::RuleUnsignedNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(146);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::NUM_INT: {
        enterOuterAlt(_localctx, 1);
        setState(144);
        unsignedInteger();
        break;
      }

      case PascalParser::NUM_REAL: {
        enterOuterAlt(_localctx, 2);
        setState(145);
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
  enterRule(_localctx, 16, PascalParser::RuleUnsignedInteger);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
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
  enterRule(_localctx, 18, PascalParser::RuleUnsignedReal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
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
  enterRule(_localctx, 20, PascalParser::RuleSign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
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
  enterRule(_localctx, 22, PascalParser::RuleBool_);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
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
  enterRule(_localctx, 24, PascalParser::RuleTypeIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(156);
        identifier();
        break;
      }

      case PascalParser::BOOLEAN:
      case PascalParser::CHAR:
      case PascalParser::INTEGER:
      case PascalParser::REAL:
      case PascalParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(157);
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
  enterRule(_localctx, 26, PascalParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
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
  enterRule(_localctx, 28, PascalParser::RuleSimpleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(165);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(162);
      scalarType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(163);
      typeIdentifier();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(164);
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
  enterRule(_localctx, 30, PascalParser::RuleScalarType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    match(PascalParser::LPAREN);
    setState(168);
    identifierList();
    setState(169);
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
  enterRule(_localctx, 32, PascalParser::RuleStringtype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(PascalParser::STRING);
    setState(172);
    match(PascalParser::LBRACKET);
    setState(175);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::IDENT: {
        setState(173);
        identifier();
        break;
      }

      case PascalParser::NUM_INT:
      case PascalParser::NUM_REAL: {
        setState(174);
        unsignedNumber();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(177);
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
  enterRule(_localctx, 34, PascalParser::RuleIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    identifier();
    setState(184);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(180);
      match(PascalParser::COMMA);
      setState(181);
      identifier();
      setState(186);
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
  enterRule(_localctx, 36, PascalParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(192);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::NUM_INT: {
        enterOuterAlt(_localctx, 1);
        setState(187);
        label();
        setState(188);
        match(PascalParser::COLON);
        setState(189);
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
        setState(191);
        unlabelledStatement();
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
  enterRule(_localctx, 38, PascalParser::RuleUnlabelledStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(196);
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
        setState(194);
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
        setState(195);
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
  enterRule(_localctx, 40, PascalParser::RuleSimpleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(201);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::AT:
      case PascalParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(198);
        assignmentStatement();
        break;
      }

      case PascalParser::GOTO: {
        enterOuterAlt(_localctx, 2);
        setState(199);
        gotoStatement();
        break;
      }

      case PascalParser::ELSE:
      case PascalParser::END:
      case PascalParser::UNTIL:
      case PascalParser::SEMICOLON: {
        enterOuterAlt(_localctx, 3);
        setState(200);
        emptyStatement_();
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
  enterRule(_localctx, 42, PascalParser::RuleEmptyStatement_);

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
  enterRule(_localctx, 44, PascalParser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    variable();
    setState(206);
    match(PascalParser::ASSIGN);
    setState(207);
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

std::vector<PascalParser::IdentifierContext *> PascalParser::VariableContext::identifier() {
  return getRuleContexts<PascalParser::IdentifierContext>();
}

PascalParser::IdentifierContext* PascalParser::VariableContext::identifier(size_t i) {
  return getRuleContext<PascalParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> PascalParser::VariableContext::LBRACKET() {
  return getTokens(PascalParser::LBRACKET);
}

tree::TerminalNode* PascalParser::VariableContext::LBRACKET(size_t i) {
  return getToken(PascalParser::LBRACKET, i);
}

std::vector<PascalParser::ExpressionContext *> PascalParser::VariableContext::expression() {
  return getRuleContexts<PascalParser::ExpressionContext>();
}

PascalParser::ExpressionContext* PascalParser::VariableContext::expression(size_t i) {
  return getRuleContext<PascalParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> PascalParser::VariableContext::RBRACKET() {
  return getTokens(PascalParser::RBRACKET);
}

tree::TerminalNode* PascalParser::VariableContext::RBRACKET(size_t i) {
  return getToken(PascalParser::RBRACKET, i);
}

std::vector<tree::TerminalNode *> PascalParser::VariableContext::LBRACKET2() {
  return getTokens(PascalParser::LBRACKET2);
}

tree::TerminalNode* PascalParser::VariableContext::LBRACKET2(size_t i) {
  return getToken(PascalParser::LBRACKET2, i);
}

std::vector<tree::TerminalNode *> PascalParser::VariableContext::RBRACKET2() {
  return getTokens(PascalParser::RBRACKET2);
}

tree::TerminalNode* PascalParser::VariableContext::RBRACKET2(size_t i) {
  return getToken(PascalParser::RBRACKET2, i);
}

std::vector<tree::TerminalNode *> PascalParser::VariableContext::DOT() {
  return getTokens(PascalParser::DOT);
}

tree::TerminalNode* PascalParser::VariableContext::DOT(size_t i) {
  return getToken(PascalParser::DOT, i);
}

std::vector<tree::TerminalNode *> PascalParser::VariableContext::CARAT() {
  return getTokens(PascalParser::CARAT);
}

tree::TerminalNode* PascalParser::VariableContext::CARAT(size_t i) {
  return getToken(PascalParser::CARAT, i);
}

std::vector<tree::TerminalNode *> PascalParser::VariableContext::COMMA() {
  return getTokens(PascalParser::COMMA);
}

tree::TerminalNode* PascalParser::VariableContext::COMMA(size_t i) {
  return getToken(PascalParser::COMMA, i);
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
  enterRule(_localctx, 46, PascalParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::AT: {
        setState(209);
        match(PascalParser::AT);
        setState(210);
        identifier();
        break;
      }

      case PascalParser::IDENT: {
        setState(211);
        identifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(241);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 55) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 55)) & ((1ULL << (PascalParser::LBRACKET2 - 55))
      | (1ULL << (PascalParser::DOT - 55))
      | (1ULL << (PascalParser::CARAT - 55))
      | (1ULL << (PascalParser::LBRACKET - 55)))) != 0)) {
      setState(239);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PascalParser::LBRACKET: {
          setState(214);
          match(PascalParser::LBRACKET);
          setState(215);
          expression();
          setState(220);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PascalParser::COMMA) {
            setState(216);
            match(PascalParser::COMMA);
            setState(217);
            expression();
            setState(222);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(223);
          match(PascalParser::RBRACKET);
          break;
        }

        case PascalParser::LBRACKET2: {
          setState(225);
          match(PascalParser::LBRACKET2);
          setState(226);
          expression();
          setState(231);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PascalParser::COMMA) {
            setState(227);
            match(PascalParser::COMMA);
            setState(228);
            expression();
            setState(233);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(234);
          match(PascalParser::RBRACKET2);
          break;
        }

        case PascalParser::DOT: {
          setState(236);
          match(PascalParser::DOT);
          setState(237);
          identifier();
          break;
        }

        case PascalParser::CARAT: {
          setState(238);
          match(PascalParser::CARAT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(243);
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

//----------------- ExpressionContext ------------------------------------------------------------------

PascalParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::SimpleExpressionContext* PascalParser::ExpressionContext::simpleExpression() {
  return getRuleContext<PascalParser::SimpleExpressionContext>(0);
}

PascalParser::RelationaloperatorContext* PascalParser::ExpressionContext::relationaloperator() {
  return getRuleContext<PascalParser::RelationaloperatorContext>(0);
}

PascalParser::ExpressionContext* PascalParser::ExpressionContext::expression() {
  return getRuleContext<PascalParser::ExpressionContext>(0);
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
  enterRule(_localctx, 48, PascalParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    simpleExpression();
    setState(248);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 24) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 24)) & ((1ULL << (PascalParser::IN - 24))
      | (1ULL << (PascalParser::EQUAL - 24))
      | (1ULL << (PascalParser::NE - 24))
      | (1ULL << (PascalParser::LTEQ - 24))
      | (1ULL << (PascalParser::GTEQ - 24))
      | (1ULL << (PascalParser::LT - 24))
      | (1ULL << (PascalParser::GT - 24)))) != 0)) {
      setState(245);
      relationaloperator();
      setState(246);
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
  enterRule(_localctx, 50, PascalParser::RuleRelationaloperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
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

PascalParser::AdditiveoperatorContext* PascalParser::SimpleExpressionContext::additiveoperator() {
  return getRuleContext<PascalParser::AdditiveoperatorContext>(0);
}

PascalParser::SimpleExpressionContext* PascalParser::SimpleExpressionContext::simpleExpression() {
  return getRuleContext<PascalParser::SimpleExpressionContext>(0);
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
  enterRule(_localctx, 52, PascalParser::RuleSimpleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    term();
    setState(256);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 37) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 37)) & ((1ULL << (PascalParser::OR - 37))
      | (1ULL << (PascalParser::PLUSOP - 37))
      | (1ULL << (PascalParser::MINUSOP - 37)))) != 0)) {
      setState(253);
      additiveoperator();
      setState(254);
      simpleExpression();
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
  enterRule(_localctx, 54, PascalParser::RuleAdditiveoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
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

PascalParser::MultiplicativeoperatorContext* PascalParser::TermContext::multiplicativeoperator() {
  return getRuleContext<PascalParser::MultiplicativeoperatorContext>(0);
}

PascalParser::TermContext* PascalParser::TermContext::term() {
  return getRuleContext<PascalParser::TermContext>(0);
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
  enterRule(_localctx, 56, PascalParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    signedFactor();
    setState(264);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::AND)
      | (1ULL << PascalParser::DIV)
      | (1ULL << PascalParser::MOD))) != 0) || _la == PascalParser::MULTOP

    || _la == PascalParser::DIVOP) {
      setState(261);
      multiplicativeoperator();
      setState(262);
      term();
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
  enterRule(_localctx, 58, PascalParser::RuleMultiplicativeoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
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
  enterRule(_localctx, 60, PascalParser::RuleSignedFactor);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::PLUSOP

    || _la == PascalParser::MINUSOP) {
      setState(268);
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
    setState(271);
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

PascalParser::UnsignedConstantContext* PascalParser::FactorContext::unsignedConstant() {
  return getRuleContext<PascalParser::UnsignedConstantContext>(0);
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
  enterRule(_localctx, 62, PascalParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(282);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::AT:
      case PascalParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(273);
        variable();
        break;
      }

      case PascalParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(274);
        match(PascalParser::LPAREN);
        setState(275);
        expression();
        setState(276);
        match(PascalParser::RPAREN);
        break;
      }

      case PascalParser::CHR:
      case PascalParser::NIL:
      case PascalParser::STRING_LITERAL:
      case PascalParser::NUM_INT:
      case PascalParser::NUM_REAL: {
        enterOuterAlt(_localctx, 3);
        setState(278);
        unsignedConstant();
        break;
      }

      case PascalParser::NOT: {
        enterOuterAlt(_localctx, 4);
        setState(279);
        match(PascalParser::NOT);
        setState(280);
        factor();
        break;
      }

      case PascalParser::TRUE:
      case PascalParser::FALSE: {
        enterOuterAlt(_localctx, 5);
        setState(281);
        bool_();
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
  enterRule(_localctx, 64, PascalParser::RuleUnsignedConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(288);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::NUM_INT:
      case PascalParser::NUM_REAL: {
        enterOuterAlt(_localctx, 1);
        setState(284);
        unsignedNumber();
        break;
      }

      case PascalParser::CHR: {
        enterOuterAlt(_localctx, 2);
        setState(285);
        constantChr();
        break;
      }

      case PascalParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(286);
        string();
        break;
      }

      case PascalParser::NIL: {
        enterOuterAlt(_localctx, 4);
        setState(287);
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
  enterRule(_localctx, 66, PascalParser::RuleGotoStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    match(PascalParser::GOTO);
    setState(291);
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
  enterRule(_localctx, 68, PascalParser::RuleStructuredStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(300);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::BEGIN: {
        enterOuterAlt(_localctx, 1);
        setState(293);
        compoundStatement();
        break;
      }

      case PascalParser::FOR:
      case PascalParser::REPEAT:
      case PascalParser::WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(294);
        reptitiveStatement();
        break;
      }

      case PascalParser::IF: {
        enterOuterAlt(_localctx, 3);
        setState(295);
        ifStatement();
        break;
      }

      case PascalParser::CASE: {
        enterOuterAlt(_localctx, 4);
        setState(296);
        caseStatement();
        break;
      }

      case PascalParser::WITH: {
        enterOuterAlt(_localctx, 5);
        setState(297);
        withStatement();
        break;
      }

      case PascalParser::WRITE: {
        enterOuterAlt(_localctx, 6);
        setState(298);
        writeStatement();
        break;
      }

      case PascalParser::WRITELN: {
        enterOuterAlt(_localctx, 7);
        setState(299);
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
  enterRule(_localctx, 70, PascalParser::RuleReptitiveStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::WHILE: {
        enterOuterAlt(_localctx, 1);
        setState(302);
        whileStatement();
        break;
      }

      case PascalParser::REPEAT: {
        enterOuterAlt(_localctx, 2);
        setState(303);
        repeatStatement();
        break;
      }

      case PascalParser::FOR: {
        enterOuterAlt(_localctx, 3);
        setState(304);
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
  enterRule(_localctx, 72, PascalParser::RuleWriteArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(307);
    writeArgs();
    setState(310);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::COMMA) {
      setState(308);
      match(PascalParser::COMMA);
      setState(309);
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
  enterRule(_localctx, 74, PascalParser::RuleWriteArgs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
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
  enterRule(_localctx, 76, PascalParser::RuleWriteStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    match(PascalParser::WRITE);
    setState(315);
    match(PascalParser::LPAREN);
    setState(316);
    writeArguments();
    setState(317);
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
  enterRule(_localctx, 78, PascalParser::RuleWritelnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    match(PascalParser::WRITELN);
    setState(320);
    match(PascalParser::LPAREN);
    setState(321);
    writeArguments();
    setState(322);
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
  enterRule(_localctx, 80, PascalParser::RuleCompoundStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    match(PascalParser::BEGIN);
    setState(325);
    statements();
    setState(326);
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
  enterRule(_localctx, 82, PascalParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    statement();
    setState(333);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::SEMICOLON) {
      setState(329);
      match(PascalParser::SEMICOLON);
      setState(330);
      statement();
      setState(335);
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
  enterRule(_localctx, 84, PascalParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    match(PascalParser::IF);
    setState(337);
    expression();
    setState(338);
    match(PascalParser::THEN);
    setState(339);
    statement();
    setState(342);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(340);
      match(PascalParser::ELSE);
      setState(341);
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
  enterRule(_localctx, 86, PascalParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(344);
    match(PascalParser::CASE);
    setState(345);
    expression();
    setState(346);
    match(PascalParser::OF);
    setState(347);
    caseListElement();
    setState(352);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(348);
        match(PascalParser::SEMICOLON);
        setState(349);
        caseListElement(); 
      }
      setState(354);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
    setState(358);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::SEMICOLON) {
      setState(355);
      match(PascalParser::SEMICOLON);
      setState(356);
      match(PascalParser::ELSE);
      setState(357);
      statements();
    }
    setState(360);
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
  enterRule(_localctx, 88, PascalParser::RuleCaseListElement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    constant();
    setState(367);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(363);
      match(PascalParser::COMMA);
      setState(364);
      constant();
      setState(369);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(370);
    match(PascalParser::COLON);
    setState(371);
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
  enterRule(_localctx, 90, PascalParser::RuleWhileStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    match(PascalParser::WHILE);
    setState(374);
    expression();
    setState(375);
    match(PascalParser::DO);
    setState(376);
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
  enterRule(_localctx, 92, PascalParser::RuleRepeatStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(378);
    match(PascalParser::REPEAT);
    setState(379);
    statements();
    setState(380);
    match(PascalParser::UNTIL);
    setState(381);
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
  enterRule(_localctx, 94, PascalParser::RuleForStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(383);
    match(PascalParser::FOR);
    setState(384);
    assignmentStatement();
    setState(385);
    _la = _input->LA(1);
    if (!(_la == PascalParser::DOWNTO

    || _la == PascalParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(386);
    expression();
    setState(387);
    match(PascalParser::DO);
    setState(388);
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
  enterRule(_localctx, 96, PascalParser::RuleWithStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    match(PascalParser::WITH);
    setState(391);
    variable();
    setState(396);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(392);
      match(PascalParser::COMMA);
      setState(393);
      variable();
      setState(398);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(399);
    match(PascalParser::DO);
    setState(400);
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
  "program", "programHead", "identifier", "label", "constantVar", "constantChr", 
  "constant", "unsignedNumber", "unsignedInteger", "unsignedReal", "sign", 
  "bool_", "typeIdentifier", "string", "simpleType", "scalarType", "stringtype", 
  "identifierList", "statement", "unlabelledStatement", "simpleStatement", 
  "emptyStatement_", "assignmentStatement", "variable", "expression", "relationaloperator", 
  "simpleExpression", "additiveoperator", "term", "multiplicativeoperator", 
  "signedFactor", "factor", "unsignedConstant", "gotoStatement", "structuredStatement", 
  "reptitiveStatement", "writeArguments", "writeArgs", "writeStatement", 
  "writelnStatement", "compoundStatement", "statements", "ifStatement", 
  "caseStatement", "caseListElement", "whileStatement", "repeatStatement", 
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
    0x3, 0x67, 0x195, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x32, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x70, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x78, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x91, 0xa, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0x95, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 
    0xe, 0xa1, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x5, 0x10, 0xa8, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xb2, 0xa, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 
    0xb9, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0xbc, 0xb, 0x13, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xc3, 0xa, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x5, 0x15, 0xc7, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x5, 0x16, 0xcc, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 
    0xd7, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 
    0xdd, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0xe0, 0xb, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0xe8, 0xa, 
    0x19, 0xc, 0x19, 0xe, 0x19, 0xeb, 0xb, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0xf2, 0xa, 0x19, 0xc, 0x19, 0xe, 
    0x19, 0xf5, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 
    0x1a, 0xfb, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x103, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x10b, 0xa, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x5, 0x20, 0x110, 0xa, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x11d, 0xa, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x123, 0xa, 0x22, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x12f, 0xa, 0x24, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x134, 0xa, 0x25, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x139, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x14e, 0xa, 0x2b, 
    0xc, 0x2b, 0xe, 0x2b, 0x151, 0xb, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x159, 0xa, 0x2c, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x161, 
    0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x164, 0xb, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x5, 0x2d, 0x169, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x170, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 
    0x173, 0xb, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
    0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 
    0x32, 0x18d, 0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 0x190, 0xb, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x2, 0x2, 0x33, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
    0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x2, 0x9, 
    0x3, 0x2, 0x50, 0x51, 0x3, 0x2, 0x43, 0x44, 0x7, 0x2, 0x8, 0x8, 0xa, 
    0xa, 0x1c, 0x1c, 0x2b, 0x2b, 0x41, 0x41, 0x5, 0x2, 0x1a, 0x1a, 0x38, 
    0x38, 0x54, 0x58, 0x4, 0x2, 0x27, 0x27, 0x50, 0x51, 0x6, 0x2, 0x3, 0x3, 
    0x10, 0x10, 0x1e, 0x1e, 0x52, 0x53, 0x4, 0x2, 0x12, 0x12, 0x30, 0x30, 
    0x2, 0x195, 0x2, 0x64, 0x3, 0x2, 0x2, 0x2, 0x4, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x79, 0x3, 0x2, 0x2, 0x2, 0x8, 0x7b, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x81, 0x3, 0x2, 0x2, 0x2, 0xe, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x94, 0x3, 0x2, 0x2, 0x2, 0x12, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x98, 0x3, 0x2, 0x2, 0x2, 0x16, 0x9a, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x22, 0xad, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0x26, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x28, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xcd, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x30, 0xd6, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x34, 0xfc, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x38, 0x104, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x106, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x10f, 0x3, 0x2, 0x2, 0x2, 0x40, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x42, 0x122, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x124, 0x3, 0x2, 0x2, 0x2, 0x46, 0x12e, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x133, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x135, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x13c, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x141, 0x3, 0x2, 0x2, 0x2, 0x52, 0x146, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x56, 0x152, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x15a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x177, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x60, 0x181, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x188, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x5, 0x4, 
    0x3, 0x2, 0x65, 0x66, 0x5, 0x52, 0x2a, 0x2, 0x66, 0x67, 0x7, 0x3c, 0x2, 
    0x2, 0x67, 0x68, 0x7, 0x2, 0x2, 0x3, 0x68, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x69, 0x6a, 0x7, 0x2a, 0x2, 0x2, 0x6a, 0x6f, 0x5, 0x6, 0x4, 0x2, 0x6b, 
    0x6c, 0x7, 0x60, 0x2, 0x2, 0x6c, 0x6d, 0x5, 0x24, 0x13, 0x2, 0x6d, 0x6e, 
    0x7, 0x61, 0x2, 0x2, 0x6e, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6b, 0x3, 
    0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 
    0x2, 0x2, 0x71, 0x72, 0x7, 0x5e, 0x2, 0x2, 0x72, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x73, 0x74, 0x7, 0x3e, 0x2, 0x2, 0x74, 0x75, 0x5, 0x6, 0x4, 0x2, 
    0x75, 0x76, 0x7, 0x5e, 0x2, 0x2, 0x76, 0x78, 0x3, 0x2, 0x2, 0x2, 0x77, 
    0x69, 0x3, 0x2, 0x2, 0x2, 0x77, 0x73, 0x3, 0x2, 0x2, 0x2, 0x78, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x48, 0x2, 0x2, 0x7a, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x7b, 0x7c, 0x5, 0x12, 0xa, 0x2, 0x7c, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x7d, 0x7e, 0x5, 0x6, 0x4, 0x2, 0x7e, 0x7f, 0x7, 0x38, 0x2, 
    0x2, 0x7f, 0x80, 0x5, 0xe, 0x8, 0x2, 0x80, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x82, 0x7, 0xb, 0x2, 0x2, 0x82, 0x83, 0x7, 0x60, 0x2, 0x2, 0x83, 
    0x84, 0x5, 0x12, 0xa, 0x2, 0x84, 0x85, 0x7, 0x61, 0x2, 0x2, 0x85, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x91, 0x5, 0x10, 0x9, 0x2, 0x87, 0x88, 0x5, 
    0x16, 0xc, 0x2, 0x88, 0x89, 0x5, 0x10, 0x9, 0x2, 0x89, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x91, 0x5, 0x6, 0x4, 0x2, 0x8b, 0x8c, 0x5, 0x16, 0xc, 
    0x2, 0x8c, 0x8d, 0x5, 0x6, 0x4, 0x2, 0x8d, 0x91, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x91, 0x5, 0x1c, 0xf, 0x2, 0x8f, 0x91, 0x5, 0xc, 0x7, 0x2, 0x90, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0x90, 0x87, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x92, 0x95, 0x5, 0x12, 0xa, 0x2, 0x93, 0x95, 0x5, 0x14, 0xb, 
    0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x95, 0x11, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 0x4a, 0x2, 0x2, 0x97, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x7, 0x4b, 0x2, 0x2, 0x99, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x9, 0x2, 0x2, 0x2, 0x9b, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x9c, 0x9d, 0x9, 0x3, 0x2, 0x2, 0x9d, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0xa1, 0x5, 0x6, 0x4, 0x2, 0x9f, 0xa1, 0x9, 0x4, 0x2, 
    0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9f, 0x3, 0x2, 0x2, 0x2, 
    0xa1, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x49, 0x2, 0x2, 0xa3, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa8, 0x5, 0x20, 0x11, 0x2, 0xa5, 0xa8, 
    0x5, 0x1a, 0xe, 0x2, 0xa6, 0xa8, 0x5, 0x22, 0x12, 0x2, 0xa7, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa6, 0x3, 0x2, 
    0x2, 0x2, 0xa8, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x60, 0x2, 
    0x2, 0xaa, 0xab, 0x5, 0x24, 0x13, 0x2, 0xab, 0xac, 0x7, 0x61, 0x2, 0x2, 
    0xac, 0x21, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x7, 0x41, 0x2, 0x2, 0xae, 
    0xb1, 0x7, 0x62, 0x2, 0x2, 0xaf, 0xb2, 0x5, 0x6, 0x4, 0x2, 0xb0, 0xb2, 
    0x5, 0x10, 0x9, 0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb0, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x63, 
    0x2, 0x2, 0xb4, 0x23, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xba, 0x5, 0x6, 0x4, 
    0x2, 0xb6, 0xb7, 0x7, 0x5f, 0x2, 0x2, 0xb7, 0xb9, 0x5, 0x6, 0x4, 0x2, 
    0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xba, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x5, 
    0x8, 0x5, 0x2, 0xbe, 0xbf, 0x7, 0x37, 0x2, 0x2, 0xbf, 0xc0, 0x5, 0x28, 
    0x15, 0x2, 0xc0, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc3, 0x5, 0x28, 0x15, 
    0x2, 0xc2, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xc3, 0x27, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc7, 0x5, 0x2a, 0x16, 0x2, 0xc5, 
    0xc7, 0x5, 0x46, 0x24, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc5, 
    0x3, 0x2, 0x2, 0x2, 0xc7, 0x29, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xcc, 0x5, 
    0x2e, 0x18, 0x2, 0xc9, 0xcc, 0x5, 0x44, 0x23, 0x2, 0xca, 0xcc, 0x5, 
    0x2c, 0x17, 0x2, 0xcb, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 0x2, 0xce, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xd0, 0x5, 0x30, 0x19, 0x2, 0xd0, 0xd1, 0x7, 0x36, 0x2, 0x2, 0xd1, 
    0xd2, 0x5, 0x32, 0x1a, 0x2, 0xd2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 
    0x7, 0x3b, 0x2, 0x2, 0xd4, 0xd7, 0x5, 0x6, 0x4, 0x2, 0xd5, 0xd7, 0x5, 
    0x6, 0x4, 0x2, 0xd6, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd5, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x62, 0x2, 
    0x2, 0xd9, 0xde, 0x5, 0x32, 0x1a, 0x2, 0xda, 0xdb, 0x7, 0x5f, 0x2, 0x2, 
    0xdb, 0xdd, 0x5, 0x32, 0x1a, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdd, 
    0xe0, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 
    0x3, 0x2, 0x2, 0x2, 0xdf, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x63, 0x2, 0x2, 0xe2, 0xf2, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0xe4, 0x7, 0x39, 0x2, 0x2, 0xe4, 0xe9, 0x5, 0x32, 0x1a, 
    0x2, 0xe5, 0xe6, 0x7, 0x5f, 0x2, 0x2, 0xe6, 0xe8, 0x5, 0x32, 0x1a, 0x2, 
    0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe9, 
    0xe7, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 
    0x3a, 0x2, 0x2, 0xed, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 0x3c, 
    0x2, 0x2, 0xef, 0xf2, 0x5, 0x6, 0x4, 0x2, 0xf0, 0xf2, 0x7, 0x5d, 0x2, 
    0x2, 0xf1, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe3, 0x3, 0x2, 0x2, 0x2, 
    0xf1, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 
    0xf5, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 
    0x3, 0x2, 0x2, 0x2, 0xf4, 0x31, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xfa, 0x5, 0x36, 0x1c, 0x2, 0xf7, 0xf8, 0x5, 0x34, 
    0x1b, 0x2, 0xf8, 0xf9, 0x5, 0x32, 0x1a, 0x2, 0xf9, 0xfb, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x3, 0x2, 0x2, 0x2, 
    0xfb, 0x33, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x9, 0x5, 0x2, 0x2, 0xfd, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x102, 0x5, 0x3a, 0x1e, 0x2, 0xff, 0x100, 
    0x5, 0x38, 0x1d, 0x2, 0x100, 0x101, 0x5, 0x36, 0x1c, 0x2, 0x101, 0x103, 
    0x3, 0x2, 0x2, 0x2, 0x102, 0xff, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x3, 
    0x2, 0x2, 0x2, 0x103, 0x37, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x9, 0x6, 
    0x2, 0x2, 0x105, 0x39, 0x3, 0x2, 0x2, 0x2, 0x106, 0x10a, 0x5, 0x3e, 
    0x20, 0x2, 0x107, 0x108, 0x5, 0x3c, 0x1f, 0x2, 0x108, 0x109, 0x5, 0x3a, 
    0x1e, 0x2, 0x109, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x107, 0x3, 0x2, 
    0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x10d, 0x9, 0x7, 0x2, 0x2, 0x10d, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x10e, 0x110, 0x9, 0x2, 0x2, 0x2, 0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 
    0x10f, 0x110, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 0x2, 
    0x111, 0x112, 0x5, 0x40, 0x21, 0x2, 0x112, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x113, 0x11d, 0x5, 0x30, 0x19, 0x2, 0x114, 0x115, 0x7, 0x60, 0x2, 0x2, 
    0x115, 0x116, 0x5, 0x32, 0x1a, 0x2, 0x116, 0x117, 0x7, 0x61, 0x2, 0x2, 
    0x117, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11d, 0x5, 0x42, 0x22, 0x2, 
    0x119, 0x11a, 0x7, 0x23, 0x2, 0x2, 0x11a, 0x11d, 0x5, 0x40, 0x21, 0x2, 
    0x11b, 0x11d, 0x5, 0x18, 0xd, 0x2, 0x11c, 0x113, 0x3, 0x2, 0x2, 0x2, 
    0x11c, 0x114, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x118, 0x3, 0x2, 0x2, 0x2, 
    0x11c, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 
    0x11d, 0x41, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x123, 0x5, 0x10, 0x9, 0x2, 
    0x11f, 0x123, 0x5, 0xc, 0x7, 0x2, 0x120, 0x123, 0x5, 0x1c, 0xf, 0x2, 
    0x121, 0x123, 0x7, 0x1f, 0x2, 0x2, 0x122, 0x11e, 0x3, 0x2, 0x2, 0x2, 
    0x122, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 0x2, 
    0x122, 0x121, 0x3, 0x2, 0x2, 0x2, 0x123, 0x43, 0x3, 0x2, 0x2, 0x2, 0x124, 
    0x125, 0x7, 0x18, 0x2, 0x2, 0x125, 0x126, 0x5, 0x8, 0x5, 0x2, 0x126, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x127, 0x12f, 0x5, 0x52, 0x2a, 0x2, 0x128, 
    0x12f, 0x5, 0x48, 0x25, 0x2, 0x129, 0x12f, 0x5, 0x56, 0x2c, 0x2, 0x12a, 
    0x12f, 0x5, 0x58, 0x2d, 0x2, 0x12b, 0x12f, 0x5, 0x62, 0x32, 0x2, 0x12c, 
    0x12f, 0x5, 0x4e, 0x28, 0x2, 0x12d, 0x12f, 0x5, 0x50, 0x29, 0x2, 0x12e, 
    0x127, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x129, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x12b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x47, 0x3, 0x2, 0x2, 0x2, 0x130, 0x134, 
    0x5, 0x5c, 0x2f, 0x2, 0x131, 0x134, 0x5, 0x5e, 0x30, 0x2, 0x132, 0x134, 
    0x5, 0x60, 0x31, 0x2, 0x133, 0x130, 0x3, 0x2, 0x2, 0x2, 0x133, 0x131, 
    0x3, 0x2, 0x2, 0x2, 0x133, 0x132, 0x3, 0x2, 0x2, 0x2, 0x134, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x135, 0x138, 0x5, 0x4c, 0x27, 0x2, 0x136, 0x137, 0x7, 
    0x5f, 0x2, 0x2, 0x137, 0x139, 0x5, 0x4c, 0x27, 0x2, 0x138, 0x136, 0x3, 
    0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 0x139, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x13a, 0x13b, 0x5, 0x32, 0x1a, 0x2, 0x13b, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x13c, 0x13d, 0x7, 0x21, 0x2, 0x2, 0x13d, 0x13e, 0x7, 0x60, 
    0x2, 0x2, 0x13e, 0x13f, 0x5, 0x4a, 0x26, 0x2, 0x13f, 0x140, 0x7, 0x61, 
    0x2, 0x2, 0x140, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x7, 0x22, 
    0x2, 0x2, 0x142, 0x143, 0x7, 0x60, 0x2, 0x2, 0x143, 0x144, 0x5, 0x4a, 
    0x26, 0x2, 0x144, 0x145, 0x7, 0x61, 0x2, 0x2, 0x145, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x146, 0x147, 0x7, 0x6, 0x2, 0x2, 0x147, 0x148, 0x5, 0x54, 
    0x2b, 0x2, 0x148, 0x149, 0x7, 0x14, 0x2, 0x2, 0x149, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x14a, 0x14f, 0x5, 0x26, 0x14, 0x2, 0x14b, 0x14c, 0x7, 0x5e, 
    0x2, 0x2, 0x14c, 0x14e, 0x5, 0x26, 0x14, 0x2, 0x14d, 0x14b, 0x3, 0x2, 
    0x2, 0x2, 0x14e, 0x151, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x14d, 0x3, 0x2, 
    0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x151, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x7, 0x19, 0x2, 
    0x2, 0x153, 0x154, 0x5, 0x32, 0x1a, 0x2, 0x154, 0x155, 0x7, 0x2f, 0x2, 
    0x2, 0x155, 0x158, 0x5, 0x26, 0x14, 0x2, 0x156, 0x157, 0x7, 0x13, 0x2, 
    0x2, 0x157, 0x159, 0x5, 0x26, 0x14, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 
    0x2, 0x158, 0x159, 0x3, 0x2, 0x2, 0x2, 0x159, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x15a, 0x15b, 0x7, 0x9, 0x2, 0x2, 0x15b, 0x15c, 0x5, 0x32, 0x1a, 0x2, 
    0x15c, 0x15d, 0x7, 0x24, 0x2, 0x2, 0x15d, 0x162, 0x5, 0x5a, 0x2e, 0x2, 
    0x15e, 0x15f, 0x7, 0x5e, 0x2, 0x2, 0x15f, 0x161, 0x5, 0x5a, 0x2e, 0x2, 
    0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x161, 0x164, 0x3, 0x2, 0x2, 0x2, 
    0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x3, 0x2, 0x2, 0x2, 
    0x163, 0x168, 0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 0x3, 0x2, 0x2, 0x2, 
    0x165, 0x166, 0x7, 0x5e, 0x2, 0x2, 0x166, 0x167, 0x7, 0x13, 0x2, 0x2, 
    0x167, 0x169, 0x5, 0x54, 0x2b, 0x2, 0x168, 0x165, 0x3, 0x2, 0x2, 0x2, 
    0x168, 0x169, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 
    0x16a, 0x16b, 0x7, 0x14, 0x2, 0x2, 0x16b, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x16c, 0x171, 0x5, 0xe, 0x8, 0x2, 0x16d, 0x16e, 0x7, 0x5f, 0x2, 0x2, 
    0x16e, 0x170, 0x5, 0xe, 0x8, 0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 0x2, 
    0x170, 0x173, 0x3, 0x2, 0x2, 0x2, 0x171, 0x16f, 0x3, 0x2, 0x2, 0x2, 
    0x171, 0x172, 0x3, 0x2, 0x2, 0x2, 0x172, 0x174, 0x3, 0x2, 0x2, 0x2, 
    0x173, 0x171, 0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x7, 0x37, 0x2, 0x2, 
    0x175, 0x176, 0x5, 0x26, 0x14, 0x2, 0x176, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x177, 0x178, 0x7, 0x34, 0x2, 0x2, 0x178, 0x179, 0x5, 0x32, 0x1a, 0x2, 
    0x179, 0x17a, 0x7, 0x11, 0x2, 0x2, 0x17a, 0x17b, 0x5, 0x26, 0x14, 0x2, 
    0x17b, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x7, 0x2d, 0x2, 0x2, 
    0x17d, 0x17e, 0x5, 0x54, 0x2b, 0x2, 0x17e, 0x17f, 0x7, 0x32, 0x2, 0x2, 
    0x17f, 0x180, 0x5, 0x32, 0x1a, 0x2, 0x180, 0x5f, 0x3, 0x2, 0x2, 0x2, 
    0x181, 0x182, 0x7, 0x16, 0x2, 0x2, 0x182, 0x183, 0x5, 0x2e, 0x18, 0x2, 
    0x183, 0x184, 0x9, 0x8, 0x2, 0x2, 0x184, 0x185, 0x5, 0x32, 0x1a, 0x2, 
    0x185, 0x186, 0x7, 0x11, 0x2, 0x2, 0x186, 0x187, 0x5, 0x26, 0x14, 0x2, 
    0x187, 0x61, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x7, 0x35, 0x2, 0x2, 
    0x189, 0x18e, 0x5, 0x30, 0x19, 0x2, 0x18a, 0x18b, 0x7, 0x5f, 0x2, 0x2, 
    0x18b, 0x18d, 0x5, 0x30, 0x19, 0x2, 0x18c, 0x18a, 0x3, 0x2, 0x2, 0x2, 
    0x18d, 0x190, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18c, 0x3, 0x2, 0x2, 0x2, 
    0x18e, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x191, 0x3, 0x2, 0x2, 0x2, 
    0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x7, 0x11, 0x2, 0x2, 
    0x192, 0x193, 0x5, 0x26, 0x14, 0x2, 0x193, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x21, 0x6f, 0x77, 0x90, 0x94, 0xa0, 0xa7, 0xb1, 0xba, 0xc2, 0xc6, 0xcb, 
    0xd6, 0xde, 0xe9, 0xf1, 0xf3, 0xfa, 0x102, 0x10a, 0x10f, 0x11c, 0x122, 
    0x12e, 0x133, 0x138, 0x14f, 0x158, 0x162, 0x168, 0x171, 0x18e, 
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
