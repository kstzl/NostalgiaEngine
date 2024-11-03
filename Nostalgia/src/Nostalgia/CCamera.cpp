#include "Nostalgia/CCamera.hpp"

namespace nostalgia
{

CCamera::CCamera(const glm::vec3& position, float fov, float aspectRatio, float nearClip, float farClip)
    : m_position(position)
    , m_fov(fov)
    , m_aspectRatio(aspectRatio)
    , m_nearClip(nearClip)
    , m_farClip(farClip)
{
    updateProjectionMatrix();
    updateViewMatrix();
}

}