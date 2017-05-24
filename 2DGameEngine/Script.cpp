#include "stdafx.h"
#include "Script.h"

std::list<Script*> Script::scripts;

Script::Script(GameObject& parentGO) : Component(parentGO){
	scriptName = "";
	scripts.push_back(this);
}

Script::~Script(){
	scripts.remove(this);
}

void Script::Init(std::string name){
	if (scriptName != "")
		return;

	scriptName = name;
	lua.open_libraries();

	Script::AddUserTypes(lua);

	lua["gameObject"] = gameObject;

	lua.script_file(scriptName, [](lua_State* L, sol::protected_function_result pfr) {
		sol::error err = pfr;
		std::cout << err.what() << std::endl;
		return pfr;
	});

	sol::protected_function luaStart = lua["Start"];
	auto luaStartResult = luaStart();
	if (!luaStartResult.valid()) {
		sol::error err = luaStartResult;
		std::cout << err.what() << std::endl;
	}
}

// Connect lua objects with c++ objects.
void Script::AddUserTypes(sol::state & lua) {
	GameObject::AddUserType(lua);
	Component::AddUserType(lua);

	Sprite::AddUserType(lua);
	Collider::AddUserType(lua);
	BoxCollider::AddUserType(lua);
	SphereCollider::AddUserType(lua);
	Transform::AddUserType(lua);
	Rigidbody::AddUserType(lua);
	Script::AddUserType(lua);

	// Custom user types
	lua.new_usertype<b2Vec2>("Vector2",
		"x", &b2Vec2::x,
		"y", &b2Vec2::y,
		"Magnitude", &b2Vec2::Length
		);
}

// Static void. Called once per frame.
void Script::Update() {
	for each (Script* script in scripts) {
		sol::protected_function luaUpdate = script->lua["Update"];
		auto luaUpdateResult = luaUpdate();
		if (!luaUpdateResult.valid()) {
			sol::error err = luaUpdateResult;
			std::cout << err.what() << std::endl;
		}
	}
}

// Lua binding.
void Script::AddUserType(sol::state & lua) {
	lua.new_usertype<Script>("Script",
		"Init", &Script::Init
		);
}