#pragma once
#include "Component.h"

// Sprite component is used for saving graphics (textures) that are drawn on objects positions.

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

	// Lua binding.
	static void AddUserType(sol::state& lua);
};