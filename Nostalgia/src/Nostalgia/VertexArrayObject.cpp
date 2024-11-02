#include "Nostalgia/VertexArrayObject.hpp"

namespace nostalgia
{

VertexArrayObject::VertexArrayObject()
{
    glGenVertexArrays(1, &m_vaoId);
}

}