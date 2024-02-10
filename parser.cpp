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
                    variable ob1 = variable(each_dec[0],i,j);
                    ob1.was_called = 1;
                    allvars.push_back(ob1);
                }

                else
                {
                    variable var1 = findVariable(each_dec[0]);
                    var1.was_called = 1; 
                }
            }

            else
            {
                variable each_var = variable();
                each_var.def_ctor = 0;
                each_var.is_valid = 1;     

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
    write_to_files();
}

void type_finder(std::vector<std::string>& each_dec, variable& each_var)
{
    auto it1 = std::find(each_dec.begin(),each_dec.end(),"int");
    if(it1 != each_dec.end())
    {
        each_var.var_type = "i";
        each_var.var_typename += "int ";
        return;   
    }

    auto it2 = std::find(each_dec.begin(),each_dec.end(),"double");
    if(it2 != each_dec.end())
    {
        each_var.var_type = "d";
        each_var.var_typename += "double ";
        return;   
    }

    auto it3 = std::find(each_dec.begin(),each_dec.end(),"float");
    if(it3 != each_dec.end())
    {
        each_var.var_type = "f";
        each_var.var_typename += "float ";
        return;   
    }

    auto it4 = std::find(each_dec.begin(),each_dec.end(),"short");
    if(it4 != each_dec.end())
    {
        each_var.var_type = "sh";
        each_var.var_typename += "short ";
        return;   
    }

    auto it5 = std::find(each_dec.begin(),each_dec.end(),"bool");
    if(it5 != each_dec.end())
    {
        each_var.var_type = "b";
        each_var.var_typename += "bool ";
        return;   
    }

    auto it6 = std::find(each_dec.begin(),each_dec.end(),"char");
    if(it6 != each_dec.end())
    {
        each_var.var_type = "ch";
        each_var.var_typename += "char ";
        return;   
    }

    else if(each_var.Signed || each_var.Unsigned)  //unsigned f; -> f is integer    signed f -> f is integer
    {
        each_var.var_type = "i";
        each_var.var_typename += "int ";
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