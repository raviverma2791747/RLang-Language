#include"parser.h"

using namespace rlang;

std::vector<std::vector<Token>> grammer = {
	{ Token("clear","keyword",0),Token("(","operator",0),Token(")","operator",0),Token(";","operator",0) },
	{ Token("pause","keyword",0),Token("(","operator",0),Token(")","operator",0),Token(";","operator",0) },
	{ Token("type","keyword",0),Token("","identifier",0),Token(";","operator",0) },
	{ Token("type","keyword",0),Token("","identifier",0),Token("=","operator",0),Token("","constant",0),Token(";","operator",0) },
	{ Token("type","keyword",0),Token("","identifier",0),Token("=","operator",0),Token("","identifier",0),Token(";","operator",0) },
	{ Token("type","keyword",0),Token("","identifier",0),Token("=","operator",0),Token("","string",0),Token(";","operator",0) },
    { Token("print","keyword",0),Token("(","operator",0), Token("","string",0),Token(")","operator",0),Token(";","operator",0)},
	{ Token("print","keyword",0),Token("(","operator",0), Token("","string",0),Token(",","operator",0),Token("endl","keyword",0),Token(")","operator",0),Token(";","operator",0)},
	{ Token("print","keyword",0),Token("(","operator",0), Token("","identifier",0),Token(",","operator",0),Token("endl","keyword",0),Token(")","operator",0),Token(";","operator",0)},
	{ Token("print","keyword",0),Token("(","operator",0), Token("","identifier",0),Token(")","operator",0),Token(";","operator",0)},
	{ Token("input","keyword",0),Token("(","operator",0), Token("","identifier",0),Token(")","operator",0),Token(";","operator",0)},
	{ Token("exit","keyword",0),Token("(","operator",0), Token("","constant",0),Token(")","operator",0),Token(";","operator",0)}
};

Expression::Expression():
	m_tvalue()
{

}

Expression::Expression(std::vector<Token> statement):
	m_tvalue(statement)
{
	bool flag = false;
	for (int i = 0; i < grammer.size(); i++)
	{
		if (grammer[i].size() == m_tvalue.size())
		{
			//std::cout << "ok";
			flag = true;
			for (int j = 0; j < grammer[i].size(); j++)
			{
				if (grammer[i][j].Type().compare(m_tvalue[j].Type()) != 0)
				{
					//std::cout << grammer[i][j].Type() <<" "<< grammer[i][j].Type().size() << std::endl;
					//std::cout << m_tvalue[j].Type() << " " << m_tvalue[j].Type().size() << std::endl;
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				break;
			}
		}
	}
	if (flag == false)
	{
		std::cout << std::endl;
		std::cout << "ERROR : Illegal or undefined Syntax" << std::endl;
		this->Log();
		std::cout << std::endl;
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
		if (source[i].Type() == "comment")
		{
			continue;
		}
		while ( (source[i].token() != ";" && i < source.size()))
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