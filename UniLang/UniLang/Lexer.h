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
private:
	std::string m_source;
	size_t m_position;

	Token read_number();
	Token read_identifier();
	bool is_operator(char c);
	bool is_key_word();

};

