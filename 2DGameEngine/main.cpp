// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "GameEngine.h"

b2Body* body[20];
b2Body* blueBody;

sf::CircleShape shape[20];
sf::Sprite blueSprite;
sf::Text text, tutorial;
sf::Font font;
sf::Texture *blueBallTex;

float32 timeStep2 = 1.0f / 60.0f;
int32 velocityIterations2 = 6;
int32 positionIterations2 = 2;
int a = 0;

int main() {
	GameEngine::Create();
	
	GameObject gameObject = GameObject("ball");
	gameObject.AddComponent<Sprite>()->SetTexture("Resources/blueBall.png");
	gameObject.AddComponent<SphereCollider>()->SetSize(40 / 2);
	gameObject.GetComponent<Transform>()->SetPosition(40 / 2 + 100, 40 / 2 + 500);
	//gameObject.GetComponent<Transform>()->SetScale(0.5f, 0.5f);
	gameObject.AddComponent<Rigidbody>()->SetMass(10);

	GameObject debugBox = GameObject("box");
	debugBox.AddComponent<Sprite>()->SetTexture("Resources/debugBox.png");
	debugBox.AddComponent<BoxCollider>()->SetSize(100 / 2, 100 / 2);
	debugBox.GetComponent<Transform>()->SetPosition(100 / 2 + 80, 100 / 2 + 100);
	debugBox.GetComponent<Transform>()->SetRotation(60);
	//debugBox.GetComponent<Transform>()->SetScale(0.5f, 0.5f);
	//debugBox.AddComponent<Rigidbody>()->SetMass(10);

	GameEngine::Run();
	return 0;
}

void CreatePhysics(b2World &world) {
	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
	b2BodyDef groundBodyDef2;
	groundBodyDef2.position.Set(-10.0f, 0.0f);
	b2BodyDef groundBodyDef3;
	groundBodyDef3.position.Set(15.0f, 0.0f);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2Body* groundBody2 = world.CreateBody(&groundBodyDef2);
	b2Body* groundBody3 = world.CreateBody(&groundBodyDef3);

	// Define the ground box shape.
	b2PolygonShape groundBox;
	b2PolygonShape groundBox2;
	b2PolygonShape groundBox3;


	// The extents are the half-widths of the box.
	groundBox.SetAsBox(50.0f, 10.0f);
	groundBox2.SetAsBox(10.0f, 50.0f);
	groundBox3.SetAsBox(10.0f, 50.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);
	groundBody2->CreateFixture(&groundBox2, 0.0f);
	groundBody3->CreateFixture(&groundBox3, 0.0f);


	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;

	b2CircleShape circleShape;
	circleShape.m_radius = 0.2f;

	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circleShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.1f;
	fixtureDef.restitution = 0.6f;


	for (int i = 0; i < 20; i++) {
		// Define the dynamic body. We set its position and call the body factory.
		bodyDef.position.Set(1.0f + 0.2f * i, 3.0f + 0.2f * i);
		body[i] = world.CreateBody(&bodyDef);

		// Add the shape to the body.
		body[i]->CreateFixture(&fixtureDef);
	}


	bodyDef.position.Set(1.0f, 1.0f);
	blueBody = world.CreateBody(&bodyDef);
	fixtureDef.density = 5.0f;
	fixtureDef.friction = 0.8f;
	blueBody->CreateFixture(&fixtureDef);
}

void CreateGraphics() {
	for (int i = 0; i < 20; i++) {
		shape[i].setRadius(20);
		shape[i].setFillColor(sf::Color::Green);
	}

	blueBallTex = new sf::Texture();
	blueBallTex->loadFromFile("Resources/blueBall.png");
	blueBallTex->setSmooth(true);

	blueSprite.setTexture(*blueBallTex);
	blueSprite.setOrigin(0.5f * blueBallTex->getSize().x, 0.5f * blueBallTex->getSize().y);

	text.setString("");
	text.setFillColor(sf::Color::Red);
	tutorial.setString("Use arrows to control the blue ball");
	tutorial.setFillColor(sf::Color::White);

	font.loadFromFile("Resources/arial.ttf");
	text.setFont(font);
	tutorial.setFont(font);
	tutorial.setPosition(0, 50);
	tutorial.setCharacterSize(20);
}

void Update(sf::RenderWindow &window, b2World &world) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window.close();
			return;
		}
	}

	//Sleep for timeStep ms.
	Sleep(timeStep2 * 1000 * 0.5f);

	// Check input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		blueBody->ApplyForce(b2Vec2(0, 10), blueBody->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		blueBody->ApplyForce(b2Vec2(0, -10), blueBody->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		blueBody->ApplyForce(b2Vec2(5, 0), blueBody->GetWorldCenter(), true);
		blueBody->ApplyTorque(10.0f, true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		blueBody->ApplyForce(b2Vec2(-5, 0), blueBody->GetWorldCenter(), true);
		blueBody->ApplyTorque(-10.0f, true);
	}

	// Instruct the world to perform a single step of simulation.
	// It is generally best to keep the time step and iterations fixed.
	world.Step(timeStep2, velocityIterations2, positionIterations2);

	for (int i = 0; i < 20; i++) {
		// Now print the position and angle of the body.
		b2Vec2 position = body[i]->GetPosition();
		float32 angle = body[i]->GetAngle();
		shape[i].setPosition(position.x * 100 - 20, 500 - position.y * 100 - 20);
	}
	b2Vec2 position = blueBody->GetPosition();
	float32 angle = blueBody->GetAngle();
	blueSprite.setRotation(angle);
	blueSprite.setPosition(position.x * 100, 500 - position.y * 100);

	a++;
	text.setString(std::to_string(a));
}

void Render(sf::RenderWindow &window) {
	window.clear();
	window.draw(blueSprite);
	for (int i = 0; i < 20; i++) window.draw(shape[i]);
	window.draw(text);
	window.draw(tutorial);
	window.display();
}

int main2() {
	// Define the gravity vector.
	b2Vec2 gravity(0.0f, -10.0f);
	// Construct a world object, which will hold and simulate the rigid bodies.
	b2World world(gravity);

	CreatePhysics(world);

	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	CreateGraphics();

	float xPos = 0;
	bool direction = true;
	while (window.isOpen())
	{
		Update(window, world);
		Render(window);
	}
	delete blueBallTex;
	return 0;
}