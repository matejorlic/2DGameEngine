#pragma once
#include <list>
#include "Sprite.h"
#include "Transform.h"

// GameObject class represent a game object.
// It saves list of components attached to a game object.
// Components can be added or removed from the game object.

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
		for each (Component* comp in components) {
			if (dynamic_cast<T*>(comp)) {
				return dynamic_cast<T*>(comp);
			}
		}
		return nullptr;
	}

	template <typename T>
	std::list<T*> GetComponents() {
		std::list<T*> comps;
		for each (Component* comp in components) {
			if (dynamic_cast<T*>(comp)) {
				comps.push_back(dynamic_cast<T*>(comp));
			}
		}
		return comps;
	}

	template <typename T>
	void RemoveComponent() {
		//TODO
	}
	void RemoveComponent(Component& component);

	// Lua binding.
	static void AddUserType(sol::state& lua);

	// Methods used for Lua binding. Type must be passed as parameter.
	Component* AddComponentLua(std::string componentType);
	Component* GetComponentLua(std::string componentType);
	std::list<Component*> GetComponentsLua(std::string componentType);
	void RemoveComponentLua(std::string componentType);
};