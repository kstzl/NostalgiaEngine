#pragma once

#include <string>
#include <fstream>
#include <sstream>

namespace nostalgia::utils
{

inline std::string getFileContent(const std::string& filePath)
{
    std::ifstream file(filePath);
    std::stringstream buffer;

    buffer << file.rdbuf();

    return buffer.str();
}

}