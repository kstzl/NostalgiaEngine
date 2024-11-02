#pragma once

#include <exception>
#include <string>
#include <iostream>

#include "Nostalgia/Core/core.hpp"

namespace nostalgia::exceptions
{

class EngineException : public std::exception
{
public:
    explicit EngineException(const std::string& message)
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