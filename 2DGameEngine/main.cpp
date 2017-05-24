// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "GameEngine.h"

/*void testGame() {
	GameObject* gameObject = new GameObject("ball");
	gameObject->AddComponent<Sprite>()->SetTexture("Resources/blueBall.png");
	gameObject->AddComponent<SphereCollider>()->SetSize(40 / 2);
	gameObject->GetComponent<Transform>()->SetPosition(40 / 2 + 100, 40 / 2 + 500);
	gameObject->AddComponent<Rigidbody>()->SetMass(10);

	GameObject* debugBox = new GameObject("box");
	//debugBox->AddComponent<Sprite>()->SetTexture("Resources/debugBox.png"); // in debugBox.lua
	debugBox->AddComponent<Sprite>();
	debugBox->AddComponent<BoxCollider>()->SetSize(100 / 2, 100 / 2);
	debugBox->GetComponent<Transform>()->SetPosition(100 / 2 + 80, 100 / 2 + 100);
	debugBox->GetComponent<Transform>()->SetRotation(60);
	//debugBox->GetComponent<Transform>()->SetScale(1.5f, 1.5f);
	debugBox->AddComponent<Script>()->Init("Resources/debugBox.lua");
}*/

void luaMain() {
	sol::state lua;
	lua.open_libraries();

	Script::AddUserTypes(lua);

	lua.script_file("Resources/init.lua", [](lua_State* L, sol::protected_function_result pfr) {
		sol::error err = pfr;
		std::cout << err.what() << std::endl;
		return pfr;
	});

	sol::protected_function luaInit = lua["Init"];
	auto luaInitResult = luaInit();
	if (!luaInitResult.valid()) {
		sol::error err = luaInitResult;
		std::cout << err.what() << std::endl;
	}
}

int main() {
	GameEngine::Create();

	// TODO Move luaMain() to GameEngine::Run() ?
	luaMain();

	GameEngine::Run();
	return 0;
}

