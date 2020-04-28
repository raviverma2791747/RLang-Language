#include"interpreter.h"
#include<sstream>
#include<vector>

using namespace rlang;

Variable::Variable():
	m_scope(),m_name(),m_type(),m_int(nullptr),m_float(nullptr),m_string(),m_bool(false)
{

}

Variable::Variable(std::string name,int value,std::string scope):
	m_scope(scope),m_name(name), m_type("int"), m_int (new int), m_float(nullptr), m_string(), m_bool(false)
{
	*(m_int) = value;
}

Variable::Variable(std::string name, float value, std::string scope) :
	m_scope(scope), m_name(name), m_type("float"), m_int(nullptr), m_float(new float), m_string(), m_bool(false)
{
	*(m_float) = value;
}

Variable::Variable(std::string name, std::string value, std::string scope) :
	m_scope(scope),m_name(name), m_type("string"), m_int(nullptr), m_float(nullptr), m_string(new std::string), m_bool(false)
{
	*(m_string) = value;
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
	if (this->m_type != "int")
	{
		std::cout << std::endl << "Error : Illegal Read Write Operation" <<std::endl;
		std::cout << "Expected Type : " << this->m_type << " but accessing : int" << std::endl;
		std::cin.get();
		return 0;
	}
	else
	{
		return *(m_int);
	}
}

float Variable::Float()
{
	if (this->m_type != "float")
	{
		std::cout << std::endl << "Error : Illegal Read Write Operation" << std::endl;
		std::cout << "Expected Type : " << this->m_type << " but accessing : Float" << std::endl;
		std::cin.get();
		return 0.0f;
	}
	else
	{
		return *(m_float);
	}
}

std::string Variable::String()
{
	if (this->m_type != "string")
	{
		std::cout << std::endl<< "Error : Illegal Read Write Operation " << std::endl;
		std::cout << "Expected Type : " << this->m_type << " but accessing : string" << std::endl;
		std::cin.get();
		return std::string("ERROR");
	}
	else
	{
	return *(m_string);
	}
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

void Variable::Log()
{
	std::cout <<m_scope<<" "<< m_name << " " << m_type << std::endl;
}

std::string Variable::Scope()
{
	return m_scope;
}

rlang::System rlang::System::instance;

void rlang::Execute(Expression e,bool& status, std::string& scope)
{
	if (e.m_tvalue[0].token() == "scope")
	{
		scope = e.m_tvalue[1].token();
		System::IO().Scope(scope);
	}
	else if (e.m_tvalue[1].token() == "end")
	{
		scope = "global";
	}
	else if (e.m_tvalue[0].token() == "int")
	{
		
		if (e.m_tvalue[1].Type() == "identifier")
		{
			if (e.m_tvalue[2].token() == ";")
			{
				Variable var(e.m_tvalue[1].token(),0,scope);
				System::IO().Allocate(var);
			}
			else if (e.m_tvalue[2].token() == "=")
			{
				
				if (e.m_tvalue[3].Type() == "constant")
				{
					
					std::stringstream s(e.m_tvalue[3].token());
					int temp_int;
					s>> temp_int;
					//Variable(e.m_tvalue[1].token(),temp_int);
					System::IO().Allocate(Variable(e.m_tvalue[1].token(), temp_int, scope));
				}
			}
		}
	}
	else if (e.m_tvalue[0].token() == "float")
	{
		if (e.m_tvalue[1].Type() == "identifier")
		{
			if (e.m_tvalue[2].token() == ";")
			{
				Variable var(e.m_tvalue[1].token(), 0.0f, scope);
				System::IO().Allocate(var);
			}
			else if (e.m_tvalue[2].token() == "=")
			{

				if (e.m_tvalue[3].Type() == "constant")
				{

					std::stringstream s(e.m_tvalue[3].token());
					float temp_float;
					s >> temp_float;
					//Variable(e.m_tvalue[1].token(),temp_int);
					System::IO().Allocate(Variable(e.m_tvalue[1].token(), temp_float, scope));
				}
			}
		}
	}
	else if (e.m_tvalue[0].token() == "string")
	{
		if (e.m_tvalue[1].Type() == "identifier")
		{
			if (e.m_tvalue[2].token() == ";")
			{
				Variable var(e.m_tvalue[1].token(),std::string(), scope);
				System::IO().Allocate(var);
			}
			else if (e.m_tvalue[2].token() == "=")
			{

				if (e.m_tvalue[3].Type() == "string")
				{
					//Variable(e.m_tvalue[1].token(),temp_int);
					System::IO().Allocate(Variable(e.m_tvalue[1].token(), e.m_tvalue[3].token(), scope));
				}
			}
		}
	}
	else if (e.m_tvalue[0].token() == "print")
	{
		if (e.m_tvalue[2].Type() == "identifier")
		{
			if (e.m_tvalue.size() == 7)
			{
				System::IO().Print(e.m_tvalue[2].token(), true, scope);
			}
			else
			{
				System::IO().Print(e.m_tvalue[2].token(), false, scope);
			}
	    }
		else if (e.m_tvalue[2].Type() == "string")
		{
			if (e.m_tvalue.size() == 7)
			{
				System::IO().Print(e.m_tvalue[2], true,scope);
			}
			else
			{
				System::IO().Print(e.m_tvalue[2], false, scope);
			}
		}
	}
	else if (e.m_tvalue[0].token() == "pause")
	{
		System::IO().Pause();
	}
	else if (e.m_tvalue[0].token() == "clear")
	{
		System::IO().Clear();
	}
	else if (e.m_tvalue[0].token() == "exit")
	{
		status = false;
	}
}

void rlang::Interpreter(std::vector<rlang::Expression>& statement, int internal)
{
	bool status = true;
	std::string  scope = "global";
	System::IO().Scope(scope);
	for(int i=0;i<statement.size();i++)
	{
		Execute(statement[i],status,scope);
		if (status == false)
		{
			break;
		}
	}
	if (internal == 1)
	{
		System::IO().Log();
	}
}