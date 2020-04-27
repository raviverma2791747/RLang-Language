#include"interpreter.h"
#include<sstream>
#include<vector>

using namespace rlang;

Variable::Variable():
	m_name(),m_type(),m_int(nullptr),m_float(nullptr),m_string(),m_bool(false)
{

}

Variable::Variable(std::string name,int value):
	m_name(name), m_type("int"), m_int (new int), m_float(nullptr), m_string(), m_bool(false)
{
	*(m_int) = value;
}

std::string Variable::Type()
{
	return m_type;
}

std::string Variable::Name()
{
	return m_name;
}

int Variable::Int()
{
	return *(m_int);
}

float Variable::Float()
{
	return *(m_float);
}

std::string Variable::String()
{
	return *(m_string);
}

void Variable::Input(int value)
{

}

void Variable::Input(float value)
{

}

void Variable::Input(std::string value)
{

}


rlang::System rlang::System::instance;

void rlang::Execute(Expression e,bool status)
{
	if (e.m_tvalue[0].token() == "int")
	{
		if (e.m_tvalue[1].Type() == "identifier")
		{
			if (e.m_tvalue[2].token() == ";")
			{
				Variable var(e.m_tvalue[1].token(),10);
				System::IO().Allocate(var);
			}
		}
	}
	if (e.m_tvalue[0].token() == "print")
	{
		if (e.m_tvalue[2].Type() == "identifier")
		{
			System::IO().Print(e.m_tvalue[2].token(), false);
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