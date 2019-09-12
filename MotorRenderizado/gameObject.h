#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "transform.h"
#include "sceneNode.h"

class GameObject : SceneNode{
public:
	GameObject() {
	
		model = Transform();

	}
protected:
private:

	Transform model;

};

#endif