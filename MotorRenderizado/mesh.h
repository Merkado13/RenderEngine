#ifndef MESH_H
#define MESH_H

#include <glad/glad.h> // holds all OpenGL type declarations

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"
#include "texture.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

struct Vertex {

	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	glm::vec3 Tangent;
	glm::vec3 Bitangent;

	Vertex(glm::vec3 position, glm::vec2 textCoords) : Position(position), TexCoords(textCoords){}
	Vertex(glm::vec3 Position, glm::vec3 Normal, glm::vec2 TexCoords, glm::vec3 Tangent, glm::vec3 Bitangent)
		: Position(Position), Normal(Normal), TexCoords(TexCoords), Tangent(Tangent), Bitangent(Bitangent){}
};


class Mesh {
public:
	/*  Functions  */
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	static Mesh createCube();
	static Mesh createPlane();
	// render the mesh
	void Draw(Shader shader);

private:
	
	/*  Mesh Data  */
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	/*  Render data  */
	unsigned int VAO;
	GLuint VBO, EBO;

	/*  Functions    */
	void setupMesh();
};
#endif
