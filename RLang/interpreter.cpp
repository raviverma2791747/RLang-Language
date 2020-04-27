#include"interpreter.h"
#include<sstream>
#include<vector>

void rlang::print(int value,bool newline)
{
	std::cout << value;
	if (newline)
	{
		std::cout << std::endl;
	}
}


void rlang::Execute(Expression e,bool status)
{
	if (e.m_tvalue[0].token() == "print")
	{
		if (e.m_tvalue.size() == 5)
		{
			std::stringstream s(e.m_tvalue[2].token());
			int temp_int;
			s >> temp_int;
			rlang::print(temp_int,false);
		}
		else if (e.m_tvalue.size() == 7)
		{
			std::stringstream s(e.m_tvalue[2].token());
			int temp_int;
			s >> temp_int;
			rlang::print(temp_int,true);
		}
	}
	else if (e.m_tvalue[0].token() == "exit")
	{
		status = false;
	}
}

void rlang::Interpreter(std::vector<rlang::Expression>& statement)
{
	bool status = true;
	for(int i=0;i<statement.size();i++)
	{
		Execute(statement[i],status);
		if (status == false)
		{
			break;
		}
	}
}