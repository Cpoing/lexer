#pragma once

// requirements:
// !=
// ! (not operator)
// ++
// comments

enum class TokenType
{
	// identifiers
    TOKEN_ID,
    TOKEN_INT,
    TOKEN_STRING,
    TOKEN_FN,
    TOKEN_LET,
    TOKEN_RETURN,
    TOKEN_PRINT,
	TOKEN_IF,
	TOKEN_ELIF,
	TOKEN_ELSE,
	TOKEN_WHILE,
	TOKEN_TRUE,
	TOKEN_FALSE,

	// symbols
    TOKEN_ASSIGN,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_ASTERISK,
    TOKEN_SLASH,
	TOKEN_EQUALS,
	TOKEN_LT,
	TOKEN_LE,
	TOKEN_GT,
	TOKEN_GE,

    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_COMMA,

    TOKEN_EOF,
};
