#include "stdafx.h"
#include "GameEngine.h"

GameEngine* GameEngine::gameEngine = nullptr;
const float GameEngine::timeStep = 1.0f / 60.0f;
const int GameEngine::velocityIterations = 6;
const int GameEngine::positionIterations = 2;

GameEngine::GameEngine() {
	b2Vec2 gravity(0.0f, -10.0f);
	physicsWorld = new b2World(gravity);
}

GameEngine::~GameEngine() {
	delete physicsWorld;
	delete gameEngine;
}

GameEngine* GameEngine::GetInstance() {
	Create();
	return gameEngine;
}

void GameEngine::Create(){
	if (gameEngine == nullptr) {
		gameEngine = new GameEngine();
	}
}

void GameEngine::Run(){
	gameEngine->window = new sf::RenderWindow(sf::VideoMode(500, 500), "SFML works!");

	float xPos = 0;
	bool direction = true;
	while (gameEngine->window->isOpen()) {
		gameEngine->ProcessInput();
		gameEngine->UpdatePhysics();
		gameEngine->UpdateGraphics();
		Sleep(1000 * timeStep * 0.5f);
	}
}

void GameEngine::ProcessInput() {
	sf::Event event;
	while (gameEngine->window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			gameEngine->window->close();
			return;
		}
	}
}

void GameEngine::UpdatePhysics(){

}

void GameEngine::UpdateGraphics(){
	window->clear();
	for each (Sprite* s in Sprite::sprites) {
		b2Vec2 position = s->gameObject.transform->GetPosition();
		float32 angle = s->gameObject.transform->GetRotation();
		//s->sprite.setPosition(position.x * 100, 500 - position.y * 100);
		s->sprite.setRotation(angle);

		window->draw(s->sprite);
	}

	//window->draw(blueSprite);
	window->display();
}