#pragma once
#include"parser.h"
#include<vector>

namespace rlang
{

	class Variable
	{
	private:
	public:
	};

	//std::vector<Variable> var_table;
	void print(int value, bool newline);
	void Execute(Expression e, bool status);
	void Interpreter(std::vector<rlang::Expression>& statement);
}