#include <iostream>
#include <filesystem>
#include <memory>

#include <Nostalgia/application/CApplication.hpp>
#include <Nostalgia/shader/CShaderProgram.hpp>
#include <Nostalgia/CVertexBufferObject.hpp>
#include <Nostalgia/CVertexArrayObject.hpp>
#include <Nostalgia/CVertex.hpp>
#include <Nostalgia/mesh/CMesh.hpp>
#include <Nostalgia/CCamera.hpp>
#include <Nostalgia/CTransform.hpp>

class CSandboxApp : public nostalgia::CApplication
{
public:
    CSandboxApp()
        : nostalgia::CApplication(800, 600, "Nostalgia Sandbox App")
    {
    }

    void init() override
    {
        m_camera =
            std::make_unique<nostalgia::CCamera>(nostalgia::CTransform(glm::vec3(0, 0, 5)), 45.f, getAspectRatio(), 0.1f, 100.f);

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

    void update(float dt) override
    {
        nostalgia::CTransform& cameraTransform = m_camera->retrieveTransform();

        cameraTransform.setPitch(cameraTransform.getPitch() - getMouseDeltaY() * dt * m_camSpeed);
        cameraTransform.setYaw(cameraTransform.getYaw() - getMouseDeltaX() * dt * m_camSpeed);

        if (isKeyPressed(GLFW_KEY_Z))
            cameraTransform.setPosition(cameraTransform.getPosition() + cameraTransform.getForwardDirection() * dt * m_moveSpeed);

        if (isKeyPressed(GLFW_KEY_S))
            cameraTransform.setPosition(cameraTransform.getPosition() - cameraTransform.getForwardDirection() * dt * m_moveSpeed);

        if (isKeyPressed(GLFW_KEY_Q))
            cameraTransform.setPosition(cameraTransform.getPosition() - cameraTransform.getRightDirection() * dt * m_moveSpeed);

        if (isKeyPressed(GLFW_KEY_D))
            cameraTransform.setPosition(cameraTransform.getPosition() + cameraTransform.getRightDirection() * dt * m_moveSpeed);

        m_camera->updateViewMatrix();
    }

    void render() override
    {
        assert(m_mesh);
        assert(m_camera);

        m_triangleTransform.setRotation(glm::vec3(0, m_rot, 0));
        m_shader->setMVP(m_camera->getViewMatrix(), m_camera->getProjectionMatrix(), m_triangleTransform.getModelMatrix());
        m_mesh->render();

        m_rot += 0.01f;
    }

    void onKeyInput(const nostalgia::SKeyCallback& data) const override
    {
        // Nothing to do
    }

private:
    std::unique_ptr<nostalgia::CCamera> m_camera;
    std::unique_ptr<nostalgia::CShaderProgram> m_shader;
    std::unique_ptr<nostalgia::CMesh> m_mesh;

    nostalgia::CTransform m_triangleTransform = {};
    float m_rot = 0;

    float m_moveSpeed = 10;
    float m_camSpeed = 10;
};

int main()
{
    CSandboxApp app;

    app.initialize();
    app.mainLoop();
}