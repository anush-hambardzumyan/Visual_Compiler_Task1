#pragma once
#include "tokenizing.hpp"
#include <fstream>


void write_to_result(variable var)
{
    std::ofstream write_to;
    write_to.open("result.txt");

    if(!write_to.is_open())
    {
        std::cerr << "file result.txt wasn't opened " << std::endl;
        exit(0);
    }

    
}
