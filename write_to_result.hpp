#pragma once
#include "tokenizing.hpp"
#include <fstream>
#include <iomanip>
void modify_var_type(variable& var);

void write_to_result()
{
    std::ofstream write_to;
    write_to.open("result.txt");

    if(!write_to.is_open())
    {
        std::cerr << "file result.txt wasn't opened " << std::endl;
        exit(0);
    }

    write_to<< std::setw(15) << std::internal << "Type"
            << std::setw(15) << std::internal << "Value"
            << std::setw(15) << std::internal << "Name"
            << std::setw(15) << std::internal << "Line"
            << std::setw(15) << std::internal << "Position" << std::endl;    

    for(int i = 0; i < allvars.size(); ++i)
    {
        modify_var_type(allvars[i]);
    }

    for(int i = 0; i < allcalled.size(); ++i)
    {
        modify_var_type(allcalled[i]);
    }

    for(int i = 0; i < allcalled.size(); ++i)
    {
        if(findVariable(allcalled[i].name).def_ctor != 1 )
        {
            allcalled[i].is_valid_dec = 1;
        }
    }

    for(int i = 0; i < allcalled.size() ; ++i)
    {
        write_to<< std::setw(15) << std::internal << allcalled[i].var_type
                << std::setw(15) << std::internal << allcalled[i].val
                << std::setw(15) << std::internal << allcalled[i].name
                << std::setw(15) << std::internal << allcalled[i].line
                << std::setw(15) << std::internal << allcalled[i].pos << std::endl;
    }          
}

void modify_var_type(variable& var)
{
    if(var.var_type == "-")
    {
        var.val = "-";
        return;
    }

    if(var.long_counter)
    {
        int cnt = var.long_counter;
        while(cnt)
        {
            var.var_type = "l" + var.var_type;
            --cnt;
        }
    }

    if(var.Unsigned)
    {
        var.var_type = "u" + var.var_type;
    }

    if(var.Constant)
    {
        var.var_type = "c" + var.var_type;
    }
}