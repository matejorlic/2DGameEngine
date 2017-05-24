#include "stdafx.h"
#include "Collider.h"


Collider::Collider(GameObject& parentGO) : Component(parentGO){
	//TODO
}


Collider::~Collider(){
	//TODO
}

void Collider::AddUserType(sol::state & lua) {
	lua.new_usertype<Collider>("Collider"
		);
}