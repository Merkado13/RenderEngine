#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H
#include "sceneGraph.h"

class RenderSystem
{
public:
	RenderSystem();
	~RenderSystem();

	void draw(SceneGraph& scene);

protected:
private:
	void init();
};

#endif 

