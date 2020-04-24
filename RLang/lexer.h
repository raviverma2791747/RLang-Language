#pragma once
#include<string>


namespace rlang
{
	/*Token*/
	class Token
	{
	private:
		std::string _type;
		std::string _token;
	public:
		Token();
		Token(std::string token,std::string _type);
		virtual void Log();
		std::string& token();
		char operator[](int index);
		bool operator==(std::string str);
		void operator=(std::string str);
		int size();
		~Token();
	};

}