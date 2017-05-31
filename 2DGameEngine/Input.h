#pragma once
class Input {
private:
	// List of available keyboard keys / mouse buttons.
	static const sf::Keyboard::Key keyboardKeys[];
	static const std::string keyboardKeyStrings[];
	static const sf::Mouse::Button mouseButtons[];
	static const std::string mouseButtonStrings[];

	// Keyboard keys and mouse buttons flags.
	static std::map<sf::Keyboard::Key, bool> keyboardKeyDown;
	static std::map<sf::Keyboard::Key, bool> keyboardKeyUp;
	static std::map<sf::Mouse::Button, bool> mouseButtonDown;
	static std::map<sf::Mouse::Button, bool> mouseButtonUp;

private:
	Input();
public:
	~Input();

	// TODO map<string, key/button>: Mapping from string to key/button codes
	static sf::Keyboard::Key StringToKey(std::string keyString);
	static sf::Mouse::Button StringToMouseButton(std::string keyString);

	static void ClearInputDownUpFlags();
	static void OnKeyDown(sf::Keyboard::Key key);
	static void OnKeyUp(sf::Keyboard::Key key);
	static void OnMouseButtonDown(sf::Mouse::Button button);
	static void OnMouseButtonUp(sf::Mouse::Button button);

	static bool GetKey(std::string keyString);
	static bool GetKeyDown(std::string keyString);
	static bool GetKeyUp(std::string keyString);

	static bool GetMouseButton(std::string keyString);
	static bool GetMouseButtonDown(std::string keyString);
	static bool GetMouseButtonUp(std::string keyString);

	static b2Vec2 GetMousePosition();

	// Lua binding.
	static void AddUserType(sol::state& lua);
};

