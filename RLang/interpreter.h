#pragma once
#include"parser.h"
#include<vector>
#include<stdlib.h>

namespace rlang
{
	class Variable
	{
	private:
		std::string m_scope;
		std::string m_name;
		std::string m_type;
		int* m_int;
		float* m_float;
		std::string* m_string;
		bool m_bool;
	public:
		Variable();
		Variable(std::string name, int value,std::string scope);
		Variable(std::string name, float value, std::string scope);
		Variable(std::string name, std::string value, std::string scope);
		std::string Type();
		std::string Name();
		int Int();
		float Float();
		std::string String();
		void Input(int value);
		void Input(float value);
		void Input(std::string value);
		void Log();
		std::string Scope();
	};

	class System
	{
	private:
		static System instance;
		System() {};
		System(System&) = delete;
		std::vector<Variable> var_table;
		std::vector<std::string> scope_table;
	public:
		static System& IO()
		{
			return instance;
		}
		
		void Scope(std::string scope)
		{
			scope_table.push_back(scope);
		}

		void Allocate(Variable var)
		{
			var_table.push_back(var);
			//std::cout << var_table.size() << std::endl;
		}

		void Print(std::string name, bool newline,std::string scope)
		{
			for (int i = 0; i < var_table.size(); i++)
			{
				if (var_table[i].Name() == name)
				{
					if (var_table[i].Scope() != scope)
					{
						std::cout << std::endl << "ERROR : Access denied not in current scope" << std::endl;
						return;
					}
					if (var_table[i].Type() == "int")
					{
						std::cout << var_table[i].Int();
						if (newline)
						{
							std::cout << std::endl;
						}
					}
					else if (var_table[i].Type() == "float")
					{
						std::cout << var_table[i].Float();
						if (newline)
						{
							std::cout << std::endl;
						}
					}
					else if (var_table[i].Type() == "string")
					{
						std::cout << var_table[i].String();
						if (newline)
						{
							std::cout << std::endl;
						}
					}
					break;
				}
			}
		}

		void Print(Token cs,bool newline, std::string scope)
		{
			if (cs.Type() == "string")
			{
				std::cout << cs.token();
				if (newline)
				{
					std::cout << std::endl;
				}
			}
			else
			{
				std::cout << cs.token();
				if (newline)
				{
					std::cout << std::endl;
				}
			}
		}

		void Print(int value, bool newline, std::string scope)
		{
			std::cout << value;
			if (newline)
			{
				std::cout << std::endl;
			}
		}

		void Input(Variable& value)
		{
			if (value.Type() == "int")
			{
				int temp_int;
				std::cin >> temp_int;
				value.Input(temp_int);
			}
			else if (value.Type() == "float")
			{
				float temp_float;
				std::cin >> temp_float;
				value.Input(temp_float);
			}
			else if(value.Type() == "string")
			{
				std::string temp_string;
				std::cin >> temp_string;
				value.Input(temp_string);
			}
		}

		void Log()
		{
			std::cout << std::endl << "Memory" << std::endl;
			for (int i = 0; i < var_table.size(); i++)
			{
				var_table[i].Log();
			}
			std::cout << std::endl << "Scopes" << std::endl;
			for (int i = 0; i < scope_table.size(); i++)
			{
				std::cout<<scope_table[i]<<std::endl;
			}
		}

		void Pause()
		{
			std::cin.get();
		}

		void Clear()
		{
			system("cls");
		}
	};

	class Logger
	{
	private:
		Logger() {};
		Logger(Logger&) = delete;
		static Logger instance;
	public:
		static Logger& IO()
		{
			return instance;
		}
		 
		void Print()
		{

		}
	};

	void Execute(Expression e, bool& status,std::string& scope);
	void Interpreter(std::vector<rlang::Expression>& statement,int internal);
}