#pragma once
#include <cassert>
#include <iostream>
#include <fstream>

bool inputInFile(const char* filename)
{
    assert(filename != nullptr);//checking name of file

    std::ofstream file;//opening file
    file.open(filename);

    assert(file.is_open() == true);//checking if file is opened

    std::string str;
    std::cin >> str;
    file << str << std::endl;
    
    file.close();

    return true;
}

bool readingFromFile(const char* filename, std::string &inputstring)
{
    assert(filename != nullptr); //checking name of file

    std::ifstream file;//opening file
    file.open(filename);

    assert(file.is_open() == true); //checking if file is opened

    file >> inputstring;

    file.close();//closing file

    return true;
}