#pragma once

#include <string>

#include <glad/glad.h>

#include "Nostalgia/Core/core.hpp"
#include "Nostalgia/utils.hpp"

namespace nostalgia
{

class ShaderProgram
{
public:
    NOSTALGIA_API ShaderProgram(const std::string& fragmentShaderPath,
                                const std::string& vertexShaderPath);

    NOSTALGIA_API inline void use() const
    {
        glUseProgram(m_shaderProgram);
    }

    NOSTALGIA_API inline void destroy() const
    {
        glDeleteProgram(m_shaderProgram);
    }

private:
    unsigned int m_fragmentShader;
    unsigned int m_vertexShader;
    unsigned int m_shaderProgram;
};

}