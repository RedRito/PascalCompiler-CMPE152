// Generated from \\wsl$\Ubuntu\home\brandonluong\Pascal\Pascal.g4 by ANTLR 4.9.2

   #include "PassOne/Typespec.h"
   #include "PassOne/Symtab.h"
   #include "PassOne/SymtabStack.h"
   #include "Object.h"
   using namespace PassOne::symtab;
   using namespace PassOne::type;

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class PascalParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		AND=1, ARRAY=2, ASM=3, BEGIN=4, BREAK=5, BOOLEAN=6, CASE=7, CHAR=8, CHR=9, 
		CONST=10, CONSTRUCTOR=11, CONTINUE=12, DESTRUCTOR=13, DIV=14, DO=15, DOWNTO=16, 
		ELSE=17, END=18, FILE=19, FOR=20, FUNCTION=21, GOTO=22, IF=23, IN=24, 
		INLINE=25, INTEGER=26, LABEL=27, MOD=28, NIL=29, OBJECT=30, WRITE=31, 
		WRITELN=32, NOT=33, OF=34, ON=35, OPERATOR=36, OR=37, PACKED=38, PROCEDURE=39, 
		PROGRAM=40, REAL=41, RECORD=42, REPEAT=43, SET=44, THEN=45, TO=46, TYPE=47, 
		UNTIL=48, VAR=49, WHILE=50, WITH=51, ASSIGN=52, COLON=53, EQUAL=54, LBRACKET2=55, 
		RBRACKET2=56, AT=57, DOT=58, DOTDOT=59, UNIT=60, INTERFACE=61, USES=62, 
		STRING=63, IMPLEMENTATION=64, TRUE=65, FALSE=66, WS=67, COMMENT_1=68, 
		COMMENT_2=69, IDENT=70, STRING_LITERAL=71, NUM_INT=72, NUM_REAL=73, SHL=74, 
		SHR=75, XOR=76, IDENTIFIER=77, PLUSOP=78, MINUSOP=79, MULTOP=80, DIVOP=81, 
		NE=82, LTEQ=83, GTEQ=84, LT=85, GT=86, PLUSEQUAL=87, MINUSEQUAL=88, MULTEQUAL=89, 
		DIVEQUAL=90, CARAT=91, SEMICOLON=92, COMMA=93, LPAREN=94, RPAREN=95, LBRACKET=96, 
		RBRACKET=97, LBRACE=98, RBRACE=99, LCOMMENT=100, RCOMMENT=101;
	public static final int
		RULE_program = 0, RULE_programHead = 1, RULE_identifier = 2, RULE_block = 3, 
		RULE_usesUnitsPart = 4, RULE_labelDeclarationPart = 5, RULE_constantDefinitionPart = 6, 
		RULE_constantDefinition = 7, RULE_constantIdentifier = 8, RULE_typeDefinitionPart = 9, 
		RULE_typeDefinition = 10, RULE_formalParameterList = 11, RULE_formalParameterSection = 12, 
		RULE_parameterGroup = 13, RULE_functionType = 14, RULE_procedureType = 15, 
		RULE_variableDeclarationPart = 16, RULE_variableDeclaration = 17, RULE_procedureAndFunctionDeclarationPart = 18, 
		RULE_procedureOrFunctionDeclaration = 19, RULE_procedureDeclaration = 20, 
		RULE_functionDeclaration = 21, RULE_type_ = 22, RULE_structuredType = 23, 
		RULE_unpackedStructuredType = 24, RULE_arrayType = 25, RULE_typeList = 26, 
		RULE_pointerType = 27, RULE_label = 28, RULE_constantVar = 29, RULE_constantChr = 30, 
		RULE_constant = 31, RULE_unsignedNumber = 32, RULE_unsignedInteger = 33, 
		RULE_unsignedReal = 34, RULE_sign = 35, RULE_bool_ = 36, RULE_typeIdentifier = 37, 
		RULE_string = 38, RULE_simpleType = 39, RULE_scalarType = 40, RULE_stringtype = 41, 
		RULE_identifierList = 42, RULE_statement = 43, RULE_unlabelledStatement = 44, 
		RULE_simpleStatement = 45, RULE_procedureStatement = 46, RULE_emptyStatement_ = 47, 
		RULE_assignmentStatement = 48, RULE_variable = 49, RULE_variableIdentifier = 50, 
		RULE_modifier = 51, RULE_expression = 52, RULE_relationaloperator = 53, 
		RULE_simpleExpression = 54, RULE_additiveoperator = 55, RULE_term = 56, 
		RULE_multiplicativeoperator = 57, RULE_signedFactor = 58, RULE_factor = 59, 
		RULE_unsignedConstant = 60, RULE_functionDesignator = 61, RULE_parameterList = 62, 
		RULE_actualParameter = 63, RULE_parameterwidth = 64, RULE_set_ = 65, RULE_element = 66, 
		RULE_gotoStatement = 67, RULE_structuredStatement = 68, RULE_reptitiveStatement = 69, 
		RULE_writeArguments = 70, RULE_writeArgs = 71, RULE_writeStatement = 72, 
		RULE_writelnStatement = 73, RULE_compoundStatement = 74, RULE_statements = 75, 
		RULE_ifStatement = 76, RULE_caseStatement = 77, RULE_caseListElement = 78, 
		RULE_whileStatement = 79, RULE_repeatStatement = 80, RULE_forStatement = 81, 
		RULE_withStatement = 82;
	private static String[] makeRuleNames() {
		return new String[] {
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
			"ifStatement", "caseStatement", "caseListElement", "whileStatement", 
			"repeatStatement", "forStatement", "withStatement"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, "':='", "':'", "'='", "'(.'", "'.)'", "'@'", 
			"'.'", "'..'", null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, "'+'", "'-'", "'*'", 
			"'/'", "'<>'", "'<='", "'>='", "'<'", "'>'", "'+='", "'-='", "'*='", 
			"'/='", "'^'", "';'", "','", "'('", "')'", "'['", "']'", "'{'", "'}'", 
			"'(*'", "'*)'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "AND", "ARRAY", "ASM", "BEGIN", "BREAK", "BOOLEAN", "CASE", "CHAR", 
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
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Pascal.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public PascalParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgramContext extends ParserRuleContext {
		public ProgramHeadContext programHead() {
			return getRuleContext(ProgramHeadContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode DOT() { return getToken(PascalParser.DOT, 0); }
		public TerminalNode EOF() { return getToken(PascalParser.EOF, 0); }
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(166);
			programHead();
			setState(167);
			block();
			setState(168);
			match(DOT);
			setState(169);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProgramHeadContext extends ParserRuleContext {
		public SymtabEntry * entry = nullptr;
		public TerminalNode PROGRAM() { return getToken(PascalParser.PROGRAM, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(PascalParser.SEMICOLON, 0); }
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public TerminalNode UNIT() { return getToken(PascalParser.UNIT, 0); }
		public ProgramHeadContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_programHead; }
	}

	public final ProgramHeadContext programHead() throws RecognitionException {
		ProgramHeadContext _localctx = new ProgramHeadContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_programHead);
		int _la;
		try {
			setState(185);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PROGRAM:
				enterOuterAlt(_localctx, 1);
				{
				setState(171);
				match(PROGRAM);
				setState(172);
				identifier();
				setState(177);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==LPAREN) {
					{
					setState(173);
					match(LPAREN);
					setState(174);
					identifierList();
					setState(175);
					match(RPAREN);
					}
				}

				setState(179);
				match(SEMICOLON);
				}
				break;
			case UNIT:
				enterOuterAlt(_localctx, 2);
				{
				setState(181);
				match(UNIT);
				setState(182);
				identifier();
				setState(183);
				match(SEMICOLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdentifierContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public SymtabEntry * entry = nullptr;
		public TerminalNode IDENT() { return getToken(PascalParser.IDENT, 0); }
		public IdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifier; }
	}

	public final IdentifierContext identifier() throws RecognitionException {
		IdentifierContext _localctx = new IdentifierContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_identifier);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(187);
			match(IDENT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockContext extends ParserRuleContext {
		public CompoundStatementContext compoundStatement() {
			return getRuleContext(CompoundStatementContext.class,0);
		}
		public List<LabelDeclarationPartContext> labelDeclarationPart() {
			return getRuleContexts(LabelDeclarationPartContext.class);
		}
		public LabelDeclarationPartContext labelDeclarationPart(int i) {
			return getRuleContext(LabelDeclarationPartContext.class,i);
		}
		public List<ConstantDefinitionPartContext> constantDefinitionPart() {
			return getRuleContexts(ConstantDefinitionPartContext.class);
		}
		public ConstantDefinitionPartContext constantDefinitionPart(int i) {
			return getRuleContext(ConstantDefinitionPartContext.class,i);
		}
		public List<TypeDefinitionPartContext> typeDefinitionPart() {
			return getRuleContexts(TypeDefinitionPartContext.class);
		}
		public TypeDefinitionPartContext typeDefinitionPart(int i) {
			return getRuleContext(TypeDefinitionPartContext.class,i);
		}
		public List<ProcedureAndFunctionDeclarationPartContext> procedureAndFunctionDeclarationPart() {
			return getRuleContexts(ProcedureAndFunctionDeclarationPartContext.class);
		}
		public ProcedureAndFunctionDeclarationPartContext procedureAndFunctionDeclarationPart(int i) {
			return getRuleContext(ProcedureAndFunctionDeclarationPartContext.class,i);
		}
		public List<VariableDeclarationPartContext> variableDeclarationPart() {
			return getRuleContexts(VariableDeclarationPartContext.class);
		}
		public VariableDeclarationPartContext variableDeclarationPart(int i) {
			return getRuleContext(VariableDeclarationPartContext.class,i);
		}
		public List<UsesUnitsPartContext> usesUnitsPart() {
			return getRuleContexts(UsesUnitsPartContext.class);
		}
		public UsesUnitsPartContext usesUnitsPart(int i) {
			return getRuleContext(UsesUnitsPartContext.class,i);
		}
		public List<TerminalNode> IMPLEMENTATION() { return getTokens(PascalParser.IMPLEMENTATION); }
		public TerminalNode IMPLEMENTATION(int i) {
			return getToken(PascalParser.IMPLEMENTATION, i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(198);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 10)) & ~0x3f) == 0 && ((1L << (_la - 10)) & ((1L << (CONST - 10)) | (1L << (FUNCTION - 10)) | (1L << (LABEL - 10)) | (1L << (PROCEDURE - 10)) | (1L << (TYPE - 10)) | (1L << (VAR - 10)) | (1L << (USES - 10)) | (1L << (IMPLEMENTATION - 10)))) != 0)) {
				{
				setState(196);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case LABEL:
					{
					setState(189);
					labelDeclarationPart();
					}
					break;
				case CONST:
					{
					setState(190);
					constantDefinitionPart();
					}
					break;
				case TYPE:
					{
					setState(191);
					typeDefinitionPart();
					}
					break;
				case FUNCTION:
				case PROCEDURE:
					{
					setState(192);
					procedureAndFunctionDeclarationPart();
					}
					break;
				case VAR:
					{
					setState(193);
					variableDeclarationPart();
					}
					break;
				case USES:
					{
					setState(194);
					usesUnitsPart();
					}
					break;
				case IMPLEMENTATION:
					{
					setState(195);
					match(IMPLEMENTATION);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(200);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(201);
			compoundStatement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UsesUnitsPartContext extends ParserRuleContext {
		public TerminalNode USES() { return getToken(PascalParser.USES, 0); }
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(PascalParser.SEMICOLON, 0); }
		public UsesUnitsPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_usesUnitsPart; }
	}

	public final UsesUnitsPartContext usesUnitsPart() throws RecognitionException {
		UsesUnitsPartContext _localctx = new UsesUnitsPartContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_usesUnitsPart);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(203);
			match(USES);
			setState(204);
			identifierList();
			setState(205);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LabelDeclarationPartContext extends ParserRuleContext {
		public TerminalNode LABEL() { return getToken(PascalParser.LABEL, 0); }
		public List<LabelContext> label() {
			return getRuleContexts(LabelContext.class);
		}
		public LabelContext label(int i) {
			return getRuleContext(LabelContext.class,i);
		}
		public TerminalNode SEMICOLON() { return getToken(PascalParser.SEMICOLON, 0); }
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public LabelDeclarationPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_labelDeclarationPart; }
	}

	public final LabelDeclarationPartContext labelDeclarationPart() throws RecognitionException {
		LabelDeclarationPartContext _localctx = new LabelDeclarationPartContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_labelDeclarationPart);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(207);
			match(LABEL);
			setState(208);
			label();
			setState(213);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(209);
				match(COMMA);
				setState(210);
				label();
				}
				}
				setState(215);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(216);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantDefinitionPartContext extends ParserRuleContext {
		public TerminalNode CONST() { return getToken(PascalParser.CONST, 0); }
		public List<ConstantDefinitionContext> constantDefinition() {
			return getRuleContexts(ConstantDefinitionContext.class);
		}
		public ConstantDefinitionContext constantDefinition(int i) {
			return getRuleContext(ConstantDefinitionContext.class,i);
		}
		public List<TerminalNode> SEMICOLON() { return getTokens(PascalParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(PascalParser.SEMICOLON, i);
		}
		public ConstantDefinitionPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constantDefinitionPart; }
	}

	public final ConstantDefinitionPartContext constantDefinitionPart() throws RecognitionException {
		ConstantDefinitionPartContext _localctx = new ConstantDefinitionPartContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_constantDefinitionPart);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(218);
			match(CONST);
			setState(222); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(219);
				constantDefinition();
				setState(220);
				match(SEMICOLON);
				}
				}
				setState(224); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==IDENT );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantDefinitionContext extends ParserRuleContext {
		public ConstantIdentifierContext constantIdentifier() {
			return getRuleContext(ConstantIdentifierContext.class,0);
		}
		public TerminalNode EQUAL() { return getToken(PascalParser.EQUAL, 0); }
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public ConstantDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constantDefinition; }
	}

	public final ConstantDefinitionContext constantDefinition() throws RecognitionException {
		ConstantDefinitionContext _localctx = new ConstantDefinitionContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_constantDefinition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(226);
			constantIdentifier();
			setState(227);
			match(EQUAL);
			setState(228);
			constant();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantIdentifierContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public SymtabEntry * entry = nullptr;
		public TerminalNode IDENT() { return getToken(PascalParser.IDENT, 0); }
		public ConstantIdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constantIdentifier; }
	}

	public final ConstantIdentifierContext constantIdentifier() throws RecognitionException {
		ConstantIdentifierContext _localctx = new ConstantIdentifierContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_constantIdentifier);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(230);
			match(IDENT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeDefinitionPartContext extends ParserRuleContext {
		public TerminalNode TYPE() { return getToken(PascalParser.TYPE, 0); }
		public List<TypeDefinitionContext> typeDefinition() {
			return getRuleContexts(TypeDefinitionContext.class);
		}
		public TypeDefinitionContext typeDefinition(int i) {
			return getRuleContext(TypeDefinitionContext.class,i);
		}
		public List<TerminalNode> SEMICOLON() { return getTokens(PascalParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(PascalParser.SEMICOLON, i);
		}
		public TypeDefinitionPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeDefinitionPart; }
	}

	public final TypeDefinitionPartContext typeDefinitionPart() throws RecognitionException {
		TypeDefinitionPartContext _localctx = new TypeDefinitionPartContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_typeDefinitionPart);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(232);
			match(TYPE);
			setState(236); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(233);
				typeDefinition();
				setState(234);
				match(SEMICOLON);
				}
				}
				setState(238); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BOOLEAN) | (1L << CHAR) | (1L << INTEGER) | (1L << REAL) | (1L << STRING))) != 0) || _la==IDENT );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeDefinitionContext extends ParserRuleContext {
		public TypeIdentifierContext typeIdentifier() {
			return getRuleContext(TypeIdentifierContext.class,0);
		}
		public TerminalNode EQUAL() { return getToken(PascalParser.EQUAL, 0); }
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public FunctionTypeContext functionType() {
			return getRuleContext(FunctionTypeContext.class,0);
		}
		public ProcedureTypeContext procedureType() {
			return getRuleContext(ProcedureTypeContext.class,0);
		}
		public TypeDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeDefinition; }
	}

	public final TypeDefinitionContext typeDefinition() throws RecognitionException {
		TypeDefinitionContext _localctx = new TypeDefinitionContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_typeDefinition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(240);
			typeIdentifier();
			setState(241);
			match(EQUAL);
			setState(245);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ARRAY:
			case BOOLEAN:
			case CHAR:
			case INTEGER:
			case PACKED:
			case REAL:
			case STRING:
			case IDENT:
			case CARAT:
			case LPAREN:
				{
				setState(242);
				type_();
				}
				break;
			case FUNCTION:
				{
				setState(243);
				functionType();
				}
				break;
			case PROCEDURE:
				{
				setState(244);
				procedureType();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FormalParameterListContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public List<FormalParameterSectionContext> formalParameterSection() {
			return getRuleContexts(FormalParameterSectionContext.class);
		}
		public FormalParameterSectionContext formalParameterSection(int i) {
			return getRuleContext(FormalParameterSectionContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public List<TerminalNode> SEMICOLON() { return getTokens(PascalParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(PascalParser.SEMICOLON, i);
		}
		public FormalParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formalParameterList; }
	}

	public final FormalParameterListContext formalParameterList() throws RecognitionException {
		FormalParameterListContext _localctx = new FormalParameterListContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_formalParameterList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(247);
			match(LPAREN);
			setState(248);
			formalParameterSection();
			setState(253);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SEMICOLON) {
				{
				{
				setState(249);
				match(SEMICOLON);
				setState(250);
				formalParameterSection();
				}
				}
				setState(255);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(256);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FormalParameterSectionContext extends ParserRuleContext {
		public ParameterGroupContext parameterGroup() {
			return getRuleContext(ParameterGroupContext.class,0);
		}
		public TerminalNode VAR() { return getToken(PascalParser.VAR, 0); }
		public TerminalNode FUNCTION() { return getToken(PascalParser.FUNCTION, 0); }
		public TerminalNode PROCEDURE() { return getToken(PascalParser.PROCEDURE, 0); }
		public FormalParameterSectionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formalParameterSection; }
	}

	public final FormalParameterSectionContext formalParameterSection() throws RecognitionException {
		FormalParameterSectionContext _localctx = new FormalParameterSectionContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_formalParameterSection);
		try {
			setState(265);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENT:
				enterOuterAlt(_localctx, 1);
				{
				setState(258);
				parameterGroup();
				}
				break;
			case VAR:
				enterOuterAlt(_localctx, 2);
				{
				setState(259);
				match(VAR);
				setState(260);
				parameterGroup();
				}
				break;
			case FUNCTION:
				enterOuterAlt(_localctx, 3);
				{
				setState(261);
				match(FUNCTION);
				setState(262);
				parameterGroup();
				}
				break;
			case PROCEDURE:
				enterOuterAlt(_localctx, 4);
				{
				setState(263);
				match(PROCEDURE);
				setState(264);
				parameterGroup();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterGroupContext extends ParserRuleContext {
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public TypeIdentifierContext typeIdentifier() {
			return getRuleContext(TypeIdentifierContext.class,0);
		}
		public ParameterGroupContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterGroup; }
	}

	public final ParameterGroupContext parameterGroup() throws RecognitionException {
		ParameterGroupContext _localctx = new ParameterGroupContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_parameterGroup);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(267);
			identifierList();
			setState(268);
			match(COLON);
			setState(269);
			typeIdentifier();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionTypeContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public TerminalNode FUNCTION() { return getToken(PascalParser.FUNCTION, 0); }
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public TypeIdentifierContext typeIdentifier() {
			return getRuleContext(TypeIdentifierContext.class,0);
		}
		public FormalParameterListContext formalParameterList() {
			return getRuleContext(FormalParameterListContext.class,0);
		}
		public FunctionTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionType; }
	}

	public final FunctionTypeContext functionType() throws RecognitionException {
		FunctionTypeContext _localctx = new FunctionTypeContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_functionType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(271);
			match(FUNCTION);
			setState(273);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LPAREN) {
				{
				setState(272);
				formalParameterList();
				}
			}

			setState(275);
			match(COLON);
			setState(276);
			typeIdentifier();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcedureTypeContext extends ParserRuleContext {
		public TerminalNode PROCEDURE() { return getToken(PascalParser.PROCEDURE, 0); }
		public FormalParameterListContext formalParameterList() {
			return getRuleContext(FormalParameterListContext.class,0);
		}
		public ProcedureTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procedureType; }
	}

	public final ProcedureTypeContext procedureType() throws RecognitionException {
		ProcedureTypeContext _localctx = new ProcedureTypeContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_procedureType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(278);
			match(PROCEDURE);
			setState(280);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LPAREN) {
				{
				setState(279);
				formalParameterList();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariableDeclarationPartContext extends ParserRuleContext {
		public TerminalNode VAR() { return getToken(PascalParser.VAR, 0); }
		public List<VariableDeclarationContext> variableDeclaration() {
			return getRuleContexts(VariableDeclarationContext.class);
		}
		public VariableDeclarationContext variableDeclaration(int i) {
			return getRuleContext(VariableDeclarationContext.class,i);
		}
		public List<TerminalNode> SEMICOLON() { return getTokens(PascalParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(PascalParser.SEMICOLON, i);
		}
		public VariableDeclarationPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableDeclarationPart; }
	}

	public final VariableDeclarationPartContext variableDeclarationPart() throws RecognitionException {
		VariableDeclarationPartContext _localctx = new VariableDeclarationPartContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_variableDeclarationPart);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(282);
			match(VAR);
			setState(283);
			variableDeclaration();
			setState(288);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(284);
					match(SEMICOLON);
					setState(285);
					variableDeclaration();
					}
					} 
				}
				setState(290);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			setState(291);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariableDeclarationContext extends ParserRuleContext {
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public VariableDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableDeclaration; }
	}

	public final VariableDeclarationContext variableDeclaration() throws RecognitionException {
		VariableDeclarationContext _localctx = new VariableDeclarationContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_variableDeclaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(293);
			identifierList();
			setState(294);
			match(COLON);
			setState(295);
			type_();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcedureAndFunctionDeclarationPartContext extends ParserRuleContext {
		public ProcedureOrFunctionDeclarationContext procedureOrFunctionDeclaration() {
			return getRuleContext(ProcedureOrFunctionDeclarationContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(PascalParser.SEMICOLON, 0); }
		public ProcedureAndFunctionDeclarationPartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procedureAndFunctionDeclarationPart; }
	}

	public final ProcedureAndFunctionDeclarationPartContext procedureAndFunctionDeclarationPart() throws RecognitionException {
		ProcedureAndFunctionDeclarationPartContext _localctx = new ProcedureAndFunctionDeclarationPartContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_procedureAndFunctionDeclarationPart);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(297);
			procedureOrFunctionDeclaration();
			setState(298);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcedureOrFunctionDeclarationContext extends ParserRuleContext {
		public ProcedureDeclarationContext procedureDeclaration() {
			return getRuleContext(ProcedureDeclarationContext.class,0);
		}
		public FunctionDeclarationContext functionDeclaration() {
			return getRuleContext(FunctionDeclarationContext.class,0);
		}
		public ProcedureOrFunctionDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procedureOrFunctionDeclaration; }
	}

	public final ProcedureOrFunctionDeclarationContext procedureOrFunctionDeclaration() throws RecognitionException {
		ProcedureOrFunctionDeclarationContext _localctx = new ProcedureOrFunctionDeclarationContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_procedureOrFunctionDeclaration);
		try {
			setState(302);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PROCEDURE:
				enterOuterAlt(_localctx, 1);
				{
				setState(300);
				procedureDeclaration();
				}
				break;
			case FUNCTION:
				enterOuterAlt(_localctx, 2);
				{
				setState(301);
				functionDeclaration();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcedureDeclarationContext extends ParserRuleContext {
		public SymtabEntry * entry = nullptr;
		public TerminalNode PROCEDURE() { return getToken(PascalParser.PROCEDURE, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(PascalParser.SEMICOLON, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public FormalParameterListContext formalParameterList() {
			return getRuleContext(FormalParameterListContext.class,0);
		}
		public ProcedureDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procedureDeclaration; }
	}

	public final ProcedureDeclarationContext procedureDeclaration() throws RecognitionException {
		ProcedureDeclarationContext _localctx = new ProcedureDeclarationContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_procedureDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(304);
			match(PROCEDURE);
			setState(305);
			identifier();
			setState(307);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LPAREN) {
				{
				setState(306);
				formalParameterList();
				}
			}

			setState(309);
			match(SEMICOLON);
			setState(310);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionDeclarationContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public SymtabEntry * entry = nullptr;
		public TerminalNode FUNCTION() { return getToken(PascalParser.FUNCTION, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public TypeIdentifierContext typeIdentifier() {
			return getRuleContext(TypeIdentifierContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(PascalParser.SEMICOLON, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public FormalParameterListContext formalParameterList() {
			return getRuleContext(FormalParameterListContext.class,0);
		}
		public FunctionDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDeclaration; }
	}

	public final FunctionDeclarationContext functionDeclaration() throws RecognitionException {
		FunctionDeclarationContext _localctx = new FunctionDeclarationContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_functionDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(312);
			match(FUNCTION);
			setState(313);
			identifier();
			setState(315);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LPAREN) {
				{
				setState(314);
				formalParameterList();
				}
			}

			setState(317);
			match(COLON);
			setState(318);
			typeIdentifier();
			setState(319);
			match(SEMICOLON);
			setState(320);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_Context extends ParserRuleContext {
		public Typespec * type = nullptr;
		public SimpleTypeContext simpleType() {
			return getRuleContext(SimpleTypeContext.class,0);
		}
		public StructuredTypeContext structuredType() {
			return getRuleContext(StructuredTypeContext.class,0);
		}
		public PointerTypeContext pointerType() {
			return getRuleContext(PointerTypeContext.class,0);
		}
		public Type_Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_; }
	}

	public final Type_Context type_() throws RecognitionException {
		Type_Context _localctx = new Type_Context(_ctx, getState());
		enterRule(_localctx, 44, RULE_type_);
		try {
			setState(325);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOLEAN:
			case CHAR:
			case INTEGER:
			case REAL:
			case STRING:
			case IDENT:
			case LPAREN:
				enterOuterAlt(_localctx, 1);
				{
				setState(322);
				simpleType();
				}
				break;
			case ARRAY:
			case PACKED:
				enterOuterAlt(_localctx, 2);
				{
				setState(323);
				structuredType();
				}
				break;
			case CARAT:
				enterOuterAlt(_localctx, 3);
				{
				setState(324);
				pointerType();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StructuredTypeContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public TerminalNode PACKED() { return getToken(PascalParser.PACKED, 0); }
		public UnpackedStructuredTypeContext unpackedStructuredType() {
			return getRuleContext(UnpackedStructuredTypeContext.class,0);
		}
		public StructuredTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_structuredType; }
	}

	public final StructuredTypeContext structuredType() throws RecognitionException {
		StructuredTypeContext _localctx = new StructuredTypeContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_structuredType);
		try {
			setState(330);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PACKED:
				enterOuterAlt(_localctx, 1);
				{
				setState(327);
				match(PACKED);
				setState(328);
				unpackedStructuredType();
				}
				break;
			case ARRAY:
				enterOuterAlt(_localctx, 2);
				{
				setState(329);
				unpackedStructuredType();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnpackedStructuredTypeContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public ArrayTypeContext arrayType() {
			return getRuleContext(ArrayTypeContext.class,0);
		}
		public UnpackedStructuredTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unpackedStructuredType; }
	}

	public final UnpackedStructuredTypeContext unpackedStructuredType() throws RecognitionException {
		UnpackedStructuredTypeContext _localctx = new UnpackedStructuredTypeContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_unpackedStructuredType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(332);
			arrayType();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArrayTypeContext extends ParserRuleContext {
		public TerminalNode ARRAY() { return getToken(PascalParser.ARRAY, 0); }
		public TerminalNode LBRACKET() { return getToken(PascalParser.LBRACKET, 0); }
		public TypeListContext typeList() {
			return getRuleContext(TypeListContext.class,0);
		}
		public TerminalNode RBRACKET() { return getToken(PascalParser.RBRACKET, 0); }
		public TerminalNode OF() { return getToken(PascalParser.OF, 0); }
		public Type_Context type_() {
			return getRuleContext(Type_Context.class,0);
		}
		public TerminalNode LBRACKET2() { return getToken(PascalParser.LBRACKET2, 0); }
		public TerminalNode RBRACKET2() { return getToken(PascalParser.RBRACKET2, 0); }
		public ArrayTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayType; }
	}

	public final ArrayTypeContext arrayType() throws RecognitionException {
		ArrayTypeContext _localctx = new ArrayTypeContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_arrayType);
		try {
			setState(348);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(334);
				match(ARRAY);
				setState(335);
				match(LBRACKET);
				setState(336);
				typeList();
				setState(337);
				match(RBRACKET);
				setState(338);
				match(OF);
				setState(339);
				type_();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(341);
				match(ARRAY);
				setState(342);
				match(LBRACKET2);
				setState(343);
				typeList();
				setState(344);
				match(RBRACKET2);
				setState(345);
				match(OF);
				setState(346);
				type_();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeListContext extends ParserRuleContext {
		public List<SimpleTypeContext> simpleType() {
			return getRuleContexts(SimpleTypeContext.class);
		}
		public SimpleTypeContext simpleType(int i) {
			return getRuleContext(SimpleTypeContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public TypeListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeList; }
	}

	public final TypeListContext typeList() throws RecognitionException {
		TypeListContext _localctx = new TypeListContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_typeList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(350);
			simpleType();
			setState(355);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(351);
				match(COMMA);
				setState(352);
				simpleType();
				}
				}
				setState(357);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PointerTypeContext extends ParserRuleContext {
		public TerminalNode CARAT() { return getToken(PascalParser.CARAT, 0); }
		public TypeIdentifierContext typeIdentifier() {
			return getRuleContext(TypeIdentifierContext.class,0);
		}
		public PointerTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pointerType; }
	}

	public final PointerTypeContext pointerType() throws RecognitionException {
		PointerTypeContext _localctx = new PointerTypeContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_pointerType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(358);
			match(CARAT);
			setState(359);
			typeIdentifier();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LabelContext extends ParserRuleContext {
		public UnsignedIntegerContext unsignedInteger() {
			return getRuleContext(UnsignedIntegerContext.class,0);
		}
		public LabelContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_label; }
	}

	public final LabelContext label() throws RecognitionException {
		LabelContext _localctx = new LabelContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_label);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(361);
			unsignedInteger();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantVarContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode EQUAL() { return getToken(PascalParser.EQUAL, 0); }
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public ConstantVarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constantVar; }
	}

	public final ConstantVarContext constantVar() throws RecognitionException {
		ConstantVarContext _localctx = new ConstantVarContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_constantVar);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(363);
			identifier();
			setState(364);
			match(EQUAL);
			setState(365);
			constant();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantChrContext extends ParserRuleContext {
		public TerminalNode CHR() { return getToken(PascalParser.CHR, 0); }
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public UnsignedIntegerContext unsignedInteger() {
			return getRuleContext(UnsignedIntegerContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public ConstantChrContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constantChr; }
	}

	public final ConstantChrContext constantChr() throws RecognitionException {
		ConstantChrContext _localctx = new ConstantChrContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_constantChr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(367);
			match(CHR);
			setState(368);
			match(LPAREN);
			setState(369);
			unsignedInteger();
			setState(370);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstantContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public Object value = nullptr;
		public UnsignedNumberContext unsignedNumber() {
			return getRuleContext(UnsignedNumberContext.class,0);
		}
		public SignContext sign() {
			return getRuleContext(SignContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public StringContext string() {
			return getRuleContext(StringContext.class,0);
		}
		public ConstantChrContext constantChr() {
			return getRuleContext(ConstantChrContext.class,0);
		}
		public ConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant; }
	}

	public final ConstantContext constant() throws RecognitionException {
		ConstantContext _localctx = new ConstantContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_constant);
		try {
			setState(382);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(372);
				unsignedNumber();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(373);
				sign();
				setState(374);
				unsignedNumber();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(376);
				identifier();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(377);
				sign();
				setState(378);
				identifier();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(380);
				string();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(381);
				constantChr();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnsignedNumberContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public UnsignedIntegerContext unsignedInteger() {
			return getRuleContext(UnsignedIntegerContext.class,0);
		}
		public UnsignedRealContext unsignedReal() {
			return getRuleContext(UnsignedRealContext.class,0);
		}
		public UnsignedNumberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unsignedNumber; }
	}

	public final UnsignedNumberContext unsignedNumber() throws RecognitionException {
		UnsignedNumberContext _localctx = new UnsignedNumberContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_unsignedNumber);
		try {
			setState(386);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUM_INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(384);
				unsignedInteger();
				}
				break;
			case NUM_REAL:
				enterOuterAlt(_localctx, 2);
				{
				setState(385);
				unsignedReal();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnsignedIntegerContext extends ParserRuleContext {
		public TerminalNode NUM_INT() { return getToken(PascalParser.NUM_INT, 0); }
		public UnsignedIntegerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unsignedInteger; }
	}

	public final UnsignedIntegerContext unsignedInteger() throws RecognitionException {
		UnsignedIntegerContext _localctx = new UnsignedIntegerContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_unsignedInteger);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(388);
			match(NUM_INT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnsignedRealContext extends ParserRuleContext {
		public TerminalNode NUM_REAL() { return getToken(PascalParser.NUM_REAL, 0); }
		public UnsignedRealContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unsignedReal; }
	}

	public final UnsignedRealContext unsignedReal() throws RecognitionException {
		UnsignedRealContext _localctx = new UnsignedRealContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_unsignedReal);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(390);
			match(NUM_REAL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SignContext extends ParserRuleContext {
		public TerminalNode PLUSOP() { return getToken(PascalParser.PLUSOP, 0); }
		public TerminalNode MINUSOP() { return getToken(PascalParser.MINUSOP, 0); }
		public SignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sign; }
	}

	public final SignContext sign() throws RecognitionException {
		SignContext _localctx = new SignContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_sign);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(392);
			_la = _input.LA(1);
			if ( !(_la==PLUSOP || _la==MINUSOP) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Bool_Context extends ParserRuleContext {
		public TerminalNode TRUE() { return getToken(PascalParser.TRUE, 0); }
		public TerminalNode FALSE() { return getToken(PascalParser.FALSE, 0); }
		public Bool_Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_bool_; }
	}

	public final Bool_Context bool_() throws RecognitionException {
		Bool_Context _localctx = new Bool_Context(_ctx, getState());
		enterRule(_localctx, 72, RULE_bool_);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(394);
			_la = _input.LA(1);
			if ( !(_la==TRUE || _la==FALSE) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeIdentifierContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public SymtabEntry * entry = nullptr;
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode CHAR() { return getToken(PascalParser.CHAR, 0); }
		public TerminalNode BOOLEAN() { return getToken(PascalParser.BOOLEAN, 0); }
		public TerminalNode INTEGER() { return getToken(PascalParser.INTEGER, 0); }
		public TerminalNode REAL() { return getToken(PascalParser.REAL, 0); }
		public TerminalNode STRING() { return getToken(PascalParser.STRING, 0); }
		public TypeIdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeIdentifier; }
	}

	public final TypeIdentifierContext typeIdentifier() throws RecognitionException {
		TypeIdentifierContext _localctx = new TypeIdentifierContext(_ctx, getState());
		enterRule(_localctx, 74, RULE_typeIdentifier);
		int _la;
		try {
			setState(398);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENT:
				enterOuterAlt(_localctx, 1);
				{
				setState(396);
				identifier();
				}
				break;
			case BOOLEAN:
			case CHAR:
			case INTEGER:
			case REAL:
			case STRING:
				enterOuterAlt(_localctx, 2);
				{
				setState(397);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BOOLEAN) | (1L << CHAR) | (1L << INTEGER) | (1L << REAL) | (1L << STRING))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StringContext extends ParserRuleContext {
		public TerminalNode STRING_LITERAL() { return getToken(PascalParser.STRING_LITERAL, 0); }
		public StringContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_string; }
	}

	public final StringContext string() throws RecognitionException {
		StringContext _localctx = new StringContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_string);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(400);
			match(STRING_LITERAL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SimpleTypeContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public ScalarTypeContext scalarType() {
			return getRuleContext(ScalarTypeContext.class,0);
		}
		public TypeIdentifierContext typeIdentifier() {
			return getRuleContext(TypeIdentifierContext.class,0);
		}
		public StringtypeContext stringtype() {
			return getRuleContext(StringtypeContext.class,0);
		}
		public SimpleTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleType; }
	}

	public final SimpleTypeContext simpleType() throws RecognitionException {
		SimpleTypeContext _localctx = new SimpleTypeContext(_ctx, getState());
		enterRule(_localctx, 78, RULE_simpleType);
		try {
			setState(405);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(402);
				scalarType();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(403);
				typeIdentifier();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(404);
				stringtype();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ScalarTypeContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public ScalarTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scalarType; }
	}

	public final ScalarTypeContext scalarType() throws RecognitionException {
		ScalarTypeContext _localctx = new ScalarTypeContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_scalarType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(407);
			match(LPAREN);
			setState(408);
			identifierList();
			setState(409);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StringtypeContext extends ParserRuleContext {
		public TerminalNode STRING() { return getToken(PascalParser.STRING, 0); }
		public TerminalNode LBRACKET() { return getToken(PascalParser.LBRACKET, 0); }
		public TerminalNode RBRACKET() { return getToken(PascalParser.RBRACKET, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public UnsignedNumberContext unsignedNumber() {
			return getRuleContext(UnsignedNumberContext.class,0);
		}
		public StringtypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stringtype; }
	}

	public final StringtypeContext stringtype() throws RecognitionException {
		StringtypeContext _localctx = new StringtypeContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_stringtype);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(411);
			match(STRING);
			setState(412);
			match(LBRACKET);
			setState(415);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENT:
				{
				setState(413);
				identifier();
				}
				break;
			case NUM_INT:
			case NUM_REAL:
				{
				setState(414);
				unsignedNumber();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(417);
			match(RBRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdentifierListContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public IdentifierListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifierList; }
	}

	public final IdentifierListContext identifierList() throws RecognitionException {
		IdentifierListContext _localctx = new IdentifierListContext(_ctx, getState());
		enterRule(_localctx, 84, RULE_identifierList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(419);
			identifier();
			setState(424);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(420);
				match(COMMA);
				setState(421);
				identifier();
				}
				}
				setState(426);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public LabelContext label() {
			return getRuleContext(LabelContext.class,0);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public UnlabelledStatementContext unlabelledStatement() {
			return getRuleContext(UnlabelledStatementContext.class,0);
		}
		public ProcedureAndFunctionDeclarationPartContext procedureAndFunctionDeclarationPart() {
			return getRuleContext(ProcedureAndFunctionDeclarationPartContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_statement);
		try {
			setState(433);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUM_INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(427);
				label();
				setState(428);
				match(COLON);
				setState(429);
				unlabelledStatement();
				}
				break;
			case BEGIN:
			case CASE:
			case ELSE:
			case END:
			case FOR:
			case GOTO:
			case IF:
			case WRITE:
			case WRITELN:
			case REPEAT:
			case UNTIL:
			case WHILE:
			case WITH:
			case AT:
			case IDENT:
			case SEMICOLON:
				enterOuterAlt(_localctx, 2);
				{
				setState(431);
				unlabelledStatement();
				}
				break;
			case FUNCTION:
			case PROCEDURE:
				enterOuterAlt(_localctx, 3);
				{
				setState(432);
				procedureAndFunctionDeclarationPart();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnlabelledStatementContext extends ParserRuleContext {
		public SimpleStatementContext simpleStatement() {
			return getRuleContext(SimpleStatementContext.class,0);
		}
		public StructuredStatementContext structuredStatement() {
			return getRuleContext(StructuredStatementContext.class,0);
		}
		public UnlabelledStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unlabelledStatement; }
	}

	public final UnlabelledStatementContext unlabelledStatement() throws RecognitionException {
		UnlabelledStatementContext _localctx = new UnlabelledStatementContext(_ctx, getState());
		enterRule(_localctx, 88, RULE_unlabelledStatement);
		try {
			setState(437);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ELSE:
			case END:
			case GOTO:
			case UNTIL:
			case AT:
			case IDENT:
			case SEMICOLON:
				enterOuterAlt(_localctx, 1);
				{
				setState(435);
				simpleStatement();
				}
				break;
			case BEGIN:
			case CASE:
			case FOR:
			case IF:
			case WRITE:
			case WRITELN:
			case REPEAT:
			case WHILE:
			case WITH:
				enterOuterAlt(_localctx, 2);
				{
				setState(436);
				structuredStatement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SimpleStatementContext extends ParserRuleContext {
		public AssignmentStatementContext assignmentStatement() {
			return getRuleContext(AssignmentStatementContext.class,0);
		}
		public ProcedureStatementContext procedureStatement() {
			return getRuleContext(ProcedureStatementContext.class,0);
		}
		public GotoStatementContext gotoStatement() {
			return getRuleContext(GotoStatementContext.class,0);
		}
		public EmptyStatement_Context emptyStatement_() {
			return getRuleContext(EmptyStatement_Context.class,0);
		}
		public SimpleStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleStatement; }
	}

	public final SimpleStatementContext simpleStatement() throws RecognitionException {
		SimpleStatementContext _localctx = new SimpleStatementContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_simpleStatement);
		try {
			setState(443);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,28,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(439);
				assignmentStatement();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(440);
				procedureStatement();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(441);
				gotoStatement();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(442);
				emptyStatement_();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ProcedureStatementContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public ProcedureStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_procedureStatement; }
	}

	public final ProcedureStatementContext procedureStatement() throws RecognitionException {
		ProcedureStatementContext _localctx = new ProcedureStatementContext(_ctx, getState());
		enterRule(_localctx, 92, RULE_procedureStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(445);
			identifier();
			setState(450);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LPAREN) {
				{
				setState(446);
				match(LPAREN);
				setState(447);
				parameterList();
				setState(448);
				match(RPAREN);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class EmptyStatement_Context extends ParserRuleContext {
		public EmptyStatement_Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_emptyStatement_; }
	}

	public final EmptyStatement_Context emptyStatement_() throws RecognitionException {
		EmptyStatement_Context _localctx = new EmptyStatement_Context(_ctx, getState());
		enterRule(_localctx, 94, RULE_emptyStatement_);
		try {
			enterOuterAlt(_localctx, 1);
			{
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignmentStatementContext extends ParserRuleContext {
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(PascalParser.ASSIGN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public AssignmentStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignmentStatement; }
	}

	public final AssignmentStatementContext assignmentStatement() throws RecognitionException {
		AssignmentStatementContext _localctx = new AssignmentStatementContext(_ctx, getState());
		enterRule(_localctx, 96, RULE_assignmentStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(454);
			variable();
			setState(455);
			match(ASSIGN);
			setState(456);
			expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariableContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public SymtabEntry * entry = nullptr;
		public TerminalNode AT() { return getToken(PascalParser.AT, 0); }
		public VariableIdentifierContext variableIdentifier() {
			return getRuleContext(VariableIdentifierContext.class,0);
		}
		public List<ModifierContext> modifier() {
			return getRuleContexts(ModifierContext.class);
		}
		public ModifierContext modifier(int i) {
			return getRuleContext(ModifierContext.class,i);
		}
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 98, RULE_variable);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(461);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case AT:
				{
				setState(458);
				match(AT);
				setState(459);
				variableIdentifier();
				}
				break;
			case IDENT:
				{
				setState(460);
				variableIdentifier();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(466);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 55)) & ~0x3f) == 0 && ((1L << (_la - 55)) & ((1L << (LBRACKET2 - 55)) | (1L << (DOT - 55)) | (1L << (CARAT - 55)) | (1L << (LBRACKET - 55)))) != 0)) {
				{
				{
				setState(463);
				modifier();
				}
				}
				setState(468);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariableIdentifierContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public SymtabEntry * entry = nullptr;
		public TerminalNode IDENT() { return getToken(PascalParser.IDENT, 0); }
		public VariableIdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableIdentifier; }
	}

	public final VariableIdentifierContext variableIdentifier() throws RecognitionException {
		VariableIdentifierContext _localctx = new VariableIdentifierContext(_ctx, getState());
		enterRule(_localctx, 100, RULE_variableIdentifier);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(469);
			match(IDENT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ModifierContext extends ParserRuleContext {
		public TerminalNode LBRACKET() { return getToken(PascalParser.LBRACKET, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode RBRACKET() { return getToken(PascalParser.RBRACKET, 0); }
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public TerminalNode LBRACKET2() { return getToken(PascalParser.LBRACKET2, 0); }
		public TerminalNode RBRACKET2() { return getToken(PascalParser.RBRACKET2, 0); }
		public TerminalNode DOT() { return getToken(PascalParser.DOT, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode CARAT() { return getToken(PascalParser.CARAT, 0); }
		public ModifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_modifier; }
	}

	public final ModifierContext modifier() throws RecognitionException {
		ModifierContext _localctx = new ModifierContext(_ctx, getState());
		enterRule(_localctx, 102, RULE_modifier);
		int _la;
		try {
			setState(496);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LBRACKET:
				enterOuterAlt(_localctx, 1);
				{
				setState(471);
				match(LBRACKET);
				setState(472);
				expression();
				setState(477);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(473);
					match(COMMA);
					setState(474);
					expression();
					}
					}
					setState(479);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(480);
				match(RBRACKET);
				}
				break;
			case LBRACKET2:
				enterOuterAlt(_localctx, 2);
				{
				setState(482);
				match(LBRACKET2);
				setState(483);
				expression();
				setState(488);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(484);
					match(COMMA);
					setState(485);
					expression();
					}
					}
					setState(490);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(491);
				match(RBRACKET2);
				}
				break;
			case DOT:
				enterOuterAlt(_localctx, 3);
				{
				setState(493);
				match(DOT);
				setState(494);
				identifier();
				}
				break;
			case CARAT:
				enterOuterAlt(_localctx, 4);
				{
				setState(495);
				match(CARAT);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public SimpleExpressionContext simpleExpression() {
			return getRuleContext(SimpleExpressionContext.class,0);
		}
		public List<RelationaloperatorContext> relationaloperator() {
			return getRuleContexts(RelationaloperatorContext.class);
		}
		public RelationaloperatorContext relationaloperator(int i) {
			return getRuleContext(RelationaloperatorContext.class,i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 104, RULE_expression);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(498);
			simpleExpression();
			setState(504);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,35,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(499);
					relationaloperator();
					setState(500);
					expression();
					}
					} 
				}
				setState(506);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,35,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RelationaloperatorContext extends ParserRuleContext {
		public TerminalNode EQUAL() { return getToken(PascalParser.EQUAL, 0); }
		public TerminalNode NE() { return getToken(PascalParser.NE, 0); }
		public TerminalNode LT() { return getToken(PascalParser.LT, 0); }
		public TerminalNode LTEQ() { return getToken(PascalParser.LTEQ, 0); }
		public TerminalNode GTEQ() { return getToken(PascalParser.GTEQ, 0); }
		public TerminalNode GT() { return getToken(PascalParser.GT, 0); }
		public TerminalNode IN() { return getToken(PascalParser.IN, 0); }
		public RelationaloperatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relationaloperator; }
	}

	public final RelationaloperatorContext relationaloperator() throws RecognitionException {
		RelationaloperatorContext _localctx = new RelationaloperatorContext(_ctx, getState());
		enterRule(_localctx, 106, RULE_relationaloperator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(507);
			_la = _input.LA(1);
			if ( !(((((_la - 24)) & ~0x3f) == 0 && ((1L << (_la - 24)) & ((1L << (IN - 24)) | (1L << (EQUAL - 24)) | (1L << (NE - 24)) | (1L << (LTEQ - 24)) | (1L << (GTEQ - 24)) | (1L << (LT - 24)) | (1L << (GT - 24)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SimpleExpressionContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public List<AdditiveoperatorContext> additiveoperator() {
			return getRuleContexts(AdditiveoperatorContext.class);
		}
		public AdditiveoperatorContext additiveoperator(int i) {
			return getRuleContext(AdditiveoperatorContext.class,i);
		}
		public List<SimpleExpressionContext> simpleExpression() {
			return getRuleContexts(SimpleExpressionContext.class);
		}
		public SimpleExpressionContext simpleExpression(int i) {
			return getRuleContext(SimpleExpressionContext.class,i);
		}
		public SimpleExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleExpression; }
	}

	public final SimpleExpressionContext simpleExpression() throws RecognitionException {
		SimpleExpressionContext _localctx = new SimpleExpressionContext(_ctx, getState());
		enterRule(_localctx, 108, RULE_simpleExpression);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(509);
			term();
			setState(515);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,36,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(510);
					additiveoperator();
					setState(511);
					simpleExpression();
					}
					} 
				}
				setState(517);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,36,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AdditiveoperatorContext extends ParserRuleContext {
		public TerminalNode PLUSOP() { return getToken(PascalParser.PLUSOP, 0); }
		public TerminalNode MINUSOP() { return getToken(PascalParser.MINUSOP, 0); }
		public TerminalNode OR() { return getToken(PascalParser.OR, 0); }
		public AdditiveoperatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_additiveoperator; }
	}

	public final AdditiveoperatorContext additiveoperator() throws RecognitionException {
		AdditiveoperatorContext _localctx = new AdditiveoperatorContext(_ctx, getState());
		enterRule(_localctx, 110, RULE_additiveoperator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(518);
			_la = _input.LA(1);
			if ( !(((((_la - 37)) & ~0x3f) == 0 && ((1L << (_la - 37)) & ((1L << (OR - 37)) | (1L << (PLUSOP - 37)) | (1L << (MINUSOP - 37)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TermContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public SignedFactorContext signedFactor() {
			return getRuleContext(SignedFactorContext.class,0);
		}
		public List<MultiplicativeoperatorContext> multiplicativeoperator() {
			return getRuleContexts(MultiplicativeoperatorContext.class);
		}
		public MultiplicativeoperatorContext multiplicativeoperator(int i) {
			return getRuleContext(MultiplicativeoperatorContext.class,i);
		}
		public List<TermContext> term() {
			return getRuleContexts(TermContext.class);
		}
		public TermContext term(int i) {
			return getRuleContext(TermContext.class,i);
		}
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		TermContext _localctx = new TermContext(_ctx, getState());
		enterRule(_localctx, 112, RULE_term);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(520);
			signedFactor();
			setState(526);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(521);
					multiplicativeoperator();
					setState(522);
					term();
					}
					} 
				}
				setState(528);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,37,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MultiplicativeoperatorContext extends ParserRuleContext {
		public TerminalNode MULTOP() { return getToken(PascalParser.MULTOP, 0); }
		public TerminalNode DIVOP() { return getToken(PascalParser.DIVOP, 0); }
		public TerminalNode DIV() { return getToken(PascalParser.DIV, 0); }
		public TerminalNode MOD() { return getToken(PascalParser.MOD, 0); }
		public TerminalNode AND() { return getToken(PascalParser.AND, 0); }
		public MultiplicativeoperatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multiplicativeoperator; }
	}

	public final MultiplicativeoperatorContext multiplicativeoperator() throws RecognitionException {
		MultiplicativeoperatorContext _localctx = new MultiplicativeoperatorContext(_ctx, getState());
		enterRule(_localctx, 114, RULE_multiplicativeoperator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(529);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << AND) | (1L << DIV) | (1L << MOD))) != 0) || _la==MULTOP || _la==DIVOP) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SignedFactorContext extends ParserRuleContext {
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public TerminalNode PLUSOP() { return getToken(PascalParser.PLUSOP, 0); }
		public TerminalNode MINUSOP() { return getToken(PascalParser.MINUSOP, 0); }
		public SignedFactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_signedFactor; }
	}

	public final SignedFactorContext signedFactor() throws RecognitionException {
		SignedFactorContext _localctx = new SignedFactorContext(_ctx, getState());
		enterRule(_localctx, 116, RULE_signedFactor);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(532);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==PLUSOP || _la==MINUSOP) {
				{
				setState(531);
				_la = _input.LA(1);
				if ( !(_la==PLUSOP || _la==MINUSOP) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
			}

			setState(534);
			factor();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FactorContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public FunctionDesignatorContext functionDesignator() {
			return getRuleContext(FunctionDesignatorContext.class,0);
		}
		public UnsignedConstantContext unsignedConstant() {
			return getRuleContext(UnsignedConstantContext.class,0);
		}
		public Set_Context set_() {
			return getRuleContext(Set_Context.class,0);
		}
		public TerminalNode NOT() { return getToken(PascalParser.NOT, 0); }
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public Bool_Context bool_() {
			return getRuleContext(Bool_Context.class,0);
		}
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 118, RULE_factor);
		try {
			setState(547);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,39,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(536);
				variable();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(537);
				match(LPAREN);
				setState(538);
				expression();
				setState(539);
				match(RPAREN);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(541);
				functionDesignator();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(542);
				unsignedConstant();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(543);
				set_();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(544);
				match(NOT);
				setState(545);
				factor();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(546);
				bool_();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnsignedConstantContext extends ParserRuleContext {
		public Typespec * type = nullptr;
		public UnsignedNumberContext unsignedNumber() {
			return getRuleContext(UnsignedNumberContext.class,0);
		}
		public ConstantChrContext constantChr() {
			return getRuleContext(ConstantChrContext.class,0);
		}
		public StringContext string() {
			return getRuleContext(StringContext.class,0);
		}
		public TerminalNode NIL() { return getToken(PascalParser.NIL, 0); }
		public UnsignedConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unsignedConstant; }
	}

	public final UnsignedConstantContext unsignedConstant() throws RecognitionException {
		UnsignedConstantContext _localctx = new UnsignedConstantContext(_ctx, getState());
		enterRule(_localctx, 120, RULE_unsignedConstant);
		try {
			setState(553);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUM_INT:
			case NUM_REAL:
				enterOuterAlt(_localctx, 1);
				{
				setState(549);
				unsignedNumber();
				}
				break;
			case CHR:
				enterOuterAlt(_localctx, 2);
				{
				setState(550);
				constantChr();
				}
				break;
			case STRING_LITERAL:
				enterOuterAlt(_localctx, 3);
				{
				setState(551);
				string();
				}
				break;
			case NIL:
				enterOuterAlt(_localctx, 4);
				{
				setState(552);
				match(NIL);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionDesignatorContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public FunctionDesignatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDesignator; }
	}

	public final FunctionDesignatorContext functionDesignator() throws RecognitionException {
		FunctionDesignatorContext _localctx = new FunctionDesignatorContext(_ctx, getState());
		enterRule(_localctx, 122, RULE_functionDesignator);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(555);
			identifier();
			setState(556);
			match(LPAREN);
			setState(557);
			parameterList();
			setState(558);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterListContext extends ParserRuleContext {
		public List<ActualParameterContext> actualParameter() {
			return getRuleContexts(ActualParameterContext.class);
		}
		public ActualParameterContext actualParameter(int i) {
			return getRuleContext(ActualParameterContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public ParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterList; }
	}

	public final ParameterListContext parameterList() throws RecognitionException {
		ParameterListContext _localctx = new ParameterListContext(_ctx, getState());
		enterRule(_localctx, 124, RULE_parameterList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(560);
			actualParameter();
			setState(565);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(561);
				match(COMMA);
				setState(562);
				actualParameter();
				}
				}
				setState(567);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ActualParameterContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<ParameterwidthContext> parameterwidth() {
			return getRuleContexts(ParameterwidthContext.class);
		}
		public ParameterwidthContext parameterwidth(int i) {
			return getRuleContext(ParameterwidthContext.class,i);
		}
		public ActualParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_actualParameter; }
	}

	public final ActualParameterContext actualParameter() throws RecognitionException {
		ActualParameterContext _localctx = new ActualParameterContext(_ctx, getState());
		enterRule(_localctx, 126, RULE_actualParameter);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(568);
			expression();
			setState(572);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COLON) {
				{
				{
				setState(569);
				parameterwidth();
				}
				}
				setState(574);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterwidthContext extends ParserRuleContext {
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ParameterwidthContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterwidth; }
	}

	public final ParameterwidthContext parameterwidth() throws RecognitionException {
		ParameterwidthContext _localctx = new ParameterwidthContext(_ctx, getState());
		enterRule(_localctx, 128, RULE_parameterwidth);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(575);
			match(COLON);
			setState(576);
			expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Set_Context extends ParserRuleContext {
		public TerminalNode LBRACKET() { return getToken(PascalParser.LBRACKET, 0); }
		public List<ElementContext> element() {
			return getRuleContexts(ElementContext.class);
		}
		public ElementContext element(int i) {
			return getRuleContext(ElementContext.class,i);
		}
		public TerminalNode RBRACKET() { return getToken(PascalParser.RBRACKET, 0); }
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public TerminalNode LBRACKET2() { return getToken(PascalParser.LBRACKET2, 0); }
		public TerminalNode RBRACKET2() { return getToken(PascalParser.RBRACKET2, 0); }
		public Set_Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_set_; }
	}

	public final Set_Context set_() throws RecognitionException {
		Set_Context _localctx = new Set_Context(_ctx, getState());
		enterRule(_localctx, 130, RULE_set_);
		int _la;
		try {
			setState(600);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LBRACKET:
				enterOuterAlt(_localctx, 1);
				{
				setState(578);
				match(LBRACKET);
				setState(579);
				element();
				setState(584);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(580);
					match(COMMA);
					setState(581);
					element();
					}
					}
					setState(586);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(587);
				match(RBRACKET);
				}
				break;
			case LBRACKET2:
				enterOuterAlt(_localctx, 2);
				{
				setState(589);
				match(LBRACKET2);
				setState(590);
				element();
				setState(595);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(591);
					match(COMMA);
					setState(592);
					element();
					}
					}
					setState(597);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(598);
				match(RBRACKET2);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ElementContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode DOTDOT() { return getToken(PascalParser.DOTDOT, 0); }
		public ElementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_element; }
	}

	public final ElementContext element() throws RecognitionException {
		ElementContext _localctx = new ElementContext(_ctx, getState());
		enterRule(_localctx, 132, RULE_element);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(602);
			expression();
			setState(605);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==DOTDOT) {
				{
				setState(603);
				match(DOTDOT);
				setState(604);
				expression();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class GotoStatementContext extends ParserRuleContext {
		public TerminalNode GOTO() { return getToken(PascalParser.GOTO, 0); }
		public LabelContext label() {
			return getRuleContext(LabelContext.class,0);
		}
		public GotoStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_gotoStatement; }
	}

	public final GotoStatementContext gotoStatement() throws RecognitionException {
		GotoStatementContext _localctx = new GotoStatementContext(_ctx, getState());
		enterRule(_localctx, 134, RULE_gotoStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(607);
			match(GOTO);
			setState(608);
			label();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StructuredStatementContext extends ParserRuleContext {
		public CompoundStatementContext compoundStatement() {
			return getRuleContext(CompoundStatementContext.class,0);
		}
		public ReptitiveStatementContext reptitiveStatement() {
			return getRuleContext(ReptitiveStatementContext.class,0);
		}
		public IfStatementContext ifStatement() {
			return getRuleContext(IfStatementContext.class,0);
		}
		public CaseStatementContext caseStatement() {
			return getRuleContext(CaseStatementContext.class,0);
		}
		public WithStatementContext withStatement() {
			return getRuleContext(WithStatementContext.class,0);
		}
		public WriteStatementContext writeStatement() {
			return getRuleContext(WriteStatementContext.class,0);
		}
		public WritelnStatementContext writelnStatement() {
			return getRuleContext(WritelnStatementContext.class,0);
		}
		public StructuredStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_structuredStatement; }
	}

	public final StructuredStatementContext structuredStatement() throws RecognitionException {
		StructuredStatementContext _localctx = new StructuredStatementContext(_ctx, getState());
		enterRule(_localctx, 136, RULE_structuredStatement);
		try {
			setState(617);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BEGIN:
				enterOuterAlt(_localctx, 1);
				{
				setState(610);
				compoundStatement();
				}
				break;
			case FOR:
			case REPEAT:
			case WHILE:
				enterOuterAlt(_localctx, 2);
				{
				setState(611);
				reptitiveStatement();
				}
				break;
			case IF:
				enterOuterAlt(_localctx, 3);
				{
				setState(612);
				ifStatement();
				}
				break;
			case CASE:
				enterOuterAlt(_localctx, 4);
				{
				setState(613);
				caseStatement();
				}
				break;
			case WITH:
				enterOuterAlt(_localctx, 5);
				{
				setState(614);
				withStatement();
				}
				break;
			case WRITE:
				enterOuterAlt(_localctx, 6);
				{
				setState(615);
				writeStatement();
				}
				break;
			case WRITELN:
				enterOuterAlt(_localctx, 7);
				{
				setState(616);
				writelnStatement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ReptitiveStatementContext extends ParserRuleContext {
		public WhileStatementContext whileStatement() {
			return getRuleContext(WhileStatementContext.class,0);
		}
		public RepeatStatementContext repeatStatement() {
			return getRuleContext(RepeatStatementContext.class,0);
		}
		public ForStatementContext forStatement() {
			return getRuleContext(ForStatementContext.class,0);
		}
		public ReptitiveStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_reptitiveStatement; }
	}

	public final ReptitiveStatementContext reptitiveStatement() throws RecognitionException {
		ReptitiveStatementContext _localctx = new ReptitiveStatementContext(_ctx, getState());
		enterRule(_localctx, 138, RULE_reptitiveStatement);
		try {
			setState(622);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case WHILE:
				enterOuterAlt(_localctx, 1);
				{
				setState(619);
				whileStatement();
				}
				break;
			case REPEAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(620);
				repeatStatement();
				}
				break;
			case FOR:
				enterOuterAlt(_localctx, 3);
				{
				setState(621);
				forStatement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WriteArgumentsContext extends ParserRuleContext {
		public List<WriteArgsContext> writeArgs() {
			return getRuleContexts(WriteArgsContext.class);
		}
		public WriteArgsContext writeArgs(int i) {
			return getRuleContext(WriteArgsContext.class,i);
		}
		public TerminalNode COMMA() { return getToken(PascalParser.COMMA, 0); }
		public WriteArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_writeArguments; }
	}

	public final WriteArgumentsContext writeArguments() throws RecognitionException {
		WriteArgumentsContext _localctx = new WriteArgumentsContext(_ctx, getState());
		enterRule(_localctx, 140, RULE_writeArguments);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(624);
			writeArgs();
			setState(627);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(625);
				match(COMMA);
				setState(626);
				writeArgs();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WriteArgsContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public WriteArgsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_writeArgs; }
	}

	public final WriteArgsContext writeArgs() throws RecognitionException {
		WriteArgsContext _localctx = new WriteArgsContext(_ctx, getState());
		enterRule(_localctx, 142, RULE_writeArgs);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(629);
			expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WriteStatementContext extends ParserRuleContext {
		public TerminalNode WRITE() { return getToken(PascalParser.WRITE, 0); }
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public WriteArgumentsContext writeArguments() {
			return getRuleContext(WriteArgumentsContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public WriteStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_writeStatement; }
	}

	public final WriteStatementContext writeStatement() throws RecognitionException {
		WriteStatementContext _localctx = new WriteStatementContext(_ctx, getState());
		enterRule(_localctx, 144, RULE_writeStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(631);
			match(WRITE);
			setState(632);
			match(LPAREN);
			setState(633);
			writeArguments();
			setState(634);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WritelnStatementContext extends ParserRuleContext {
		public TerminalNode WRITELN() { return getToken(PascalParser.WRITELN, 0); }
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public WriteArgumentsContext writeArguments() {
			return getRuleContext(WriteArgumentsContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public WritelnStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_writelnStatement; }
	}

	public final WritelnStatementContext writelnStatement() throws RecognitionException {
		WritelnStatementContext _localctx = new WritelnStatementContext(_ctx, getState());
		enterRule(_localctx, 146, RULE_writelnStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(636);
			match(WRITELN);
			setState(637);
			match(LPAREN);
			setState(638);
			writeArguments();
			setState(639);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CompoundStatementContext extends ParserRuleContext {
		public TerminalNode BEGIN() { return getToken(PascalParser.BEGIN, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode END() { return getToken(PascalParser.END, 0); }
		public CompoundStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compoundStatement; }
	}

	public final CompoundStatementContext compoundStatement() throws RecognitionException {
		CompoundStatementContext _localctx = new CompoundStatementContext(_ctx, getState());
		enterRule(_localctx, 148, RULE_compoundStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(641);
			match(BEGIN);
			setState(642);
			statements();
			setState(643);
			match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementsContext extends ParserRuleContext {
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public List<TerminalNode> SEMICOLON() { return getTokens(PascalParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(PascalParser.SEMICOLON, i);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		StatementsContext _localctx = new StatementsContext(_ctx, getState());
		enterRule(_localctx, 150, RULE_statements);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(645);
			statement();
			setState(650);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SEMICOLON) {
				{
				{
				setState(646);
				match(SEMICOLON);
				setState(647);
				statement();
				}
				}
				setState(652);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IfStatementContext extends ParserRuleContext {
		public TerminalNode IF() { return getToken(PascalParser.IF, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode THEN() { return getToken(PascalParser.THEN, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(PascalParser.ELSE, 0); }
		public IfStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifStatement; }
	}

	public final IfStatementContext ifStatement() throws RecognitionException {
		IfStatementContext _localctx = new IfStatementContext(_ctx, getState());
		enterRule(_localctx, 152, RULE_ifStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(653);
			match(IF);
			setState(654);
			expression();
			setState(655);
			match(THEN);
			setState(656);
			statement();
			setState(659);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,51,_ctx) ) {
			case 1:
				{
				setState(657);
				match(ELSE);
				setState(658);
				statement();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CaseStatementContext extends ParserRuleContext {
		public TerminalNode CASE() { return getToken(PascalParser.CASE, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode OF() { return getToken(PascalParser.OF, 0); }
		public List<CaseListElementContext> caseListElement() {
			return getRuleContexts(CaseListElementContext.class);
		}
		public CaseListElementContext caseListElement(int i) {
			return getRuleContext(CaseListElementContext.class,i);
		}
		public TerminalNode END() { return getToken(PascalParser.END, 0); }
		public List<TerminalNode> SEMICOLON() { return getTokens(PascalParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(PascalParser.SEMICOLON, i);
		}
		public TerminalNode ELSE() { return getToken(PascalParser.ELSE, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public CaseStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_caseStatement; }
	}

	public final CaseStatementContext caseStatement() throws RecognitionException {
		CaseStatementContext _localctx = new CaseStatementContext(_ctx, getState());
		enterRule(_localctx, 154, RULE_caseStatement);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(661);
			match(CASE);
			setState(662);
			expression();
			setState(663);
			match(OF);
			setState(664);
			caseListElement();
			setState(669);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,52,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(665);
					match(SEMICOLON);
					setState(666);
					caseListElement();
					}
					} 
				}
				setState(671);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,52,_ctx);
			}
			setState(675);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SEMICOLON) {
				{
				setState(672);
				match(SEMICOLON);
				setState(673);
				match(ELSE);
				setState(674);
				statements();
				}
			}

			setState(677);
			match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CaseListElementContext extends ParserRuleContext {
		public List<ConstantContext> constant() {
			return getRuleContexts(ConstantContext.class);
		}
		public ConstantContext constant(int i) {
			return getRuleContext(ConstantContext.class,i);
		}
		public TerminalNode COLON() { return getToken(PascalParser.COLON, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public CaseListElementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_caseListElement; }
	}

	public final CaseListElementContext caseListElement() throws RecognitionException {
		CaseListElementContext _localctx = new CaseListElementContext(_ctx, getState());
		enterRule(_localctx, 156, RULE_caseListElement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(679);
			constant();
			setState(684);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(680);
				match(COMMA);
				setState(681);
				constant();
				}
				}
				setState(686);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(687);
			match(COLON);
			setState(688);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhileStatementContext extends ParserRuleContext {
		public TerminalNode WHILE() { return getToken(PascalParser.WHILE, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode DO() { return getToken(PascalParser.DO, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public WhileStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileStatement; }
	}

	public final WhileStatementContext whileStatement() throws RecognitionException {
		WhileStatementContext _localctx = new WhileStatementContext(_ctx, getState());
		enterRule(_localctx, 158, RULE_whileStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(690);
			match(WHILE);
			setState(691);
			expression();
			setState(692);
			match(DO);
			setState(693);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RepeatStatementContext extends ParserRuleContext {
		public TerminalNode REPEAT() { return getToken(PascalParser.REPEAT, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode UNTIL() { return getToken(PascalParser.UNTIL, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public RepeatStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_repeatStatement; }
	}

	public final RepeatStatementContext repeatStatement() throws RecognitionException {
		RepeatStatementContext _localctx = new RepeatStatementContext(_ctx, getState());
		enterRule(_localctx, 160, RULE_repeatStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(695);
			match(REPEAT);
			setState(696);
			statements();
			setState(697);
			match(UNTIL);
			setState(698);
			expression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ForStatementContext extends ParserRuleContext {
		public TerminalNode FOR() { return getToken(PascalParser.FOR, 0); }
		public AssignmentStatementContext assignmentStatement() {
			return getRuleContext(AssignmentStatementContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode DO() { return getToken(PascalParser.DO, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public TerminalNode TO() { return getToken(PascalParser.TO, 0); }
		public TerminalNode DOWNTO() { return getToken(PascalParser.DOWNTO, 0); }
		public ForStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forStatement; }
	}

	public final ForStatementContext forStatement() throws RecognitionException {
		ForStatementContext _localctx = new ForStatementContext(_ctx, getState());
		enterRule(_localctx, 162, RULE_forStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(700);
			match(FOR);
			setState(701);
			assignmentStatement();
			setState(702);
			_la = _input.LA(1);
			if ( !(_la==DOWNTO || _la==TO) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(703);
			expression();
			setState(704);
			match(DO);
			setState(705);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WithStatementContext extends ParserRuleContext {
		public TerminalNode WITH() { return getToken(PascalParser.WITH, 0); }
		public List<VariableContext> variable() {
			return getRuleContexts(VariableContext.class);
		}
		public VariableContext variable(int i) {
			return getRuleContext(VariableContext.class,i);
		}
		public TerminalNode DO() { return getToken(PascalParser.DO, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public WithStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_withStatement; }
	}

	public final WithStatementContext withStatement() throws RecognitionException {
		WithStatementContext _localctx = new WithStatementContext(_ctx, getState());
		enterRule(_localctx, 164, RULE_withStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(707);
			match(WITH);
			setState(708);
			variable();
			setState(713);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(709);
				match(COMMA);
				setState(710);
				variable();
				}
				}
				setState(715);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(716);
			match(DO);
			setState(717);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3g\u02d2\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="+
		"\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\4C\tC\4D\tD\4E\tE\4F\tF\4G\tG\4H\tH\4I"+
		"\tI\4J\tJ\4K\tK\4L\tL\4M\tM\4N\tN\4O\tO\4P\tP\4Q\tQ\4R\tR\4S\tS\4T\tT"+
		"\3\2\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\5\3\u00b4\n\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\5\3\u00bc\n\3\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\7\5\u00c7"+
		"\n\5\f\5\16\5\u00ca\13\5\3\5\3\5\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\7\7\u00d6"+
		"\n\7\f\7\16\7\u00d9\13\7\3\7\3\7\3\b\3\b\3\b\3\b\6\b\u00e1\n\b\r\b\16"+
		"\b\u00e2\3\t\3\t\3\t\3\t\3\n\3\n\3\13\3\13\3\13\3\13\6\13\u00ef\n\13\r"+
		"\13\16\13\u00f0\3\f\3\f\3\f\3\f\3\f\5\f\u00f8\n\f\3\r\3\r\3\r\3\r\7\r"+
		"\u00fe\n\r\f\r\16\r\u0101\13\r\3\r\3\r\3\16\3\16\3\16\3\16\3\16\3\16\3"+
		"\16\5\16\u010c\n\16\3\17\3\17\3\17\3\17\3\20\3\20\5\20\u0114\n\20\3\20"+
		"\3\20\3\20\3\21\3\21\5\21\u011b\n\21\3\22\3\22\3\22\3\22\7\22\u0121\n"+
		"\22\f\22\16\22\u0124\13\22\3\22\3\22\3\23\3\23\3\23\3\23\3\24\3\24\3\24"+
		"\3\25\3\25\5\25\u0131\n\25\3\26\3\26\3\26\5\26\u0136\n\26\3\26\3\26\3"+
		"\26\3\27\3\27\3\27\5\27\u013e\n\27\3\27\3\27\3\27\3\27\3\27\3\30\3\30"+
		"\3\30\5\30\u0148\n\30\3\31\3\31\3\31\5\31\u014d\n\31\3\32\3\32\3\33\3"+
		"\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33\3\33\5\33\u015f"+
		"\n\33\3\34\3\34\3\34\7\34\u0164\n\34\f\34\16\34\u0167\13\34\3\35\3\35"+
		"\3\35\3\36\3\36\3\37\3\37\3\37\3\37\3 \3 \3 \3 \3 \3!\3!\3!\3!\3!\3!\3"+
		"!\3!\3!\3!\5!\u0181\n!\3\"\3\"\5\"\u0185\n\"\3#\3#\3$\3$\3%\3%\3&\3&\3"+
		"\'\3\'\5\'\u0191\n\'\3(\3(\3)\3)\3)\5)\u0198\n)\3*\3*\3*\3*\3+\3+\3+\3"+
		"+\5+\u01a2\n+\3+\3+\3,\3,\3,\7,\u01a9\n,\f,\16,\u01ac\13,\3-\3-\3-\3-"+
		"\3-\3-\5-\u01b4\n-\3.\3.\5.\u01b8\n.\3/\3/\3/\3/\5/\u01be\n/\3\60\3\60"+
		"\3\60\3\60\3\60\5\60\u01c5\n\60\3\61\3\61\3\62\3\62\3\62\3\62\3\63\3\63"+
		"\3\63\5\63\u01d0\n\63\3\63\7\63\u01d3\n\63\f\63\16\63\u01d6\13\63\3\64"+
		"\3\64\3\65\3\65\3\65\3\65\7\65\u01de\n\65\f\65\16\65\u01e1\13\65\3\65"+
		"\3\65\3\65\3\65\3\65\3\65\7\65\u01e9\n\65\f\65\16\65\u01ec\13\65\3\65"+
		"\3\65\3\65\3\65\3\65\5\65\u01f3\n\65\3\66\3\66\3\66\3\66\7\66\u01f9\n"+
		"\66\f\66\16\66\u01fc\13\66\3\67\3\67\38\38\38\38\78\u0204\n8\f8\168\u0207"+
		"\138\39\39\3:\3:\3:\3:\7:\u020f\n:\f:\16:\u0212\13:\3;\3;\3<\5<\u0217"+
		"\n<\3<\3<\3=\3=\3=\3=\3=\3=\3=\3=\3=\3=\3=\5=\u0226\n=\3>\3>\3>\3>\5>"+
		"\u022c\n>\3?\3?\3?\3?\3?\3@\3@\3@\7@\u0236\n@\f@\16@\u0239\13@\3A\3A\7"+
		"A\u023d\nA\fA\16A\u0240\13A\3B\3B\3B\3C\3C\3C\3C\7C\u0249\nC\fC\16C\u024c"+
		"\13C\3C\3C\3C\3C\3C\3C\7C\u0254\nC\fC\16C\u0257\13C\3C\3C\5C\u025b\nC"+
		"\3D\3D\3D\5D\u0260\nD\3E\3E\3E\3F\3F\3F\3F\3F\3F\3F\5F\u026c\nF\3G\3G"+
		"\3G\5G\u0271\nG\3H\3H\3H\5H\u0276\nH\3I\3I\3J\3J\3J\3J\3J\3K\3K\3K\3K"+
		"\3K\3L\3L\3L\3L\3M\3M\3M\7M\u028b\nM\fM\16M\u028e\13M\3N\3N\3N\3N\3N\3"+
		"N\5N\u0296\nN\3O\3O\3O\3O\3O\3O\7O\u029e\nO\fO\16O\u02a1\13O\3O\3O\3O"+
		"\5O\u02a6\nO\3O\3O\3P\3P\3P\7P\u02ad\nP\fP\16P\u02b0\13P\3P\3P\3P\3Q\3"+
		"Q\3Q\3Q\3Q\3R\3R\3R\3R\3R\3S\3S\3S\3S\3S\3S\3S\3T\3T\3T\3T\7T\u02ca\n"+
		"T\fT\16T\u02cd\13T\3T\3T\3T\3T\2\2U\2\4\6\b\n\f\16\20\22\24\26\30\32\34"+
		"\36 \"$&(*,.\60\62\64\668:<>@BDFHJLNPRTVXZ\\^`bdfhjlnprtvxz|~\u0080\u0082"+
		"\u0084\u0086\u0088\u008a\u008c\u008e\u0090\u0092\u0094\u0096\u0098\u009a"+
		"\u009c\u009e\u00a0\u00a2\u00a4\u00a6\2\t\3\2PQ\3\2CD\7\2\b\b\n\n\34\34"+
		"++AA\5\2\32\3288TX\4\2\'\'PQ\6\2\3\3\20\20\36\36RS\4\2\22\22\60\60\2\u02d6"+
		"\2\u00a8\3\2\2\2\4\u00bb\3\2\2\2\6\u00bd\3\2\2\2\b\u00c8\3\2\2\2\n\u00cd"+
		"\3\2\2\2\f\u00d1\3\2\2\2\16\u00dc\3\2\2\2\20\u00e4\3\2\2\2\22\u00e8\3"+
		"\2\2\2\24\u00ea\3\2\2\2\26\u00f2\3\2\2\2\30\u00f9\3\2\2\2\32\u010b\3\2"+
		"\2\2\34\u010d\3\2\2\2\36\u0111\3\2\2\2 \u0118\3\2\2\2\"\u011c\3\2\2\2"+
		"$\u0127\3\2\2\2&\u012b\3\2\2\2(\u0130\3\2\2\2*\u0132\3\2\2\2,\u013a\3"+
		"\2\2\2.\u0147\3\2\2\2\60\u014c\3\2\2\2\62\u014e\3\2\2\2\64\u015e\3\2\2"+
		"\2\66\u0160\3\2\2\28\u0168\3\2\2\2:\u016b\3\2\2\2<\u016d\3\2\2\2>\u0171"+
		"\3\2\2\2@\u0180\3\2\2\2B\u0184\3\2\2\2D\u0186\3\2\2\2F\u0188\3\2\2\2H"+
		"\u018a\3\2\2\2J\u018c\3\2\2\2L\u0190\3\2\2\2N\u0192\3\2\2\2P\u0197\3\2"+
		"\2\2R\u0199\3\2\2\2T\u019d\3\2\2\2V\u01a5\3\2\2\2X\u01b3\3\2\2\2Z\u01b7"+
		"\3\2\2\2\\\u01bd\3\2\2\2^\u01bf\3\2\2\2`\u01c6\3\2\2\2b\u01c8\3\2\2\2"+
		"d\u01cf\3\2\2\2f\u01d7\3\2\2\2h\u01f2\3\2\2\2j\u01f4\3\2\2\2l\u01fd\3"+
		"\2\2\2n\u01ff\3\2\2\2p\u0208\3\2\2\2r\u020a\3\2\2\2t\u0213\3\2\2\2v\u0216"+
		"\3\2\2\2x\u0225\3\2\2\2z\u022b\3\2\2\2|\u022d\3\2\2\2~\u0232\3\2\2\2\u0080"+
		"\u023a\3\2\2\2\u0082\u0241\3\2\2\2\u0084\u025a\3\2\2\2\u0086\u025c\3\2"+
		"\2\2\u0088\u0261\3\2\2\2\u008a\u026b\3\2\2\2\u008c\u0270\3\2\2\2\u008e"+
		"\u0272\3\2\2\2\u0090\u0277\3\2\2\2\u0092\u0279\3\2\2\2\u0094\u027e\3\2"+
		"\2\2\u0096\u0283\3\2\2\2\u0098\u0287\3\2\2\2\u009a\u028f\3\2\2\2\u009c"+
		"\u0297\3\2\2\2\u009e\u02a9\3\2\2\2\u00a0\u02b4\3\2\2\2\u00a2\u02b9\3\2"+
		"\2\2\u00a4\u02be\3\2\2\2\u00a6\u02c5\3\2\2\2\u00a8\u00a9\5\4\3\2\u00a9"+
		"\u00aa\5\b\5\2\u00aa\u00ab\7<\2\2\u00ab\u00ac\7\2\2\3\u00ac\3\3\2\2\2"+
		"\u00ad\u00ae\7*\2\2\u00ae\u00b3\5\6\4\2\u00af\u00b0\7`\2\2\u00b0\u00b1"+
		"\5V,\2\u00b1\u00b2\7a\2\2\u00b2\u00b4\3\2\2\2\u00b3\u00af\3\2\2\2\u00b3"+
		"\u00b4\3\2\2\2\u00b4\u00b5\3\2\2\2\u00b5\u00b6\7^\2\2\u00b6\u00bc\3\2"+
		"\2\2\u00b7\u00b8\7>\2\2\u00b8\u00b9\5\6\4\2\u00b9\u00ba\7^\2\2\u00ba\u00bc"+
		"\3\2\2\2\u00bb\u00ad\3\2\2\2\u00bb\u00b7\3\2\2\2\u00bc\5\3\2\2\2\u00bd"+
		"\u00be\7H\2\2\u00be\7\3\2\2\2\u00bf\u00c7\5\f\7\2\u00c0\u00c7\5\16\b\2"+
		"\u00c1\u00c7\5\24\13\2\u00c2\u00c7\5&\24\2\u00c3\u00c7\5\"\22\2\u00c4"+
		"\u00c7\5\n\6\2\u00c5\u00c7\7B\2\2\u00c6\u00bf\3\2\2\2\u00c6\u00c0\3\2"+
		"\2\2\u00c6\u00c1\3\2\2\2\u00c6\u00c2\3\2\2\2\u00c6\u00c3\3\2\2\2\u00c6"+
		"\u00c4\3\2\2\2\u00c6\u00c5\3\2\2\2\u00c7\u00ca\3\2\2\2\u00c8\u00c6\3\2"+
		"\2\2\u00c8\u00c9\3\2\2\2\u00c9\u00cb\3\2\2\2\u00ca\u00c8\3\2\2\2\u00cb"+
		"\u00cc\5\u0096L\2\u00cc\t\3\2\2\2\u00cd\u00ce\7@\2\2\u00ce\u00cf\5V,\2"+
		"\u00cf\u00d0\7^\2\2\u00d0\13\3\2\2\2\u00d1\u00d2\7\35\2\2\u00d2\u00d7"+
		"\5:\36\2\u00d3\u00d4\7_\2\2\u00d4\u00d6\5:\36\2\u00d5\u00d3\3\2\2\2\u00d6"+
		"\u00d9\3\2\2\2\u00d7\u00d5\3\2\2\2\u00d7\u00d8\3\2\2\2\u00d8\u00da\3\2"+
		"\2\2\u00d9\u00d7\3\2\2\2\u00da\u00db\7^\2\2\u00db\r\3\2\2\2\u00dc\u00e0"+
		"\7\f\2\2\u00dd\u00de\5\20\t\2\u00de\u00df\7^\2\2\u00df\u00e1\3\2\2\2\u00e0"+
		"\u00dd\3\2\2\2\u00e1\u00e2\3\2\2\2\u00e2\u00e0\3\2\2\2\u00e2\u00e3\3\2"+
		"\2\2\u00e3\17\3\2\2\2\u00e4\u00e5\5\22\n\2\u00e5\u00e6\78\2\2\u00e6\u00e7"+
		"\5@!\2\u00e7\21\3\2\2\2\u00e8\u00e9\7H\2\2\u00e9\23\3\2\2\2\u00ea\u00ee"+
		"\7\61\2\2\u00eb\u00ec\5\26\f\2\u00ec\u00ed\7^\2\2\u00ed\u00ef\3\2\2\2"+
		"\u00ee\u00eb\3\2\2\2\u00ef\u00f0\3\2\2\2\u00f0\u00ee\3\2\2\2\u00f0\u00f1"+
		"\3\2\2\2\u00f1\25\3\2\2\2\u00f2\u00f3\5L\'\2\u00f3\u00f7\78\2\2\u00f4"+
		"\u00f8\5.\30\2\u00f5\u00f8\5\36\20\2\u00f6\u00f8\5 \21\2\u00f7\u00f4\3"+
		"\2\2\2\u00f7\u00f5\3\2\2\2\u00f7\u00f6\3\2\2\2\u00f8\27\3\2\2\2\u00f9"+
		"\u00fa\7`\2\2\u00fa\u00ff\5\32\16\2\u00fb\u00fc\7^\2\2\u00fc\u00fe\5\32"+
		"\16\2\u00fd\u00fb\3\2\2\2\u00fe\u0101\3\2\2\2\u00ff\u00fd\3\2\2\2\u00ff"+
		"\u0100\3\2\2\2\u0100\u0102\3\2\2\2\u0101\u00ff\3\2\2\2\u0102\u0103\7a"+
		"\2\2\u0103\31\3\2\2\2\u0104\u010c\5\34\17\2\u0105\u0106\7\63\2\2\u0106"+
		"\u010c\5\34\17\2\u0107\u0108\7\27\2\2\u0108\u010c\5\34\17\2\u0109\u010a"+
		"\7)\2\2\u010a\u010c\5\34\17\2\u010b\u0104\3\2\2\2\u010b\u0105\3\2\2\2"+
		"\u010b\u0107\3\2\2\2\u010b\u0109\3\2\2\2\u010c\33\3\2\2\2\u010d\u010e"+
		"\5V,\2\u010e\u010f\7\67\2\2\u010f\u0110\5L\'\2\u0110\35\3\2\2\2\u0111"+
		"\u0113\7\27\2\2\u0112\u0114\5\30\r\2\u0113\u0112\3\2\2\2\u0113\u0114\3"+
		"\2\2\2\u0114\u0115\3\2\2\2\u0115\u0116\7\67\2\2\u0116\u0117\5L\'\2\u0117"+
		"\37\3\2\2\2\u0118\u011a\7)\2\2\u0119\u011b\5\30\r\2\u011a\u0119\3\2\2"+
		"\2\u011a\u011b\3\2\2\2\u011b!\3\2\2\2\u011c\u011d\7\63\2\2\u011d\u0122"+
		"\5$\23\2\u011e\u011f\7^\2\2\u011f\u0121\5$\23\2\u0120\u011e\3\2\2\2\u0121"+
		"\u0124\3\2\2\2\u0122\u0120\3\2\2\2\u0122\u0123\3\2\2\2\u0123\u0125\3\2"+
		"\2\2\u0124\u0122\3\2\2\2\u0125\u0126\7^\2\2\u0126#\3\2\2\2\u0127\u0128"+
		"\5V,\2\u0128\u0129\7\67\2\2\u0129\u012a\5.\30\2\u012a%\3\2\2\2\u012b\u012c"+
		"\5(\25\2\u012c\u012d\7^\2\2\u012d\'\3\2\2\2\u012e\u0131\5*\26\2\u012f"+
		"\u0131\5,\27\2\u0130\u012e\3\2\2\2\u0130\u012f\3\2\2\2\u0131)\3\2\2\2"+
		"\u0132\u0133\7)\2\2\u0133\u0135\5\6\4\2\u0134\u0136\5\30\r\2\u0135\u0134"+
		"\3\2\2\2\u0135\u0136\3\2\2\2\u0136\u0137\3\2\2\2\u0137\u0138\7^\2\2\u0138"+
		"\u0139\5\b\5\2\u0139+\3\2\2\2\u013a\u013b\7\27\2\2\u013b\u013d\5\6\4\2"+
		"\u013c\u013e\5\30\r\2\u013d\u013c\3\2\2\2\u013d\u013e\3\2\2\2\u013e\u013f"+
		"\3\2\2\2\u013f\u0140\7\67\2\2\u0140\u0141\5L\'\2\u0141\u0142\7^\2\2\u0142"+
		"\u0143\5\b\5\2\u0143-\3\2\2\2\u0144\u0148\5P)\2\u0145\u0148\5\60\31\2"+
		"\u0146\u0148\58\35\2\u0147\u0144\3\2\2\2\u0147\u0145\3\2\2\2\u0147\u0146"+
		"\3\2\2\2\u0148/\3\2\2\2\u0149\u014a\7(\2\2\u014a\u014d\5\62\32\2\u014b"+
		"\u014d\5\62\32\2\u014c\u0149\3\2\2\2\u014c\u014b\3\2\2\2\u014d\61\3\2"+
		"\2\2\u014e\u014f\5\64\33\2\u014f\63\3\2\2\2\u0150\u0151\7\4\2\2\u0151"+
		"\u0152\7b\2\2\u0152\u0153\5\66\34\2\u0153\u0154\7c\2\2\u0154\u0155\7$"+
		"\2\2\u0155\u0156\5.\30\2\u0156\u015f\3\2\2\2\u0157\u0158\7\4\2\2\u0158"+
		"\u0159\79\2\2\u0159\u015a\5\66\34\2\u015a\u015b\7:\2\2\u015b\u015c\7$"+
		"\2\2\u015c\u015d\5.\30\2\u015d\u015f\3\2\2\2\u015e\u0150\3\2\2\2\u015e"+
		"\u0157\3\2\2\2\u015f\65\3\2\2\2\u0160\u0165\5P)\2\u0161\u0162\7_\2\2\u0162"+
		"\u0164\5P)\2\u0163\u0161\3\2\2\2\u0164\u0167\3\2\2\2\u0165\u0163\3\2\2"+
		"\2\u0165\u0166\3\2\2\2\u0166\67\3\2\2\2\u0167\u0165\3\2\2\2\u0168\u0169"+
		"\7]\2\2\u0169\u016a\5L\'\2\u016a9\3\2\2\2\u016b\u016c\5D#\2\u016c;\3\2"+
		"\2\2\u016d\u016e\5\6\4\2\u016e\u016f\78\2\2\u016f\u0170\5@!\2\u0170=\3"+
		"\2\2\2\u0171\u0172\7\13\2\2\u0172\u0173\7`\2\2\u0173\u0174\5D#\2\u0174"+
		"\u0175\7a\2\2\u0175?\3\2\2\2\u0176\u0181\5B\"\2\u0177\u0178\5H%\2\u0178"+
		"\u0179\5B\"\2\u0179\u0181\3\2\2\2\u017a\u0181\5\6\4\2\u017b\u017c\5H%"+
		"\2\u017c\u017d\5\6\4\2\u017d\u0181\3\2\2\2\u017e\u0181\5N(\2\u017f\u0181"+
		"\5> \2\u0180\u0176\3\2\2\2\u0180\u0177\3\2\2\2\u0180\u017a\3\2\2\2\u0180"+
		"\u017b\3\2\2\2\u0180\u017e\3\2\2\2\u0180\u017f\3\2\2\2\u0181A\3\2\2\2"+
		"\u0182\u0185\5D#\2\u0183\u0185\5F$\2\u0184\u0182\3\2\2\2\u0184\u0183\3"+
		"\2\2\2\u0185C\3\2\2\2\u0186\u0187\7J\2\2\u0187E\3\2\2\2\u0188\u0189\7"+
		"K\2\2\u0189G\3\2\2\2\u018a\u018b\t\2\2\2\u018bI\3\2\2\2\u018c\u018d\t"+
		"\3\2\2\u018dK\3\2\2\2\u018e\u0191\5\6\4\2\u018f\u0191\t\4\2\2\u0190\u018e"+
		"\3\2\2\2\u0190\u018f\3\2\2\2\u0191M\3\2\2\2\u0192\u0193\7I\2\2\u0193O"+
		"\3\2\2\2\u0194\u0198\5R*\2\u0195\u0198\5L\'\2\u0196\u0198\5T+\2\u0197"+
		"\u0194\3\2\2\2\u0197\u0195\3\2\2\2\u0197\u0196\3\2\2\2\u0198Q\3\2\2\2"+
		"\u0199\u019a\7`\2\2\u019a\u019b\5V,\2\u019b\u019c\7a\2\2\u019cS\3\2\2"+
		"\2\u019d\u019e\7A\2\2\u019e\u01a1\7b\2\2\u019f\u01a2\5\6\4\2\u01a0\u01a2"+
		"\5B\"\2\u01a1\u019f\3\2\2\2\u01a1\u01a0\3\2\2\2\u01a2\u01a3\3\2\2\2\u01a3"+
		"\u01a4\7c\2\2\u01a4U\3\2\2\2\u01a5\u01aa\5\6\4\2\u01a6\u01a7\7_\2\2\u01a7"+
		"\u01a9\5\6\4\2\u01a8\u01a6\3\2\2\2\u01a9\u01ac\3\2\2\2\u01aa\u01a8\3\2"+
		"\2\2\u01aa\u01ab\3\2\2\2\u01abW\3\2\2\2\u01ac\u01aa\3\2\2\2\u01ad\u01ae"+
		"\5:\36\2\u01ae\u01af\7\67\2\2\u01af\u01b0\5Z.\2\u01b0\u01b4\3\2\2\2\u01b1"+
		"\u01b4\5Z.\2\u01b2\u01b4\5&\24\2\u01b3\u01ad\3\2\2\2\u01b3\u01b1\3\2\2"+
		"\2\u01b3\u01b2\3\2\2\2\u01b4Y\3\2\2\2\u01b5\u01b8\5\\/\2\u01b6\u01b8\5"+
		"\u008aF\2\u01b7\u01b5\3\2\2\2\u01b7\u01b6\3\2\2\2\u01b8[\3\2\2\2\u01b9"+
		"\u01be\5b\62\2\u01ba\u01be\5^\60\2\u01bb\u01be\5\u0088E\2\u01bc\u01be"+
		"\5`\61\2\u01bd\u01b9\3\2\2\2\u01bd\u01ba\3\2\2\2\u01bd\u01bb\3\2\2\2\u01bd"+
		"\u01bc\3\2\2\2\u01be]\3\2\2\2\u01bf\u01c4\5\6\4\2\u01c0\u01c1\7`\2\2\u01c1"+
		"\u01c2\5~@\2\u01c2\u01c3\7a\2\2\u01c3\u01c5\3\2\2\2\u01c4\u01c0\3\2\2"+
		"\2\u01c4\u01c5\3\2\2\2\u01c5_\3\2\2\2\u01c6\u01c7\3\2\2\2\u01c7a\3\2\2"+
		"\2\u01c8\u01c9\5d\63\2\u01c9\u01ca\7\66\2\2\u01ca\u01cb\5j\66\2\u01cb"+
		"c\3\2\2\2\u01cc\u01cd\7;\2\2\u01cd\u01d0\5f\64\2\u01ce\u01d0\5f\64\2\u01cf"+
		"\u01cc\3\2\2\2\u01cf\u01ce\3\2\2\2\u01d0\u01d4\3\2\2\2\u01d1\u01d3\5h"+
		"\65\2\u01d2\u01d1\3\2\2\2\u01d3\u01d6\3\2\2\2\u01d4\u01d2\3\2\2\2\u01d4"+
		"\u01d5\3\2\2\2\u01d5e\3\2\2\2\u01d6\u01d4\3\2\2\2\u01d7\u01d8\7H\2\2\u01d8"+
		"g\3\2\2\2\u01d9\u01da\7b\2\2\u01da\u01df\5j\66\2\u01db\u01dc\7_\2\2\u01dc"+
		"\u01de\5j\66\2\u01dd\u01db\3\2\2\2\u01de\u01e1\3\2\2\2\u01df\u01dd\3\2"+
		"\2\2\u01df\u01e0\3\2\2\2\u01e0\u01e2\3\2\2\2\u01e1\u01df\3\2\2\2\u01e2"+
		"\u01e3\7c\2\2\u01e3\u01f3\3\2\2\2\u01e4\u01e5\79\2\2\u01e5\u01ea\5j\66"+
		"\2\u01e6\u01e7\7_\2\2\u01e7\u01e9\5j\66\2\u01e8\u01e6\3\2\2\2\u01e9\u01ec"+
		"\3\2\2\2\u01ea\u01e8\3\2\2\2\u01ea\u01eb\3\2\2\2\u01eb\u01ed\3\2\2\2\u01ec"+
		"\u01ea\3\2\2\2\u01ed\u01ee\7:\2\2\u01ee\u01f3\3\2\2\2\u01ef\u01f0\7<\2"+
		"\2\u01f0\u01f3\5\6\4\2\u01f1\u01f3\7]\2\2\u01f2\u01d9\3\2\2\2\u01f2\u01e4"+
		"\3\2\2\2\u01f2\u01ef\3\2\2\2\u01f2\u01f1\3\2\2\2\u01f3i\3\2\2\2\u01f4"+
		"\u01fa\5n8\2\u01f5\u01f6\5l\67\2\u01f6\u01f7\5j\66\2\u01f7\u01f9\3\2\2"+
		"\2\u01f8\u01f5\3\2\2\2\u01f9\u01fc\3\2\2\2\u01fa\u01f8\3\2\2\2\u01fa\u01fb"+
		"\3\2\2\2\u01fbk\3\2\2\2\u01fc\u01fa\3\2\2\2\u01fd\u01fe\t\5\2\2\u01fe"+
		"m\3\2\2\2\u01ff\u0205\5r:\2\u0200\u0201\5p9\2\u0201\u0202\5n8\2\u0202"+
		"\u0204\3\2\2\2\u0203\u0200\3\2\2\2\u0204\u0207\3\2\2\2\u0205\u0203\3\2"+
		"\2\2\u0205\u0206\3\2\2\2\u0206o\3\2\2\2\u0207\u0205\3\2\2\2\u0208\u0209"+
		"\t\6\2\2\u0209q\3\2\2\2\u020a\u0210\5v<\2\u020b\u020c\5t;\2\u020c\u020d"+
		"\5r:\2\u020d\u020f\3\2\2\2\u020e\u020b\3\2\2\2\u020f\u0212\3\2\2\2\u0210"+
		"\u020e\3\2\2\2\u0210\u0211\3\2\2\2\u0211s\3\2\2\2\u0212\u0210\3\2\2\2"+
		"\u0213\u0214\t\7\2\2\u0214u\3\2\2\2\u0215\u0217\t\2\2\2\u0216\u0215\3"+
		"\2\2\2\u0216\u0217\3\2\2\2\u0217\u0218\3\2\2\2\u0218\u0219\5x=\2\u0219"+
		"w\3\2\2\2\u021a\u0226\5d\63\2\u021b\u021c\7`\2\2\u021c\u021d\5j\66\2\u021d"+
		"\u021e\7a\2\2\u021e\u0226\3\2\2\2\u021f\u0226\5|?\2\u0220\u0226\5z>\2"+
		"\u0221\u0226\5\u0084C\2\u0222\u0223\7#\2\2\u0223\u0226\5x=\2\u0224\u0226"+
		"\5J&\2\u0225\u021a\3\2\2\2\u0225\u021b\3\2\2\2\u0225\u021f\3\2\2\2\u0225"+
		"\u0220\3\2\2\2\u0225\u0221\3\2\2\2\u0225\u0222\3\2\2\2\u0225\u0224\3\2"+
		"\2\2\u0226y\3\2\2\2\u0227\u022c\5B\"\2\u0228\u022c\5> \2\u0229\u022c\5"+
		"N(\2\u022a\u022c\7\37\2\2\u022b\u0227\3\2\2\2\u022b\u0228\3\2\2\2\u022b"+
		"\u0229\3\2\2\2\u022b\u022a\3\2\2\2\u022c{\3\2\2\2\u022d\u022e\5\6\4\2"+
		"\u022e\u022f\7`\2\2\u022f\u0230\5~@\2\u0230\u0231\7a\2\2\u0231}\3\2\2"+
		"\2\u0232\u0237\5\u0080A\2\u0233\u0234\7_\2\2\u0234\u0236\5\u0080A\2\u0235"+
		"\u0233\3\2\2\2\u0236\u0239\3\2\2\2\u0237\u0235\3\2\2\2\u0237\u0238\3\2"+
		"\2\2\u0238\177\3\2\2\2\u0239\u0237\3\2\2\2\u023a\u023e\5j\66\2\u023b\u023d"+
		"\5\u0082B\2\u023c\u023b\3\2\2\2\u023d\u0240\3\2\2\2\u023e\u023c\3\2\2"+
		"\2\u023e\u023f\3\2\2\2\u023f\u0081\3\2\2\2\u0240\u023e\3\2\2\2\u0241\u0242"+
		"\7\67\2\2\u0242\u0243\5j\66\2\u0243\u0083\3\2\2\2\u0244\u0245\7b\2\2\u0245"+
		"\u024a\5\u0086D\2\u0246\u0247\7_\2\2\u0247\u0249\5\u0086D\2\u0248\u0246"+
		"\3\2\2\2\u0249\u024c\3\2\2\2\u024a\u0248\3\2\2\2\u024a\u024b\3\2\2\2\u024b"+
		"\u024d\3\2\2\2\u024c\u024a\3\2\2\2\u024d\u024e\7c\2\2\u024e\u025b\3\2"+
		"\2\2\u024f\u0250\79\2\2\u0250\u0255\5\u0086D\2\u0251\u0252\7_\2\2\u0252"+
		"\u0254\5\u0086D\2\u0253\u0251\3\2\2\2\u0254\u0257\3\2\2\2\u0255\u0253"+
		"\3\2\2\2\u0255\u0256\3\2\2\2\u0256\u0258\3\2\2\2\u0257\u0255\3\2\2\2\u0258"+
		"\u0259\7:\2\2\u0259\u025b\3\2\2\2\u025a\u0244\3\2\2\2\u025a\u024f\3\2"+
		"\2\2\u025b\u0085\3\2\2\2\u025c\u025f\5j\66\2\u025d\u025e\7=\2\2\u025e"+
		"\u0260\5j\66\2\u025f\u025d\3\2\2\2\u025f\u0260\3\2\2\2\u0260\u0087\3\2"+
		"\2\2\u0261\u0262\7\30\2\2\u0262\u0263\5:\36\2\u0263\u0089\3\2\2\2\u0264"+
		"\u026c\5\u0096L\2\u0265\u026c\5\u008cG\2\u0266\u026c\5\u009aN\2\u0267"+
		"\u026c\5\u009cO\2\u0268\u026c\5\u00a6T\2\u0269\u026c\5\u0092J\2\u026a"+
		"\u026c\5\u0094K\2\u026b\u0264\3\2\2\2\u026b\u0265\3\2\2\2\u026b\u0266"+
		"\3\2\2\2\u026b\u0267\3\2\2\2\u026b\u0268\3\2\2\2\u026b\u0269\3\2\2\2\u026b"+
		"\u026a\3\2\2\2\u026c\u008b\3\2\2\2\u026d\u0271\5\u00a0Q\2\u026e\u0271"+
		"\5\u00a2R\2\u026f\u0271\5\u00a4S\2\u0270\u026d\3\2\2\2\u0270\u026e\3\2"+
		"\2\2\u0270\u026f\3\2\2\2\u0271\u008d\3\2\2\2\u0272\u0275\5\u0090I\2\u0273"+
		"\u0274\7_\2\2\u0274\u0276\5\u0090I\2\u0275\u0273\3\2\2\2\u0275\u0276\3"+
		"\2\2\2\u0276\u008f\3\2\2\2\u0277\u0278\5j\66\2\u0278\u0091\3\2\2\2\u0279"+
		"\u027a\7!\2\2\u027a\u027b\7`\2\2\u027b\u027c\5\u008eH\2\u027c\u027d\7"+
		"a\2\2\u027d\u0093\3\2\2\2\u027e\u027f\7\"\2\2\u027f\u0280\7`\2\2\u0280"+
		"\u0281\5\u008eH\2\u0281\u0282\7a\2\2\u0282\u0095\3\2\2\2\u0283\u0284\7"+
		"\6\2\2\u0284\u0285\5\u0098M\2\u0285\u0286\7\24\2\2\u0286\u0097\3\2\2\2"+
		"\u0287\u028c\5X-\2\u0288\u0289\7^\2\2\u0289\u028b\5X-\2\u028a\u0288\3"+
		"\2\2\2\u028b\u028e\3\2\2\2\u028c\u028a\3\2\2\2\u028c\u028d\3\2\2\2\u028d"+
		"\u0099\3\2\2\2\u028e\u028c\3\2\2\2\u028f\u0290\7\31\2\2\u0290\u0291\5"+
		"j\66\2\u0291\u0292\7/\2\2\u0292\u0295\5X-\2\u0293\u0294\7\23\2\2\u0294"+
		"\u0296\5X-\2\u0295\u0293\3\2\2\2\u0295\u0296\3\2\2\2\u0296\u009b\3\2\2"+
		"\2\u0297\u0298\7\t\2\2\u0298\u0299\5j\66\2\u0299\u029a\7$\2\2\u029a\u029f"+
		"\5\u009eP\2\u029b\u029c\7^\2\2\u029c\u029e\5\u009eP\2\u029d\u029b\3\2"+
		"\2\2\u029e\u02a1\3\2\2\2\u029f\u029d\3\2\2\2\u029f\u02a0\3\2\2\2\u02a0"+
		"\u02a5\3\2\2\2\u02a1\u029f\3\2\2\2\u02a2\u02a3\7^\2\2\u02a3\u02a4\7\23"+
		"\2\2\u02a4\u02a6\5\u0098M\2\u02a5\u02a2\3\2\2\2\u02a5\u02a6\3\2\2\2\u02a6"+
		"\u02a7\3\2\2\2\u02a7\u02a8\7\24\2\2\u02a8\u009d\3\2\2\2\u02a9\u02ae\5"+
		"@!\2\u02aa\u02ab\7_\2\2\u02ab\u02ad\5@!\2\u02ac\u02aa\3\2\2\2\u02ad\u02b0"+
		"\3\2\2\2\u02ae\u02ac\3\2\2\2\u02ae\u02af\3\2\2\2\u02af\u02b1\3\2\2\2\u02b0"+
		"\u02ae\3\2\2\2\u02b1\u02b2\7\67\2\2\u02b2\u02b3\5X-\2\u02b3\u009f\3\2"+
		"\2\2\u02b4\u02b5\7\64\2\2\u02b5\u02b6\5j\66\2\u02b6\u02b7\7\21\2\2\u02b7"+
		"\u02b8\5X-\2\u02b8\u00a1\3\2\2\2\u02b9\u02ba\7-\2\2\u02ba\u02bb\5\u0098"+
		"M\2\u02bb\u02bc\7\62\2\2\u02bc\u02bd\5j\66\2\u02bd\u00a3\3\2\2\2\u02be"+
		"\u02bf\7\26\2\2\u02bf\u02c0\5b\62\2\u02c0\u02c1\t\b\2\2\u02c1\u02c2\5"+
		"j\66\2\u02c2\u02c3\7\21\2\2\u02c3\u02c4\5X-\2\u02c4\u00a5\3\2\2\2\u02c5"+
		"\u02c6\7\65\2\2\u02c6\u02cb\5d\63\2\u02c7\u02c8\7_\2\2\u02c8\u02ca\5d"+
		"\63\2\u02c9\u02c7\3\2\2\2\u02ca\u02cd\3\2\2\2\u02cb\u02c9\3\2\2\2\u02cb"+
		"\u02cc\3\2\2\2\u02cc\u02ce\3\2\2\2\u02cd\u02cb\3\2\2\2\u02ce\u02cf\7\21"+
		"\2\2\u02cf\u02d0\5X-\2\u02d0\u00a7\3\2\2\2:\u00b3\u00bb\u00c6\u00c8\u00d7"+
		"\u00e2\u00f0\u00f7\u00ff\u010b\u0113\u011a\u0122\u0130\u0135\u013d\u0147"+
		"\u014c\u015e\u0165\u0180\u0184\u0190\u0197\u01a1\u01aa\u01b3\u01b7\u01bd"+
		"\u01c4\u01cf\u01d4\u01df\u01ea\u01f2\u01fa\u0205\u0210\u0216\u0225\u022b"+
		"\u0237\u023e\u024a\u0255\u025a\u025f\u026b\u0270\u0275\u028c\u0295\u029f"+
		"\u02a5\u02ae\u02cb";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}