#pragma once
#include "types_and_keywords.hpp"
#include "tokenizing.hpp"
#include "writeToFiles.hpp"

void type_finder(std::vector<std::string>& each_dec, variable& each_var);
void var_and_val_finder(std::vector<std::string>& each_dec, variable& each_var);


void parsing()
{
    std::vector<std::vector<std::string>> test = lines_and_tokens();
    for(int i = 0; i < test.size(); ++i)
    {
        for(int j = 0; j < test[i].size(); ++j)
        {        
            std::vector<std::string> each_dec = splitString(test[i][j], ' ');
            if(each_dec.size() == 1) 
            {
                if(findVariable(each_dec[0]).def_ctor == 1) // A ;
                {
                    allcalled.push_back(variable(each_dec[0],i,j));
                }

                else
                {
                    allcalled.push_back(findVariable(each_dec[0]));
                }
            }

            else
            {
                variable each_var = variable();
                each_var.def_ctor = 0;

                auto it1 = std::find(each_dec.begin(),each_dec.end(),"const");
                if(it1 != each_dec.end())
                {
                    each_var.Constant = 1;   
                }

                auto it2 = std::find(each_dec.begin(),each_dec.end(),"unsigned");
                if(it2 != each_dec.end())
                {
                    each_var.Unsigned = 1;   
                } 
                

                for(int i = 0; i < each_dec.size(); ++i)
                {
                    if(each_dec[i] == "long")
                    {
                        each_var.long_counter++;
                    }
                }

                type_finder(each_dec,each_var);
                var_and_val_finder(each_dec,each_var);
                each_var.line = i;
                each_var.pos = j;
                allvars.push_back(each_var);
            }
        }        
    }
    write_to_result();
    write_to_typeInfo();
}

void type_finder(std::vector<std::string>& each_dec, variable& each_var)
{
    auto it1 = std::find(each_dec.begin(),each_dec.end(),"int");
    if(it1 != each_dec.end())
    {
        each_var.var_type = "i";
        return;   
    }

    auto it2 = std::find(each_dec.begin(),each_dec.end(),"double");
    if(it2 != each_dec.end())
    {
        each_var.var_type = "d";
        return;   
    }

    auto it3 = std::find(each_dec.begin(),each_dec.end(),"float");
    if(it3 != each_dec.end())
    {
        each_var.var_type = "f";
        return;   
    }

    auto it4 = std::find(each_dec.begin(),each_dec.end(),"short");
    if(it4 != each_dec.end())
    {
        each_var.var_type = "sh";
        return;   
    }

    auto it5 = std::find(each_dec.begin(),each_dec.end(),"bool");
    if(it5 != each_dec.end())
    {
        each_var.var_type = "b";
        return;   
    }

    auto it6 = std::find(each_dec.begin(),each_dec.end(),"char");
    if(it6 != each_dec.end())
    {
        each_var.var_type = "ch";
        return;   
    }

    else if(each_var.Signed || each_var.Unsigned)  //unsigned f; -> f is integer    signed f -> f is integer
    {
        each_var.var_type = "i";
        return;
    }
    return ;
}

void var_and_val_finder(std::vector<std::string>& each_dec, variable& each_var)
{
    bool assigning = false;
    for(int i = 0;i < each_dec.size(); ++i)
    {
        if(each_dec[i] == "=")
        {
            assigning = true;
            each_var.has_val = true;
            each_var.val = each_dec[each_dec.size() - 1];
        }
    }

    if(assigning) //unsigned int alo = 9;
    {
        each_var.name = each_dec[each_dec.size() - 3];
    }

    else //unsigned int alo;
    {
        each_var.name = each_dec[each_dec.size() - 1];
        each_var.val = "GARBAGE";
    }
}

int main()
{
    parsing();
}