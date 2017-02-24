#pragma once

class GameObject;

class Component {
public:
	GameObject& gameObject;

public:
	Component(GameObject& parentGO);
	~Component();
};
