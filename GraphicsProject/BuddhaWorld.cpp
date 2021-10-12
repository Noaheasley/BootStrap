#include "BuddhaWorld.h"

void BuddhaWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Light
	m_light = new Light(
		{ 1.0f, 1.0f, 1.0f },
		{ 1.0f, 0.5f, 0.5f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	);
	m_light->setDirection(glm::vec3{ -60, -60, -60 });
	add(m_light);

	//Cube
	m_cube = new Cube();
	m_cube->setColor(glm::vec4(0.6f, 0.2f, 1.0f, 1.0f));
	add(m_cube);

	//Dragon
	m_buddha = new OBJMesh();
	m_buddha->load("Buddha.obj");
	m_buddha->getTransform()->setPosition({ 5.0f, 0.0f, 0.0f });
	m_buddha->getTransform()->setScale(glm::vec3(0.1f));
	add(m_buddha);
}

void BuddhaWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_buddha);
	destroy(m_cube);
}