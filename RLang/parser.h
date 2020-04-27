#pragma once
#include"lexer.h"
#include<vector>

namespace rlang
{
	
	class Expression
	{
	public:
		std::vector<Token> m_tvalue;
	public:
		Expression();
		Expression(std::vector<Token> statement);
		~Expression();
	public:
		void Log();
	};

	void Parser(std::vector<Token>& source,std::vector<Expression>& statements,int internal);
}