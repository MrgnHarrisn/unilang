#pragma once

enum TokenType {
    // Identifiers
    IDENTIFIER,  // For variable names, function names, etc.

    // Literals
    BOOL,        // Boolean literals (true, false)

    // Numeric literals (optional, based on your language design)
    INTEGER_LITERAL,    // For representing integer values directly, e.g., 123
    FLOAT_LITERAL,      // For representing floating-point values, e.g., 3.14

    // Keywords

    // Operators
    OPERATOR,

    // Special tokens
    END_OF_FILE,                        // End of file token
};

struct Token {
    TokenType type;
    std::string value;
};