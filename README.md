# Lexer written in c++
Reads source code e.g. "let x = 5" and outputs tokens in the format:

TOKEN_ID('let') @ 1:1\
TOKEN_ID('x') @ 1:5\
TOKEN_EQUALS('=') @ 1:7\
TOKEN_ID('5') @ 1:9\
TOKEN_EOF('') @ 2:1
