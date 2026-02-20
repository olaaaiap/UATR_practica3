#define GLAD_BIN

#include "mapi/common.h"
#include "FactoryEngine.h"
#include "GL1Render.h"
#include "System.h"
#include "TrianguloRot.h"
#include "CameraKeyboard.h"

int main(int argc, char** argv)
{
	FactoryEngine::SetGraphicsBackend(FactoryEngine::GBackend::GL4);

	//Inicializar el backend dela clase FactoryEngine
	IRender* render = FactoryEngine::getNewRender();
	InputManager* inputManager = FactoryEngine::getNewInputManager();

	System* system = new System();
	system->initSystem();

	TrianguloRot* triangulo = new TrianguloRot(); //Inicializar triangulo
	System::addObject(triangulo); //Añadir triangulo al sistema

	World* world = new World();
	world->addObject(triangulo); //Añadir triangulo al mundo

	CameraKeyboard* cam = new CameraKeyboard(projectionType_e::perspectiva, glm::vec3( 0.0f, 0.0f, -3.0f), glm::vec3( 0.0f, 1.0f, 0.0f ), glm::vec3(0.0f, 0.0f, 0.0f));
	world->addCamera(cam);
	world->setActiveCamera(0);


	System::SetWorld(world);
	system->mainLoop();

	return 0;

}