#ifndef DISPLAY_H
#define DISPLAY_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Display
{
public:
	Display(int width, int height, const std::string& tittle);
	~Display();

	void Clear(float r, float g, float b, float a);
	void Update();

	bool IsClosed();
	void Close();
	inline GLFWwindow* getWindow(){ return window; }

protected:
private:
	GLFWwindow *window;
	bool isClosed;
};

#endif // !DISPLAY_H
