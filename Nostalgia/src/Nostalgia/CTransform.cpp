#include "Nostalgia/CTransform.hpp"

namespace nostalgia
{

glm::mat4 CTransform::getModelMatrix() const
{
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), m_position);
    glm::mat4 rotationMatrix = glm::mat4_cast(m_rotation);
    glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), m_scale);

    return translationMatrix * rotationMatrix * scaleMatrix;
}

}