// Generated from \\wsl$\Ubuntu\home\brandonluong\Pascal\Pascal.g4 by ANTLR 4.9.2
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
		RULE_program = 0, RULE_programHead = 1, RULE_identifier = 2, RULE_label = 3, 
		RULE_constantVar = 4, RULE_constantChr = 5, RULE_constant = 6, RULE_unsignedNumber = 7, 
		RULE_unsignedInteger = 8, RULE_unsignedReal = 9, RULE_sign = 10, RULE_bool_ = 11, 
		RULE_typeIdentifier = 12, RULE_string = 13, RULE_simpleType = 14, RULE_scalarType = 15, 
		RULE_stringtype = 16, RULE_identifierList = 17, RULE_statement = 18, RULE_unlabelledStatement = 19, 
		RULE_simpleStatement = 20, RULE_emptyStatement_ = 21, RULE_assignmentStatement = 22, 
		RULE_variable = 23, RULE_expression = 24, RULE_relationaloperator = 25, 
		RULE_simpleExpression = 26, RULE_additiveoperator = 27, RULE_term = 28, 
		RULE_multiplicativeoperator = 29, RULE_signedFactor = 30, RULE_factor = 31, 
		RULE_unsignedConstant = 32, RULE_gotoStatement = 33, RULE_structuredStatement = 34, 
		RULE_reptitiveStatement = 35, RULE_writeArguments = 36, RULE_writeArgs = 37, 
		RULE_writeStatement = 38, RULE_writelnStatement = 39, RULE_compoundStatement = 40, 
		RULE_statements = 41, RULE_ifStatement = 42, RULE_caseStatement = 43, 
		RULE_caseListElement = 44, RULE_whileStatement = 45, RULE_repeatStatement = 46, 
		RULE_forStatement = 47, RULE_withStatement = 48;
	private static String[] makeRuleNames() {
		return new String[] {
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
		public CompoundStatementContext compoundStatement() {
			return getRuleContext(CompoundStatementContext.class,0);
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
			setState(98);
			programHead();
			setState(99);
			compoundStatement();
			setState(100);
			match(DOT);
			setState(101);
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
			setState(117);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PROGRAM:
				enterOuterAlt(_localctx, 1);
				{
				setState(103);
				match(PROGRAM);
				setState(104);
				identifier();
				setState(109);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==LPAREN) {
					{
					setState(105);
					match(LPAREN);
					setState(106);
					identifierList();
					setState(107);
					match(RPAREN);
					}
				}

				setState(111);
				match(SEMICOLON);
				}
				break;
			case UNIT:
				enterOuterAlt(_localctx, 2);
				{
				setState(113);
				match(UNIT);
				setState(114);
				identifier();
				setState(115);
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
			setState(119);
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
		enterRule(_localctx, 6, RULE_label);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(121);
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
		enterRule(_localctx, 8, RULE_constantVar);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(123);
			identifier();
			setState(124);
			match(EQUAL);
			setState(125);
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
		enterRule(_localctx, 10, RULE_constantChr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(127);
			match(CHR);
			setState(128);
			match(LPAREN);
			setState(129);
			unsignedInteger();
			setState(130);
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
		enterRule(_localctx, 12, RULE_constant);
		try {
			setState(142);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(132);
				unsignedNumber();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(133);
				sign();
				setState(134);
				unsignedNumber();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(136);
				identifier();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(137);
				sign();
				setState(138);
				identifier();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(140);
				string();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(141);
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
		enterRule(_localctx, 14, RULE_unsignedNumber);
		try {
			setState(146);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUM_INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(144);
				unsignedInteger();
				}
				break;
			case NUM_REAL:
				enterOuterAlt(_localctx, 2);
				{
				setState(145);
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
		enterRule(_localctx, 16, RULE_unsignedInteger);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(148);
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
		enterRule(_localctx, 18, RULE_unsignedReal);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(150);
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
		enterRule(_localctx, 20, RULE_sign);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(152);
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
		enterRule(_localctx, 22, RULE_bool_);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(154);
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
		enterRule(_localctx, 24, RULE_typeIdentifier);
		int _la;
		try {
			setState(158);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENT:
				enterOuterAlt(_localctx, 1);
				{
				setState(156);
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
				setState(157);
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
		enterRule(_localctx, 26, RULE_string);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(160);
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
		enterRule(_localctx, 28, RULE_simpleType);
		try {
			setState(165);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(162);
				scalarType();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(163);
				typeIdentifier();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(164);
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
		enterRule(_localctx, 30, RULE_scalarType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(167);
			match(LPAREN);
			setState(168);
			identifierList();
			setState(169);
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
		enterRule(_localctx, 32, RULE_stringtype);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(171);
			match(STRING);
			setState(172);
			match(LBRACKET);
			setState(175);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENT:
				{
				setState(173);
				identifier();
				}
				break;
			case NUM_INT:
			case NUM_REAL:
				{
				setState(174);
				unsignedNumber();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(177);
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
		enterRule(_localctx, 34, RULE_identifierList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(179);
			identifier();
			setState(184);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(180);
				match(COMMA);
				setState(181);
				identifier();
				}
				}
				setState(186);
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
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_statement);
		try {
			setState(192);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUM_INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(187);
				label();
				setState(188);
				match(COLON);
				setState(189);
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
				setState(191);
				unlabelledStatement();
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
		enterRule(_localctx, 38, RULE_unlabelledStatement);
		try {
			setState(196);
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
				setState(194);
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
				setState(195);
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
		enterRule(_localctx, 40, RULE_simpleStatement);
		try {
			setState(201);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case AT:
			case IDENT:
				enterOuterAlt(_localctx, 1);
				{
				setState(198);
				assignmentStatement();
				}
				break;
			case GOTO:
				enterOuterAlt(_localctx, 2);
				{
				setState(199);
				gotoStatement();
				}
				break;
			case ELSE:
			case END:
			case UNTIL:
			case SEMICOLON:
				enterOuterAlt(_localctx, 3);
				{
				setState(200);
				emptyStatement_();
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

	public static class EmptyStatement_Context extends ParserRuleContext {
		public EmptyStatement_Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_emptyStatement_; }
	}

	public final EmptyStatement_Context emptyStatement_() throws RecognitionException {
		EmptyStatement_Context _localctx = new EmptyStatement_Context(_ctx, getState());
		enterRule(_localctx, 42, RULE_emptyStatement_);
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
		enterRule(_localctx, 44, RULE_assignmentStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(205);
			variable();
			setState(206);
			match(ASSIGN);
			setState(207);
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
		public TerminalNode AT() { return getToken(PascalParser.AT, 0); }
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public List<TerminalNode> LBRACKET() { return getTokens(PascalParser.LBRACKET); }
		public TerminalNode LBRACKET(int i) {
			return getToken(PascalParser.LBRACKET, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> RBRACKET() { return getTokens(PascalParser.RBRACKET); }
		public TerminalNode RBRACKET(int i) {
			return getToken(PascalParser.RBRACKET, i);
		}
		public List<TerminalNode> LBRACKET2() { return getTokens(PascalParser.LBRACKET2); }
		public TerminalNode LBRACKET2(int i) {
			return getToken(PascalParser.LBRACKET2, i);
		}
		public List<TerminalNode> RBRACKET2() { return getTokens(PascalParser.RBRACKET2); }
		public TerminalNode RBRACKET2(int i) {
			return getToken(PascalParser.RBRACKET2, i);
		}
		public List<TerminalNode> DOT() { return getTokens(PascalParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(PascalParser.DOT, i);
		}
		public List<TerminalNode> CARAT() { return getTokens(PascalParser.CARAT); }
		public TerminalNode CARAT(int i) {
			return getToken(PascalParser.CARAT, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(PascalParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(PascalParser.COMMA, i);
		}
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_variable);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(212);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case AT:
				{
				setState(209);
				match(AT);
				setState(210);
				identifier();
				}
				break;
			case IDENT:
				{
				setState(211);
				identifier();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(241);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 55)) & ~0x3f) == 0 && ((1L << (_la - 55)) & ((1L << (LBRACKET2 - 55)) | (1L << (DOT - 55)) | (1L << (CARAT - 55)) | (1L << (LBRACKET - 55)))) != 0)) {
				{
				setState(239);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case LBRACKET:
					{
					setState(214);
					match(LBRACKET);
					setState(215);
					expression();
					setState(220);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==COMMA) {
						{
						{
						setState(216);
						match(COMMA);
						setState(217);
						expression();
						}
						}
						setState(222);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(223);
					match(RBRACKET);
					}
					break;
				case LBRACKET2:
					{
					setState(225);
					match(LBRACKET2);
					setState(226);
					expression();
					setState(231);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==COMMA) {
						{
						{
						setState(227);
						match(COMMA);
						setState(228);
						expression();
						}
						}
						setState(233);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(234);
					match(RBRACKET2);
					}
					break;
				case DOT:
					{
					setState(236);
					match(DOT);
					setState(237);
					identifier();
					}
					break;
				case CARAT:
					{
					setState(238);
					match(CARAT);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(243);
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

	public static class ExpressionContext extends ParserRuleContext {
		public SimpleExpressionContext simpleExpression() {
			return getRuleContext(SimpleExpressionContext.class,0);
		}
		public RelationaloperatorContext relationaloperator() {
			return getRuleContext(RelationaloperatorContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_expression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(244);
			simpleExpression();
			setState(248);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 24)) & ~0x3f) == 0 && ((1L << (_la - 24)) & ((1L << (IN - 24)) | (1L << (EQUAL - 24)) | (1L << (NE - 24)) | (1L << (LTEQ - 24)) | (1L << (GTEQ - 24)) | (1L << (LT - 24)) | (1L << (GT - 24)))) != 0)) {
				{
				setState(245);
				relationaloperator();
				setState(246);
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
		enterRule(_localctx, 50, RULE_relationaloperator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(250);
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
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public AdditiveoperatorContext additiveoperator() {
			return getRuleContext(AdditiveoperatorContext.class,0);
		}
		public SimpleExpressionContext simpleExpression() {
			return getRuleContext(SimpleExpressionContext.class,0);
		}
		public SimpleExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simpleExpression; }
	}

	public final SimpleExpressionContext simpleExpression() throws RecognitionException {
		SimpleExpressionContext _localctx = new SimpleExpressionContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_simpleExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(252);
			term();
			setState(256);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 37)) & ~0x3f) == 0 && ((1L << (_la - 37)) & ((1L << (OR - 37)) | (1L << (PLUSOP - 37)) | (1L << (MINUSOP - 37)))) != 0)) {
				{
				setState(253);
				additiveoperator();
				setState(254);
				simpleExpression();
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
		enterRule(_localctx, 54, RULE_additiveoperator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(258);
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
		public SignedFactorContext signedFactor() {
			return getRuleContext(SignedFactorContext.class,0);
		}
		public MultiplicativeoperatorContext multiplicativeoperator() {
			return getRuleContext(MultiplicativeoperatorContext.class,0);
		}
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		TermContext _localctx = new TermContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_term);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(260);
			signedFactor();
			setState(264);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << AND) | (1L << DIV) | (1L << MOD))) != 0) || _la==MULTOP || _la==DIVOP) {
				{
				setState(261);
				multiplicativeoperator();
				setState(262);
				term();
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
		enterRule(_localctx, 58, RULE_multiplicativeoperator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(266);
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
		enterRule(_localctx, 60, RULE_signedFactor);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(269);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==PLUSOP || _la==MINUSOP) {
				{
				setState(268);
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

			setState(271);
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
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(PascalParser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(PascalParser.RPAREN, 0); }
		public UnsignedConstantContext unsignedConstant() {
			return getRuleContext(UnsignedConstantContext.class,0);
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
		enterRule(_localctx, 62, RULE_factor);
		try {
			setState(282);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case AT:
			case IDENT:
				enterOuterAlt(_localctx, 1);
				{
				setState(273);
				variable();
				}
				break;
			case LPAREN:
				enterOuterAlt(_localctx, 2);
				{
				setState(274);
				match(LPAREN);
				setState(275);
				expression();
				setState(276);
				match(RPAREN);
				}
				break;
			case CHR:
			case NIL:
			case STRING_LITERAL:
			case NUM_INT:
			case NUM_REAL:
				enterOuterAlt(_localctx, 3);
				{
				setState(278);
				unsignedConstant();
				}
				break;
			case NOT:
				enterOuterAlt(_localctx, 4);
				{
				setState(279);
				match(NOT);
				setState(280);
				factor();
				}
				break;
			case TRUE:
			case FALSE:
				enterOuterAlt(_localctx, 5);
				{
				setState(281);
				bool_();
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

	public static class UnsignedConstantContext extends ParserRuleContext {
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
		enterRule(_localctx, 64, RULE_unsignedConstant);
		try {
			setState(288);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUM_INT:
			case NUM_REAL:
				enterOuterAlt(_localctx, 1);
				{
				setState(284);
				unsignedNumber();
				}
				break;
			case CHR:
				enterOuterAlt(_localctx, 2);
				{
				setState(285);
				constantChr();
				}
				break;
			case STRING_LITERAL:
				enterOuterAlt(_localctx, 3);
				{
				setState(286);
				string();
				}
				break;
			case NIL:
				enterOuterAlt(_localctx, 4);
				{
				setState(287);
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
		enterRule(_localctx, 66, RULE_gotoStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(290);
			match(GOTO);
			setState(291);
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
		enterRule(_localctx, 68, RULE_structuredStatement);
		try {
			setState(300);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BEGIN:
				enterOuterAlt(_localctx, 1);
				{
				setState(293);
				compoundStatement();
				}
				break;
			case FOR:
			case REPEAT:
			case WHILE:
				enterOuterAlt(_localctx, 2);
				{
				setState(294);
				reptitiveStatement();
				}
				break;
			case IF:
				enterOuterAlt(_localctx, 3);
				{
				setState(295);
				ifStatement();
				}
				break;
			case CASE:
				enterOuterAlt(_localctx, 4);
				{
				setState(296);
				caseStatement();
				}
				break;
			case WITH:
				enterOuterAlt(_localctx, 5);
				{
				setState(297);
				withStatement();
				}
				break;
			case WRITE:
				enterOuterAlt(_localctx, 6);
				{
				setState(298);
				writeStatement();
				}
				break;
			case WRITELN:
				enterOuterAlt(_localctx, 7);
				{
				setState(299);
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
		enterRule(_localctx, 70, RULE_reptitiveStatement);
		try {
			setState(305);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case WHILE:
				enterOuterAlt(_localctx, 1);
				{
				setState(302);
				whileStatement();
				}
				break;
			case REPEAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(303);
				repeatStatement();
				}
				break;
			case FOR:
				enterOuterAlt(_localctx, 3);
				{
				setState(304);
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
		enterRule(_localctx, 72, RULE_writeArguments);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(307);
			writeArgs();
			setState(310);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(308);
				match(COMMA);
				setState(309);
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
		enterRule(_localctx, 74, RULE_writeArgs);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(312);
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
		enterRule(_localctx, 76, RULE_writeStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(314);
			match(WRITE);
			setState(315);
			match(LPAREN);
			setState(316);
			writeArguments();
			setState(317);
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
		enterRule(_localctx, 78, RULE_writelnStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(319);
			match(WRITELN);
			setState(320);
			match(LPAREN);
			setState(321);
			writeArguments();
			setState(322);
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
		enterRule(_localctx, 80, RULE_compoundStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(324);
			match(BEGIN);
			setState(325);
			statements();
			setState(326);
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
		enterRule(_localctx, 82, RULE_statements);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(328);
			statement();
			setState(333);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SEMICOLON) {
				{
				{
				setState(329);
				match(SEMICOLON);
				setState(330);
				statement();
				}
				}
				setState(335);
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
		enterRule(_localctx, 84, RULE_ifStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(336);
			match(IF);
			setState(337);
			expression();
			setState(338);
			match(THEN);
			setState(339);
			statement();
			setState(342);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,26,_ctx) ) {
			case 1:
				{
				setState(340);
				match(ELSE);
				setState(341);
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
		enterRule(_localctx, 86, RULE_caseStatement);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(344);
			match(CASE);
			setState(345);
			expression();
			setState(346);
			match(OF);
			setState(347);
			caseListElement();
			setState(352);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(348);
					match(SEMICOLON);
					setState(349);
					caseListElement();
					}
					} 
				}
				setState(354);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			}
			setState(358);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SEMICOLON) {
				{
				setState(355);
				match(SEMICOLON);
				setState(356);
				match(ELSE);
				setState(357);
				statements();
				}
			}

			setState(360);
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
		enterRule(_localctx, 88, RULE_caseListElement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(362);
			constant();
			setState(367);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(363);
				match(COMMA);
				setState(364);
				constant();
				}
				}
				setState(369);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(370);
			match(COLON);
			setState(371);
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
		enterRule(_localctx, 90, RULE_whileStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(373);
			match(WHILE);
			setState(374);
			expression();
			setState(375);
			match(DO);
			setState(376);
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
		enterRule(_localctx, 92, RULE_repeatStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(378);
			match(REPEAT);
			setState(379);
			statements();
			setState(380);
			match(UNTIL);
			setState(381);
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
		enterRule(_localctx, 94, RULE_forStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(383);
			match(FOR);
			setState(384);
			assignmentStatement();
			setState(385);
			_la = _input.LA(1);
			if ( !(_la==DOWNTO || _la==TO) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(386);
			expression();
			setState(387);
			match(DO);
			setState(388);
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
		enterRule(_localctx, 96, RULE_withStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(390);
			match(WITH);
			setState(391);
			variable();
			setState(396);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(392);
				match(COMMA);
				setState(393);
				variable();
				}
				}
				setState(398);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(399);
			match(DO);
			setState(400);
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3g\u0195\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\3\2\3\2\3\2\3\2\3"+
		"\2\3\3\3\3\3\3\3\3\3\3\3\3\5\3p\n\3\3\3\3\3\3\3\3\3\3\3\3\3\5\3x\n\3\3"+
		"\4\3\4\3\5\3\5\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3\b"+
		"\3\b\3\b\3\b\3\b\3\b\5\b\u0091\n\b\3\t\3\t\5\t\u0095\n\t\3\n\3\n\3\13"+
		"\3\13\3\f\3\f\3\r\3\r\3\16\3\16\5\16\u00a1\n\16\3\17\3\17\3\20\3\20\3"+
		"\20\5\20\u00a8\n\20\3\21\3\21\3\21\3\21\3\22\3\22\3\22\3\22\5\22\u00b2"+
		"\n\22\3\22\3\22\3\23\3\23\3\23\7\23\u00b9\n\23\f\23\16\23\u00bc\13\23"+
		"\3\24\3\24\3\24\3\24\3\24\5\24\u00c3\n\24\3\25\3\25\5\25\u00c7\n\25\3"+
		"\26\3\26\3\26\5\26\u00cc\n\26\3\27\3\27\3\30\3\30\3\30\3\30\3\31\3\31"+
		"\3\31\5\31\u00d7\n\31\3\31\3\31\3\31\3\31\7\31\u00dd\n\31\f\31\16\31\u00e0"+
		"\13\31\3\31\3\31\3\31\3\31\3\31\3\31\7\31\u00e8\n\31\f\31\16\31\u00eb"+
		"\13\31\3\31\3\31\3\31\3\31\3\31\7\31\u00f2\n\31\f\31\16\31\u00f5\13\31"+
		"\3\32\3\32\3\32\3\32\5\32\u00fb\n\32\3\33\3\33\3\34\3\34\3\34\3\34\5\34"+
		"\u0103\n\34\3\35\3\35\3\36\3\36\3\36\3\36\5\36\u010b\n\36\3\37\3\37\3"+
		" \5 \u0110\n \3 \3 \3!\3!\3!\3!\3!\3!\3!\3!\3!\5!\u011d\n!\3\"\3\"\3\""+
		"\3\"\5\"\u0123\n\"\3#\3#\3#\3$\3$\3$\3$\3$\3$\3$\5$\u012f\n$\3%\3%\3%"+
		"\5%\u0134\n%\3&\3&\3&\5&\u0139\n&\3\'\3\'\3(\3(\3(\3(\3(\3)\3)\3)\3)\3"+
		")\3*\3*\3*\3*\3+\3+\3+\7+\u014e\n+\f+\16+\u0151\13+\3,\3,\3,\3,\3,\3,"+
		"\5,\u0159\n,\3-\3-\3-\3-\3-\3-\7-\u0161\n-\f-\16-\u0164\13-\3-\3-\3-\5"+
		"-\u0169\n-\3-\3-\3.\3.\3.\7.\u0170\n.\f.\16.\u0173\13.\3.\3.\3.\3/\3/"+
		"\3/\3/\3/\3\60\3\60\3\60\3\60\3\60\3\61\3\61\3\61\3\61\3\61\3\61\3\61"+
		"\3\62\3\62\3\62\3\62\7\62\u018d\n\62\f\62\16\62\u0190\13\62\3\62\3\62"+
		"\3\62\3\62\2\2\63\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"$&(*,.\60\62"+
		"\64\668:<>@BDFHJLNPRTVXZ\\^`b\2\t\3\2PQ\3\2CD\7\2\b\b\n\n\34\34++AA\5"+
		"\2\32\3288TX\4\2\'\'PQ\6\2\3\3\20\20\36\36RS\4\2\22\22\60\60\2\u0195\2"+
		"d\3\2\2\2\4w\3\2\2\2\6y\3\2\2\2\b{\3\2\2\2\n}\3\2\2\2\f\u0081\3\2\2\2"+
		"\16\u0090\3\2\2\2\20\u0094\3\2\2\2\22\u0096\3\2\2\2\24\u0098\3\2\2\2\26"+
		"\u009a\3\2\2\2\30\u009c\3\2\2\2\32\u00a0\3\2\2\2\34\u00a2\3\2\2\2\36\u00a7"+
		"\3\2\2\2 \u00a9\3\2\2\2\"\u00ad\3\2\2\2$\u00b5\3\2\2\2&\u00c2\3\2\2\2"+
		"(\u00c6\3\2\2\2*\u00cb\3\2\2\2,\u00cd\3\2\2\2.\u00cf\3\2\2\2\60\u00d6"+
		"\3\2\2\2\62\u00f6\3\2\2\2\64\u00fc\3\2\2\2\66\u00fe\3\2\2\28\u0104\3\2"+
		"\2\2:\u0106\3\2\2\2<\u010c\3\2\2\2>\u010f\3\2\2\2@\u011c\3\2\2\2B\u0122"+
		"\3\2\2\2D\u0124\3\2\2\2F\u012e\3\2\2\2H\u0133\3\2\2\2J\u0135\3\2\2\2L"+
		"\u013a\3\2\2\2N\u013c\3\2\2\2P\u0141\3\2\2\2R\u0146\3\2\2\2T\u014a\3\2"+
		"\2\2V\u0152\3\2\2\2X\u015a\3\2\2\2Z\u016c\3\2\2\2\\\u0177\3\2\2\2^\u017c"+
		"\3\2\2\2`\u0181\3\2\2\2b\u0188\3\2\2\2de\5\4\3\2ef\5R*\2fg\7<\2\2gh\7"+
		"\2\2\3h\3\3\2\2\2ij\7*\2\2jo\5\6\4\2kl\7`\2\2lm\5$\23\2mn\7a\2\2np\3\2"+
		"\2\2ok\3\2\2\2op\3\2\2\2pq\3\2\2\2qr\7^\2\2rx\3\2\2\2st\7>\2\2tu\5\6\4"+
		"\2uv\7^\2\2vx\3\2\2\2wi\3\2\2\2ws\3\2\2\2x\5\3\2\2\2yz\7H\2\2z\7\3\2\2"+
		"\2{|\5\22\n\2|\t\3\2\2\2}~\5\6\4\2~\177\78\2\2\177\u0080\5\16\b\2\u0080"+
		"\13\3\2\2\2\u0081\u0082\7\13\2\2\u0082\u0083\7`\2\2\u0083\u0084\5\22\n"+
		"\2\u0084\u0085\7a\2\2\u0085\r\3\2\2\2\u0086\u0091\5\20\t\2\u0087\u0088"+
		"\5\26\f\2\u0088\u0089\5\20\t\2\u0089\u0091\3\2\2\2\u008a\u0091\5\6\4\2"+
		"\u008b\u008c\5\26\f\2\u008c\u008d\5\6\4\2\u008d\u0091\3\2\2\2\u008e\u0091"+
		"\5\34\17\2\u008f\u0091\5\f\7\2\u0090\u0086\3\2\2\2\u0090\u0087\3\2\2\2"+
		"\u0090\u008a\3\2\2\2\u0090\u008b\3\2\2\2\u0090\u008e\3\2\2\2\u0090\u008f"+
		"\3\2\2\2\u0091\17\3\2\2\2\u0092\u0095\5\22\n\2\u0093\u0095\5\24\13\2\u0094"+
		"\u0092\3\2\2\2\u0094\u0093\3\2\2\2\u0095\21\3\2\2\2\u0096\u0097\7J\2\2"+
		"\u0097\23\3\2\2\2\u0098\u0099\7K\2\2\u0099\25\3\2\2\2\u009a\u009b\t\2"+
		"\2\2\u009b\27\3\2\2\2\u009c\u009d\t\3\2\2\u009d\31\3\2\2\2\u009e\u00a1"+
		"\5\6\4\2\u009f\u00a1\t\4\2\2\u00a0\u009e\3\2\2\2\u00a0\u009f\3\2\2\2\u00a1"+
		"\33\3\2\2\2\u00a2\u00a3\7I\2\2\u00a3\35\3\2\2\2\u00a4\u00a8\5 \21\2\u00a5"+
		"\u00a8\5\32\16\2\u00a6\u00a8\5\"\22\2\u00a7\u00a4\3\2\2\2\u00a7\u00a5"+
		"\3\2\2\2\u00a7\u00a6\3\2\2\2\u00a8\37\3\2\2\2\u00a9\u00aa\7`\2\2\u00aa"+
		"\u00ab\5$\23\2\u00ab\u00ac\7a\2\2\u00ac!\3\2\2\2\u00ad\u00ae\7A\2\2\u00ae"+
		"\u00b1\7b\2\2\u00af\u00b2\5\6\4\2\u00b0\u00b2\5\20\t\2\u00b1\u00af\3\2"+
		"\2\2\u00b1\u00b0\3\2\2\2\u00b2\u00b3\3\2\2\2\u00b3\u00b4\7c\2\2\u00b4"+
		"#\3\2\2\2\u00b5\u00ba\5\6\4\2\u00b6\u00b7\7_\2\2\u00b7\u00b9\5\6\4\2\u00b8"+
		"\u00b6\3\2\2\2\u00b9\u00bc\3\2\2\2\u00ba\u00b8\3\2\2\2\u00ba\u00bb\3\2"+
		"\2\2\u00bb%\3\2\2\2\u00bc\u00ba\3\2\2\2\u00bd\u00be\5\b\5\2\u00be\u00bf"+
		"\7\67\2\2\u00bf\u00c0\5(\25\2\u00c0\u00c3\3\2\2\2\u00c1\u00c3\5(\25\2"+
		"\u00c2\u00bd\3\2\2\2\u00c2\u00c1\3\2\2\2\u00c3\'\3\2\2\2\u00c4\u00c7\5"+
		"*\26\2\u00c5\u00c7\5F$\2\u00c6\u00c4\3\2\2\2\u00c6\u00c5\3\2\2\2\u00c7"+
		")\3\2\2\2\u00c8\u00cc\5.\30\2\u00c9\u00cc\5D#\2\u00ca\u00cc\5,\27\2\u00cb"+
		"\u00c8\3\2\2\2\u00cb\u00c9\3\2\2\2\u00cb\u00ca\3\2\2\2\u00cc+\3\2\2\2"+
		"\u00cd\u00ce\3\2\2\2\u00ce-\3\2\2\2\u00cf\u00d0\5\60\31\2\u00d0\u00d1"+
		"\7\66\2\2\u00d1\u00d2\5\62\32\2\u00d2/\3\2\2\2\u00d3\u00d4\7;\2\2\u00d4"+
		"\u00d7\5\6\4\2\u00d5\u00d7\5\6\4\2\u00d6\u00d3\3\2\2\2\u00d6\u00d5\3\2"+
		"\2\2\u00d7\u00f3\3\2\2\2\u00d8\u00d9\7b\2\2\u00d9\u00de\5\62\32\2\u00da"+
		"\u00db\7_\2\2\u00db\u00dd\5\62\32\2\u00dc\u00da\3\2\2\2\u00dd\u00e0\3"+
		"\2\2\2\u00de\u00dc\3\2\2\2\u00de\u00df\3\2\2\2\u00df\u00e1\3\2\2\2\u00e0"+
		"\u00de\3\2\2\2\u00e1\u00e2\7c\2\2\u00e2\u00f2\3\2\2\2\u00e3\u00e4\79\2"+
		"\2\u00e4\u00e9\5\62\32\2\u00e5\u00e6\7_\2\2\u00e6\u00e8\5\62\32\2\u00e7"+
		"\u00e5\3\2\2\2\u00e8\u00eb\3\2\2\2\u00e9\u00e7\3\2\2\2\u00e9\u00ea\3\2"+
		"\2\2\u00ea\u00ec\3\2\2\2\u00eb\u00e9\3\2\2\2\u00ec\u00ed\7:\2\2\u00ed"+
		"\u00f2\3\2\2\2\u00ee\u00ef\7<\2\2\u00ef\u00f2\5\6\4\2\u00f0\u00f2\7]\2"+
		"\2\u00f1\u00d8\3\2\2\2\u00f1\u00e3\3\2\2\2\u00f1\u00ee\3\2\2\2\u00f1\u00f0"+
		"\3\2\2\2\u00f2\u00f5\3\2\2\2\u00f3\u00f1\3\2\2\2\u00f3\u00f4\3\2\2\2\u00f4"+
		"\61\3\2\2\2\u00f5\u00f3\3\2\2\2\u00f6\u00fa\5\66\34\2\u00f7\u00f8\5\64"+
		"\33\2\u00f8\u00f9\5\62\32\2\u00f9\u00fb\3\2\2\2\u00fa\u00f7\3\2\2\2\u00fa"+
		"\u00fb\3\2\2\2\u00fb\63\3\2\2\2\u00fc\u00fd\t\5\2\2\u00fd\65\3\2\2\2\u00fe"+
		"\u0102\5:\36\2\u00ff\u0100\58\35\2\u0100\u0101\5\66\34\2\u0101\u0103\3"+
		"\2\2\2\u0102\u00ff\3\2\2\2\u0102\u0103\3\2\2\2\u0103\67\3\2\2\2\u0104"+
		"\u0105\t\6\2\2\u01059\3\2\2\2\u0106\u010a\5> \2\u0107\u0108\5<\37\2\u0108"+
		"\u0109\5:\36\2\u0109\u010b\3\2\2\2\u010a\u0107\3\2\2\2\u010a\u010b\3\2"+
		"\2\2\u010b;\3\2\2\2\u010c\u010d\t\7\2\2\u010d=\3\2\2\2\u010e\u0110\t\2"+
		"\2\2\u010f\u010e\3\2\2\2\u010f\u0110\3\2\2\2\u0110\u0111\3\2\2\2\u0111"+
		"\u0112\5@!\2\u0112?\3\2\2\2\u0113\u011d\5\60\31\2\u0114\u0115\7`\2\2\u0115"+
		"\u0116\5\62\32\2\u0116\u0117\7a\2\2\u0117\u011d\3\2\2\2\u0118\u011d\5"+
		"B\"\2\u0119\u011a\7#\2\2\u011a\u011d\5@!\2\u011b\u011d\5\30\r\2\u011c"+
		"\u0113\3\2\2\2\u011c\u0114\3\2\2\2\u011c\u0118\3\2\2\2\u011c\u0119\3\2"+
		"\2\2\u011c\u011b\3\2\2\2\u011dA\3\2\2\2\u011e\u0123\5\20\t\2\u011f\u0123"+
		"\5\f\7\2\u0120\u0123\5\34\17\2\u0121\u0123\7\37\2\2\u0122\u011e\3\2\2"+
		"\2\u0122\u011f\3\2\2\2\u0122\u0120\3\2\2\2\u0122\u0121\3\2\2\2\u0123C"+
		"\3\2\2\2\u0124\u0125\7\30\2\2\u0125\u0126\5\b\5\2\u0126E\3\2\2\2\u0127"+
		"\u012f\5R*\2\u0128\u012f\5H%\2\u0129\u012f\5V,\2\u012a\u012f\5X-\2\u012b"+
		"\u012f\5b\62\2\u012c\u012f\5N(\2\u012d\u012f\5P)\2\u012e\u0127\3\2\2\2"+
		"\u012e\u0128\3\2\2\2\u012e\u0129\3\2\2\2\u012e\u012a\3\2\2\2\u012e\u012b"+
		"\3\2\2\2\u012e\u012c\3\2\2\2\u012e\u012d\3\2\2\2\u012fG\3\2\2\2\u0130"+
		"\u0134\5\\/\2\u0131\u0134\5^\60\2\u0132\u0134\5`\61\2\u0133\u0130\3\2"+
		"\2\2\u0133\u0131\3\2\2\2\u0133\u0132\3\2\2\2\u0134I\3\2\2\2\u0135\u0138"+
		"\5L\'\2\u0136\u0137\7_\2\2\u0137\u0139\5L\'\2\u0138\u0136\3\2\2\2\u0138"+
		"\u0139\3\2\2\2\u0139K\3\2\2\2\u013a\u013b\5\62\32\2\u013bM\3\2\2\2\u013c"+
		"\u013d\7!\2\2\u013d\u013e\7`\2\2\u013e\u013f\5J&\2\u013f\u0140\7a\2\2"+
		"\u0140O\3\2\2\2\u0141\u0142\7\"\2\2\u0142\u0143\7`\2\2\u0143\u0144\5J"+
		"&\2\u0144\u0145\7a\2\2\u0145Q\3\2\2\2\u0146\u0147\7\6\2\2\u0147\u0148"+
		"\5T+\2\u0148\u0149\7\24\2\2\u0149S\3\2\2\2\u014a\u014f\5&\24\2\u014b\u014c"+
		"\7^\2\2\u014c\u014e\5&\24\2\u014d\u014b\3\2\2\2\u014e\u0151\3\2\2\2\u014f"+
		"\u014d\3\2\2\2\u014f\u0150\3\2\2\2\u0150U\3\2\2\2\u0151\u014f\3\2\2\2"+
		"\u0152\u0153\7\31\2\2\u0153\u0154\5\62\32\2\u0154\u0155\7/\2\2\u0155\u0158"+
		"\5&\24\2\u0156\u0157\7\23\2\2\u0157\u0159\5&\24\2\u0158\u0156\3\2\2\2"+
		"\u0158\u0159\3\2\2\2\u0159W\3\2\2\2\u015a\u015b\7\t\2\2\u015b\u015c\5"+
		"\62\32\2\u015c\u015d\7$\2\2\u015d\u0162\5Z.\2\u015e\u015f\7^\2\2\u015f"+
		"\u0161\5Z.\2\u0160\u015e\3\2\2\2\u0161\u0164\3\2\2\2\u0162\u0160\3\2\2"+
		"\2\u0162\u0163\3\2\2\2\u0163\u0168\3\2\2\2\u0164\u0162\3\2\2\2\u0165\u0166"+
		"\7^\2\2\u0166\u0167\7\23\2\2\u0167\u0169\5T+\2\u0168\u0165\3\2\2\2\u0168"+
		"\u0169\3\2\2\2\u0169\u016a\3\2\2\2\u016a\u016b\7\24\2\2\u016bY\3\2\2\2"+
		"\u016c\u0171\5\16\b\2\u016d\u016e\7_\2\2\u016e\u0170\5\16\b\2\u016f\u016d"+
		"\3\2\2\2\u0170\u0173\3\2\2\2\u0171\u016f\3\2\2\2\u0171\u0172\3\2\2\2\u0172"+
		"\u0174\3\2\2\2\u0173\u0171\3\2\2\2\u0174\u0175\7\67\2\2\u0175\u0176\5"+
		"&\24\2\u0176[\3\2\2\2\u0177\u0178\7\64\2\2\u0178\u0179\5\62\32\2\u0179"+
		"\u017a\7\21\2\2\u017a\u017b\5&\24\2\u017b]\3\2\2\2\u017c\u017d\7-\2\2"+
		"\u017d\u017e\5T+\2\u017e\u017f\7\62\2\2\u017f\u0180\5\62\32\2\u0180_\3"+
		"\2\2\2\u0181\u0182\7\26\2\2\u0182\u0183\5.\30\2\u0183\u0184\t\b\2\2\u0184"+
		"\u0185\5\62\32\2\u0185\u0186\7\21\2\2\u0186\u0187\5&\24\2\u0187a\3\2\2"+
		"\2\u0188\u0189\7\65\2\2\u0189\u018e\5\60\31\2\u018a\u018b\7_\2\2\u018b"+
		"\u018d\5\60\31\2\u018c\u018a\3\2\2\2\u018d\u0190\3\2\2\2\u018e\u018c\3"+
		"\2\2\2\u018e\u018f\3\2\2\2\u018f\u0191\3\2\2\2\u0190\u018e\3\2\2\2\u0191"+
		"\u0192\7\21\2\2\u0192\u0193\5&\24\2\u0193c\3\2\2\2!ow\u0090\u0094\u00a0"+
		"\u00a7\u00b1\u00ba\u00c2\u00c6\u00cb\u00d6\u00de\u00e9\u00f1\u00f3\u00fa"+
		"\u0102\u010a\u010f\u011c\u0122\u012e\u0133\u0138\u014f\u0158\u0162\u0168"+
		"\u0171\u018e";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}