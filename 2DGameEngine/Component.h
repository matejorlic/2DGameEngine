#pragma once
#include "GameEngine.h"

class GameObject;
class Sprite;
class Collider;
class BoxCollider;
class SphereCollider;
class Transform;
class Rigidbody;
class Script;
class Camera;

// Base class for every component.

class Component {
public:
	GameObject& gameObject;

public:
	Component(GameObject& parentGO);
	virtual ~Component();

	// Methods for Lua type casting:
	Sprite* ToSprite();
	Collider* ToCollider();
	BoxCollider* ToBoxCollider();
	SphereCollider* ToSphereCollider();
	Transform* ToTransform();
	Rigidbody* ToRigidbody();
	Script* ToScript();
	Camera* ToCamera();
	//sol::state* ToLuaScript();
	//sol::as_table_t<sol::state* >* ToLuaScript();
	//lua_State* ToLuaScript();
	//sol::state_view* ToLuaScript();

	// Lua binding.
	static void AddUserType(sol::state& lua);
};
