#pragma once
#include"lexer.h"
#include<vector>

namespace rlang
{
	class Expression
	{
	private:
	public:
		Expression();
		~Expression();
	};

	class Statement
	{
	private:
		std::vector<rlang::Token> m_statement;
	public:
		Statement(std::vector<rlang::Token> statement);
		~Statement();
	public:
		void Log();
	};

	void Parser(std::vector<Token>& source) ;
}