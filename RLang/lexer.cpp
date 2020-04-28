#include"lexer.h"
#include<fstream>
#include<vector>

using namespace rlang;

char operators[] = "=,;+-*/(){}&";
const int operator_count = 13;
std::string Keywords[] = {"endl","null","true","false","main","print","bool","int","float","string","return","break","continue","exit","input"};
const int keyword_count = 15;

Token::Token(std::string token, std::string type, int line) :
    m_token(token), m_type(type), m_line(line)
{
}

Token::Token(char token, std::string type, int line) :
    m_token(1, token), m_type(type), m_line(line)
{
}

Token::~Token()
{

}

bool Token::operator==(std::string str)
{
    if (m_token == str)
    {
        return true;
    }
    return false;
}

bool Token::operator==(char str)
{
    std::string t_str(str, 1);
    if (m_token == t_str)
    {
        return true;
    }
    return false;
}

void Token::Log()
{
    std::cout.width(4);
    std::cout << std::left << m_line << " | ";
    std::cout.width(10);
    std::cout << std::left << m_type << " | " << m_token << std::endl;
}
void Token::Log(int internal)
{
    std::cout << m_token << " ";
}

void Token::Push_back(char ch)
{
    m_token.push_back(ch);
}

void Token::Push_back(std::string str)
{
    for (unsigned int i = 0; i < str.size(); i++)
    {
        m_token.push_back(str[i]);
    }
}

std::string Token::token()
{
    return m_token;
}

void Token::Type(std::string type)
{
    m_type = type;
}

std::string Token::Type()
{
    return m_type;
}

bool rlang::IsKeyword(std::string& buffer)
{
    for (int i = 0; i < keyword_count; i++)
    {
        if (buffer == Keywords[i])
        {
            return true;
        }
    }
    return false;
}

bool rlang::IsOperator(char ch)
{
    for (int i = 0; i < operator_count; i++)
    {
        if (ch == operators[i])
        {
            return true;
        }
    }
    return false;
}

void rlang::Lexer(std::string path, std::vector<Token>& source,int internal)
{
    /*First Pass*/
    std::ifstream fin;
    fin.open(path, std::ios::in);
    if (!fin)
    {
        std::cout << "No such file exists" << std::endl;
    }
    std::string buffer;
    char ch;
    bool flag = false;
    int line = 1;
    while (fin)
    {
        flag = false;
        fin.get(ch);
        if (fin.eof())
        {
            break;
        }
        //track lines
        else if (ch == '\n')
        {
            line += 1;
            continue;
        }
        //remove spaces
        else if (ch == ' ')
        {
            continue;
        }
        //comment identification
        else if (ch == '/')
        {
            buffer.push_back(ch);
            fin.get(ch);
            if (ch == '*')
            {
                int t_line = line;
                buffer.push_back(ch);
                bool t_flag = true;
                while (t_flag)
                {
                    fin.get(ch);
                    if (ch == '*')
                    {
                        buffer.push_back(ch);
                        fin.get(ch);
                        if (ch == '/')
                        {
                            buffer.push_back(ch);
                            t_flag = false;
                        }
                        else
                        {
                            buffer.push_back(ch);
                        }
                    }
                    else if (ch == '\n')
                    {
                        buffer.push_back(ch);
                        line += 1;
                    }
                    else
                    {
                        buffer.push_back(ch);
                    }
                }
                source.push_back(Token(buffer, "comment", t_line));
                buffer.clear();
                continue;
            }
            else if (ch == '/')
            {
                buffer.push_back(ch);
                bool t_flag = true;
                while (t_flag)
                {
                    fin.get(ch);
                    if (ch == '\n')
                    {
                        line += 1;
                        t_flag = false;
                    }
                    else
                    {
                        buffer.push_back(ch);
                    }
                }
                source.push_back(Token(buffer, "comment", line - 1));
                buffer.clear();
                continue;
            }
            else
            {
                int pos = fin.tellg();
                fin.seekg(pos - 1);
                source.push_back(Token(buffer, "operator", line));
                buffer.clear();
                continue;
            }
        }
        //String identification
        else if (ch == '\"')
        {
            buffer.push_back(ch);
            fin.get(ch);
            while (ch != '\"')
            {
                buffer.push_back(ch);
                fin.get(ch);
            }
            buffer.push_back(ch);
            source.push_back(Token(buffer, "string", line));
            buffer.clear();
            continue;
        }
        else if (IsOperator(ch) == true)
        {
            source.push_back(Token(ch, "operator", line));
            continue;
        }
        //Constant identification
        else if (isdigit(ch))
        {
            buffer.push_back(ch);
            fin.get(ch);
            while (isdigit(ch) || ch == '.')
            {
                buffer.push_back(ch);
                fin.get(ch);
            }
            int pos = fin.tellg();
            fin.seekg(pos - 1);
            source.push_back(Token(buffer, "constant", line));
            buffer.clear();
            continue;
        }
        //Keyword identification
        while (!flag)
        {
            buffer.push_back(ch);
            if (fin.eof())
            {
                buffer.pop_back();
                source.push_back(Token(buffer, "identifier", line));
                flag = true;
                break;
            }
            if (ch == '\n')
            {
                line += 1;
                buffer.pop_back();
                break;
            }
            else if (ch == ' ')
            {
                break;
            }
            else if (IsOperator(ch))
            {
                buffer.pop_back();
                source.push_back(Token(buffer, "identifier", line));
                source.push_back(Token(ch, "operator", line));
                buffer.clear();
                flag = true;
                break;
            }
            else if (IsKeyword(buffer) == true)
            {
                source.push_back(Token(buffer, "keyword", line));
                buffer.clear();
                flag = true;
                break;
            }
            fin.get(ch);
        }
        //UnIdentified string saved as identifier
        if (flag == false)
        {
            source.push_back(Token(buffer, "identifier", line));
            buffer.clear();
        }
    }
    fin.close();
    if (internal == 1 ||internal == 3)
    {
        std::ofstream fout;
        fout.open("a.txt", std::ios::out);
        for (int i = 0; i < source.size(); i++)
        {
            fout << source[i].token() << std::endl;
        }
        fout.close();
    }
    if (internal == 2 || internal == 3)
    {
        for (int i = 0; i < source.size(); i++)
        {
            source[i].Log();
        }
    }
}
