#pragma once
#include "Component.h"

class Sprite : public Component {
public:
	Sprite(GameObject& parentGO);
	~Sprite();
	void SetTexture(std::string s);
};

