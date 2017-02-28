#pragma once

class GameObject;

// Base class for every component.

class Component {
public:
	GameObject& gameObject;

public:
	Component(GameObject& parentGO);
	virtual ~Component();
};
