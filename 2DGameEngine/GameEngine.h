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
#include "Transform.h"
#include "Rigidbody.h"

class b2World;

class GameEngine {
private:
	// Singleton GameEngine object
	static GameEngine* gameEngine;

public:

	// Physics constants
	static const float timeStep;
	static const int velocityIterations;
	static const int positionIterations;
	static const int physicsToGraphicsRatio;

	b2World* physicsWorld;
	sf::RenderWindow* window;

	// Window size
	static int windowSizeX;
	static int windowSizeY;
	
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