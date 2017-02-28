#pragma once
#include "Component.h"

// Collider is a base class for special collider types: Box, Sphere, Polygon
// Collider do not respond to forces and collisions. To have dynamic object use Rigidbody component.

class Collider : public Component {
	friend class Rigidbody;

protected:
	b2Fixture* fixture;
public:
	Collider(GameObject& parentGO);
	virtual ~Collider();
};