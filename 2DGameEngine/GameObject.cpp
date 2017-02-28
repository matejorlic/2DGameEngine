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

GameObject& GameObject::Find(std::string name) {
	//TODO
	return GameObject();
}
GameObject& GameObject::Clone(GameObject gameObject) {
	//TODO
	return GameObject();
}

void GameObject::RemoveComponent(Component& component) {
	//TODO
}
