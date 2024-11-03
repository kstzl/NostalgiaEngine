#pragma once

#include <glm/glm.hpp>

#include "Nostalgia/core/core.hpp"

namespace nostalgia
{

class CVertex
{
public:
    NOSTALGIA_API explicit CVertex(const glm::vec3& position);

private:
    glm::vec3 m_position;
};

}