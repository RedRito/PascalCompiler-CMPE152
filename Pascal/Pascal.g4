grammar Pascal;

@header{
   #include "PassOne/Typespec.h"
   #include "PassOne/Symtab.h"
   #include "PassOne/SymtabStack.h"
   #include "Object.h"
   using namespace PassOne::symtab;
   using namespace PassOne::type;
}


program
   : programHead block DOT EOF
   ;

programHead locals [ SymtabEntry *entry = nullptr ]
   : PROGRAM identifier (LPAREN identifierList RPAREN)? SEMICOLON
   | UNIT identifier SEMICOLON
   ;

identifier locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
   : IDENT
   ;

block
   : (labelDeclarationPart | constantDefinitionPart | typeDefinitionPart | procedureAndFunctionDeclarationPart | variableDeclarationPart | usesUnitsPart | IMPLEMENTATION)* compoundStatement
   ;

usesUnitsPart
   : USES identifierList SEMICOLON
   ;

labelDeclarationPart
   : LABEL label (COMMA label)* SEMICOLON
   ;

constantDefinitionPart
   : CONST (constantDefinition SEMICOLON) +
   ;

constantDefinition
   : constantIdentifier EQUAL constant
   ;

constantIdentifier locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
   : IDENT
   ;

typeDefinitionPart
   : TYPE (typeDefinition SEMICOLON) +
   ;

typeDefinition
   : typeIdentifier EQUAL (type_ | functionType | procedureType)
   ;



formalParameterList locals[ Typespec *type = nullptr ]
   : LPAREN formalParameterSection (SEMICOLON formalParameterSection)* RPAREN
   ;

formalParameterSection
   : parameterGroup
   | VAR parameterGroup
   | FUNCTION parameterGroup
   | PROCEDURE parameterGroup
   ;

parameterGroup
   : identifierList COLON typeIdentifier
   ;

functionType locals [ Typespec *type = nullptr ]
   : FUNCTION (formalParameterList)? COLON typeIdentifier
   ;

procedureType
   : PROCEDURE (formalParameterList)?
   ;

variableDeclarationPart
   : VAR variableDeclaration (SEMICOLON variableDeclaration)* SEMICOLON
   ;

variableDeclaration
   : identifierList COLON type_
   ;

procedureAndFunctionDeclarationPart
   : procedureOrFunctionDeclaration SEMICOLON
   ;

procedureOrFunctionDeclaration
   : procedureDeclaration
   | functionDeclaration
   ;

procedureDeclaration locals [ SymtabEntry *entry = nullptr ]
   : PROCEDURE identifier (formalParameterList)? SEMICOLON block
   ;

functionDeclaration locals[ Typespec *type = nullptr , SymtabEntry *entry = nullptr]
   : FUNCTION identifier (formalParameterList)? COLON typeIdentifier SEMICOLON block
   ;


type_ locals [ Typespec *type = nullptr ]
   : simpleType
   | structuredType
   | pointerType
   ;

structuredType locals [ Typespec *type = nullptr ]
   : PACKED unpackedStructuredType
   | unpackedStructuredType
   ;

unpackedStructuredType locals [ Typespec *type = nullptr ]
   : arrayType
   ;

arrayType
   : ARRAY LBRACKET typeList RBRACKET OF type_
   | ARRAY LBRACKET2 typeList RBRACKET2 OF type_
   ;

typeList
   : simpleType (COMMA simpleType)*
   ;

pointerType
   : CARAT typeIdentifier
   ;


label
   : unsignedInteger
   ;

constantVar
   : identifier EQUAL constant
   ;

constantChr
   : CHR LPAREN unsignedInteger RPAREN
   ;

constant locals [ Typespec *type = nullptr, Object value = nullptr]
   : unsignedNumber
   | sign unsignedNumber
   | identifier
   | sign identifier
   | string
   | constantChr
   ;

unsignedNumber locals[ Typespec *type = nullptr ]
   : unsignedInteger
   | unsignedReal
   ;

unsignedInteger
   : NUM_INT
   ;

unsignedReal
   : NUM_REAL
   ;

sign
   : PLUSOP
   | MINUSOP
   ;

bool_
   : TRUE
   | FALSE
   ;

typeIdentifier locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
   : identifier
   | (CHAR | BOOLEAN | INTEGER | REAL | STRING)
   ;

string
   : STRING_LITERAL
   ;

simpleType locals [ Typespec *type = nullptr ]
   : scalarType
   | typeIdentifier
   | stringtype
   ;

scalarType
   : LPAREN identifierList RPAREN
   ;


stringtype
   : STRING LBRACKET (identifier | unsignedNumber) RBRACKET
   ;

identifierList
   : identifier (COMMA identifier)*
   ;


statement
   : label COLON unlabelledStatement
   | unlabelledStatement
   | procedureAndFunctionDeclarationPart
   ;

unlabelledStatement
   : simpleStatement
   | structuredStatement
   ;

simpleStatement
   : assignmentStatement
   | procedureStatement
   | gotoStatement
   | emptyStatement_
   ;

procedureStatement
   : identifier (LPAREN parameterList RPAREN)?
   ;

emptyStatement_
   :
   ;
assignmentStatement
   : variable ASSIGN expression
   ;

variable locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
   : (AT variableIdentifier | variableIdentifier) modifier*
   ;
variableIdentifier locals [ Typespec *type = nullptr, SymtabEntry *entry = nullptr ]
   : IDENT
   ;
modifier
   : LBRACKET expression (COMMA expression)* RBRACKET | LBRACKET2 expression (COMMA expression)* RBRACKET2 | DOT identifier | CARAT
   ;

expression locals [ Typespec *type = nullptr ]
   : simpleExpression (relationaloperator expression)*
   ;

relationaloperator
   : EQUAL
   | NE
   | LT
   | LTEQ
   | GTEQ
   | GT
   | IN
   ;

simpleExpression locals [ Typespec *type = nullptr ]
   : term (additiveoperator simpleExpression)*
   ;

additiveoperator 
   : PLUSOP
   | MINUSOP
   | OR
   ;

term locals [ Typespec *type = nullptr ]
   : signedFactor (multiplicativeoperator term)*
   ;

multiplicativeoperator
   : MULTOP
   | DIVOP
   | DIV
   | MOD
   | AND
   ;

signedFactor
   : (PLUSOP | MINUSOP)? factor
   ;

factor locals [ Typespec *type = nullptr ]
   : variable
   | LPAREN expression RPAREN
   | functionDesignator
   | unsignedConstant
   | set_
   | NOT factor
   | bool_
   ;

unsignedConstant locals [ Typespec *type = nullptr ]
   : unsignedNumber
   | constantChr
   | string
   | NIL
   ;

functionDesignator
   : identifier LPAREN parameterList RPAREN
   ;

parameterList
   : actualParameter (COMMA actualParameter)*
   ;

actualParameter
   : expression parameterwidth*
   ;

parameterwidth
   : ':' expression
   ;   

set_
   : LBRACKET element (COMMA element)* RBRACKET
   | LBRACKET2 element (COMMA element)* RBRACKET2
   ;

element
   : expression (DOTDOT expression)?
   ;

gotoStatement
   : GOTO label
   ;

structuredStatement
   : compoundStatement
   | reptitiveStatement
   | ifStatement
   | caseStatement
   | withStatement
   | writeStatement
   | writelnStatement
   ;

reptitiveStatement
   : whileStatement
   | repeatStatement
   | forStatement
   ;

writeArguments
   :  writeArgs (COMMA writeArgs)?
   ;

writeArgs
   : expression
   ;

writeStatement
   :  WRITE LPAREN writeArguments RPAREN
   ;

writelnStatement
   : WRITELN LPAREN writeArguments RPAREN
   ;

compoundStatement
   : BEGIN statements END
   ;

statements
   : statement (SEMICOLON statement)*
   ;

ifStatement
   : IF expression THEN statement (: ELSE statement)?
   ;

caseStatement
   : CASE expression OF caseListElement (SEMICOLON caseListElement)* (SEMICOLON ELSE statements)? END
   ;

caseListElement
   : constant (COMMA constant)* COLON statement
   ;

whileStatement
   : WHILE expression DO statement
   ;

repeatStatement
   : REPEAT statements UNTIL expression
   ;

forStatement
   : FOR assignmentStatement (TO | DOWNTO) expression DO statement
   ;

withStatement
   : WITH variable (COMMA variable)* DO statement
   ;


AND
   : A N D
   ;


ARRAY
   : A R R A Y
   ;


ASM
   : A S M
   ;


BEGIN
   : B E G I N
   ;


BREAK
   : B R E A K
   ;


BOOLEAN
   : B O O L E A N
   ;


CASE
   : C A S E
   ;


CHAR
   : C H A R
   ;


CHR
   : C H R
   ;


CONST
   : C O N S T
   ;


CONSTRUCTOR
   : C O N S T R U C T O R
   ;


CONTINUE
   : C O N T I N U E
   ;


DESTRUCTOR
   : D E S T R U C T O R
   ;


DIV
   : D I V
   ;


DO
   : D O
   ;


DOWNTO
   : D O W N T O
   ;


ELSE
   : E L S E
   ;


END
   : E N D
   ;


FILE
   : F I L E
   ;


FOR
   : F O R
   ;


FUNCTION
   : F U N C T I O N
   ;


GOTO
   : G O T O
   ;


IF
   : I F
   ;


IN
   : I N
   ;


INLINE
   : I N L I N E
   ;


INTEGER
   : I N T E G E R
   ;


LABEL
   : L A B E L
   ;


MOD
   : M O D
   ;


NIL
   : N I L
   ;


OBJECT
   : O B J E C T
   ;
WRITE
   : W R I T E
   ;
WRITELN
   : W R I T E L N
   ;



NOT
   : N O T
   ;


OF
   : O F
   ;


ON
   : O N
   ;


OPERATOR
   : O P E R A T O R
   ;


OR
   : O R
   ;


PACKED
   : P A C K E D
   ;


PROCEDURE
   : P R O C E D U R E
   ;


PROGRAM
   : P R O G R A M
   ;


REAL
   : R E A L
   ;


RECORD
   : R E C O R D
   ;


REPEAT
   : R E P E A T
   ;


SET
   : S E T
   ;


THEN
   : T H E N
   ;


TO
   : T O
   ;


TYPE
   : T Y P E
   ;


UNTIL
   : U N T I L
   ;


VAR
   : V A R
   ;


WHILE
   : W H I L E
   ;


WITH
   : W I T H
   ;
   

ASSIGN
   : ':='
   ;


COLON
   : ':'
   ;


EQUAL
   : '='
   ;


LBRACKET2
   : '(.'
   ;


RBRACKET2
   : '.)'
   ;




AT
   : '@'
   ;


DOT
   : '.'
   ;


DOTDOT
   : '..'
   ;


UNIT
   : U N I T
   ;


INTERFACE
   : I N T E R F A C E
   ;


USES
   : U S E S
   ;


STRING
   : S T R I N G
   ;


IMPLEMENTATION
   : I M P L E M E N T A T I O N
   ;


TRUE
   : T R U E
   ;


FALSE
   : F A L S E
   ;


WS
   : [ \t\r\n] -> skip
   ;


COMMENT_1
   : '(*' .*? '*)' -> skip
   ;


COMMENT_2
   : '{' .*? '}' -> skip
   ;


IDENT
   : [a-zA-Z][a-zA-Z0-9]* 
   ;

STRING_LITERAL
   : '\'' ('\'\'' | ~ ('\''))* '\''
   ;


NUM_INT
   : [0-9]+ ;


NUM_REAL
   : NUM_INT DOT NUM_INT
   | NUM_INT ('e' | 'E') ('+' | '-')? NUM_INT
   | NUM_INT DOT NUM_INT ('e' | 'E') ('+' | '-')? NUM_INT
   ;


fragment EXPONENT
   : ('E') ('+' | '-')? ('0' .. '9') +
   ;

SHL		   
   : S H L
   ;
SHR		   
   : S H R
   ;
XOR
   : X O R
   ;
IDENTIFIER
   : I D E N T I F I E R
   ;
PLUSOP
   : '+'
   ;
MINUSOP
   : '-'
   ;
MULTOP
   : '*'
   ;
DIVOP
   : '/'
   ;
NE
   : '<>'
   ;
LTEQ
   : '<='
   ;
GTEQ
   : '>='
   ;
LT
   : '<'
   ;
GT
   : '>'
   ;
PLUSEQUAL
   : '+='
   ;
MINUSEQUAL
   : '-='
   ;
MULTEQUAL
   : '*='
   ;
DIVEQUAL
   : '/='
   ;
CARAT
   : '^'
   ;
SEMICOLON
   : ';'
   ;
COMMA
   : ','
   ;
LPAREN
   : '('
   ;
RPAREN
   : ')'
   ;
LBRACKET
   : '['
   ;
RBRACKET
   : ']'
   ;
LBRACE
   : '{'
   ;
RBRACE
   : '}'
   ;
LCOMMENT
   : '(*'
   ;
RCOMMENT
   : '*)'
   ;


fragment A 
	: ('a' | 'A') 
	;
fragment B 
	: ('b' | 'B') 
	;
fragment C 
	: ('c' | 'C') 
	;
fragment D 
	: ('d' | 'D') 
	;
fragment E 
	: ('e' | 'E') 
	;
fragment F 
	: ('f' | 'F') 
	;
fragment G 
	: ('g' | 'G') 
	;
fragment H 
	: ('h' | 'H') 
	;
fragment I 
	: ('i' | 'I') 
	;
fragment J 
	: ('j' | 'J') 
	;
fragment K 
	: ('k' | 'K') 
	;
fragment L 
	: ('l' | 'L') 
	;
fragment M 
	: ('m' | 'M') 
	;
fragment N 
	: ('n' | 'N') 
	;
fragment O 
	: ('o' | 'O') 
	;
fragment P 
	: ('p' | 'P') 
	;
fragment Q 
	: ('q' | 'Q') 
	;
fragment R 
	: ('r' | 'R') 
	;
fragment S 
	: ('s' | 'S') 
	;
fragment T 
	: ('t' | 'T') 
	;
fragment U 
	: ('u' | 'U') 
	;
fragment V 
	: ('v' | 'V') 
	;
fragment W 
	: ('w' | 'W') 
	;
fragment X 
	: ('x' | 'X') 
	;
fragment Y 
	: ('y' | 'Y') 
	;
fragment Z 
	: ('z' | 'Z')
	;