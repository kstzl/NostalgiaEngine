#include "Nostalgia/Mesh/CMesh.hpp"

namespace nostalgia
{

CMesh::CMesh(const std::vector<CVertex>& vertices)
    : m_vtxCount(vertices.size())
{
    m_pVao = std::make_unique<nostalgia::CVertexArrayObject>();
    m_pVao->bind();

    m_pVbo = std::make_unique<nostalgia::CVertexBufferObject>(vertices.data(), m_vtxCount * sizeof(nostalgia::CVertex));
    m_pVbo->bind();

    m_pVao->bindAttribute(0, 3, GL_FLOAT, 3 * sizeof(float), nullptr);
}

}