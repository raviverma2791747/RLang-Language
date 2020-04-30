#include"parser.h"
#include"lexer.h"

using namespace rlang;

Expression::Expression()
{

}

Expression::~Expression()
{

}

Statement::Statement(std::vector<rlang::Token> statement):
	m_statement(statement)
{
	if (m_statement[0].token() == "int" || 
		m_statement[0].token() == "float" ||
		m_statement[0].token() == "bool" ||
		m_statement[0].token() == "string" 
		)
	{

	}
}

Statement::~Statement()
{

}

void Statement::Log()
{
	for (int i = 0; i < m_statement.size(); i++)
	{
		std::cout << m_statement[i].token() << " ";
	}
	std::cout<<std::endl;
}

void rlang::Parser(std::vector<rlang::Token>& source) 
{
	std::vector<rlang::Token> buffer;
	std::vector<rlang::Statement> statements;
	for (int i = 0; i < source.size(); i++)
	{
		while (source[i].token() != ";")
		{
			buffer.push_back(source[i]);	
			i += 1;
		}
		buffer.push_back(source[i]);
		statements.push_back(rlang::Statement(buffer));
		buffer.clear();
	}
	for (int i = 0; i < statements.size(); i++)
	{
		statements[i].Log();
	}
}