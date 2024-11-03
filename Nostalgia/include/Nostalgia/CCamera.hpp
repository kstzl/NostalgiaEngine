#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Nostalgia/core/core.hpp"

namespace nostalgia
{

class CCamera
{
public:
    NOSTALGIA_API CCamera(const glm::vec3& position, float fov, float aspectRatio, float nearClip, float farClip);

    NOSTALGIA_API inline const glm::mat4& getViewMatrix() const
    {
        return m_viewMatrix;
    }

    NOSTALGIA_API inline const glm::mat4& getProjectionMatrix() const
    {
        return m_projectionMatrix;
    }

private:
    void updateViewMatrix()
    {
        m_viewMatrix = glm::lookAt(m_position, m_position + m_direction, m_up);
    }

    void updateProjectionMatrix()
    {
        m_projectionMatrix = glm::perspective(glm::radians(m_fov), m_aspectRatio, m_nearClip, m_farClip);
    }

    glm::vec3 m_position;
    glm::vec3 m_direction = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);

    float m_fov;
    float m_aspectRatio;
    float m_nearClip;
    float m_farClip;

    glm::mat4 m_viewMatrix = glm::mat4(1.0f);
    glm::mat4 m_projectionMatrix = glm::mat4(1.0f);
};

}