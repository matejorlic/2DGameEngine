#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject() : GameObject("GameObject") {};

GameObject::GameObject(std::string n) {
	name = n;
	gameObjects.push_back(*this);
}
GameObject::~GameObject() {
	gameObjects.remove(*this);
}

GameObject GameObject::Find(std::string name) {

}
GameObject GameObject::Clone(GameObject gameObject) {

}

void GameObject::RemoveComponent(Component component)
{
}

template <typename T>
T GameObject::AddComponent() {

}
template <typename T>
T GameObject::GetComponent() {

}

void GameObject::RemoveComponent() {

}
