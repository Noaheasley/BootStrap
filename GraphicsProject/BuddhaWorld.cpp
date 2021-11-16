#include "BuddhaWorld.h"
#include "gl_core_4_4.h"
#include "glm/ext.hpp"

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
		{ 1.0f, -1.0f, 1.0f },
		{ 0.5f, 0.5f, 0.5f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	);
	add(m_light);

	//Flashlight
	m_flashlight = new Flashlight(
		m_camera->getTransform()->getPosition(),
		m_camera->getTransform()->getForward(),
		{ 0.5f, 0.5f, 0.5f, 1.0f },
		{ 0.8f, 0.8f, 0.8f, 1.0f },
		{ 1.0f, 0.0f, 1.0f, 1.0f },
		12.5f,
		17.5f
	);
	add(m_flashlight);
	//Cube
	m_cube = new Cube();
	m_cube->setColor(glm::vec4(0.3f, 0.6f, 1.0f, 1.0f));
	m_cube->getTransform()->scale(glm::vec3(0.1f));
	if (!m_raccoon.load("Raccoon.jpg")) {
		printf("Failed to load texture.\n");
	}
	add(m_cube);

	//Buddha
	m_buddha = new OBJMesh();
	m_buddha->load("Buddha.obj");
	m_buddha->getTransform()->setPosition({ 0.0f, -1.0f, 0.0f });
	m_buddha->getTransform()->setScale(glm::vec3(0.1f));
	add(m_buddha);
}

void BuddhaWorld::onUpdate(float deltaTime)
{
	m_flashlight->setPosition(m_camera->getTransform()->getPosition());
	m_flashlight->getTransform()->setForward(m_camera->getTransform()->getForward());
}

void BuddhaWorld::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == -1)
		printf("No shader bound.\n");

	int diffuseTextureUniform = glGetUniformLocation(program, "diffuseTexture");
	if (diffuseTextureUniform >= 0)
		glUniform1i(diffuseTextureUniform, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_raccoon.getHandle());

	m_cube->draw();
}

void BuddhaWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_flashlight);
	destroy(m_buddha);
	destroy(m_cube);
}
