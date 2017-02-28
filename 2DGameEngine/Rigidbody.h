#pragma once
#include "Component.h"

// Rigidbody component respond to forces using game object's mass.
// Use Collider class to set up colliders.

class Rigidbody : public Component {
private:
	float mass;

public:
	Rigidbody(GameObject& parentGO);
	~Rigidbody();
	void SetMass(float m);
};

