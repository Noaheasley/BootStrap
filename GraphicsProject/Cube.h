#pragma once
#include "Mesh.h"

class Cube : public Mesh
{
public:
	Cube() : Mesh() {}
	~Cube() {}
	Vertex* generateVertices(unsigned int& vertexCount, unsigned int& triCount) override;
	void setVertexPosition(Vertex* vertices, int vertexCount, int index, glm::vec3 position);

	glm::vec4 getColor() { return m_color; }
	void setColor(glm::vec4 color) { m_color = color; }

private:
	glm::vec4 m_color = glm::vec4(1.0f);
};

