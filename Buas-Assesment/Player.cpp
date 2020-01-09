#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player() {

}

Player::Player(sf::Vector2f position, float jumpForce, sf::VertexArray collisionBox)
{
	_position = position;
	_velocity = sf::Vector2f(0,0);
	_accelleration = sf::Vector2f(0,0);

	_jumpForce = jumpForce;

	_collisionBox = collisionBox;
	
	std::cout << _position.x << " , " << _position.y << "\n";
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
	if (this->_state != Player::Airborne) {
		this->_velocity = sf::Vector2f(0,_jumpForce);
		this->_state = Airborne;
	}
}

void Player::Update() {
	switch (this->_state) {
	case Player::Airborne:
		this->_accelleration = sf::Vector2f(0, -1);
		break;
	case Player::Grounded:
		this->_accelleration = sf::Vector2f(0, 0);
	}
	this->_position += this->_velocity + this->_accelleration;
	std::cout << this->_position.x << " , " << this->_position.y << "\n";
}

Player::~Player()
{
}
