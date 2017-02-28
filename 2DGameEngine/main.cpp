// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "GameEngine.h"

int main() {
	GameEngine::Create();
	
	GameObject gameObject = GameObject("ball");
	gameObject.AddComponent<Sprite>()->SetTexture("Resources/blueBall.png");
	gameObject.AddComponent<SphereCollider>()->SetSize(40 / 2);
	gameObject.GetComponent<Transform>()->SetPosition(40 / 2 + 100, 40 / 2 + 500);
	gameObject.AddComponent<Rigidbody>()->SetMass(10);

	GameObject debugBox = GameObject("box");
	debugBox.AddComponent<Sprite>()->SetTexture("Resources/debugBox.png");
	debugBox.AddComponent<BoxCollider>()->SetSize(100 / 2, 100 / 2);
	debugBox.GetComponent<Transform>()->SetPosition(100 / 2 + 80, 100 / 2 + 100);
	debugBox.GetComponent<Transform>()->SetRotation(60);
	//debugBox.GetComponent<Transform>()->SetScale(1.5f, 1.5f);

	GameEngine::Run();
	return 0;
}