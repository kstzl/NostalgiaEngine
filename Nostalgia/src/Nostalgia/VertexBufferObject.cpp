#include <glad/glad.h>

#include "Nostalgia/VertexBufferObject.hpp"

namespace nostalgia
{

VertexBufferObject::VertexBufferObject(const void* pData, size_t size)
{
    glGenBuffers(1, &m_bufferId);
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
    glBufferData(GL_ARRAY_BUFFER, static_cast<unsigned int>(size), pData, GL_STATIC_DRAW);
}

}