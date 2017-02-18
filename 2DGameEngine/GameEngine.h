#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include <Windows.h> //For Sleep()

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
	sf::RenderWindow* window;
	
private:
	GameEngine();
	void ProcessInput();
	void UpdatePhysics();
	void UpdateGraphics();
	
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