#include <iostream>
#include<fstream>
#include<vector>
#include<string>


class Token
{
private:
    std::string token;
    std::string type;
public:
    Token();
    Token(std::string token,std::string type);
    void Log();
    ~Token();
};

Token::Token()
{


}

Token::Token(std::string token, std::string type):
    token(token),type(type)
{


}

void Token::Log()
{
    std::cout << type << " " << token;
}

Token::~Token()
{

}

std::string operators = "+-*/%&!#~='\"|\\,.:;[](){}<>?";
std::string keywords[] = { "asm","auto","bool","break","case",
"catch","char","class","const_cast","continue",
"default","delete","do","double","dynamic_cast",
"else","enum","explicit","extern","false","float",
"for","friend","gotot","if","inline","int","long",
"mutable","namespace","new","operator","private",
"protected","public","register","reinterpret_cast",
"return","short","signed","sizeof","static",
"static_cast","struct","switch","template","this",
"throw","true","try","typedef","typeid","typename",
"union","unsigned","using","virtual","void",
"volatile","wchar_t","while" };
char constants[] = { "0123456789" };


int main()
{
    std::ifstream fin;
    char ch;
    int count = 0;
    fin.open("prj.txt", std::ios::in);
    while (fin)
    {
        fin.get(ch);
        count += 1;
    }
    fin.close();
    std::cout << count << std::endl;
    char* source = new char[count];
    fin.open("prj.txt", std::ios::in);
    for (int i = 0; i < count; i++)
    {
        fin.get(ch);
        source[i] = ch;
    }
    fin.close();
    std::string src = source;
    std::vector<Token> tkn;
    bool fwd = true;
    for (int i = 0; i < count-1; i++)
    {
       
        if (src[i] == '\n')
        {
           // tkn.push_back("\n");
            continue;
        }
      
        for (int j = 0; j < 28; j++)
        {
            if (src[i] == operators[j])
            {
                tkn.push_back(Token(operators.substr(j, 1),"Operator"));              
                break;
            }
        }
        
        for (int j = 0; j < 61; j++)
        {
            if (src.substr(i,keywords[j].size()) ==keywords[j])
            {
                tkn.push_back(Token(keywords[j],"Keyword"));
                i += keywords[j].size()-1;
                break;
            }
        }
    }
    for (int i = 0; i < tkn.size(); i++)
    {
       tkn[i].Log();
       std::cout << std::endl;
    }
    std::cin.get();
    return 0;
}

