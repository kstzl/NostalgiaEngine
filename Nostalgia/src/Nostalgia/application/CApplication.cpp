#include <iostream>
#include <sstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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
    catch (const exceptions::EngineException& e)
    {
        glfwTerminate();

        std::stringstream errorMessage;
        errorMessage << "Fatal Engine Error : ";
        errorMessage << e.what();

        throw exceptions::EngineException(errorMessage.str());
    }
}

void CApplication::tryInitializeGLFW()
{
    if (!glfwInit())
        throw exceptions::EngineException("GLFW initialization failed!");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_pWindow = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle.c_str(), nullptr, nullptr);

    if (!m_pWindow)
    {
        glfwTerminate();
        throw exceptions::EngineException("GLFW Window creation failed!");
    }

    glfwMakeContextCurrent(m_pWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw exceptions::EngineException("GLAD initialization failed!");
}

void CApplication::mainLoop()
{
    NOSTALGIA_ASSERT(m_pWindow);

    init();

    while (!glfwWindowShouldClose(m_pWindow))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        render();

        glfwSwapBuffers(m_pWindow);
        glfwPollEvents();
    }

    glfwTerminate();
}

}