#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Nostalgia/Nostalgia.hpp"

namespace nostalgia
{

void NostalgiaEngine::test()
{
    GLFWwindow* pWindow;

    if (!glfwInit())
    {
        std::cerr << "glfwInit(): error\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "glfwInit(): ok";

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    pWindow = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!pWindow)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(pWindow);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (!glfwWindowShouldClose(pWindow))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    glfwTerminate();
}

}