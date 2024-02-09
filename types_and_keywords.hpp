#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

struct variable
{
    std::string name;
    std::string var_type;
    bool Unsigned = 0;
    bool Signed = 0;
    bool Constant;
    std::string val;
    bool has_val;
    int line;
    int pos;
    bool def_ctor;
    int long_counter = 0;
 
    variable() : def_ctor(true) {}

    variable(std::string name1 , int line1 , int pos1) 
    : name(name1) , var_type("-") ,line(line1) , pos(pos1){}
};


std::vector<variable> allvars;  //name and variable
std::vector<variable> allcalled;

std::vector<std::string> allkeywords = 
{
    "int" , "double" , "char" , "float" , "short" , "bool" , "unsigned" , "signed" , "const"
};

std::vector<std::string> lines;

variable findVariable(const std::string& str) 
{
    for(int i = 0; i < allvars.size(); ++i)
    {
        if(str == allvars[i].name)
        {
            return allvars[i];
        }
    }
    return variable();
}

