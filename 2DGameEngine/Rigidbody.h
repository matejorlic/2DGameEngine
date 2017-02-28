#pragma once
#include "Component.h"
class Rigidbody : public Component {
private:
	float mass;

public:
	Rigidbody(GameObject& parentGO);
	~Rigidbody();
	void SetMass(float m);
};

