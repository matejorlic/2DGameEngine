#include "stdafx.h"
#include "Input.h"

const sf::Keyboard::Key Input::keyboardKeys[] = {
	sf::Keyboard::Key::A, sf::Keyboard::Key::B, sf::Keyboard::Key::C, sf::Keyboard::Key::D, sf::Keyboard::Key::E, sf::Keyboard::Key::F,
	sf::Keyboard::Key::G, sf::Keyboard::Key::H, sf::Keyboard::Key::I, sf::Keyboard::Key::J, sf::Keyboard::Key::K, sf::Keyboard::Key::L,
	sf::Keyboard::Key::M, sf::Keyboard::Key::N, sf::Keyboard::Key::O, sf::Keyboard::Key::P, sf::Keyboard::Key::Q, sf::Keyboard::Key::R,
	sf::Keyboard::Key::S, sf::Keyboard::Key::T, sf::Keyboard::Key::U, sf::Keyboard::Key::V, sf::Keyboard::Key::W, sf::Keyboard::Key::X,
	sf::Keyboard::Key::Y, sf::Keyboard::Key::Z,
	sf::Keyboard::Key::Escape, sf::Keyboard::Key::LControl, sf::Keyboard::Key::RControl, sf::Keyboard::Key::LShift, sf::Keyboard::Key::RShift,
	sf::Keyboard::Key::Space, sf::Keyboard::Key::Return, sf::Keyboard::Key::BackSpace, sf::Keyboard::Key::Tab,
	sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Keyboard::Key::Up, sf::Keyboard::Key::Down
};
const std::string Input::keyboardKeyStrings[] = {
	"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
	"Escape", "LControl", "RControl", "LShift", "RShift", "Space", "Return", "BackSpace", "Tab", "Left", "Right", "Up", "Down"
};

const sf::Mouse::Button Input::mouseButtons[] = {
	sf::Mouse::Button::Left, sf::Mouse::Button::Right, sf::Mouse::Button::Middle
};
const std::string Input::mouseButtonStrings[] = {
	"Left", "Right", "Middle"
};

std::map<sf::Keyboard::Key, bool> Input::keyboardKeyDown;
std::map<sf::Keyboard::Key, bool> Input::keyboardKeyUp;
std::map<sf::Mouse::Button, bool> Input::mouseButtonDown;
std::map<sf::Mouse::Button, bool> Input::mouseButtonUp;

Input::Input(){
}
Input::~Input(){
}

sf::Keyboard::Key Input::StringToKey(std::string keyString) {
	for (int i = 0; i < sizeof(keyboardKeyStrings)/sizeof(keyboardKeyStrings[0]); i++) {
		if (keyString == keyboardKeyStrings[i]) {
			return keyboardKeys[i];
		}
	}
	//TODO throw lua error?
	return sf::Keyboard::Key::Unknown;
}

sf::Mouse::Button Input::StringToMouseButton(std::string keyString) {
	for (int i = 0; i < sizeof(mouseButtonStrings)/sizeof(mouseButtonStrings[0]); i++) {
		if (keyString == mouseButtonStrings[i]) {
			return mouseButtons[i];
		}
	}
	//TODO throw lua error?
	return sf::Mouse::Button::Left;
}

void Input::ClearInputDownUpFlags() {
	for (sf::Keyboard::Key key : keyboardKeys) {
		keyboardKeyDown[key] = false;
		keyboardKeyUp[key] = false;
	}

	for (sf::Mouse::Button button : mouseButtons) {
		mouseButtonDown[button] = false;
		mouseButtonUp[button] = false;
	}
}

void Input::OnKeyDown(sf::Keyboard::Key key) {
	keyboardKeyDown[key] = true;
}
void Input::OnKeyUp(sf::Keyboard::Key key) {
	keyboardKeyUp[key] = true;
}
void Input::OnMouseButtonDown(sf::Mouse::Button button) {
	mouseButtonDown[button] = true;
}
void Input::OnMouseButtonUp(sf::Mouse::Button button) {
	mouseButtonUp[button] = true;
}

bool Input::GetKey(std::string keyString) {
	return sf::Keyboard::isKeyPressed(StringToKey(keyString));
}
bool Input::GetKeyDown(std::string keyString) {
	return keyboardKeyDown[StringToKey(keyString)];
}
bool Input::GetKeyUp(std::string keyString) {
	return keyboardKeyUp[StringToKey(keyString)];
}

bool Input::GetMouseButton(std::string keyString) {
	return sf::Mouse::isButtonPressed(StringToMouseButton(keyString));
}
bool Input::GetMouseButtonDown(std::string keyString) {
	return mouseButtonDown[StringToMouseButton(keyString)];
}
bool Input::GetMouseButtonUp(std::string keyString) {
	return mouseButtonUp[StringToMouseButton(keyString)];
}

b2Vec2 Input::GetMousePosition() {
	sf::Vector2i globalPosition = sf::Mouse::getPosition(*GameEngine::GetInstance()->window);
	return b2Vec2(globalPosition.x, globalPosition.y);
}

void Input::AddUserType(sol::state & lua) {
	lua.new_usertype<Input>("Input",
		"GetKey", &Input::GetKey,
		"GetKeyDown", &Input::GetKeyDown,
		"GetKeyUp", &Input::GetKeyUp,
		"GetMouseButton", &Input::GetMouseButton,
		"GetMouseButtonDown", &Input::GetMouseButtonDown,
		"GetMouseButtonUp", &Input::GetMouseButtonUp,
		"GetMousePosition", &Input::GetMousePosition
		);
}