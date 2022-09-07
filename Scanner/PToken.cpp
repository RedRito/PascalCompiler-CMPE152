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