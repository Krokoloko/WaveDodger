#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "Object.h"
class Player : public Object
{

public:
	Player();

	Player(sf::Vector2f, float, Collision);

	enum PlayerState {
		Grounded,
		Airborne
	};

	Collision collider;

	sf::Vector2f Velocity();
	sf::Vector2f Accelleration();

	Collision CollisionBox();

	float Weight();

	void Jump();
	void Update();

	~Player();
private:
	sf::Vector2f _velocity;
	sf::Vector2f _accelleration;

	Collision _collisionBox;

	Player::PlayerState _state;
	int _jumpForce;
	
	float _weight;
};

