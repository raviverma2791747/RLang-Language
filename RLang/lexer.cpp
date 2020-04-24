#include"lexer.h"
#include<iostream>


using namespace rlang;

/*Token class */

Token::Token() :
    _token()
{

}

Token::Token(std::string token,std::string type) :
    _token(token),
    _type(type)
{

}

Token::~Token()
{

}

void Token::Log()
{
    std::cout << _type << " : "<<_token << std::endl;
}

std::string& Token::token()
{
    return _token;
}

char Token::operator[](int index)
{
    return _token[index];
}

void Token::operator=(std::string str)
{
    _token = str;
}
bool Token::operator==(std::string str)
{
    return _token == str;
}

int Token::size()
{
    return _token.size();
}

