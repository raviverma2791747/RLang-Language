#include<iostream>
#include"lexer.h"
#include"parser.h"
#include"interpreter.h"
#include<vector>
#include<sstream>


int main()
{
	std::cout << "Lexical Analysis started" << std::endl;
	std::vector<rlang::Token> tkn;
	rlang::Lexer("test.txt",tkn,2);
	std::cout << "Lexical Analysis ended" << std::endl;
	std::cin.get();
	std::cout << "Parsing started" <<std::endl;
	std::vector<rlang::Expression> stm;
	rlang::Parser(tkn,stm,0);
	std::cout << "Parsing Ended" << std::endl;
	std::cin.get();
	std::cout << "Interpreting started" << std::endl;
	rlang::Interpreter(stm);
	std::cout <<std::endl<< "Interpreting Ended" << std::endl;
	std::cin.get();
	return 0;
}