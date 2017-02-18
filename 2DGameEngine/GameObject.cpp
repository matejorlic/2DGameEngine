#include "stdafx.h"
#include "GameObject.h"

std::list<GameObject*> GameObject::gameObjects;

GameObject::GameObject() : GameObject("GameObject") {};

GameObject::GameObject(std::string n) {
	name = n;
	gameObjects.push_back(this);
}
GameObject::~GameObject() {
	gameObjects.remove(this);
}

GameObject& GameObject::Find(std::string name) {
	return GameObject();
}
GameObject& GameObject::Clone(GameObject gameObject) {
	return GameObject();
}

void GameObject::RemoveComponent(Component& component) {

}
