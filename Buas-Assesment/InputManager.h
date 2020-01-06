#pragma once
#include <sfml/Graphics.hpp>

class InputManager
{
	//Keyboard controls for any typical game
private:
	void TriggerEvent(sf::Event, sf::Keyboard::Key, void(*trigger)());

	//Movement actions you need in a lot of games
	sf::Keyboard::Key _up;
	void (*_eventUp)();

	sf::Keyboard::Key _down;
	void (*_eventDown)();

	sf::Keyboard::Key _left;
	void (*_eventLeft)();

	sf::Keyboard::Key _right;
	void (*_eventRight)();
	
	//Generic actions
	sf::Keyboard::Key _jump;
	void (*_eventJump)();

	sf::Keyboard::Key _fire;
	void (*_eventFire)();

	//The boring actions you need;
	sf::Keyboard::Key _pause;
	void (*_eventPause)();

public:
	InputManager();
	
	enum Input {
		Up,
		Down,
		Left,
		Right,
		Jump,
		Fire,
		Pause
	};

	//Sets the key to a different kind of key
	void SetKeyTo(InputManager::Input, sf::Keyboard::Key);

	//Adds a event listener on the response of a key
	void SetEvent(InputManager::Input, void(*trigger)());

	//Checks through all eventlisteners and activates when responded
	void UpdateEvents(sf::Event);
	
	//Checks a specific event and activates it when responded
	void UpdateEvent(sf::Event, InputManager::Input);

	~InputManager();
};

