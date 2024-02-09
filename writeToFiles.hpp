#pragma once
#include "tokenizing.hpp"
#include <fstream>
#include <iomanip>
void modify_var_type(variable& var);

void write_to_result()
{
    std::ofstream write_to_res;
    write_to_res.open("result.txt");

    if(!write_to_res.is_open())
    {
        std::cerr << "file result.txt wasn't opened " << std::endl;
        exit(0);
    }

    write_to_res<< std::setw(15) << std::internal << "Type"
                << std::setw(15) << std::internal << "Value"
                << std::setw(15) << std::internal << "Name"
                << std::setw(15) << std::internal << "Line"
                << std::setw(15) << std::internal << "Position" << std::endl;    

    // for(int i = 0; i < allvars.size(); ++i)
    // {
    //     modify_var_type(allvars[i]);
    // }

    for(int i = 0; i < allcalled.size(); ++i)
    {
        modify_var_type(allcalled[i]);
    }

    for(int i = 0; i < allcalled.size() ; ++i)
    {
        write_to_res<< std::setw(15) << std::internal << allcalled[i].var_type
                    << std::setw(15) << std::internal << allcalled[i].val
                    << std::setw(15) << std::internal << allcalled[i].name
                    << std::setw(15) << std::internal << allcalled[i].line
                    << std::setw(15) << std::internal << allcalled[i].pos << std::endl;
    }          
    write_to_res.close();
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
        if(var.long_counter == 1)
        {
            var.var_type = "l" + var.var_type;
        }

        if(var.long_counter == 2)
        {
            var.var_type = "l" + var.var_type;
            var.var_type = "l" + var.var_type;
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


void write_to_typeInfo()
{
    std::ofstream write_to_info;
    write_to_info.open("typeInfo.txt");

    if(!write_to_info.is_open())
    {
        std::cerr << "file typeInfo.txt wasn't opened " << std::endl;
        exit(0);
    }

    for(int i = 0; i < allvars.size(); ++i)
    {
        variable each_var = allvars[i];
        if(each_var.Constant == 1)
        {
            write_to_info << "const" << " ";
        }

        if(each_var.Unsigned == 1)
        {
            write_to_info << "unsigned" << " ";
        }

        if(each_var.Signed == 1)
        {
            write_to_info << "signed" << " ";
        }

        if(each_var.long_counter)
        {
            if(each_var.long_counter == 1)
            {
                write_to_info << "long" << " ";
            }

            if(each_var.long_counter == 2)
            {
                write_to_info << "long long" << " ";
            }
        }

        if(each_var.var_type == "i")
        {
            write_to_info << "int" << " ";
        }

        if(each_var.var_type == "sh")
        {
            write_to_info << "short " << " ";
        }

        if(each_var.var_type == "ch")
        {
            write_to_info << "char" << " ";
        }

        if(each_var.var_type == "d")
        {
            write_to_info << "double" << " ";
        }

        if(each_var.var_type == "f")
        {
            write_to_info << "float" << " ";
        }

        if(each_var.var_type == "b")
        {
            write_to_info << "bool" << " ";
        }

        write_to_info << each_var.name ;

        if(each_var.has_val == false ||  each_var.val == "GARBAGE")
        {
            write_to_info << ";" << std::endl;
        }

        else
        {
            write_to_info << " = " << each_var.val  << "; "<< std::endl;
        }
    }
}
