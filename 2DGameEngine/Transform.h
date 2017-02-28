#pragma once
#include "Component.h"
#include <Box2D\Box2D.h>

class Transform : public Component {
	friend class BoxCollider;
	friend class SphereCollider;
	friend class Rigidbody;

private:
	b2Body* body;
public:
	Transform(GameObject& parentGO);
	~Transform();

	b2Vec2 GetPosition();
	float GetRotation();

	Transform& SetPosition(float x, float y);
	Transform& SetRotation(float angle);
};

