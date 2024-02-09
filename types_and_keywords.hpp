#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

struct variable
{
    variable(std::string name1, std::string var_type1, bool uns1,bool s1,bool has_val1, std::string value,int line1 , int pos1 , bool is_valid1)
    : name(name1) , var_type(var_type1) , Unsigned(uns1) , Signed(s1) , has_val(has_val1) ,
    val(value) , line(line1) , pos(pos1) , is_valid_dec(is_valid1) {} 

    variable() : default_ctor(1) {}

    std::string name;
    std::string var_type;
    bool Unsigned;
    bool Signed;
    bool has_val;
    std::string val;
    int line;
    int pos;
    bool is_valid_dec;
    bool default_ctor;
};


std::vector<variable> allvars;  //name and variable

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

