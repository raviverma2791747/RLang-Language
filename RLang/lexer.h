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
        bool operator==(std::string str);
        bool operator==(char str);
    public:
        void Log();
        void Push_back(char ch);
        void Push_back(std::string str);
        std::string token();
        void Type(std::string type);
        std::string Type();
    };

    bool IsKeyword(std::string& buffer);
    bool IsOperator(char ch);
    void Lexer(std::string path,std::vector<Token>& source);
}