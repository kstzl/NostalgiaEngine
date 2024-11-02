#pragma once

#include "Nostalgia/Core/core.hpp"

namespace nostalgia
{

class VertexBufferObject
{
public:
    NOSTALGIA_API explicit VertexBufferObject(const void* pData, size_t size);

    NOSTALGIA_API ~VertexBufferObject()
    {
        glDeleteBuffers(1, &m_bufferId);
    }

    NOSTALGIA_API inline void bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
    }

private:
    unsigned int m_bufferId = 0;
};

}