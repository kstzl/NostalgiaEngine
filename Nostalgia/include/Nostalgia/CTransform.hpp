#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Nostalgia/core/core.hpp"

namespace nostalgia
{

class CTransform
{
public:
    NOSTALGIA_API inline glm::mat4 getModelMatrix() const
    {
        glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), m_position);
        glm::mat4 rotationMatrix = glm::mat4_cast(m_rotation);
        glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), m_scale);

        return translationMatrix * rotationMatrix * scaleMatrix;
    }

    NOSTALGIA_API inline void setPosition(const glm::vec3& newPosition)
    {
        m_position = newPosition;
    }

    NOSTALGIA_API inline void setScale(const glm::vec3& newScale)
    {
        m_scale = newScale;
    }

    NOSTALGIA_API inline void setRotation(const glm::vec3& newRotationQuat)
    {
        m_rotation = newRotationQuat;
    }

private:
    glm::vec3 m_position;
    glm::vec3 m_scale;
    glm::quat m_rotation;
};

}