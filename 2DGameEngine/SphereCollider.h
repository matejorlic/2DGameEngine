#pragma once
#include "Collider.h"

// Circle shaped collider

class SphereCollider : public Collider {
public:
	SphereCollider(GameObject& parentGO);
	~SphereCollider();
	void SetSize(int x);

	// Lua binding.
	static void AddUserType(sol::state& lua);
};

