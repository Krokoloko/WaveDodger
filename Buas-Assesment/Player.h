#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "SineWall.h"
#include "Object.h"
class Player : public Object
{

public:
	Player();

	Player(sf::Vector2f, float, float, Collision);

	enum PlayerState {
		None,
		Grounded,
		Airborne,
		Dead
	};

	Collision collider;

	sf::Vector2f Velocity();
	sf::Vector2f Accelleration();

	Collision CollisionBox();
	PlayerState State();

	float Weight();

	void Jump();
	void Update(SineWall);

	~Player();
private:
	sf::Vector2f _velocity;
	sf::Vector2f _accelleration;

	Collision _collisionBox;

	Player::PlayerState _state;
	int _jumpForce;
	
	float _weight;
};

