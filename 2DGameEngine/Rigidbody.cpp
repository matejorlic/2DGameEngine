#include "stdafx.h"
#include "Rigidbody.h"

Rigidbody::Rigidbody(GameObject& parentGO) : Component(parentGO){
	if (gameObject.transform->body->GetType() == b2BodyType::b2_kinematicBody)
		gameObject.transform->body->SetType(b2BodyType::b2_dynamicBody);
}

Rigidbody::~Rigidbody(){
	if (gameObject.GetComponents<Rigidbody>().size() == 1 && gameObject.transform->body->GetType() == b2BodyType::b2_dynamicBody) {
		gameObject.transform->body->SetType(b2BodyType::b2_kinematicBody);
	}
}

void Rigidbody::SetMass(float m){
	std::list<Collider*> colliders = gameObject.GetComponents<Collider>();
	for each (Collider* c in colliders) {
		c->fixture->SetDensity(m / colliders.size());
		c->fixture->SetFriction(0.1f);
		c->fixture->SetRestitution(0.1f);
	}
}

void Rigidbody::SetGravityScale(float s){
	gameObject.transform->body->SetGravityScale(s);
}

void Rigidbody::AddUserType(sol::state & lua) {
	lua.new_usertype<Rigidbody>("Rigidbody",
		"SetMass", &Rigidbody::SetMass,
		"SetGravityScale", &Rigidbody::SetGravityScale
		);
}