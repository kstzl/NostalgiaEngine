#pragma once

#include <string>

#include "Nostalgia/Core/core.hpp"

struct GLFWwindow;

namespace nostalgia
{

class Application
{
public:
    NOSTALGIA_API explicit Application(int windowWidth, int windowHeight, const std::string& windowTitle)
        : m_windowWidth(windowWidth)
        , m_windowHeight(windowHeight)
        , m_windowTitle(windowTitle)
    {
    }

    NOSTALGIA_API virtual void init() = 0;
    NOSTALGIA_API virtual void render() = 0;
    NOSTALGIA_API virtual ~Application() = default;

    NOSTALGIA_API void initialize();
    NOSTALGIA_API void mainLoop();

private:
    void tryInitializeGLFW();

    int m_windowWidth;
    int m_windowHeight;

    std::string m_windowTitle;

    GLFWwindow* m_pWindow = nullptr;
};

}