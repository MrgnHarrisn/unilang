#include <iostream>

#include "Lexer.h"

int main() {
    std::string source = "x = 42.3 + 3 - 23";
    Lexer lexer(source);
    std::vector<Token> tokens = lexer.tokenize();

    for (const Token& token : tokens) {
        std::cout << "Token: " << token.value << " Type: " << static_cast<int>(token.type) << std::endl;
    }

    return 0;
}
