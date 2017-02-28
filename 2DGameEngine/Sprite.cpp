#include "stdafx.h"
#include "Sprite.h"

std::list<Sprite*> Sprite::sprites;

Sprite::Sprite(GameObject& parentGO) : Component(parentGO){
	sprites.push_back(this);
}

Sprite::~Sprite(){
	if (texture != nullptr)
		delete texture;
	sprites.remove(this);
}

void Sprite::SetTexture(std::string s){
	if (texture != nullptr)
		delete texture;

	texture = new sf::Texture();
	texture->loadFromFile(s);
	//texture->setSmooth(true);

	sprite.setTexture(*texture);
	sprite.setOrigin(0.5f * texture->getSize().x, 0.5f * texture->getSize().y);
}
