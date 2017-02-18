#pragma once
#include "Collider.h"

class BoxCollider : public Collider {
public:
	BoxCollider(GameObject& parentGO);
	~BoxCollider();
	void SetSize(int x, int y);
};

