#include <iostream>
#include <filesystem>
#include <memory>

#include <Nostalgia/Application/Application.hpp>
#include <Nostalgia/Shader/ShaderProgram.hpp>
#include <Nostalgia/VertexBufferObject.hpp>
#include <Nostalgia/VertexArrayObject.hpp>

class SandboxApp : public nostalgia::Application
{
public:
    SandboxApp()
        : nostalgia::Application(800, 600, "Nostalgia Sandbox App")
    {
    }

    void init() override
    {
        const float triangleVertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

        m_triangleVao = std::make_unique<nostalgia::VertexArrayObject>();
        m_triangleVao->bind();

        m_triangleVbo = std::make_unique<nostalgia::VertexBufferObject>(triangleVertices, sizeof(triangleVertices));
        m_triangleVbo->bind();
        m_triangleVao->bindAttribute(0, 3, GL_FLOAT, 3 * sizeof(float), nullptr);
    }

    void render() override
    {
        assert(m_triangleVbo);
        assert(m_triangleVao);
    }

private:
    std::unique_ptr<nostalgia::VertexBufferObject> m_triangleVbo;
    std::unique_ptr<nostalgia::VertexArrayObject> m_triangleVao;
};

int main()
{
    SandboxApp app;

    app.initialize();

    nostalgia::ShaderProgram shaderProgram("assets/frag.glsl", "assets/vert.glsl");
    shaderProgram.use();

    app.mainLoop();
}