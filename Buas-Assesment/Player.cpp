#include "Player.h"
#include "Collision.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player() {

}

Player::Player(sf::Vector2f aPosition, float jumpForce, Collision collisionBox)
{
	position = aPosition;
	_velocity = sf::Vector2f(0,0);
	_accelleration = sf::Vector2f(0,0);

	_jumpForce = jumpForce;

	_collisionBox = collisionBox;
	
	//std::cout << position.x << " , " << position.y << "\n";
}

sf::Vector2f Player::Velocity() {
	return _velocity;;
}

sf::Vector2f Player::Accelleration() {
	return _accelleration;;
}

Collision Player::CollisionBox() {
	Collision collisionBox = _collisionBox;
	for (int i = 0; i < _collisionBox.collision.getVertexCount(); i++) {
		collisionBox.collision[i].position += position;
	}
	return collisionBox;
}

float Player::Weight() {
	return _weight;;
}

void Player::Jump() {
	if (_state != Player::Airborne) {
		_velocity = sf::Vector2f(0,_jumpForce);
		_state = Airborne;
	}
}

void Player::Update() {
	switch (_state) {
		case Player::Airborne:
			_accelleration = sf::Vector2f(0, -1);
			break;
		case Player::Grounded:
			_accelleration = sf::Vector2f(0, 0);
	}
	position += _velocity + _accelleration;
	//std::cout << position.x << " , " << position.y << "\n";
}

Player::~Player()
{
}
