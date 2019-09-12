#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h> 

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"

#include <string>


class Model
{
public:

	Model(const std::string& path, bool gamma);
	Model(const Mesh mesh);
	void Draw(Shader shader);

	inline Transform& getTransform() { return transform; }
	inline void setModel(const Transform& transform) { this->transform = transform; }

private:

	Transform transform;

	std::vector<Texture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;
	bool gammaCorrection;

	void loadModel(const string& path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};

#endif
