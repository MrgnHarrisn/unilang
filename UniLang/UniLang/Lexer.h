#pragma once

#include <vector>
#include <string>

#include "Token.h"


using namespace std;

class Lexer
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="src">source file</param>
	Lexer(const string& src);

	/// <summary>
	/// Returns a list of tokens from the source code
	/// </summary>
	/// <returns></returns>
	vector<Token> tokenize();

	/// <summary>
	/// Sets the source to a new string
	/// </summary>
	/// <param name="src"></param>
	void set_source(const string& src);

private:
	std::string m_source;
	size_t m_position;

	Token read_number();
	Token read_identifier();
	Token read_key_word();
	TokenType keyword_to_tt(const string& word);
	bool is_operator(char c);
	bool is_key_word();

};

