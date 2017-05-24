#pragma once
#include "Component.h"
#include <Box2D\Box2D.h>

// Transform is always added to a game object.
// This component take care of position, rotation and scale of the game object.
// Also save hierarchy data - parent transform and children transforms.

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

	// Lua binding.
	static void AddUserType(sol::state& lua);
};