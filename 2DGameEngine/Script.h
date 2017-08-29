#pragma once
#include "Component.h"

// Script component is used to bind the engine with Lua scripting

class Script : public Component {
private:
	static std::list<Script*> scripts;
	sol::state lua;
	std::string scriptName;

public:
	static void Update();
	Script(GameObject& parentGO);
	~Script();
	void Init(std::string name);
	std::string GetScriptName() { return scriptName; }
	sol::state* GetLua() { return &lua; }

	// Lua binding
	static void AddUserType(sol::state& lua);
	static void AddUserTypes(sol::state& lua); // Add user types for all engine classes.
};