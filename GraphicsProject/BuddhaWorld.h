#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Light.h"
#include "Flashlight.h"
#include "OBJMesh.h"
#include "Cube.h"
#include "Quad.h"

class BuddhaWorld :	public World
{
public:
	void onStart() override;
	void onUpdate(float deltaTime) override;
	void onDraw() override;
	void onEnd() override;

private:
	PlayerCamera* m_camera = nullptr;
	Light* m_light = nullptr;
	Flashlight* m_flashlight = nullptr;
	OBJMesh* m_buddha = nullptr;
	Cube* m_cube = nullptr;
	Quad* m_quad = nullptr;
	aie::Texture m_earth;
};

