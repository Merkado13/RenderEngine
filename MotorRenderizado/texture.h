#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>
#include <string>

class Texture
{
public:
	Texture(const std::string& fileName, const std::string& nameType, const std::string& path);
	~Texture();

	void Bind(unsigned int unit);
	inline std::string GetPath() { return path; }
	inline std::string GetNameType() { return nameType; }
protected:
private:
	GLuint texture;
	std::string nameType;
	std::string path;
};


#endif // !TEXTURE_H