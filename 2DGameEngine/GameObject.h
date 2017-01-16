#pragma once
#include <list>

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
	static GameObject* Find(std::string name);
	static GameObject* Clone(GameObject gameObject);
	template <typename T>
	T AddComponent();
	template <typename T>
	T GetComponent();
	template <typename T>
	void RemoveComponent();
	void RemoveComponent(Component& component);
};