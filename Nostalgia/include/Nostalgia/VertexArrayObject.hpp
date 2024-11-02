#pragma once

#include <glad/glad.h>

#include "Nostalgia/Core/core.hpp"

namespace nostalgia
{

class VertexArrayObject
{
public:
    NOSTALGIA_API VertexArrayObject();

    NOSTALGIA_API VertexArrayObject& operator=(const VertexArrayObject&) = default;
    NOSTALGIA_API VertexArrayObject(const VertexArrayObject&) = default;

    NOSTALGIA_API ~VertexArrayObject()
    {
        glDeleteVertexArrays(1, &m_vaoId);
    }

    NOSTALGIA_API inline void bind() const
    {
        glBindVertexArray(m_vaoId);
    }

    NOSTALGIA_API inline void bindAttribute(unsigned int index, unsigned int size, unsigned int type, unsigned int stride,
                                            void* pOffset) const

    {
        glVertexAttribPointer(index, size, type, GL_FALSE, stride, pOffset);
        glEnableVertexAttribArray(index);
    }

private:
    unsigned int m_vaoId = 0;
};

}