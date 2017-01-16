#pragma once

class GameObject;

class Component {
private:
	GameObject& parent;
public:
	Component(GameObject& parentGO);
	~Component();
};
