#include "stdafx.h"
#include "GameObject.h"

std::list<GameObject*> GameObject::gameObjects;

GameObject::GameObject() : GameObject("GameObject") {};

GameObject::GameObject(std::string n) {
	name = n;
	gameObjects.push_back(this);
	transform = AddComponent<Transform>();
}

GameObject::~GameObject() {
	gameObjects.remove(this);
}

GameObject* GameObject::Find(std::string name) {
	for (GameObject* gameObject : gameObjects) {
		if (gameObject->name == name)
			return gameObject;
	}
	return nullptr;
}

GameObject& GameObject::Clone(GameObject gameObject) {
	//TODO
	return GameObject();
}

GameObject* GameObject::Create() {
	return new GameObject();
}

void GameObject::RemoveComponent(Component& component) {
	//TODO
}


// Methods for Lua binding - type must be passed as parameter.
void GameObject::AddUserType(sol::state & lua){
	lua.new_usertype<GameObject>("GameObject",
		//TODO remove name variable, add SetName function
		"name", &GameObject::name,
		"AddComponent", &GameObject::AddComponentLua,
		"GetComponent", &GameObject::GetComponentLua,
		"GetComponents", &GameObject::GetComponentsLua,
		"RemoveComponent", &GameObject::RemoveComponentLua,
		"Find", &GameObject::Find,
		"Create", &GameObject::Create
		);
}

Component * GameObject::AddComponentLua(std::string componentType) {
	if (componentType == "Sprite")
		return AddComponent<Sprite>();
	else if (componentType == "BoxCollider")
		return AddComponent<BoxCollider>();
	else if (componentType == "SphereCollider")
		return AddComponent<SphereCollider>();
	else if (componentType == "Transform")
		return AddComponent<Transform>();
	else if (componentType == "Rigidbody")
		return AddComponent<Rigidbody>();
	else if (componentType == "Script")
		return AddComponent<Script>();
	else if (componentType == "Camera")
		return AddComponent<Camera>();
}

Component * GameObject::GetComponentLua(std::string componentType) {
	if (componentType == "Sprite")
		return GetComponent<Sprite>();
	else if (componentType == "BoxCollider")
		return GetComponent<BoxCollider>();
	else if (componentType == "SphereCollider")
		return GetComponent<SphereCollider>();
	else if (componentType == "Transform")
		return GetComponent<Transform>();
	else if (componentType == "Rigidbody")
		return GetComponent<Rigidbody>();
	else if (componentType == "Script")
		return GetComponent<Script>();
	else if (componentType == "Camera")
		return GetComponent<Camera>();
	else {
		Script* script = GetComponent<Script>();
		if (script->GetScriptName() == componentType) {
			return script;
		}
	}
}

std::list<Component*> GameObject::GetComponentsLua(std::string componentType) {
	//TODO

	return std::list<Component*>();
}

void GameObject::RemoveComponentLua(std::string componentType) {
	//TODO
}
