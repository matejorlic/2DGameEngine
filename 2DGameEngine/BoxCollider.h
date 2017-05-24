#pragma once
#include "Collider.h"

// Rectangle shaped collider

class BoxCollider : public Collider {
public:
	BoxCollider(GameObject& parentGO);
	~BoxCollider();
	void SetSize(int x, int y);

	// Lua binding.
	static void AddUserType(sol::state& lua);
};

