#pragma once

#include <glad/glad.h>

#include "Nostalgia/core/core.hpp"
#include "Nostalgia/core/types.hpp"

namespace nostalgia
{

class CVertexArrayObject
{
public:
    NOSTALGIA_API CVertexArrayObject();

    NOSTALGIA_API CVertexArrayObject& operator=(const CVertexArrayObject&) = default;
    NOSTALGIA_API CVertexArrayObject(const CVertexArrayObject&) = default;

    NOSTALGIA_API ~CVertexArrayObject()
    {
        glDeleteVertexArrays(1, &m_vaoId);
    }

    NOSTALGIA_API inline void bind() const
    {
        glBindVertexArray(m_vaoId);
    }

    NOSTALGIA_API inline void bindAttribute(UUint index, UUint size, UUint type, UUint stride, void* pOffset) const

    {
        glVertexAttribPointer(index, size, type, GL_FALSE, stride, pOffset);
        glEnableVertexAttribArray(index);
    }

private:
    UVaoId m_vaoId = 0;
};

}