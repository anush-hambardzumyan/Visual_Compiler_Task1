#ifndef WRITE_TO_FILES
#define WRITE_TO_FILES
#include "tokenizing.hpp"
#include <iomanip>

void modify_var_type(variable& var);

void write_to_files()
{
    std::ofstream write_to_res;
    std::ofstream write_to_info;
    write_to_res.open("result.txt");
    write_to_info.open("typeInfo.txt");

    if(!write_to_res.is_open() || !write_to_info.is_open())
    {
        std::cerr << "File wasn't opened: " << std::endl;
        exit(0);
    }
////write to result.txt
    write_to_res<< std::setw(15) << std::internal << "Type"
                << std::setw(15) << std::internal << "Value"
                << std::setw(15) << std::internal << "Name"
                << std::setw(15) << std::internal << "Line"
                << std::setw(15) << std::internal << "Position" << std::endl;    

    for(int i = 0; i < allvars.size() ; ++i)
    {
        modify_var_type(allvars[i]);
        if(allvars[i].was_called == 1)
        {
            write_to_res<< std::setw(15) << std::internal << allvars[i].var_type
                        << std::setw(15) << std::internal << allvars[i].val
                        << std::setw(15) << std::internal << allvars[i].name
                        << std::setw(15) << std::internal << allvars[i].line
                        << std::setw(15) << std::internal << allvars[i].pos << std::endl;   
        }
    }
/////write to typeInfo.txt
    for(int i = 0; i < allvars.size(); ++i)
    {
        variable each_var = allvars[i];
        if(each_var.is_valid == 1)
        {
            write_to_info << each_var.var_typename << each_var.name;

            if(each_var.val == "-" ||  each_var.val == "GARBAGE")
            {
                write_to_info << ";" << std::endl;
            }

            else
            {
                write_to_info << " = " << each_var.val  << "; "<< std::endl;
            }
        }
        
    }
    write_to_info.close();
    write_to_res.close();
}

void modify_var_type(variable& var)
{
    if(var.var_type == "-")
    {
        return;
    }

    while(var.long_counter)
    {
        var.var_type = "l" + var.var_type;
        var.var_typename = "long " + var.var_typename;
        var.long_counter--;
    }

    if(var.Unsigned)
    {
        var.var_type = "u" + var.var_type;
        var.var_typename = "unsigned " + var.var_typename;
    }

    if(var.Constant)
    {
        var.var_type = "c" + var.var_type;
        var.var_typename = "const " + var.var_typename;
    }
}

#endif