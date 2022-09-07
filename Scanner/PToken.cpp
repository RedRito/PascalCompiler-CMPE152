//Initialize reserved words map:
map<string, Token> Token::ReservedWord;
void Token::initMaps()
{
    ReservedWord["AND"] = AND;
    ReservedWord["ARRAY"] = ARRAY;
    ReservedWord["ASM"] = ASM;
    ReservedWord["BEGIN"] = BEGIN;
    ReservedWord["BREAK"] = BREAK;
    ReservedWord["CASE"] = CASE;
    ReservedWord["CONST"] = CONST;
    ReservedWord["CONSTRUCTOR"] = CONSTRUCTOR;
    ReservedWord["CONTINUE"] = CONTINUE;
    ReservedWord["DESTRUCTOR"] = DESTRUCTOR;
    ReservedWord["DIV"] = DIV;
    ReservedWord["DO"] = DO;
    ReservedWord["DOWNTO"] = DOWNTO;
    ReservedWord["ELSE"] = ELSE;
    ReservedWord["END"] = END;
    ReservedWord["FALSE"] = FALSE;
    ReservedWord["FILE"] = FILE;
    ReservedWord["FOR"] = FOR;
    ReservedWord["FUNCTION"] = FUNCTION;
    ReservedWord["GOTO"] = GOTO;
    ReservedWord["IF"] = IF;
    ReservedWord["IMPLEMENTATION"] = IMPLEMENTATION;
    ReservedWord["IN"] = IN;
    ReservedWord["INLINE"] = INLINE;
    ReservedWord["INTERFACE"] = INTERFACE;
    ReservedWord["LABEL"] = LABEL;
    ReservedWord["MOD"] = MOD;
    ReservedWord["NIL"] = NIL;
    ReservedWord["NOT"] = NOT;
    ReservedWord["OBJECT"] = OBJECT;
    ReservedWord["OF"] = OF;
    ReservedWord["ON"] = ON;
    ReservedWord["OPERATOR"] = OPERATOR;
    ReservedWord["OR"] = OR;
    ReservedWord["PACKED"] = PACKED;
    ReservedWord["PROCEDURE"] = PROCEDURE;
    ReservedWord["PROGRAM"] = PROGRAM;
    ReservedWord["RECORD"] = RECORD;
    ReservedWord["REPEAT"] = REPEAT;
    ReservedWord["SET"] = SET;
    ReservedWord["SHL"] = SHL;
    ReservedWord["SHR"] = SHR;
    ReservedWord["STRING"] = STRING;
    ReservedWord["THEN"] = THEN;
    ReservedWord["TO"] = TO;
    ReservedWord["TRUE"] = TRUE;
    ReservedWord["TYPE"] = TYPE;
    ReservedWord["UNIT"] = UNIT;
    ReservedWord["UNTIL"] = UNTIL;
    ReservedWord["USES"] = USES;
    ReservedWord["VAR"] = VAR;
    ReservedWord["WHILE"] = WHILE;
    ReservedWord["WITH"] = WITH;
    ReservedWord["XOR"] = XOR;
}
//Initialize symbols map:
map<string, Token> Token::Symbols;
void Token::initMaps()
{
    Symbols["PLUSOP"] = PLUSOP;
    Symbols["MINUSOP"] = MINUSOP;
    Symbols["MULTOP"] = MULTOP;
    Symbols["DIVOP"] = DIVOP;
    Symbols["ASSIGN"] = ASSIGN;
    Symbols["EQUAL"] = EQUAL;
    Symbols["NE"] = NE;
    Symbols["LTEQ"] = LTEQ;
    Symbols["GTEQ"] = GTEQ;
    Symbols["LT"] = LT;
    Symbols["GT"] = GT;
    Symbols["PLUSEQUAL"] = PLUSEQUAL;
    Symbols["MINUSEQUAL"] = MINUSEQUAL;
    Symbols["MULTEQUAL"] = MULTEQUAL;
    Symbols["DIVEQUAL"] = DIVEQUAL;
    Symbols["CARAT"] = CARAT;
    Symbols["SEMICOLOR"] = SEMICOLOR;
    Symbols["COMMA"] = COMMA;
    Symbols["LPAREN"] = LPAREN;
    Symbols["RPAREN"] = RPAREN;
    Symbols["LBRACKET"] = LBRACKET;
    Symbols["RBRACKET"] = RBRACKET;
    Symbols["LBRACE"] = LBRACE;
    Symbols["RBRACE"] = RBRACE;
    Symbols["LCOMMENT"] = LCOMMENT;
    Symbols["RCOMMENT"] = RCOMMENT;
}
Token *Token::Word(char firstChar, Source *source)
{
    Token *token = new Token(firstChar);
    token->lineNumber = source->lineNumber();

    // Loop to get the rest of the characters of the word token.
    // Append letters and digits to the token.
    for (char ch = source->nextChar(); isalnum(ch); ch = source->nextChar())
    {
        token->text += ch;
    }

    // Is it a reserved word or an identifier?
    string upper = toUpperCase(token->text);
    if (Token::reservedWords.find(upper) != Token::reservedWords.end())
    {
        token->type = Token::reservedWords[upper];
    }
    else
    {
        token->type = TokenType::IDENTIFIER;
    }

    return token;
}

Token *Token::Number(char firstChar, Source *source)
{
    Token *token = new Token(firstChar);
    token->lineNumber = source->lineNumber();
    int pointCount = 0;

    // Loop to get the rest of the characters of the number token.
    // Append digits to the token.
    for (char ch = source->nextChar();
         isdigit(ch) || (ch == '.');
         ch = source->nextChar())
    {
        if (ch == '.') pointCount++;
        token->text += ch;
    }

    // Integer constant.
    if (pointCount == 0)
    {
        token->type    = TokenType::INTEGER;
        token->value.L = stol(token->text);
        token->value.D = token->value.L;  // allow using integer value as double
    }

    // Real constant.
    else if (pointCount == 1)
    {
        token->type    = TokenType::REAL;
        token->value.D = stod(token->text);
    }

    else
    {
        token->type = TokenType::ERROR;
        tokenError(token, "Invalid number");
    }

    return token;
}

Token *Token::CharacterOrString(char firstChar, Source *source)
{
    Token *token = new Token(firstChar);  // the leading '
    token->lineNumber = source->lineNumber();
    int length = 0;                       // string length

    // Loop to append the rest of the characters of the string,
    // up to but not including the closing quote.
    bool done = false;
    char ch = source->nextChar();
    do
    {
        // Append characters to the string until ' or EOF.
        while ((ch != '\'') && (ch != EOF))
        {
            token->text += ch;
            length++;
            ch = source->nextChar();  // consume the character
        }

        // End of file. An unclosed string.
        if (ch == EOF)
        {
            tokenError(token, "String not closed");
            done = true;
        }

        // Got a ' so it can be the closing ', or a ''
        else
        {
            ch = source->nextChar();  // consume the '

            // That was the closing '. Close the string.
            if (ch != '\'')
            {
                token->text += '\'';
                done = true;
            }

            // It's '' so append ' to the string.
            else
            {
                token->text += '\'';
                length++;
                ch = source->nextChar();  // consume second '
            }
        }
    } while (!done);

    // It's a character token if the string length is 1.
    // Otherwise, it's a string token.
    token->type = length == 1 ? TokenType::CHARACTER : TokenType::STRING;

    // Don't include the leading and trailing '.
    token->value.S = token->text.substr(1, token->text.length() - 2);

    return token;
}
