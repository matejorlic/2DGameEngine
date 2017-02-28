#pragma once
#include "Component.h"

class Collider : public Component {
protected:
	b2Fixture* fixture;
public:
	Collider(GameObject& parentGO);
	virtual ~Collider();
};