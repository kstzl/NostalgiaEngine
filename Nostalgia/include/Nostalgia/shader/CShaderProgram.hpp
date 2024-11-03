#pragma once

#include <string>

#include <glad/glad.h>

#include "Nostalgia/core/core.hpp"
#include "Nostalgia/core/types.hpp"
#include "Nostalgia/core/utils.hpp"

namespace nostalgia
{

class CShaderProgram
{
public:
    NOSTALGIA_API CShaderProgram(const std::string& fragmentShaderPath, const std::string& vertexShaderPath);

    NOSTALGIA_API ~CShaderProgram()
    {
        glDeleteProgram(m_shaderProgram);
    }

    NOSTALGIA_API inline void use() const
    {
        glUseProgram(m_shaderProgram);
    }

private:
    UShaderId m_fragmentShader;
    UShaderId m_vertexShader;
    UShaderProgramId m_shaderProgram;
};

}