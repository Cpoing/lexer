#pragma once

#include "token.h"
#include <string>
#include <iostream>

//TOKEN_ID('let') @ 1:1
//TOKEN_ID('x') @ 1:5

struct Token
{
	TokenType type;
	std::string lexeme;
	int line;
	int column;

	Token(TokenType t, const std::string& l, int ln, int col)
		: type(t), lexeme(l), line(ln), column(col)
	{}

	friend std::ostream& operator<<(std::ostream& os, const Token& token)
	{
		std::string typeName;
		switch (token.type)
		{
		case TokenType::TOKEN_ID: typeName = "TOKEN_ID"; break;
		case TokenType::TOKEN_INT: typeName = "TOKEN_INT"; break;
		case TokenType::TOKEN_EQUALS: typeName = "TOKEN_EQUALS"; break;
		case TokenType::TOKEN_EOF: typeName = "TOKEN_EOF"; break;
		case TokenType::TOKEN_LPAREN: typeName = "TOKEN_LPAREN"; break;
		case TokenType::TOKEN_RPAREN: typeName = "TOKEN_RPAREN"; break;
		case TokenType::TOKEN_STRING: typeName = "TOKEN_STRING"; break;
		case TokenType::TOKEN_FN: typeName = "TOKEN_FN"; break;
		case TokenType::TOKEN_COMMA: typeName = "TOKEN_COMMA"; break;
		case TokenType::TOKEN_LET: typeName = "TOKEN_LET"; break;
		case TokenType::TOKEN_PLUS: typeName = "TOKEN_PLUS"; break;
		case TokenType::TOKEN_LBRACE: typeName = "TOKEN_LBRACE"; break;
		case TokenType::TOKEN_RBRACE: typeName = "TOKEN_RBRACE"; break;
		}
		os << typeName << "('" << token.lexeme << "') @ " << token.line << ":" << token.column;
		return os;
	}
};
