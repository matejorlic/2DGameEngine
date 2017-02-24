#pragma once
#include <list>
#include "Sprite.h"
#include "Transform.h"

class Component;

class GameObject {
private:
	static std::list<GameObject*> gameObjects;
	std::list<Component*> components;
public:
	std::string name;
	Transform *transform;

private:

public:
	GameObject();
	GameObject(std::string name);
	~GameObject();
	static GameObject& Find(std::string name);
	static GameObject& Clone(GameObject gameObject);
	template <typename T>
	T* AddComponent() {
		T* newComponent = new T(*this);
		components.push_back(newComponent);
		return newComponent;
	}
	template <typename T>
	T* GetComponent() {
		return &T(*this);
	}
	template <typename T>
	void RemoveComponent() {

	}
	void RemoveComponent(Component& component);
};