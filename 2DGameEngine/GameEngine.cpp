#include "stdafx.h"
#include "GameEngine.h"
#include <Box2D\Box2D.h>

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

}
