#include <iostream>

#include <glm/glm.hpp>

#include "Nostalgia/shader/CShaderProgram.hpp"

namespace nostalgia
{

CShaderProgram::CShaderProgram(const std::string& fragmentShaderPath, const std::string& vertexShaderPath)
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

void CShaderProgram::setMVP(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix, const glm::mat4& modelMatrix) const
{
    GLuint viewLoc = glGetUniformLocation(m_shaderProgram, "view");
    GLuint projLoc = glGetUniformLocation(m_shaderProgram, "projection");
    GLuint modelLoc = glGetUniformLocation(m_shaderProgram, "model");

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &viewMatrix[0][0]);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &projectionMatrix[0][0]);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &modelMatrix[0][0]);
}

}