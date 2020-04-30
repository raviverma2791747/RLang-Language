#include<iostream>
#include"interpreter.h"
#include<vector>
#include"lexer.h"
#include"parser.h"




int main()
{
	std::cout << "Lexical Analysis started" << std::endl;
	std::vector<rlang::Token> tkn;
	rlang::Lexer("test.txt",tkn,2);
	std::cout << "Lexical Analysis ended" << std::endl;
	std::cin.get();
	std::cout << "Parser started" << std::endl;
	rlang::Parser(tkn);
	std::cin.get();
	return 0;
}