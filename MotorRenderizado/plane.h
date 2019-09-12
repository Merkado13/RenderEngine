#ifndef PLANE_H
#define PLANE_H

#include <glm/glm.hpp>
#include "mesh.h"
#include "texture.h"

class Plane {

public:
	Plane() {}
	const Mesh getPlane() {
		return Mesh(vector<Vertex>(std::begin(VERTICES), std::end(VERTICES)),
			vector<unsigned int>(std::begin(INDICES), std::end(INDICES)),
			vector<Texture>(std::begin(TEXTURES), std::end(TEXTURES)));
	}
protected:
private:

	static const unsigned int N_VERTICES = 4;
	static const unsigned int N_TEXTURES = 2;
	static const unsigned int N_INDICES = 6;

	const Vertex VERTICES[N_VERTICES] = {

		Vertex(glm::vec3(-0.5f,0.5f,0.0f),glm::vec2(0.0f,0.0f)),
		Vertex(glm::vec3(-0.5f,-0.5f,0.0f),glm::vec2(0.0f,1.0f)),
		Vertex(glm::vec3(0.5f,-0.5f,0.0f),glm::vec2(1.0f,1.0f)),
		Vertex(glm::vec3(0.5f,0.5f,0.0f),glm::vec2(1.0f,0.0f)),
	};

	const unsigned int INDICES[N_INDICES] = {

				0,1,2,		0,2,3,
	};

	const Texture TEXTURES[N_TEXTURES] = {
			Texture("./res/tex/terracota/terra_diffuse.jpg","texture_diffuse","terra_diffuse"),
			Texture("./res/tex/terracota/terra_normal.jpg","texture_normal","terra_normal"),
	};

};

#endif // !PLANE_H
