#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "camera.h"
#include "model.h"
#include "display.h"
#include <GLFW/glfw3.h>
#include <iostream>


#define SCR_WIDTH 800
#define SCR_HEIGHT 600

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(Display* display);

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;
float deltaRotation = 0.0f;

int main(int argc, char** argvs)
{
	
	Display display(SCR_WIDTH,SCR_HEIGHT, "Render Engine! :D");
	GLFWwindow *window = display.getWindow();

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	
	// build and compile shaders
	// -------------------------
	Shader ourShader("shaderBasic");

	//Model ourModel("./res/Ness/Ness.obj", false);

	Mesh cubeMesh = Mesh::createCube();
	Model cube(cubeMesh);
	
	Mesh planeMesh = Mesh::createPlane();
	Model plane(planeMesh);
	

	// draw in wireframe
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// render loop
	// -----------
	while (!display.IsClosed())
	{
		// per-frame time logic
		// --------------------
		float currentFrame = (float) glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		processInput(&display);

		display.Clear(0.0f, 0.13f, 0.33f, 1.0f);

		ourShader.use();

		// view/projection transformations
		glm::mat4 projectionView = camera.GetProjectionViewMatrix();

		// render the loaded model
		deltaRotation += deltaTime;
		if (deltaRotation > 360.0f)
			deltaRotation = 0.0f;

		//scene
		cube.getTransform().SetPos(glm::vec3(-0.75f,0.0f,0.0f));
		cube.getTransform().SetRot(glm::vec3(45.0f, deltaRotation , 45.0f));
		//renderer
		ourShader.setMat4("mvp", projectionView * cube.getTransform().GetModel());
		cube.Draw(ourShader);		

		plane.getTransform().SetPos(glm::vec3(0.75f, 0.0f, 0.0f));
		ourShader.setMat4("mvp", projectionView * plane.getTransform().GetModel());
		plane.Draw(ourShader);

		display.Update();
		glfwPollEvents();
	}

	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(Display* display)
{
	GLFWwindow *window = display->getWindow();

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		//display->Close();
		
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = (float) xpos;
		lastY = (float) ypos;
		firstMouse = false;
	}

	float xoffset = (float)xpos - lastX;
	float yoffset = lastY - (float)ypos; // reversed since y-coordinates go from bottom to top

	lastX = (float)xpos;
	lastY = (float)ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll((float) yoffset);
}