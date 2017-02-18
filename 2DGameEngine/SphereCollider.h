#pragma once
#include "Collider.h"

class SphereCollider : public Collider {
public:
	SphereCollider(GameObject& parentGO);
	~SphereCollider();
	void SetSize(int x);
};

