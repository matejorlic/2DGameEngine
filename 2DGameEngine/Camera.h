#pragma once
#include "Component.h"
class Camera : public Component {
private:
	sf::View view;
public:
	static Camera* mainCamera;
	static std::list<Camera*> cameras;

public:
	Camera(GameObject& parentGO);
	~Camera();
	
	static void SetMainCamera(Camera& newMainCamera);

	sf::View GetView();
	void UpdateView();


	// Lua binding.
	static void AddUserType(sol::state& lua);
};

