#pragma once
#include "Component.h"

class Sprite : public Component {
private:
	sf::Texture* texture;
public:
	static std::list<Sprite*> sprites;
	sf::Sprite sprite;

public:
	Sprite(GameObject& parentGO);
	~Sprite();
	void SetTexture(std::string s);
};

