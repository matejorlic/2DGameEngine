#pragma once
#include "Component.h"
#include <Box2D\Box2D.h>

class Transform : public Component {
private:
	b2Body* body;
public:
	Transform(GameObject& parentGO);
	~Transform();

	b2Vec2 GetPosition();
	float GetRotation();
};

