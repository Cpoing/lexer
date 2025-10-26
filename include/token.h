#pragma once

// requirements:
// - MINUS
// - ASTERISK
// - SLASH
// - IF
// - ELSE
// - WHILE
// - BOOLEANS (TRUE OR FALSE)
// - COMPARISONS (== != <= >= < >)

enum class TokenType
{
    TOKEN_ID,
    TOKEN_INT,
    TOKEN_STRING,
    TOKEN_FN,
    TOKEN_LET,
    TOKEN_RETURN,
    TOKEN_PRINT,

    TOKEN_EQUALS,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_ASTERISK,
    TOKEN_SLASH,

    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_COMMA,

    TOKEN_EOF,
};
