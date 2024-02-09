#pragma once
#include "types_and_keywords.hpp"
#include <fstream>
#include <sstream>

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
    int line_number = 0;

    while(!code_file.eof())
    {
        std::getline(code_file,line);
        lines.push_back(line);
        line_number++;
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