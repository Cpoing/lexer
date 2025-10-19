#include "../include/lexer.hpp"
#include <cctype>
#include <vector>

Lexer::Lexer(const std::string& source)
	: src(source), pos(0), line(1), col(1)
	{}

bool Lexer::isAtEnd() const { return pos >= src.size(); }
char Lexer::peek() const { return isAtEnd() ? '\0' : src[pos]; }

char Lexer::advance()
{
	char c = peek();
	pos++;
	if (c == '\n')
	{
		line++;
		col = 1;
	}
	else
		col++;
	return c;
};

void Lexer::skipWhiteSpace()
{
	while (!isAtEnd() && std::isspace(peek()))
		advance();
}

Token Lexer::identifier()
{
	int startCol = col;
	std::string value;
	while (!isAtEnd() && std::isalnum(peek()))
		value += advance();
	return Token(TokenType::TOKEN_ID, value, line, startCol);
}

Token Lexer::integer()
{
	int startCol = col;
	std::string value;

	while (!isAtEnd() && std::isdigit(peek()))
		value += advance();

	return Token(TokenType::TOKEN_INT, value, line, startCol);
}

std::vector<Token> Lexer::tokenize()
{
	std::vector<Token> tokens;

	while (!isAtEnd())
	{
		skipWhiteSpace();
		if (isAtEnd()) break;

		char c = peek();
		if (std::isalnum(c))
			tokens.push_back(identifier());
		else if (std::isdigit(c))
			tokens.push_back(integer());
		else if (c == '=')
		{
			tokens.emplace_back(TokenType::TOKEN_EQUALS, "=", line, col);
			advance();
		}
		else
		{
			std::cerr << "Unexpected character '" << c << "' at line " << line << " col " << col << "\n";
			advance();
		}
	}

	tokens.emplace_back(TokenType::TOKEN_EOF, "", line, col);
	return tokens;
}
