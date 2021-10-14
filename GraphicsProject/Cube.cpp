#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* vertices = nullptr;
	vertexCount = 36;
	triCount = 12;

	//Define vertices for a quad
	vertices = new Vertex[vertexCount];

	////Top Face
	//triangle 0
	vertices[0].position = { 1.0f, 1.0f,  1.0f, 1.0f };
	vertices[1].position = { -1.0f, 1.0f,  1.0f, 1.0f };
	vertices[2].position = { -1.0f, 1.0f,  -1.0f, 1.0f };
	//triangle 1
	vertices[3].position = { 1.0f, 1.0f,  1.0f, 1.0f };
	vertices[4].position = { 1.0f, 1.0f, -1.0f, 1.0f };
	vertices[5].position = { -1.0f, 1.0f, -1.0f, 1.0f };

	////Bottom Face
	//triangle 0
	vertices[6].position = { -0.5f, 0.0f, 0.5f, 1.0f };
	vertices[7].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	vertices[8].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	//triangle 1
	vertices[9].position = { 0.5f, 0.0f, 0.5f, 1.0f };
	vertices[10].position = { -0.5f, 0.0f, -0.5f, 1.0f };
	vertices[11].position = { 0.5f, 0.0f, -0.5f, 1.0f };

	////Right Face
	//triangle 0
	vertices[12].position = { -1.0f, 1.0f, 1.0f, 1.0f };
	vertices[13].position = { -1.0f, -1.0f,  -1.0f, 1.0f };
	vertices[14].position = { -1.0f, 1.0f,  -1.0f, 1.0f };
	//triangle 1
	vertices[15].position = { -1.0f, -1.0f, 1.0f, 1.0f };
	vertices[16].position = { -1.0f, -1.0f,  -1.0f, 1.0f };
	vertices[17].position = { -1.0f, 1.0f,  1.0f, 1.0f };

	////Left Face
	//triangle 0
	vertices[18].position = { 1.0f, -1.0f, -1.0f, 1.0f };
	vertices[19].position = { 1.0f, 1.0f,  1.0f, 1.0f };
	vertices[20].position = { 1.0f, 1.0f,  -1.0f, 1.0f };
	//triangle 1
	vertices[21].position = { 1.0f, -1.0f,  1.0f, 1.0f }; 
	vertices[22].position = { 1.0f, -1.0f,  -1.0f, 1.0f }; 
	vertices[23].position = { 1.0f, 1.0f,  1.0f, 1.0f }; 

	////Back Face
	//triangle 0
	vertices[24].position = { -1.0f, -1.0f, -1.0f, 1.0f };
	vertices[25].position = { 1.0f, -1.0f,  -1.0f, 1.0f };
	vertices[26].position = { 1.0f, 1.0f,  -1.0f, 1.0f };
	//triangle 1
	vertices[27].position = { -1.0f, -1.0f,  -1.0f, 1.0f };
	vertices[28].position = { -1.0f, 1.0f,  -1.0f, 1.0f };
	vertices[29].position = { 1.0f, 1.0f,  -1.0f, 1.0f };

	////Front Face
	//triangle 0
	vertices[30].position = { -1.0f, -1.0f,  1.0f, 1.0f }; 
	vertices[31].position = { 1.0f, -1.0f,  1.0f, 1.0f }; 
	vertices[32].position = { 1.0f, 1.0f,  1.0f, 1.0f }; 
	//triangle 1
	vertices[33].position = { -1.0f, -1.0f,  1.0f, 1.0f}; 
	vertices[34].position = { -1.0f, 1.0f,  1.0f, 1.0f }; 
	vertices[35].position = { 1.0f, 1.0f,  1.0f, 1.0f }; 



	for (int i = 0; i < vertexCount; i++) {
		vertices[i].color = m_color;
	}

	return vertices;
}
	void Cube::setVertexPosition(Vertex* vertices, int vertexCount, int index, glm::vec3 position) {
		for (int i = index; i < vertexCount; i += 8) {
			vertices[i].position = glm::vec4(position * 0.5f, 1.0f);
			vertices[i].normal = glm::vec4(position, 0.0f);
			vertices[i].color = m_color;
		}
	}