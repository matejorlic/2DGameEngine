#include "stdafx.h"
#include "GameEngine.h"
#include <Box2D\Box2D.h>

GameEngine* GameEngine::gameEngine = nullptr;
b2World* GameEngine::world;

GameEngine::GameEngine() {
	b2Vec2 gravity(0.0f, -10.0f);
	world = new b2World(gravity);
}

GameEngine::~GameEngine() {
	delete world;
	delete gameEngine;
}

void GameEngine::Create() {
	if (gameEngine == nullptr) {
		gameEngine = new GameEngine();
	}
}
