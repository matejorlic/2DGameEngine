#include "stdafx.h"
#include "Camera.h"

Camera* Camera::mainCamera;
std::list<Camera*> Camera::cameras;

Camera::Camera(GameObject& parentGO) : Component(parentGO) {
	if (Camera::mainCamera == nullptr)
		Camera::mainCamera = this;

	cameras.push_back(this);
}

Camera::~Camera() {
	if (Camera::mainCamera == this)
		Camera::mainCamera = nullptr;

	cameras.push_back(this);
}

void Camera::SetMainCamera(Camera& newMainCamera) {
	Camera::mainCamera = &newMainCamera;
}

sf::View Camera::GetView(){
	return view;
}

void Camera::UpdateView(){
	view.setSize(GameEngine::GetInstance()->window->getSize().x, GameEngine::GetInstance()->window->getSize().y);

	view.setCenter(gameObject.transform->GetPosition().x, GameEngine::windowSizeY - gameObject.transform->GetPosition().y);
}

void Camera::AddUserType(sol::state & lua) {
	lua.new_usertype<Camera>("Camera",
		"SetMainCamera", &Camera::SetMainCamera
		);
}
