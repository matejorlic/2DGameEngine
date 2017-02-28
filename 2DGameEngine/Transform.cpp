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
	//TODO
}

b2Vec2 Transform::GetPosition() {
	return body->GetPosition();
}

float Transform::GetRotation() {
	return body->GetAngle();
}

Transform & Transform::SetPosition(float x, float y) {
	body->SetTransform(b2Vec2(x / GameEngine::physicsToGraphicsRatio, y / GameEngine::physicsToGraphicsRatio), body->GetAngle());
	return *this;
}

Transform & Transform::SetRotation(float angle) {
	body->SetTransform(body->GetPosition(), angle);
	return *this;
}
