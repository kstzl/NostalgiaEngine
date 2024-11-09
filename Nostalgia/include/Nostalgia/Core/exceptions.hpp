#pragma once

#include <exception>
#include <string>
#include <iostream>

#include "Nostalgia/core/core.hpp"

namespace nostalgia::exceptions
{

class CEngineException : public std::exception
{
public:
    explicit CEngineException(const std::string& message)
        : m_message(message)
    {
    }

    const char* what() const noexcept override
    {
        return m_message.c_str();
    }

private:
    std::string m_message;
};

}