#include <iostream>
#include <filesystem>
#include <memory>

#include <Nostalgia/application/CApplication.hpp>
#include <Nostalgia/shader/CShaderProgram.hpp>
#include <Nostalgia/CVertexBufferObject.hpp>
#include <Nostalgia/CVertexArrayObject.hpp>
#include <Nostalgia/CVertex.hpp>
#include <Nostalgia/mesh/CMesh.hpp>

class CSandboxApp : public nostalgia::CApplication
{
public:
    CSandboxApp()
        : nostalgia::CApplication(800, 600, "Nostalgia Sandbox App")
    {
    }

    void init() override
    {
        m_shader = std::make_unique<nostalgia::CShaderProgram>("assets/frag.glsl", "assets/vert.glsl");
        m_shader->use();

        std::vector<nostalgia::CVertex> triangleVertices = {
            nostalgia::CVertex(glm::vec3(-0.5f, -0.5f, 0.0)),
            nostalgia::CVertex(glm::vec3(0.5f, -0.5f, 0.0f)),
            nostalgia::CVertex(glm::vec3(0.0f, 0.5f, 0.0f)),
        };

        m_mesh = std::make_unique<nostalgia::CMesh>(triangleVertices);
        m_mesh->bind();
    }

    void render() override
    {
        assert(m_mesh);

        m_mesh->render();
    }

private:
    std::unique_ptr<nostalgia::CShaderProgram> m_shader;
    std::unique_ptr<nostalgia::CMesh> m_mesh;
};

int main()
{
    CSandboxApp app;

    app.initialize();
    app.mainLoop();
}