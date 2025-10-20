#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../include/lexer.hpp"

int main()
{
    std::ifstream inputFile("../examples/lang.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open input file!\n";
        return 1;
    }

    std::string source((std::istreambuf_iterator<char>(inputFile)),
                       std::istreambuf_iterator<char>());
    inputFile.close();

    Lexer lexer(source);
    std::vector<Token> tokens = lexer.tokenize();

    for (const auto& token : tokens)
    {
        std::cout << token << std::endl;
    }

    return 0;
}

