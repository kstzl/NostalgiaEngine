#include "Nostalgia/CVertexArrayObject.hpp"

namespace nostalgia
{

CVertexArrayObject::CVertexArrayObject()
{
    glGenVertexArrays(1, &m_vaoId);
}

}