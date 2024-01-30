#include <iostream>

#include "Lexer.h"

int main() {
    std::string source = "";
    Lexer lexer(source);
    
    do {
        getline(cin, source);

        if (source == "quit") {
            break;
        }
        lexer.set_source(source);

        std::vector<Token> tokens = lexer.tokenize();

        for (const Token& token : tokens) {
            std::cout << "Token: " << token.value << " Type: " << static_cast<int>(token.type) << std::endl;
        }

    } while (source != "quit");

    return 0;
}
