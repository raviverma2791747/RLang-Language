/*
 Author  : Ravi Verma
 Contact : raviverma439@gmail.com
 Version : 1.0
 This is a custom lexer for RLang language.
 Contact author before using it in any project
*/

#pragma once
#include <iostream>
#include<string>
#include<vector>

namespace rlang
{
  
    class Token
    {
    private:
        std::string m_token;
        std::string m_type;
        int m_line;
    public:
        Token(std::string token, std::string type, int line);
        Token(char token, std::string type, int line);
        ~Token();
    public:
        void Log();
        void Push_back(std::string str);
        const std::string& token();
        void Type(std::string type);
        const std::string& Type();
    };

    bool IsKeyword(std::string& buffer);
    bool IsOperator(char ch);
    void Lexer(std::string path,std::vector<Token>& source,int internal);
}