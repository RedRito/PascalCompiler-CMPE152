
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
    setState(94);
    programHead();
    setState(95);
    compoundStatement();
    setState(96);
    match(PascalParser::DOT);
    setState(97);
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
    setState(113);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::PROGRAM: {
        enterOuterAlt(_localctx, 1);
        setState(99);
        match(PascalParser::PROGRAM);
        setState(100);
        identifier();
        setState(105);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PascalParser::LPAREN) {
          setState(101);
          match(PascalParser::LPAREN);
          setState(102);
          identifierList();
          setState(103);
          match(PascalParser::RPAREN);
        }
        setState(107);
        match(PascalParser::SEMICOLON);
        break;
      }

      case PascalParser::UNIT: {
        enterOuterAlt(_localctx, 2);
        setState(109);
        match(PascalParser::UNIT);
        setState(110);
        identifier();
        setState(111);
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
    setState(115);
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
    setState(117);
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
    setState(119);
    identifier();
    setState(120);
    match(PascalParser::EQUAL);
    setState(121);
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
    setState(123);
    match(PascalParser::CHR);
    setState(124);
    match(PascalParser::LPAREN);
    setState(125);
    unsignedInteger();
    setState(126);
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
    setState(138);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(128);
      unsignedNumber();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(129);
      sign();
      setState(130);
      unsignedNumber();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(132);
      identifier();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(133);
      sign();
      setState(134);
      identifier();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(136);
      string();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(137);
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
    setState(142);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::NUM_INT: {
        enterOuterAlt(_localctx, 1);
        setState(140);
        unsignedInteger();
        break;
      }

      case PascalParser::NUM_REAL: {
        enterOuterAlt(_localctx, 2);
        setState(141);
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
    setState(144);
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
    setState(146);
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
    setState(148);
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
    setState(150);
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
    setState(154);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(152);
        identifier();
        break;
      }

      case PascalParser::BOOLEAN:
      case PascalParser::CHAR:
      case PascalParser::INTEGER:
      case PascalParser::REAL:
      case PascalParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(153);
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
    setState(156);
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
    setState(161);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(158);
      scalarType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(159);
      typeIdentifier();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(160);
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
    setState(163);
    match(PascalParser::LPAREN);
    setState(164);
    identifierList();
    setState(165);
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
    setState(167);
    match(PascalParser::STRING);
    setState(168);
    match(PascalParser::LBRACKET);
    setState(171);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::IDENT: {
        setState(169);
        identifier();
        break;
      }

      case PascalParser::NUM_INT:
      case PascalParser::NUM_REAL: {
        setState(170);
        unsignedNumber();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(173);
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
    setState(175);
    identifier();
    setState(180);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(176);
      match(PascalParser::COMMA);
      setState(177);
      identifier();
      setState(182);
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
    setState(188);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::NUM_INT: {
        enterOuterAlt(_localctx, 1);
        setState(183);
        label();
        setState(184);
        match(PascalParser::COLON);
        setState(185);
        unlabelledStatement();
        break;
      }

      case PascalParser::BEGIN:
      case PascalParser::CASE:
      case PascalParser::FOR:
      case PascalParser::GOTO:
      case PascalParser::IF:
      case PascalParser::REPEAT:
      case PascalParser::WHILE:
      case PascalParser::WITH:
      case PascalParser::WRITE:
      case PascalParser::WRITELN:
      case PascalParser::AT:
      case PascalParser::IDENT: {
        enterOuterAlt(_localctx, 2);
        setState(187);
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
    setState(192);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::GOTO:
      case PascalParser::AT:
      case PascalParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(190);
        simpleStatement();
        break;
      }

      case PascalParser::BEGIN:
      case PascalParser::CASE:
      case PascalParser::FOR:
      case PascalParser::IF:
      case PascalParser::REPEAT:
      case PascalParser::WHILE:
      case PascalParser::WITH:
      case PascalParser::WRITE:
      case PascalParser::WRITELN: {
        enterOuterAlt(_localctx, 2);
        setState(191);
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
    setState(196);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::AT:
      case PascalParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(194);
        assignmentStatement();
        break;
      }

      case PascalParser::GOTO: {
        enterOuterAlt(_localctx, 2);
        setState(195);
        gotoStatement();
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
  enterRule(_localctx, 42, PascalParser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    variable();
    setState(199);
    match(PascalParser::ASSIGN);
    setState(200);
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
  enterRule(_localctx, 44, PascalParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::AT: {
        setState(202);
        match(PascalParser::AT);
        setState(203);
        identifier();
        break;
      }

      case PascalParser::IDENT: {
        setState(204);
        identifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 55) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 55)) & ((1ULL << (PascalParser::LBRACKET2 - 55))
      | (1ULL << (PascalParser::DOT - 55))
      | (1ULL << (PascalParser::CARAT - 55))
      | (1ULL << (PascalParser::LBRACKET - 55)))) != 0)) {
      setState(232);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PascalParser::LBRACKET: {
          setState(207);
          match(PascalParser::LBRACKET);
          setState(208);
          expression();
          setState(213);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PascalParser::COMMA) {
            setState(209);
            match(PascalParser::COMMA);
            setState(210);
            expression();
            setState(215);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(216);
          match(PascalParser::RBRACKET);
          break;
        }

        case PascalParser::LBRACKET2: {
          setState(218);
          match(PascalParser::LBRACKET2);
          setState(219);
          expression();
          setState(224);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PascalParser::COMMA) {
            setState(220);
            match(PascalParser::COMMA);
            setState(221);
            expression();
            setState(226);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(227);
          match(PascalParser::RBRACKET2);
          break;
        }

        case PascalParser::DOT: {
          setState(229);
          match(PascalParser::DOT);
          setState(230);
          identifier();
          break;
        }

        case PascalParser::CARAT: {
          setState(231);
          match(PascalParser::CARAT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(236);
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
  enterRule(_localctx, 46, PascalParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    simpleExpression();
    setState(241);
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
      setState(238);
      relationaloperator();
      setState(239);
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
  enterRule(_localctx, 48, PascalParser::RuleRelationaloperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
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
  enterRule(_localctx, 50, PascalParser::RuleSimpleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    term();
    setState(249);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 35) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 35)) & ((1ULL << (PascalParser::OR - 35))
      | (1ULL << (PascalParser::PLUSOP - 35))
      | (1ULL << (PascalParser::MINUSOP - 35)))) != 0)) {
      setState(246);
      additiveoperator();
      setState(247);
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
  enterRule(_localctx, 52, PascalParser::RuleAdditiveoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    _la = _input->LA(1);
    if (!(((((_la - 35) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 35)) & ((1ULL << (PascalParser::OR - 35))
      | (1ULL << (PascalParser::PLUSOP - 35))
      | (1ULL << (PascalParser::MINUSOP - 35)))) != 0))) {
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
  enterRule(_localctx, 54, PascalParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    signedFactor();
    setState(257);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PascalParser::AND)
      | (1ULL << PascalParser::DIV)
      | (1ULL << PascalParser::MOD))) != 0) || _la == PascalParser::MULTOP

    || _la == PascalParser::DIVOP) {
      setState(254);
      multiplicativeoperator();
      setState(255);
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
  enterRule(_localctx, 56, PascalParser::RuleMultiplicativeoperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
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
  enterRule(_localctx, 58, PascalParser::RuleSignedFactor);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::PLUSOP

    || _la == PascalParser::MINUSOP) {
      setState(261);
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
    setState(264);
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
  enterRule(_localctx, 60, PascalParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(275);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::AT:
      case PascalParser::IDENT: {
        enterOuterAlt(_localctx, 1);
        setState(266);
        variable();
        break;
      }

      case PascalParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(267);
        match(PascalParser::LPAREN);
        setState(268);
        expression();
        setState(269);
        match(PascalParser::RPAREN);
        break;
      }

      case PascalParser::CHR:
      case PascalParser::NIL:
      case PascalParser::STRING_LITERAL:
      case PascalParser::NUM_INT:
      case PascalParser::NUM_REAL: {
        enterOuterAlt(_localctx, 3);
        setState(271);
        unsignedConstant();
        break;
      }

      case PascalParser::NOT: {
        enterOuterAlt(_localctx, 4);
        setState(272);
        match(PascalParser::NOT);
        setState(273);
        factor();
        break;
      }

      case PascalParser::TRUE:
      case PascalParser::FALSE: {
        enterOuterAlt(_localctx, 5);
        setState(274);
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
  enterRule(_localctx, 62, PascalParser::RuleUnsignedConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(281);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::NUM_INT:
      case PascalParser::NUM_REAL: {
        enterOuterAlt(_localctx, 1);
        setState(277);
        unsignedNumber();
        break;
      }

      case PascalParser::CHR: {
        enterOuterAlt(_localctx, 2);
        setState(278);
        constantChr();
        break;
      }

      case PascalParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(279);
        string();
        break;
      }

      case PascalParser::NIL: {
        enterOuterAlt(_localctx, 4);
        setState(280);
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
  enterRule(_localctx, 64, PascalParser::RuleGotoStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    match(PascalParser::GOTO);
    setState(284);
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

PascalParser::IfStatementContext* PascalParser::StructuredStatementContext::ifStatement() {
  return getRuleContext<PascalParser::IfStatementContext>(0);
}

PascalParser::CaseStatementContext* PascalParser::StructuredStatementContext::caseStatement() {
  return getRuleContext<PascalParser::CaseStatementContext>(0);
}

PascalParser::WhileStatementContext* PascalParser::StructuredStatementContext::whileStatement() {
  return getRuleContext<PascalParser::WhileStatementContext>(0);
}

PascalParser::RepeatStatementContext* PascalParser::StructuredStatementContext::repeatStatement() {
  return getRuleContext<PascalParser::RepeatStatementContext>(0);
}

PascalParser::ForStatementContext* PascalParser::StructuredStatementContext::forStatement() {
  return getRuleContext<PascalParser::ForStatementContext>(0);
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
  enterRule(_localctx, 66, PascalParser::RuleStructuredStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(295);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PascalParser::BEGIN: {
        enterOuterAlt(_localctx, 1);
        setState(286);
        compoundStatement();
        break;
      }

      case PascalParser::IF: {
        enterOuterAlt(_localctx, 2);
        setState(287);
        ifStatement();
        break;
      }

      case PascalParser::CASE: {
        enterOuterAlt(_localctx, 3);
        setState(288);
        caseStatement();
        break;
      }

      case PascalParser::WHILE: {
        enterOuterAlt(_localctx, 4);
        setState(289);
        whileStatement();
        break;
      }

      case PascalParser::REPEAT: {
        enterOuterAlt(_localctx, 5);
        setState(290);
        repeatStatement();
        break;
      }

      case PascalParser::FOR: {
        enterOuterAlt(_localctx, 6);
        setState(291);
        forStatement();
        break;
      }

      case PascalParser::WITH: {
        enterOuterAlt(_localctx, 7);
        setState(292);
        withStatement();
        break;
      }

      case PascalParser::WRITE: {
        enterOuterAlt(_localctx, 8);
        setState(293);
        writeStatement();
        break;
      }

      case PascalParser::WRITELN: {
        enterOuterAlt(_localctx, 9);
        setState(294);
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

std::vector<tree::TerminalNode *> PascalParser::WriteArgumentsContext::COMMA() {
  return getTokens(PascalParser::COMMA);
}

tree::TerminalNode* PascalParser::WriteArgumentsContext::COMMA(size_t i) {
  return getToken(PascalParser::COMMA, i);
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
  enterRule(_localctx, 68, PascalParser::RuleWriteArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    writeArgs();
    setState(302);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(298);
      match(PascalParser::COMMA);
      setState(299);
      writeArgs();
      setState(304);
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

//----------------- WriteArgsContext ------------------------------------------------------------------

PascalParser::WriteArgsContext::WriteArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PascalParser::IdentifierContext* PascalParser::WriteArgsContext::identifier() {
  return getRuleContext<PascalParser::IdentifierContext>(0);
}

PascalParser::UnsignedConstantContext* PascalParser::WriteArgsContext::unsignedConstant() {
  return getRuleContext<PascalParser::UnsignedConstantContext>(0);
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
  enterRule(_localctx, 70, PascalParser::RuleWriteArgs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(305);
      identifier();
      break;
    }

    case 2: {
      setState(306);
      unsignedConstant();
      break;
    }

    case 3: {
      setState(307);
      expression();
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
  enterRule(_localctx, 72, PascalParser::RuleWriteStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    match(PascalParser::WRITE);
    setState(311);
    match(PascalParser::LPAREN);
    setState(312);
    writeArguments();
    setState(313);
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
  enterRule(_localctx, 74, PascalParser::RuleWritelnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    match(PascalParser::WRITELN);
    setState(316);
    match(PascalParser::LPAREN);
    setState(317);
    writeArguments();
    setState(318);
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
  enterRule(_localctx, 76, PascalParser::RuleCompoundStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(320);
    match(PascalParser::BEGIN);
    setState(321);
    statements();
    setState(322);
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
  enterRule(_localctx, 78, PascalParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    statement();
    setState(329);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::SEMICOLON) {
      setState(325);
      match(PascalParser::SEMICOLON);
      setState(326);
      statement();
      setState(331);
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
  enterRule(_localctx, 80, PascalParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    match(PascalParser::IF);
    setState(333);
    expression();
    setState(334);
    match(PascalParser::THEN);
    setState(335);
    statement();
    setState(338);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(336);
      match(PascalParser::ELSE);
      setState(337);
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
  enterRule(_localctx, 82, PascalParser::RuleCaseStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(340);
    match(PascalParser::CASE);
    setState(341);
    expression();
    setState(342);
    match(PascalParser::OF);
    setState(343);
    caseListElement();
    setState(348);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(344);
        match(PascalParser::SEMICOLON);
        setState(345);
        caseListElement(); 
      }
      setState(350);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
    setState(354);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PascalParser::SEMICOLON) {
      setState(351);
      match(PascalParser::SEMICOLON);
      setState(352);
      match(PascalParser::ELSE);
      setState(353);
      statements();
    }
    setState(356);
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
  enterRule(_localctx, 84, PascalParser::RuleCaseListElement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(358);
    constant();
    setState(363);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(359);
      match(PascalParser::COMMA);
      setState(360);
      constant();
      setState(365);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(366);
    match(PascalParser::COLON);
    setState(367);
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
  enterRule(_localctx, 86, PascalParser::RuleWhileStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    match(PascalParser::WHILE);
    setState(370);
    expression();
    setState(371);
    match(PascalParser::DO);
    setState(372);
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
  enterRule(_localctx, 88, PascalParser::RuleRepeatStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    match(PascalParser::REPEAT);
    setState(375);
    statements();
    setState(376);
    match(PascalParser::UNTIL);
    setState(377);
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

PascalParser::IdentifierContext* PascalParser::ForStatementContext::identifier() {
  return getRuleContext<PascalParser::IdentifierContext>(0);
}

tree::TerminalNode* PascalParser::ForStatementContext::ASSIGN() {
  return getToken(PascalParser::ASSIGN, 0);
}

std::vector<PascalParser::ExpressionContext *> PascalParser::ForStatementContext::expression() {
  return getRuleContexts<PascalParser::ExpressionContext>();
}

PascalParser::ExpressionContext* PascalParser::ForStatementContext::expression(size_t i) {
  return getRuleContext<PascalParser::ExpressionContext>(i);
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
  enterRule(_localctx, 90, PascalParser::RuleForStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
    match(PascalParser::FOR);
    setState(380);
    identifier();
    setState(381);
    match(PascalParser::ASSIGN);
    setState(382);
    expression();
    setState(383);
    _la = _input->LA(1);
    if (!(_la == PascalParser::DOWNTO

    || _la == PascalParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(384);
    expression();
    setState(385);
    match(PascalParser::DO);
    setState(386);
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
  enterRule(_localctx, 92, PascalParser::RuleWithStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    match(PascalParser::WITH);
    setState(389);
    variable();
    setState(394);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PascalParser::COMMA) {
      setState(390);
      match(PascalParser::COMMA);
      setState(391);
      variable();
      setState(396);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(397);
    match(PascalParser::DO);
    setState(398);
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
  "assignmentStatement", "variable", "expression", "relationaloperator", 
  "simpleExpression", "additiveoperator", "term", "multiplicativeoperator", 
  "signedFactor", "factor", "unsignedConstant", "gotoStatement", "structuredStatement", 
  "writeArguments", "writeArgs", "writeStatement", "writelnStatement", "compoundStatement", 
  "statements", "ifStatement", "caseStatement", "caseListElement", "whileStatement", 
  "repeatStatement", "forStatement", "withStatement"
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
  "INLINE", "INTEGER", "LABEL", "MOD", "NIL", "OBJECT", "NOT", "OF", "ON", 
  "OPERATOR", "OR", "PACKED", "PROCEDURE", "PROGRAM", "REAL", "RECORD", 
  "REPEAT", "SET", "THEN", "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH", 
  "WRITE", "WRITELN", "ASSIGN", "COLON", "EQUAL", "LBRACKET2", "RBRACKET2", 
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
    0x3, 0x67, 0x193, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x6c, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x74, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 
    0x8, 0x8d, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x91, 0xa, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x9d, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xa4, 0xa, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x5, 0x12, 0xae, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x7, 0x13, 0xb5, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0xb8, 
    0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 
    0x14, 0xbf, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xc3, 0xa, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xc7, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0xd0, 
    0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0xd6, 
    0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0xd9, 0xb, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0xe1, 0xa, 0x18, 
    0xc, 0x18, 0xe, 0x18, 0xe4, 0xb, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0xeb, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 
    0xee, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 
    0xf4, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x5, 0x1b, 0xfc, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x104, 0xa, 0x1d, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1f, 0x5, 0x1f, 0x109, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x116, 0xa, 0x20, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x11c, 0xa, 0x21, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x12a, 
    0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x12f, 0xa, 0x24, 
    0xc, 0x24, 0xe, 0x24, 0x132, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x5, 0x25, 0x137, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x7, 0x29, 0x14a, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x14d, 0xb, 0x29, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 
    0x2a, 0x155, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x15d, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 
    0x160, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x165, 
    0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 
    0x2c, 0x16c, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x16f, 0xb, 0x2c, 0x3, 
    0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x7, 
    0x30, 0x18b, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x18e, 0xb, 0x30, 0x3, 
    0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x2, 0x2, 0x31, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
    0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x2, 0x9, 0x3, 0x2, 
    0x50, 0x51, 0x3, 0x2, 0x43, 0x44, 0x7, 0x2, 0x8, 0x8, 0xa, 0xa, 0x1c, 
    0x1c, 0x29, 0x29, 0x41, 0x41, 0x5, 0x2, 0x1a, 0x1a, 0x38, 0x38, 0x54, 
    0x58, 0x4, 0x2, 0x25, 0x25, 0x50, 0x51, 0x6, 0x2, 0x3, 0x3, 0x10, 0x10, 
    0x1e, 0x1e, 0x52, 0x53, 0x4, 0x2, 0x12, 0x12, 0x2e, 0x2e, 0x2, 0x196, 
    0x2, 0x60, 0x3, 0x2, 0x2, 0x2, 0x4, 0x73, 0x3, 0x2, 0x2, 0x2, 0x6, 0x75, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x77, 0x3, 0x2, 0x2, 0x2, 0xa, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x7d, 0x3, 0x2, 0x2, 0x2, 0xe, 0x8c, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x90, 0x3, 0x2, 0x2, 0x2, 0x12, 0x92, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0x16, 0x96, 0x3, 0x2, 0x2, 0x2, 0x18, 0x98, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x9e, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x20, 0xa5, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x24, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xbe, 0x3, 0x2, 0x2, 0x2, 0x28, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0xc6, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0xcf, 0x3, 0x2, 0x2, 0x2, 0x30, 0xef, 0x3, 0x2, 0x2, 0x2, 0x32, 0xf5, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x36, 0xfd, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0xff, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x105, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x108, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x115, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x42, 0x11d, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x129, 0x3, 0x2, 0x2, 0x2, 0x46, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x136, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x13d, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x142, 0x3, 0x2, 0x2, 0x2, 0x50, 0x146, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x54, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x168, 0x3, 0x2, 0x2, 0x2, 0x58, 0x173, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x178, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x17d, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x186, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x5, 0x4, 0x3, 0x2, 0x61, 
    0x62, 0x5, 0x4e, 0x28, 0x2, 0x62, 0x63, 0x7, 0x3c, 0x2, 0x2, 0x63, 0x64, 
    0x7, 0x2, 0x2, 0x3, 0x64, 0x3, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x7, 
    0x28, 0x2, 0x2, 0x66, 0x6b, 0x5, 0x6, 0x4, 0x2, 0x67, 0x68, 0x7, 0x60, 
    0x2, 0x2, 0x68, 0x69, 0x5, 0x24, 0x13, 0x2, 0x69, 0x6a, 0x7, 0x61, 0x2, 
    0x2, 0x6a, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x67, 0x3, 0x2, 0x2, 0x2, 
    0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 
    0x6e, 0x7, 0x5e, 0x2, 0x2, 0x6e, 0x74, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 
    0x7, 0x3e, 0x2, 0x2, 0x70, 0x71, 0x5, 0x6, 0x4, 0x2, 0x71, 0x72, 0x7, 
    0x5e, 0x2, 0x2, 0x72, 0x74, 0x3, 0x2, 0x2, 0x2, 0x73, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x73, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x74, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x75, 0x76, 0x7, 0x48, 0x2, 0x2, 0x76, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x77, 0x78, 0x5, 0x12, 0xa, 0x2, 0x78, 0x9, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x7a, 0x5, 0x6, 0x4, 0x2, 0x7a, 0x7b, 0x7, 0x38, 0x2, 0x2, 0x7b, 0x7c, 
    0x5, 0xe, 0x8, 0x2, 0x7c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x7, 
    0xb, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x60, 0x2, 0x2, 0x7f, 0x80, 0x5, 0x12, 
    0xa, 0x2, 0x80, 0x81, 0x7, 0x61, 0x2, 0x2, 0x81, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x8d, 0x5, 0x10, 0x9, 0x2, 0x83, 0x84, 0x5, 0x16, 0xc, 0x2, 
    0x84, 0x85, 0x5, 0x10, 0x9, 0x2, 0x85, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x86, 
    0x8d, 0x5, 0x6, 0x4, 0x2, 0x87, 0x88, 0x5, 0x16, 0xc, 0x2, 0x88, 0x89, 
    0x5, 0x6, 0x4, 0x2, 0x89, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8d, 0x5, 
    0x1c, 0xf, 0x2, 0x8b, 0x8d, 0x5, 0xc, 0x7, 0x2, 0x8c, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x8c, 0x83, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x86, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x8c, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x91, 0x5, 0x12, 0xa, 0x2, 0x8f, 0x91, 0x5, 0x14, 0xb, 0x2, 0x90, 0x8e, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x4a, 0x2, 0x2, 0x93, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x94, 0x95, 0x7, 0x4b, 0x2, 0x2, 0x95, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x96, 0x97, 0x9, 0x2, 0x2, 0x2, 0x97, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x98, 0x99, 0x9, 0x3, 0x2, 0x2, 0x99, 0x19, 0x3, 0x2, 0x2, 0x2, 0x9a, 
    0x9d, 0x5, 0x6, 0x4, 0x2, 0x9b, 0x9d, 0x9, 0x4, 0x2, 0x2, 0x9c, 0x9a, 
    0x3, 0x2, 0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x49, 0x2, 0x2, 0x9f, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0xa4, 0x5, 0x20, 0x11, 0x2, 0xa1, 0xa4, 0x5, 0x1a, 0xe, 
    0x2, 0xa2, 0xa4, 0x5, 0x22, 0x12, 0x2, 0xa3, 0xa0, 0x3, 0x2, 0x2, 0x2, 
    0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x60, 0x2, 0x2, 0xa6, 0xa7, 
    0x5, 0x24, 0x13, 0x2, 0xa7, 0xa8, 0x7, 0x61, 0x2, 0x2, 0xa8, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x41, 0x2, 0x2, 0xaa, 0xad, 0x7, 0x62, 
    0x2, 0x2, 0xab, 0xae, 0x5, 0x6, 0x4, 0x2, 0xac, 0xae, 0x5, 0x10, 0x9, 
    0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xac, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x63, 0x2, 0x2, 0xb0, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb6, 0x5, 0x6, 0x4, 0x2, 0xb2, 0xb3, 
    0x7, 0x5f, 0x2, 0x2, 0xb3, 0xb5, 0x5, 0x6, 0x4, 0x2, 0xb4, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0xb5, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x5, 0x8, 0x5, 0x2, 
    0xba, 0xbb, 0x7, 0x37, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0x28, 0x15, 0x2, 0xbc, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbf, 0x5, 0x28, 0x15, 0x2, 0xbe, 0xb9, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc3, 0x5, 0x2a, 0x16, 0x2, 0xc1, 0xc3, 0x5, 0x44, 
    0x23, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc1, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0x29, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc7, 0x5, 0x2c, 0x17, 0x2, 
    0xc5, 0xc7, 0x5, 0x42, 0x22, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 
    0x5, 0x2e, 0x18, 0x2, 0xc9, 0xca, 0x7, 0x36, 0x2, 0x2, 0xca, 0xcb, 0x5, 
    0x30, 0x19, 0x2, 0xcb, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x3b, 
    0x2, 0x2, 0xcd, 0xd0, 0x5, 0x6, 0x4, 0x2, 0xce, 0xd0, 0x5, 0x6, 0x4, 
    0x2, 0xcf, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xce, 0x3, 0x2, 0x2, 0x2, 
    0xd0, 0xec, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x62, 0x2, 0x2, 0xd2, 
    0xd7, 0x5, 0x30, 0x19, 0x2, 0xd3, 0xd4, 0x7, 0x5f, 0x2, 0x2, 0xd4, 0xd6, 
    0x5, 0x30, 0x19, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd9, 0x3, 
    0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 
    0x2, 0x2, 0xd8, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 
    0x2, 0xda, 0xdb, 0x7, 0x63, 0x2, 0x2, 0xdb, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xdd, 0x7, 0x39, 0x2, 0x2, 0xdd, 0xe2, 0x5, 0x30, 0x19, 0x2, 0xde, 
    0xdf, 0x7, 0x5f, 0x2, 0x2, 0xdf, 0xe1, 0x5, 0x30, 0x19, 0x2, 0xe0, 0xde, 
    0x3, 0x2, 0x2, 0x2, 0xe1, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe5, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x3a, 0x2, 
    0x2, 0xe6, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x3c, 0x2, 0x2, 
    0xe8, 0xeb, 0x5, 0x6, 0x4, 0x2, 0xe9, 0xeb, 0x7, 0x5d, 0x2, 0x2, 0xea, 
    0xd1, 0x3, 0x2, 0x2, 0x2, 0xea, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe7, 
    0x3, 0x2, 0x2, 0x2, 0xea, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 
    0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 
    0x2, 0x2, 0xed, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 
    0x2, 0xef, 0xf3, 0x5, 0x34, 0x1b, 0x2, 0xf0, 0xf1, 0x5, 0x32, 0x1a, 
    0x2, 0xf1, 0xf2, 0x5, 0x30, 0x19, 0x2, 0xf2, 0xf4, 0x3, 0x2, 0x2, 0x2, 
    0xf3, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x9, 0x5, 0x2, 0x2, 0xf6, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0xf7, 0xfb, 0x5, 0x38, 0x1d, 0x2, 0xf8, 0xf9, 0x5, 
    0x36, 0x1c, 0x2, 0xf9, 0xfa, 0x5, 0x34, 0x1b, 0x2, 0xfa, 0xfc, 0x3, 
    0x2, 0x2, 0x2, 0xfb, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 
    0x2, 0x2, 0xfc, 0x35, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x9, 0x6, 0x2, 
    0x2, 0xfe, 0x37, 0x3, 0x2, 0x2, 0x2, 0xff, 0x103, 0x5, 0x3c, 0x1f, 0x2, 
    0x100, 0x101, 0x5, 0x3a, 0x1e, 0x2, 0x101, 0x102, 0x5, 0x38, 0x1d, 0x2, 
    0x102, 0x104, 0x3, 0x2, 0x2, 0x2, 0x103, 0x100, 0x3, 0x2, 0x2, 0x2, 
    0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 0x104, 0x39, 0x3, 0x2, 0x2, 0x2, 0x105, 
    0x106, 0x9, 0x7, 0x2, 0x2, 0x106, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x107, 0x109, 
    0x9, 0x2, 0x2, 0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 
    0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 
    0x5, 0x3e, 0x20, 0x2, 0x10b, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x116, 
    0x5, 0x2e, 0x18, 0x2, 0x10d, 0x10e, 0x7, 0x60, 0x2, 0x2, 0x10e, 0x10f, 
    0x5, 0x30, 0x19, 0x2, 0x10f, 0x110, 0x7, 0x61, 0x2, 0x2, 0x110, 0x116, 
    0x3, 0x2, 0x2, 0x2, 0x111, 0x116, 0x5, 0x40, 0x21, 0x2, 0x112, 0x113, 
    0x7, 0x21, 0x2, 0x2, 0x113, 0x116, 0x5, 0x3e, 0x20, 0x2, 0x114, 0x116, 
    0x5, 0x18, 0xd, 0x2, 0x115, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x115, 0x10d, 
    0x3, 0x2, 0x2, 0x2, 0x115, 0x111, 0x3, 0x2, 0x2, 0x2, 0x115, 0x112, 
    0x3, 0x2, 0x2, 0x2, 0x115, 0x114, 0x3, 0x2, 0x2, 0x2, 0x116, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x117, 0x11c, 0x5, 0x10, 0x9, 0x2, 0x118, 0x11c, 0x5, 
    0xc, 0x7, 0x2, 0x119, 0x11c, 0x5, 0x1c, 0xf, 0x2, 0x11a, 0x11c, 0x7, 
    0x1f, 0x2, 0x2, 0x11b, 0x117, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x118, 0x3, 
    0x2, 0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11a, 0x3, 
    0x2, 0x2, 0x2, 0x11c, 0x41, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x7, 0x18, 
    0x2, 0x2, 0x11e, 0x11f, 0x5, 0x8, 0x5, 0x2, 0x11f, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x120, 0x12a, 0x5, 0x4e, 0x28, 0x2, 0x121, 0x12a, 0x5, 0x52, 0x2a, 
    0x2, 0x122, 0x12a, 0x5, 0x54, 0x2b, 0x2, 0x123, 0x12a, 0x5, 0x58, 0x2d, 
    0x2, 0x124, 0x12a, 0x5, 0x5a, 0x2e, 0x2, 0x125, 0x12a, 0x5, 0x5c, 0x2f, 
    0x2, 0x126, 0x12a, 0x5, 0x5e, 0x30, 0x2, 0x127, 0x12a, 0x5, 0x4a, 0x26, 
    0x2, 0x128, 0x12a, 0x5, 0x4c, 0x27, 0x2, 0x129, 0x120, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x121, 0x3, 0x2, 0x2, 0x2, 0x129, 0x122, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x123, 0x3, 0x2, 0x2, 0x2, 0x129, 0x124, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x125, 0x3, 0x2, 0x2, 0x2, 0x129, 0x126, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x129, 0x128, 0x3, 0x2, 0x2, 
    0x2, 0x12a, 0x45, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x130, 0x5, 0x48, 0x25, 
    0x2, 0x12c, 0x12d, 0x7, 0x5f, 0x2, 0x2, 0x12d, 0x12f, 0x5, 0x48, 0x25, 
    0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x132, 0x3, 0x2, 0x2, 
    0x2, 0x130, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x3, 0x2, 0x2, 
    0x2, 0x131, 0x47, 0x3, 0x2, 0x2, 0x2, 0x132, 0x130, 0x3, 0x2, 0x2, 0x2, 
    0x133, 0x137, 0x5, 0x6, 0x4, 0x2, 0x134, 0x137, 0x5, 0x40, 0x21, 0x2, 
    0x135, 0x137, 0x5, 0x30, 0x19, 0x2, 0x136, 0x133, 0x3, 0x2, 0x2, 0x2, 
    0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 0x136, 0x135, 0x3, 0x2, 0x2, 0x2, 
    0x137, 0x49, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x7, 0x34, 0x2, 0x2, 
    0x139, 0x13a, 0x7, 0x60, 0x2, 0x2, 0x13a, 0x13b, 0x5, 0x46, 0x24, 0x2, 
    0x13b, 0x13c, 0x7, 0x61, 0x2, 0x2, 0x13c, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x13d, 0x13e, 0x7, 0x35, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x60, 0x2, 0x2, 
    0x13f, 0x140, 0x5, 0x46, 0x24, 0x2, 0x140, 0x141, 0x7, 0x61, 0x2, 0x2, 
    0x141, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x7, 0x6, 0x2, 0x2, 0x143, 
    0x144, 0x5, 0x50, 0x29, 0x2, 0x144, 0x145, 0x7, 0x14, 0x2, 0x2, 0x145, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x146, 0x14b, 0x5, 0x26, 0x14, 0x2, 0x147, 
    0x148, 0x7, 0x5e, 0x2, 0x2, 0x148, 0x14a, 0x5, 0x26, 0x14, 0x2, 0x149, 
    0x147, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14b, 
    0x149, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14c, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 
    0x7, 0x19, 0x2, 0x2, 0x14f, 0x150, 0x5, 0x30, 0x19, 0x2, 0x150, 0x151, 
    0x7, 0x2d, 0x2, 0x2, 0x151, 0x154, 0x5, 0x26, 0x14, 0x2, 0x152, 0x153, 
    0x7, 0x13, 0x2, 0x2, 0x153, 0x155, 0x5, 0x26, 0x14, 0x2, 0x154, 0x152, 
    0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 0x155, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x156, 0x157, 0x7, 0x9, 0x2, 0x2, 0x157, 0x158, 0x5, 
    0x30, 0x19, 0x2, 0x158, 0x159, 0x7, 0x22, 0x2, 0x2, 0x159, 0x15e, 0x5, 
    0x56, 0x2c, 0x2, 0x15a, 0x15b, 0x7, 0x5e, 0x2, 0x2, 0x15b, 0x15d, 0x5, 
    0x56, 0x2c, 0x2, 0x15c, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x160, 0x3, 
    0x2, 0x2, 0x2, 0x15e, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 
    0x2, 0x2, 0x2, 0x15f, 0x164, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15e, 0x3, 
    0x2, 0x2, 0x2, 0x161, 0x162, 0x7, 0x5e, 0x2, 0x2, 0x162, 0x163, 0x7, 
    0x13, 0x2, 0x2, 0x163, 0x165, 0x5, 0x50, 0x29, 0x2, 0x164, 0x161, 0x3, 
    0x2, 0x2, 0x2, 0x164, 0x165, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 
    0x2, 0x2, 0x2, 0x166, 0x167, 0x7, 0x14, 0x2, 0x2, 0x167, 0x55, 0x3, 
    0x2, 0x2, 0x2, 0x168, 0x16d, 0x5, 0xe, 0x8, 0x2, 0x169, 0x16a, 0x7, 
    0x5f, 0x2, 0x2, 0x16a, 0x16c, 0x5, 0xe, 0x8, 0x2, 0x16b, 0x169, 0x3, 
    0x2, 0x2, 0x2, 0x16c, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16b, 0x3, 
    0x2, 0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x170, 0x3, 
    0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x7, 
    0x37, 0x2, 0x2, 0x171, 0x172, 0x5, 0x26, 0x14, 0x2, 0x172, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x173, 0x174, 0x7, 0x32, 0x2, 0x2, 0x174, 0x175, 0x5, 
    0x30, 0x19, 0x2, 0x175, 0x176, 0x7, 0x11, 0x2, 0x2, 0x176, 0x177, 0x5, 
    0x26, 0x14, 0x2, 0x177, 0x59, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x7, 
    0x2b, 0x2, 0x2, 0x179, 0x17a, 0x5, 0x50, 0x29, 0x2, 0x17a, 0x17b, 0x7, 
    0x30, 0x2, 0x2, 0x17b, 0x17c, 0x5, 0x30, 0x19, 0x2, 0x17c, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x17d, 0x17e, 0x7, 0x16, 0x2, 0x2, 0x17e, 0x17f, 0x5, 
    0x6, 0x4, 0x2, 0x17f, 0x180, 0x7, 0x36, 0x2, 0x2, 0x180, 0x181, 0x5, 
    0x30, 0x19, 0x2, 0x181, 0x182, 0x9, 0x8, 0x2, 0x2, 0x182, 0x183, 0x5, 
    0x30, 0x19, 0x2, 0x183, 0x184, 0x7, 0x11, 0x2, 0x2, 0x184, 0x185, 0x5, 
    0x26, 0x14, 0x2, 0x185, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x7, 
    0x33, 0x2, 0x2, 0x187, 0x18c, 0x5, 0x2e, 0x18, 0x2, 0x188, 0x189, 0x7, 
    0x5f, 0x2, 0x2, 0x189, 0x18b, 0x5, 0x2e, 0x18, 0x2, 0x18a, 0x188, 0x3, 
    0x2, 0x2, 0x2, 0x18b, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18a, 0x3, 
    0x2, 0x2, 0x2, 0x18c, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18f, 0x3, 
    0x2, 0x2, 0x2, 0x18e, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x7, 
    0x11, 0x2, 0x2, 0x190, 0x191, 0x5, 0x26, 0x14, 0x2, 0x191, 0x5f, 0x3, 
    0x2, 0x2, 0x2, 0x21, 0x6b, 0x73, 0x8c, 0x90, 0x9c, 0xa3, 0xad, 0xb6, 
    0xbe, 0xc2, 0xc6, 0xcf, 0xd7, 0xe2, 0xea, 0xec, 0xf3, 0xfb, 0x103, 0x108, 
    0x115, 0x11b, 0x129, 0x130, 0x136, 0x14b, 0x154, 0x15e, 0x164, 0x16d, 
    0x18c, 
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
