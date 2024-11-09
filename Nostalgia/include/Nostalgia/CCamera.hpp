#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Nostalgia/core/core.hpp"
#include "Nostalgia/CTransform.hpp"

namespace nostalgia
{

class CCamera
{
public:
    NOSTALGIA_API CCamera(const CTransform& initialTransform, float fov, float aspectRatio, float nearClip, float farClip);

    NOSTALGIA_API inline const glm::mat4& getViewMatrix() const
    {
        return m_viewMatrix;
    }

    NOSTALGIA_API inline const glm::mat4& getProjectionMatrix() const
    {
        return m_projectionMatrix;
    }

    NOSTALGIA_API inline CTransform& retrieveTransform()
    {
        return m_transform;
    }

    NOSTALGIA_API inline void updateViewMatrix()
    {
        m_viewMatrix = glm::lookAt(m_transform.getPosition(), m_transform.getPosition() + m_transform.getForwardDirection(),
                                   m_transform.getUpDirection());
    }

private:
    void updateProjectionMatrix()
    {
        m_projectionMatrix = glm::perspective(glm::radians(m_fov), m_aspectRatio, m_nearClip, m_farClip);
    }

    CTransform m_transform = {};

    float m_fov;
    float m_aspectRatio;
    float m_nearClip;
    float m_farClip;

    glm::mat4 m_viewMatrix = glm::mat4(1.0f);
    glm::mat4 m_projectionMatrix = glm::mat4(1.0f);
};

}