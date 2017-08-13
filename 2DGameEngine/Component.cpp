#include "stdafx.h"
#include "Component.h"

Component::Component(GameObject& parentGO) : gameObject(parentGO){
	//TODO
}

Component::~Component(){
	//TODO
}

// Methods for Lua type casting:
//TODO error handling
Sprite* Component::ToSprite() { return dynamic_cast<Sprite*>(this); }
Collider* Component::ToCollider() { return dynamic_cast<Collider*>(this); }
BoxCollider* Component::ToBoxCollider() { return dynamic_cast<BoxCollider*>(this); }
SphereCollider* Component::ToSphereCollider() { return dynamic_cast<SphereCollider*>(this); }
Transform* Component::ToTransform() { return dynamic_cast<Transform*>(this); }
Rigidbody* Component::ToRigidbody() { return dynamic_cast<Rigidbody*>(this); }
Script* Component::ToScript() { return dynamic_cast<Script*>(this); }
Camera* Component::ToCamera() { return dynamic_cast<Camera*>(this); }

// Lua binding:
void Component::AddUserType(sol::state & lua){
	lua.new_usertype<Component>("Component",
		"ToSprite", &Component::ToSprite,
		"ToCollider", &Component::ToCollider,
		"ToBoxCollider", &Component::ToBoxCollider,
		"ToSphereCollider", &Component::ToSphereCollider,
		"ToTransform", &Component::ToTransform,
		"ToRigidbody", &Component::ToRigidbody,
		"ToScript", &Component::ToScript,
		"ToCamera", &Component::ToCamera
		);
}