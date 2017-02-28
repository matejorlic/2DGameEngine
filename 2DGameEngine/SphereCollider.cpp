#include "stdafx.h"
#include "SphereCollider.h"

SphereCollider::SphereCollider(GameObject& parentGO) : Collider(parentGO) {
	//TODO
	if (gameObject.transform->body->GetType() == b2BodyType::b2_staticBody)
		gameObject.transform->body->SetType(b2BodyType::b2_kinematicBody);
}


SphereCollider::~SphereCollider() {
	if (fixture != nullptr) {
		gameObject.transform->body->DestroyFixture(fixture);
	}

	/*if (gameObject.GetComponents<Collider>().lenght == 1 && gameObject.transform->body->GetType() == b2BodyType::b2_kinematicBody) {
	gameObject.transform->body->SetType(b2BodyType::b2_staticBody);
	}*/
}

void SphereCollider::SetSize(int x) {
	if (fixture != nullptr) {
		gameObject.transform->body->DestroyFixture(fixture);
	}

	b2CircleShape circleShape;
	circleShape.m_radius = x;
	fixture = gameObject.transform->body->CreateFixture(&circleShape, 0.0f);
}
