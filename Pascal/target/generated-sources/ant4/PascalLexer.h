
// Generated from Pascal.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  PascalLexer : public antlr4::Lexer {
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

  PascalLexer(antlr4::CharStream *input);
  ~PascalLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

