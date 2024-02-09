#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

template<typename T>
struct variable
{
    std::string var_type;
    bool Unsigned;
    bool Signed;
    T val;
};

template<typename T>
std::vector<std::pair<std::string,variable<T>>> allvars;  //name and variable

std::vector<std::vector<std::string>> pos_of_vars;

std::vector<std::string> allkeywords = 
{
    "int" , "double" , "char" , "float" , "short" , "bool" , "unsigned" , "signed" , "const"
};

std::vector<std::string> lines;

