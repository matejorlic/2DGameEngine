#include "stdafx.h"
#include "BoxCollider.h"

BoxCollider::BoxCollider(GameObject& parentGO) : Collider(parentGO) {
	//TODO
	if(gameObject.transform->body->GetType() == b2BodyType::b2_staticBody)
		gameObject.transform->body->SetType(b2BodyType::b2_kinematicBody);
}


BoxCollider::~BoxCollider() {
	if (fixture != nullptr) {
		gameObject.transform->body->DestroyFixture(fixture);
	}
	
	if (gameObject.GetComponents<Collider>().size() == 1 && gameObject.transform->body->GetType() == b2BodyType::b2_kinematicBody) {
		gameObject.transform->body->SetType(b2BodyType::b2_staticBody);
	}
}

void BoxCollider::SetSize(int x, int y){
	if (fixture != nullptr) {
		gameObject.transform->body->DestroyFixture(fixture);
	}

	// Define the ground box shape.
	b2PolygonShape box;

	// The extents are the half-widths of the box.
	box.SetAsBox(1.0f * x / GameEngine::physicsToGraphicsRatio, 1.0f * y / GameEngine::physicsToGraphicsRatio);
	
	// Add the ground fixture to the ground body.
	fixture = gameObject.transform->body->CreateFixture(&box, 0.0f);
}

void BoxCollider::AddUserType(sol::state & lua) {
	lua.new_usertype<BoxCollider>("BoxCollider",
		"SetSize", &BoxCollider::SetSize
		);
}