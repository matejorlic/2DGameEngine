#pragma once
#include <list>
#include "Sprite.h"

class Component;

class GameObject {
private:
	static std::list<GameObject*> gameObjects;
	std::list<Component*> components;
public:
	std::string name;

private:

public:
	GameObject();
	GameObject(std::string name);
	~GameObject();
	static GameObject& Find(std::string name);
	static GameObject& Clone(GameObject gameObject);
	template <typename T>
	T AddComponent() {
		return T(*this);
	}
	template <typename T>
	T GetComponent() {
		return T(*this);
	}
	template <typename T>
	void RemoveComponent() {

	}
	void RemoveComponent(Component& component);
};