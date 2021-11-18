#include "PlayerCamera.h"
#include "GLFW/glfw3.h"

void PlayerCamera::onUpdate(float deltaTime)
{
    GLFWwindow* window = glfwGetCurrentContext();

    int keyForward = GLFW_KEY_W;
    int keyBack = GLFW_KEY_S;
    int keyLeft = GLFW_KEY_A;
    int keyRight = GLFW_KEY_D;
    int keyUp = GLFW_KEY_E;
    int keyDown = GLFW_KEY_Q;
    int sprintKey = GLFW_KEY_LEFT_SHIFT;


    //Get the direction vectors
    glm::vec3 right = getTransform()->getRight();
    glm::vec3 up = getTransform()->getUp();
    glm::vec3 forward = getTransform()->getForward();

    //Check input
    if (glfwGetKey(window, keyForward)) {
        //Move forward
        if (glfwGetKey(window, sprintKey))
        {
            getTransform()->translate(forward * m_moveSpeed * m_sprintSpeed * (float)deltaTime);
        }
        getTransform()->translate(forward * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyBack)) {
        //Move back
        if (glfwGetKey(window, sprintKey))
        {
            getTransform()->translate(-forward * m_moveSpeed * m_sprintSpeed * (float)deltaTime);
        }
        getTransform()->translate(-forward * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyLeft)) {
        //Move left
        if (glfwGetKey(window, sprintKey))
        {
            getTransform()->translate(-right * m_moveSpeed * m_sprintSpeed * (float)deltaTime);
        }
        getTransform()->translate(-right * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyRight)) {
        //Move right
        if (glfwGetKey(window, sprintKey))
        {
            getTransform()->translate(right * m_moveSpeed * m_sprintSpeed * (float)deltaTime);
        }
        getTransform()->translate(right * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyUp)) {
        //Move up
        if (glfwGetKey(window, sprintKey))
        {
            getTransform()->translate(up * m_moveSpeed * m_sprintSpeed * (float)deltaTime);
        }
        getTransform()->translate(up * m_moveSpeed * (float)deltaTime);
    }
    if (glfwGetKey(window, keyDown)) {
        //Move down
        if (glfwGetKey(window, sprintKey))
        {
            getTransform()->translate(-up * m_moveSpeed * m_sprintSpeed * (float)deltaTime);
        }
        getTransform()->translate(-up * m_moveSpeed * (float)deltaTime);
    }

    //Get current mouse coordinates
    glfwGetCursorPos(window, &m_currentMouseX, &m_currentMouseY);

    //Turn the camera based on the change in mouse position (delta mouse)
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2)) {
        float pitch = m_lookSpeed * (m_currentMouseY - m_previousMouseY);
        float yaw = m_lookSpeed * (m_currentMouseX - m_previousMouseX);
        getTransform()->rotate(-pitch, yaw, 0.0f);
    }
    //Store previous mouse coordinates
    m_previousMouseX = m_currentMouseX;
    m_previousMouseY = m_currentMouseY;
}
