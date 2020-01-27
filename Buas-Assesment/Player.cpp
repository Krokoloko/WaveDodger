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
		_velocity = sf::Vector2f(0,1*_jumpForce);
	}
}

void Player::Update(SineWall wall) {
	switch (_state) {
		case Player::Airborne:
			if (_collisionBox.OnHitStartWith(wall.Wall())) {
				_state = Player::Grounded;
			}
		case Player::Grounded:
			if (_collisionBox.OnHitReleaseWith(wall.Wall())) {
				_state = Player::Airborne;
			}
	}
	if (CollisionBox().OnHitWith(wall.Wall()))
	{
		if (wall.Position().y+(wall.Length()/2)>position.y+(collider.collision[0].position.y-collider.collision[3].position.y)/2) {

			std::cout << "Die?";

		}
	}
	switch (_state) {
		case Player::Airborne:
			_accelleration = sf::Vector2f(0, -1);
			_velocity -= sf::Vector2f(0, _jumpForce/_weight);
			break;
		case Player::Grounded:
			_accelleration = sf::Vector2f(0, 0);
	}
	std::cout << "test";
	
	position += _velocity + _accelleration;
	//std::cout << position.x << " , " << position.y << "\n";
}

Player::~Player()
{
}
