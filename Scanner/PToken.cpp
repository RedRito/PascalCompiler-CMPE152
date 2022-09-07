//Initialize reserved words map:
map<string, Token> Token::ReservedWord;
void Token::initMaps()
{
    ReservedWord["AND"] = PToken::AND;
    ReservedWord["ARRAY"] = PToken::ARRAY;
    ReservedWord["ASM"] = PToken::ASM;
    ReservedWord["BEGIN"] = PToken::BEGIN;
    ReservedWord["BREAK"] = PToken::BREAK;
    ReservedWord["CASE"] = PToken::CASE;
    ReservedWord["CONST"] = PToken::CONST;
    ReservedWord["CONSTRUCTOR"] = PToken::CONSTRUCTOR;
    ReservedWord["CONTINUE"] = PToken::CONTINUE;
    ReservedWord["DESTRUCTOR"] = PToken::DESTRUCTOR;
    ReservedWord["DIV"] = PToken::DIV;
    ReservedWord["DO"] = PToken::DO;
    ReservedWord["DOWNTO"] = PToken::DOWNTO;
    ReservedWord["ELSE"] = PToken::ELSE;
    ReservedWord["END"] = PToken::END;
    ReservedWord["FALSE"] = PToken::FALSE;
    ReservedWord["FILE"] = PToken::FILE;
    ReservedWord["FOR"] = PToken::FOR;
    ReservedWord["FUNCTION"] = PToken::FUNCTION;
    ReservedWord["GOTO"] = PToken::GOTO;
    ReservedWord["IF"] = PToken::IF;
    ReservedWord["IMPLEMENTATION"] = PToken::IMPLEMENTATION;
    ReservedWord["IN"] = PToken::IN;
    ReservedWord["INLINE"] = PToken::INLINE;
    ReservedWord["INTERFACE"] = PToken::INTERFACE;
    ReservedWord["LABEL"] = PToken::LABEL;
    ReservedWord["MOD"] = PToken::MOD;
    ReservedWord["NIL"] = PToken::NIL;
    ReservedWord["NOT"] = PToken::NOT;
    ReservedWord["OBJECT"] = PToken::OBJECT;
    ReservedWord["OF"] = PToken::OF;
    ReservedWord["ON"] = PToken::ON;
    ReservedWord["OPERATOR"] = PToken::OPERATOR;
    ReservedWord["OR"] = PToken::OR;
    ReservedWord["PACKED"] = PToken::PACKED;
    ReservedWord["PROCEDURE"] = PToken::PROCEDURE;
    ReservedWord["PROGRAM"] = PToken::PROGRAM;
    ReservedWord["RECORD"] = PToken::RECORD;
    ReservedWord["REPEAT"] = PToken::REPEAT;
    ReservedWord["SET"] = PToken::SET;
    ReservedWord["SHL"] = PToken::SHL;
    ReservedWord["SHR"] = PToken::SHR;
    ReservedWord["STRING"] = PToken::STRING;
    ReservedWord["THEN"] = PToken::THEN;
    ReservedWord["TO"] = PToken::TO;
    ReservedWord["TRUE"] = PToken::TRUE;
    ReservedWord["TYPE"] = PToken::TYPE;
    ReservedWord["UNIT"] = PToken::UNIT;
    ReservedWord["UNTIL"] = PToken::UNTIL;
    ReservedWord["USES"] = PToken::USES;
    ReservedWord["VAR"] = PToken::VAR;
    ReservedWord["WHILE"] = PToken::WHILE;
    ReservedWord["WITH"] = PToken::WITH;
    ReservedWord["XOR"] = PToken::XOR;
}
//Initialize symbols map:
map<string, Token> Token::Symbols;
void Token::initMaps()
{
    Symbols["PLUSOP"] = PToken::PLUSOP;
    Symbols["MINUSOP"] = PToken::MINUSOP;
    Symbols["MULTOP"] = PToken::MULTOP;
    Symbols["DIVOP"] = PToken::DIVOP;
    Symbols["ASSIGN"] = PToken::ASSIGN;
    Symbols["EQUAL"] = PToken::EQUAL;
    Symbols["NE"] = PToken::NE;
    Symbols["LTEQ"] = PToken::LTEQ;
    Symbols["GTEQ"] = PToken::GTEQ;
    Symbols["LT"] = PToken::LT;
    Symbols["GT"] = PToken::GT;
    Symbols["PLUSEQUAL"] = PToken::PLUSEQUAL;
    Symbols["MINUSEQUAL"] = PToken::MINUSEQUAL;
    Symbols["MULTEQUAL"] = PToken::MULTEQUAL;
    Symbols["DIVEQUAL"] = PToken::DIVEQUAL;
    Symbols["CARAT"] = PToken::CARAT;
    Symbols["SEMICOLOR"] = PToken::SEMICOLOR;
    Symbols["COMMA"] = PToken::COMMA;
    Symbols["LPAREN"] = PToken::LPAREN;
    Symbols["RPAREN"] = PToken::RPAREN;
    Symbols["LBRACKET"] = PToken::LBRACKET;
    Symbols["RBRACKET"] = PToken::RBRACKET;
    Symbols["LBRACE"] = PToken::LBRACE;
    Symbols["RBRACE"] = PToken::RBRACE;
    Symbols["LCOMMENT"] = PToken::LCOMMENT;
    Symbols["RCOMMENT"] = PToken::RCOMMENT;
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
