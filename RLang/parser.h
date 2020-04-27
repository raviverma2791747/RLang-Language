#pragma once
#include"lexer.h"
#include<vector>

namespace rlang
{
	
	class Base : public Token
	{
	private:
	public:
	};


	class Expression
	{
	private:
		std::vector<Token> m_tvalue;
		std::vector<Base>  m_bvalue;
	public:
		Expression();
		Expression(std::vector<Token> statement);
		~Expression();
	public:
		void Log();
	};

	void Parser(std::vector<Token>& source,std::vector<Expression>& statements,int internal);
}