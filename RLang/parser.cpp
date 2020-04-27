#include"parser.h"

using namespace rlang;



Expression::Expression():
	m_tvalue(),m_bvalue()
{

}

Expression::Expression(std::vector<Token> statement):
	m_tvalue(statement),m_bvalue()
{
	/*Grammar Check*/
	if (m_bvalue[0].token() == "int" && m_bvalue[1].Type() == "identifier" && m_tvalue[2].token() == ";")
	{
		m_bvalue.push_back()
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