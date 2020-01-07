#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>



InputManager::InputManager()
{	
	_up = sf::Keyboard::Up;
	_down = sf::Keyboard::Down;
	_left = sf::Keyboard::Left;
	_right = sf::Keyboard::Right;

	_jump = sf::Keyboard::Space;
	_fire = sf::Keyboard::Z;

	_pause = sf::Keyboard::Escape;
}

void InputManager::SetKeyTo(InputManager::Input id, sf::Keyboard::Key key) {
	//This decides in which key variable it will get the key value 
	switch (id) {
	case InputManager::Up:
		_up = key;
		break;
	case InputManager::Down:
		_down = key;
		break;
	case InputManager::Left:
		_left = key;
		break;
	case InputManager::Right:
		_right = key;
		break;
	case InputManager::Jump:
		_jump = key;
		break;
	case InputManager::Fire:
		_fire = key;
		break;
	case InputManager::Pause:
		_pause = key;
		break;
	}
}

//Sets the eventListener to a function
void InputManager::SetEvent(InputManager::Input id, void(*f)()) {
	switch (id) {
		case Input::Up:
			_eventUp = f;
			break;
		case Input::Down:
			_eventDown = f;
			break;
		case Input::Left:
			_eventLeft = f;
			break;
		case Input::Right:
			_eventRight = f;
			break;
		case InputManager::Jump:
			_eventJump = f;
			break;
		case Input::Fire:
			_eventFire = f;
			break;
		case Input::Pause:
			_eventPause = f;
			break;
	}
}

//Checks if a specific input is triggered
void InputManager::UpdateEvent(sf::Event event, InputManager::Input id) {
	//Is there even a key being pressed?
	if (event.type == event.KeyPressed) {
		//Check which event you want to listen
		switch (id) {
		case InputManager::Up:
			TriggerEvent(event, _up, _eventUp);
			break;
		case InputManager::Down:
			TriggerEvent(event, _down, _eventDown);
			break;
		case InputManager::Left:
			TriggerEvent(event, _left, _eventLeft);
			break;
		case InputManager::Right:
			TriggerEvent(event, _right, _eventRight);
			break;
		case InputManager::Jump:
			TriggerEvent(event, _jump, _eventJump);
			break;
		case InputManager::Fire:
			TriggerEvent(event, _fire, _eventFire);
			break;
		case InputManager::Pause:
			TriggerEvent(event, _pause, _eventPause);
			break;
		}
	}
}

//Checks if any input is triggered
void InputManager::UpdateEvents(sf::Event event) {
	//Is there even a key being pressed?
	if (event.type == event.KeyPressed) {
		//Check if anything triggers
		TriggerEvent(event, _up, _eventUp);
		TriggerEvent(event, _down, _eventDown);
		TriggerEvent(event, _left, _eventLeft);
		TriggerEvent(event, _right, _eventRight);
		TriggerEvent(event, _jump, _eventJump);
		TriggerEvent(event, _fire, _eventFire);
		TriggerEvent(event, _pause, _eventPause);
	}
}

//Validates the event listener
void InputManager::TriggerEvent(sf::Event event, sf::Keyboard::Key input, void (*trigger)()){
	//First check if there is even a event listed to the input
	if (trigger != NULL) {
		//Check if the input is registered
		if (event.key.code == input) {
			//Execute function
			(*trigger)();
		}
	}
}

//Deletes all references that are stored in the pointers
InputManager::~InputManager()
{
	//delete &_eventUp;

	//delete &_eventDown;
	
	//delete &_eventLeft;

	//delete &_eventRight;

	//delete &_eventJump;

	//delete &_eventFire;

 	//delete &_eventPause;
}
