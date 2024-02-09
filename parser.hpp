#pragma once
#include "tokenizing.hpp"
#include "write_to_result.hpp"

std::vector<std::vector<std::string>> parsing()
{
    std::vector<std::vector<std::string>> test = lines_and_tokens();
    for(int i = 0; i < test.size(); ++i)
    {
        for(int j = 0; j < test[i].size(); ++j)
        {
            std::vector<std::string> each_dec = splitString(test[i][j], ' ');
            if(each_dec.size() == 1 && findVariable(each_dec[0]).default_ctor == 1) // A ;
            {
                
            }
        }        
    }
}