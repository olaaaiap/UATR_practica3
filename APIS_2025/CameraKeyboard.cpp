#include "CameraKeyboard.h"
#include "GLFWInputManager.h"

void CameraKeyboard::step(float timeStep)
{
    //actualizar movimientos
    float vel = 1.0f; //unidadesGl segundo
    float velRot = 40.0f;
    if (GLFWInputManager::keyboardState[GLFW_KEY_D])
    {
        this->posicion.x += vel * timeStep;
        lookAt.x += vel * timeStep;
    }
    if (GLFWInputManager::keyboardState[GLFW_KEY_A])
    {
        this->posicion.x -= vel * timeStep;
        lookAt.x -= vel * timeStep;
    }
    if (GLFWInputManager::keyboardState[GLFW_KEY_W])
    {
        this->posicion.z += vel * timeStep;
        lookAt.z += vel * timeStep;
    }
    if (GLFWInputManager::keyboardState[GLFW_KEY_S])
    {
        this->posicion.z -= vel * timeStep;
        lookAt.z -= vel * timeStep;

    }
    //calcular matriz vista

    view = glm::lookAt(glm::vec3(posicion), glm::vec3(lookAt), glm::vec3(0, 1, 0));

}
