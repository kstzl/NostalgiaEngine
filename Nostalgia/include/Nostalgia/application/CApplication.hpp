#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Nostalgia/core/core.hpp"
#include "Nostalgia/application/events/SKeyCallback.hpp"

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
    NOSTALGIA_API virtual void update(float deltaTime) = 0;
    NOSTALGIA_API virtual void render() = 0;
    NOSTALGIA_API virtual ~CApplication() = default;

    NOSTALGIA_API virtual void onKeyInput(const SKeyCallback& data) const
    {
        // Nothing to do
    }

    NOSTALGIA_API void initialize();
    NOSTALGIA_API void mainLoop();

    NOSTALGIA_API inline float getAspectRatio() const
    {
        return static_cast<float>(m_windowWidth) / static_cast<float>(m_windowHeight);
    }

    NOSTALGIA_API inline bool isKeyPressed(int keyCode)
    {
        return glfwGetKey(m_pWindow, keyCode);
    }

    NOSTALGIA_API inline float getMouseDeltaX() const
    {
        return m_mouseDeltaX;
    }

    NOSTALGIA_API inline float getMouseDeltaY() const
    {
        return m_mouseDeltaY;
    }

private:
    void updateMouseDeltas();

    void tryInitializeGLFW();

    int m_windowWidth;
    int m_windowHeight;

    bool m_running = false;

    float m_mouseDeltaX = 0;
    float m_mouseDeltaY = 0;

    std::string m_windowTitle;

    GLFWwindow* m_pWindow = nullptr;
};

}