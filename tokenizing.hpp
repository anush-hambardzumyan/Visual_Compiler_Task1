#ifndef TOKENIZING_HPP
#define TOKENIZING_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

//TYPES AND KEYWORDS
struct variable
{
    std::string name = "-";
    std::string var_type = "-";
    std::string var_typename;
    std::string val = "-";
    int line;
    int pos;
    int long_counter = 0;
    bool Unsigned = 0;
    bool Signed = 0;
    bool Constant = 0;
    bool was_called = 0;
    bool def_ctor = 0;
    bool is_valid = 0;
 
    variable() : def_ctor(true) {}

    variable(std::string name1 , int line1 , int pos1) 
    : name(name1) ,line(line1) , pos(pos1){}
};

std::vector<variable> allvars;  //name and variable
std::vector<std::string> lines;

variable ob = variable();
variable& findVariable(const std::string& str) 
{
    for(int i = 0; i < allvars.size(); ++i)
    {
        if(str == allvars[i].name)
        {
            allvars[i].was_called = 1;
            return allvars[i];
        }
    }
    return ob;
}
////////

std::vector<std::string> splitString(const std::string& input, char delimiter);
std::vector<std::string> Lines();
std::vector<std::vector<std::string>> lines_and_tokens();

std::string carry = "";

std::vector<std::string> splitString(const std::string& input, char delimiter) 
{
    std::vector<std::string> parts;
    std::istringstream stream(input);
    std::string part;

    while (std::getline(stream, part, delimiter)) 
    {
        if (!part.empty()) 
        {
            parts.push_back(part);
        }
    }
    return parts;
}

std::vector<std::string> Lines()
{
    std::ifstream code_file;
    code_file.open("text.txt");

    if(!code_file.is_open())
    {
        return {};
    }

    std::string line;

    while(!code_file.eof())
    {
        std::getline(code_file,line);
        lines.push_back(line);
    }
    code_file.close();
    return lines;
}

std::vector<std::vector<std::string>> lines_and_tokens()
{
    std::vector<std::string> lines = Lines();
    std::vector<std::vector<std::string>> decStream;

    for(std::string line : lines)
    {
        std::vector<std::string> tokens;

        if(carry != "")
        {
            line = carry + " " + line;
            carry = "";
        }

        if (!line.empty() && line.back() == ';') 
        {
            tokens = splitString(line, ';');
            decStream.push_back(tokens);
        }

        else 
        {
            size_t pos = line.find_last_of(';');
            if (pos != std::string::npos)
            {
                carry = line.substr(pos + 1);
                line = line.substr(0, pos + 1);
            }
            tokens = splitString(line, ';');
            decStream.push_back(tokens);
        }
    }
    return decStream;
}

#endif