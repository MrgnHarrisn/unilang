#include "Lexer.h"

Lexer::Lexer(const string& src) : m_source(src), m_position(0) {}

vector<Token> Lexer::tokenize()
{
	vector<Token> tokens;

	while (m_position < m_source.length())
	{
		char current = m_source[m_position];

		if (std::isdigit(current)) {
			tokens.push_back(read_number());
		}
		else if (is_operator(current)) {
			tokens.push_back({TokenType::OPERATOR, std::string(1, current)});
			m_position++;
		}
		else if (std::isalpha(m_source[m_position])) {
			tokens.push_back(read_identifier());
		}
		else {
			m_position++;
		}

	}

	tokens.push_back({TokenType::END_OF_FILE, ""});
	return tokens;

}

Token Lexer::read_number()
{
	size_t start = m_position;
	bool is_floating = false;
	/* Keep reading the number in till the end also checking if it is a decimal place */
	while (m_position < m_source.length() && (std::isdigit(m_source[m_position]) || m_source[m_position] == '.')) {
		if (m_source[m_position] == '.') {
			is_floating = true;
		}
		m_position++;
	}

	/* Check if it is a floating point or not */
	return {is_floating ? TokenType::FLOAT_LITERAL : TokenType::INTEGER_LITERAL, m_source.substr(start, m_position - start)};
}

Token Lexer::read_identifier()
{
	size_t start = m_position;
	while (m_position < m_source.length() && std::isalnum(m_source[m_position])) {
		m_position++;
	}

	return {TokenType::IDENTIFIER, m_source.substr(start, m_position - start)};

}

bool Lexer::is_operator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool Lexer::is_key_word()
{
	size_t start = m_position;
	size_t pos = start;
	while (pos < m_source.length() && std::isalnum(m_source[pos])) {
		pos++;
	}
	string word = m_source.substr(start, pos - start);
	
	if (word == "var" || word == "const" || word == "if" || word == "else" || word == "while") {
		return true;
	}
	else if (word == "return" || word == "def" || word == "true" || word == "false" || word == "class") {
		return true;
	}
	else {
		return false;
	}
}