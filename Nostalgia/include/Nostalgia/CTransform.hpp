#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Nostalgia/core/core.hpp"

namespace nostalgia
{

class CTransform
{
public:
    NOSTALGIA_API CTransform() = default;

    NOSTALGIA_API explicit CTransform(const glm::vec3& initialPosition)
        : m_position(initialPosition)
    {
    }

    NOSTALGIA_API glm::mat4 getModelMatrix() const;

    NOSTALGIA_API inline const glm::vec3& getPosition() const
    {
        return m_position;
    }

    NOSTALGIA_API inline glm::vec3 getForwardDirection() const
    {
        return m_rotation * glm::vec3(0.0f, 0.0f, -1.0f);
    }

    NOSTALGIA_API inline glm::vec3 getUpDirection() const
    {
        return m_rotation * glm::vec3(0.0f, 1.0f, 0.0f);
    }

    NOSTALGIA_API inline glm::vec3 getRightDirection() const
    {
        return m_rotation * glm::vec3(1.0f, 0.0f, 0.0f);
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

    NOSTALGIA_API inline float getPitch() const
    {
        return m_pitch;
    }

    NOSTALGIA_API inline float getYaw() const
    {
        return m_yaw;
    }

    NOSTALGIA_API inline void setPitch(float newPitch)
    {
        m_pitch = newPitch;
        updateRotation();
    }

    NOSTALGIA_API inline void setYaw(float newYaw)
    {
        m_yaw = newYaw;
        updateRotation();
    }

private:
    void updateRotation()
    {
        glm::quat rotationYaw = glm::angleAxis(glm::radians(m_yaw), glm::vec3(0.0f, 1.0f, 0.0f));
        glm::quat rotationPitch = glm::angleAxis(glm::radians(m_pitch), glm::vec3(1.0f, 0.0f, 0.0f));

        m_rotation = rotationYaw * rotationPitch;
    }

    glm::vec3 m_position = {0.0f, 0.0f, 0.0f};
    glm::vec3 m_scale = {1.0f, 1.0f, 1.0f};
    glm::quat m_rotation = {glm::quat(1.0f, 0.0f, 0.0f, 0.0f)};

    float m_pitch = 0.0;
    float m_yaw = 0.0f;
};

}