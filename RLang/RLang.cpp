#include<iostream>
#include"lexer.h"
#include<vector>
#include<sstream>

struct variable
{
	std::string name;
	std::string type;
	int _int;
	float _float;
	double _double;
	std::string _string;
};

std::vector<variable> var_table;

int main()
{
	std::vector<rlang::Token> tkn;
	rlang::Lexer("test.txt",tkn);
	/*for (int i = 0; i < tkn.size(); i++)
	{
		tkn[i].Log();
	}
	*/

	std::cout << "Interpreting started" << std::endl;

	for (int i = 0; i < tkn.size(); i++)
	{
		if (tkn[i].Type() == "keyword")
		{
			if (tkn[i] == "int")
			{
				if (tkn[i + 1].Type() == "identifier")
				{
					if (tkn[i + 2] == "=")
					{
						std::stringstream temp(tkn[i + 3].token());
						int temp_int;
						temp >> temp_int;
						var_table.push_back(variable{tkn[i+1].token(),tkn[i].token(),temp_int,0,0,""});
						i += 4;
						//std::cout <<"variable created"<<std::endl;
					}
				}
			}
			else if (tkn[i] == "float")
			{
				if (tkn[i + 1].Type() == "identifier")
				{
					if (tkn[i + 2] == "=")
					{
						std::stringstream temp(tkn[i + 3].token());
						int temp_int;
						temp >> temp_int;
						var_table.push_back(variable{ tkn[i + 1].token(),tkn[i].token(),temp_int,0,0,"" });
						i += 4;
						//std::cout <<"variable created"<<std::endl;
					}
				}
			}
			else if (tkn[i] == "print")
			{
				
				if (tkn[i + 2].Type() == "identifier")
				{

					for (int j = 0; j < var_table.size(); j++)
					{
						if ( var_table[j].name.compare( tkn[1 + 2].token()) )
						{
							if (var_table[j].type == "int")
							{
								std::cout<< var_table[j]._int;
								i += 4;
							}
							else if (var_table[j].type == "float")
							{
								std::cout << var_table[j]._float;
								i += 4;
							}
						}
					}
				}
				else if (tkn[i + 2].Type() == "string")
				{
					std::cout << tkn[i + 2].token();
					i += 4;
				}
				else if (tkn[i + 2].Type() == "keyword")
				{
					if (tkn[i + 2] == "endl")
					{
						std::cout << "\n";
						i += 2;
					}
				}
			}
		}
	}
	//std::cout << var_table.size() << std::endl;
	std::cin.get();
	return 0;
}