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

GameObject* GameObject::Find(std::string name) {
	return new GameObject();
}
GameObject* GameObject::Clone(GameObject gameObject) {
	return new GameObject();
}

template <typename T>
T GameObject::AddComponent() {

}

template <typename T>
T GameObject::GetComponent() {

}

template <typename T>
void GameObject::RemoveComponent() {

}

void GameObject::RemoveComponent(Component& component) {

}
