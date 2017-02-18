#pragma once
#include "GameObject.h"
#include "Component.h"
#include "Sprite.h"
#include "Collider.h"
#include "BoxCollider.h"
#include "SphereCollider.h"


class b2World;

class GameEngine {
private:
	// Singleton GameEngine object
	static GameEngine* gameEngine;

	// Physics constants
	static const float timeStep;
	static const int velocityIterations;
	static const int positionIterations;
public:
	b2World* physicsWorld;
	
private:
	GameEngine();
	
public:
	static GameEngine* GetInstance();
	static void Create();
	static void Run();

	GameEngine(const GameEngine &) = delete;
	GameEngine(GameEngine &&) = delete;
	GameEngine & operator=(const GameEngine &) = delete;
	GameEngine & operator=(GameEngine &&) = delete;

	~GameEngine();
};