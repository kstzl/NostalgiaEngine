#include <iostream>

#include "Nostalgia/Shader/ShaderProgram.hpp"

namespace nostalgia
{

ShaderProgram::ShaderProgram(const std::string& fragmentShaderPath,
                             const std::string& vertexShaderPath)
{
    const std::string fragmentShaderContent = utils::getFileContent(fragmentShaderPath);
    const std::string vertexShaderContent = utils::getFileContent(vertexShaderPath);

    const char* pFragmentShaderContent = fragmentShaderContent.c_str();
    const char* pVertexShaderContent = vertexShaderContent.c_str();

    NOSTALGIA_ASSERT(pFragmentShaderContent);

    m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_fragmentShader, 1, &pFragmentShaderContent, nullptr);
    glCompileShader(m_fragmentShader);

    NOSTALGIA_ASSERT(pVertexShaderContent);

    m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_vertexShader, 1, &pVertexShaderContent, nullptr);
    glCompileShader(m_vertexShader);

    m_shaderProgram = glCreateProgram();

    glAttachShader(m_shaderProgram, m_fragmentShader);
    glAttachShader(m_shaderProgram, m_vertexShader);
    glLinkProgram(m_shaderProgram);

    glDeleteShader(m_fragmentShader);
    glDeleteShader(m_vertexShader);
}

}