#ifndef CUBE_H
#define CUBE_H

#include"mesh.h"
#include <glm/glm.hpp>
#include "texture.h"

class Cube {

public:
	
	Cube() {}

	const Mesh getCube() {
		return Mesh(vector<Vertex>(std::begin(VERTICES), std::end(VERTICES)), 
					vector<unsigned int>(std::begin(INDICES), std::end(INDICES)),
					vector<Texture>(std::begin(TEXTURES),std::end(TEXTURES)));
	}

protected:
private:
	
	static const unsigned int N_VERTICES = 24;
	static const unsigned int N_TEXTURES = 2;
	static const unsigned int N_INDICES = 36;

	const Vertex VERTICES[N_VERTICES] = {

		Vertex(glm::vec3(-0.5f,0.5f,0.5f),glm::vec2(0.0f,0.0f)),
		Vertex(glm::vec3(-0.5f,-0.5f,0.5f),glm::vec2(0.0f,1.0f)),
		Vertex(glm::vec3(0.5f,-0.5f,0.5f),glm::vec2(1.0f,1.0f)),
		Vertex(glm::vec3(0.5f,0.5f,0.5f),glm::vec2(1.0f,0.0f)),

		Vertex(glm::vec3(0.5f,0.5f,0.5f),glm::vec2(0.0f,0.0f)),
		Vertex(glm::vec3(0.5f,-0.5f,0.5f),glm::vec2(0.0f,1.0f)),
		Vertex(glm::vec3(0.5f,-0.5f,-0.5f),glm::vec2(1.0f,1.0f)),
		Vertex(glm::vec3(0.5f,0.5f,-0.5f),glm::vec2(1.0f,0.0f)),

		Vertex(glm::vec3(0.5f,0.5f,-0.5f),glm::vec2(0.0f,0.0f)),
		Vertex(glm::vec3(0.5f,-0.5f,-0.5f),glm::vec2(0.0f,1.0f)),
		Vertex(glm::vec3(-0.5f,-0.5f,-0.5f),glm::vec2(1.0f,1.0f)),
		Vertex(glm::vec3(-0.5f,0.5f,-0.5f),glm::vec2(1.0f,0.0f)),

		Vertex(glm::vec3(-0.5f,0.5f,-0.5f),glm::vec2(0.0f,0.0f)),
		Vertex(glm::vec3(-0.5f,-0.5f,-0.5f),glm::vec2(0.0f,1.0f)),
		Vertex(glm::vec3(-0.5f,-0.5f,0.5f),glm::vec2(1.0f,1.0f)),
		Vertex(glm::vec3(-0.5f,0.5f,0.5f),glm::vec2(1.0f,0.0f)),

		Vertex(glm::vec3(-0.5f,0.5f,-0.5f),glm::vec2(0.0f,0.0f)),
		Vertex(glm::vec3(-0.5f,0.5f,0.5f),glm::vec2(0.0f,1.0f)),
		Vertex(glm::vec3(0.5f,0.5f,0.5f),glm::vec2(1.0f,1.0f)),
		Vertex(glm::vec3(0.5f,0.5f,-0.5f),glm::vec2(1.0f,0.0f)),

		Vertex(glm::vec3(-0.5f,-0.5f,0.5f),glm::vec2(0.0f,0.0f)),
		Vertex(glm::vec3(-0.5f,-0.5f,-0.5f),glm::vec2(0.0f,1.0f)),
		Vertex(glm::vec3(0.5f,-0.5f,-0.5f),glm::vec2(1.0f,1.0f)),
		Vertex(glm::vec3(0.5f,-0.5f,0.5f),glm::vec2(1.0f,0.0f)),

	};

	const unsigned int INDICES[N_INDICES] = {

				0,1,2,		0,2,3,
				4,5,6,		4,6,7,
				8,9,10,		8,10,11,
				12,13,14,	12,14,15,
				16,17,18,	16,18,19,
				20,21,22,	20,22,23
	};

	const Texture TEXTURES[N_TEXTURES] = {
			Texture("./res/tex/terracota/terra_diffuse.jpg","texture_diffuse","terra_diffuse"),
			Texture("./res/tex/terracota/terra_normal.jpg","texture_normal","terra_normal"),
	};
};

#endif
