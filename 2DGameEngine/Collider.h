#pragma once
#include "Component.h"

class Collider : public Component {
public:
	Collider(GameObject& parentGO);
	~Collider();
};

