#include"parser.h"

using namespace rlang;


Expression::Expression():
	m_tvalue()
{

}

Expression::Expression(std::vector<Token> statement):
	m_tvalue(statement)
{
	/*Grammar Check*/
	if (m_tvalue[0].token() == "print")
	{
		if (m_tvalue[2].Type() == "constant")
		{
			std::cout << m_tvalue[2].token() << std::endl;
		}
	}
}

Expression::~Expression()
{

}

void Expression::Log()
{
	for (int i = 0; i < m_tvalue.size(); i++)
	{
		m_tvalue[i].Log(0);
	}
	std::cout << std::endl;
}

void rlang::Parser(std::vector<Token>& source, std::vector<Expression>& statements,int internal)
{
	std::vector<rlang::Token> buffer;
	bool flag = false;
	for (int i = 0; i < source.size(); i++)
	{
		flag = false;
		while (source[i].token() != ";")
		{
			buffer.push_back(source[i]);
			flag = true;
			i += 1;
		}
		if (flag == true)
		{
			buffer.push_back(source[i]);
			statements.push_back(buffer);
			buffer.clear();
		}
	}
	if (internal == 1)
	{
		for (int i = 0; i < statements.size(); i++)
		{
			statements[i].Log();
		}
	}
}