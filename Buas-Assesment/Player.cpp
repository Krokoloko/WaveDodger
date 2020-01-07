#include "Player.h"
#include <SFML/Graphics.hpp>


Player::Player(sf::Vector2f position, float jumpForce, sf::VertexArray collisionBox)
{
	_position = position;
	_velocity = sf::Vector2f(0,0);
	_accelleration = sf::Vector2f(0,0);

	_jumpForce = jumpForce;

	_collisionBox = collisionBox;
	
}

sf::Vector2f Player::Position() {
	return _position;;
}

sf::Vector2f Player::Velocity() {
	return _velocity;;
}

sf::Vector2f Player::Accelleration() {
	return _accelleration;;
}

sf::VertexArray Player::CollisionBox() {
	sf::VertexArray collisionBox = _collisionBox;

	for (int i = 0; i < _collisionBox.getVertexCount(); i++) {
		collisionBox[i].position += _position;
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
	_position += _velocity + _accelleration;
}

Player::~Player()
{
}
