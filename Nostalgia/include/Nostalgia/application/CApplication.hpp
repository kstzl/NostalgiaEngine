#pragma once

#include <string>

#include "Nostalgia/core/core.hpp"

struct GLFWwindow;

namespace nostalgia
{

class CApplication
{
public:
    NOSTALGIA_API explicit CApplication(int windowWidth, int windowHeight, const std::string& windowTitle)
        : m_windowWidth(windowWidth)
        , m_windowHeight(windowHeight)
        , m_windowTitle(windowTitle)
    {
    }

    NOSTALGIA_API virtual void init() = 0;
    NOSTALGIA_API virtual void render() = 0;
    NOSTALGIA_API virtual ~CApplication() = default;

    NOSTALGIA_API void initialize();
    NOSTALGIA_API void mainLoop();

    NOSTALGIA_API inline float getAspectRatio() const
    {
        return static_cast<float>(m_windowWidth) / static_cast<float>(m_windowHeight);
    }

private:
    void tryInitializeGLFW();

    int m_windowWidth;
    int m_windowHeight;

    std::string m_windowTitle;

    GLFWwindow* m_pWindow = nullptr;
};

}