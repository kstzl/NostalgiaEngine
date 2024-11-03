#pragma once

#include "Nostalgia/Core/core.hpp"
#include "Nostalgia/Core/types.hpp"

namespace nostalgia
{

class CVertexBufferObject
{
public:
    NOSTALGIA_API explicit CVertexBufferObject(const void* pData, UUint size);

    NOSTALGIA_API ~CVertexBufferObject()
    {
        glDeleteBuffers(1, &m_vboId);
    }

    NOSTALGIA_API inline void bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
    }

private:
    UVboId m_vboId = 0;
};

}