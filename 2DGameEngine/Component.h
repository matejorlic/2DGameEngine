#pragma once
#include "GameObject.h"

class Component {
private:
	GameObject& parent;
public:
	Component(GameObject& p);
	~Component();
};
