#include "Player.h"
#include "Collision.h"
#include "SineWall.h"

#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player() {

}

Player::Player(sf::Vector2f aPosition, float aJumpForce, float aWeight, Collision aCollisionBox)
{
	position = aPosition;
	_velocity = sf::Vector2f(0,0);
	_accelleration = sf::Vector2f(0,0);

	_weight = aWeight;
	_jumpForce = aJumpForce;

	_collisionBox = aCollisionBox;
	_state = PlayerState::None;

	_jumped = false;
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

Player::PlayerState Player::State() {
	return _state;
}

float Player::Weight() {
	return _weight;;
}

void Player::Jump() {
	if (_state != Player::Airborne) {
		_velocity = sf::Vector2f(0, 1 * _jumpForce);
		_jumped = true;
	}
}

void Player::Update(SineWall wall) {
	switch (_state) {
		case Player::Airborne:
			if (_collisionBox.OnHitWith(wall.Wall())) {
				_accelleration = sf::Vector2f(0, 0);
				_velocity = sf::Vector2f(0, 0);
				_jumped = false;
				_state = PlayerState::Grounded;
				break;
			}
		case Player::Grounded:
			if (_collisionBox.OnHitReleaseWith(wall.Wall())) {
				_state = PlayerState::Airborne;
				break;
			}
		case PlayerState::None:
			if (CollisionBox().OnHitWith(wall.Wall()))
			{
				_state = PlayerState::Grounded;
				break;
			}
			else {
				_state = PlayerState::Airborne;
				break;
			}
	}
	
	
	switch (_state) {
		case Player::Airborne:
			_accelleration = sf::Vector2f(0, -1*_weight);
			if (_jumped) {
				_velocity -= sf::Vector2f(0, _weight/10);
			}
			//std::cout << "Airborne\n";
			break;
		case Player::Grounded:
			_accelleration = sf::Vector2f(0, 0);
			//std::cout << "Grounded\n";
			break;
	}
	//std::cout << position.x << " , " << position.y << "\n";
}

void Player::UpdatePhysics() {
	position -= (_velocity + _accelleration);
}

Player::~Player()
{
}
