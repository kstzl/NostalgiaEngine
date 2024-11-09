#include <iostream>
#include <sstream>

#include "Nostalgia/application/CApplication.hpp"
#include "Nostalgia/core/exceptions.hpp"

namespace nostalgia
{

void CApplication::initialize()
{
    try
    {
        tryInitializeGLFW();
    }
    catch (const exceptions::CEngineException& e)
    {
        glfwTerminate();

        std::stringstream errorMessage;
        errorMessage << "Fatal Engine Error : ";
        errorMessage << e.what();

        throw exceptions::CEngineException(errorMessage.str());
    }
}

void CApplication::tryInitializeGLFW()
{
    if (!glfwInit())
        throw exceptions::CEngineException("GLFW initialization failed!");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_pWindow = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle.c_str(), nullptr, nullptr);

    if (!m_pWindow)
    {
        glfwTerminate();
        throw exceptions::CEngineException("GLFW Window creation failed!");
    }

    glfwMakeContextCurrent(m_pWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw exceptions::CEngineException("GLAD initialization failed!");

    // Input modes
    glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Register callbacks
    glfwSetWindowUserPointer(m_pWindow, this);
    glfwSetInputMode(m_pWindow, GLFW_REPEAT, GLFW_TRUE);

    glfwSetKeyCallback(m_pWindow,
                       [](GLFWwindow* pWindow, int key, int scanCode, int action, int mods)
                       {
                           auto* pApplication = static_cast<const CApplication*>(glfwGetWindowUserPointer(pWindow));
                           NOSTALGIA_ASSERT(pApplication);

                           pApplication->onKeyInput(SKeyCallback{key, scanCode, action, mods});
                       });
}

void CApplication::mainLoop()
{
    NOSTALGIA_ASSERT(m_pWindow);

    init();

    double lastFrame = glfwGetTime();
    m_running = true;

    while (m_running)
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        const double currentFrame = glfwGetTime();
        const double deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        updateMouseDeltas();
        update(static_cast<float>(deltaTime));
        render();

        glfwSwapBuffers(m_pWindow);
        glfwPollEvents();

        if (glfwWindowShouldClose(m_pWindow) || glfwGetKey(m_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            m_running = false;
    }

    glfwTerminate();
}

void CApplication::updateMouseDeltas()
{
    double xPos = 0;
    double yPos = 0;

    int windowWidthCenter = m_windowHeight / 2;
    int windowHeightCenter = m_windowHeight / 2;

    glfwGetCursorPos(m_pWindow, &xPos, &yPos);
    glfwSetCursorPos(m_pWindow, windowWidthCenter, windowHeightCenter);

    m_mouseDeltaX = static_cast<float>(xPos) - static_cast<float>(windowWidthCenter);
    m_mouseDeltaY = static_cast<float>(yPos) - static_cast<float>(windowHeightCenter);
}

}