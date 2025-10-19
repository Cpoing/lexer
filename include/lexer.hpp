#pragma once

#include "token.hpp"
#include <vector>
#include <string>

class Lexer
{
public:
	explicit Lexer(const std::string& source);
	std::vector<Token> tokenize();

private:
	std::string src;
	size_t pos;
	int line, col;

	bool isAtEnd() const; // checks if lexer reached end of input string
	char peek() const; // gets the current char without consuming it
	char advance(); // moves forward by one character and returns it
	void skipWhiteSpace(); // skips spaces, tabs, and newlines
	Token identifier(); // TOKEN_ID('let'), reads char until end of identifier and creates a token : TOKEN(TokenType::TOKEN_ID, "let", line, column);
	Token integer(); // TOKEN_INT('123'), reads digits until end of number and creates a token : Token(TokenType::TOKEN_INT, "123", line, column);
};
