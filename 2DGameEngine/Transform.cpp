#include "stdafx.h"
#include "Transform.h"
#include "GameEngine.h"

Transform::Transform(GameObject& parentGO) : Component(parentGO){
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(0.0f, 0.0f);
	body = GameEngine::GetInstance()->physicsWorld->CreateBody(&bodyDef);
}


Transform::~Transform(){

}

b2Vec2 Transform::GetPosition() {
	return body->GetPosition();
}

float Transform::GetRotation() {
	return body->GetAngle();
}
