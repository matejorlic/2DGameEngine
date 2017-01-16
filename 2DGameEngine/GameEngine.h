#pragma once
#include "GameObject.h"
#include "Component.h"

class b2World;

class GameEngine {
private:
	static GameEngine* gameEngine;
public:
	static b2World* world;
	
private:
	GameEngine();
	
public:
	static void Create();

	GameEngine(const GameEngine &) = delete;
	GameEngine(GameEngine &&) = delete;
	GameEngine & operator=(const GameEngine &) = delete;
	GameEngine & operator=(GameEngine &&) = delete;

	~GameEngine();
};