#pragma once

#include <vector>
#include <memory>

#include "Nostalgia/CVertexArrayObject.hpp"
#include "Nostalgia/CVertexBufferObject.hpp"
#include "Nostalgia/core/core.hpp"
#include "Nostalgia/CVertex.hpp"

namespace nostalgia
{

class CMesh
{
public:
    NOSTALGIA_API explicit CMesh(const std::vector<CVertex>& vertices);

    NOSTALGIA_API inline void bind()
    {
        NOSTALGIA_ASSERT(m_pVao);
        NOSTALGIA_ASSERT(m_pVbo);

        m_pVao->bind();
        m_pVbo->bind();
    }

    NOSTALGIA_API inline void render() const
    {
        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(m_vtxCount));
    }

private:
    std::unique_ptr<CVertexArrayObject> m_pVao;
    std::unique_ptr<CVertexBufferObject> m_pVbo;
    USize m_vtxCount = 0;
};

}