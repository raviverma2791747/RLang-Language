#pragma once
#include"parser.h"
#include<vector>
#include<stdlib.h>

namespace rlang
{
	
	class System
	{
	private:
		static System instance;
		System() {};
		System(System&) = delete;
	public:
		static System& IO()
		{
			return instance;
		}
		
		void Allocate()
		{
		
		}

		void Print()
		{
			
		}

		void Input()
		{
		
			
		}

		void Log()
		{
			
		}

		void Pause()
		{
			system("pause");
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

	void Execute();
	void Interpreter();
}