#include <glad/glad.h>

#include "Nostalgia/CVertexBufferObject.hpp"

namespace nostalgia
{

CVertexBufferObject::CVertexBufferObject(const void* pData, UUint size)
{
    glGenBuffers(1, &m_vboId);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
    glBufferData(GL_ARRAY_BUFFER, size, pData, GL_STATIC_DRAW);
}

}