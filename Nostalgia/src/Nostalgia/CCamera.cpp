#include "Nostalgia/CCamera.hpp"

namespace nostalgia
{

CCamera::CCamera(const CTransform& initialTransform, float fov, float aspectRatio, float nearClip, float farClip)
    : m_transform(initialTransform)
    , m_fov(fov)
    , m_aspectRatio(aspectRatio)
    , m_nearClip(nearClip)
    , m_farClip(farClip)
{
    updateProjectionMatrix();
    updateViewMatrix();
}

}