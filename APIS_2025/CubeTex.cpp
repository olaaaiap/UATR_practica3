#include "CubeTex.h"
#include "GLTexture.h"
#include "GLSLMaterial.h"
#include "GLFWInputManager.h"

CubeTex::CubeTex()
{

	Mesh3D* meshLados = new Mesh3D();

	std::vector<vertex_t> vertLados =
	{
	  {{ 0.5f, 0.5f,0.0f,1.0f},{1,1}},//0
	  {{-0.5f, 0.5f,0.0f,1.0f},{0,1}},//1
	  {{-0.5f,-0.5f,0.0f,1.0f},{0,0}},//2
	  {{ 0.5f,-0.5f,0.0f,1.0f},{1,0}}, //3

	  {{ -0.5f,-0.5f,-0.5f,1.0f },{0,0} }, //4
	  {{ 0.5f,-0.5f,-0.5f,1.0f},{1,0}}, //5
	  {{ 0.5f, 0.5f,-0.5f,1.0f},{1,1}}, //6
	  {{-0.5f, 0.5f,-0.5f,1.0f},{0,1}}, //7
	}; //posiciones de vertices

	for (auto v : vertLados)
	{
		meshLados->addVertex(v);
	}

	auto idxLados = meshLados->getTriangleList(); //puntero a la lista de indices de triangulos de esta malla
	*idxLados = {
		0,1,2, 0,2,3,
		4,5,6, 4,6,7,
		1,7,6, 1,6,2,
		0,3,5, 0,5,4,
		1,0,4, 1,4,7,
		3,2,6, 3,6,5
	};


	// Material y textura para caras verticales
	GLSLMaterial* matLados = new GLSLMaterial();
	matLados->loadPrograms({ "data/shader.vert", "data/shader.frag" });
	GLTexture* texFront = new GLTexture("data/front.png");
	matLados->setColorText(texFront);
	glm::vec4 zeroColor(0.0f, 0.0f, 0.0f, 0.0f);
	matLados->setColorRGBA(zeroColor);
	meshLados->setMaterial(matLados);

	this->addMesh(meshLados);



	Mesh3D* meshTapas = new Mesh3D();

	std::vector<vertex_t> vertTapas =
	{
	  {{0.5f,0.5f,0.5f, 1.0f}, {1.0f, 1.0f}}, // 0
	  {{-0.5f,0.5f,0.5f, 1.0f}, {0.0f, 1.0f}}, // 1
	  {{-0.5f,-0.5f,0.5f, 1.0f}, {0.0f, 0.0f}}, // 2
	  {{0.5f, -0.5f,0.5f, 1.0f}, {1.0f, 0.0f}}, // 3
	  {{0.5f,0.5f, -0.5f, 1.0f}, {1.0f, 1.0f}}, // 4
	  {{-0.5f, 0.5f, -0.5f, 1.0f}, {0.0f, 1.0f}}, // 5
	  {{-0.5f, -0.5f, -0.5f, 1.0f}, {0.0f, 0.0f}}, // 6
	  {{0.5f, -0.5f, -0.5f, 1.0f}, {1.0f, 0.0f}}, // 7
	}; //posiciones de vertices

	for (auto v : vertTapas)
	{
		meshTapas->addVertex(v);
	}

	auto idxTapas = meshTapas->getTriangleList(); //puntero a la lista de indices de triangulos de esta malla
	*idxTapas = {
		4,5,1, 4,1,0,
		3,2,6, 3,6,7
	};


	// Material y textura para caras verticales
	GLSLMaterial* matTapas = new GLSLMaterial();
	matTapas->loadPrograms({ "data/shader.vert", "data/shader.frag" });
	GLTexture* texTop = new GLTexture("data/top.png");
	matTapas->setColorText(texTop);
	matTapas->setColorRGBA(zeroColor);
	meshTapas->setMaterial(matTapas);

	this->addMesh(meshTapas);

	// Transformaciones iniciales
	this->setPosicion({ 0.0f, 0.0f, 0.0f, 1.0f });
	this->setRotacion({ 0.0f, 0.0f, 0.0f, 1.0f });
	this->setEscala({ 1.0f, 1.0f, 1.0f, 1.0f });


}


void CubeTex::step(double deltaTime)
{
	float velRot = 90.0f; // grados por segundo

	// Obtener rotación actual
	glm::vec4 rot = this->GetRotacion();

	rot.y += static_cast<float>(velRot * deltaTime);


	// Aplicar nueva rotación
	this->setRotacion(rot);

	// Salida del programa al pulsar E
	if (GLFWInputManager::keyboardState[GLFW_KEY_E])
		std::exit(0);
}