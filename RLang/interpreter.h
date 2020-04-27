#pragma once
#include"parser.h"
#include<vector>

namespace rlang
{
	class Variable
	{
	private:
		std::string m_name;
		std::string m_type;
		int* m_int;
		float* m_float;
		std::string* m_string;
		bool m_bool;
	public:
		Variable();
		Variable(std::string name, int value);
		std::string Type();
		std::string Name();
		int Int();
		float Float();
		std::string String();
		void Input(int value);
		void Input(float value);
		void Input(std::string value);
	};

	class System
	{
	private:
		static System instance;
		System() {};
		System(System&) = delete;
		std::vector<Variable> var_table;
	public:
		static System& IO()
		{
			return instance;
		}

		void Allocate(Variable var)
		{
			var_table.push_back(var);
		}

		void Print(std::string name, bool newline)
		{
			for (int i = 0; i < var_table.size(); i++)
			{
				if (var_table[i].Name() == name)
				{
					if (var_table[i].Type() == "int")
					{
						std::cout << var_table[i].Int();
						if (newline)
						{
								std::cout << std::endl;
						}
					}
				}
			}
		}

		void Print(int value, bool newline)
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
	};

	void Execute(Expression e, bool status);
	void Interpreter(std::vector<rlang::Expression>& statement);
}