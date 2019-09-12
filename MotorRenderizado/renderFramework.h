#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "mesh.h"
#include "model.h"

class RenderFramework
{
public:
	RenderFramework();
	~RenderFramework();

protected:
private:

	void createShader();
	void useShader();

	void drawMesh(Mesh& mesh);
	void drawModel(Model& model);

	void createWindow();

};

#endif 

