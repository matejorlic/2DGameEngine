#include "stdafx.h"
#include "Transform.h"
#include "GameEngine.h"
#include <cmath>

Transform::Transform(GameObject& parentGO) : Component(parentGO){
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(0.0f, 0.0f);
	body = GameEngine::GetInstance()->physicsWorld->CreateBody(&bodyDef);
}

Transform::~Transform(){
	//TODO
	GameEngine::GetInstance()->physicsWorld->DestroyBody(body);
	body = nullptr;
}

b2Vec2 Transform::GetPosition() {
	return b2Vec2(body->GetPosition().x * GameEngine::physicsToGraphicsRatio, body->GetPosition().y * GameEngine::physicsToGraphicsRatio);
}

float Transform::GetRotation() {
	return body->GetAngle() * 180 / b2_pi;
}

Transform & Transform::SetPosition(float x, float y) {
	body->SetTransform(b2Vec2(x / GameEngine::physicsToGraphicsRatio, y / GameEngine::physicsToGraphicsRatio), body->GetAngle());
	body->SetAwake(true);
	return *this;
}

Transform & Transform::SetRotation(float angle) {
	body->SetTransform(body->GetPosition(), angle * b2_pi / 180);
	body->SetAwake(true);
	return *this;
}

void Transform::AddUserType(sol::state & lua) {
	lua.new_usertype<Transform>("Transform",
		"GetPosition", &Transform::GetPosition,
		"GetRotation", &Transform::GetRotation,
		"SetPosition", &Transform::SetPosition,
		"SetRotation", &Transform::SetRotation
		);
}